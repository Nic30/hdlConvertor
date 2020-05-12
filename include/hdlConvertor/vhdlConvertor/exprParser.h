#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/hdlValue.h>
#include <hdlConvertor/hdlAst/hdlOp.h>

#include <hdlConvertor/hdlAst/hdlOpType.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlExprParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlAst::iHdlExprItem>>> visitAssociation_list(
			vhdlParser::Association_listContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitAssociation_element(
			vhdlParser::Association_elementContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitFormal_part(
			vhdlParser::Formal_partContext *ctx);
	static std::unique_ptr<hdlAst::HdlOp> visitExplicit_range(
			vhdlParser::Explicit_rangeContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitRange(
			vhdlParser::RangeContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitActual_part(
			vhdlParser::Actual_partContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitActual_designator(
			vhdlParser::Actual_designatorContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitResolution_indication(
			vhdlParser::Resolution_indicationContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitDiscrete_range(
			vhdlParser::Discrete_rangeContext *ctx);
	static hdlAst::HdlOpType visitSign(vhdlParser::SignContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitSimple_expression(
			vhdlParser::Simple_expressionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitExpression(
			vhdlParser::ExpressionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitPrimary(
			vhdlParser::PrimaryContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitQualified_expression(
			vhdlParser::Qualified_expressionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitAllocator(
			vhdlParser::AllocatorContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitAggregate(
			vhdlParser::AggregateContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitElement_association(
			vhdlParser::Element_associationContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitTarget(
			vhdlParser::TargetContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitWaveform(
			vhdlParser::WaveformContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitCondition(
			vhdlParser::ConditionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitConditional_waveforms(
			vhdlParser::Conditional_waveformsContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitWaveform_element(
			vhdlParser::Waveform_elementContext *ctx);
	/*
	 * @return expression if specified else nullptr for "others" the vhdl keyword
	 * */
	static std::unique_ptr<hdlAst::iHdlExprItem> visitChoice(
			vhdlParser::ChoiceContext *ctx);
	static std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> visitChoices(
			vhdlParser::ChoicesContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitProcedure_call_statement(
			vhdlParser::Procedure_call_statementContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitProcedure_call(
			vhdlParser::Procedure_callContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitType_mark(
			vhdlParser::Type_markContext *ctx);
};

}
}
