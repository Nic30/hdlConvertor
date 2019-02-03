#include "../verilogPreproc/macroSymbol.h"

#include "../verilogPreproc/vPreprocessor.h"

void macroSymbol::insert(const std::pair<std::string, macro_replace*> item,
		std::vector<std::string> &incdir,unsigned int mode) {

  std::string new_replacement = return_preprocessed(item.second->data.tmplate,
			incdir, *this,mode);
  item.second->data.tmplate = new_replacement;
  std::map<std::string, macro_replace*>::insert(item);
}
