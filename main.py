from enum import Enum, unique
from typing import Collection, Sequence, Tuple, Any, Dict

import sys
import os
from typing_extensions import assert_never
from dot_graph import viz_function, viz_raw_function

import syntax
import source
import abc_cfg
import smt
import dsa
import nip
import assume_prove
import ghost_data
import ghost_code

import validate_dsa

syntax.set_arch('rv64')


def assert_all_kernel_functions_are_reducible() -> None:
    with open('examples/kernel_CFunctions.txt') as f:
        structs, functions, const_globals = syntax.parse_and_install_all(
            f, None)
        for unsafe_func in functions.values():
            if not unsafe_func.entry:
                continue
            func = source.convert_function(unsafe_func)
            assert abc_cfg.is_reducible(func.cfg)
    print("[check] all kernel functions with an entry are reducible")


def same_var_diff_type(func: source.Function) -> None:
    vars: dict[str, set[source.ProgVarName]] = {}
    for n in func.nodes:
        for var in source.used_variables_in_node(func.nodes[n]).union(source.assigned_variables_in_node(func, n, with_loop_targets=True)):
            if '__' in var.name:
                real_name, type_info = var.name.split('__', maxsplit=1)

                if '.' in type_info:
                    real_name += type_info.split('.', maxsplit=1)[1]

                if real_name not in vars:
                    vars[real_name] = set()
                vars[real_name].add(var.name)

    diff = {var: uses for var, uses in vars.items() if len(uses) > 1}
    if diff:
        print(f"diffs: {func.name} {diff}")


@unique
class CmdlineOption(Enum):
    SHOW_RAW = '--show-raw'
    """ Show the raw function """

    SHOW_GRAPH = '--show-graph'
    """ Show the graph lang """

    SHOW_NIP = '--show-nip'
    """ Show the non-initialized protected cfg """

    SHOW_GHOST = '--show-ghost'
    """ Show the cfg with the ghost code inserted
        (pre condition, post condition and loop invariants)
    """

    SHOW_DSA = '--show-dsa'
    """ Show the graph after having applied dynamic single assignment """

    SHOW_AP = '--show-ap'
    """ Show the assume prove prog """

    SHOW_SMT = '--show-smt'
    """ Show the SMT given to the solvers """

    SHOW_SATS = '--show-sats'
    """ Show the raw results from the smt solvers (sat/unsat) """

    SHOW_LINE_NUMBERS = '--ln'
    """ Shows line numbers for the smt """

    PROVE_NON_TERMINATE = '--prove-non-termination'
    """ States that the function does not terminate, therefore correctness here means to prove that the 
    error node is never reached """

    DEBUG = '--debug-smt'
    """ Creates n many error nodes and relies on you to fix the emitted SMT. 
    Fixing is simple, remove node_Err_ok and the assertion of node_Err_ok. 
    From here, enable various error nodes by setting the node_Err_ok_{num} to false. 
    This allows finding what assertion failed. 
    """


def find_functions_by_name(function_names: Collection[str], target: str) -> str:
    if target in function_names:
        return target

    for option in function_names:
        if option.endswith(target) and len(option) > len(target) and option[-len(target) - 1] == '.':
            return option

    selected: str | None = None
    for option in function_names:
        if target in option:
            if selected is None:
                selected = option
            else:
                print(
                    f"{target} doesn't allow me to chose between {selected} and {option}")
                print(f"Use a more specific name")
                exit(1)
    if selected is None:
        print(f"{target} didn't match any function name")
        print(f"The list of available functions is")
        print('\n'.join(function_names))
        exit(1)
    return selected


