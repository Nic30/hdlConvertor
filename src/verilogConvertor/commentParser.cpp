#include <hdlConvertor/verilogConvertor/commentParser.h>

namespace hdlConvertor {
namespace verilog {

CommentParser::CommentParser(antlr4::TokenStream * _tokens) :
		tokens(*dynamic_cast<antlr4::CommonTokenStream *>(_tokens)) {
}

}
}
