#!/bin/bash
set -o errexit

ANTLR_VERSION="4.7"
ANTLR_JAR="antlr-$ANTLR_VERSION-complete.jar"
ANTLR_RUNTIME="antlr4-cpp-runtime-$ANTLR_VERSION-source.zip"

if [ ! -f $ANTLR_JAR ]; then
   # download if not exists
   wget http://www.antlr.org/download/$ANTLR_JAR
fi

# update antlr4 cpp runtime
# wget http://www.antlr.org/download/$ANTLR_RUNTIME
# rm src/antlr4-runtime-cpp/* -r
# unzip $ANTLR_RUNTIME "runtime/src/*" -d  src/antlr4-runtime-cpp
# mv src/antlr4-runtime-cpp/runtime/src/* src/antlr4-runtime-cpp
# rm -r src/antlr4-runtime-cpp/runtime

antlr4_createParser="java -Xmx500M -cp \"$ANTLR_JAR:$CLASSPATH\" org.antlr.v4.Tool -Dlanguage=Cpp -visitor -no-listener"
eval "$antlr4_createParser grammars/vhdl.g4 -o VhdlParser -package vhdl"
eval "$antlr4_createParser grammars/Verilog2001.g4 -o VerilogParser -package verilog"
eval "$antlr4_createParser grammars/sv2012.g4 -o SVParser -package sv"

rm -rf src/VhdlParser 
mv  VhdlParser src/

rm -rf src/VerilogParser 
mv  VerilogParser src/

rm -rf src/SVParser 
mv  SVParser src/
