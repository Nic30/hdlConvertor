# hdlConvertor
[![Travis-ci Build Status](https://travis-ci.org/Nic30/hdlConvertor.png?branch=master)](https://travis-ci.org/Nic30/hdlConvertor)
[![PyPI version](https://badge.fury.io/py/hdlConvertor.svg)](http://badge.fury.io/py/hdlConvertor)
[![Python version](https://img.shields.io/pypi/pyversions/hdlConvertor.svg)](https://img.shields.io/pypi/pyversions/hdlConvertor.svg)

The System Verilog and VHDL parser for Python written in C++

This project was extracted from [HWT](https://github.com/Nic30/hwt).
There is also Java version. But it seems that there is no use for it.

This project use a ANTLR4. Currently, there is no universal way of distributing ANTLR4 library known to me.
To make your live easier I included it to this package for you.


## Installation and usage
```
sudo apt install uuid-dev
sudo pip3 install -r requirements.txt

sudo pip3 install hdlConvertor
#or download repository and run
sudo python3 setup.py install

```


In the meantime when there is no wiki yet you can take look at src/hdlObjects.
There are classes for objects in HDL langues and there are also toJson() for them.
This function is used for conversion to Python objects.

In python all parsed stuff are just dictionaries and values (str, int).

Top class of hdlObjects is Context, wich is container of all other hdl objects.


Example of usage:
```python
import hdlConvertor
res = hdlConvertor.parse("yourfile.vhd", "vhdl")
for e in res['entities']:
    print(e['name'])

```


Currently package is tested only for python3.5+ (python3.6 or latest recomended) under Linux but should work on any system with c++11 support. 

### Supported languages:

* VHDL 2002 (based on grammar https://guest.iis.ee.ethz.ch/~zimmi/download/vhdl02_syntax.html, https://github.com/antlr/grammars-v4/blob/master/vhdl/vhdl.g4 )
* Verilog 2001 (based on grammar http://www.syncad.com/VeriLogger_bnf_Syntax_Verilog_2001.htm, https://github.com/antlr/grammars-v4/blob/master/verilog/Verilog2001.g4)
* System Verilog 2012 (without preprocessor) (based on grammar http://insights.sigasi.com/tech/systemverilog.ebnf.html)


### Similar projects:

* [pyVHDLParser](https://github.com/Paebbels/pyVHDLParser) - python vhdl parser with 2008 support
* [hdlparse](https://github.com/kevinpt/hdlparse/) - vhdl/verilog parser in python 
* [v2sc](https://github.com/denisgav/v2sc) - vhdl to systemc
* [verilog-parser](https://github.com/ben-marshall/verilog-parser) - verilog parser, c 
* [systemc-clang](https://github.com/anikau31/systemc-clang) - SystemC Parser using the Clang Front-end


### Installation 

export PYTHONPATH=/tmp/python_install/lib/python2.7/site-packages/
python setup.py install --prefix /tmp/python_install/ -j 8 --build-type Debug -- -DANTLR_JAR_LOCATION=../../../antlr4/antlr-4.7.1-complete.jar -- VERBOSE=1

Other commands:
python setup.py --help-commands


### License

License in top folder applies to this project only.
In this repository there is also ANTRLR4 library (BSD 3-clause license) and some grammars (.g4 files - BSD 3, GPL-3, GPL).
This library is for now distributed in this package as a temporary solution until proper package for ANTLR4 library will be present in linux prepositories.


