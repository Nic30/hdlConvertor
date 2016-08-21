#!/bin/bash
set -o errexit

java -Xmx500M -cp "./lib/antlr4-4.5.4-SNAPSHOT.jar:$CLASSPATH" org.antlr.v4.Tool -Dlanguage=Cpp -visitor -no-listener vhdl.g4 -o VhdlParser -package vhdl
java -Xmx500M -cp "./lib/antlr4-4.5.4-SNAPSHOT.jar:$CLASSPATH" org.antlr.v4.Tool -Dlanguage=Cpp -visitor -no-listener Verilog2001.g4 -o VerilogParser -package verilog
java -Xmx500M -cp "./lib/antlr4-4.5.4-SNAPSHOT.jar:$CLASSPATH" org.antlr.v4.Tool -Dlanguage=Cpp -visitor -no-listener sv2012.g4 -o SVParser -package sv

rm -rf src/VhdlParser 
mv  VhdlParser src/

rm -rf src/VerilogParser 
mv  VerilogParser src/

rm -rf src/SVParser 
mv  SVParser src/
