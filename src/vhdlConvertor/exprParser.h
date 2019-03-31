#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/expr.h"

class ExprParser {
public:
	static std::vector<Expr*> * visitActual_parameter_part(
			vhdl::vhdlParser::Actual_parameter_partContext* ctx);
	static Expr* visitAssociation_element(
			vhdl::vhdlParser::Association_elementContext* ctx);
	static Expr* visitFormal_part(vhdl::vhdlParser::Formal_partContext* ctx);
	static Expr* visitExplicit_range(vhdl::vhdlParser::Explicit_rangeContext* ctx);
	static Expr* visitRange(vhdl::vhdlParser::RangeContext* ctx);
	static Expr* visitActual_part(vhdl::vhdlParser::Actual_partContext* ctx);
	static Expr* visitActual_designator(
			vhdl::vhdlParser::Actual_designatorContext* ctx);
	static Expr* visitSubtype_indication(
			vhdl::vhdlParser::Subtype_indicationContext* ctx);
	static Expr* visitConstraint(
			vhdl::vhdlParser::Selected_nameContext * selectedName,
			vhdl::vhdlParser::ConstraintContext* ctx);
	static Expr* visitIndex_constraint(
			vhdl::vhdlParser::Index_constraintContext* ctx);
	static Expr* visitDiscrete_range(vhdl::vhdlParser::Discrete_rangeContext* ctx);
	static Expr* visitSimple_expression(
			vhdl::vhdlParser::Simple_expressionContext* ctx);
	static Expr* visitExpression(vhdl::vhdlParser::ExpressionContext* ctx);
	static Expr* visitRelation(vhdl::vhdlParser::RelationContext* ctx);
	static Expr* visitShift_expression(
			vhdl::vhdlParser::Shift_expressionContext* ctx);
	static Expr* visitTerm(vhdl::vhdlParser::TermContext* ctx);
	static Expr* visitFactor(vhdl::vhdlParser::FactorContext* ctx);
	static Expr* visitPrimary(vhdl::vhdlParser::PrimaryContext* ctx);
	static Expr* visitQualified_expression(
			vhdl::vhdlParser::Qualified_expressionContext* ctx);
	static Expr* visitAllocator(vhdl::vhdlParser::AllocatorContext* ctx);
	static Expr* visitAggregate(vhdl::vhdlParser::AggregateContext* ctx);
	static Expr* visitElement_association(
			vhdl::vhdlParser::Element_associationContext* ctx);
	static Expr* visitTarget(vhdl::vhdlParser::TargetContext* ctx);
	static Expr* visitWaveform(vhdl::vhdlParser::WaveformContext* ctx);
	static Expr* visitWaveform_element(
			vhdl::vhdlParser::Waveform_elementContext* ctx);
};
