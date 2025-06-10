#include <hdlConvertor/hdlConvertorTokenFactory.h>

namespace hdlConvertor {

using namespace std;

const std::unique_ptr<antlr4::TokenFactory<antlr4::CommonToken>> hdlConvertorTokenFactory::DEFAULT(new hdlConvertorTokenFactory);

verilog_pp::FileLineMap* hdlConvertorTokenFactory::_file_line_map = nullptr;


hdlConvertorTokenFactory::hdlConvertorTokenFactory(
		bool copyText) :
	CommonTokenFactory(copyText) {
}

hdlConvertorTokenFactory::hdlConvertorTokenFactory() {
}

void hdlConvertorTokenFactory::setFileLineMap( verilog_pp::FileLineMap * file_line_map){
	hdlConvertorTokenFactory::_file_line_map = file_line_map;
}

std::unique_ptr<antlr4::CommonToken>
hdlConvertorTokenFactory::create(
	std::pair<antlr4::TokenSource*, antlr4::CharStream*> source,
	size_t type,
      	const std::string &text,
	size_t channel,
	size_t start,
	size_t stop,
	size_t line,
	size_t charPositionInLine) {

	bool found = false;

	std::unique_ptr<antlr4::CommonToken> t(new hdlConvertorToken(
				source, type, channel, start, stop
				)
			);

	hdlConvertorToken * ptr = dynamic_cast<hdlConvertorToken *>(t.get());

	std::vector<verilog_pp::FileLineMapItem>::iterator fileLineMap_iter;
	fileLineMap_iter = (*hdlConvertorTokenFactory::_file_line_map).begin();
	while (fileLineMap_iter != (*hdlConvertorTokenFactory::_file_line_map).end() && found==false) {

		if (line == (fileLineMap_iter->line+1)) {
			found = true;
			ptr->setLine(fileLineMap_iter->line_override+1);
			ptr->setSrcName(fileLineMap_iter->file_override);
		}

		fileLineMap_iter++;
	}
	if (found ==  false) {
		ptr->setLine(line);
		/* line not found ! For time beeing keep original data
		std::cout << "Drama! "
			<< text
			<< "line: "<< line << " not found" << std::endl;
		*/
	}
	ptr->setCharPositionInLine(charPositionInLine);
	if (text != "") {
		ptr->setText(text);
	} else if (copyText && source.second != nullptr) {
		ptr->setText(source.second->getText(antlr4::misc::Interval(start, stop)));
	}

	return t;
}



std::unique_ptr<antlr4::CommonToken>
hdlConvertorTokenFactory::create(
	size_t type,
	const std::string &text) {
	return std::unique_ptr<antlr4::CommonToken>(new hdlConvertorToken(type, text));

}

}
