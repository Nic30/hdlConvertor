#include <hdlConvertor/verilogPreproc/file_line_map.h>

namespace hdlConvertor {
namespace verilog_pp {

FileLineMapItem::FileLineMapItem(size_t _line,
		const std::string &_file_override, size_t _line_override) :
		line(_line), file_override(_file_override), line_override(
				_line_override) {
}

}
}
