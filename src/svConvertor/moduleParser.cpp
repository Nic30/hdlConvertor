#include <hdlConvertor/svConvertor/moduleParser.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/conversion_exception.h>

#include <hdlConvertor/svConvertor/utils.h>
#include <hdlConvertor/svConvertor/portParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/svConvertor/statementParser.h>
#include <hdlConvertor/svConvertor/moduleInstanceParser.h>
#include <hdlConvertor/svConvertor/paramDefParser.h>
#include <hdlConvertor/svConvertor/attributeParser.h>
#include <hdlConvertor/svConvertor/portParser.h>
#include <hdlConvertor/svConvertor/typeParser.h>

namespace hdlConvertor {
namespace sv {

using namespace std;
using namespace sv2017_antlr;
using namespace hdlConvertor::hdlObjects;

VerModuleParser::VerModuleParser(SVCommentParser &commentParser, HdlContext *_context,
		bool _hierarchyOnly) :
		commentParser(commentParser) {
	context = _context;
	hierarchyOnly = _hierarchyOnly;
	ent = new HdlModuleDec();
	arch = new HdlModuleDef();
}

void VerModuleParser::visitModule_declaration(
		sv2017Parser::Module_declarationContext *ctx) {
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
		VerParamDefParser pp(commentParser);
		auto ppls = pp.visitModule_parameter_port_list(mppl);
		for (auto v : *ppls)
			ent->generics.push_back(v);
	}
	auto lop = ctx->list_of_ports();
	if (lop) {
		VerPortParser pp(commentParser, non_ANSI_port_groups);
		auto ps = pp.visitList_of_ports(lop);
		for (auto p : *ps) {
			ent->ports.push_back(p);
		}
		delete ps;
	}

	auto lpd = ctx->list_of_port_declarations();
	if (lpd) {
		VerPortParser pp(commentParser, non_ANSI_port_groups);
		auto ps = pp.visitList_of_port_declarations(lpd);
		for (auto p : *ps) {
			ent->ports.push_back(p);
		}
		delete ps;
	}

	for (auto mi : ctx->module_item())
		visitModule_item(mi, arch->objs);

	for (auto npmi : ctx->non_port_module_item())
		visitNon_port_module_item(npmi);

