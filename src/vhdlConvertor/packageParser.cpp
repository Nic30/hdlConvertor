#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/packageParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/processParser.h>
#include <hdlConvertor/createObject.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlAst;

std::unique_ptr<HdlValueIdspace> VhdlPackageParser::visitPackage_body(
		vhdlParser::Package_bodyContext* ctx) {
	// package_body:
	//       PACKAGE BODY identifier IS
	//           ( process_declarative_item )*
	//       END ( PACKAGE BODY )? ( identifier )? SEMI
	// ;
	p = create_object<HdlValueIdspace>(ctx);
	p->name = VhdlLiteralParser::getIdentifierStr(ctx->identifier(0));
        p->defs_only = false;

	if (!hierarchyOnly) {
		auto pdi = ctx->process_declarative_item();
		VhdlProcessParser pp(commentParser, hierarchyOnly);
		for (auto i : pdi) {
			pp.visitProcess_declarative_item(i, p->objs);
		}
	}
	return std::move(p);
}


}
}
