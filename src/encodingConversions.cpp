#include <hdlConvertor/encodingConversions.h>
#include <locale>
#include <codecvt>

namespace hdlConvertor {

std::string iso_8859_1_to_utf8(const std::string &str) {
	std::string strOut;
	strOut.reserve(str.size());
	for (auto it = str.begin(); it != str.end(); ++it) {
		uint8_t ch = *it;
		if (ch < 0x80) {
			strOut.push_back(ch);
		} else {
			strOut.push_back(0xc0 | ch >> 6);
			strOut.push_back(0x80 | (ch & 0x3f));
		}
	}
	return strOut;
}

std::string _to_utf8(const std::string &str, const std::string &encoding) {
	if (encoding == "utf-8") {
		return str;
	} else if (encoding == "utf-16") {
		std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
		return convert.to_bytes(reinterpret_cast<const std::u16string&>(str));
	} else if (encoding == "iso-8859-1") {
		return iso_8859_1_to_utf8(str);
	} else {
		throw std::runtime_error(
				"iParserContainer implemented only for utf-8, utf-16 and iso-8859-1, recieved:"
						+ encoding);
	}
}

antlr4::ANTLRInputStream ANTLRFileStream_with_encoding(
		const std::filesystem::path &file_name, const std::string &encoding) {
	std::ifstream ifs(file_name);
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	std::string str(size, ' ');
	ifs.seekg(0);
	ifs.read(&str[0], size);
	str = _to_utf8(str, encoding);

	try {
		antlr4::ANTLRInputStream input_stream(str);
		input_stream.name = file_name.u8string();
		return input_stream;
	} catch (const std::range_error &e) {
		throw std::range_error(
				std::string("Invalid character/encoding in ")
						+ file_name.u8string() + " file");
	}
}

}
