#include <hdlConvertor/conversion_exception.h>

namespace hdlConvertor {

ParseException::ParseException(std::string msg) throw () :
		_msg(msg) {
}

const char* ParseException::what() const throw () {
	return _msg.c_str();
}

}
