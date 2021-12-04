#include <hdlConvertor/createObject.h>

#include <hdlConvertor/vhdlConvertor/blockParser.h>
#include <hdlConvertor/vhdlConvertor/blockDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/compInstanceParser.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/generateStatementParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/processParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/signalParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>
#include <assert.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlAst;
using namespace std;

template<typename CTX_T>
std::unique_ptr<iHdlStatement> VhdlBlockStatementParser::visitBlock_statement(
		CTX_T *ctx) {
//	block_statement:
//     KW_BLOCK ( LPAREN condition RPAREN )? ( KW_IS )?
//         block_header
//         ( block_declarative_item )*
//     KW_BEGIN
//         ( concurrent_statement )*
//     KW_END KW_BLOCK ( label )? SEMI
	auto bdis = ctx->block_declarative_item();
	auto cstms = ctx->concurrent_statement();
	VhdlStatementParser sp(commentParser, hierarchyOnly);
	auto b = create_object<HdlStmBlock>(ctx);
	b->in_preproc = true;
	if (bdis.size()) {
		VhdlBlockDeclarationParser _bdp(commentParser, hierarchyOnly);
		for (auto bdi : ctx->block_declarative_item()) {
			_bdp.visitBlock_declarative_item(bdi, b->statements);
		}
	}
	for (auto cs : ctx->concurrent_statement()) {
		sp.visitConcurrent_statement(cs, b->statements);
	}
	return b;
}

template std::unique_ptr<hdlAst::iHdlStatement> VhdlBlockStatementParser::visitBlock_statement<
		vhdl_antlr::vhdlParser::Block_statementContext>(
		vhdl_antlr::vhdlParser::Block_statementContext *ctx);
}
}
