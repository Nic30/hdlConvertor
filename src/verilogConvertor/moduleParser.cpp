#include <hdlConvertor/verilogConvertor/moduleParser.h>
#include <hdlConvertor/notImplementedLogger.h>

#include <hdlConvertor/verilogConvertor/attributeParser.h>
#include <hdlConvertor/verilogConvertor/portParser.h>
#include <hdlConvertor/verilogConvertor/exprParser.h>
#include <hdlConvertor/verilogConvertor/statementParser.h>
#include <hdlConvertor/verilogConvertor/moduleInstanceParser.h>
#include <hdlConvertor/verilogConvertor/utils.h>
#include <hdlConvertor/verilogConvertor/moduleParamParser.h>

namespace hdlConvertor {
namespace verilog {

using namespace std;
using namespace Verilog2001_antlr;
using namespace hdlConvertor::hdlObjects;

ModuleParser::ModuleParser(CommentParser & commentParser, HdlContext * _context,
		bool _hierarchyOnly) :
		commentParser(commentParser) {
	context = _context;
	hierarchyOnly = _hierarchyOnly;
	ent = new HdlModuleDec();
	arch = new HdlModuleDef();
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
	ent->__doc__ = commentParser.parse(ctx);
	ent->name = ctx->module_identifier()->getText();
	if (ctx->attribute_instance().size()) {
		NotImplementedLogger::print(
				"ModuleParser.visitModule_declaration.attribute_instance", ctx);
		//auto ais = AttributeParser::visitAttribute_instance(a);
		//for (auto v : *ais)
		//	delete v;
		//delete ais;
	}
	auto mppl = ctx->module_parameter_port_list();
	if (mppl) {
		ModuleParamParser pp(commentParser);
		auto ppls = pp.visitModule_parameter_port_list(mppl);
		for (auto v : *ppls)
			ent->generics.push_back(v);
	}
	auto lop = ctx->list_of_ports();
	if (lop) {
		PortParser pp(commentParser);
		auto ps = pp.visitList_of_ports(lop);
		for (auto p : *ps) {
			ent->ports.push_back(p);
		}
		delete ps;
	}

	for (auto mi : ctx->module_item())
		visitModule_item(mi, arch->objs);

	auto lpd = ctx->list_of_port_declarations();
	if (lpd) {
		PortParser pp(commentParser);
		auto ps = pp.visitList_of_port_declarations(lpd);
		for (auto p : *ps) {
			ent->ports.push_back(p);
		}
		delete ps;
	}
	for (auto npmi : ctx->non_port_module_item())
		visitNon_port_module_item(npmi);

	context->objs.push_back(ent);
	arch->entityName = iHdlExpr::ID(ent->name);
	context->objs.push_back(arch);
}

void ModuleParser::visitModule_item(Verilog2001Parser::Module_itemContext* ctx,
		std::vector<hdlObjects::iHdlObj*> & objs) {
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
		visitModule_or_generate_item(mog, objs);
		return;
	}
	auto ai = ctx->attribute_instance();
	if (ai.size()) {
		NotImplementedLogger::print(
				"ModuleParser.module_item.attribute_instance", ctx);
	}
	auto pd = ctx->port_declaration();
	if (pd) {
		string doc = commentParser.parse(ctx);
		bool first = true;
		PortParser pp(commentParser);
		auto portsDeclr = pp.visitPort_declaration(pd);
		for (auto declr : *portsDeclr) {
			HdlVariableDef * p = ent->getPortByName(declr->name);
			p->direction = declr->direction;
			assert(p != nullptr);
			p->type = declr->type;
			p->value = declr->value;
			assert(p->value == nullptr);
			p->is_latched |= declr->is_latched;
			p->is_const |= declr->is_const;
			if (p->direction == HdlDirection::DIR_UNKNOWN)
				p->direction = declr->direction;
			if (first) {
				p->__doc__ += doc;
				first = false;
			}
			delete declr;
		}
		delete portsDeclr;
		return;
	}
	auto gi = ctx->generated_instantiation();
	if (gi) {
		NotImplementedLogger::print("ModuleParser.generated_instantiation", gi);
		return;
	}
	auto lpd = ctx->local_parameter_declaration();
	if (lpd) {
		NotImplementedLogger::print("ModuleParser.local_parameter_declaration",
				lpd);
		return;
	}
	auto pad = ctx->parameter_declaration();
	if (pad) {
		ModuleParamParser pp(commentParser);
		// [TODO] sync with params defined in module header
		auto ppls = pp.visitParameter_declaration(pad);
		for (auto v : *ppls)
			ent->generics.push_back(v);
		return;
	}
	auto sb = ctx->specify_block();
	if (sb) {
		NotImplementedLogger::print("ModuleParser.specify_block", sb);
		return;
	}
	auto spd = ctx->specparam_declaration();
	if (spd) {
		NotImplementedLogger::print("ModuleParser.specparam_declaration", spd);
		return;
	}
	throw std::runtime_error(
			"ModuleParser.visitModule_item - probably missing part of implementation");
}

void ModuleParser::visitModule_or_generate_item(
		Verilog2001Parser::Module_or_generate_itemContext * ctx,
		std::vector<hdlObjects::iHdlObj*> & objs) {
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

	auto ai = ctx->attribute_instance();
	if (ai.size()) {
		NotImplementedLogger::print(
				"ModuleParser.visitModule_or_generate_item.attribute_instance",
				ctx);
	}
	auto mg = ctx->module_or_generate_item_declaration();
	if (mg) {
		visitModule_or_generate_item_declaration(mg);
		return;
	}
	auto pa = ctx->parameter_override();
	if (pa) {
		NotImplementedLogger::print("ModuleParser.parameter_override", pa);
		return;
	}
	auto ca = ctx->continuous_assign();
	if (ca) {
		VerStatementParser stmp(commentParser);
		for (auto stm : stmp.vistContinuous_assign(ca))
			objs.push_back(stm);
		return;
	}

	auto ga = ctx->gate_instantiation();
	if (ga) {
		NotImplementedLogger::print("ModuleParser.gate_instantiation", ga);
		return;
	}

	auto mi = ctx->module_instantiation();
	if (mi) {
		auto components = ModuleInstanceParser::visitModule_instantiation(mi);
		for (auto c : components) {
			objs.push_back(c);
		}
		return;
	}

	auto ic = ctx->initial_construct();
	if (ic) {
		VerStatementParser vsp(commentParser);
		auto p = vsp.visitInitial_construct(ic);
		objs.push_back(p);
		return;
	}

	auto a = ctx->always_construct();
	if (a) {
		VerStatementParser vsp(commentParser);
		auto stm = vsp.visitAlways_construct(a);
		if (stm.first)
			objs.push_back(stm.first);
		else if (stm.second) {
			for (iHdlStatement * s : *stm.second) {
				objs.push_back(s);
			}
		}
		return;
	}

	NotImplementedLogger::print("ModuleParser.visitModule_or_generate_item",
			ctx);
}

void ModuleParser::visitModule_or_generate_item_declaration(
		Verilog2001Parser::Module_or_generate_item_declarationContext * ctx) {
	// module_or_generate_item_declaration
	//    : net_declaration
	//    | reg_declaration
	//    | integer_declaration
	//    | real_declaration
	//    | time_declaration
	//    | realtime_declaration
	//    | event_declaration
	//    | genvar_declaration
	//    | task_declaration
	//    | function_declaration
	//    ;

	auto nd = ctx->net_declaration();
	if (nd) {
		visitNet_declaration(nd);
		return;
	}
	auto rd = ctx->reg_declaration();
	if (rd) {
		visitReg_declaration(rd);
		return;
	}
	auto id = ctx->integer_declaration();
	if (id) {
		visitInteger_declaration(id);
		return;
	}
	auto red = ctx->real_declaration();
	if (red) {
		NotImplementedLogger::print("ModuleParser.real_declaration", red);
		return;
	}
	auto td = ctx->time_declaration();
	if (td) {
		NotImplementedLogger::print("ModuleParser.time_declaration", td);
		return;
	}
	auto rtd = ctx->realtime_declaration();
	if (rtd) {
		NotImplementedLogger::print("ModuleParser.realtime_declaration", rtd);
		return;
	}
	auto ed = ctx->event_declaration();
	if (ed) {
		NotImplementedLogger::print("ModuleParser.event_declaration", ed);
		return;
	}
	auto gd = ctx->genvar_declaration();
	if (gd) {
		NotImplementedLogger::print("ModuleParser.genvar_declaration", gd);
		return;
	}
	auto tad = ctx->task_declaration();
	if (tad) {
		NotImplementedLogger::print("ModuleParser.task_declaration", tad);
		return;
	}
	auto fd = ctx->function_declaration();
	if (fd) {
		NotImplementedLogger::print("ModuleParser.function_declaration", fd);
		return;
	}

	NotImplementedLogger::print(
			"ModuleParser.module_or_generate_item_declaration", ctx);
}

void ModuleParser::visitInteger_declaration(
		Verilog2001Parser::Integer_declarationContext* ctx) {
	// integer_declaration
	//    : 'integer' list_of_variable_identifiers ';'
	//    ;
	auto t = Utils::mkIntT();
	auto doc = commentParser.parse(ctx);
	visitList_of_variable_identifiers(ctx->list_of_variable_identifiers(), t,
			true, doc);
}

void ModuleParser::visitReg_declaration(
		Verilog2001Parser::Reg_declarationContext * ctx) {
	// reg_declaration
	//    : 'reg' ('signed')? (range_)? list_of_variable_identifiers ';'
	//    ;
	auto t = Utils::mkWireT(ctx->range_(), Utils::is_signed(ctx));
	auto doc = commentParser.parse(ctx);
	visitList_of_variable_identifiers(ctx->list_of_variable_identifiers(), t,
			true, doc);
}

void ModuleParser::visitNet_declaration(
		Verilog2001Parser::Net_declarationContext * ctx) {
	// net_declaration
	//    : net_type ('signed')? (delay3)? list_of_net_identifiers ';'
	//    | net_type (drive_strength)? ('signed')? (delay3)? list_of_net_decl_assignments ';'
	//    | 'trireg' (drive_strength)? ('signed')? (delay3)? list_of_net_decl_assignments ';'
	//    | 'trireg' (charge_strength)? ('signed')? (delay3)? list_of_net_identifiers ';'
	//    | 'trireg' (charge_strength)? ('vectored' | 'scalared')? ('signed')? range_ (delay3)? list_of_net_identifiers ';'
	//    | 'trireg' (drive_strength)? ('vectored' | 'scalared')? ('signed')? range_ (delay3)? list_of_net_decl_assignments ';'
	//    | net_type (drive_strength)? ('vectored' | 'scalared')? ('signed')? range_ (delay3)? list_of_net_decl_assignments ';'
	//    | net_type ('vectored' | 'scalared')? ('signed')? range_ (delay3)? list_of_net_identifiers ';'
	//    ;
	auto nt = ctx->net_type();
	if (nt->getText() != "wire") {
		NotImplementedLogger::print(
				string(
						"ModuleParser.visitNet_declaration.net_type different than wire (")
						+ nt->getText() + ")", nt);
	}
	auto del = ctx->delay3();
	if (del) {
		NotImplementedLogger::print("ModuleParser.visitNet_declaration.delay3",
				del);
	}
	auto ds = ctx->drive_strength();
	if (ds) {
		NotImplementedLogger::print(
				"ModuleParser.visitNet_declaration.drive_strength", ds);
	}
	auto cs = ctx->charge_strength();
	if (cs) {
		NotImplementedLogger::print(
				"ModuleParser.visitNet_declaration.charge_strength", cs);
	}

	bool is_signed = Utils::is_signed(ctx);
	iHdlExpr * t;
	auto r = ctx->range_();
	if (r) {
		t = Utils::mkWireT(r, is_signed);
	} else {
		t = Utils::mkWireT();
	}
	auto doc = commentParser.parse(ctx);
	bool first = true;
	auto ln = ctx->list_of_net_identifiers();
	if (ln) {
		for (auto v : visitList_of_net_identifiers(ln, t)) {
			if (first) {
				v->__doc__ = doc;
				first = false;
			}
			arch->objs.push_back(v);
		}
	} else {
		auto lna = ctx->list_of_net_decl_assignments();
		for (auto v : visitList_of_net_decl_assignments(lna, t)) {
			if (first) {
				v->__doc__ = doc;
				first = false;
			}
			arch->objs.push_back(v);
		}
	}
}
std::vector<HdlVariableDef*> ModuleParser::visitList_of_net_identifiers(
		Verilog2001Parser::List_of_net_identifiersContext * ctx,
		iHdlExpr * base_type) {
	// list_of_net_identifiers
	//    : net_identifier (dimension (dimension)*)? (',' net_identifier (dimension (dimension)*)?)*
	//    ;

	// net_identifier
	//    : identifier
	//    ;

	std::vector<HdlVariableDef*> res;
	iHdlExpr * actual_id = nullptr;
	iHdlExpr * actual_t = base_type;
	for (auto &child : ctx->children) {
		auto ni =
				dynamic_cast<Verilog2001Parser::Net_identifierContext *>(child);
		if (ni) {
			if (actual_id) {
				// store previous variable
				res.push_back(
						new HdlVariableDef(actual_id->extractStr(), actual_t,
								nullptr));
				// reset state of variable parsing
				delete actual_id;
				actual_id = nullptr;
				actual_t = new iHdlExpr(*base_type);
			}
			actual_id = VerExprParser::visitIdentifier(ni->identifier());
		} else {
			// stack the dimensions on type
			auto d = dynamic_cast<Verilog2001Parser::DimensionContext *>(child);
			if (d) {
				actual_t = new iHdlExpr(actual_t, HdlOperatorType::INDEX,
						VerExprParser::visitDimension(d));
			}
		}
	}
	if (actual_id) {
		// process leftover
		res.push_back(
				new HdlVariableDef(actual_id->extractStr(), actual_t, nullptr));
	}

	return res;
}

// @note same as visitList_of_net_identifiers but without the dimensions and with the default value
std::vector<HdlVariableDef*> ModuleParser::visitList_of_net_decl_assignments(
		Verilog2001Parser::List_of_net_decl_assignmentsContext * ctx,
		iHdlExpr * base_type) {
	//	list_of_net_decl_assignments
	//	   : net_decl_assignment (',' net_decl_assignment)*
	//	   ;

	// net_decl_assignment
	//    : net_identifier '=' expression
	//    ;

	// net_identifier
	//    : identifier
	//    ;

	std::vector<HdlVariableDef*> res;
	for (auto & nd : ctx->net_decl_assignment()) {
		iHdlExpr * id = VerExprParser::visitIdentifier(
				nd->net_identifier()->identifier());
		iHdlExpr * def_val = VerExprParser::visitExpression(nd->expression());
		res.push_back(new HdlVariableDef(id->extractStr(), base_type, def_val));
		delete id;
	}
	return res;
}

void ModuleParser::visitList_of_variable_identifiers(
		Verilog2001Parser::List_of_variable_identifiersContext * ctx,
		iHdlExpr * base_type, bool latched, const std::string & doc) {
	// list_of_variable_identifiers
	//    : variable_type (',' variable_type)*
	//    ;
	bool first = true;
	for (auto vt : ctx->variable_type()) {
		if (!first)
			base_type = new iHdlExpr(*base_type);
		HdlVariableDef * v = visitVariable_type(vt, base_type);
		if (first)
			v->__doc__ = doc;
		v->is_latched = latched;
		arch->objs.push_back(v);
		first = false;
	}
}

HdlVariableDef * ModuleParser::visitVariable_type(
		Verilog2001Parser::Variable_typeContext * ctx, iHdlExpr * base_type) {
	// variable_type
	//    : variable_identifier ('=' constant_expression)?
	//    | variable_identifier dimension (dimension)*
	//    ;
	auto vi = ctx->variable_identifier();
	auto t = base_type;
	for (auto d : ctx->dimension()) {
		t = new iHdlExpr(t, HdlOperatorType::INDEX,
				VerExprParser::visitDimension(d));
	}
	iHdlExpr * def_val = nullptr;
	auto c = ctx->constant_expression();
	if (c) {
		def_val = VerExprParser::visitConstant_expression(c);
	}
	return visitVariable_identifier(vi, t, def_val);
}

HdlVariableDef * ModuleParser::visitVariable_identifier(
		Verilog2001Parser::Variable_identifierContext * ctx, iHdlExpr * t,
		iHdlExpr * def_val) {
	// variable_identifier
	//    : identifier
	//    ;
	auto id = VerExprParser::visitIdentifier(ctx->identifier());
	auto v = new HdlVariableDef(id->extractStr(), t, def_val);
	delete id;
	return v;
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
	auto gi = ctx->generated_instantiation();
	if (gi) {
		NotImplementedLogger::print(
				"ModuleParser.visitNon_port_module_item.generated_instantiation",
				gi);
		return;
	}
	auto lp = ctx->local_parameter_declaration();
	if (lp) {
		NotImplementedLogger::print(
				"ModuleParser.visitNon_port_module_item.local_parameter_declaration",
				lp);
		return;
	}
	auto mg = ctx->module_or_generate_item();
	if (mg) {
		visitModule_or_generate_item(mg, arch->objs);
		return;
	}
	auto pd = ctx->parameter_declaration();
	if (pd) {
		NotImplementedLogger::print(
				"ModuleParser.visitNon_port_module_item.parameter_declaration",
				pd);
		return;
	}
	auto sb = ctx->specify_block();
	if (sb) {
		NotImplementedLogger::print(
				"ModuleParser.visitNon_port_module_item.specify_block", sb);
		return;
	}
	auto sd = ctx->specparam_declaration();
	if (sd) {
		NotImplementedLogger::print(
				"ModuleParser.visitNon_port_module_item.specparam_declaration",
				sd);
		return;
	}
	throw runtime_error(
			"ModuleParser.visitNon_port_module_item - unexpected transition");
}

}
}
