
#include "../verilogPreproc/macroPrototype.h"

#include "./symbol.h"

macroPrototype return_prototype(std::string input_token) {

  ANTLRInputStream input(input_token);

  verilogPreprocSymbolLexer * lexer = new verilogPreprocSymbolLexer(&input);
  CommonTokenStream * tokens = new CommonTokenStream(lexer);
  verilogPreprocSymbolParser * parser = new verilogPreprocSymbolParser(tokens);
  tree::ParseTree *tree = parser->pattern();

  tree::ParseTreeWalker walker = tree::ParseTreeWalker();
  symbol * extractor = new symbol();
  walker.walk( (tree::ParseTreeListener*) extractor,tree);

  macroPrototype return_value = extractor->data;

  delete extractor;
  delete parser;
  delete tokens;
  delete lexer;

  return return_value;
}
