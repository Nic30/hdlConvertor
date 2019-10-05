#pragma once

#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/commentParser.h>

namespace hdlConvertor {
namespace sv {

class VerTypeParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	SVCommentParser &commentParser;

	VerTypeParser(SVCommentParser &commentParser);

	std::unique_ptr<hdlObjects::iHdlExpr> visitType_reference(
			sv2017Parser::Type_referenceContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitInteger_type(
			sv2017Parser::Integer_typeContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitNon_integer_type(
			sv2017Parser::Non_integer_typeContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitData_type_primitive(
			sv2017Parser::Data_type_primitiveContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitInteger_atom_type(
			sv2017Parser::Integer_atom_typeContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitInteger_vector_type(
			sv2017Parser::Integer_vector_typeContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitData_type(
			sv2017Parser::Data_typeContext *ctx);
	/*
	 * @note ctx can be nullptr
	 * @note net_type can be nullptr, if specified it is used as base type
	 * */
	std::unique_ptr<hdlObjects::iHdlExpr> visitData_type_or_implicit(
			sv2017Parser::Data_type_or_implicitContext *ctx,
			std::unique_ptr<hdlObjects::iHdlExpr> net_type);
	static bool visitSigning(sv2017Parser::SigningContext *ctx);
	/*
	 * @note net_type can be nullptr, if specified it is used as base type
	 * */
	std::unique_ptr<hdlObjects::iHdlExpr> visitImplicit_data_type(
			sv2017Parser::Implicit_data_typeContext *ctx,
			std::unique_ptr<hdlObjects::iHdlExpr> net_type);
	std::unique_ptr<hdlObjects::iHdlExpr> visitUnpacked_dimension(
			sv2017Parser::Unpacked_dimensionContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> applyUnpacked_dimension(
			std::unique_ptr<hdlObjects::iHdlExpr> base_expr,
			std::vector<sv2017Parser::Unpacked_dimensionContext*> &uds);
	std::unique_ptr<hdlObjects::iHdlExpr> applyVariable_dimension(
			std::unique_ptr<hdlObjects::iHdlExpr> base_expr,
			std::vector<sv2017Parser::Variable_dimensionContext*> &vds);
	std::unique_ptr<hdlObjects::iHdlExpr> visitPacked_dimension(
			sv2017Parser::Packed_dimensionContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitVariable_dimension(
			sv2017Parser::Variable_dimensionContext *ctx,
			std::unique_ptr<hdlObjects::iHdlExpr> selected_name);
	std::unique_ptr<hdlObjects::iHdlExpr> visitNet_type(
			sv2017Parser::Net_typeContext *ctx);
	// @note ctx can be nullptr
	std::unique_ptr<hdlObjects::iHdlExpr> visitNet_port_type(
			sv2017Parser::Net_port_typeContext *ctx);
	// @return type expr, is_latched flag
	std::pair<std::unique_ptr<hdlObjects::iHdlExpr>, bool> visitNet_or_var_data_type(
			sv2017Parser::Net_or_var_data_typeContext *ctx);
	/* @return true if static
	 * @attention static is default if lifetime is not specified
	 * @note ctx can be nullptr
	 */
	bool visitLifetime(sv2017Parser::LifetimeContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitFunction_data_type_or_implicit(
			sv2017Parser::Function_data_type_or_implicitContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitData_type_or_void(
			sv2017Parser::Data_type_or_voidContext *ctx);
	std::unique_ptr<hdlObjects::iHdlExpr> visitVar_data_type(
			sv2017Parser::Var_data_typeContext *ctx);
};

}
}
