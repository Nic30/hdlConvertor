
// Generated from /home/tom/prog/git/hdlConvertor/grammars/symbol.g4 by ANTLR 4.7


#include "symbolListener.h"

#include "symbolParser.h"


using namespace antlrcpp;
using namespace antlr4;

symbolParser::symbolParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

symbolParser::~symbolParser() {
  delete _interpreter;
}

std::string symbolParser::getGrammarFileName() const {
  return "symbol.g4";
}

const std::vector<std::string>& symbolParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& symbolParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- PatternContext ------------------------------------------------------------------

symbolParser::PatternContext::PatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> symbolParser::PatternContext::SYMBOL() {
  return getTokens(symbolParser::SYMBOL);
}

tree::TerminalNode* symbolParser::PatternContext::SYMBOL(size_t i) {
  return getToken(symbolParser::SYMBOL, i);
}

tree::TerminalNode* symbolParser::PatternContext::EOF() {
  return getToken(symbolParser::EOF, 0);
}


size_t symbolParser::PatternContext::getRuleIndex() const {
  return symbolParser::RulePattern;
}

void symbolParser::PatternContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<symbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPattern(this);
}

void symbolParser::PatternContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<symbolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPattern(this);
}

symbolParser::PatternContext* symbolParser::pattern() {
  PatternContext *_localctx = _tracker.createInstance<PatternContext>(_ctx, getState());
  enterRule(_localctx, 0, symbolParser::RulePattern);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2);
    match(symbolParser::SYMBOL);
    setState(13);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == symbolParser::T__0) {
      setState(3);
      match(symbolParser::T__0);
      setState(4);
      match(symbolParser::SYMBOL);
      setState(9);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == symbolParser::T__1) {
        setState(5);
        match(symbolParser::T__1);
        setState(6);
        match(symbolParser::SYMBOL);
        setState(11);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(12);
      match(symbolParser::T__2);
    }
    setState(15);
    match(symbolParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> symbolParser::_decisionToDFA;
atn::PredictionContextCache symbolParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN symbolParser::_atn;
std::vector<uint16_t> symbolParser::_serializedATN;

std::vector<std::string> symbolParser::_ruleNames = {
  "pattern"
};

std::vector<std::string> symbolParser::_literalNames = {
  "", "'('", "','", "')'"
};

std::vector<std::string> symbolParser::_symbolicNames = {
  "", "", "", "", "SYMBOL", "LETTER", "WS"
};

dfa::Vocabulary symbolParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> symbolParser::_tokenNames;

symbolParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x8, 0x14, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0xa, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xd, 0xb, 
    0x2, 0x3, 0x2, 0x5, 0x2, 0x10, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x2, 0x2, 0x3, 0x2, 0x2, 0x2, 0x2, 0x14, 0x2, 0x4, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0xf, 0x7, 0x6, 0x2, 0x2, 0x5, 0x6, 0x7, 0x3, 0x2, 0x2, 0x6, 0xb, 
    0x7, 0x6, 0x2, 0x2, 0x7, 0x8, 0x7, 0x4, 0x2, 0x2, 0x8, 0xa, 0x7, 0x6, 
    0x2, 0x2, 0x9, 0x7, 0x3, 0x2, 0x2, 0x2, 0xa, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0xb, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 0x3, 0x2, 0x2, 0x2, 0xc, 0xe, 
    0x3, 0x2, 0x2, 0x2, 0xd, 0xb, 0x3, 0x2, 0x2, 0x2, 0xe, 0x10, 0x7, 0x5, 
    0x2, 0x2, 0xf, 0x5, 0x3, 0x2, 0x2, 0x2, 0xf, 0x10, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x11, 0x3, 0x2, 0x2, 0x2, 0x11, 0x12, 0x7, 0x2, 0x2, 0x3, 0x12, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x4, 0xb, 0xf, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

symbolParser::Initializer symbolParser::_init;
