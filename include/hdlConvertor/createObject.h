#pragma once

#include <hdlConvertor/hdlObjects/iHdlObj.h>
#include <hdlConvertor/hdlObjects/named.h>

#include <antlr4-runtime.h>

#include <memory>

namespace hdlConvertor {
	template<typename T, typename... Args>
	std::unique_ptr<T> create_object(antlr4::tree::ParseTree *const node, Args &&... args) {
		std::unique_ptr<T> object = std::make_unique<T>(std::forward<Args>(args)...);
		if (node) {
			antlr4::ParserRuleContext *ctx = dynamic_cast<antlr4::ParserRuleContext *>(node);
			if (!ctx) {
				antlr4::tree::TerminalNode *const tn = dynamic_cast<antlr4::tree::TerminalNode *>(node);
				if (tn && tn->parent) {
					ctx = dynamic_cast<antlr4::ParserRuleContext *>(tn->parent);
				}
			}

			if (ctx) {
				auto wp = dynamic_cast<hdlObjects::WithPos *>(object.get());
				if (wp) {
					wp->position.update_from_elem(ctx);
				}
			}
		}
		return object;
	}
}
