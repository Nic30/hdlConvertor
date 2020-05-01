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
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimary(sv2017Parser::PrimaryContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryCast(
			sv2017Parser::PrimaryCastContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryCast2(
			sv2017Parser::PrimaryCast2Context *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryBitSelect(
			sv2017Parser::PrimaryBitSelectContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryDot(sv2017Parser::PrimaryDotContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryIndex(
			sv2017Parser::PrimaryIndexContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryConcat(
			sv2017Parser::PrimaryConcatContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryStreaming_concatenation(
			sv2017Parser::PrimaryStreaming_concatenationContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryTfCall(
			sv2017Parser::PrimaryTfCallContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryRandomize(
			sv2017Parser::PrimaryRandomizeContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryRandomize2(
			sv2017Parser::PrimaryRandomize2Context *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryAssig(
			sv2017Parser::PrimaryAssigContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryTypeRef(
			sv2017Parser::PrimaryTypeRefContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryCall(
			sv2017Parser::PrimaryCallContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryCallArrayMethodNoArgs(
			sv2017Parser::PrimaryCallArrayMethodNoArgsContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExprItem> visitPrimaryCallWith(
			sv2017Parser::PrimaryCallWithContext *ctx);
};

}
}
