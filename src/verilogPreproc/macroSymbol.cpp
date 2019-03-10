#include "../verilogPreproc/macroSymbol.h"

#include "../verilogPreproc/vPreprocessor.h"

void macroSymbol::insert(const std::pair<std::string, macro_replace*> item,
		std::vector<std::string> &incdir,  
		std::vector<std::string> &stack_incfile, unsigned int mode) {

  //std::string new_replacement = return_preprocessed(item.second->data.tmplate,
  //			incdir, *this,stack_incfile, mode);
  //item.second->data.tmplate = new_replacement;
  
  std::map<std::string, macro_replace*>::insert(item);
}