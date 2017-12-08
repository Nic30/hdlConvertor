# hdlConvertor
[![Travis-ci Build Status](https://travis-ci.org/Nic30/hdlConvertor.png?branch=master)](https://travis-ci.org/Nic30/hdlConvertor)
[![PyPI version](https://badge.fury.io/py/hdlConvertor.svg)](http://badge.fury.io/py/hdlConvertor) 
(!!! Note that because of system verilog support it requires 3GB of RAM to build this and build tooks ~3min !!!)


verilog and vhdl parser module for python

In the meantime when there is no wiki yet you can take look at src/hdlObjects.
There are classes which are recognized in HDL langue and there are also toJson() for them.
This function is used for conversion to Python objects.

In python all parsed stuff are just dictionaries and values.

Top class of hdlObjects is Context, wich is container of all other hdl objects.

This project was extracted from https://github.com/Nic30/HWToolkit.
There is also Java version. But it seems that there is no use for it when there is a C++ version.

This project use a ANTLR4. Currently, there is no universal way of distributing ANTLR4 library known to me.
To make your live easier I included it to this package for you.


Package is stored in pip respository you can install it by:
`pip3 install hdlConvertor`
or download repository and run `python3 setup.py install`

Example of usage:
```python
import hdlConvertor
res = hdlConvertor.parse("yourfile.vhd", "vhdl")
for e in res['entities']:
    print(e['name'])

```


Currently package is testet only for python3.5 under linux but should work with every python3.x on any system where is compiler with c++11 support.

### Supported languages:

* VHDL 2002 (based on grammar https://guest.iis.ee.ethz.ch/~zimmi/download/vhdl02_syntax.html, https://github.com/antlr/grammars-v4/blob/master/vhdl/vhdl.g4 )

* Verilog 2001 (based on grammar http://www.syncad.com/VeriLogger_bnf_Syntax_Verilog_2001.htm, https://github.com/antlr/grammars-v4/blob/master/verilog/Verilog2001.g4)


* System Verilog 2012 (without preprocessor) (based on grammar http://insights.sigasi.com/tech/systemverilog.ebnf.html)


### Similar projects:

* https://github.com/Paebbels/pyVHDLParser - python vhdl parser with 2008 support

* https://github.com/kevinpt/hdlparse/ - vhdl/verilgo parser in python 

* https://github.com/denisgav/v2sc - vhdl to systemc
