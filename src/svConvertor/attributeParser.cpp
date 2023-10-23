#include <hdlConvertor/svConvertor/attributeParser.h>
#include <hdlConvertor/hdlAst/iHdlExprItem.h>

#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace sv {

void VerAttributeParser::visitAttribute_instance(hdlAst::iHdlObj &parent,
		sv2017Parser::Attribute_instanceContext *ctx) {
	// attribute_instance : '(' '*' attr_spec ( ',' attr_spec )* '*' ')' ;
	for (auto *as : ctx->attr_spec()) {
		visitAttr_spec_instance(parent, as);
	}
}

void VerAttributeParser::visitAttribute_instance(hdlAst::iHdlObj &parent,
		std::vector<sv2017Parser::Attribute_instanceContext*> ctx) {
	for (auto ai : ctx)
		visitAttribute_instance(parent, ai);
}

void VerAttributeParser::visitAttr_spec_instance(hdlAst::iHdlObj &parent,
		sv2017Parser::Attr_specContext *ctx) {
	// attr_spec: identifier ( ASSIGN expression )?;
	auto id = VerExprParser::getIdentifierStr(ctx->identifier());
	std::unique_ptr<hdlAst::iHdlExprItem> val = nullptr;
	if (auto e = ctx->expression()) {
		VerExprParser ep(this);
		val = ep.visitExpression(e);
	}
	if (!parent.hdlAttributes) {
		parent.hdlAttributes = new std::vector<hdlAst::iHdlObj::HdlAttribute>();
	}
	parent.hdlAttributes->push_back(hdlAst::iHdlObj::HdlAttribute(id, std::move(val)));
}

}
}
