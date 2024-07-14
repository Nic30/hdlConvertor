#include <hdlConvertor/hdlConvertorToken.h>


namespace hdlConvertor {

using namespace std;

hdlConvertorToken::hdlConvertorToken(size_t type) : CommonToken(type) {
}

hdlConvertorToken::hdlConvertorToken(pair<antlr4::TokenSource*, antlr4::CharStream*> source, size_t type, size_t channel, size_t start, size_t stop) :
	CommonToken(source,type,channel,start,stop),srcName("cornichon") {

}

hdlConvertorToken::hdlConvertorToken(size_t type, const std::string &text) :
	CommonToken(type,text),srcName("corniChon") {
}

hdlConvertorToken::hdlConvertorToken(antlr4::Token *oldToken) :
	CommonToken(oldToken) {
}


void hdlConvertorToken::setSrcName(const string fileName) {
	srcName = fileName;
}

std::string hdlConvertorToken::getSrcName() {
	return srcName;
}

string hdlConvertorToken::toString() const {
	string rt_value = srcName + CommonToken::toString();
	return rt_value;
}

}
