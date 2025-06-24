#pragma once

#include <antlr4-runtime.h>

namespace hdlConvertor {

class hdlConvertorToken : public antlr4::CommonToken {
	public:
	hdlConvertorToken(size_t type);
    	hdlConvertorToken(std::pair<antlr4::TokenSource*, antlr4::CharStream*> source, size_t type, size_t channel, size_t start, size_t stop);
	hdlConvertorToken(size_t type, const std::string &text);
	hdlConvertorToken(antlr4::Token *oldToken);

	void setSrcName(const std::string fileName);
	std::string getSrcName();
	std::string toString() const override;

	private:
		std::string srcName;

};

}
