#!/bin/bash
set -o errexit

java -Xmx500M -cp "./lib/antlr4-4.5.4-SNAPSHOT.jar:$CLASSPATH" org.antlr.v4.Tool -Dlanguage=Cpp -visitor vhdl.g4 -o VhdlParser -package vhdl
java -Xmx500M -cp "./lib/antlr4-4.5.4-SNAPSHOT.jar:$CLASSPATH" org.antlr.v4.Tool -Dlanguage=Cpp -visitor Verilog2001.g4 -o VerilogParser -package verilog


rm -rf src/VhdlParser 
mv  VhdlParser src/

rm -rf src/VerilogParser 
mv  VerilogParser src/

