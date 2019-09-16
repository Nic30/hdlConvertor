#include <hdlConvertor/conversion_exception.h>

namespace hdlConvertor {

const char* get_cpp_py_error_message() {
	try {
		throw;
	} catch (const ParseException& e) {
		return e.what();
	} catch (const std::exception &e) {
		return e.what();
	}
	return "<unknown C++ exception>";
}

}
