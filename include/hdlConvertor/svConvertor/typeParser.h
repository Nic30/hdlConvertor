#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace sv {

class VerTypeParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	static hdlObjects::iHdlExpr* visitType_reference(
			sv2017Parser::Type_referenceContext *ctx);
	static hdlObjects::iHdlExpr* visitData_type(
			sv2017Parser::Data_typeContext *ctx);
	/*
	 * @note ctx can be nullptr
	 * */
	static hdlObjects::iHdlExpr* visitData_type_or_implicit(
			sv2017Parser::Data_type_or_implicitContext *ctx);
	static bool visitSigning(sv2017Parser::SigningContext *ctx);
	static hdlObjects::iHdlExpr* visitImplicit_data_type(
			sv2017Parser::Implicit_data_typeContext *ctx);
	static hdlObjects::iHdlExpr* visitUnpacked_dimension(
			sv2017Parser::Unpacked_dimensionContext *ctx);
	static hdlObjects::iHdlExpr* visitPacked_dimension(
			sv2017Parser::Packed_dimensionContext *ctx);
};

}
}
