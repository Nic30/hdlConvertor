#!/bin/bash
antlr4 -Dlanguage=Python3 proto_grammar/proto_grammar.g4 -package proto_grammar -no-listener
