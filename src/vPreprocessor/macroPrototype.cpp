
#include "macroPrototype.h"
#include "symbol.h"

macroPrototype return_prototype(std::string input_token) {

  ANTLRInputStream input(input_token);

  symbolLexer * lexer = new symbolLexer(&input);
  CommonTokenStream * tokens = new CommonTokenStream(lexer);
  symbolParser * parser = new symbolParser(tokens);
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
