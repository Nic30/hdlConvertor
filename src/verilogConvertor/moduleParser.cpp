#include "moduleParser.h"

ModuleParser::ModuleParser(Context * _context, bool _hierarchyOnly) {
	context = _context;
	hierarchyOnly = _hierarchyOnly;
	ent = new Entity();
}

void ModuleParser::visitModule_declaration(
		Verilog2001Parser::Module_declarationContext* ctx) {
	// module_declaration
	// : attribute_instance* module_keyword module_identifier
	// ( module_parameter_port_list )? ( list_of_ports )? ';' module_item*
	// 'endmodule'
	// | attribute_instance* module_keyword module_identifier
	// ( module_parameter_port_list )? ( list_of_port_declarations )? ';'
	// non_port_module_item*
	// 'endmodule'
	// ;
	ent->name = strdup(
			ctx->module_identifier()->identifier()->getText().c_str());
	for (auto a : ctx->attribute_instance()) {
		auto ais = AttributeParser::visitAttribute_instance(a);
		for (auto v : *ais)
			ent->generics.push_back(v);
		delete ais;
	}
	auto mppl = ctx->module_parameter_port_list();
	if (mppl) {
		auto ppls = visitModule_parameter_port_list(mppl);
		for (auto v : *ppls)
			ent->generics.push_back(v);
	}
	auto lop = ctx->list_of_ports();
	if (lop) {
		auto ps = PortParser::visitList_of_ports(lop);
		for (auto p : *ps) {
			ent->ports.push_back(p);
		}
		delete ps;
	}

	for (auto mi : ctx->module_item())
		visitModule_item(mi);

	auto lpd = ctx->list_of_port_declarations();
	if (lpd) {
		auto ps = PortParser::visitList_of_port_declarations(lpd);
		for (auto p : *ps) {
			ent->ports.push_back(p);
		}
		delete ps;
	}
	for (auto npmi : ctx->non_port_module_item())
		visitNon_port_module_item(npmi);

	context->entities.push_back(ent);
}

std::vector<Variable*>* ModuleParser::visitModule_parameter_port_list(
		Verilog2001Parser::Module_parameter_port_listContext* ctx) {
	// module_parameter_port_list : '#' '(' parameter_declaration_ ( ','
	// parameter_declaration_ )* ')' ;
	std::vector<Variable*>* vars = new std::vector<Variable*>();
	for (auto pd : ctx->parameter_declaration_()) {
		auto pds = visitParameter_declaration_(pd);
		for (auto pd : *pds)
			vars->push_back(pd);
		delete pds;
	}

	return vars;
}

std::vector<Variable*>* ModuleParser::visitParameter_declaration_(
		Verilog2001Parser::Parameter_declaration_Context* ctx) {
	//// split out semi on end. spec grammar is wrong. It won't allow
	//// #(parameter B=8) since it wants a ';' in (...). Rule
	//// module_parameter_port_list calls this one.

	// parameter_declaration_ :
	// 'parameter' ( 'signed' )? ( range_ )? list_of_param_assignments
	// |'parameter' 'integer' list_of_param_assignments
	// |'parameter' 'real' list_of_param_assignments
	// |'parameter' 'realtime' list_of_param_assignments
	// |'parameter' 'time' list_of_param_assignments
	// ;

	// [TODO] signed

	Expr * t = Utils::mkStringT();
	auto typeStr = ctx->children[1];
	auto term = dynamic_cast<antlr4::tree::TerminalNodeImpl*>(typeStr);
	if (term) {
		t = Expr::ID(term->getText());
	}

	auto r = ctx->range_();
	if (r) {
		std::vector<Expr*> * operands = new std::vector<Expr*>();
		operands->push_back(VerExprParser::visitRange_(r));
		t = Expr::call(Utils::mkWireT(), operands);
	}

	std::vector<Variable*> * params = visitList_of_param_assignments(
			ctx->list_of_param_assignments());

	std::shared_ptr<Expr> _t(t);
	for (auto v : *params)
		v->type = _t;

	return params;
}
std::vector<Variable*> *ModuleParser::visitList_of_param_assignments(
		Verilog2001Parser::List_of_param_assignmentsContext * ctx) {
	// list_of_param_assignments :
	// param_assignment ( ',' param_assignment )*
	// ;
	std::vector<Variable*>* params = new std::vector<Variable*>();
	for (auto pa : ctx->param_assignment())
		params->push_back(visitParam_assignment(pa));
	return params;

}
Variable * ModuleParser::visitParam_assignment(
		Verilog2001Parser::Param_assignmentContext* ctx) {
	// param_assignment : parameter_identifier '=' constant_expression ;
	auto value = VerExprParser::visitConstant_expression(
			ctx->constant_expression());
	Variable* p = new Variable(
			ctx->parameter_identifier()->identifier()->getText(), NULL, value);
	return p;
}

