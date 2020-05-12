#pragma once

#include <hdlConvertor/hdlAst/hdlModuleDec.h>
#include <hdlConvertor/hdlAst/hdlModuleDef.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>
#include <hdlConvertor/hdlAst/hdlCompInst.h>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>

#include <hdlConvertor/svConvertor/portParser.h>

namespace hdlConvertor {
namespace sv {

class VerModuleParser {
	SVCommentParser &commentParser;
	bool hierarchyOnly;

	// @note: non-ANSI ports are converted to ANSI ports after module body is parsed

public:
	class ModuleCtx {
	public:
		std::vector<VerPortParser::Non_ANSI_port_info_t> non_ANSI_port_groups;
		hdlAst::HdlModuleDec &ent;
		hdlAst::HdlModuleDef *arch;
		ModuleCtx(hdlAst::HdlModuleDec &_ent) :
				ent(_ent), arch(nullptr) {
		}
	};

	using sv2017Parser = sv2017_antlr::sv2017Parser;

	VerModuleParser(SVCommentParser &commentParser, bool _hierarchyOnly);
	void visitModule_header_common(
			sv2017Parser::Module_header_commonContext *ctx,
			hdlAst::HdlModuleDec &ent);
	void visitModule_declaration(sv2017Parser::Module_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res);
	void visitModule_item_item(sv2017Parser::Module_item_itemContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &param);
	void visitModule_item(sv2017Parser::Module_itemContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &objs,
			ModuleCtx &m_ctx);
	void visitNet_declaration(sv2017Parser::Net_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);
	void visitList_of_net_decl_assignments(
			sv2017Parser::List_of_net_decl_assignmentsContext *ctx,
			std::unique_ptr<hdlAst::iHdlExprItem> base_type, bool is_latched,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);

};

}
}
