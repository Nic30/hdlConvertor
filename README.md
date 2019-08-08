# hdlConvertor
[![Travis-ci Build Status](https://travis-ci.org/Nic30/hdlConvertor.png?branch=master)](https://travis-ci.org/Nic30/hdlConvertor)
[![Win Build status](https://ci.appveyor.com/api/projects/status/e3cvi3ig5y4vni7e?svg=true)](https://ci.appveyor.com/project/nic30/hdlconvertor)
[![PyPI version](https://badge.fury.io/py/hdlConvertor.svg)](http://badge.fury.io/py/hdlConvertor)
[![Python version](https://img.shields.io/pypi/pyversions/hdlConvertor.svg)](https://img.shields.io/pypi/pyversions/hdlConvertor.svg)
[ROADMAP](https://drive.google.com/file/d/1zyegLIf7VaBRyb-ED5vgOMmHzW4SRZLp/view?usp=sharing) [![Gitter](https://badges.gitter.im/hdlConvertor/community.svg)](https://gitter.im/hdlConvertor/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)


The System Verilog and VHDL parser (and preprocessor) for Python/C++ written in C++. The lower layers are ANTLR4 generated parsers with full language support. Next layer converts this raw Verilog/VHDL AST to simple universal AST (Classes defined in [hdlConvertor::hdlObjects](https://github.com/Nic30/hdlConvertor/tree/master/include/hdlConvertor/hdlObjects) and it's [python equivalent](https://github.com/Nic30/hdlConvertor/tree/master/hdlConvertor/hdlAst).). So your project does not not have to care about Verilog/VHDL differences

It is also possible to convert this AST back to original HDL.

This project was extracted from [HWT](https://github.com/Nic30/hwt).
There is also Java version. But it seems that there is no use for it.


## Installation
**Use version from this repo as the pip package is currently very old (The pip package will be updated after specified functionality is implemented [issues/48](https://github.com/Nic30/hdlConvertor/issues/48).).**

Linux:
```
# note: use up to date compiler, gcc 5.4 is too old
# note that only last 2 are really required rest is downloaded automatically as dependency
sudo apt install build-essential uuid-dev cmake default-jre python3 python3-dev python3-pip libantlr4-runtime-dev antlr4
# note this may be older version than you see in repo
sudo pip3 install hdlConvertor

#or download repository and run
sudo pip3 install -r requirements.txt
sudo python3 setup.py install
```
Or the same for python 2.7 with other options just for demonstration.

Installer also supports other commands.
```
# note that setting PYTHONPATH and params after install are there just for example and are not required 
export PYTHONPATH=/tmp/python_install/lib/python2.7/site-packages/
python setup.py install --prefix /tmp/python_install/ -j 8 --build-type Debug -- -DANTLR_JAR_LOCATION=../../../antlr4/antlr-4.7.1-complete.jar -- VERBOSE=1

Other commands:
python setup.py --help-commands
```

You can also install only C++ library/generate .deb package (nothing specific, just normal cmake-builded library)
```
mkdir build && cd build
cmake .. && cmake . --build
cpack # to generate .deb package
```

If you having issues take a look at .travis.yml (build script for the ubuntu 16.04).

Windows:

Take a look at appveyor.yml. It is required to download antlr4 first and have visual studio or other c++ compiler installed.

Also if it is something which is not unique to your system, tell us so we can fix it.


## Usage
The HDL AST (the parsed code) is represented by objects from `hdlConvertor.hdlAst`.
In the meantime when there is no wiki yet you can take look at src/hdlAst.py.
There are classes for objects in HDL langues and there is also type specified for every properrty.

Example of usage:
```python
import sys
from hdlConvertor.language import Language
from hdlConvertor.toVerilog import ToVerilog
from hdlConvertor import HdlConvertor

c = HdlConvertor()
filenames = ["your.v", ]
include_dirs = []
d = c.parse(filenames, Language.VERILOG, include_dirs, hierarchyOnly=False, debug=True)

tv = ToVerilog(sys.stdout)
tv.print_context(d)

for o in d.objs:
    print(o)
```


### Supported languages:
* [VHDL 1076-1993](https://perso.telecom-paristech.fr/guilley/ENS/20161206/TP/tp_syn/doc/IEEE_VHDL_1076-1993.pdf) compatible
* [VHDL 1076-2002](https://perso.telecom-paristech.fr/guilley/ENS/20171205/TP/tp_syn/doc/IEEE_VHDL_1076-2002.pdf) compatible
* VHDL 2008, (currently only without `tool_directive` and `PSL`) ftp://ftp.lpp.polytechnique.fr/jeandet/keep/sync/vhdl/4772740_IEEE-1076_Standard-VHDL-Language-Ref-Manual.pdf
* Verilog 2001 (based on grammar http://www.syncad.com/VeriLogger_bnf_Syntax_Verilog_2001.htm, https://github.com/antlr/grammars-v4/blob/master/verilog/Verilog2001.g4)
* System Verilog 2012 (based on grammar http://insights.sigasi.com/tech/systemverilog.ebnf.html) (WIP, currently only on C++ level)


### Similar projects:
(Tell us If you know about some other project!)

* [cl-vhdl](https://github.com/mabragor/cl-vhdl) - lisp, Parser of VHDL into lisp-expressions 
* [HDL_ANTLR4](https://github.com/denisgav/HDL_ANTLR4) - C# projects that use ANTLR4 library to analyse VHDL and Verilog code
* [hdlparse](https://github.com/kevinpt/hdlparse/) - vhdl/verilog parser in python
* [ieee1800_2017](https://github.com/veriktig/ieee1800_2017) - Java, SystemVerilog preprocessor
* [pyVHDLParser](https://github.com/Paebbels/pyVHDLParser) - python vhdl parser with 2008 support
* [rust_hdl](https://github.com/kraigher/rust_hdl) - rust vhdl 2008 parser
* [slang](https://github.com/MikePopoloski/slang) - Parser and compiler library for SystemVerilog.
* [systemc-clang](https://github.com/anikau31/systemc-clang) - SystemC Parser using the Clang Front-end
* [v2sc](https://github.com/denisgav/v2sc) - vhdl to systemc
* [veelox](https://github.com/martinda/veelox) - Java+ANTLR,  An experiment in SystemVerilog Preprocessing 
* [verilog-parser](https://github.com/ben-marshall/verilog-parser) - A Flex/Bison Parser for the IEEE 1364-2001 Verilog Standard.
* [verilog-parser](https://github.com/ben-marshall/verilog-parser) - verilog parser, c
* [Verilog-Perl](https://metacpan.org/pod/Verilog-Perl)
* [vpp.pl](https://www.beyond-circuits.com/wordpress/vpp-pl-man-page/) - verilog preprocessor with integrated Perl

### License

License in top folder applies to this project only.
In this repository there are also ANTLR4 grammars (.g4 files - BSD 3, GPL-3, GPL, however they are not present in installation).

