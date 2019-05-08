#include "../verilogPreproc/macroSymbol.h"
#include "../verilogPreproc/vPreprocessor.h"

using namespace std;

void macroSymbol::insert(const pair<string, macro_replace*> item,
		vector<string> &incdir, vector<string> &stack_incfile,
		unsigned int mode) {

	//string new_replacement = return_preprocessed(item.second->data.tmplate,
	//			incdir, *this,stack_incfile, mode);
	//item.second->data.tmplate = new_replacement;

	map<string, macro_replace*>::insert(item);
}
