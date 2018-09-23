
// Generated from /home/tom/prog/git/hdlConvertor/grammars/vpp.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "vppListener.h"


/**
 * This class provides an empty implementation of vppListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  vppBaseListener : public vppListener {
public:

  virtual void enterFile(vppParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(vppParser::FileContext * /*ctx*/) override { }

  virtual void enterPreprocess_directive(vppParser::Preprocess_directiveContext * /*ctx*/) override { }
  virtual void exitPreprocess_directive(vppParser::Preprocess_directiveContext * /*ctx*/) override { }

  virtual void enterDefine(vppParser::DefineContext * /*ctx*/) override { }
  virtual void exitDefine(vppParser::DefineContext * /*ctx*/) override { }

  virtual void enterReplacement(vppParser::ReplacementContext * /*ctx*/) override { }
  virtual void exitReplacement(vppParser::ReplacementContext * /*ctx*/) override { }

  virtual void enterUndef(vppParser::UndefContext * /*ctx*/) override { }
  virtual void exitUndef(vppParser::UndefContext * /*ctx*/) override { }

  virtual void enterConditional(vppParser::ConditionalContext * /*ctx*/) override { }
  virtual void exitConditional(vppParser::ConditionalContext * /*ctx*/) override { }

  virtual void enterIfdef_directive(vppParser::Ifdef_directiveContext * /*ctx*/) override { }
  virtual void exitIfdef_directive(vppParser::Ifdef_directiveContext * /*ctx*/) override { }

  virtual void enterIfndef_directive(vppParser::Ifndef_directiveContext * /*ctx*/) override { }
  virtual void exitIfndef_directive(vppParser::Ifndef_directiveContext * /*ctx*/) override { }

  virtual void enterIfdef_group_of_lines(vppParser::Ifdef_group_of_linesContext * /*ctx*/) override { }
  virtual void exitIfdef_group_of_lines(vppParser::Ifdef_group_of_linesContext * /*ctx*/) override { }

  virtual void enterIfndef_group_of_lines(vppParser::Ifndef_group_of_linesContext * /*ctx*/) override { }
  virtual void exitIfndef_group_of_lines(vppParser::Ifndef_group_of_linesContext * /*ctx*/) override { }

  virtual void enterElsif_group_of_lines(vppParser::Elsif_group_of_linesContext * /*ctx*/) override { }
  virtual void exitElsif_group_of_lines(vppParser::Elsif_group_of_linesContext * /*ctx*/) override { }

  virtual void enterElse_group_of_lines(vppParser::Else_group_of_linesContext * /*ctx*/) override { }
  virtual void exitElse_group_of_lines(vppParser::Else_group_of_linesContext * /*ctx*/) override { }

  virtual void enterGroup_of_lines(vppParser::Group_of_linesContext * /*ctx*/) override { }
  virtual void exitGroup_of_lines(vppParser::Group_of_linesContext * /*ctx*/) override { }

  virtual void enterToken_id(vppParser::Token_idContext * /*ctx*/) override { }
  virtual void exitToken_id(vppParser::Token_idContext * /*ctx*/) override { }

  virtual void enterInclude(vppParser::IncludeContext * /*ctx*/) override { }
  virtual void exitInclude(vppParser::IncludeContext * /*ctx*/) override { }

  virtual void enterMacro_id(vppParser::Macro_idContext * /*ctx*/) override { }
  virtual void exitMacro_id(vppParser::Macro_idContext * /*ctx*/) override { }

  virtual void enterMacro_toreplace(vppParser::Macro_toreplaceContext * /*ctx*/) override { }
  virtual void exitMacro_toreplace(vppParser::Macro_toreplaceContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

