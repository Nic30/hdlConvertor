#pragma once

#include <hdlConvertor/verilogPreproc/file_line_map.h>
#include <hdlConvertor/hdlConvertorToken.h>
#include <antlr4-runtime.h>
namespace hdlConvertor {

class hdlConvertorTokenFactory : public antlr4::CommonTokenFactory {
	public:
        static const std::unique_ptr<antlr4::TokenFactory<antlr4::CommonToken>> DEFAULT;

	hdlConvertorTokenFactory(bool copy_text);
	hdlConvertorTokenFactory();
	void setFileLineMap( verilog_pp::FileLineMap * file_line_map);

	std::unique_ptr<antlr4::CommonToken> create(
			std::pair<antlr4::TokenSource*, antlr4::CharStream*> source,
			size_t type,
      			const std::string &text,
			size_t channel,
			size_t start,
			size_t stop,
			size_t line,
			size_t charPositionInLine) override;

	std::unique_ptr<antlr4::CommonToken> create(
			size_t type,
			const std::string &text) override;


	private:
	static verilog_pp::FileLineMap *_file_line_map;

};

}
