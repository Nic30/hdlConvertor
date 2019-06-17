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

vPreprocessor::vPreprocessor(TokenStream & tokens,
		std::vector<filesystem::path> &incdir, bool _added_incdir,
		macroSymbol & defineDB,
		std::vector<filesystem::path> &stack_incfile, Language mode,
		size_t include_depth_limit) :
		_defineDB(defineDB), _tokens(*(CommonTokenStream *) &tokens), _incdir(
				incdir), added_incdir(_added_incdir), _stack_incfile(
				stack_incfile), _mode(mode), include_depth_limit(
				include_depth_limit), _rewriter(&tokens) {
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
}

template<typename CTX_T>
void processIfdef(vPreprocessor& sefl, CTX_T * ctx, bool is_negated,
		macroSymbol & defineDB, antlr4::TokenStreamRewriter & rewriter) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	bool en_in = !is_negated;
	auto cond_ids = ctx->cond_id();
	auto group_of_lines = ctx->group_of_lines();
	auto group_of_line = group_of_lines.begin();
	bool matched = false;
	misc::Interval token_to_keep;
	for (auto cond_id : cond_ids) {
		auto macro_name = cond_id->getText();
		auto is_defined = defineDB.find(macro_name) != defineDB.end();
		if (is_defined == en_in) {
			auto gl = *group_of_line;
			assert(gl);
			sefl.visitGroup_of_lines(gl);
			token_to_keep = gl->getSourceInterval();
			matched = true;
			break;
		}
		++group_of_line;
	}
	if (!matched && ctx->ELSE() != nullptr) {
		auto eg = ctx->else_group_of_lines();
		sefl.visitElse_group_of_lines(eg);
		token_to_keep = eg->getSourceInterval();
		matched = true;
	}
	auto token = ctx->getSourceInterval();
	if (matched) {
		rewriter.Delete(token.a, token_to_keep.a);
		rewriter.Delete(token_to_keep.b, token.b);
	} else {
		rewriter.Delete(token.a, token.b);
	}
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
	string body;

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

	vector<string> params;
	// test the number of argument
	auto _params = ctx->var_id();
	// the macro has argument so we take each of them and register them in
	// a vector<string>
	for (auto arg : _params) {
		params.push_back(arg->getText());
	}
	// for (auto a:data) { printf("  *%s*\n",a.c_str()); }
	// get the template
	if (ctx->replacement() != nullptr) {
		body = _tokens.getText(ctx->replacement()->getSourceInterval());
		remove_comment(ctx->replacement()->getStart(),
				ctx->replacement()->getStop(), &body);
		body = rtrim(body);
	}
	if (_mode < Language::SV2012) {
		assert(default_args.size() == 0);
	}
	bool has_params = ctx->children.size() >= 3
			&& ctx->children[2]->getText() == "(";
	auto item = new macro_replace(macroName, has_params, params, default_args,
			body);
	_defineDB.insert( { macroName, item });

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
	// printf("@%s %s\n",__PRETTY_FUNCTION__,ctx->getText().c_str());
	// token_id
	//     : BACKTICK macro_toreplace LP value? (MR_COMMA value? )* RP
	//     | BACKTICK macro_toreplace
	//     ;

	auto macroName = ctx->macro_toreplace()->getText();

	//create a macroPrototype object
	vector<string> args;
	bool has_args = ctx->children.size() > 2;
	if (has_args) {
		bool expected_value = true;
		bool last_was_comma = false;
		auto end = ctx->children.end();
		for (auto _c = ctx->children.begin() + 3; _c != end; ++_c) {
			auto & c = *_c;
			//printf("%s\n", c->getText().c_str());
			auto ch_text = c->getText();
			if (antlrcpp::is<tree::TerminalNode *>(c)) {
				if (expected_value
						&& (ch_text == "," || (last_was_comma && ch_text == ")"))) {
					// the case for macro(,)
					// must prevent case of macro()
					args.push_back("");
				}
				expected_value = true;
				last_was_comma = ch_text == ",";
			} else if (antlrcpp::is<verilogPreprocParser::ValueContext *>(c)) {
				string data = _tokens.getText(c->getSourceInterval());
				data = trim(data);
				args.push_back(data);
				expected_value = false;
				last_was_comma = false;
			}
		}
	}

	//printf("%s\n", ctx->macro_toreplace()->getText().c_str());
	//for (auto a : args) {
	//	printf("  *%s*\n", a.c_str());
	//}

	//test if the macro has already been defined
	if (_defineDB.find(macroName) == _defineDB.end()) {
		//The  macro has not yet been defined. It is an issue we throw an
		//exception
		string msg = macroName + " is not defined";
		throw ParseException(msg);
	}

	//build the replacement string by calling the replacement method of the
	//macro_replace object and the provided argument of the macro.
	string replacement = _defineDB[macroName]->replace(args, has_args);
	//printf("=>%s\n",replacement.c_str());

	if (_mode == Language::SV2012) {
		auto rm_str = [&replacement](string s, int n) {
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
	return nullptr;
}

// methode call after `ifdef `elsif `else is found
antlrcpp::Any vPreprocessor::visitIfdef_directive(
		verilogPreprocParser::Ifdef_directiveContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	processIfdef(*this, ctx, false, _defineDB, _rewriter);
	return nullptr;

}

// method call after `ifndef `elif `else tree is found
// See vPreprocessor::exitIfdef_directive for code comment
antlrcpp::Any vPreprocessor::visitIfndef_directive(
		verilogPreprocParser::Ifndef_directiveContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	processIfdef(*this, ctx, true, _defineDB, _rewriter);
	return nullptr;
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

	//iterator on the list of directoy
	auto incdir_iter = _incdir.begin();
	bool found = false;
	string StringLiteral = visit(ctx->stringLiteral());
	filesystem::path filename;
	// iterate on list of directory until we found the file.
	while (incdir_iter != _incdir.end() && found == false) {
		// build the filename
		filename = (*incdir_iter)
				/ StringLiteral.substr(1, StringLiteral.size() - 2);
		//Test if the file exist
		if (filesystem::exists(filename)) {
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
		_rewriter.Delete(token.a, token.b);
		filesystem::path my_incdir;
		if (added_incdir) {
			my_incdir = _incdir.back();
			_incdir.pop_back();
		}
		// run the pre-processor on it
		auto replacement = run_verilog_preproc_file(filename, _incdir,
				_defineDB, _stack_incfile, _mode);
		if (added_incdir) {
			_incdir.push_back(my_incdir);
		}
		//update the current source code
		_rewriter.insertAfter(ctx->getStop(), replacement);

	}
	return nullptr;
}

string run_verilog_preproc(ANTLRInputStream & input,
		vector<filesystem::path> &incdir, bool added_incdir,
		macroSymbol & defineDB, vector<filesystem::path> & stack_incfile,
		Language mode) {
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
	vPreprocessor extractor(tokens, incdir, added_incdir, defineDB,
			stack_incfile, mode);
	extractor.visit(tree);
	string res = extractor._rewriter.getText();
	return res;
}

string run_verilog_preproc_str(const string & input_str,
		vector<filesystem::path> & incdir, macroSymbol & defineDB,
		vector<filesystem::path> & stack_incfile, Language mode) {

	ANTLRInputStream input(input_str);
	input.name = "<string>";
	return run_verilog_preproc(input, incdir, false, defineDB, stack_incfile,
			mode);
}

string run_verilog_preproc_file(const filesystem::path & filename,
		vector<filesystem::path> &incdir, macroSymbol & defineDB,
		vector<filesystem::path> & stack_incfile, Language mode) {
	ANTLRFileStream input(filename.u8string());

	filesystem::path dir = filename.parent_path();
	bool add_to_inc_dir = std::find(incdir.begin(), incdir.end(), dir)
			== incdir.end();
	// register the include file on the include file stack
	stack_incfile.push_back(filename);

	if (add_to_inc_dir)
		incdir.push_back(dir);

	auto res = run_verilog_preproc(input, incdir, add_to_inc_dir, defineDB,
			stack_incfile, mode);
	if (add_to_inc_dir)
		incdir.pop_back();
	stack_incfile.pop_back();
	return res;
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
