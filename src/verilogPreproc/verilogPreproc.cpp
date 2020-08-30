#include <hdlConvertor/verilogPreproc/verilogPreproc.h>

// antlr4-runtime/
#include <ParserRuleContext.h>
#include <misc/Interval.h>

#include <hdlConvertor/verilogPreproc/macro_def_verilog.h>

using namespace antlr4;
using namespace std;

namespace hdlConvertor {
namespace verilog_pp {

using verilogPreprocParser = verilogPreproc_antlr::verilogPreprocParser;
using verilogPreprocLexer = verilogPreproc_antlr::verilogPreprocLexer;

VerilogPreproc::VerilogPreproc(VerilogPreprocContainer &_container,
		VerilogPreprocOutBuffer &_preproc_out, TokenStream &tokens,
		bool _added_incdir, const std::string _encoding, size_t include_depth_limit) :
		container(_container), _tokens(*(CommonTokenStream*) &tokens), added_incdir(
				_added_incdir), include_depth_limit(include_depth_limit), preproc_out(
				_preproc_out), encoding(_encoding) {
	switch (container.lang) {
	case Language::VERILOG1995:
	case Language::VERILOG2001:
	case Language::VERILOG2001_NOCONFIG:
	case Language::VERILOG2005:
	case Language::SV2005:
	case Language::SV2009:
	case Language::SV2012:
	case Language::SV2017:
		break;
	default:
		throw std::runtime_error("vPreprocessor: unsupported language");
	}
}

VerilogPreproc::~VerilogPreproc() {
}

antlrcpp::Any VerilogPreproc::visitText(
		verilogPreprocParser::TextContext *ctx) {
	// text:
	//    preprocess_directive
	//   | LINE_COMMENT
	//   | CODE
	//   | NEW_LINE
	//   | NUM
	//   | ID
	//   | STR
	//   | NEW_LINE
	//   | COMMENT
	//   ;
	auto c = ctx->children[0];
	auto pd =
			dynamic_cast<verilogPreprocParser::Preprocess_directiveContext*>(c);
	if (pd) {
		return visitPreprocess_directive(pd);
	} else {
		preproc_out.set_input_line(ctx->getStart()->getLine() - 1);
		auto str = ctx->getText();
		preproc_out << str;
		return nullptr;
	}

}

antlrcpp::Any VerilogPreproc::visitResetall(
		verilogPreprocParser::ResetallContext*) {
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitCelldefine(
		verilogPreprocParser::CelldefineContext*) {
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitEndcelldefine(
		verilogPreprocParser::EndcelldefineContext*) {
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitTiming_spec(
		verilogPreprocParser::Timing_specContext*) {
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitDefault_nettype(
		verilogPreprocParser::Default_nettypeContext*) {
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitUnconnected_drive(
		verilogPreprocParser::Unconnected_driveContext*) {
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitNounconnected_drive(
		verilogPreprocParser::Nounconnected_driveContext*) {
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitKeywords_directive(
		verilogPreprocParser::Keywords_directiveContext*) {
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitEndkeywords_directive(
		verilogPreprocParser::Endkeywords_directiveContext*) {
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitPragma(
		verilogPreprocParser::PragmaContext*) {
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitLine_directive(
		verilogPreprocParser::Line_directiveContext *ctx) {
	auto file = ctx->STR()->getText();
	// [todo] process also level parameter (last)
	std::istringstream line_no_str(ctx->NUM(0)->getText());
	size_t line;
	line_no_str >> line;
	preproc_out.set_input_line(file, line);
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitUndef(
		verilogPreprocParser::UndefContext *ctx) {
	// we simply remove the macro from the macroDB object. So it is not anymore
	// defined
	auto m = container.defineDB.find(ctx->ID()->getText());
	if (m != container.defineDB.end() && !m->second->is_persistent) {
		container.defineDB.erase(m);
		delete m->second;
	}

	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitUndefineall(
		verilogPreprocParser::UndefineallContext*) {
	container.delete_non_persystent_macro_defs();
	return nullptr;
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
		verilogPreprocParser::DefineContext *ctx) {
	// get the macro name
	auto da = ctx->define_args();
	vector<MacroDefVerilog::param_info_t> *params;
	vector<MacroDefVerilog::param_info_t> params_dummy;
	if (da)
		params = visitDefine_args(da);
	else {
		params = &params_dummy;
	}

	string def_name = ctx->macro_id()->getText();
	string body;
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
		container.defineDB.insert( { def_name, item });
	} catch (const ParseException &e) {
		throw_input_caused_error(ctx, e.what());
	}
	if (da)
		delete params;

	// the macro definition is replace by an empty string in the original
	// source code
	return nullptr;
}

void VerilogPreproc::parse_macro_args(
		verilogPreprocParser::Macro_callContext *ctx, vector<string> &args) {
	//create a macroPrototype object
	bool expected_value = true;
	bool last_was_comma = false;
	auto end = ctx->children.end();
	for (auto _c = ctx->children.begin() + 1; _c != end; ++_c) {
		auto &c = *_c;
		string ch_text = c->getText();
		if (antlrcpp::is<tree::TerminalNode*>(c)) {
			if (expected_value
					&& (ch_text == "," || (last_was_comma && ch_text == ")"))) {
				// the case for macro(,)
				// must prevent case of macro()
				args.push_back("");
			}
			expected_value = true;
			last_was_comma = ch_text == ",";
		} else if (antlrcpp::is<verilogPreprocParser::ValueContext*>(c)) {
			string data = _tokens.getText(c->getSourceInterval());
			data = trim(data);
			args.push_back(data);
			expected_value = false;
			last_was_comma = false;
		}
	}
}
//method call when `macro is found in the source code
antlrcpp::Any VerilogPreproc::visitMacro_call(
		verilogPreprocParser::Macro_callContext *ctx) {
	return visitMacro_call(ctx, true);
}
antlrcpp::Any VerilogPreproc::visitMacro_call(
		verilogPreprocParser::Macro_callContext *ctx, bool add_to_output) {
	// macro_call:
	// 	OTHER_MACRO_CALL_NO_ARGS
	// 	| OTHER_MACRO_CALL_WITH_ARGS value? (COMMA value? )* RP
	// ;

	string macro_name;
	vector<string> args;
	bool has_args = false;
	auto no_args = ctx->OTHER_MACRO_CALL_NO_ARGS();
	if (no_args) {
		macro_name = no_args->getText();
	} else {
		auto with_args = ctx->OTHER_MACRO_CALL_WITH_ARGS();
		assert(with_args);
		auto _macro_name = with_args->getText();
		size_t name_len = 1;
		for (; name_len < _macro_name.size(); name_len++) {
			auto c = _macro_name[name_len];
			if (!isalnum(c) && c != '_')
				break;
		}
		macro_name = _macro_name.substr(0, name_len);
		has_args = true;
	}

	//test if the macro has already been defined
	auto m = container.defineDB.find(macro_name);
	if (m == container.defineDB.end()) {
		throw_input_caused_error(ctx, macro_name + " is not defined");
	}

	//build the replacement string by calling the replacement method of the
	//macro_replace object and the provided argument of the macro.
	bool _has_args = has_args;
	if (m->second->requires_args()) {
		if (has_args) {
			parse_macro_args(ctx, args);
		}
	} else {
		_has_args = false;
	}
	string replacement;
	try {
		replacement = m->second->replace(args, _has_args, this, ctx);
	} catch (const ParseException &e) {
		throw_input_caused_error(ctx, e.what());
	}
	if (!m->second->requires_args() && has_args) {
		// args belongs to the code and not to macro
		auto a = ctx->start->getStartIndex() + macro_name.size();
		auto b = ctx->stop->getStopIndex();
		auto args_str = ctx->start->getInputStream()->getText(
				misc::Interval(a, b));
		replacement += args_str;
	}

	if (container.lang >= Language::SV2005) {
		replace_substring(replacement, "``", "");
		replace_substring(replacement, "`\\`", "\\");
	}

	if (replacement.find("`", 0) != string::npos) {
		if (container.macro_call_stack.size()
				>= container.max_macro_call_stack_size) {
			throw_input_caused_error(ctx,
					std::string("Macro call stack overflow ")
							+ vector_to_string(container.macro_call_stack)
							+ ".");
		}
		container.macro_call_stack.push_back(macro_name);
		auto input_line_no = preproc_out.input_line_begin + ctx->start->getLine() - 1;
		VerilogPreprocOutBuffer _replacement(input_line_no);
		container.run_preproc_str(replacement, "utf-8", _replacement);
		// [todo] it is expected that the macro call won't cause any change in
		//        file line map directly
		//assert(_replacement.file_line_map.size() <= 1);
		replacement = _replacement.str();
		container.macro_call_stack.pop_back();
	}

	if (container.lang >= Language::SV2005) {
		unescape_string_dblquotes(replacement);
	}

	if (add_to_output) {
		// replace the original macro in the source code by the replacement string
		// we just setup
		preproc_out.set_input_line(ctx->getStart()->getLine() - 1);
		preproc_out << replacement;
	}
	return replacement;
}

/*
 * @param is_negated is used to reverse polarity of condition (ifdef/ifndef difference)
 * */
template<typename CTX_T>
void processIfdef(VerilogPreproc &self, CTX_T *ctx, bool is_negated,
		VerilogPreprocContainer &container, VerilogPreprocOutBuffer &out) {
	bool en_in = !is_negated;
	auto cond_ids = ctx->cond_id();
	auto group_of_lines = ctx->group_of_lines();
	auto group_of_line = group_of_lines.begin();
	antlr4::ParserRuleContext *branch_to_keep = nullptr;
	for (auto cond_id : cond_ids) {
		auto macro_name = cond_id->getText();
		auto is_defined = container.defineDB.find(macro_name)
				!= container.defineDB.end();
		if (is_defined == en_in) {
			auto gl = *group_of_line;
			assert(gl);
			branch_to_keep = gl;
			out.set_input_line(branch_to_keep->getStart()->getLine() - 1);
			self.visitGroup_of_lines(gl);
			break;
		}
		++group_of_line;
	}
	if (!branch_to_keep && ctx->ELSE() != nullptr) {
		auto eg = ctx->else_group_of_lines();
		branch_to_keep = eg;
		out.set_input_line(branch_to_keep->getStart()->getLine() - 1);
		self.visitElse_group_of_lines(eg);
	}
}

antlrcpp::Any VerilogPreproc::visitIfdef_directive(
		verilogPreprocParser::Ifdef_directiveContext *ctx) {
	processIfdef(*this, ctx, false, container, preproc_out);
	return nullptr;
}

antlrcpp::Any VerilogPreproc::visitIfndef_directive(
		verilogPreprocParser::Ifndef_directiveContext *ctx) {
	processIfdef(*this, ctx, true, container, preproc_out);
	return nullptr;
}

//method call when `include is found
antlrcpp::Any VerilogPreproc::visitInclude(
		verilogPreprocParser::IncludeContext *ctx) {
	//iterator on the list of inc. directory
	auto incdir_iter = container.incdirs.begin();
	bool found = false;
	string inc_file_path;
	auto mc = ctx->macro_call();
	if (mc) {
		inc_file_path = visitMacro_call(mc, false).as<string>();
	} else {
		inc_file_path = ctx->STR()->getText();
	}
	filesystem::path filename;
	// iterate on list of directory until we found the file.
	while (incdir_iter != container.incdirs.end() && found == false) {
		// build the filename
		filename = (*incdir_iter)
				/ inc_file_path.substr(1, inc_file_path.size() - 2);
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
		string msg = inc_file_path //.substr(1, inc_file_path.size() - 2)
		+ " was not found in include directories\n";
		throw_input_caused_error(ctx, msg);
	} else if (container.incfile_stack.size() > include_depth_limit) {
		// test the number of nested include.
		// If so throw an exception
		stringstream msg;
		msg << "Nested include limit reach" << endl;
		for (auto f : container.incfile_stack) {
			msg << "    " << f.first << endl;
		}
		throw_input_caused_error(ctx, msg.str());
	} else {
		// We are going to replace the content of the `include
		// directive by the content of the processed file
		filesystem::path my_incdir;
		if (added_incdir) {
			my_incdir = container.incdirs.back();
			container.incdirs.pop_back();
		}
		// run the pre-processor on it
		VerilogPreprocOutBuffer replacement(0);
		container.run_preproc_file(filename, encoding, replacement);
		if (added_incdir) {
			container.incdirs.push_back(my_incdir);
		}
		//update the current source code
		preproc_out << replacement;
	}
	return nullptr;
}

void VerilogPreproc::throw_input_caused_error(antlr4::ParserRuleContext *ctx,
		const std::string &_msg) {
	auto ts = _tokens.getTokenSource();
	auto s = ctx->start;
	// [todo] use line offsets and file to reconstruct position in original code
	stringstream msg;
	msg << ts->getSourceName() << ":";
	if (s) {
		// [TODO] use line offset from preproc_out
		msg << ctx->start->getLine() << ":"
				<< ctx->start->getCharPositionInLine() << ":";
	}
	msg << "Error: ";
	msg << _msg;
	throw ParseException(msg.str());
}

/*
 * Remove unwanted comment in text macro.
 * Line escape and Line comment have to be removed
 */
void VerilogPreproc::remove_comment(Token *start, Token *end, string *str) {
	//Get the list of token between the start and the end of replacement rule.
	vector<Token*> cmtChannel = _tokens.getTokens(start->getTokenIndex(),
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
