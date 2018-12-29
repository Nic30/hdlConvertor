
// Generated from /home/tom/prog/git/hdlConvertor/grammars/vpp.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  vppParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, INCLUDE = 5, DEFINE = 6, IFNDEF = 7, 
    UNDEF = 8, IFDEF = 9, ELSIF = 10, ELSE = 11, ENDIF = 12, IGNORED_DIRECTIVE = 13, 
    BACKTICK = 14, ID = 15, CharacterLiteral = 16, StringLiteral = 17, COMMENT = 18, 
    LINE_ESCAPE = 19, LINE_COMMENT = 20, WS = 21, OTHER = 22
  };

  enum {
    RuleFile = 0, RulePreprocess_directive = 1, RuleDefine = 2, RuleReplacement = 3, 
    RuleUndef = 4, RuleConditional = 5, RuleIfdef_directive = 6, RuleIfndef_directive = 7, 
    RuleIfdef_group_of_lines = 8, RuleIfndef_group_of_lines = 9, RuleElsif_group_of_lines = 10, 
    RuleElse_group_of_lines = 11, RuleGroup_of_lines = 12, RuleToken_id = 13, 
    RuleInclude = 14, RuleMacro_id = 15, RuleMacro_toreplace = 16
  };

  vppParser(antlr4::TokenStream *input);
  ~vppParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class Preprocess_directiveContext;
  class DefineContext;
  class ReplacementContext;
  class UndefContext;
  class ConditionalContext;
  class Ifdef_directiveContext;
  class Ifndef_directiveContext;
  class Ifdef_group_of_linesContext;
  class Ifndef_group_of_linesContext;
  class Elsif_group_of_linesContext;
  class Else_group_of_linesContext;
  class Group_of_linesContext;
  class Token_idContext;
  class IncludeContext;
  class Macro_idContext;
  class Macro_toreplaceContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Preprocess_directiveContext *> preprocess_directive();
    Preprocess_directiveContext* preprocess_directive(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  Preprocess_directiveContext : public antlr4::ParserRuleContext {
  public:
    Preprocess_directiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DefineContext *define();
    UndefContext *undef();
    ConditionalContext *conditional();
    IncludeContext *include();
    Token_idContext *token_id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Preprocess_directiveContext* preprocess_directive();

  class  DefineContext : public antlr4::ParserRuleContext {
  public:
    DefineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFINE();
    Macro_idContext *macro_id();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    ReplacementContext *replacement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DefineContext* define();

  class  ReplacementContext : public antlr4::ParserRuleContext {
  public:
    ReplacementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReplacementContext* replacement();

  class  UndefContext : public antlr4::ParserRuleContext {
  public:
    UndefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNDEF();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UndefContext* undef();

  class  ConditionalContext : public antlr4::ParserRuleContext {
  public:
    ConditionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ifdef_directiveContext *ifdef_directive();
    Ifndef_directiveContext *ifndef_directive();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConditionalContext* conditional();

  class  Ifdef_directiveContext : public antlr4::ParserRuleContext {
  public:
    Ifdef_directiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IFDEF();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    Ifdef_group_of_linesContext *ifdef_group_of_lines();
    antlr4::tree::TerminalNode *ENDIF();
    std::vector<antlr4::tree::TerminalNode *> ELSIF();
    antlr4::tree::TerminalNode* ELSIF(size_t i);
    std::vector<Elsif_group_of_linesContext *> elsif_group_of_lines();
    Elsif_group_of_linesContext* elsif_group_of_lines(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    Else_group_of_linesContext *else_group_of_lines();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ifdef_directiveContext* ifdef_directive();

  class  Ifndef_directiveContext : public antlr4::ParserRuleContext {
  public:
    Ifndef_directiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IFNDEF();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    Ifndef_group_of_linesContext *ifndef_group_of_lines();
    antlr4::tree::TerminalNode *ENDIF();
    std::vector<antlr4::tree::TerminalNode *> ELSIF();
    antlr4::tree::TerminalNode* ELSIF(size_t i);
    std::vector<Elsif_group_of_linesContext *> elsif_group_of_lines();
    Elsif_group_of_linesContext* elsif_group_of_lines(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    Else_group_of_linesContext *else_group_of_lines();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ifndef_directiveContext* ifndef_directive();

  class  Ifdef_group_of_linesContext : public antlr4::ParserRuleContext {
  public:
    Ifdef_group_of_linesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Group_of_linesContext *group_of_lines();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ifdef_group_of_linesContext* ifdef_group_of_lines();

  class  Ifndef_group_of_linesContext : public antlr4::ParserRuleContext {
  public:
    Ifndef_group_of_linesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Group_of_linesContext *group_of_lines();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ifndef_group_of_linesContext* ifndef_group_of_lines();

  class  Elsif_group_of_linesContext : public antlr4::ParserRuleContext {
  public:
    Elsif_group_of_linesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Group_of_linesContext *group_of_lines();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Elsif_group_of_linesContext* elsif_group_of_lines();

  class  Else_group_of_linesContext : public antlr4::ParserRuleContext {
  public:
    Else_group_of_linesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Group_of_linesContext *group_of_lines();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Else_group_of_linesContext* else_group_of_lines();

  class  Group_of_linesContext : public antlr4::ParserRuleContext {
  public:
    Group_of_linesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Preprocess_directiveContext *> preprocess_directive();
    Preprocess_directiveContext* preprocess_directive(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Group_of_linesContext* group_of_lines();

  class  Token_idContext : public antlr4::ParserRuleContext {
  public:
    Token_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BACKTICK();
    Macro_toreplaceContext *macro_toreplace();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Token_idContext* token_id();

  class  IncludeContext : public antlr4::ParserRuleContext {
  public:
    IncludeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCLUDE();
    antlr4::tree::TerminalNode *StringLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IncludeContext* include();

  class  Macro_idContext : public antlr4::ParserRuleContext {
  public:
    Macro_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Macro_idContext* macro_id();

  class  Macro_toreplaceContext : public antlr4::ParserRuleContext {
  public:
    Macro_toreplaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Macro_toreplaceContext* macro_toreplace();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

