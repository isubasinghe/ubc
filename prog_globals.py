from __future__ import annotations
from enum import Enum
from typing import Mapping, NamedTuple
from collections import OrderedDict
import syntax
from source import convert_type, TypeStruct, Type


class StructField(NamedTuple):
    name: str
    offset: int
    typ: Type

class Struct(NamedTuple):
    name: str
    size: int
    align: int
    fields: Mapping[str, StructField]
    typ: Type





safe_globals: Mapping[str, Type] = {
}

safe_structs: Mapping[TypeStruct, Struct] = {

}


# declare your global variables here
__loose_globals: Mapping[str, Type] = {   
}


def to_safe_struct(struct: syntax.Struct) -> Struct:
    fields:OrderedDict[str, StructField] = OrderedDict()

    for field_name, (typ, offset, _) in struct.fields.items():
        assert field_name not in fields
        fields[field_name] = StructField(field_name, offset, convert_type(typ))
    return Struct(struct.name, struct.size, struct.align, fields, convert_type(struct.typ))

def populate_safe_structs(structs: Mapping[str, syntax.Struct]):
    for struct_name, struct in structs.items():
        safe_struct = to_safe_struct(struct)
        key = TypeStruct(struct_name)
        assert key not in safe_structs
        safe_structs[key] = safe_struct
        print(safe_struct)


def populate_safe_globals():
    """
    All we do is check if the structs referred in the __loose_globals
    have actually been populated in safe_structs.
    It then moves these variables to safe_globals.
    We can then assume that every variable in safe_globals has an
    associated type
    """
    
    for variable, typ in __loose_globals:
        if not isinstance(typ, TypeStruct): 
            continue
        assert typ.name in safe_structs
        safe_globals[variable] = typ



def initialise_memory():
    """
    We need to initialise the array used to represent memory, 
    because our globals are by definition already valid.
    """
    pass
