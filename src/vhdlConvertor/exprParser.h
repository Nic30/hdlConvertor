#pragma once

#include <vector>
#include "antlr4-runtime.h"
#include "../VhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/operatorType.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"

#include "literalParser.h"
#include "referenceParser.h"
#include "operatoTypeParser.h"

using namespace antlr4;
using namespace vhdl;

class ExprParser {
public:
	static std::vector<Expr*> * visitActual_parameter_part(
			Ref<vhdlParser::Actual_parameter_partContext> ctx);
	static Expr* visitAssociation_element(
			Ref<vhdlParser::Association_elementContext> ctx);
	static Expr* visitFormal_part(Ref<vhdlParser::Formal_partContext> ctx);
	static Expr* visitExplicit_range(Ref<vhdlParser::Explicit_rangeContext> ctx);
	static Expr* visitRange(Ref<vhdlParser::RangeContext> ctx);
	static Expr* visitActual_part(Ref<vhdlParser::Actual_partContext> ctx);
	static Expr* visitActual_designator(
			Ref<vhdlParser::Actual_designatorContext> ctx);
	static Expr* visitSubtype_indication(
			Ref<vhdlParser::Subtype_indicationContext> ctx);
	static Expr* visitConstraint(
			Ref<vhdlParser::Selected_nameContext> selectedName,
			Ref<vhdlParser::ConstraintContext> ctx);
	static Expr* visitIndex_constraint(
			Ref<vhdlParser::Index_constraintContext> ctx);
	static Expr* visitDiscrete_range(Ref<vhdlParser::Discrete_rangeContext> ctx);
	static Expr* visitSimple_expression(
			Ref<vhdlParser::Simple_expressionContext> ctx);
	static Expr* visitExpression(Ref<vhdlParser::ExpressionContext> ctx);
	static Expr* visitRelation(Ref<vhdlParser::RelationContext> ctx);
	static Expr* visitShift_expression(
			Ref<vhdlParser::Shift_expressionContext> ctx);
	static Expr* visitTerm(Ref<vhdlParser::TermContext> ctx);
	static Expr* visitFactor(Ref<vhdlParser::FactorContext> ctx);
	static Expr* visitPrimary(Ref<vhdlParser::PrimaryContext> ctx);
	static Expr* visitQualified_expression(
			Ref<vhdlParser::Qualified_expressionContext> ctx);
	static Expr* visitAllocator(Ref<vhdlParser::AllocatorContext> ctx);
	static Expr* visitAggregate(Ref<vhdlParser::AggregateContext> ctx);
	static Expr* visitTarget(Ref<vhdlParser::TargetContext> ctx);
	static Expr* visitWaveform(Ref<vhdlParser::WaveformContext> ctx);
	static Expr* visitWaveform_element(
			Ref<vhdlParser::Waveform_elementContext> ctx);
};
