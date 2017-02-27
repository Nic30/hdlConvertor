#!/bin/bash
set -o errexit

antlr4_createParser="java -Xmx500M -cp \"./lib/antlr-4.6-complete.jar:$CLASSPATH\" org.antlr.v4.Tool -Dlanguage=Cpp -visitor -no-listener"
eval "$antlr4_createParser vhdl.g4 -o VhdlParser -package vhdl"
eval "$antlr4_createParser Verilog2001.g4 -o VerilogParser -package verilog"
eval "$antlr4_createParser sv2012.g4 -o SVParser -package sv"

rm -rf src/VhdlParser 
mv  VhdlParser src/

rm -rf src/VerilogParser 
mv  VerilogParser src/

rm -rf src/SVParser 
mv  SVParser src/
