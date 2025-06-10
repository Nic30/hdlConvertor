#! /bin/sh

# :note: this script should be executed only in directory where antlr4-complete.jar is
CLASSPATH=antlr4-complete.jar
exec java -cp $CLASSPATH org.antlr.v4.Tool "$@"