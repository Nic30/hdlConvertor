#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/blockDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/compInstanceParser.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/generateStatementParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/processParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/signalParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/subtypeDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;
using namespace std;

VhdlGenerateStatementParser::VhdlGenerateStatementParser(bool _hierarchyOnly) :
		hierarchyOnly(_hierarchyOnly) {
}

iHdlStatement * VhdlGenerateStatementParser::visitGenerate_statement(
		vhdlParser::Generate_statementContext *ctx) {
	//generate_statement
	//  : for_generate_statement
	//  | if_generate_statement
	//  | case_generate_statement
	//  ;

	auto fgs = ctx->for_generate_statement();
	if (fgs) {
		return visitFor_generate_statement(fgs);
	}

	auto ifs = ctx->if_generate_statement();
	if (ifs) {
		return visitIf_generate_statement(ifs);
	}

	auto cgs = ctx->case_generate_statement();
	assert(cgs);
	return visitCase_generate_statement(cgs);

}

iHdlStatement * VhdlGenerateStatementParser::visitFor_generate_statement(
		vhdlParser::For_generate_statementContext *ctx) {
	// for_generate_statement:
	//           FOR parameter_specification GENERATE
	//               generate_statement_body
	//           END GENERATE ( label )? SEMI
	// ;

	auto args = VhdlStatementParser::visitParameter_specification(
			ctx->parameter_specification());
	auto objs = new std::vector<iHdlObj*>();
	visitGenerate_statement_body(ctx->generate_statement_body(), *objs);
	auto fstm = iHdlStatement::FOR_IN(args.first, args.second, objs);
	auto label = ctx->label();
	if (label) {
		auto l = VhdlLiteralParser::visitLabel(label);
		fstm->labels.push_back(l);
	}
	fstm->position.update_from_elem(ctx);
	fstm->in_preproc = true;
	return fstm;
}

iHdlStatement * VhdlGenerateStatementParser::visitIf_generate_statement(
		vhdlParser::If_generate_statementContext *ctx) {
	// if_generate_statement:
	//       label COLON
	//           IF ( label COLON )? condition GENERATE
	//               generate_statement_body
	//           ( ELSIF ( label COLON )? condition GENERATE
	//               generate_statement_body )*
	//           ( ELSE ( label COLON )? GENERATE
	//               generate_statement_body )?
	//           END GENERATE ( label )? SEMI
	// ;

	auto c = ctx->condition();
	auto cIt = c.begin();
	auto s = ctx->generate_statement_body();
	auto sIt = s.begin();

	iHdlExpr * cond = VhdlExprParser::visitCondition(*cIt);
	auto ifTrue = new vector<iHdlObj*>();
	visitGenerate_statement_body(*sIt, *ifTrue);
	++cIt;
	++sIt;
	std::vector<iHdlStatement::case_t> elseIfs;
	while (cIt != c.end()) {
		auto c = VhdlExprParser::visitCondition(*cIt);
		auto stms = new vector<iHdlObj*>();
		visitGenerate_statement_body(*sIt, *stms);
		elseIfs.push_back( { c, stms });
		++cIt;
		++sIt;
	}
	iHdlStatement * ifStm = nullptr;
	std::vector<iHdlObj*> * ifFalse = nullptr;
	if (sIt != s.end()) {
		ifFalse = new std::vector<iHdlObj*>();
		visitGenerate_statement_body(*sIt, *ifFalse);
	}

	ifStm = iHdlStatement::IF(cond, ifTrue, elseIfs, ifFalse);
	ifStm->position.update_from_elem(ctx);
	auto labels = ctx->label();
	if (labels.size()) {
		ifStm->labels.push_back(VhdlLiteralParser::visitLabel(labels[0]));
	}
	return ifStm;
}

iHdlStatement * VhdlGenerateStatementParser::visitCase_generate_statement(
		vhdlParser::Case_generate_statementContext *ctx) {
	// case_generate_statement:
	//           CASE expression GENERATE
	//               case_generate_alternative
	//               ( case_generate_alternative )*
	//           END GENERATE ( label )? SEMI
	// ;

	auto _e = ctx->expression();
	auto e = VhdlExprParser::visitExpression(_e);
	vector<iHdlStatement::case_t> alternatives;
	vector<iHdlObj*>* _default = nullptr;
	vector<std::string> labels;
	auto label = ctx->label();
	if (label) {
		auto l = VhdlLiteralParser::visitLabel(label);
		labels.push_back(l);
	}
	for (auto a : ctx->case_generate_alternative()) {
		// case_generate_alternative:
		//       WHEN ( label COLON )? choices ARROW
		//           generate_statement_body
		// ;
		if (a->label()) {
			auto l = VhdlLiteralParser::visitLabel(a->label());
			labels.push_back(l);
		}
		for (auto ch : VhdlExprParser::visitChoices(a->choices())) {
			auto s = a->generate_statement_body();
			auto stms = new vector<iHdlObj*>();
			visitGenerate_statement_body(s, *stms);
			if (ch == nullptr) {
				assert(_default == nullptr);
				_default = stms;
			} else {
				alternatives.push_back( { ch, stms });
			}
		}
	}
	auto cstm = iHdlStatement::CASE(e, alternatives, _default);
	cstm->in_preproc = true;
	cstm->position.update_from_elem(ctx);
	return cstm;
}

void VhdlGenerateStatementParser::visitGenerate_statement_body(
		vhdlParser::Generate_statement_bodyContext *ctx,
		std::vector<iHdlObj*> & objs) {
	// generate_statement_body:
	//     ( block_declarative_item*
	//       KW_BEGIN
	//         ( concurrent_statement )*
	//       KW_END ( label )? SEMI
	//      )
	//      | ( concurrent_statement )*
	// ;
	auto bdis = ctx->block_declarative_item();
	if (bdis.size()) {
		// [TODO] wrap in block
		VhdlBlockDeclarationParser _bdp(hierarchyOnly);
		for (auto bdi : ctx->block_declarative_item()) {
			_bdp.visitBlock_declarative_item(bdi, objs);
		}
	}
	VhdlStatementParser sp(hierarchyOnly);
	for (auto cs : ctx->concurrent_statement()) {
		sp.visitConcurrent_statement(cs, objs);
	}
}

HdlModuleDec * VhdlGenerateStatementParser::visitComponent_declaration(
		vhdlParser::Component_declarationContext* ctx) {
	// component_declaration:
	//       COMPONENT identifier ( IS )?
	//           ( generic_clause )?
	//           ( port_clause )?
	//       END COMPONENT ( identifier )? SEMI
	// ;
	HdlModuleDec * e = new HdlModuleDec();
	e->name = ctx->identifier(0)->getText();
	auto gc = ctx->generic_clause();
	if (gc)
		VhdlEntityParser::visitGeneric_clause(gc, &e->generics);
	auto pc = ctx->port_clause();
	if (pc)
		VhdlEntityParser::visitPort_clause(pc, &e->ports);

	return e;
}

}
}