void ModuleParser::visitModule_item(
		Verilog2001Parser::Module_itemContext* ctx) {
	// module_item :
	// module_or_generate_item
	// | port_declaration ';'
	// | attribute_instance* generated_instantiation
	// | attribute_instance* local_parameter_declaration
	// | attribute_instance* parameter_declaration
	// | attribute_instance* specify_block
	// | attribute_instance* specparam_declaration
	// ;
	auto mog = ctx->module_or_generate_item();
	if (mog) {
		visitModule_or_generate_item(mog);
		return;
	}
	// [TODO] attribute_instance
	auto pd = ctx->port_declaration();
	if (pd) {
		auto portsDeclr = PortParser::visitPort_declaration(pd);
		for (auto declr : *portsDeclr) {
			Port * p = ent->getPortByName(declr->variable->name);
			p->direction = declr->direction;
			p->variable = declr->variable;
			declr->variable = NULL;
			delete declr;
		}
		delete portsDeclr;
		return;
	}
	auto gi = ctx->generated_instantiation();
	if (gi) {
		NotImplementedLogger::print("ModuleParser.generated_instantiation");
		return;
	}
	auto lpd = ctx->local_parameter_declaration();
	if (lpd) {
		NotImplementedLogger::print("ModuleParser.local_parameter_declaration");
		return;
	}
	auto pad = ctx->parameter_declaration();
	if (pad) {
		NotImplementedLogger::print("ModuleParser.parameter_declaration");
		return;
	}
	auto sb = ctx->specify_block();
	if (sb) {
		NotImplementedLogger::print("ModuleParser.specify_block");
		return;
	}
	auto spd = ctx->specparam_declaration();
	if(spd) {
		NotImplementedLogger::print("ModuleParser.specparam_declaration");
		return;
	}
	throw std::runtime_error("ModuleParser.visitModule_item - probably missing part of imolementation");
}

void ModuleParser::visitModule_or_generate_item(Verilog2001Parser::Module_or_generate_itemContext * ctx) {
	//module_or_generate_item
	//   : attribute_instance* module_or_generate_item_declaration
	//   | attribute_instance* parameter_override
	//   | attribute_instance* continuous_assign
	//   | attribute_instance* gate_instantiation
	////   | attribute_instance* udp_instantiation
	//   | attribute_instance* module_instantiation
	//   | attribute_instance* initial_construct
	//   | attribute_instance* always_construct
	//   ;

	// [TODO] attribute_instance
	auto mg = ctx->module_or_generate_item_declaration();
	if (mg) {
		NotImplementedLogger::print("ModuleParser.module_or_generate_item_declaration");
		return;
	}
	auto pa = ctx->parameter_override();
	if (pa) {
		NotImplementedLogger::print("ModuleParser.parameter_override");
		return;
	}
	auto ca = ctx->continuous_assign();
	if (ca) {
		NotImplementedLogger::print("ModuleParser.continuous_assign");
		return;
	}

	auto ga = ctx->gate_instantiation();
	if (ga) {
		NotImplementedLogger::print("ModuleParser.gate_instantiation");
		return;
	}

	auto mi = ctx->module_instantiation();
	if (mi) {
		NotImplementedLogger::print("ModuleParser.module_instantiation");
		return;
	}

	auto ic = ctx->initial_construct();
	if (ic) {
		NotImplementedLogger::print("ModuleParser.initial_construct");
		return;
	}

	auto a = ctx->always_construct();
	if (a) {
		NotImplementedLogger::print("ModuleParser.always_construct");
		return;
	}

	NotImplementedLogger::print("ModuleParser.visitModule_or_generate_item");
}

void ModuleParser::visitNon_port_module_item(
		Verilog2001Parser::Non_port_module_itemContext* ctx) {
	// non_port_module_item :
	// attribute_instance* generated_instantiation
	// | attribute_instance* local_parameter_declaration
	// | attribute_instance* module_or_generate_item
	// | attribute_instance* parameter_declaration
	// | attribute_instance* specify_block
	// | attribute_instance* specparam_declaration
	// ;
	NotImplementedLogger::print("ModuleParser.visitNon_port_module_item");
}
