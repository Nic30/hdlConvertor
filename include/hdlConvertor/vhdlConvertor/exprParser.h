#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>

namespace hdlConvertor {
namespace vhdl {

class ExprParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::vector<hdlObjects::iHdlExpr*> * visitActual_parameter_part(
			vhdlParser::Actual_parameter_partContext* ctx);
	static std::vector<hdlObjects::iHdlExpr*> * visitAssociation_list(
			vhdlParser::Association_listContext *ctx);
	static hdlObjects::iHdlExpr* visitAssociation_element(
			vhdlParser::Association_elementContext* ctx);
	static hdlObjects::iHdlExpr* visitFormal_part(
			vhdlParser::Formal_partContext* ctx);
	static hdlObjects::iHdlExpr* visitExplicit_range(
			vhdlParser::Explicit_rangeContext* ctx);
	static hdlObjects::iHdlExpr* visitRange(vhdlParser::RangeContext* ctx);
	static hdlObjects::iHdlExpr* visitPrefix(vhdlParser::PrefixContext * ctx);
	static hdlObjects::iHdlExpr* visitFunction_call(
			vhdlParser::Function_callContext *ctx);
	static hdlObjects::iHdlExpr* visitActual_part(
			vhdlParser::Actual_partContext* ctx);
	static hdlObjects::iHdlExpr* visitActual_designator(
			vhdlParser::Actual_designatorContext* ctx);
	static hdlObjects::iHdlExpr* visitSubtype_indication(
			vhdlParser::Subtype_indicationContext* ctx);
	static hdlObjects::iHdlExpr * visitResolution_indication(
			vhdlParser::Resolution_indicationContext * ctx);
	static hdlObjects::iHdlExpr* visitConstraint(
			hdlObjects::iHdlExpr * selectedName,
			vhdlParser::ConstraintContext* ctx);
	static hdlObjects::iHdlExpr* visitArray_constraint(
			vhdlParser::Array_constraintContext * ctx);
	static hdlObjects::iHdlExpr* visitIndex_constraint(
			vhdlParser::Index_constraintContext* ctx);
	static hdlObjects::iHdlExpr* visitDiscrete_range(
			vhdlParser::Discrete_rangeContext* ctx);
	static hdlObjects::HdlOperatorType visitSign(vhdlParser::SignContext * ctx);
	static hdlObjects::iHdlExpr* visitSimple_expression(
			vhdlParser::Simple_expressionContext* ctx);
	static hdlObjects::iHdlExpr* visitExpression(
			vhdlParser::ExpressionContext* ctx);
	static hdlObjects::iHdlExpr* visitLogical_expression(
			vhdlParser::Logical_expressionContext *ctx);
	static hdlObjects::iHdlExpr* visitRelation(
			vhdlParser::RelationContext* ctx);
	static hdlObjects::iHdlExpr* visitShift_expression(
			vhdlParser::Shift_expressionContext* ctx);
	static hdlObjects::iHdlExpr* visitTerm(vhdlParser::TermContext* ctx);
	static hdlObjects::iHdlExpr* visitFactor(vhdlParser::FactorContext* ctx);
	static hdlObjects::iHdlExpr* visitType_conversion(
			vhdlParser::Type_conversionContext * ctx);
	static hdlObjects::iHdlExpr* visitPrimary(vhdlParser::PrimaryContext* ctx);
	static hdlObjects::iHdlExpr* visitQualified_expression(
			vhdlParser::Qualified_expressionContext* ctx);
	static hdlObjects::iHdlExpr* visitAllocator(
			vhdlParser::AllocatorContext* ctx);
	static hdlObjects::iHdlExpr* visitAggregate(
			vhdlParser::AggregateContext* ctx);
	static hdlObjects::iHdlExpr* visitElement_association(
			vhdlParser::Element_associationContext* ctx);
	static hdlObjects::iHdlExpr* visitTarget(vhdlParser::TargetContext* ctx);
	static hdlObjects::iHdlExpr* visitWaveform(
			vhdlParser::WaveformContext* ctx);
	static hdlObjects::iHdlExpr * visitCondition(
			vhdlParser::ConditionContext* ctx);
	static hdlObjects::iHdlExpr * visitConditional_waveforms(
			vhdlParser::Conditional_waveformsContext * ctx);
	static hdlObjects::iHdlExpr* visitWaveform_element(
			vhdlParser::Waveform_elementContext* ctx);
	/*
	 * @return expression if specified else nullptr for "others" the vhdl keyword
	 * */
	static hdlObjects::iHdlExpr * visitChoice(vhdlParser::ChoiceContext * ctx);
	static std::vector<hdlObjects::iHdlExpr *> visitChoices(
			vhdlParser::ChoicesContext * ctx);

	static hdlObjects::iHdlExpr * visitProcedure_call_statement(
			vhdlParser::Procedure_call_statementContext * ctx);
	static hdlObjects::iHdlExpr * visitProcedure_call(
			vhdlParser::Procedure_callContext * ctx);
	static hdlObjects::iHdlExpr * visitType_mark(
			vhdlParser::Type_markContext * ctx);
};

}
}