def run(filename: str, function_names: Collection[str], options: Collection[CmdlineOption]) -> None:
    if filename.lower() == 'dsa':
        filename = 'examples/dsa.txt'
    elif filename.lower() == 'kernel':
        filename = 'examples/kernel_CFunctions.txt'
    elif filename.lower() == 'all':
        filename = 'tests/all.txt'

    if filename.endswith('.c'):
        print(
            "You probably meant to pass in the .txt file, not the .c file", file=sys.stderr)
        print("If not, don't be silly and rename it to .txt", file=sys.stderr)
        exit(1)

    if os.path.isfile(filename):
        with open(filename) as f:
            stuff = syntax.parse_and_install_all(f, None)
    else:
        print(f"filename {filename} should be the path of a file")
        exit(1)

    if len(function_names) == 0:
        print("list of functions in the file")
        for func in stuff[1].values():
            print(f'  {func.name} ({len(func.nodes)} nodes)')

    _, functions, _ = stuff
    
    debug_mode = CmdlineOption.DEBUG in options 

    for name in function_names:
        unsafe_func = functions[find_functions_by_name(functions.keys(), name)]
        if CmdlineOption.SHOW_RAW in options:
            viz_raw_function(unsafe_func)

        prog_func = source.convert_function(unsafe_func).with_ghost(
            ghost_data.get(filename, unsafe_func.name))
        if CmdlineOption.SHOW_GRAPH in options:
            viz_function(prog_func)

        nip_func = nip.nip(prog_func)
        if CmdlineOption.SHOW_NIP in options:
            viz_function(nip_func)

        ghost_func = ghost_code.sprinkle_ghost_code(
            filename, nip_func, functions)
        if CmdlineOption.SHOW_GHOST in options:
            viz_function(ghost_func)

        dsa_func = dsa.dsa(ghost_func)
        if CmdlineOption.SHOW_DSA in options:
            viz_function(dsa_func)

        validate_dsa.validate(ghost_func, dsa_func)

        prog = assume_prove.make_prog(
            dsa_func, CmdlineOption.PROVE_NON_TERMINATE not in options)
        if CmdlineOption.SHOW_AP in options:
            assume_prove.pretty_print_prog(prog)

        _, smtlib = smt.make_smtlib(prog, debug_mode)
        if CmdlineOption.SHOW_SMT in options:
            if CmdlineOption.SHOW_LINE_NUMBERS in options:
                lines = smtlib.splitlines()
                w = len(str(len(lines)))
                for i, line in enumerate(lines):
                    print(f'{str(i).rjust(w)}  {line}')
            else:
                print(smtlib)

        sats = tuple(smt.send_smtlib_to_z3(smtlib))
        if CmdlineOption.SHOW_SATS in options:
            print(sats)

        assert len(sats) == 2
        result = smt.parse_sats(sats)

        if debug_mode:
            # we don't know if it will verify or not so we shoulnd't emit anything that might give a programmer false confidence
            exit(0)
        if result is smt.VerificationResult.OK:
            print("verification succeeded", file=sys.stderr)
            exit(0)
        elif result is smt.VerificationResult.INCONSTENT:
            print("INTERNAL ERROR: smt is an inconsistent state", file=sys.stderr)
            exit(2)
        elif result is smt.VerificationResult.FAIL:
            print("verification failed (good luck figuring out why)", file=sys.stderr)
            exit(1)
        else:
            assert_never(result)


def usage() -> None:
    print('usage: python3 main.py [options] <graphfile.txt> function-names...')
    print()
    print('  --show-graph: Show the graph lang')
    print('  --show-dsa: Show the graph after having applied dynamic single assignment')
    print('  --show-ap: Show the assume prove prog')
    print('  --show-smt: Show the SMT given to the solvers')
    print('  --show-sats: Show the raw results from the smt solvers (sat/unsat)')
    exit(0)


def debug1() -> None:
    with open('examples/kernel_CFunctions.txt') as f:
        structs, functions, const_globals = syntax.parse_and_install_all(
            f, None)
        pains = []
        for unsafe_func in functions.values():
            if not unsafe_func.entry:
                continue
            func = source.convert_function(unsafe_func)
            rets = set(var for var in func.all_variables() if var.name.startswith(
                'ret__') and '.' not in var.name and not var.name.startswith('ret___'))
            if len(rets) > 1:
                pains.append((func, unsafe_func.outputs, rets))

        for func, outputs, rets in sorted(pains, key=lambda v: len(v[0].nodes)):
            print(func.name, outputs, len(func.nodes), len(rets))


def debug() -> None:
    with open('examples/dsa.txt') as f:
        structs, functions, const_globals = syntax.parse_and_install_all(
            f, None)
        pains: list[Any] = []
        for unsafe_func in functions.values():
            if not unsafe_func.entry:
                continue
            func = source.convert_function(unsafe_func)
            ret_assigns = []
            for n in func.nodes:
                for var in source.assigned_variables_in_node(func, n, with_loop_targets=False):
                    if var.name.startswith('ret__') and not var.name.startswith('ret___'):
                        ret_assigns.append(n)
            if len(ret_assigns) > 1:
                print(func.name, ret_assigns)


def main() -> None:
    if '--help' in sys.argv or '-h' in sys.argv or len(sys.argv) == 1:
        usage()

    if '--debug' in sys.argv:
        debug()
        exit(0)

    options: list[CmdlineOption] = []
    function_names: list[str] = []
    for arg in sys.argv[1:]:
        if arg in (opt.value for opt in CmdlineOption):
            options.append(CmdlineOption(arg))
        elif arg.startswith('-'):
            print(f'err: unknown option {arg}')
            print()
            usage()
        else:
            function_names.append(arg)

    if len(function_names) == 0:
        print("err: you need to specify at least the graphfile")
        print()
        usage()

    filename = function_names[0]
    function_names = function_names[1:]
    run(filename, function_names, options)


if __name__ == "__main__":
    main()
