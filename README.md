# hdlConvertor
[![Travis-ci Build Status](https://travis-ci.org/Nic30/hdlConvertor.png?branch=master)](https://travis-ci.org/Nic30/hdlConvertor)
[![Win Build status](https://ci.appveyor.com/api/projects/status/e3cvi3ig5y4vni7e?svg=true)](https://ci.appveyor.com/project/nic30/hdlconvertor)
[![PyPI version](https://badge.fury.io/py/hdlConvertor.svg)](http://badge.fury.io/py/hdlConvertor)
[![Python version](https://img.shields.io/pypi/pyversions/hdlConvertor.svg)](https://img.shields.io/pypi/pyversions/hdlConvertor.svg)
[ROADMAP](https://drive.google.com/file/d/1zyegLIf7VaBRyb-ED5vgOMmHzW4SRZLp/view?usp=sharing) [![Gitter](https://badges.gitter.im/hdlConvertor/community.svg)](https://gitter.im/hdlConvertor/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)
[![Coverage Status](https://coveralls.io/repos/github/Nic30/hdlConvertor/badge.svg?branch=master)](https://coveralls.io/github/Nic30/hdlConvertor?branch=master)

The System Verilog and VHDL parser, preprocessor and code generator for Python/C++ written in C++. The lower layers are ANTLR4 generated parsers with full language support. Next layer converts this raw Verilog/VHDL AST to simple universal AST (Classes defined in [hdlConvertor::hdlObjects](https://github.com/Nic30/hdlConvertor/tree/master/include/hdlConvertor/hdlObjects) and it's [python equivalent](https://github.com/Nic30/hdlConvertor/tree/master/hdlConvertor/hdlAst).). So your project does not not have to care about Verilog/VHDL differences and deprecated ridiculous features.
It is also possible to convert this AST back to original HDL or access the comments from HDL.

![overview](https://raw.githubusercontent.com/nic30/hdlConvertor/master/doc/hdlConvertor_overview.png)


### Supported languages:
* [IEEE 1076-2008 (VHDL 2008)](https://ieeexplore.ieee.org/document/4772740) and all previous standard, (currently without `tool_directive` and `PSL`)
* [IEEE 1076-2019] WIP
* [IEEE 1800-2017 (SystemVerilog 2017)](https://ieeexplore.ieee.org/document/8299595) and all previous standards.


## Installation

Linux:
Installing dependencies (Ubuntu 19.04)
```
# use up to date compiler, gcc>=7
# on old systems without libantlr4-runtime-dev you have to add apt repo manually, see .travis.yml
sudo apt install build-essential uuid-dev cmake default-jre python3 python3-dev python3-pip libantlr4-runtime-dev antlr4
```

Installing this library
```
# note this may be older version than you see in repo
sudo pip3 install hdlConvertor

# or download repository and run
sudo pip3 install -r requirements.txt
sudo python3 setup.py install
```

Installer also supports other options which may be usefull
```
python setup.py install --prefix /tmp/python_install/ -j 8 --build-type Debug -- -DANTLR_JAR_LOCATION=/antlr-4.7.1-complete.jar -- VERBOSE=1
```

You can also install only C++ library/generate .deb package (nothing specific, just normal cmake-based library)
```
mkdir build && cd build
cmake .. && cmake . --build
cpack # to generate .deb package
```

Windows:

Take a look at appveyor.yml. It is required to download antlr4 first and have visual studio or other c++ compiler installed.


## Usage

The HDL AST (the parsed code) is represented by objects from `hdlConvertor.hdlAst`.
There are classes for objects in HDL langues and there is also type specified for every property in anotations. This allows IDEs to advise and it is also a part of doc.

Example of usage:
```python
import sys
from hdlConvertor.language import Language
from hdlConvertor.toVerilog import ToVerilog
from hdlConvertor import HdlConvertor

filenames = ["your.v", ]
include_dirs = []
c = HdlConvertor()
d = c.parse(filenames, Language.VERILOG, include_dirs, hierarchyOnly=False, debug=True)

tv = ToVerilog(sys.stdout)
tv.print_context(d)

for o in d.objs:
    print(o)
```

![overview](https://raw.githubusercontent.com/nic30/hdlConvertor/master/doc/hdlConvertor_typical_usage.png)


### Similar projects:
(Tell us If you know about some other project!)

* [cl-vhdl](https://github.com/mabragor/cl-vhdl) - lisp, Parser of VHDL into lisp-expressions 
* [HDL_ANTLR4](https://github.com/denisgav/HDL_ANTLR4) - C# projects that use ANTLR4 library to analyse VHDL and Verilog code
* [hdlparse](https://github.com/kevinpt/hdlparse/) - vhdl/verilog parser in python
* [ieee1800_2017](https://github.com/veriktig/ieee1800_2017) - Java, SystemVerilog preprocessor
* [Pyverilog](https://github.com/PyHDI/Pyverilog) - python verilog toolkit
* [pyVHDLParser](https://github.com/Paebbels/pyVHDLParser) - python vhdl parser with 2008 support
* [rust_hdl](https://github.com/kraigher/rust_hdl) - rust vhdl 2008 parser
* [slang](https://github.com/MikePopoloski/slang) - Parser and compiler library for SystemVerilog.
* [sv-parser](https://github.com/dalance/sv-parser) - Rust, SystemVerilog parser library fully complient with IEEE 1800-2017
* [systemc-clang](https://github.com/anikau31/systemc-clang) - SystemC Parser using the Clang Front-end
* [v2sc](https://github.com/denisgav/v2sc) - vhdl to systemc
* [veelox](https://github.com/martinda/veelox) - Java+ANTLR, An experiment in SystemVerilog Preprocessing 
* [verible](https://github.com/chiplicity/verible) -C++, SystemVerilog parser, style-linter, and formatter
* [verilog-parser](https://github.com/ben-marshall/verilog-parser) - A Flex/Bison Parser for the IEEE 1364-2001 Verilog Standard.
* [vbpp](https://github.com/balanx/vbpp) - C, Verilog PreProcessor
* [tree-sitter-verilog](https://github.com/tree-sitter/tree-sitter-verilog) - JS,  Verilog grammar for tree-sitter 
* [Verilog-Perl](https://metacpan.org/pod/Verilog-Perl)
* [vpp.pl](https://www.beyond-circuits.com/wordpress/vpp-pl-man-page/) - verilog preprocessor with integrated Perl
* [sv2v](https://github.com/zachjs/sv2v)- Haskell, SystemVerilog to Verilog

