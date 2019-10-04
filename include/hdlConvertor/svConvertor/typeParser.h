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

	hdlObjects::iHdlExpr* visitType_reference(
			sv2017Parser::Type_referenceContext *ctx);
	hdlObjects::iHdlExpr* visitData_type(sv2017Parser::Data_typeContext *ctx);
	/*
	 * @note ctx can be nullptr
	 * @note net_type can be nullptr, if specified it is used as base type
	 * */
	hdlObjects::iHdlExpr* visitData_type_or_implicit(
			sv2017Parser::Data_type_or_implicitContext *ctx,
			hdlObjects::iHdlExpr *net_type);
	static bool visitSigning(sv2017Parser::SigningContext *ctx);
	/*
	 * @note net_type can be nullptr, if specified it is used as base type
	 * */
	hdlObjects::iHdlExpr* visitImplicit_data_type(
			sv2017Parser::Implicit_data_typeContext *ctx,
			hdlObjects::iHdlExpr *net_type);
	hdlObjects::iHdlExpr* visitUnpacked_dimension(
			sv2017Parser::Unpacked_dimensionContext *ctx);
	hdlObjects::iHdlExpr* applyUnpacked_dimension(
			hdlObjects::iHdlExpr *base_expr,
			std::vector<sv2017Parser::Unpacked_dimensionContext*> &uds);
	hdlObjects::iHdlExpr* applyVariable_dimension(
			hdlObjects::iHdlExpr *base_expr,
			std::vector<sv2017Parser::Variable_dimensionContext*> &vds);
	hdlObjects::iHdlExpr* visitPacked_dimension(
			sv2017Parser::Packed_dimensionContext *ctx);
	hdlObjects::iHdlExpr* visitVariable_dimension(
			sv2017Parser::Variable_dimensionContext *ctx,
			hdlObjects::iHdlExpr *selected_name);
	hdlObjects::iHdlExpr* visitNet_type(sv2017Parser::Net_typeContext *ctx);
	// @note ctx can be nullptr
	hdlObjects::iHdlExpr* visitNet_port_type(
			sv2017Parser::Net_port_typeContext *ctx);
	// @return type expr, is_latched flag
	std::pair<hdlObjects::iHdlExpr*, bool> visitNet_or_var_data_type(
			sv2017Parser::Net_or_var_data_typeContext *ctx);
	/* @return true if static
	 * @attention static is default if lifetime is not specified
	 * @note ctx can be nullptr
	 */
	bool visitLifetime(sv2017Parser::LifetimeContext *ctx);
	hdlObjects::iHdlExpr* visitFunction_data_type_or_implicit(
			sv2017Parser::Function_data_type_or_implicitContext *ctx);
	hdlObjects::iHdlExpr* visitData_type_or_void(
			sv2017Parser::Data_type_or_voidContext *ctx);
};

}
}