	context->objs.push_back(ent);
	arch->entityName = iHdlExpr::ID(ent->name);
	context->objs.push_back(arch);
	if (non_ANSI_port_groups.size()) {
		VerPortParser pp(commentParser, non_ANSI_port_groups);
		pp.convert_non_ansi_ports_to_ansi(ent->ports, arch->objs);
	}
	for (auto o : ent->ports) {
		if (o->type == nullptr) {
			throw ParseException(
					string("Can not find type specification for port ")
							+ ent->name + "::" + o->name);
		}
	}
}

void VerModuleParser::visitModule_item(sv2017Parser::Module_itemContext *ctx,
		std::vector<hdlObjects::iHdlObj*> &objs) {
	// module_item:
	//     generate_region
	//     | ( attribute_instance )* module_item_item
	//     | specify_block
	//     | program_declaration
	//     | module_declaration
	//     | interface_declaration
	//     | timeunits_declaration
	//     | nonansi_port_declaration SEMI
	// ;
	auto ai = ctx->attribute_instance();
	if (ai.size()) {
		NotImplementedLogger::print(
				"ModuleParser.module_item.attribute_instance", ctx);
	}
	auto pd = ctx->nonansi_port_declaration();
	if (pd) {
		string doc = commentParser.parse(ctx);
		bool first = true;
		VerPortParser pp(commentParser, non_ANSI_port_groups);
		auto portsDeclr = pp.visitNonansi_port_declaration(pd);
		for (auto declr : *portsDeclr) {
			HdlVariableDef *p = ent->getPortByName(declr->name);
			p->direction = declr->direction;
			assert(p != nullptr);
			p->type = declr->type;
			if (declr->value) {
				assert(p->value == nullptr);
				p->value = declr->value;
			}
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

	throw std::runtime_error(
			"ModuleParser.visitModule_item - probably missing part of implementation");
}

void VerModuleParser::visitInteger_declaration(
		sv2017Parser::Integer_declarationContext *ctx) {
	// integer_declaration
	//    : 'integer' list_of_variable_identifiers ';'
	//    ;
	auto t = Utils::mkIntT();
	auto doc = commentParser.parse(ctx);
	visitList_of_variable_identifiers(ctx->list_of_variable_identifiers(), t,
			true, doc);
}

void VerModuleParser::visitNet_declaration(
		sv2017Parser::Net_declarationContext *ctx) {
	// net_declaration:
	//  ( KW_INTERCONNECT ( implicit_data_type )? ( HASH delay_value )? identifier ( unpacked_dimension )* (
	//   COMMA identifier ( unpacked_dimension )* )?
	//   | ( net_type ( drive_strength
	//                   | charge_strength
	//                   )? ( KW_VECTORED
	//                           | KW_SCALARED
	//                           )? ( data_type_or_implicit )? ( delay3 )?
	//       | identifier ( delay_control )?
	//       ) list_of_net_decl_assignments
	//   ) SEMI;
	if (ctx->KW_INTERCONNECT()) {
		NotImplementedLogger::print(
				"ModuleParser.visitNet_declaration.net_type interconnect", ctx);
		return;
	}

	auto nt = ctx->net_type();
	if (nt->getText() != "wire") {
		NotImplementedLogger::print(
				string(
						"ModuleParser.visitNet_declaration.net_type different than wire (")
						+ nt->getText() + ")", nt);
	}
	if (ctx->drive_strength()) {
		NotImplementedLogger::print(
				"ModuleParser.visitNet_declaration.net_type drive_strength",
				ctx);
		return;
	}
	if (ctx->charge_strength()) {
		NotImplementedLogger::print(
				"ModuleParser.visitNet_declaration.net_type charge_strength",
				ctx);
		return;
	}
	if (ctx->KW_VECTORED()) {
		NotImplementedLogger::print(
				"ModuleParser.visitNet_declaration.net_type KW_VECTORED", ctx);
		return;
	}
	if (ctx->KW_SCALARED()) {
		NotImplementedLogger::print(
				"ModuleParser.visitNet_declaration.net_type KW_SCALARED", ctx);
		return;
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
	auto dti = ctx->data_type_or_implicit();
	iHdlExpr *t = VerTypeParser::visitData_type_or_implicit(dti);
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
std::vector<HdlVariableDef*> VerModuleParser::visitList_of_net_identifiers(
		sv2017Parser::List_of_net_identifiersContext *ctx,
		iHdlExpr *base_type) {
	// list_of_net_identifiers
	//    : net_identifier (dimension (dimension)*)? (',' net_identifier (dimension (dimension)*)?)*
	//    ;

	// net_identifier
	//    : identifier
	//    ;

	std::vector<HdlVariableDef*> res;
	iHdlExpr *actual_id = nullptr;
	iHdlExpr *actual_t = base_type;
	for (auto &child : ctx->children) {
		auto ni = dynamic_cast<sv2017Parser::Net_identifierContext*>(child);
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
			auto d = dynamic_cast<sv2017Parser::DimensionContext*>(child);
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
std::vector<HdlVariableDef*> VerModuleParser::visitList_of_net_decl_assignments(
		sv2017Parser::List_of_net_decl_assignmentsContext *ctx,
		iHdlExpr *base_type) {
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
	for (auto &nd : ctx->net_decl_assignment()) {
		iHdlExpr *id = VerExprParser::visitIdentifier(
				nd->net_identifier()->identifier());
		iHdlExpr *def_val = VerExprParser::visitExpression(nd->expression());
		res.push_back(new HdlVariableDef(id->extractStr(), base_type, def_val));
		delete id;
	}
	return res;
}

void VerModuleParser::visitList_of_variable_identifiers(
		sv2017Parser::List_of_variable_identifiersContext *ctx,
		iHdlExpr *base_type, bool latched, const std::string &doc) {
	// list_of_variable_identifiers
	//    : variable_type (',' variable_type)*
	//    ;
	bool first = true;
	for (auto vt : ctx->variable_type()) {
		if (!first)
			base_type = new iHdlExpr(*base_type);
		HdlVariableDef *v = visitVariable_type(vt, base_type);
		if (first)
			v->__doc__ = doc;
		v->is_latched = latched;
		arch->objs.push_back(v);
		first = false;
	}
}

HdlVariableDef* VerModuleParser::visitVariable_type(
		sv2017Parser::Variable_typeContext *ctx, iHdlExpr *base_type) {
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
	iHdlExpr *def_val = nullptr;
	auto c = ctx->constant_expression();
	if (c) {
		def_val = VerExprParser::visitConstant_expression(c);
	}
	return visitVariable_identifier(vi, t, def_val);
}

}
}
