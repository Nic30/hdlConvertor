
// Generated from /home/tom/prog/git/hdlConvertor/grammars/vpp.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  vppLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, INCLUDE = 5, DEFINE = 6, IFNDEF = 7, 
    UNDEF = 8, IFDEF = 9, ELSIF = 10, ELSE = 11, ENDIF = 12, IGNORED_DIRECTIVE = 13, 
    BACKTICK = 14, ID = 15, CharacterLiteral = 16, StringLiteral = 17, COMMENT = 18, 
    LINE_ESCAPE = 19, LINE_COMMENT = 20, WS = 21, OTHER = 22
  };

  vppLexer(antlr4::CharStream *input);
  ~vppLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

