#include <hdlConvertor/verilogPreproc/macroDB.h>

using namespace std;

namespace hdlConvertor {
namespace verilog_pp {

MacroDB::~MacroDB() {
	for (auto item : *this) {
		delete item.second;
	}
}

}
}
