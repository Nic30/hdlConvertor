#include <hdlConvertor/verilogPreproc/verilogPreproc.h>
#include <hdlConvertor/verilogPreproc/macro_def_verilog.h>
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

VerilogPreproc::VerilogPreproc(TokenStream & tokens,
		std::vector<filesystem::path> &incdir, bool _added_incdir,
		MacroDB & defineDB, std::vector<filesystem::path> &stack_incfile,
		Language mode, size_t include_depth_limit) :
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

VerilogPreproc::~VerilogPreproc() {
}

template<typename CTX_T>
void processIfdef(VerilogPreproc& sefl, CTX_T * ctx, bool is_negated,
		MacroDB & defineDB, antlr4::TokenStreamRewriter & rewriter) {
	// printf("@%s\n", __PRETTY_FUNCTION__);
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
		rewriter.Delete(token.a, token_to_keep.a - 1);
		rewriter.Delete(token_to_keep.b + 1, token.b);
	} else {
		rewriter.Delete(token.a, token.b);
	}
}

void VerilogPreproc::replace_context_by_bank(antlr4::ParserRuleContext * ctx) {
	misc::Interval token = ctx->getSourceInterval();
	_rewriter.Delete(token.a, token.b);
}

antlrcpp::Any VerilogPreproc::visitResetall(
		verilogPreprocParser::ResetallContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitCelldefine(
		verilogPreprocParser::CelldefineContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitEndcelldefine(
		verilogPreprocParser::EndcelldefineContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitTiming_spec(
		verilogPreprocParser::Timing_specContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitDefault_nettype(
		verilogPreprocParser::Default_nettypeContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitUnconnected_drive(
		verilogPreprocParser::Unconnected_driveContext * ctx) {
	//printf("@%s",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitNounconnected_drive(
		verilogPreprocParser::Nounconnected_driveContext * ctx) {
	//printf("@%s",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitLine_directive(
		verilogPreprocParser::Line_directiveContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitKeywords_directive(
		verilogPreprocParser::Keywords_directiveContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitEndkeywords_directive(
		verilogPreprocParser::Endkeywords_directiveContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitPragma(
		verilogPreprocParser::PragmaContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitUndefineall(
		verilogPreprocParser::UndefineallContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	replace_context_by_bank(ctx);
	_defineDB.clear();
	return NULL;
}

antlrcpp::Any VerilogPreproc::visitDefine_args_with_def_val(
		verilogPreprocParser::Define_args_with_def_valContext *ctx) {
	auto params = ctx->param_with_def_val();
	auto res = new vector<MacroDefVerilog::param_info_t>();
	res->reserve(params.size());
	// define_args_with_def_val:
	// 	param_with_def_val ( DM_COMMA param_with_def_val )*
	// ;
	for (auto p : params) {
		// param_with_def_val:
		// 	var_id (DM_EQUAL default_text?) ?
		// ;
		MacroDefVerilog::param_info_t i;
		i.name = p->var_id()->getText();
		i.has_def_val = p->EQUAL() != nullptr;
		if (i.has_def_val) {
			auto dt = p->default_text();
			if (dt)
				i.def_val = dt->getText();
		}
		res->push_back(i);
	}
	return res;
}

antlrcpp::Any VerilogPreproc::visitDefine_args_basic(
		verilogPreprocParser::Define_args_basicContext *ctx) {
	// define_args_basic:
	// 	var_id ( DM_COMMA var_id )*
	// ;
	auto params = ctx->var_id();
	auto res = new vector<MacroDefVerilog::param_info_t>();
	res->reserve(params.size());
	for (auto p : params) {
		res->push_back( { p->getText(), false, "" });
	}
	return res;
}

//method call when the definition of a macro is found
antlrcpp::Any VerilogPreproc::visitDefine(
		verilogPreprocParser::DefineContext * ctx) {
	//printf("@%s - %s\n",__PRETTY_FUNCTION__,ctx->getText().c_str());
	// get the macro name
	string def_name = ctx->macro_id()->getText();
	//printf("%s\n", macroName.c_str());
	string body;

	auto da = ctx->define_args();
	vector<MacroDefVerilog::param_info_t> * params;
	vector<MacroDefVerilog::param_info_t> params_dummy;
	if (da)
		params = visitDefine_args(da);
	else {
		params = &params_dummy;
	}
	// get the template
	if (ctx->replacement() != nullptr) {
		body = _tokens.getText(ctx->replacement()->getSourceInterval());
		remove_comment(ctx->replacement()->getStart(),
				ctx->replacement()->getStop(), &body);
		body = rtrim(body);
	}
	bool has_params = da != nullptr;
	try {
		auto item = new MacroDefVerilog(def_name, has_params, *params, body);
		_defineDB.insert( { def_name, item });
	} catch (const ParseException & e) {
		throw_input_caused_error(ctx, e.what());
	}
	if (da)
		delete params;

	// the macro definition is replace by an empty string in the original
	// source code
	replace_context_by_bank(ctx);

	return NULL;
}

//method call when `undef macroID if found
antlrcpp::Any VerilogPreproc::visitUndef(
		verilogPreprocParser::UndefContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	// we simply remove the macro from the macroDB object. So it is not anymore
	// defined
	_defineDB.erase(ctx->ID()->getText());

	replace_context_by_bank(ctx);
	return NULL;
}

//method call when `macro is found in the source code
antlrcpp::Any VerilogPreproc::visitToken_id(
		verilogPreprocParser::Token_idContext * ctx) {
	// printf("@%s %s\n",__PRETTY_FUNCTION__,ctx->getText().c_str());
	// token_id:
	// 	OTHER_MACRO_NO_ARGS
	// 	| OTHER_MACRO_WITH_ARGS value? (COMMA value? )* RP )?
	// ;

	string macro_name;
	vector<string> args;
	bool has_args = false;
	auto no_args = ctx->OTHER_MACRO_NO_ARGS();
	if (no_args) {
		macro_name = no_args->getText().substr(1);
	} else {
		auto with_args = ctx->OTHER_MACRO_WITH_ARGS();
		assert(with_args);
		auto _macro_name = with_args->getText();
		size_t end_of_name = 1;
		for (; end_of_name < _macro_name.size(); end_of_name++) {
			auto c = _macro_name[end_of_name];
			if (!isalnum(c) && c != '_')
				break;
		}
		macro_name = _macro_name.substr(1, end_of_name - 1);

		has_args = true;
		//create a macroPrototype object
		bool expected_value = true;
		bool last_was_comma = false;
		auto end = ctx->children.end();
		for (auto _c = ctx->children.begin() + 1; _c != end; ++_c) {
			auto & c = *_c;
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

	//test if the macro has already been defined
	auto m = _defineDB.find(macro_name);
	if (m == _defineDB.end()) {
		throw_input_caused_error(ctx, macro_name + " is not defined");
	}

	//build the replacement string by calling the replacement method of the
	//macro_replace object and the provided argument of the macro.
	string replacement;
	try {
		replacement = m->second->replace(args, has_args, this, ctx);
	} catch (const ParseException & e) {
		throw_input_caused_error(ctx, e.what());
	}
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
	misc::Interval token = ctx->getSourceInterval();
	_rewriter.replace(token.a, token.b, replacement);
	return nullptr;
}

// method call after `ifdef `elsif `else is found
antlrcpp::Any VerilogPreproc::visitIfdef_directive(
		verilogPreprocParser::Ifdef_directiveContext * ctx) {
	//  printf("@%s\n",__PRETTY_FUNCTION__);
	processIfdef(*this, ctx, false, _defineDB, _rewriter);
	return nullptr;
}

// method call after `ifndef `elif `else tree is found
// See vPreprocessor::exitIfdef_directive for code comment
antlrcpp::Any VerilogPreproc::visitIfndef_directive(
		verilogPreprocParser::Ifndef_directiveContext * ctx) {
	//printf("@%s\n",__PRETTY_FUNCTION__);
	processIfdef(*this, ctx, true, _defineDB, _rewriter);
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitStringLiteral(
		verilogPreprocParser::StringLiteralContext *ctx) {
	string filestring = run_verilog_preproc_str(ctx->getText(), _incdir,
			_defineDB, _stack_incfile, _mode);
	return filestring;
}

//method call when `include is found
antlrcpp::Any VerilogPreproc::visitInclude(
		verilogPreprocParser::IncludeContext * ctx) {
	// printf("@%s\n",__PRETTY_FUNCTION__);
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
		throw_input_caused_error(ctx, msg);
	} else if (_stack_incfile.size() > include_depth_limit) {
		// test the number of nested include.
		// If so throw an exception
		stringstream msg;
		msg << "Nested include limit reach" << endl;
		for (auto f : _stack_incfile) {
			msg << "    " << f << endl;
		}
		throw_input_caused_error(ctx, msg.str());
	} else {
		//Well done. we are going to replace the content of the `include
		//directive by the content of the processed file
		misc::Interval token = ctx->getSourceInterval();
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

void VerilogPreproc::throw_input_caused_error(antlr4::ParserRuleContext * ctx,
		const std::string & _msg) {
	auto ts = _tokens.getTokenSource();
	auto s = ctx->start;
	stringstream msg;
	msg << ts->getSourceName() << ":";
	if (s)
		msg << ctx->start->getLine() << ":"
				<< ctx->start->getCharPositionInLine() << ":";
	msg << _msg;
	throw ParseException(msg.str());
}

string run_verilog_preproc(ANTLRInputStream & input,
		vector<filesystem::path> &incdir, bool added_incdir, MacroDB & defineDB,
		vector<filesystem::path> & stack_incfile, Language mode) {
	verilogPreprocLexer lexer(&input);
	lexer.mode = mode;
	lexer.reset(); // bug ?
	auto syntaxErrLogger = make_unique<SyntaxErrorLogger>();
	lexer.removeErrorListeners();
	lexer.addErrorListener(syntaxErrLogger.get());

	CommonTokenStream tokens(&lexer);

	verilogPreprocParser parser(&tokens);
	parser.removeErrorListeners();
	parser.addErrorListener(syntaxErrLogger.get());
	parser.mode = mode;

	tree::ParseTree *tree = parser.file();
	// cout << "tokens.size()=" << tokens.size() << endl;
	// for (size_t i = 0; i < tokens.size(); i++) {
	// 	cout << tokens.get(i)->toString() << endl;
	// }

	syntaxErrLogger->CheckErrors();

	VerilogPreproc extractor(tokens, incdir, added_incdir, defineDB,
			stack_incfile, mode);
	extractor.visit(tree);
	string res = extractor._rewriter.getText();
	return res;
}

string run_verilog_preproc_str(const string & input_str,
		vector<filesystem::path> & incdir, MacroDB & defineDB,
		vector<filesystem::path> & stack_incfile, Language mode) {
	ANTLRInputStream input(input_str);
	input.name = "<string>";
	return run_verilog_preproc(input, incdir, false, defineDB, stack_incfile,
			mode);
}

string run_verilog_preproc_file(const filesystem::path & filename,
		vector<filesystem::path> &incdir, MacroDB & defineDB,
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
void VerilogPreproc::remove_comment(Token * start, Token * end, string * str) {
	vector<Token *> cmtChannel;
	//Get the list of token between the start and the end of replacement rule.
	cmtChannel = _tokens.getTokens(start->getTokenIndex(),
			end->getTokenIndex());
	//For all those token we are going to their channel.
	//If the channel is of the kind we search then we search and removed it from the string.
	//TODO : replace by " " to preserve character position of the original source code
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
