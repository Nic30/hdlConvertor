#pragma once

#include <vector>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/compInstance.h"
#include "../hdlObjects/context.h"
#include "../hdlObjects/entity.h"
#include "../hdlObjects/variable.h"
#include "commentParser.h"

namespace hdlConvertor {
namespace verilog {

class ModuleParser {
	CommentParser & commentParser;
	hdlObjects::Context * context;
	bool hierarchyOnly;
	hdlObjects::Entity * ent;
	hdlObjects::Arch * arch;
public:
	using Variable = hdlObjects::Variable;
	using Expr = hdlObjects::Expr;
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;

	ModuleParser(CommentParser & commentParser, hdlObjects::Context * _context,
			bool _hierarchyOnly);
	void visitModule_declaration(
			Verilog2001Parser::Module_declarationContext * ctx);

	void visitModule_item(Verilog2001Parser::Module_itemContext * ctx);
	void visitModule_or_generate_item(
			Verilog2001Parser::Module_or_generate_itemContext * ctx);
	void visitModule_or_generate_item_declaration(
			Verilog2001Parser::Module_or_generate_item_declarationContext * ctx);
	void visitReg_declaration(Verilog2001Parser::Reg_declarationContext * ctx);
	void visitNet_declaration(Verilog2001Parser::Net_declarationContext * ctx);
	std::vector<Variable*> visitList_of_net_identifiers(
			Verilog2001Parser::List_of_net_identifiersContext * ctx,
			Expr * base_type);
	std::vector<Variable*> visitList_of_net_decl_assignments(
			Verilog2001Parser::List_of_net_decl_assignmentsContext * ctx,
			Expr * base_type);
	/*
	 * @note the variables may contains also the specification of the size of the array from this reason
	 * 		the base_type does not have to be final type of the variable
	 * @note base_type is used inn first variable, the rest will have copy
	 * */
	void visitList_of_variable_identifiers(
			Verilog2001Parser::List_of_variable_identifiersContext* ctx,
			Expr * base_type, bool latched);
	Variable * visitVariable_type(Verilog2001Parser::Variable_typeContext * ctx,
			Expr * base_type);
	Variable * visitVariable_identifier(
			Verilog2001Parser::Variable_identifierContext * ctx, Expr * t,
			Expr * def_val);
	void visitNon_port_module_item(
			Verilog2001Parser::Non_port_module_itemContext * ctx);

};

}
}
