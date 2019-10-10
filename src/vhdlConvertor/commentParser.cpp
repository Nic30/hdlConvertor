#include <hdlConvertor/vhdlConvertor/commentParser.h>

namespace hdlConvertor {
namespace vhdl {

VhdlCommentParser::VhdlCommentParser(antlr4::TokenStream& _tokens) :
		tokens(dynamic_cast<antlr4::CommonTokenStream&>(_tokens)) {
}

}
}
