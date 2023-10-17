from __future__ import annotations
from typing import Mapping, NamedTuple, TYPE_CHECKING, Sequence
from typing_extensions import assert_never
from collections import OrderedDict
from dot_graph import pretty_expr
from source import TypeArray, TypeBitVec, TypeBuiltin, TypeFloatingPoint, TypePtr, TypeSpecGhost, TypeWordArray, convert_type, TypeStruct, Type, ExprSymbolT, ExprT, pretty_expr_ascii
import source

if TYPE_CHECKING:
    import assume_prove
    import syntax

class StructField(NamedTuple):
    name: str
    offset: int
    typ: Type

class Struct(NamedTuple):
    """
    """
    name: str
    size: int
    align: int
    fields: Mapping[str, StructField]
    typ: Type

safe_globals: Mapping[ExprSymbolT, Type] = {

}

safe_structs: Mapping[TypeStruct, Struct] = {

}


# These turns into asserts later
global_asserts: Sequence[ExprT[assume_prove.VarName]] = []

ring_handle_t = TypeStruct("Kernel_C.ring_handle_C")

# declare your global variables here
__loose_globals: Mapping[str, Type] = {
    "rx_ring_mux": ring_handle_t,
    "rx_ring_cli": ring_handle_t
}


def sz(ty: Type) -> int:
    """
    Returns the number of bits needed 
    to store a certain type
    """
    size: int = 0

    if isinstance(ty, TypeStruct):
        struct = safe_structs[ty]
        return struct.size
    elif isinstance(ty, TypeBitVec):
        assert ty.size % 8 == 0
        size += int(ty.size / 8)
    elif isinstance(ty, TypePtr):
        size += 8
    elif isinstance(ty, TypeArray):
        inner_typ_sz = sz(ty.element_typ)
        size += inner_typ_sz * ty.size
    elif isinstance(ty, TypeFloatingPoint):
        assert False, "TypeFloatingPoint not implemented"
    elif isinstance(ty, TypeBuiltin):
        assert False, "TypeBuiltin not implemented"
    elif isinstance(ty, TypeWordArray):
        assert False, "TypeWordArray not implemented"
    elif isinstance(ty, TypeSpecGhost):
        assert False, "TypeSpecGhost not implemented"
    else:
        assert_never(ty)

    return size

class InitMem():
    addr_bits: int
    offset: int # we layout variables one by one

    sym_conds: list[source.ExprT[source.ProgVarName]]

    def __init__(self, addr_bits: int):
        self.addr_bits = addr_bits
        self.offset = 0
        self.sym_conds = []

    def init_mem(self, var: ExprSymbolT, ty: Type) -> None:
        """
        This can be a source of unsoundness.
        We have to be extremely careful when 
        initialising memory. We need to 
        ensure that the space taken up
        by every global variable is distinct.
        The memory starts out at index 0 
        and then we start laying out everything
        from there.

        Any pointers can now be 'created' by ensuring the value is greater
        than the last offset. This isn't flexible enough to support 
        'malloc' but good enough for our use case for now.
        """
        if isinstance(ty, TypeStruct):
            assert safe_globals[var] == ty
            assert ty in safe_structs
            struct = safe_structs[ty]
            self.init_struct(var, struct)
        elif isinstance(ty, TypeBitVec):
            assert False, "not yet implemented"
        elif isinstance(ty, TypeArray):
            assert False, "not yet implemented"
        elif isinstance(ty, TypeWordArray):
            assert False, "not yet implemented"
        elif isinstance(ty, TypePtr):
            assert False, "not yet implemented"
        elif isinstance(ty, TypeFloatingPoint):
            assert False, "not yet implemented"
        elif isinstance(ty, TypeSpecGhost):
            assert False, "not yet implemented"
        elif isinstance(ty, TypeBuiltin):
            assert False, "not yet implemented"
        else:
            assert_never(ty)


    def init_struct(self, var: ExprSymbolT, struct: Struct) -> None:

        # alignment is given by default through this
        starting_point = self.offset + (self.offset % struct.align)

        offset = starting_point
        local_offset = 0
    
        # finding our next offset is simple, 
        # we just want to sanity check though

        assert len(struct.fields) >= 1, "structs should have at least one field"
        for _, (_, field) in enumerate(struct.fields.items()):
            size = sz(field.typ)

            if field.offset != local_offset:
                assert field.offset > local_offset, "padding is the only case where this makes any sense"
                local_offset += (field.offset - local_offset)
            local_offset += size

        offset = offset + local_offset
        expected_offset = starting_point + struct.size

        assert offset == expected_offset
        self.offset = offset
        
        cond: source.ExprT[source.ProgVarName] = source.expr_eq(var, source.ExprNum(num=starting_point, typ=source.type_word64))
        vari = source.ExprVar(source.type_word64, source.ProgVarName("i"))
        var_htd = source.ExprVar(source.type_htd, source.ProgVarName("h"))
        # starting_point <= i < offset
        # starting_point <= i
        # offset < i
        lowerterm = source.expr_ule(source.ExprNum(source.type_word64, starting_point), vari)
        upperterm = source.expr_ult(source.ExprNum(source.type_word64, offset), vari)
        memvalid = source.expr_valid(mem, vari)
        validity = source.expr_implies(source.expr_and(lowerterm, upperterm), memvalid)
        validityQuant = source.ExprForall(source.type_bool, [var_htd, vari], validity, memvalid, f"quantifier-valid-{struct.name}", f"skolem-valid-{struct.name}")
        self.sym_conds.append(cond)
        self.sym_conds.append(validityQuant)
        print('-'*80)
        print(cond)
        print('*'*80)
        print(validityQuant)
        print('x'*80)
        print(pretty_expr_ascii(validityQuant))
        exit(0)

def to_safe_struct(struct: syntax.Struct) -> Struct:
    fields:OrderedDict[str, StructField] = OrderedDict()

    for field_name, (typ, offset, _) in struct.fields.items():
        assert field_name not in fields
        fields[field_name] = StructField(field_name, offset, convert_type(typ))
    return Struct(struct.name, struct.size, struct.align, fields, convert_type(struct.typ))

def populate_safe_structs(structs: Mapping[str, syntax.Struct]) -> None:
    safe_structs_local: dict[TypeStruct, Struct] = {}
    global safe_structs
    for struct_name, struct in structs.items():
        safe_struct = to_safe_struct(struct)
        key = TypeStruct(struct_name)
        assert key not in safe_structs
        safe_structs_local[key] = safe_struct
    safe_structs = safe_structs_local


def populate_safe_globals() -> None:
    """
    All we do is check if the structs referred in the __loose_globals
    have actually been populated in safe_structs.
    It then moves these variables to safe_globals.
    We can then assume that every variable in safe_globals has an
    associated type
    """
    global safe_globals
    safe_globals_local: dict[ExprSymbolT, Type] = {} 
    for variable, typ in __loose_globals.items():
        if isinstance(typ, TypeStruct): 
            assert typ in safe_structs
        safe_globals_local[ExprSymbolT(name=variable, typ=source.type_word64)] = typ

    safe_globals = safe_globals_local



def initialise_memory() -> None:
    """
    We need to initialise the array used to represent memory, 
    because our globals are by definition already valid.
    """
    
    mem = InitMem(64)
    for var, ty in safe_globals.items():
        mem.init_mem(var, ty)
