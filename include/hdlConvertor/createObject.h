#pragma once

#include <hdlConvertor/hdlAst/iHdlObj.h>
#include <hdlConvertor/hdlAst/named.h>

#include <antlr4-runtime.h>

#include <memory>

namespace hdlConvertor {

template<typename T>
std::unique_ptr<T> update_code_position(std::unique_ptr<T> object,
		antlr4::tree::ParseTree *const node) {
	if (node) {
		// node can be ParserRuleContext or TerminalNode, get ParserRuleContext
		auto ctx = dynamic_cast<antlr4::ParserRuleContext*>(node);
		if (!ctx) {
			auto tn = dynamic_cast<antlr4::tree::TerminalNode*>(node);
			if (tn && tn->parent) {
				ctx = dynamic_cast<antlr4::ParserRuleContext*>(tn->parent);
			}
		}

		if (ctx) {
			auto wp = dynamic_cast<hdlAst::WithPos*>(object.get());
			if (wp) {
				wp->position.update_from_elem(ctx);
			}
		}
	}
	return object;
}
/*
 * Call an object constructor and set code position
 * (info about where the object is in parsed source code)
 * */
template<typename T, typename ... Args>
std::unique_ptr<T> create_object(antlr4::tree::ParseTree *const node,
		Args &&... args) {
	// call a constructor with arguments specified and create a unique_ptr
	auto object = std::make_unique<T>(std::forward<Args>(args)...);
	return update_code_position(std::move(object), node);
}
/*
 * Call an object constructor and set code position
 * (info about where the object is in parsed source code)
 * */
template<typename T, typename DOC_PARSER_T, typename ANTLR_NODE_T, typename ... Args>
std::unique_ptr<T> create_object_with_doc(ANTLR_NODE_T *const node, DOC_PARSER_T doc_parser,
		Args &&... args) {
	// call a constructor with arguments specified and create a unique_ptr
	auto object = std::make_unique<T>(std::forward<Args>(args)...);
	object = update_code_position(std::move(object), node);
	object->__doc__ = doc_parser.parse(node);
	return object;
}

}
