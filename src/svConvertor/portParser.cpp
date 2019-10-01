#include <hdlConvertor/svConvertor/portParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/svConvertor/utils.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/hdlObjects/hdlDirection.h>
#include <hdlConvertor/hdlObjects/hdlStmAssign.h>
#include <hdlConvertor/conversion_exception.h>

namespace hdlConvertor {
namespace sv {

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlObjects;

VerPortParser::VerPortParser(SVCommentParser &commentParser,
		vector<Non_ANSI_port_info_t> &_non_ansi_port_groups) :
		commentParser(commentParser), non_ansi_port_groups(
				_non_ansi_port_groups) {
}

vector<HdlVariableDef*>* VerPortParser::addTypeSpecToPorts(HdlDirection direction,
		sv2017Parser::Net_typeContext *net_type, bool signed_, bool reg_,
		const string &doc, sv2017Parser::Range_Context *range_,
		vector<HdlVariableDef*> *ports) {
	if ((net_type != nullptr) && (net_type->getText() != "wire")) {
		NotImplementedLogger::print(
				"VerPortParser.addTypeSpecToPorts.net_type different than wire",
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

vector<HdlVariableDef*>* VerPortParser::visitNonansi_port(
		sv2017Parser::Nonansi_portContext *ctx) {
	// nonansi_port:
	//     nonansi_port__expr
	//     | DOT identifier LPAREN ( nonansi_port__expr )? RPAREN;
	auto pi = ctx->identifier();
	auto _pe = ctx->nonansi_port__expr();
	vector<HdlVariableDef*> *pe = nullptr;
	if (_pe) {
		pe = visitNonansi_port__expr(_pe);
	} else {
		pe = new vector<HdlVariableDef*>();
		NotImplementedLogger::print(
				"Source_textParser.visitPort - empty port record", ctx);
	}
	if (pi) {
		non_ansi_port_groups.push_back( { ctx->identifier()->getText(), *pe });
	}
	return pe;
}
vector<HdlVariableDef*>* VerPortParser::visitNonansi_port__expr(
		sv2017Parser::Nonansi_port__exprContext *ctx) {
	// nonansi_port__expr:
	//     identifier_doted_index_at_end
	//     | LBRACE identifier_doted_index_at_end ( COMMA identifier_doted_index_at_end )* RBRACE
	// ;
	vector<HdlVariableDef*> *ports = new vector<HdlVariableDef*>();
	if (ctx->LBRACE()) {
		NotImplementedLogger::print("VerPortParser.visitNonansi_port__expr - {}",
				ctx);
	}
	if (ctx) {
		for (auto pr : ctx->identifier_doted_index_at_end()) {
			auto id = VerExprParser::visitIdentifier_doted_index_at_end(pr);
			try {
				string id_name = id->extractStr();
				ports->push_back(new HdlVariableDef(id_name, nullptr, nullptr));
			} catch (const std::runtime_error &err) {
				NotImplementedLogger::print(
						"VerPortParser.visitNonansi_port__expr variable which is not just identifier",
						pr);
			}
		}
	}
	return ports;
}
vector<HdlVariableDef*>* VerPortParser::visitList_of_port_declarations(
		sv2017Parser::List_of_port_declarationsContext *ctx) {
	// list_of_port_declarations:
	//     LPAREN
	//     (
	//       ( nonansi_port ( COMMA ( nonansi_port )? )* )
	//       | ( COMMA ( nonansi_port )? )+
	//       | ( ( attribute_instance )* ansi_port_declaration ( COMMA ( attribute_instance )* ansi_port_declaration )* )
	//     )? RPAREN;
	auto ports = new vector<HdlVariableDef*>();
	for (auto pd : ctx->nonansi_port()) {
		auto pds = visitNonansi_port(pd);
		for (unsigned i = 0; i < pds->size(); i++)
			ports->push_back((*pds)[i]);
		delete pds;
	}
	for (auto pd : ctx->ansi_port_declaration()) {
		auto pds = visitAnsi_port_declaration(pd);
		for (unsigned i = 0; i < pds->size(); i++)
			ports->push_back((*pds)[i]);
		delete pds;
	}
	return ports;
}
vector<HdlVariableDef*>* VerPortParser::visitNonansi_port_declaration(
		sv2017Parser::Nonansi_port_declarationContext *ctx) {
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
vector<HdlVariableDef*>* VerPortParser::visitList_of_variable_port_identifiers(
		sv2017Parser::List_of_variable_port_identifiersContext *ctx) {
	// list_of_variable_port_identifiers :
	// port_identifier ( '=' constant_expression )? ( ',' port_identifier (
	// '=' constant_expression )? )* ;
	auto ports = new vector<HdlVariableDef*>();
	HdlVariableDef *last = nullptr;
	for (auto n : ctx->children) {
		auto cec = dynamic_cast<sv2017Parser::Constant_expressionContext*>(n);
		if (cec) {
			last->value = VerExprParser::visitConstant_expression(cec);
		} else {
			auto pic = dynamic_cast<sv2017Parser::Port_identifierContext*>(n);
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

void VerPortParser::convert_non_ansi_ports_to_ansi(vector<HdlVariableDef*> &ports,
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
		iHdlExpr *conc = reduce(ops, HdlOperatorType::CONCAT);
		iHdlExpr *this_port_id = iHdlExpr::ID(g.first);
		HdlStmAssign *drv;
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
