#include <hdlConvertor/svConvertor/gateParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/svConvertor/utils.h>
#include <hdlConvertor/hdlAst/hdlStmAssign.h>
#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlAst/hdlCompInst.h>

#include <cassert>


namespace hdlConvertor {
namespace sv {

using namespace std;
using namespace hdlConvertor::hdlAst;


std::unique_ptr<iHdlExprItem> VerGateParser::visitEnable_terminal(
		sv2017Parser::Enable_terminalContext *ctx) {
	// enable_terminal: expression;
	return VerExprParser(this).visitExpression(ctx->expression());
}
std::unique_ptr<iHdlExprItem> VerGateParser::visitInout_terminal(
		sv2017Parser::Inout_terminalContext *ctx) {
	// inout_terminal: net_lvalue;
	return VerExprParser(this).visitNet_lvalue(ctx->net_lvalue());
}

std::unique_ptr<iHdlExprItem> VerGateParser::visitInput_terminal(
		sv2017Parser::Input_terminalContext *ctx) {
	// input_terminal: expression;
	return VerExprParser(this).visitExpression(ctx->expression());
}

std::unique_ptr<iHdlExprItem> VerGateParser::visitOutput_terminal(
		sv2017Parser::Output_terminalContext *ctx) {
	// output_terminal: net_lvalue;
	return VerExprParser(this).visitNet_lvalue(ctx->net_lvalue());
}

HdlOpType VerGateParser::visitN_output_gatetype(
		sv2017Parser::N_output_gatetypeContext *ctx) {
	// n_output_gatetype:
	//  KW_BUF
	//   | KW_NOT
	// ;
	if (ctx->KW_BUF()) {
		return HdlOpType::ASSIGN;
	} else {
		assert(ctx->KW_NOT());
		return HdlOpType::NEG;
	}
}

HdlOpType VerGateParser::visitN_input_gatetype(
		sv2017Parser::N_input_gatetypeContext *ctx) {
	// n_input_gatetype:
	// KW_AND
	// | KW_NAND
	// | KW_OR
	// | KW_NOR
	// | KW_XOR
	// | KW_XNOR
	// ;
	if(ctx->KW_AND()) {
		return HdlOpType::AND;
	}
	if (ctx->KW_NAND()) {
		return HdlOpType::NAND;
	}
	if (ctx->KW_OR()) {
		return HdlOpType::OR;
	}
	if (ctx->KW_NOR()) {
		return HdlOpType::NOR;
	}
	if (ctx->KW_XOR()) {
		return HdlOpType::XOR;
	}
	assert(ctx->KW_XNOR());
	{
		return HdlOpType::XNOR;
	}
}

std::pair<std::unique_ptr<iHdlExprItem>, std::unique_ptr<iHdlExprItem>> VerGateParser::visitN_output_gate_instance(
		sv2017Parser::N_output_gate_instanceContext *ctx) {
	// n_output_gate_instance:
	//  ( name_of_instance )? LPAREN output_terminal ( COMMA output_terminal )* COMMA input_terminal
	//       RPAREN;
	auto noi = ctx->name_of_instance();
	if (noi) {
		// name_of_instance: identifier ( unpacked_dimension )*;
		// auto name = VerExprParser::visitIdentifier(noi->identifier());
		NotImplementedLogger::print(
				"VerGateParser.visitN_output_gate_instance name_of_instance",
				ctx);
	}
	vector<unique_ptr<iHdlExprItem>> outputs;
	for (auto _ot : ctx->output_terminal()) {
		outputs.push_back(visitOutput_terminal(_ot));
	}
	auto _it = ctx->input_terminal();
	auto it = visitInput_terminal(_it);
	if (outputs.size() > 1) {
		auto o = reduce(outputs, HdlOpType::CONCAT);
		return {move(o), move(it)};
	} else {
		return {move(outputs[0]), move(it)};
	}
}

std::vector<std::unique_ptr<iHdlExprItem>> VerGateParser::visitN_input_gate_instance(
		sv2017Parser::N_input_gate_instanceContext *ctx) {
	// n_input_gate_instance:
	// ( name_of_instance )? LPAREN output_terminal ( COMMA input_terminal )+ RPAREN;
	auto noi = ctx->name_of_instance();
	if (noi) {
		// name_of_instance: identifier ( unpacked_dimension )*;
		// auto name = VerExprParser::visitIdentifier(noi->identifier());
		NotImplementedLogger::print(
				"VerGateParser.visitN_input_gate_instance name_of_instance",
				ctx);
	}
	auto _ot = ctx->output_terminal();
	vector<unique_ptr<iHdlExprItem>> terminals;
	terminals.emplace_back(visitOutput_terminal(_ot));
	for(auto _it : ctx->input_terminal()) {
		terminals.emplace_back(visitInput_terminal(_it));
	}
	return terminals;
}

void VerGateParser::visitGate_instantiation(
		sv2017Parser::Gate_instantiationContext *ctx,
		std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res) {
	// gate_instantiation:
	//  ( ( KW_PULLDOWN ( pulldown_strength )?
	//       | KW_PULLUP ( pullup_strength )?
	//       ) pull_gate_instance ( COMMA pull_gate_instance )*
	//   | ( cmos_switchtype | mos_switchtype) ( delay3 )? enable_gate_or_mos_switch_or_cmos_switch_instance ( COMMA enable_gate_or_mos_switch_or_cmos_switch_instance )*
	//   | enable_gatetype ( drive_strength )? ( delay3 )? enable_gate_or_mos_switch_or_cmos_switch_instance ( COMMA enable_gate_or_mos_switch_or_cmos_switch_instance )*
	//   | n_input_gatetype ( drive_strength )? ( delay2 )? n_input_gate_instance ( COMMA  n_input_gate_instance )*
	//   | n_output_gatetype ( drive_strength )? ( delay2 )? n_output_gate_instance ( COMMA n_output_gate_instance )*
	//   | pass_en_switchtype ( delay2 )? pass_enable_switch_instance ( COMMA pass_enable_switch_instance )*
	//   | pass_switchtype pass_switch_instance ( COMMA pass_switch_instance )*
	//   ) SEMI
	// ;

	auto _ot = ctx->n_output_gatetype();
	if (_ot) {
		auto ot = visitN_output_gatetype(_ot);
		auto ds = ctx->drive_strength();
		if (ds) {
			NotImplementedLogger::print(
					"VerGateParser.visitGate_instantiation drive_strength",
					ctx);
		}
		auto d2 = ctx->delay2();
		if (d2) {
			NotImplementedLogger::print(
					"VerGateParser.visitGate_instantiation delay2", ctx);
		}
		for (auto ogi : ctx->n_output_gate_instance()) {
			unique_ptr<HdlStmAssign> a;
			auto output_input = visitN_output_gate_instance(ogi);
			if (ot == HdlOpType::ASSIGN) {
				a = create_object<HdlStmAssign>(ogi, move(output_input.first),
						move(output_input.second), false);
			} else if (ot == HdlOpType::NEG) {
				auto i = create_object<HdlOp>(ogi, HdlOpType::NEG,
						move(output_input.second));
				a = create_object<HdlStmAssign>(ogi, move(output_input.first),
						move(i), false);
			}
			res.push_back(move(a));
		}
	} else if (auto _ot2 = ctx->n_input_gatetype()) {
		auto ot = visitN_input_gatetype(_ot2);
		auto ds = ctx->drive_strength();
		if (ds) {
			NotImplementedLogger::print(
					"VerGateParser.visitGate_instantiation drive_strength",
					ctx);
		}
		auto d2 = ctx->delay2();
		if (d2) {
			NotImplementedLogger::print(
					"VerGateParser.visitGate_instantiation delay2", ctx);
		}
		for (auto ogi : ctx->n_input_gate_instance()) {
			unique_ptr<HdlCompInst> a;
			auto output_input = visitN_input_gate_instance(ogi);
			//
			// n_input_gatetype:
			// KW_AND
			// | KW_NAND
			// | KW_OR
			// | KW_NOR
			// | KW_XOR
			// | KW_XNOR
			// ;
			auto noi = ogi->name_of_instance();
			auto name = (noi)?VerExprParser::visitIdentifier(noi->identifier()): make_unique<HdlValueId>(" ");
			std::unique_ptr<HdlValueId> gt;
			switch(ot) {
				case HdlOpType::AND:
					gt = create_object<HdlValueId>(ogi, "and");
				break;
				case HdlOpType::NAND:
					gt = create_object<HdlValueId>(ogi, "nand");
				break;
				case HdlOpType::OR:
					gt = create_object<HdlValueId>(ogi, "or");
				break;
				case HdlOpType::NOR:
					gt = create_object<HdlValueId>(ogi, "nor");
				break;
				case HdlOpType::XOR:
					gt = create_object<HdlValueId>(ogi, "xor");
				break;
				case HdlOpType::XNOR:
					gt = create_object<HdlValueId>(ogi, "xnor");
				break;
				default:
					// Should not reach here!
					assert(false);
				break;
			}
			if (gt) {
				a = create_object<HdlCompInst>(ogi, move(name), move(gt));
				a->portMap = move(output_input);
			}
			if(a)
				res.push_back(move(a));
		}
	} else {
		NotImplementedLogger::print("VerGateParser.visitGate_instantiation",
				ctx);
	}
}

}
}
