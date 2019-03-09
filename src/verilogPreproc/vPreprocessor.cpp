#include "../verilogPreproc/vPreprocessor.h"

void ReplaceStringInPlace(std::string& subject, const std::string& search,
    const std::string& replace) {

  size_t pos = 0;
  while ((pos = subject.find(search, pos)) != std::string::npos) {
    subject.replace(pos, search.length(), replace);
    pos += replace.length();
  }
}

vPreprocessor::vPreprocessor(TokenStream *tokens,
    std::vector<std::string> &incdir, macroSymbol & defineDB,
    std::vector<std::string> &stack_incfile,
    unsigned int mode,
    size_t include_depth_limit) :
  _defineDB(defineDB),
  _rewriter(tokens), 
  _tokens((CommonTokenStream *) tokens), 
  _incdir(incdir),
  _mode(mode),
  _stack_incfile(stack_incfile),
  include_depth_limit(include_depth_limit) {
    // [TODO] add dir of current file into _incdir if not present
  }

vPreprocessor::~vPreprocessor() {
  // [TODO] pop dir of this file if was added to incdir
}

std::string vPreprocessor::genBlank(size_t n) {
  std::string a_string;
  a_string.resize(n, ' ');
  return a_string;
}

void vPreprocessor::replace_context_by_bank( antlr4::ParserRuleContext * ctx) {
    misc::Interval token = ctx->getSourceInterval();
    std::string replacement = "";
    _rewriter.replace(token.a, token.b, replacement);
}

antlrcpp::Any vPreprocessor::visitResetall(verilogPreprocParser::ResetallContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  return NULL;
}

antlrcpp::Any vPreprocessor::visitCelldefine(verilogPreprocParser::CelldefineContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  return NULL;
}

antlrcpp::Any vPreprocessor::visitEndcelldefine(verilogPreprocParser::EndcelldefineContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  return NULL;
}

antlrcpp::Any vPreprocessor::visitTiming_spec(verilogPreprocParser::Timing_specContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  return NULL;
}

antlrcpp::Any vPreprocessor::visitDefault_nettype(verilogPreprocParser::Default_nettypeContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  return NULL;
}

antlrcpp::Any vPreprocessor::visitUnconnected_drive(verilogPreprocParser::Unconnected_driveContext * ctx) {
  //printf("@%s",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  return NULL;
}

antlrcpp::Any vPreprocessor::visitNounconnected_drive(verilogPreprocParser::Nounconnected_driveContext * ctx) {
  //printf("@%s",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  return NULL;
}

antlrcpp::Any vPreprocessor::visitLine_directive(verilogPreprocParser::Line_directiveContext * ctx){
  //printf("@%s\n",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  return NULL;
}	

antlrcpp::Any vPreprocessor::visitKeywords_directive(verilogPreprocParser::Keywords_directiveContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  return NULL;
}

antlrcpp::Any vPreprocessor::visitEndkeywords_directive(verilogPreprocParser::Endkeywords_directiveContext * ctx){
  //printf("@%s\n",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  return NULL;
}

antlrcpp::Any vPreprocessor::visitPragma(verilogPreprocParser::PragmaContext * ctx){
  //printf("@%s\n",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  return NULL;
}

antlrcpp::Any vPreprocessor::visitUndefineall(verilogPreprocParser::UndefineallContext * ctx){
  //printf("@%s\n",__PRETTY_FUNCTION__);
  replace_context_by_bank(ctx);
  _defineDB.clear();
  return NULL;
}

antlrcpp::Any vPreprocessor::visitFile_nb(verilogPreprocParser::File_nbContext * ctx){
  //printf("@%s\n",__PRETTY_FUNCTION__);
    misc::Interval token = ctx->getSourceInterval();
    std::string replacement = _tokens->getSourceName();
    _rewriter.replace(token.a, token.b, replacement);
  return NULL;
}

antlrcpp::Any vPreprocessor::visitLine_nb(verilogPreprocParser::Line_nbContext * ctx){
  //printf("@%s\n",__PRETTY_FUNCTION__);
    misc::Interval token = ctx->getSourceInterval();
    std::string replacement = std::to_string(ctx->getStart()->getLine());
    _rewriter.replace(token.a, token.b, replacement);
  return NULL;
}

