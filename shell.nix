{ pkgs ? import (fetchTarball "https://github.com/NixOS/nixpkgs/archive/ca012a02bf8327be9e488546faecae5e05d7d749.tar.gz") {}
}:

let
  pythonPkgs = pkgs.python310Packages;


  /* pyjion = with pythonPkgs;
    buildPythonPackage rec {
      pname = "pyjion";
      version = "2.0.0";
      src = fetchPypi {
        inherit pname version;
        hash = "sha256-Q1WDDl5SZZBq1tRpuucFMAM8NbUkXW3kUDCCWXIeZyA=";
      };

      propagatedBuildInputs = [
        scikit-build
      ];
      doCheck = true;
    }; */


  pythonEnv = pkgs.python310.withPackages (ps: [
    ps.pytest
    ps.typing-extensions
    ps.mypy
    ps.autopep8
    ps.rich
    ps.pytest-xdist
    ps.nuitka
    ps.snakeviz
    # pyjion
  ]);
in pkgs.mkShell {

  packages = [
    pythonEnv
    pkgs.pyright
    pkgs.graphviz
    pkgs.z3_4_11
    pkgs.cvc5
    pkgs.time
    pkgs.chromium
    pkgs.watchexec
    pkgs.pypy310
  ];
}
