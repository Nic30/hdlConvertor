#pragma once

#include <string>
#include <antlr4-runtime.h>
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
//[TODO] naive impl. only
template<typename CONTEXT_T>
std::string parseComment(antlr4::TokenStream * tokens, CONTEXT_T * ctx) {
	std::string tmp;
	auto comment_pre =
			dynamic_cast<antlr4::CommonTokenStream *>(tokens)->getHiddenTokensToLeft(
					ctx->getStart()->getTokenIndex(),
					antlr4::Token::HIDDEN_CHANNEL);
	for (auto c : comment_pre) {
		auto s = c->getText();
		if (s.size() >= 2 && s[0] == '/' && s[1] == '/') {
			// trim the starting //
			s = s.substr(2);
		}
		tmp += s;
	}
	return tmp;
}
