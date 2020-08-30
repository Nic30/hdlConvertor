#include <string>
#include <ANTLRInputStream.h>
#include <hdlConvertor/universal_fs.h>

namespace hdlConvertor {

std::string iso_8859_1_to_utf8(const std::string &str);
std::string _to_utf8(const std::string &str, const std::string &encoding);
antlr4::ANTLRInputStream ANTLRFileStream_with_encoding(
		const std::filesystem::path &file_name, const std::string &encoding);

}