//method call when the definition of a macro is found
antlrcpp::Any vPreprocessor::visitDefine(verilogPreprocParser::DefineContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);
  // get the macro name
  //printf("%s\n",ctx->getText().c_str());
  std::string macroName = ctx->macro_id()->getText();
  //printf("%s\n",macroName.c_str());
  std::string rep_data;
  
  macro_replace * item ;
  std::map<std::string,std::string> default_args;

  for(unsigned int i=0; i< ctx->children.size(); i++){
    if (antlrcpp::is<verilogPreprocParser::Default_textContext *>(ctx->children[i])) {
        //printf("arg: %s defaut: %s\n",ctx->children[i-2]->getText().c_str(), ctx->children[i]->getText().c_str());
	default_args[ctx->children[i-2]->getText()] = ctx->children[i]->getText();
      }
  }

  // test the number of argument
  if (ctx->ID().size() != 0) {
    // the macro has argument so we take each of them and register them in
    // a std::vector<std::string>
    std::vector<std::string> data;
    for (auto arg : ctx->ID()) {
      data.push_back(arg->getText());
    }


//    for (auto a:data) {
//      printf("  *%s*\n",a.c_str());
//    }

    // get the template
    rep_data = _tokens->getText(ctx->replacement()-> getSourceInterval());
    remove_comment(ctx->replacement()->getStart(),ctx->replacement()->getStop(),&rep_data);

    rep_data = rtrim(rep_data);

    // add the macro to the macroDB object
    if (_mode == SV2012) {
       item = new macro_replace_sv(macroName,rep_data, data, default_args);
    }
    else {
       item = new macro_replace(macroName,rep_data, data);
    }
    _defineDB.insert(
        std::pair<std::string, macro_replace*>(macroName, item),
        _incdir,_stack_incfile,_mode);
  } else {
    // The macro has no argument
    std::vector<std::string> data;
    // test if a template is provided
    if (ctx->replacement() != NULL) {
      // a template is provide.
      // So we add a macro with an empty argument list to the macroDB
      // object
      rep_data = _tokens->getText(ctx->replacement()-> getSourceInterval());
      remove_comment(ctx->replacement()->getStart(),ctx->replacement()->getStop(),&rep_data);
      rep_data = rtrim(rep_data);
      if (_mode == SV2012) {
        item = new macro_replace_sv(macroName,rep_data, data, default_args);
      }
      else {
        item = new macro_replace(macroName,rep_data, data);
      }
      _defineDB.insert(
          std::pair<std::string, macro_replace*>(macroName, item),
          _incdir,_stack_incfile,_mode);
    } else {
      // no template is provided
      // So we add a macro with empty string as template and no argument
      // to the macroDB object
      if (_mode == SV2012) {
        item = new macro_replace_sv(macroName,rep_data, data, default_args);
      }
      else {
        item = new macro_replace(macroName,rep_data, data);
      }
      _defineDB.insert(
          std::pair<std::string, macro_replace*>(macroName, item),
          _incdir,_stack_incfile,_mode);
    }
  }

  // the macro definition is replace by an empty string in the original
  // source code
  //misc::Interval token = ctx->getSourceInterval();
  //_rewriter.replace(token.a, token.b, std::string(""));
  replace_context_by_bank(ctx);  

  return NULL;
}

//method call when `undef macroID if found
antlrcpp::Any vPreprocessor::visitUndef(verilogPreprocParser::UndefContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);
  // we simply remove the macro from the macroDB object. So it is not anymore
  // defined
  _defineDB.erase(ctx->ID()->getText());
  
  replace_context_by_bank(ctx);  
  return NULL;
}

