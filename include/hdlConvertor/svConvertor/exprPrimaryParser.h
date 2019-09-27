#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace sv {

class VerExprPrimaryParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	static hdlObjects::iHdlExpr* visitPrimary(
			sv2017Parser::PrimaryContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryCast(
			sv2017Parser::PrimaryCastContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryCast2(
			sv2017Parser::PrimaryCast2Context *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryBitSelect(
			sv2017Parser::PrimaryBitSelectContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryDot(
			sv2017Parser::PrimaryDotContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryIndex(
			sv2017Parser::PrimaryIndexContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryConcat(
			sv2017Parser::PrimaryConcatContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryStreaming_concatenation(
			sv2017Parser::PrimaryStreaming_concatenationContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryTfCall(
			sv2017Parser::PrimaryTfCallContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryRandomize(
			sv2017Parser::PrimaryRandomizeContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryRandomize2(
			sv2017Parser::PrimaryRandomize2Context *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryAssig(
			sv2017Parser::PrimaryAssigContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryTypeRef(
			sv2017Parser::PrimaryTypeRefContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryCall(
			sv2017Parser::PrimaryCallContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryCallArrayMethodNoArgs(
			sv2017Parser::PrimaryCallArrayMethodNoArgsContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimaryCallWith(
			sv2017Parser::PrimaryCallWithContext *ctx);
};

}
}
