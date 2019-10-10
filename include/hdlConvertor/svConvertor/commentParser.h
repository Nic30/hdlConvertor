#pragma once

#include <string>
#include <antlr4-runtime.h>
#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Lexer.h>

namespace hdlConvertor {
namespace sv {

/**
 * The comment parser reads the text from the hidden tokens
 * generated from the antlr lexer. This tokens are not connected
 * to a AST tree and they have know position in text.
 * Problem is that there is no way to tell to which object exactly the comment
 * actually belong to. However this feature is not meant to work with any code and is not critical.
 *
 * The comments are parsed in this way:
 *  * There is no difference between the single-line comment and multi-line comment.
 *  * Multiple comments are merged together, if there is no doc capable object between them.
 *  * The doc capable object are object from the hdlObject which are derived from the WithDoc class.
 *    (declarations, statements, ...)
 *  * If the comment is before the object (definition, statement, ...)
 *    and it was not assigned to anything else.
 *    The comment is assigned to his object.
 *  * If the comment is on same line as an object the comment is assigned to this object.
 *    (The object can be on multiple lines, in this case this apply to comments on all lines.)
 *  * For object which declaration is composed by several parts (like Verilog ports,
 *    where the type is specified inside of the module). The comments are concatenated.
 * */
class SVCommentParser {
	antlr4::CommonTokenStream & tokens;
public:
	SVCommentParser(antlr4::TokenStream & _tokens);

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
			if (t->getType() == sv2017_antlr::sv2017Lexer::WHITE_SPACE) {
				continue;
			}
			//printf("comment: %s, %s\n", s.c_str(), t->toString().c_str());
			// trim the whitespaces on the beginning
			size_t start = 0;
			while (start < s.size() && isspace(s[start]))
				start++;
			if (s.size() >= start + 2 && s[start + 0] == '/'
					&& s[start + 1] == '/') {
				// trim the starting "//" OR "// "
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
