#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlExprParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<std::vector<std::unique_ptr<hdlObjects::iHdlExpr>>> visitAssociation_list(
			vhdlParser::Association_listContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitAssociation_element(
			vhdlParser::Association_elementContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitFormal_part(
			vhdlParser::Formal_partContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitExplicit_range(
			vhdlParser::Explicit_rangeContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitRange(
			vhdlParser::RangeContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitActual_part(
			vhdlParser::Actual_partContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitActual_designator(
			vhdlParser::Actual_designatorContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitSubtype_indication(
			vhdlParser::Subtype_indicationContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitResolution_indication(
			vhdlParser::Resolution_indicationContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitConstraint(
			std::unique_ptr<hdlObjects::iHdlExpr> selectedName,
			vhdlParser::ConstraintContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitArray_constraint(
			vhdlParser::Array_constraintContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitIndex_constraint(
			vhdlParser::Index_constraintContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitDiscrete_range(
			vhdlParser::Discrete_rangeContext *ctx);
	static hdlObjects::HdlOperatorType visitSign(vhdlParser::SignContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitSimple_expression(
			vhdlParser::Simple_expressionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitExpression(
			vhdlParser::ExpressionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitPrimary(
			vhdlParser::PrimaryContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitQualified_expression(
			vhdlParser::Qualified_expressionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitAllocator(
			vhdlParser::AllocatorContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitAggregate(
			vhdlParser::AggregateContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitElement_association(
			vhdlParser::Element_associationContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitTarget(
			vhdlParser::TargetContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitWaveform(
			vhdlParser::WaveformContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitCondition(
			vhdlParser::ConditionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitConditional_waveforms(
			vhdlParser::Conditional_waveformsContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitWaveform_element(
			vhdlParser::Waveform_elementContext *ctx);
	/*
	 * @return expression if specified else nullptr for "others" the vhdl keyword
	 * */
	static std::unique_ptr<hdlObjects::iHdlExpr> visitChoice(
			vhdlParser::ChoiceContext *ctx);
	static std::vector<std::unique_ptr<hdlObjects::iHdlExpr>> visitChoices(
			vhdlParser::ChoicesContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitProcedure_call_statement(
			vhdlParser::Procedure_call_statementContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitProcedure_call(
			vhdlParser::Procedure_callContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitType_mark(
			vhdlParser::Type_markContext *ctx);
};

}
}
