#pragma once

#include <vector>

#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/baseSvParser.h>

namespace hdlConvertor {
namespace sv {

class VerAttributeParser: public BaseSvParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	using BaseSvParser::BaseSvParser;

	void visitAttribute_instance(hdlAst::iHdlObj &parent,
			sv2017Parser::Attribute_instanceContext *ctx);
	void visitAttribute_instance(hdlAst::iHdlObj &parent,
			std::vector<sv2017Parser::Attribute_instanceContext*> ctx);
	void visitAttr_spec_instance(hdlAst::iHdlObj &parent,
			sv2017Parser::Attr_specContext *ctx);
};

template<typename PARENT_PARSER_T, typename CTX_T, typename ITEM_T>
class VerVisitAttributeForVectorResult {
public:
	PARENT_PARSER_T *parentParser;
	CTX_T *ctx;
	std::vector<std::unique_ptr<ITEM_T>> &res;
	size_t originalSize;
	VerVisitAttributeForVectorResult(PARENT_PARSER_T *parentParser, CTX_T *ctx,
			std::vector<std::unique_ptr<ITEM_T>> &res) :
			parentParser(parentParser), ctx(ctx), res(res), originalSize(
					res.size()) {

	}
	~VerVisitAttributeForVectorResult() {
		VerAttributeParser ap(parentParser);
		for (auto item = res.begin() + originalSize; item != res.end();
				++item) {
			ITEM_T &_item = **item;
			ap.visitAttribute_instance(_item, ctx->attribute_instance());
		}
	}

};

}
}
