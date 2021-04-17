#pragma once

#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/baseSvParser.h>

namespace hdlConvertor {
namespace sv {

class VerExprPrimaryParser: public BaseSvParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	using BaseSvParser::BaseSvParser;

	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimary(
			sv2017Parser::PrimaryContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryCast(
			sv2017Parser::PrimaryCastContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryCast2(
			sv2017Parser::PrimaryCast2Context *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryBitSelect(
			sv2017Parser::PrimaryBitSelectContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryDot(
			sv2017Parser::PrimaryDotContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryIndex(
			sv2017Parser::PrimaryIndexContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryConcat(
			sv2017Parser::PrimaryConcatContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryStreaming_concatenation(
			sv2017Parser::PrimaryStreaming_concatenationContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryTfCall(
			sv2017Parser::PrimaryTfCallContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryRandomize(
			sv2017Parser::PrimaryRandomizeContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryRandomize2(
			sv2017Parser::PrimaryRandomize2Context *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryAssig(
			sv2017Parser::PrimaryAssigContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitStructure_pattern_key(
			sv2017Parser::Structure_pattern_keyContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitArray_pattern_key(
			sv2017Parser::Array_pattern_keyContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitAssignment_pattern_key(
			sv2017Parser::Assignment_pattern_keyContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitAssignment_pattern(
			sv2017Parser::Assignment_patternContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryTypeRef(
			sv2017Parser::PrimaryTypeRefContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryCall(
			sv2017Parser::PrimaryCallContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryCallArrayMethodNoArgs(
			sv2017Parser::PrimaryCallArrayMethodNoArgsContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPrimaryCallWith(
			sv2017Parser::PrimaryCallWithContext *ctx);

};

}
}