//method call when `macro is found in the source code
antlrcpp::Any vPreprocessor::visitToken_id(verilogPreprocParser::Token_idContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);
  if (_stack_incfile.size() > 0) {
    return NULL;
  }
  //printf("%s\n",_tokens->getText(ctx->getSourceInterval()).c_str());
  //create a macroPrototype object
  std::vector<std::string> args;
  
  //if (ctx->LP() == nullptr || ctx->children.size()<=4) {
  if (ctx->children.size()<=4) {
  //}
  //else if (ctx->COMMA().size() == 0 || ctx->value().size() == 1) {
  //  args.push_back(ctx->value(0)->getText());
  } else {
     std::string prevText;
     for(size_t i=0; i < ctx->children.size(); i++) {
	//printf("%li : %s\n",i,ctx->children[i]->getText().c_str());
	if (antlrcpp::is<tree::TerminalNode *>(ctx->children[i])) {
	  //std::cout << "prevText: " << prevText << " current: " << ctx->children[i]->getText() <<std::endl;
	  if (
	     //(prevText == ctx->LP()->getText() && ctx->children[i]->getText() == ctx->COMMA(0)->getText()) ||
	     (prevText == ctx->LP()->getText() && ctx->children[i]->getText() == std::string(",")) ||
	     //(prevText == ctx->COMMA(0)->getText() && ctx->children[i]->getText() == ctx->COMMA(0)->getText()) ||
	     (prevText == std::string(",") && ctx->children[i]->getText() == std::string(",")) ||
	     //(prevText == ctx->COMMA(0)->getText() && ctx->children[i]->getText() == ctx->RP()->getText())
	     (prevText == std::string(",") && ctx->children[i]->getText() == ctx->RP()->getText())
	     ) {
             args.push_back("");
	  }
	}
	else if (antlrcpp::is<verilogPreprocParser::ValueContext *>(ctx->children[i]))  {
	  args.push_back(_tokens->getText(ctx->children[i]->getSourceInterval()).c_str());
	}
	prevText = ctx->children[i]->getText();
     }
  }
  /* 
  for (auto a:args) {
    printf("  *%s*\n",a.c_str());
  }
  */
  
  macroPrototype macro(ctx->macro_toreplace()->getText(),args);

  //test if the macro has already been defined
  if (_defineDB.find(macro.macroName) == _defineDB.end()) {
    //The  macro has not yet been defined. It is an issue we throw an
    //exception
    std::string msg = macro.macroName + " is not defined";
    throw parseException(msg);
  }

  //build the replacement string by calling the replacement method of the
  //macro_replace object and the provided argument of the macro.
  std::string replacement = _defineDB[macro.macroName]->replace(macro.args);
  //printf("%s\n",replacement.c_str());
  
  if (_mode == SV2012) {
    size_t start_pos = 0;
    while((start_pos = replacement.find("``", start_pos)) != std::string::npos) {
      replacement.erase(start_pos,2);
      start_pos += 1;
    }
    start_pos = 0;
    while((start_pos = replacement.find("`\\", start_pos)) != std::string::npos) {
      replacement.erase(start_pos,1);
      start_pos += 1;
    }
    start_pos = 0;
    while((start_pos = replacement.find("`\"", start_pos)) != std::string::npos) {
      replacement.erase(start_pos,1);
      start_pos += 1;
    }
  
  }
  
  replacement = return_preprocessed(replacement,_incdir,_defineDB,_stack_incfile,_mode);
  // replace the original macro in the source code by the replacement string
  // we just setup
  //printf("%s->%s\n",ctx->getText().c_str(),replacement.c_str());
  misc::Interval token = ctx->getSourceInterval();
  _rewriter.replace(token.a, token.b, replacement);
  return NULL;
}

