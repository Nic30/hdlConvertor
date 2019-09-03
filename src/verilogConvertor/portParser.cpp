#include <hdlConvertor/verilogConvertor/portParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/verilogConvertor/utils.h>
#include <hdlConvertor/verilogConvertor/exprParser.h>
#include <hdlConvertor/hdlObjects/hdlDirection.h>
#include <hdlConvertor/hdlObjects/hdlStmAssign.h>
#include <hdlConvertor/conversion_exception.h>

namespace hdlConvertor {
namespace verilog {

using namespace std;
using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
using namespace hdlObjects;

PortParser::PortParser(CommentParser &commentParser,
		vector<Non_ANSI_port_info_t> &_non_ansi_port_groups) :
		commentParser(commentParser), non_ansi_port_groups(
				_non_ansi_port_groups) {
}

vector<HdlVariableDef*>* PortParser::addTypeSpecToPorts(HdlDirection direction,
		Verilog2001Parser::Net_typeContext *net_type, bool signed_, bool reg_,
		const string &doc, Verilog2001Parser::Range_Context *range_,
		vector<HdlVariableDef*> *ports) {
	if ((net_type != nullptr) && (net_type->getText() != "wire")) {
		NotImplementedLogger::print(
				"PortParser.addTypeSpecToPorts.net_type different than wire",
				net_type);
	}
	bool first = true;
	for (auto p : *ports) {
		assert(!p->type);
		if (first) {
			p->__doc__ = doc + p->__doc__;
			first = false;
		}
		p->type = Utils::mkWireT(range_, signed_);
		p->direction = direction;
		p->is_latched = reg_;
	}
	return ports;
}

vector<HdlVariableDef*>* PortParser::visitList_of_ports(
		Verilog2001Parser::List_of_portsContext *ctx) {
	// list_of_ports : '(' port ( ',' port )* ')' ;
	auto ports = new vector<HdlVariableDef*>();
	for (auto p : ctx->port()) {
		auto ps = visitPort(p);
		for (unsigned i = 0; i < ps->size(); i++) {
			ports->push_back((*ps)[i]);
		}
		delete ps;
	}
	return ports;
}
vector<HdlVariableDef*>* PortParser::visitPort(
		Verilog2001Parser::PortContext *ctx) {
	// port: port_expression?
	// | '.' port_identifier '(' ( port_expression )? ')'
	// ;
	auto pi = ctx->port_identifier();
	auto _pe = ctx->port_expression();
	vector<HdlVariableDef*> *pe = nullptr;
	if (_pe) {
		pe = visitPort_expression(_pe);
	} else {
		pe = new vector<HdlVariableDef*>();
		NotImplementedLogger::print(
				"Source_textParser.visitPort - empty port record", ctx);
	}
	if (pi) {
		non_ansi_port_groups.push_back(
				{ ctx->port_identifier()->identifier()->getText(), *pe });
	}
	return pe;
}
vector<HdlVariableDef*>* PortParser::visitPort_expression(
		Verilog2001Parser::Port_expressionContext *ctx) {
	// port_expression :
	// port_reference
	// | '{' port_reference ( ',' port_reference )* '}'
	// ;
	vector<HdlVariableDef*> *ports = new vector<HdlVariableDef*>();
	if (ctx) {
		for (auto pr : ctx->port_reference()) {
			ports->push_back(visitPort_reference(pr));
		}
	}
	return ports;
}
HdlVariableDef* PortParser::visitPort_reference(
		Verilog2001Parser::Port_referenceContext *ctx) {
	// port_reference :
	// port_identifier
	// | port_identifier '[' constant_expression ']'
	// | port_identifier '[' range_expression ']'
	// ;
	// port_identifier : identifier ;

	iHdlExpr *t = nullptr;
	auto c = ctx->constant_expression();
	if (c) {
		t = VerExprParser::visitConstant_expression(c);
	}
	auto r = ctx->range_expression();
	if (r)
		t = VerExprParser::visitRange_expression(r);

	auto p = new HdlVariableDef(ctx->port_identifier()->identifier()->getText(),
			t, nullptr);
	p->direction = HdlDirection::DIR_UNKNOWN;
	return p;

}
vector<HdlVariableDef*>* PortParser::visitList_of_port_declarations(
		Verilog2001Parser::List_of_port_declarationsContext *ctx) {
	// list_of_port_declarations
	// : '(' port_declaration ( ',' port_declaration )* ')'
	// | '(' ')'
	// ;
	auto ports = new vector<HdlVariableDef*>();
	for (auto pd : ctx->port_declaration()) {
		auto pds = visitPort_declaration(pd);
		for (unsigned i = 0; i < pds->size(); i++)
			ports->push_back((*pds)[i]);
		delete pds;
	}
	return ports;
}
vector<HdlVariableDef*>* PortParser::visitPort_declaration(
		Verilog2001Parser::Port_declarationContext *ctx) {
	// port_declaration :
	// attribute_instance* inout_declaration
	// | attribute_instance* input_declaration
	// | attribute_instance* output_declaration
	// ;
	string doc = commentParser.parse(ctx);
	auto attribs = ctx->attribute_instance();
	if (attribs.size() > 0) {
		NotImplementedLogger::print(
				"ModuleParser.visitPort_declaration - attribs not implemented",
				ctx);
	}

	bool signed_ = Utils::is_signed(ctx);
	bool reg_ = false;
	{
		// inout_declaration : 'inout' ( net_type )? ( 'signed' )? ( range_ )?
		// list_of_port_identifiers ;
		auto inout = ctx->inout_declaration();
		if (inout) {
			auto ports = visitList_of_port_identifiers(
					inout->list_of_port_identifiers());
			return addTypeSpecToPorts(DIR_INOUT, inout->net_type(), signed_,
					reg_, doc, inout->range_(), ports);
		}
	}
	{
		// input_declaration : 'input' ( net_type )? ( 'signed' )? ( range_ )?
		//                      list_of_port_identifiers ;
		auto input = ctx->input_declaration();
		if (input) {
			auto ports = visitList_of_port_identifiers(
					input->list_of_port_identifiers());
			return addTypeSpecToPorts(DIR_IN, input->net_type(), signed_, reg_,
					doc, input->range_(), ports);
		}
	}
	{
		// output_declaration
		//    : 'output' (net_type)? ('signed')? (range_)? list_of_port_identifiers
		//    | 'output' ('reg')? ('signed')? (range_)? list_of_port_identifiers
		//    | 'output' 'reg' ('signed')? (range_)? list_of_variable_port_identifiers
		//    | 'output' (output_variable_type)? list_of_port_identifiers
		//    | 'output' output_variable_type list_of_variable_port_identifiers
		//    ;
		auto od = ctx->output_declaration();
		reg_ = Utils::is_reg(od);
		signed_ = Utils::is_signed(od);
		vector<HdlVariableDef*> *ports;
		auto lovpi = od->list_of_variable_port_identifiers();
		if (lovpi) {
			ports = visitList_of_variable_port_identifiers(lovpi);
		} else {
			ports = visitList_of_port_identifiers(
					od->list_of_port_identifiers());
		}
		return addTypeSpecToPorts(DIR_OUT, od->net_type(), signed_, reg_, doc,
				od->range_(), ports);
	}
}
vector<HdlVariableDef*>* PortParser::visitList_of_port_identifiers(
		Verilog2001Parser::List_of_port_identifiersContext *ctx) {
	// list_of_port_identifiers :
	// port_identifier ( ',' port_identifier )*
	// ;
	auto ports = new vector<HdlVariableDef*>();
	for (auto pi : ctx->port_identifier()) {
		ports->push_back(visitPort_identifier(pi));
	}
	return ports;
}
HdlVariableDef* PortParser::visitPort_identifier(
		Verilog2001Parser::Port_identifierContext *ctx) {
	// port_identifier : identifier ;
	auto v = new HdlVariableDef(ctx->identifier()->getText(), NULL, NULL);
	v->direction = HdlDirection::DIR_UNKNOWN;
	return v;
}
vector<HdlVariableDef*>* PortParser::visitList_of_variable_port_identifiers(
		Verilog2001Parser::List_of_variable_port_identifiersContext *ctx) {
	// list_of_variable_port_identifiers :
	// port_identifier ( '=' constant_expression )? ( ',' port_identifier (
	// '=' constant_expression )? )* ;
	auto ports = new vector<HdlVariableDef*>();
	HdlVariableDef *last = nullptr;
	for (auto n : ctx->children) {
		auto cec =
				dynamic_cast<Verilog2001Parser::Constant_expressionContext*>(n);
		if (cec) {
			last->value = VerExprParser::visitConstant_expression(cec);
		} else {
			auto pic =
					dynamic_cast<Verilog2001Parser::Port_identifierContext*>(n);
			if (pic) {
				last = visitPort_identifier(pic);
				ports->push_back(last);
			}
		}
	}
	return ports;
}
template<typename T>
typename std::vector<T>::iterator replace_seq_with_value(std::vector<T> &vec,
		T first_val, size_t seq_len, T replacement) {
	auto seq_start = std::find(vec.begin(), vec.end(), first_val);
	if (seq_start == vec.end())
		return vec.end(); // return last if no seq was found

	*seq_start = replacement;

	auto items_to_rm = seq_len - 1;

	// return new end
	if (items_to_rm > 0)
		return std::remove_if(std::next(seq_start), vec.end(),
				[&items_to_rm](const auto&) {
					return items_to_rm-- > 0;
				});
	return vec.end();
}

void PortParser::convert_non_ansi_ports_to_ansi(vector<HdlVariableDef*> &ports,
		vector<iHdlObj*> &body) {
	std::vector<HdlVariableDef*> non_ansi_converted_ports(
			non_ansi_port_groups.size());
	// module x (.a(b, c)); input b, c; endmodule -> module x (input [2:0] a); wire b, c; assign {b, c} = a; endmodule
	throw ParseException("Conversion of non-ANSI ports not implemented");
	size_t i = 0;
	for (auto &g : non_ansi_port_groups) {
		iHdlExpr *lsb = iHdlExpr::INT(0), *msb = nullptr;
		bool _signed = false;
		for (auto p : g.second) {
			// [todo] resolve width of type
			if (p->type) {

			}
		}
		auto range = new iHdlExpr(msb, HdlOperatorType::DOWNTO, lsb);
		iHdlExpr *nap_t = Utils::mkWireT(range, _signed);
		auto nap = new HdlVariableDef(g.first, nap_t, nullptr);
		replace_seq_with_value(ports, g.second[0], g.second.size(), nap);
		non_ansi_converted_ports[i++] = nap;
	}
	auto nap = non_ansi_converted_ports.begin();
	for (auto &g : non_ansi_port_groups) {
		std::vector<iHdlExpr*> ops;
		for (auto p : g.second) {
			ops.push_back(iHdlExpr::ID(p->name));
		}
		iHdlExpr * conc = VerExprParser::reduce(ops, HdlOperatorType::CONCAT);
		iHdlExpr * this_port_id = iHdlExpr::ID(g.first);
		HdlStmAssign * drv;
		if ((*nap)->direction == HdlDirection::DIR_IN) {
			drv = new HdlStmAssign(conc, this_port_id, false);
		} else {
			drv = new HdlStmAssign(this_port_id, conc, false);
		}
		body.push_back(static_cast<iHdlObj*>(drv));
		nap++;
	}
}

}
}
