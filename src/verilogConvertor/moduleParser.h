#pragma once

#include <antlr4-runtime.h>
#include <vector>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/context.h"
#include "../hdlObjects/entity.h"

#include "attributeParser.h"
#include "portParser.h"
#include "exprParser.h"

using namespace antlr4;
using namespace Verilog2001;

class ModuleParser {
	Context * context;
	bool hierarchyOnly;
	Entity * ent;
	Arch * arch;
public:
	ModuleParser(Context * _context, bool _hierarchyOnly);
	void visitModule_declaration(
			Verilog2001Parser::Module_declarationContext * ctx);
	static std::vector<Variable*>* visitModule_parameter_port_list(
			Verilog2001Parser::Module_parameter_port_listContext * ctx);

	static std::vector<Variable*>* visitParameter_declaration_(
			Verilog2001Parser::Parameter_declaration_Context * ctx);
	static std::vector<Variable*> *visitList_of_param_assignments(
			Verilog2001Parser::List_of_param_assignmentsContext * ctx);
	static Variable * visitParam_assignment(
			Verilog2001Parser::Param_assignmentContext * ctx);

	void visitModule_item(Verilog2001Parser::Module_itemContext * ctx);
	void visitModule_or_generate_item(
			Verilog2001Parser::Module_or_generate_itemContext * ctx);
	void visitAlways_construct(
			Verilog2001Parser::Always_constructContext * ctx);
	void visitModule_or_generate_item_declaration(
			Verilog2001Parser::Module_or_generate_item_declarationContext * ctx);
	void visitReg_declaration(Verilog2001Parser::Reg_declarationContext * ctx);
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
