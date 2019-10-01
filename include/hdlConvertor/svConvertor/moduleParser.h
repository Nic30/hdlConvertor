#pragma once

#include <hdlConvertor/hdlObjects/hdlContext.h>
#include <hdlConvertor/hdlObjects/hdlModuleDec.h>
#include <hdlConvertor/hdlObjects/hdlModuleDef.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>
#include <hdlConvertor/hdlObjects/hdlCompInstance.h>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>

#include <hdlConvertor/svConvertor/portParser.h>

namespace hdlConvertor {
namespace sv {

class VerModuleParser {
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	SVCommentParser &commentParser;
	hdlObjects::HdlContext *context;
	bool hierarchyOnly;

	// @note: non-ANSI ports are converted to ANSI ports after module body is parsed
	std::vector<VerPortParser::Non_ANSI_port_info_t> non_ANSI_port_groups;
	hdlObjects::HdlModuleDec *ent;
	hdlObjects::HdlModuleDef *arch;

public:

	VerModuleParser(SVCommentParser &commentParser, hdlObjects::HdlContext *_context,
			bool _hierarchyOnly);
	void visitModule_declaration(
			sv2017Parser::Module_declarationContext *ctx);

	void visitModule_item(sv2017Parser::Module_itemContext *ctx,
			std::vector<hdlObjects::iHdlObj*> &objs);
	void visitModule_or_generate_item(
			sv2017Parser::Module_or_generate_itemContext *ctx,
			std::vector<hdlObjects::iHdlObj*> &objs);
	void visitModule_or_generate_item_declaration(
			sv2017Parser::Module_or_generate_item_declarationContext *ctx);
	void visitInteger_declaration(
			sv2017Parser::Integer_declarationContext *ctx);
	void visitNet_declaration(sv2017Parser::Net_declarationContext *ctx);
	std::vector<hdlObjects::HdlVariableDef*> visitList_of_net_identifiers(
			sv2017Parser::List_of_net_identifiersContext *ctx,
			hdlObjects::iHdlExpr *base_type);
	std::vector<hdlObjects::HdlVariableDef*> visitList_of_net_decl_assignments(
			sv2017Parser::List_of_net_decl_assignmentsContext *ctx,
			hdlObjects::iHdlExpr *base_type);
	/*
	 * @note the variables may contains also the specification of the size of the array from this reason
	 * 		the base_type does not have to be final type of the variable
	 * @note base_type is used inn first variable, the rest will have copy
	 * */
	void visitList_of_variable_identifiers(
			sv2017Parser::List_of_variable_identifiersContext *ctx,
			hdlObjects::iHdlExpr *base_type, bool latched,
			const std::string &doc);
	hdlObjects::HdlVariableDef* visitVariable_type(
			sv2017Parser::Variable_typeContext *ctx,
			hdlObjects::iHdlExpr *base_type);
			hdlObjects::iHdlExpr *t, hdlObjects::iHdlExpr *def_val);
	void visitNon_port_module_item(
			sv2017Parser::Non_port_module_itemContext *ctx);

};

}
}
