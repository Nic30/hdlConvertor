#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/svConvertor/commentParser.h>

namespace hdlConvertor {
namespace sv {

class VerExprPrimaryParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	SVCommentParser &commentParser;
	VerExprPrimaryParser(SVCommentParser &commentParser);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimary(sv2017Parser::PrimaryContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryCast(
			sv2017Parser::PrimaryCastContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryCast2(
			sv2017Parser::PrimaryCast2Context *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryBitSelect(
			sv2017Parser::PrimaryBitSelectContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryDot(sv2017Parser::PrimaryDotContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryIndex(
			sv2017Parser::PrimaryIndexContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryConcat(
			sv2017Parser::PrimaryConcatContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryStreaming_concatenation(
			sv2017Parser::PrimaryStreaming_concatenationContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryTfCall(
			sv2017Parser::PrimaryTfCallContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryRandomize(
			sv2017Parser::PrimaryRandomizeContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryRandomize2(
			sv2017Parser::PrimaryRandomize2Context *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryAssig(
			sv2017Parser::PrimaryAssigContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryTypeRef(
			sv2017Parser::PrimaryTypeRefContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryCall(
			sv2017Parser::PrimaryCallContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryCallArrayMethodNoArgs(
			sv2017Parser::PrimaryCallArrayMethodNoArgsContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPrimaryCallWith(
			sv2017Parser::PrimaryCallWithContext *ctx);
};

}
}
