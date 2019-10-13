#include <hdlConvertor/svConvertor/commentParser.h>

namespace hdlConvertor {
namespace sv {

SVCommentParser::SVCommentParser(antlr4::TokenStream & _tokens) :
		tokens(dynamic_cast<antlr4::CommonTokenStream &>(_tokens)) {
}

}
}
