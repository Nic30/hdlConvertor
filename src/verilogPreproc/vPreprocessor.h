
#pragma once

#include "antlr4-runtime.h"
#include "verilogPreprocParser/verilogPreprocLexer.h"
#include "verilogPreprocParser/verilogPreprocParser.h"
#include "verilogPreprocParser/verilogPreprocBaseListener.h"
#include <string>
#include <map>
#include <sys/stat.h>

#include "../verilogPreproc/macroPrototype.h"
#include "../verilogPreproc/macroSymbol.h"
#include "exception.h"

using namespace antlr4;


/*
 * Verilog preprocessor
 * :ivar _defineDB: database of defines
 * :ivar _incdir: directories where to search for included files (last will be searched first)
 * :ivar _stack_incfile: stack of include files which are currently parsed (used for detection of cycle in includes)
 **/
class vPreprocessor : public  verilogPreprocBaseListener {
  macroSymbol & _defineDB;
  CommonTokenStream * _tokens;
  std::vector<std::string> _incdir;
  std::vector<std::string> _stack_incfile;

  void remove_comment(Token * start, Token * end, std::string * str );
  std::string genBlank(size_t n);
  void replace_context_by_bank( antlr4::ParserRuleContext * ctx);

  public:
  size_t include_depth_limit;
  TokenStreamRewriter _rewriter;


  vPreprocessor(TokenStream *tokens,
      std::vector<std::string> &incdir,
      macroSymbol & defineDB,
      size_t include_depth_limit=100);
  ~vPreprocessor();

  virtual void enterResetall(verilogPreprocParser::ResetallContext * ctx);
  virtual void enterCelldefine(verilogPreprocParser::CelldefineContext * ctx);
  virtual void enterEndcelldefine(verilogPreprocParser::EndcelldefineContext * ctx);

  virtual void enterTiming_spec(verilogPreprocParser::Timing_specContext * ctx);
  virtual void enterDefault_nettype(verilogPreprocParser::Default_nettypeContext * ctx);
  virtual void enterUnconnected_drive(verilogPreprocParser::Unconnected_driveContext * ctx);
  virtual void enterNounconnected_drive(verilogPreprocParser::Nounconnected_driveContext * ctx);

  virtual void enterDefine(verilogPreprocParser::DefineContext * ctx);
  virtual void enterUndef(verilogPreprocParser::UndefContext * ctx);

  virtual void exitToken_id(verilogPreprocParser::Token_idContext * ctx);

  virtual void exitIfdef_directive(verilogPreprocParser::Ifdef_directiveContext * ctx);
  virtual void exitIfndef_directive(verilogPreprocParser::Ifndef_directiveContext * ctx);

  virtual void enterInclude(verilogPreprocParser::IncludeContext * ctx);
};

//call the preprocessor tool.
//argument are
// a string token
// a list of include directory (std::vector<std::string>)
// a object representing the list of already defined macro
std::string return_preprocessed(const std::string input_token,
    std::vector<std::string> &incdir,
    macroSymbol & defineDB);

std::string& rtrim(std::string& str, const std::string& chars = "\n\r");
