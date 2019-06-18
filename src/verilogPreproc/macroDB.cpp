#include <hdlConvertor/verilogPreproc/vPreprocessor.h>
#include <hdlConvertor/verilogPreproc/macroDB.h>

using namespace std;

namespace hdlConvertor {
namespace verilog_pp {

void MacroDB::insert(const pair<string, MacroDef*> item) {
	map<string, MacroDef*>::insert(item);
}

}
}
