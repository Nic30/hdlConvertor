
// Generated from /home/tom/prog/git/hdlConvertor/grammars/vpp.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "vppParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by vppParser.
 */
class  vppListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(vppParser::FileContext *ctx) = 0;
  virtual void exitFile(vppParser::FileContext *ctx) = 0;

  virtual void enterPreprocess_directive(vppParser::Preprocess_directiveContext *ctx) = 0;
  virtual void exitPreprocess_directive(vppParser::Preprocess_directiveContext *ctx) = 0;

  virtual void enterDefine(vppParser::DefineContext *ctx) = 0;
  virtual void exitDefine(vppParser::DefineContext *ctx) = 0;

  virtual void enterReplacement(vppParser::ReplacementContext *ctx) = 0;
  virtual void exitReplacement(vppParser::ReplacementContext *ctx) = 0;

  virtual void enterUndef(vppParser::UndefContext *ctx) = 0;
  virtual void exitUndef(vppParser::UndefContext *ctx) = 0;

  virtual void enterConditional(vppParser::ConditionalContext *ctx) = 0;
  virtual void exitConditional(vppParser::ConditionalContext *ctx) = 0;

  virtual void enterIfdef_directive(vppParser::Ifdef_directiveContext *ctx) = 0;
  virtual void exitIfdef_directive(vppParser::Ifdef_directiveContext *ctx) = 0;

  virtual void enterIfndef_directive(vppParser::Ifndef_directiveContext *ctx) = 0;
  virtual void exitIfndef_directive(vppParser::Ifndef_directiveContext *ctx) = 0;

  virtual void enterIfdef_group_of_lines(vppParser::Ifdef_group_of_linesContext *ctx) = 0;
  virtual void exitIfdef_group_of_lines(vppParser::Ifdef_group_of_linesContext *ctx) = 0;

  virtual void enterIfndef_group_of_lines(vppParser::Ifndef_group_of_linesContext *ctx) = 0;
  virtual void exitIfndef_group_of_lines(vppParser::Ifndef_group_of_linesContext *ctx) = 0;

  virtual void enterElsif_group_of_lines(vppParser::Elsif_group_of_linesContext *ctx) = 0;
  virtual void exitElsif_group_of_lines(vppParser::Elsif_group_of_linesContext *ctx) = 0;

  virtual void enterElse_group_of_lines(vppParser::Else_group_of_linesContext *ctx) = 0;
  virtual void exitElse_group_of_lines(vppParser::Else_group_of_linesContext *ctx) = 0;

  virtual void enterGroup_of_lines(vppParser::Group_of_linesContext *ctx) = 0;
  virtual void exitGroup_of_lines(vppParser::Group_of_linesContext *ctx) = 0;

  virtual void enterToken_id(vppParser::Token_idContext *ctx) = 0;
  virtual void exitToken_id(vppParser::Token_idContext *ctx) = 0;

  virtual void enterInclude(vppParser::IncludeContext *ctx) = 0;
  virtual void exitInclude(vppParser::IncludeContext *ctx) = 0;

  virtual void enterMacro_id(vppParser::Macro_idContext *ctx) = 0;
  virtual void exitMacro_id(vppParser::Macro_idContext *ctx) = 0;

  virtual void enterMacro_toreplace(vppParser::Macro_toreplaceContext *ctx) = 0;
  virtual void exitMacro_toreplace(vppParser::Macro_toreplaceContext *ctx) = 0;


};

