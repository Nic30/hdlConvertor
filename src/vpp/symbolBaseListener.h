
// Generated from /home/tom/prog/git/hdlConvertor/grammars/symbol.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "symbolListener.h"


/**
 * This class provides an empty implementation of symbolListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  symbolBaseListener : public symbolListener {
public:

  virtual void enterPattern(symbolParser::PatternContext * /*ctx*/) override { }
  virtual void exitPattern(symbolParser::PatternContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

