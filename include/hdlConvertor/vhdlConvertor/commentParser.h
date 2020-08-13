#pragma once
#pragma once

#include <string>
#include <antlr4-runtime.h>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlLexer.h>

namespace hdlConvertor {
namespace vhdl {

/**
 * @note very similar implementation in <hdlConvertor/veriligConverotcommentParser.h>
 * */
class VhdlCommentParser {
public:
	antlr4::CommonTokenStream & tokens;
	VhdlCommentParser(antlr4::TokenStream& _tokens);

	template<typename CONTEXT_T>
	std::string parse(CONTEXT_T * ctx) {
		std::string tmp = "";
		size_t last_token = ctx->getStart()->getTokenIndex();
		size_t first_comment_token = last_token;
		// find the first comment in block of comments
		while (true) {
			if (first_comment_token == 0)
				break;
			auto t = tokens.get(first_comment_token - 1);
			if (t->getChannel() != antlr4::Token::HIDDEN_CHANNEL) {
				//printf("break: %s\n", t->toString().c_str());
				break;
			}
			first_comment_token--;
		}
		// collect the text from the comments
		for (size_t i = first_comment_token; i < last_token; i++) {
			auto t = tokens.get(i);
			auto s = t->getText();
			auto tt = t->getType();
			using l = vhdl_antlr::vhdlLexer;
			bool is_whitespace = tt == l::TAB
					|| tt == l::SPACE
					|| tt == l::NEWLINE
					|| tt == l::CR
					|| tt == l::SPACE_CHARACTER;
			if (is_whitespace) {
				continue;
			}
			//printf("comment: %s, %s\n", s.c_str(), t->toString().c_str());
			// trim the whitespaces on the beginning
			size_t start = 0;
			while (start < s.size() && isspace(s[start]))
				start++;
			if (s.size() >= start + 2 && s[start + 0] == '-'
					&& s[start + 1] == '-') {
				// trim the starting "--" OR "-- "
				if (s.size() >= start + 3 && s[start + 3] == ' ')
					s = s.substr(start + 3);
				else
					s = s.substr(start + 2);
				//printf("comment after: %s\n", s.c_str());
			}
			tmp += s;
		}

		return tmp;
	}
};

}
}
