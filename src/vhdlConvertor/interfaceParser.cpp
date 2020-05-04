#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/directionParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/typeDeclarationParser.h>


using std::vector;
using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlAst;

namespace hdlConvertor {
namespace vhdl {

std::unique_ptr<vector<std::unique_ptr<HdlIdDef>>> VhdlInterfaceParser::extractVariables(
		vhdlParser::Identifier_listContext *identifier_list,
		vhdlParser::Subtype_indicationContext *subType,
		vhdlParser::ExpressionContext *_expr) {
	auto vl = std::make_unique<vector<std::unique_ptr<HdlIdDef>>>();
	auto _type = VhdlTypeDeclarationParser::visitSubtype_indication(subType);
	std::unique_ptr<iHdlExprItem> expr = nullptr;
	if (_expr)
		expr = VhdlExprParser::visitExpression(_expr);

	bool firstIt = true;
	auto _type_tmp = _type.get();
	for (auto i : identifier_list->identifier()) {
		// identifier_list
		// : identifier ( COMMA identifier )*
		// ;
		if (!firstIt)
			_type = _type_tmp->clone_uniq();
		std::unique_ptr<iHdlExprItem> __expr;
		if (!expr) {
			firstIt = false;
			__expr = nullptr;
		} else if (firstIt) {
			firstIt = false;
			__expr = move(expr);
		} else {
			__expr = expr->clone_uniq();
		}
		auto v = create_object<HdlIdDef>(i, i->getText(),
				std::move(_type), std::move(__expr));
		vl->push_back(std::move(v));
	}
	return vl;
}
std::unique_ptr<vector<std::unique_ptr<HdlIdDef>>> VhdlInterfaceParser::visitInterface_constant_declaration(
		vhdlParser::Interface_constant_declarationContext *ctx) {
	// interface_constant_declaration:
	//       ( CONSTANT )? identifier_list COLON ( IN )? subtype_indication ( VARASGN expression )?
	// ;
	auto consts = extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
	for (auto &c : *consts)
		c->is_const = true;
	return consts;
}
std::unique_ptr<vector<std::unique_ptr<HdlIdDef>>> VhdlInterfaceParser::visitInterface_signal_declaration(
		vhdlParser::Interface_signal_declarationContext *ctx) {
	// interface_signal_declaration:
	//       ( SIGNAL )? identifier_list COLON ( signal_mode )? subtype_indication ( BUS )? ( VARASGN expression )?
	// ;
	if (ctx->KW_BUS()) {
		NotImplementedLogger::print(
				"InterfaceParser.visitInterface_signal_declaration - BUS", ctx);
	}
	auto sigs = extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
	auto m = visitSignalMode(ctx->signal_mode());
	for (auto &s : *sigs)
		s->direction = m;
	return sigs;
}
std::unique_ptr<vector<std::unique_ptr<HdlIdDef>>> VhdlInterfaceParser::visitInterface_variable_declaration(
		vhdlParser::Interface_variable_declarationContext *ctx) {
	// interface_variable_declaration:
	//       ( VARIABLE )? identifier_list COLON ( signal_mode )? subtype_indication ( VARASGN expression )?
	// ;
	auto vars = extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
	auto m = visitSignalMode(ctx->signal_mode());
	for (auto &v : *vars) {
		v->direction = m;
		v->is_latched = true;
	}
	return vars;
}
std::unique_ptr<vector<std::unique_ptr<HdlIdDef>>> VhdlInterfaceParser::visitInterface_file_declaration(
		vhdlParser::Interface_file_declarationContext *ctx) {
	// interface_file_declaration:
	//       FILE identifier_list COLON subtype_indication
	// ;
	NotImplementedLogger::print(
			"InterfaceParser.visitInterface_file_declaration", ctx);
	return std::make_unique<vector<std::unique_ptr<HdlIdDef>>>();
}

std::unique_ptr<vector<std::unique_ptr<HdlIdDef>>> VhdlInterfaceParser::visitInterface_declaration(
		vhdlParser::Interface_declarationContext *ctx) {
	// interface_declaration:
	//       interface_object_declaration
	//       | interface_type_declaration
	//       | interface_subprogram_declaration
	//       | interface_package_declaration
	// ;
	auto iod = ctx->interface_object_declaration();
	if (iod) {
		return visitInterface_object_declaration(iod);
	}
	do {
		auto itd = ctx->interface_type_declaration();
		if (itd) {
			auto t = visitInterface_type_declaration(itd);
			NotImplementedLogger::print(
					"InterfaceParser.visitInterface_declaration - interface_type_declaration",
					itd);
			break;
		}
		auto isd = ctx->interface_subprogram_declaration();
		if (isd) {
			NotImplementedLogger::print(
					"InterfaceParser.visitInterface_declaration - interface_subprogram_declaration",
					isd);
			break;
		}
		auto ipd = ctx->interface_package_declaration();
		if (ipd) {
			NotImplementedLogger::print(
					"InterfaceParser.visitInterface_declaration - interface_package_declaration",
					ipd);
			break;
		}
	} while (0);

	return std::make_unique<vector<std::unique_ptr<HdlIdDef>>>();
}
std::unique_ptr<iHdlExprItem> VhdlInterfaceParser::visitInterface_type_declaration(
		vhdlParser::Interface_type_declarationContext *ctx) {
	// interface_type_declaration:
	//       interface_incomplete_type_declaration
	// ;
	// interface_incomplete_type_declaration: TYPE identifier;
	return VhdlLiteralParser::visitIdentifier(
			ctx->interface_incomplete_type_declaration()->identifier());
}
std::unique_ptr<vector<std::unique_ptr<HdlIdDef>>> VhdlInterfaceParser::visitInterface_object_declaration(
		vhdlParser::Interface_object_declarationContext *ctx) {
	// interface_object_declaration:
	//       interface_constant_declaration
	//       | interface_signal_declaration
	//       | interface_variable_declaration
	//       | interface_file_declaration
	// ;
	auto c = ctx->interface_constant_declaration();
	if (c) {
		return visitInterface_constant_declaration(c);
	}
	auto s = ctx->interface_signal_declaration();
	if (s) {
		return visitInterface_signal_declaration(s);
	}
	auto v = ctx->interface_variable_declaration();
	if (v) {
		return visitInterface_variable_declaration(v);
	}
	auto f = ctx->interface_file_declaration();
	assert(f);
	return visitInterface_file_declaration(f);
}
std::unique_ptr<vector<std::unique_ptr<HdlIdDef>>> VhdlInterfaceParser::visitInterface_list(
		vhdlParser::Interface_listContext *ctx) {
	// interface_list:
	//       interface_element ( SEMI interface_element )*
	// ;
	auto elems = std::make_unique<vector<std::unique_ptr<HdlIdDef>>>();
	for (auto ie : ctx->interface_element()) {
		auto _elements = visitInterface_element(ie);
		for (auto &e : *_elements) {
			elems->push_back(std::move(e));
		}
	}
	return elems;
}
std::unique_ptr<vector<std::unique_ptr<HdlIdDef>>> VhdlInterfaceParser::visitInterface_element(
		vhdlParser::Interface_elementContext *ctx) {
	// interface_element: interface_declaration;
	auto intfDec = ctx->interface_declaration();
	return visitInterface_declaration(intfDec);
}

}
}
