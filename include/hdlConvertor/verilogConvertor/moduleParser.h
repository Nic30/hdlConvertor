#pragma once

#include <vector>

#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>
#include <hdlConvertor/hdlObjects/hdlCompInstance.h>
#include <hdlConvertor/hdlObjects/hdlContext.h>
#include <hdlConvertor/verilogConvertor/commentParser.h>
#include <hdlConvertor/hdlObjects/hdlModuleDec.h>
#include <hdlConvertor/hdlObjects/hdlModuleDef.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace verilog {

class ModuleParser {
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;

	CommentParser & commentParser;
	hdlObjects::HdlContext * context;
	bool hierarchyOnly;
	hdlObjects::HdlModuleDec * ent;
	hdlObjects::HdlModuleDef * arch;

public:

	ModuleParser(CommentParser & commentParser,
			hdlObjects::HdlContext * _context, bool _hierarchyOnly);
	void visitModule_declaration(
			Verilog2001Parser::Module_declarationContext * ctx);

	void visitModule_item(Verilog2001Parser::Module_itemContext * ctx,
			std::vector<hdlObjects::iHdlObj*> & objs);
	void visitModule_or_generate_item(
			Verilog2001Parser::Module_or_generate_itemContext * ctx,
			std::vector<hdlObjects::iHdlObj*> & objs);
	void visitModule_or_generate_item_declaration(
			Verilog2001Parser::Module_or_generate_item_declarationContext * ctx);
	void visitInteger_declaration(
			Verilog2001Parser::Integer_declarationContext* ctx);
	void visitReg_declaration(Verilog2001Parser::Reg_declarationContext * ctx);
	void visitNet_declaration(Verilog2001Parser::Net_declarationContext * ctx);
	std::vector<hdlObjects::HdlVariableDef*> visitList_of_net_identifiers(
			Verilog2001Parser::List_of_net_identifiersContext * ctx,
			hdlObjects::iHdlExpr * base_type);
	std::vector<hdlObjects::HdlVariableDef*> visitList_of_net_decl_assignments(
			Verilog2001Parser::List_of_net_decl_assignmentsContext * ctx,
			hdlObjects::iHdlExpr * base_type);
	/*
	 * @note the variables may contains also the specification of the size of the array from this reason
	 * 		the base_type does not have to be final type of the variable
	 * @note base_type is used inn first variable, the rest will have copy
	 * */
	void visitList_of_variable_identifiers(
			Verilog2001Parser::List_of_variable_identifiersContext* ctx,
			hdlObjects::iHdlExpr * base_type, bool latched,
			const std::string & doc);
	hdlObjects::HdlVariableDef * visitVariable_type(
			Verilog2001Parser::Variable_typeContext * ctx,
			hdlObjects::iHdlExpr * base_type);
	hdlObjects::HdlVariableDef * visitVariable_identifier(
			Verilog2001Parser::Variable_identifierContext * ctx,
			hdlObjects::iHdlExpr * t, hdlObjects::iHdlExpr * def_val);
	void visitNon_port_module_item(
			Verilog2001Parser::Non_port_module_itemContext * ctx);

};

}
}
