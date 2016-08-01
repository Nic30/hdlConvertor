# hdlConvertor
[![Travis-ci Build Status](https://travis-ci.org/Nic30/hdlConvertor.png?branch=master)](https://travis-ci.org/Nic30/hdlConvertor)

[attention] there is bug in antlr4 c++ runtime which is causing non determinism of parser after issue https://github.com/DanMcLaughlin/antlr4/issues/12 and https://github.com/DanMcLaughlin/antlr4/issues/25 is fixed library should work as it used to 

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
`pip install hdlConvertor`
or for python3
`pip3 install hdlConvertor`

Currently package is testet only under python3.5.
