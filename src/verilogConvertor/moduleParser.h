#pragma once

#include <antlr4-runtime.h>
#include <vector>

#include "../VerilogParser/Verilog2001Parser.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/context.h"
#include "../hdlObjects/entity.h"

#include "attributeParser.h"
#include "portParser.h"
#include "exprParser.h"

using namespace antlr4;
using namespace verilog;

class ModuleParser {
	Context * context;
	bool hierarchyOnly;
	Entity * ent;
public:
	ModuleParser(Context * _context, bool _hierarchyOnly);
	void visitModule_declaration(
			Ref<Verilog2001Parser::Module_declarationContext> ctx);
	static std::vector<Variable*>* visitModule_parameter_port_list(
			Ref<Verilog2001Parser::Module_parameter_port_listContext> ctx);

	static std::vector<Variable*>* visitParameter_declaration_(
			Ref<Verilog2001Parser::Parameter_declaration_Context> ctx);
	static std::vector<Variable*> *visitList_of_param_assignments(
			Ref<Verilog2001Parser::List_of_param_assignmentsContext> ctx);
	static Variable * visitParam_assignment(
			Ref<Verilog2001Parser::Param_assignmentContext> ctx);

	void visitModule_item(Ref<Verilog2001Parser::Module_itemContext> ctx);
	void visitNon_port_module_item(
			Ref<Verilog2001Parser::Non_port_module_itemContext> ctx);

};
