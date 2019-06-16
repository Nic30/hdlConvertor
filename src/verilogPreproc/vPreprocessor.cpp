#include <hdlConvertor/verilogPreproc/vPreprocessor.h>
#include <antlr4-common.h>
#include <antlr4-runtime.h>

namespace hdlConvertor {
namespace verilog_pp {

using namespace antlr4;
using namespace std;

using verilogPreprocParser = verilogPreproc_antlr::verilogPreprocParser;
using verilogPreprocLexer = verilogPreproc_antlr::verilogPreprocLexer;

void replaceStringInPlace(string& subject, const string& search,
		const string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
}

vPreprocessor::vPreprocessor(TokenStream & tokens, vector<string> &incdir,
		macroSymbol & defineDB, vector<string> &stack_incfile, Language mode,
		size_t include_depth_limit) :
		_defineDB(defineDB), _tokens(*(CommonTokenStream *) &tokens), _incdir(
				incdir), _stack_incfile(stack_incfile), _mode(mode), include_depth_limit(
				include_depth_limit), _rewriter(&tokens) {
	// [TODO] add dir of current file into _incdir if not present
	switch (mode) {
	case Language::VERILOG2001:
	case Language::VERILOG2005:
	case Language::SV2012:
	case Language::SV2017:
		break;
	default:
		throw std::runtime_error("vPreprocessor: unsupported mode");
	}
}

vPreprocessor::~vPreprocessor() {
	// [TODO] pop dir of this file if was added to incdir
}

string vPreprocessor::genBlank(size_t n) {
	string a_string;
	a_string.resize(n, ' ');
	return a_string;
}

void vPreprocessor::replace_context_by_bank(antlr4::ParserRuleContext * ctx) {
	misc::Interval token = ctx->getSourceInterval();
	string replacement = "";
	_rewriter.replace(token.a, token.b, replacement);
}

antlrcpp::Any vPreprocessor::visitResetall(
		verilogPreprocParser::ResetallContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitCelldefine(
		verilogPreprocParser::CelldefineContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitEndcelldefine(
		verilogPreprocParser::EndcelldefineContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitTiming_spec(
		verilogPreprocParser::Timing_specContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitDefault_nettype(
		verilogPreprocParser::Default_nettypeContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitUnconnected_drive(
		verilogPreprocParser::Unconnected_driveContext * ctx) {
	//printf("@%s",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitNounconnected_drive(
		verilogPreprocParser::Nounconnected_driveContext * ctx) {
	//printf("@%s",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitLine_directive(
		verilogPreprocParser::Line_directiveContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitKeywords_directive(
		verilogPreprocParser::Keywords_directiveContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitEndkeywords_directive(
		verilogPreprocParser::Endkeywords_directiveContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitPragma(
		verilogPreprocParser::PragmaContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitUndefineall(
		verilogPreprocParser::UndefineallContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	_defineDB.clear();
	return NULL;
}

antlrcpp::Any vPreprocessor::visitFile_nb(
		verilogPreprocParser::File_nbContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	misc::Interval token = ctx->getSourceInterval();
	string replacement = "\"" + _tokens.getSourceName() + "\"";
	_rewriter.replace(token.a, token.b, replacement);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitLine_nb(
		verilogPreprocParser::Line_nbContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	misc::Interval token = ctx->getSourceInterval();
	string replacement = to_string(ctx->getStart()->getLine());
	_rewriter.replace(token.a, token.b, replacement);
	return NULL;
}

//method call when the definition of a macro is found
antlrcpp::Any vPreprocessor::visitDefine(
		verilogPreprocParser::DefineContext * ctx) {
	//printf("@%s - %s\n",__PRETTY_FUNCTION__,ctx->getText().c_str());
	// get the macro name
	string macroName = ctx->macro_id()->getText();
	//printf("%s\n", macroName.c_str());
	string rep_data;


	map<string, string> default_args;

	for (unsigned int i = 0; i < ctx->children.size(); i++) {
		if (antlrcpp::is<verilogPreprocParser::Default_textContext *>(
				ctx->children[i])) {
			auto kw_name = ctx->children[i - 2]->getText();
			auto kw_val = ctx->children[i]->getText();
			//printf("arg: %s defaut: %s\n",kw_name.c_str(), kw_val.c_str());
			default_args[kw_name] = ctx->children[i]->getText();
		}
	}

	vector<string> data;
	// test the number of argument
	auto _params = ctx->var_id();
	// the macro has argument so we take each of them and register them in
	// a vector<string>
	for (auto arg : _params) {
		data.push_back(arg->getText());
	}
	// for (auto a:data) { printf("  *%s*\n",a.c_str()); }
	// get the template
	if (ctx->replacement() != nullptr) {
		rep_data = _tokens.getText(ctx->replacement()->getSourceInterval());
		remove_comment(ctx->replacement()->getStart(),
				ctx->replacement()->getStop(), &rep_data);
		rep_data = rtrim(rep_data);
	}
	if (_mode < Language::SV2012) {
		assert(default_args.size() == 0);
	}
	macro_replace * item = new macro_replace(macroName, rep_data, data, default_args);
	_defineDB.insert(pair<string, macro_replace*>(macroName, item), _incdir,
			_stack_incfile, _mode);

	// the macro definition is replace by an empty string in the original
	// source code
	//misc::Interval token = ctx->getSourceInterval();
	//_rewriter.replace(token.a, token.b, string(""));
	replace_context_by_bank(ctx);

	return NULL;
}

//method call when `undef macroID if found
antlrcpp::Any vPreprocessor::visitUndef(
		verilogPreprocParser::UndefContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	// we simply remove the macro from the macroDB object. So it is not anymore
	// defined
	_defineDB.erase(ctx->ID()->getText());

	replace_context_by_bank(ctx);
	return NULL;
}

//method call when `macro is found in the source code
antlrcpp::Any vPreprocessor::visitToken_id(
		verilogPreprocParser::Token_idContext * ctx) {
	//printf("@%s %s\n",__PRETTY_FUNCTION__,ctx->getText().c_str());

	//create a macroPrototype object
	vector<string> args;

	if (ctx->children.size() <= 4) {
	} else {
		string prevText;
		for (size_t i = 0; i < ctx->children.size(); i++) {
			//printf("%li : %s\n",i,ctx->children[i]->getText().c_str());
			auto ch_text = ctx->children[i]->getText();
			if (antlrcpp::is<tree::TerminalNode *>(ctx->children[i])) {
				if ((prevText == ctx->LP()->getText() && ch_text == string(","))
						|| (prevText == string(",") && ch_text == string(","))
						|| (prevText == string(",")
								&& ch_text == ctx->RP()->getText())) {
					args.push_back("");
				}
			} else if (antlrcpp::is<verilogPreprocParser::ValueContext *>(
					ctx->children[i])) {
				string data;
				data = _tokens.getText(ctx->children[i]->getSourceInterval());
				data = trim(data);
				args.push_back(data);
			}
			prevText = ch_text;
		}
	}
	/*
	 printf("%s\n", ctx->macro_toreplace()->getText().c_str());
	 for (auto a:args) {
	 printf("  *%s*\n",a.c_str());
	 }
	 */

	macroPrototype macro(ctx->macro_toreplace()->getText(), args);

	//test if the macro has already been defined
	if (_defineDB.find(macro.macroName) == _defineDB.end()) {
		//The  macro has not yet been defined. It is an issue we throw an
		//exception
		string msg = macro.macroName + " is not defined";
		throw ParseException(msg);
	}

	//build the replacement string by calling the replacement method of the
	//macro_replace object and the provided argument of the macro.
	string replacement = _defineDB[macro.macroName]->replace(macro.args);
	//printf("=>%s\n",replacement.c_str());

	if (_mode == Language::SV2012) {
		auto rm_str =
				[&replacement](string s, int n) {
					size_t start_pos = 0;
					while ((start_pos = replacement.find(s, start_pos))
								!= string::npos) {
						replacement.erase(start_pos, n);
						start_pos += 1;
					}
				};
		rm_str("``", 2);
		rm_str("`\\", 1);
		rm_str("`\"", 1);
	}

	if (replacement.find("`", 0) != string::npos) {
		replacement = run_verilog_preproc_str(replacement, _incdir, _defineDB,
				_stack_incfile, _mode);
	}

	// replace the original macro in the source code by the replacement string
	// we just setup
	//printf("%s->%s\n",ctx->getText().c_str(),replacement.c_str());
	misc::Interval token = ctx->getSourceInterval();
	_rewriter.replace(token.a, token.b, replacement);
	return NULL;
}

// methode call after `ifdef `elsif `else is found
antlrcpp::Any vPreprocessor::visitIfdef_directive(
		verilogPreprocParser::Ifdef_directiveContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);

	uint32_t cond_id_cpt = 0;
	macroSymbol::iterator search;
	string replacement = "";

	//get the source code match by the rule
	misc::Interval token = ctx->getSourceInterval();

	//search if the macro cond_id is in the macroDB object
	search = _defineDB.find(ctx->cond_id(0)->getText());

	if (search != _defineDB.end()) {
		//the macro cond_id object is defined
		//Get the source code to use when the macro is found
		visitIfdef_group_of_lines(ctx->ifdef_group_of_lines());
	} else {
		// process `elsif and `else
		cond_id_cpt++; // cond_id(0) is the one for the `ifdef so we start to cond_id(1)

		// process the multiple `elsif. There is ctx-cond_id().size() number of
		// `elsif
		while (cond_id_cpt < ctx->cond_id().size()) {
			// lookup if the current macro exist
			search = _defineDB.find(ctx->cond_id(cond_id_cpt)->getText());
			if (search != _defineDB.end()) {
				// the define exist so we process the relevant source code part
				visitElsif_group_of_lines(
						ctx->elsif_group_of_lines(cond_id_cpt));
				// Then we jump inconditionnaly to the end of the method
				goto exit_label;

			}
			//next cond_id
			cond_id_cpt++;
		}
		// all `elsif has been test
		// we test if the rule has match an else statement. That may or may not
		// exist
		if (ctx->ELSE() != nullptr) {
			visitElse_group_of_lines(ctx->else_group_of_lines());
		}
	}

	//perform the replacement of code.
	//But not if the cond_id is not one that match and if there is no `else
	//then we will replace the `ifdef `elsif by an empty string.
	//Because by default replacement is ""
	exit_label: _rewriter.replace(token.a, token.b, replacement);
	return NULL;

}

// method call after `ifndef `elif `else tree is found
// See vPreprocessor::exitIfdef_directive for code comment
antlrcpp::Any vPreprocessor::visitIfndef_directive(
		verilogPreprocParser::Ifndef_directiveContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);

	uint32_t cond_id_cpt = 0;
	macroSymbol::iterator search;
	string replacement = "";
	misc::Interval token = ctx->getSourceInterval();

	search = _defineDB.find(ctx->cond_id(0)->getText());
	if (search == _defineDB.end()) {
		visitIfndef_group_of_lines(ctx->ifndef_group_of_lines());
	} else {
		cond_id_cpt++;
		while (cond_id_cpt < ctx->cond_id().size()) {
			search = _defineDB.find(ctx->cond_id(cond_id_cpt)->getText());
			if (search != _defineDB.end()) {
				visitElsif_group_of_lines(
						ctx->elsif_group_of_lines(cond_id_cpt));
				goto exit_label;

			}
			cond_id_cpt++;
		}
		if (ctx->ELSE() != nullptr) {
			visitElse_group_of_lines(ctx->else_group_of_lines());
		}
	}

	exit_label: _rewriter.replace(token.a, token.b, replacement);
	return NULL;
}

antlrcpp::Any vPreprocessor::visitStringLiteral(
		verilogPreprocParser::StringLiteralContext *ctx) {
	string filestring = run_verilog_preproc_str(ctx->getText(), _incdir,
			_defineDB, _stack_incfile, _mode);
	return filestring;
}

//method call when `include is found
antlrcpp::Any vPreprocessor::visitInclude(
		verilogPreprocParser::IncludeContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);

	struct stat buffer;

	//iterator on the list of directoy
	vector<string>::iterator incdir_iter = _incdir.begin();
	bool found = false;
	string StringLiteral = visit(ctx->stringLiteral());
	string filename;
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
		string msg = StringLiteral.substr(1, StringLiteral.size() - 2)
				+ " was not found in include directories\n";
		throw ParseException(msg);
	} else if (_stack_incfile.size() > include_depth_limit) {
		// test the number of nested include.
		// If so throw an exception
		stringstream msg;
		msg << "Nested include limit reach" << endl;
		for (auto f : _stack_incfile) {
			msg << "    " << f << endl;
		}
		throw ParseException(msg.str());
	} else {
		//Well done. we are going to replace the content of the `include
		//directive by the content of the processed file

		misc::Interval token = ctx->getSourceInterval();
		//string replacement = genBlank(ctx->getText().size());
		string replacement;
		_rewriter.Delete(token.a, token.b);

		// register the include file on the include file stack
		_stack_incfile.push_back(filename);
		//printf("%s (%li)\n",filename.c_str(),buffer.st_size);

		// read the file
		// run the pre-processor on it
		replacement = run_verilog_preproc_file(filename, _incdir, _defineDB,
				_stack_incfile, _mode);

		//printf("%s pop\n",filename.c_str());
		//pop back the include file
		_stack_incfile.pop_back();

		//update the current source code
		_rewriter.insertAfter(ctx->getStop(), replacement);

	}
	return NULL;
}

string run_verilog_preproc(ANTLRInputStream & input, vector<string> &incdir,
		macroSymbol & defineDB, vector<string> & stack_incfile, Language mode) {
	verilogPreprocLexer lexer(&input);
	lexer.mode = mode;
	lexer.reset(); // bug ?
	CommonTokenStream tokens(&lexer);
	/*
	 tokens->fill();
	 for (auto token : tokens->getTokens()) {
	 cout << token->toString() << endl;
	 }
	 */
	verilogPreprocParser parser(&tokens);
	parser.mode = mode;
	tree::ParseTree *tree = parser.file();
	/*
	 cout << tree->toStringTree(parser) << endl << endl;
	 */
	vPreprocessor extractor(tokens, incdir, defineDB, stack_incfile, mode);
	extractor.visit(tree);
	string res = extractor._rewriter.getText();
	return res;
}

string run_verilog_preproc_str(const string & input_str,
		vector<string> & incdir, macroSymbol & defineDB,
		vector<string> & stack_incfile, Language mode) {

	ANTLRInputStream input(input_str);
	input.name = "<string>";
	return run_verilog_preproc(input, incdir, defineDB, stack_incfile, mode);
}

string run_verilog_preproc_file(const string & fileName, vector<string> &incdir,
		macroSymbol & defineDB, vector<string> & stack_incfile, Language mode) {
	ANTLRFileStream input(fileName);
	return run_verilog_preproc(input, incdir, defineDB, stack_incfile, mode);
}

string& rtrim(string& str, const string& chars) {
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

string& ltrim(string& str, const string& chars) {
	str = str.erase(0, str.find_first_not_of(chars));
	return str;
}

string& trim(string& str, const string& chars) {
	return rtrim(ltrim(str, chars), chars);
}

/*
 * Remove unwanted comment in text macro.
 * Line escape and Line comment have to be removed
 */
void vPreprocessor::remove_comment(Token * start, Token * end, string * str) {
	vector<Token *> cmtChannel;
	//Get the list of token between the start and the end of replacement rule.
	cmtChannel = _tokens.getTokens(start->getTokenIndex(),
			end->getTokenIndex());
	//For all those token we are going to their channel.
	//If the channel is of the kind we search then we search and removed it from the string.
	//TODO : replace by " " to preserve charactere position of the original source code
	for (auto cmt : cmtChannel) {
		if (cmt->getChannel() == verilogPreprocLexer::CH_LINE_ESCAPE) {
			string comment_txt = cmt->getText();
			replaceStringInPlace(*str, comment_txt, "\n");
		} else if (cmt->getChannel() == verilogPreprocLexer::CH_LINE_COMMENT) {
			string comment_txt = cmt->getText();
			replaceStringInPlace(*str, comment_txt, "");
		}
	}
}

}
}
