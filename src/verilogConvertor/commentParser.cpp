#include "commentParser.h"

CommentParser::CommentParser(antlr4::TokenStream * _tokens) :
		tokens(*dynamic_cast<antlr4::CommonTokenStream *>(_tokens)) {
}