// methode call after `ifdef `elsif `else is found
antlrcpp::Any vPreprocessor::visitIfdef_directive(
//void vPreprocessor::enterIfdef_directive(
    verilogPreprocParser::Ifdef_directiveContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);
  
  //printf("exitIfdef_directive\n");

  uint32_t ID_cpt = 0;
  macroSymbol::iterator search;
  std::string replacement = "";

  //get the source code match by the rule
  misc::Interval token = ctx->getSourceInterval();

  //search if the macro ID is in the macroDB object
  search = _defineDB.find(ctx->ID(0)->getText());

  if (search != _defineDB.end()) {
    //the macro ID object is defined
    //Get the source code to use when the macro is found
    misc::Interval interval =
      ctx->ifdef_group_of_lines()->getSourceInterval();
    // process it
    replacement = return_preprocessed(_tokens->getText(interval), _incdir,
        _defineDB,_stack_incfile,_mode);
  } else {
    // process `elsif and `else
    ID_cpt++; // ID(0) is the one for the `ifdef so we start to ID(1)

    // process the multiple `elsif. There is ctx-ID().size() number of
    // `elsif
    while (ID_cpt < ctx->ID().size()) {
      // lookup if the current macro exist
      search = _defineDB.find(ctx->ID(ID_cpt)->getText());
      if (search != _defineDB.end()) {
        // the define exist to we process the relevant source code part
        misc::Interval interval =
          ctx->elsif_group_of_lines(ID_cpt)->getSourceInterval();
        replacement = return_preprocessed(_tokens->getText(interval),
            _incdir, _defineDB,_stack_incfile,_mode);
        // Because found the first macro that exist. we jump
        // inconditionnaly to the end of the method
        goto exit_label;

      }
      //next ID
      ID_cpt++;
    }
    // all `elsif has been test
    // we test if the rule has match an else statement. That may or may not
    // exist
    if (ctx->ELSE() != nullptr) {
      misc::Interval interval =
        ctx->else_group_of_lines()->getSourceInterval();
      replacement = return_preprocessed(_tokens->getText(interval),
          _incdir, _defineDB,_stack_incfile,_mode);
    }
  }

  //perform the replacement of code.
  //But not if the ID is not one that match and if there is no `else
  //then we will replace the `ifdef `elsif by an empty string.
  //Because by default replacement is ""
  exit_label: _rewriter.replace(token.a, token.b, replacement);
  return NULL;

}

// method call after `ifndef `elif `else tree is found
// See vPreprocessor::exitIfdef_directive for code comment
antlrcpp::Any vPreprocessor::visitIfndef_directive(
//void vPreprocessor::enterIfndef_directive(
    verilogPreprocParser::Ifndef_directiveContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);

  //printf("exitIfndef_directive\n");

  uint32_t ID_cpt = 0;
  macroSymbol::iterator search;
  std::string replacement = "";
  misc::Interval token = ctx->getSourceInterval();

  search = _defineDB.find(ctx->ID(0)->getText());
  if (search == _defineDB.end()) {
    misc::Interval interval =
      ctx->ifndef_group_of_lines()->getSourceInterval();
    replacement = return_preprocessed(_tokens->getText(interval), _incdir,
        _defineDB,_stack_incfile,_mode);
  } else {
    ID_cpt++;
    while (ID_cpt < ctx->ID().size()) {
      search = _defineDB.find(ctx->ID(ID_cpt)->getText());
      if (search != _defineDB.end()) {
        misc::Interval interval =
          ctx->elsif_group_of_lines(ID_cpt)->getSourceInterval();
        replacement = return_preprocessed(_tokens->getText(interval),
            _incdir, _defineDB,_stack_incfile,_mode);
        goto exit_label;

      }
      ID_cpt++;
    }
    if (ctx->ELSE() != nullptr) {
      misc::Interval interval =
        ctx->else_group_of_lines()->getSourceInterval();
      replacement = return_preprocessed(_tokens->getText(interval),
          _incdir, _defineDB,_stack_incfile,_mode);

    }
  }

  exit_label: _rewriter.replace(token.a, token.b, replacement);
  return NULL;
}

