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
	hdlObjects::iHdlExpr* visitPrimary(sv2017Parser::PrimaryContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryCast(
			sv2017Parser::PrimaryCastContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryCast2(
			sv2017Parser::PrimaryCast2Context *ctx);
	hdlObjects::iHdlExpr* visitPrimaryBitSelect(
			sv2017Parser::PrimaryBitSelectContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryDot(sv2017Parser::PrimaryDotContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryIndex(
			sv2017Parser::PrimaryIndexContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryConcat(
			sv2017Parser::PrimaryConcatContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryStreaming_concatenation(
			sv2017Parser::PrimaryStreaming_concatenationContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryTfCall(
			sv2017Parser::PrimaryTfCallContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryRandomize(
			sv2017Parser::PrimaryRandomizeContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryRandomize2(
			sv2017Parser::PrimaryRandomize2Context *ctx);
	hdlObjects::iHdlExpr* visitPrimaryAssig(
			sv2017Parser::PrimaryAssigContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryTypeRef(
			sv2017Parser::PrimaryTypeRefContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryCall(
			sv2017Parser::PrimaryCallContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryCallArrayMethodNoArgs(
			sv2017Parser::PrimaryCallArrayMethodNoArgsContext *ctx);
	hdlObjects::iHdlExpr* visitPrimaryCallWith(
			sv2017Parser::PrimaryCallWithContext *ctx);
};

}
}
