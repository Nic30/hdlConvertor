#include <hdlConvertor/verilogPreproc/macroSymbol.h>
#include <hdlConvertor/verilogPreproc/vPreprocessor.h>

using namespace std;

namespace hdlConvertor {
namespace verilog_pp {

void macroSymbol::insert(const pair<string, macro_replace*> item) {
	map<string, macro_replace*>::insert(item);
}

}
}