//method call when `include is found
antlrcpp::Any vPreprocessor::visitInclude(verilogPreprocParser::IncludeContext * ctx) {
  //printf("@%s\n",__PRETTY_FUNCTION__);

  struct stat buffer;

  //iterator on the list of directoy
  std::vector<std::string>::iterator incdir_iter = _incdir.begin();
  bool found = false;
  std::string StringLiteral = ctx->stringLiteral()->getText();
  std::string filename;
  // iterate on list of directory until we found the file. 
  while (incdir_iter != _incdir.end() && found == false) {
    // build the filename
    // TODO: this code is not system agnostic ... it won't work on window.
    filename = (*incdir_iter) + '/'
      + StringLiteral.substr(1, StringLiteral.size() - 2);
    //Test if the file exist
    if (stat(filename.c_str(), &buffer) == 0) {
      // the file exist. we rise the flag to leave the loop over the
      // directory list
      found = true;
    }
    //continue on next directory
    incdir_iter++;
  }

  if (found == false) {
    // The file was not found. We throw a exception
    std::string msg = StringLiteral.substr(1, StringLiteral.size() - 2)
      + " was not found in include directory\n";
    throw parseException(msg);
  } else if (_stack_incfile.size() > include_depth_limit) {
    // test the number of nested include. 
    // If so throw an exception
    std::stringstream msg;
    msg << "Nested include limit reach" << std::endl;
    for (auto f : _stack_incfile) {
      msg << "    " << f << std::endl;
    }
    throw parseException(msg.str());
  } else {
    //Well done. we are going to replace the content of the `include
    //directive by the content of the processed file

    misc::Interval token = ctx->getSourceInterval();
    //std::string replacement = genBlank(ctx->getText().size());
    std::string replacement;
    _rewriter.Delete(token.a, token.b);

    // register the include file on the include file stack
    _stack_incfile.push_back(filename);
    //printf("%s (%li)\n",filename.c_str(),buffer.st_size);

    // read the file
    std::ifstream t(filename);
    std::string str((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());
    // run the pre-processor on it
    replacement = return_preprocessed(str, _incdir, _defineDB,_stack_incfile,_mode);

    //printf("%s pop\n",filename.c_str());
    //pop back the include file
    _stack_incfile.pop_back();

    //update the current source code
    _rewriter.insertAfter(ctx->getStop(), replacement);

  }
  return NULL;
}

std::string return_preprocessed(const std::string input_str,
    std::vector<std::string> &incdir, macroSymbol & defineDB, 
    std::vector<std::string> & stack_incfile,
    unsigned int mode) {
  //printf("@%s\n",__PRETTY_FUNCTION__);
  //printf("@return_preprocessed*%s*\n",input_str.c_str());

  ANTLRInputStream input(input_str);
  verilogPreprocLexer * lexer = new verilogPreprocLexer(&input);
  lexer->mode = mode;
  CommonTokenStream * tokens = new CommonTokenStream(lexer);
  /*
  tokens->fill();
  for (auto token : tokens->getTokens()) {
    std::cout << token->toString() << std::endl;
  }
  */
  verilogPreprocParser * parser = new verilogPreprocParser(tokens);
  parser->mode = mode;
  tree::ParseTree *tree = parser->file();
  /*
  std::cout << tree->toStringTree(parser) << std::endl << std::endl;
  */
  //tree::ParseTreeWalker walker = tree::ParseTreeWalker();
  vPreprocessor * extractor = new vPreprocessor(tokens,incdir, defineDB, stack_incfile, mode);
  //walker.walk((tree::ParseTreeListener*) extractor, tree);
  extractor->visit(tree);
  std::string return_value = extractor->_rewriter.getText();
  delete extractor;
  delete parser;
  delete tokens;
  delete lexer;
  return return_value;
}

std::string& rtrim(std::string& str, const std::string& chars ) {
  str.erase(str.find_last_not_of(chars) + 1);
  return str;
}

/*
 * Remove unwanted comment in text macro.
 * Line escape and Line comment have to be removed
 */
void vPreprocessor::remove_comment(Token * start, Token * end, std::string * str){
  
  std::vector<Token *> cmtChannel;
  //Get the list of token between the start and the end of replacement rule.
  cmtChannel = _tokens->getTokens( start->getTokenIndex(),
      end->getTokenIndex()
      );
  //For all those token we are going to their channel.
  //If the channel is of the kind we search then we search and removed it from the string.
  //TODO : replace by " " to preserve charactere position of the original source code
  for (auto cmt :cmtChannel) {

    if (cmt->getChannel() == verilogPreprocLexer::CH_LINE_ESCAPE) {
      std::string comment_txt = cmt->getText();
      ReplaceStringInPlace(*str, comment_txt,"\n");
    }
    else if (cmt->getChannel() == verilogPreprocLexer::CH_LINE_COMMENT) {
      std::string comment_txt = cmt->getText();
      ReplaceStringInPlace(*str, comment_txt,"");
    }
  }
}
