
// Generated from grammars/vhdl.g4 by ANTLR 4.7


#include "vhdlVisitor.h"

#include "vhdlParser.h"


using namespace antlrcpp;
using namespace vhdl;
using namespace antlr4;

vhdlParser::vhdlParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

vhdlParser::~vhdlParser() {
  delete _interpreter;
}

std::string vhdlParser::getGrammarFileName() const {
  return "vhdl.g4";
}

const std::vector<std::string>& vhdlParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& vhdlParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Abstract_literalContext ------------------------------------------------------------------

vhdlParser::Abstract_literalContext::Abstract_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Abstract_literalContext::INTEGER() {
  return getToken(vhdlParser::INTEGER, 0);
}

tree::TerminalNode* vhdlParser::Abstract_literalContext::REAL_LITERAL() {
  return getToken(vhdlParser::REAL_LITERAL, 0);
}

tree::TerminalNode* vhdlParser::Abstract_literalContext::BASE_LITERAL() {
  return getToken(vhdlParser::BASE_LITERAL, 0);
}


size_t vhdlParser::Abstract_literalContext::getRuleIndex() const {
  return vhdlParser::RuleAbstract_literal;
}

antlrcpp::Any vhdlParser::Abstract_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAbstract_literal(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Abstract_literalContext* vhdlParser::abstract_literal() {
  Abstract_literalContext *_localctx = _tracker.createInstance<Abstract_literalContext>(_ctx, getState());
  enterRule(_localctx, 0, vhdlParser::RuleAbstract_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(550);
    _la = _input->LA(1);
    if (!(((((_la - 114) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 114)) & ((1ULL << (vhdlParser::BASE_LITERAL - 114))
      | (1ULL << (vhdlParser::REAL_LITERAL - 114))
      | (1ULL << (vhdlParser::INTEGER - 114)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Access_type_definitionContext ------------------------------------------------------------------

vhdlParser::Access_type_definitionContext::Access_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Access_type_definitionContext::ACCESS() {
  return getToken(vhdlParser::ACCESS, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Access_type_definitionContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::Access_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleAccess_type_definition;
}

antlrcpp::Any vhdlParser::Access_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAccess_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Access_type_definitionContext* vhdlParser::access_type_definition() {
  Access_type_definitionContext *_localctx = _tracker.createInstance<Access_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 2, vhdlParser::RuleAccess_type_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(552);
    match(vhdlParser::ACCESS);
    setState(553);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Across_aspectContext ------------------------------------------------------------------

vhdlParser::Across_aspectContext::Across_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Identifier_listContext* vhdlParser::Across_aspectContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Across_aspectContext::ACROSS() {
  return getToken(vhdlParser::ACROSS, 0);
}

vhdlParser::Tolerance_aspectContext* vhdlParser::Across_aspectContext::tolerance_aspect() {
  return getRuleContext<vhdlParser::Tolerance_aspectContext>(0);
}

tree::TerminalNode* vhdlParser::Across_aspectContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Across_aspectContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Across_aspectContext::getRuleIndex() const {
  return vhdlParser::RuleAcross_aspect;
}

antlrcpp::Any vhdlParser::Across_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAcross_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Across_aspectContext* vhdlParser::across_aspect() {
  Across_aspectContext *_localctx = _tracker.createInstance<Across_aspectContext>(_ctx, getState());
  enterRule(_localctx, 4, vhdlParser::RuleAcross_aspect);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(555);
    identifier_list();
    setState(557);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::TOLERANCE) {
      setState(556);
      tolerance_aspect();
    }
    setState(561);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(559);
      match(vhdlParser::VARASGN);
      setState(560);
      expression();
    }
    setState(563);
    match(vhdlParser::ACROSS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Actual_designatorContext ------------------------------------------------------------------

vhdlParser::Actual_designatorContext::Actual_designatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::ExpressionContext* vhdlParser::Actual_designatorContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Actual_designatorContext::OPEN() {
  return getToken(vhdlParser::OPEN, 0);
}


size_t vhdlParser::Actual_designatorContext::getRuleIndex() const {
  return vhdlParser::RuleActual_designator;
}

antlrcpp::Any vhdlParser::Actual_designatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitActual_designator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Actual_designatorContext* vhdlParser::actual_designator() {
  Actual_designatorContext *_localctx = _tracker.createInstance<Actual_designatorContext>(_ctx, getState());
  enterRule(_localctx, 6, vhdlParser::RuleActual_designator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(567);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::ABS:
      case vhdlParser::NEW:
      case vhdlParser::NOT:
      case vhdlParser::NULL_SYM:
      case vhdlParser::BASE_LITERAL:
      case vhdlParser::BIT_STRING_LITERAL:
      case vhdlParser::REAL_LITERAL:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::LPAREN:
      case vhdlParser::PLUS:
      case vhdlParser::MINUS:
      case vhdlParser::CONDITION_OPERATOR:
      case vhdlParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(565);
        expression();
        break;
      }

      case vhdlParser::OPEN: {
        enterOuterAlt(_localctx, 2);
        setState(566);
        match(vhdlParser::OPEN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Actual_parameter_partContext ------------------------------------------------------------------

vhdlParser::Actual_parameter_partContext::Actual_parameter_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Association_listContext* vhdlParser::Actual_parameter_partContext::association_list() {
  return getRuleContext<vhdlParser::Association_listContext>(0);
}


size_t vhdlParser::Actual_parameter_partContext::getRuleIndex() const {
  return vhdlParser::RuleActual_parameter_part;
}

antlrcpp::Any vhdlParser::Actual_parameter_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitActual_parameter_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Actual_parameter_partContext* vhdlParser::actual_parameter_part() {
  Actual_parameter_partContext *_localctx = _tracker.createInstance<Actual_parameter_partContext>(_ctx, getState());
  enterRule(_localctx, 8, vhdlParser::RuleActual_parameter_part);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(569);
    association_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Actual_partContext ------------------------------------------------------------------

vhdlParser::Actual_partContext::Actual_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Actual_partContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Actual_partContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Actual_designatorContext* vhdlParser::Actual_partContext::actual_designator() {
  return getRuleContext<vhdlParser::Actual_designatorContext>(0);
}

tree::TerminalNode* vhdlParser::Actual_partContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Actual_partContext::getRuleIndex() const {
  return vhdlParser::RuleActual_part;
}

antlrcpp::Any vhdlParser::Actual_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitActual_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Actual_partContext* vhdlParser::actual_part() {
  Actual_partContext *_localctx = _tracker.createInstance<Actual_partContext>(_ctx, getState());
  enterRule(_localctx, 10, vhdlParser::RuleActual_part);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(577);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(571);
      name();
      setState(572);
      match(vhdlParser::LPAREN);
      setState(573);
      actual_designator();
      setState(574);
      match(vhdlParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(576);
      actual_designator();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Adding_operatorContext ------------------------------------------------------------------

vhdlParser::Adding_operatorContext::Adding_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Adding_operatorContext::PLUS() {
  return getToken(vhdlParser::PLUS, 0);
}

tree::TerminalNode* vhdlParser::Adding_operatorContext::MINUS() {
  return getToken(vhdlParser::MINUS, 0);
}

tree::TerminalNode* vhdlParser::Adding_operatorContext::AMPERSAND() {
  return getToken(vhdlParser::AMPERSAND, 0);
}


size_t vhdlParser::Adding_operatorContext::getRuleIndex() const {
  return vhdlParser::RuleAdding_operator;
}

antlrcpp::Any vhdlParser::Adding_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAdding_operator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Adding_operatorContext* vhdlParser::adding_operator() {
  Adding_operatorContext *_localctx = _tracker.createInstance<Adding_operatorContext>(_ctx, getState());
  enterRule(_localctx, 12, vhdlParser::RuleAdding_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(579);
    _la = _input->LA(1);
    if (!(((((_la - 145) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 145)) & ((1ULL << (vhdlParser::AMPERSAND - 145))
      | (1ULL << (vhdlParser::PLUS - 145))
      | (1ULL << (vhdlParser::MINUS - 145)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AggregateContext ------------------------------------------------------------------

vhdlParser::AggregateContext::AggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::AggregateContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Element_associationContext *> vhdlParser::AggregateContext::element_association() {
  return getRuleContexts<vhdlParser::Element_associationContext>();
}

vhdlParser::Element_associationContext* vhdlParser::AggregateContext::element_association(size_t i) {
  return getRuleContext<vhdlParser::Element_associationContext>(i);
}

tree::TerminalNode* vhdlParser::AggregateContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::AggregateContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::AggregateContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::AggregateContext::getRuleIndex() const {
  return vhdlParser::RuleAggregate;
}

antlrcpp::Any vhdlParser::AggregateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAggregate(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::AggregateContext* vhdlParser::aggregate() {
  AggregateContext *_localctx = _tracker.createInstance<AggregateContext>(_ctx, getState());
  enterRule(_localctx, 14, vhdlParser::RuleAggregate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(581);
    match(vhdlParser::LPAREN);
    setState(582);
    element_association();
    setState(587);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(583);
      match(vhdlParser::COMMA);
      setState(584);
      element_association();
      setState(589);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(590);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Alias_declarationContext ------------------------------------------------------------------

vhdlParser::Alias_declarationContext::Alias_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Alias_declarationContext::ALIAS() {
  return getToken(vhdlParser::ALIAS, 0);
}

vhdlParser::Alias_designatorContext* vhdlParser::Alias_declarationContext::alias_designator() {
  return getRuleContext<vhdlParser::Alias_designatorContext>(0);
}

tree::TerminalNode* vhdlParser::Alias_declarationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::NameContext* vhdlParser::Alias_declarationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Alias_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Alias_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Alias_indicationContext* vhdlParser::Alias_declarationContext::alias_indication() {
  return getRuleContext<vhdlParser::Alias_indicationContext>(0);
}

vhdlParser::SignatureContext* vhdlParser::Alias_declarationContext::signature() {
  return getRuleContext<vhdlParser::SignatureContext>(0);
}


size_t vhdlParser::Alias_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleAlias_declaration;
}

antlrcpp::Any vhdlParser::Alias_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAlias_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Alias_declarationContext* vhdlParser::alias_declaration() {
  Alias_declarationContext *_localctx = _tracker.createInstance<Alias_declarationContext>(_ctx, getState());
  enterRule(_localctx, 16, vhdlParser::RuleAlias_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(592);
    match(vhdlParser::ALIAS);
    setState(593);
    alias_designator();
    setState(596);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::COLON) {
      setState(594);
      match(vhdlParser::COLON);
      setState(595);
      alias_indication();
    }
    setState(598);
    match(vhdlParser::IS);
    setState(599);
    name();
    setState(601);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LBRACKET) {
      setState(600);
      signature();
    }
    setState(603);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Alias_designatorContext ------------------------------------------------------------------

vhdlParser::Alias_designatorContext::Alias_designatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Alias_designatorContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Alias_designatorContext::CHARACTER_LITERAL() {
  return getToken(vhdlParser::CHARACTER_LITERAL, 0);
}

tree::TerminalNode* vhdlParser::Alias_designatorContext::STRING_LITERAL() {
  return getToken(vhdlParser::STRING_LITERAL, 0);
}


size_t vhdlParser::Alias_designatorContext::getRuleIndex() const {
  return vhdlParser::RuleAlias_designator;
}

antlrcpp::Any vhdlParser::Alias_designatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAlias_designator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Alias_designatorContext* vhdlParser::alias_designator() {
  Alias_designatorContext *_localctx = _tracker.createInstance<Alias_designatorContext>(_ctx, getState());
  enterRule(_localctx, 18, vhdlParser::RuleAlias_designator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(608);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(605);
        identifier();
        break;
      }

      case vhdlParser::CHARACTER_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(606);
        match(vhdlParser::CHARACTER_LITERAL);
        break;
      }

      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(607);
        match(vhdlParser::STRING_LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Alias_indicationContext ------------------------------------------------------------------

vhdlParser::Alias_indicationContext::Alias_indicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subnature_indicationContext* vhdlParser::Alias_indicationContext::subnature_indication() {
  return getRuleContext<vhdlParser::Subnature_indicationContext>(0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Alias_indicationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::Alias_indicationContext::getRuleIndex() const {
  return vhdlParser::RuleAlias_indication;
}

antlrcpp::Any vhdlParser::Alias_indicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAlias_indication(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Alias_indicationContext* vhdlParser::alias_indication() {
  Alias_indicationContext *_localctx = _tracker.createInstance<Alias_indicationContext>(_ctx, getState());
  enterRule(_localctx, 20, vhdlParser::RuleAlias_indication);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(612);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(610);
      subnature_indication();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(611);
      subtype_indication();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AllocatorContext ------------------------------------------------------------------

vhdlParser::AllocatorContext::AllocatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::AllocatorContext::NEW() {
  return getToken(vhdlParser::NEW, 0);
}

vhdlParser::Qualified_expressionContext* vhdlParser::AllocatorContext::qualified_expression() {
  return getRuleContext<vhdlParser::Qualified_expressionContext>(0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::AllocatorContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::AllocatorContext::getRuleIndex() const {
  return vhdlParser::RuleAllocator;
}

antlrcpp::Any vhdlParser::AllocatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAllocator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::AllocatorContext* vhdlParser::allocator() {
  AllocatorContext *_localctx = _tracker.createInstance<AllocatorContext>(_ctx, getState());
  enterRule(_localctx, 22, vhdlParser::RuleAllocator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(614);
    match(vhdlParser::NEW);
    setState(617);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(615);
      qualified_expression();
      break;
    }

    case 2: {
      setState(616);
      subtype_indication();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Architecture_bodyContext ------------------------------------------------------------------

vhdlParser::Architecture_bodyContext::Architecture_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Architecture_bodyContext::ARCHITECTURE() {
  return getTokens(vhdlParser::ARCHITECTURE);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::ARCHITECTURE(size_t i) {
  return getToken(vhdlParser::ARCHITECTURE, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Architecture_bodyContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Architecture_bodyContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::OF() {
  return getToken(vhdlParser::OF, 0);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::Architecture_declarative_partContext* vhdlParser::Architecture_bodyContext::architecture_declarative_part() {
  return getRuleContext<vhdlParser::Architecture_declarative_partContext>(0);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::BEGIN() {
  return getToken(vhdlParser::BEGIN, 0);
}

vhdlParser::Architecture_statement_partContext* vhdlParser::Architecture_bodyContext::architecture_statement_part() {
  return getRuleContext<vhdlParser::Architecture_statement_partContext>(0);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Architecture_bodyContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Architecture_bodyContext::getRuleIndex() const {
  return vhdlParser::RuleArchitecture_body;
}

antlrcpp::Any vhdlParser::Architecture_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitArchitecture_body(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Architecture_bodyContext* vhdlParser::architecture_body() {
  Architecture_bodyContext *_localctx = _tracker.createInstance<Architecture_bodyContext>(_ctx, getState());
  enterRule(_localctx, 24, vhdlParser::RuleArchitecture_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(619);
    match(vhdlParser::ARCHITECTURE);
    setState(620);
    identifier();
    setState(621);
    match(vhdlParser::OF);
    setState(622);
    identifier();
    setState(623);
    match(vhdlParser::IS);
    setState(624);
    architecture_declarative_part();
    setState(625);
    match(vhdlParser::BEGIN);
    setState(626);
    architecture_statement_part();
    setState(627);
    match(vhdlParser::END);
    setState(629);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::ARCHITECTURE) {
      setState(628);
      match(vhdlParser::ARCHITECTURE);
    }
    setState(632);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(631);
      identifier();
    }
    setState(634);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Architecture_declarative_partContext ------------------------------------------------------------------

vhdlParser::Architecture_declarative_partContext::Architecture_declarative_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Block_declarative_itemContext *> vhdlParser::Architecture_declarative_partContext::block_declarative_item() {
  return getRuleContexts<vhdlParser::Block_declarative_itemContext>();
}

vhdlParser::Block_declarative_itemContext* vhdlParser::Architecture_declarative_partContext::block_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Block_declarative_itemContext>(i);
}


size_t vhdlParser::Architecture_declarative_partContext::getRuleIndex() const {
  return vhdlParser::RuleArchitecture_declarative_part;
}

antlrcpp::Any vhdlParser::Architecture_declarative_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitArchitecture_declarative_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Architecture_declarative_partContext* vhdlParser::architecture_declarative_part() {
  Architecture_declarative_partContext *_localctx = _tracker.createInstance<Architecture_declarative_partContext>(_ctx, getState());
  enterRule(_localctx, 26, vhdlParser::RuleArchitecture_declarative_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(639);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ALIAS)
      | (1ULL << vhdlParser::ATTRIBUTE)
      | (1ULL << vhdlParser::COMPONENT)
      | (1ULL << vhdlParser::CONSTANT)
      | (1ULL << vhdlParser::DISCONNECT)
      | (1ULL << vhdlParser::FILE)
      | (1ULL << vhdlParser::FOR)
      | (1ULL << vhdlParser::FUNCTION)
      | (1ULL << vhdlParser::GROUP)
      | (1ULL << vhdlParser::IMPURE)
      | (1ULL << vhdlParser::LIMIT)
      | (1ULL << vhdlParser::NATURE))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (vhdlParser::PROCEDURE - 69))
      | (1ULL << (vhdlParser::PURE - 69))
      | (1ULL << (vhdlParser::QUANTITY - 69))
      | (1ULL << (vhdlParser::SHARED - 69))
      | (1ULL << (vhdlParser::SIGNAL - 69))
      | (1ULL << (vhdlParser::SUBNATURE - 69))
      | (1ULL << (vhdlParser::SUBTYPE - 69))
      | (1ULL << (vhdlParser::TERMINAL - 69))
      | (1ULL << (vhdlParser::TYPE - 69))
      | (1ULL << (vhdlParser::USE - 69))
      | (1ULL << (vhdlParser::VARIABLE - 69)))) != 0)) {
      setState(636);
      block_declarative_item();
      setState(641);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Architecture_statementContext ------------------------------------------------------------------

vhdlParser::Architecture_statementContext::Architecture_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Block_statementContext* vhdlParser::Architecture_statementContext::block_statement() {
  return getRuleContext<vhdlParser::Block_statementContext>(0);
}

vhdlParser::Process_statementContext* vhdlParser::Architecture_statementContext::process_statement() {
  return getRuleContext<vhdlParser::Process_statementContext>(0);
}

vhdlParser::Concurrent_procedure_call_statementContext* vhdlParser::Architecture_statementContext::concurrent_procedure_call_statement() {
  return getRuleContext<vhdlParser::Concurrent_procedure_call_statementContext>(0);
}

vhdlParser::Label_colonContext* vhdlParser::Architecture_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::Concurrent_assertion_statementContext* vhdlParser::Architecture_statementContext::concurrent_assertion_statement() {
  return getRuleContext<vhdlParser::Concurrent_assertion_statementContext>(0);
}

vhdlParser::Concurrent_signal_assignment_statementContext* vhdlParser::Architecture_statementContext::concurrent_signal_assignment_statement() {
  return getRuleContext<vhdlParser::Concurrent_signal_assignment_statementContext>(0);
}

tree::TerminalNode* vhdlParser::Architecture_statementContext::POSTPONED() {
  return getToken(vhdlParser::POSTPONED, 0);
}

vhdlParser::Component_instantiation_statementContext* vhdlParser::Architecture_statementContext::component_instantiation_statement() {
  return getRuleContext<vhdlParser::Component_instantiation_statementContext>(0);
}

vhdlParser::Generate_statementContext* vhdlParser::Architecture_statementContext::generate_statement() {
  return getRuleContext<vhdlParser::Generate_statementContext>(0);
}

vhdlParser::Concurrent_break_statementContext* vhdlParser::Architecture_statementContext::concurrent_break_statement() {
  return getRuleContext<vhdlParser::Concurrent_break_statementContext>(0);
}

vhdlParser::Simultaneous_statementContext* vhdlParser::Architecture_statementContext::simultaneous_statement() {
  return getRuleContext<vhdlParser::Simultaneous_statementContext>(0);
}


size_t vhdlParser::Architecture_statementContext::getRuleIndex() const {
  return vhdlParser::RuleArchitecture_statement;
}

antlrcpp::Any vhdlParser::Architecture_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitArchitecture_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Architecture_statementContext* vhdlParser::architecture_statement() {
  Architecture_statementContext *_localctx = _tracker.createInstance<Architecture_statementContext>(_ctx, getState());
  enterRule(_localctx, 28, vhdlParser::RuleArchitecture_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(663);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(642);
      block_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(643);
      process_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(645);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
      case 1: {
        setState(644);
        label_colon();
        break;
      }

      }
      setState(647);
      concurrent_procedure_call_statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(649);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
      case 1: {
        setState(648);
        label_colon();
        break;
      }

      }
      setState(651);
      concurrent_assertion_statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(653);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
      case 1: {
        setState(652);
        label_colon();
        break;
      }

      }
      setState(656);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(655);
        match(vhdlParser::POSTPONED);
        break;
      }

      }
      setState(658);
      concurrent_signal_assignment_statement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(659);
      component_instantiation_statement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(660);
      generate_statement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(661);
      concurrent_break_statement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(662);
      simultaneous_statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Architecture_statement_partContext ------------------------------------------------------------------

vhdlParser::Architecture_statement_partContext::Architecture_statement_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Architecture_statementContext *> vhdlParser::Architecture_statement_partContext::architecture_statement() {
  return getRuleContexts<vhdlParser::Architecture_statementContext>();
}

vhdlParser::Architecture_statementContext* vhdlParser::Architecture_statement_partContext::architecture_statement(size_t i) {
  return getRuleContext<vhdlParser::Architecture_statementContext>(i);
}


size_t vhdlParser::Architecture_statement_partContext::getRuleIndex() const {
  return vhdlParser::RuleArchitecture_statement_part;
}

antlrcpp::Any vhdlParser::Architecture_statement_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitArchitecture_statement_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Architecture_statement_partContext* vhdlParser::architecture_statement_part() {
  Architecture_statement_partContext *_localctx = _tracker.createInstance<Architecture_statement_partContext>(_ctx, getState());
  enterRule(_localctx, 30, vhdlParser::RuleArchitecture_statement_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(668);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ABS)
      | (1ULL << vhdlParser::ASSERT)
      | (1ULL << vhdlParser::BREAK)
      | (1ULL << vhdlParser::CASE)
      | (1ULL << vhdlParser::IF)
      | (1ULL << vhdlParser::NEW)
      | (1ULL << vhdlParser::NOT)
      | (1ULL << vhdlParser::NULL_SYM))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (vhdlParser::POSTPONED - 67))
      | (1ULL << (vhdlParser::PROCESS - 67))
      | (1ULL << (vhdlParser::PROCEDURAL - 67))
      | (1ULL << (vhdlParser::WITH - 67))
      | (1ULL << (vhdlParser::BASE_LITERAL - 67))
      | (1ULL << (vhdlParser::BIT_STRING_LITERAL - 67))
      | (1ULL << (vhdlParser::REAL_LITERAL - 67))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 67))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 67)))) != 0) || ((((_la - 131) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 131)) & ((1ULL << (vhdlParser::CHARACTER_LITERAL - 131))
      | (1ULL << (vhdlParser::STRING_LITERAL - 131))
      | (1ULL << (vhdlParser::LPAREN - 131))
      | (1ULL << (vhdlParser::PLUS - 131))
      | (1ULL << (vhdlParser::MINUS - 131))
      | (1ULL << (vhdlParser::INTEGER - 131)))) != 0)) {
      setState(665);
      architecture_statement();
      setState(670);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_nature_definitionContext ------------------------------------------------------------------

vhdlParser::Array_nature_definitionContext::Array_nature_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Unconstrained_nature_definitionContext* vhdlParser::Array_nature_definitionContext::unconstrained_nature_definition() {
  return getRuleContext<vhdlParser::Unconstrained_nature_definitionContext>(0);
}

vhdlParser::Constrained_nature_definitionContext* vhdlParser::Array_nature_definitionContext::constrained_nature_definition() {
  return getRuleContext<vhdlParser::Constrained_nature_definitionContext>(0);
}


size_t vhdlParser::Array_nature_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleArray_nature_definition;
}

antlrcpp::Any vhdlParser::Array_nature_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitArray_nature_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Array_nature_definitionContext* vhdlParser::array_nature_definition() {
  Array_nature_definitionContext *_localctx = _tracker.createInstance<Array_nature_definitionContext>(_ctx, getState());
  enterRule(_localctx, 32, vhdlParser::RuleArray_nature_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(673);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(671);
      unconstrained_nature_definition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(672);
      constrained_nature_definition();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_type_definitionContext ------------------------------------------------------------------

vhdlParser::Array_type_definitionContext::Array_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Unconstrained_array_definitionContext* vhdlParser::Array_type_definitionContext::unconstrained_array_definition() {
  return getRuleContext<vhdlParser::Unconstrained_array_definitionContext>(0);
}

vhdlParser::Constrained_array_definitionContext* vhdlParser::Array_type_definitionContext::constrained_array_definition() {
  return getRuleContext<vhdlParser::Constrained_array_definitionContext>(0);
}


size_t vhdlParser::Array_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleArray_type_definition;
}

antlrcpp::Any vhdlParser::Array_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitArray_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Array_type_definitionContext* vhdlParser::array_type_definition() {
  Array_type_definitionContext *_localctx = _tracker.createInstance<Array_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 34, vhdlParser::RuleArray_type_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(677);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(675);
      unconstrained_array_definition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(676);
      constrained_array_definition();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssertionContext ------------------------------------------------------------------

vhdlParser::AssertionContext::AssertionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::AssertionContext::ASSERT() {
  return getToken(vhdlParser::ASSERT, 0);
}

vhdlParser::ConditionContext* vhdlParser::AssertionContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}

tree::TerminalNode* vhdlParser::AssertionContext::REPORT() {
  return getToken(vhdlParser::REPORT, 0);
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::AssertionContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::AssertionContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

tree::TerminalNode* vhdlParser::AssertionContext::SEVERITY() {
  return getToken(vhdlParser::SEVERITY, 0);
}


size_t vhdlParser::AssertionContext::getRuleIndex() const {
  return vhdlParser::RuleAssertion;
}

antlrcpp::Any vhdlParser::AssertionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAssertion(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::AssertionContext* vhdlParser::assertion() {
  AssertionContext *_localctx = _tracker.createInstance<AssertionContext>(_ctx, getState());
  enterRule(_localctx, 36, vhdlParser::RuleAssertion);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(679);
    match(vhdlParser::ASSERT);
    setState(680);
    condition();
    setState(683);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::REPORT) {
      setState(681);
      match(vhdlParser::REPORT);
      setState(682);
      expression();
    }
    setState(687);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::SEVERITY) {
      setState(685);
      match(vhdlParser::SEVERITY);
      setState(686);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assertion_statementContext ------------------------------------------------------------------

vhdlParser::Assertion_statementContext::Assertion_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::AssertionContext* vhdlParser::Assertion_statementContext::assertion() {
  return getRuleContext<vhdlParser::AssertionContext>(0);
}

tree::TerminalNode* vhdlParser::Assertion_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Assertion_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}


size_t vhdlParser::Assertion_statementContext::getRuleIndex() const {
  return vhdlParser::RuleAssertion_statement;
}

antlrcpp::Any vhdlParser::Assertion_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAssertion_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Assertion_statementContext* vhdlParser::assertion_statement() {
  Assertion_statementContext *_localctx = _tracker.createInstance<Assertion_statementContext>(_ctx, getState());
  enterRule(_localctx, 38, vhdlParser::RuleAssertion_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(690);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(689);
      label_colon();
    }
    setState(692);
    assertion();
    setState(693);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Association_elementContext ------------------------------------------------------------------

vhdlParser::Association_elementContext::Association_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Actual_partContext* vhdlParser::Association_elementContext::actual_part() {
  return getRuleContext<vhdlParser::Actual_partContext>(0);
}

vhdlParser::Formal_partContext* vhdlParser::Association_elementContext::formal_part() {
  return getRuleContext<vhdlParser::Formal_partContext>(0);
}

tree::TerminalNode* vhdlParser::Association_elementContext::ARROW() {
  return getToken(vhdlParser::ARROW, 0);
}


size_t vhdlParser::Association_elementContext::getRuleIndex() const {
  return vhdlParser::RuleAssociation_element;
}

antlrcpp::Any vhdlParser::Association_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAssociation_element(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Association_elementContext* vhdlParser::association_element() {
  Association_elementContext *_localctx = _tracker.createInstance<Association_elementContext>(_ctx, getState());
  enterRule(_localctx, 40, vhdlParser::RuleAssociation_element);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(698);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(695);
      formal_part();
      setState(696);
      match(vhdlParser::ARROW);
      break;
    }

    }
    setState(700);
    actual_part();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Association_listContext ------------------------------------------------------------------

vhdlParser::Association_listContext::Association_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Association_elementContext *> vhdlParser::Association_listContext::association_element() {
  return getRuleContexts<vhdlParser::Association_elementContext>();
}

vhdlParser::Association_elementContext* vhdlParser::Association_listContext::association_element(size_t i) {
  return getRuleContext<vhdlParser::Association_elementContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Association_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Association_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Association_listContext::getRuleIndex() const {
  return vhdlParser::RuleAssociation_list;
}

antlrcpp::Any vhdlParser::Association_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAssociation_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Association_listContext* vhdlParser::association_list() {
  Association_listContext *_localctx = _tracker.createInstance<Association_listContext>(_ctx, getState());
  enterRule(_localctx, 42, vhdlParser::RuleAssociation_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(702);
    association_element();
    setState(707);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(703);
      match(vhdlParser::COMMA);
      setState(704);
      association_element();
      setState(709);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attribute_declarationContext ------------------------------------------------------------------

vhdlParser::Attribute_declarationContext::Attribute_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Attribute_declarationContext::ATTRIBUTE() {
  return getToken(vhdlParser::ATTRIBUTE, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Attribute_declarationContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::NameContext* vhdlParser::Attribute_declarationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Attribute_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Attribute_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleAttribute_declaration;
}

antlrcpp::Any vhdlParser::Attribute_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAttribute_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Attribute_declarationContext* vhdlParser::attribute_declaration() {
  Attribute_declarationContext *_localctx = _tracker.createInstance<Attribute_declarationContext>(_ctx, getState());
  enterRule(_localctx, 44, vhdlParser::RuleAttribute_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(710);
    match(vhdlParser::ATTRIBUTE);
    setState(711);
    label_colon();
    setState(712);
    name();
    setState(713);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attribute_designatorContext ------------------------------------------------------------------

vhdlParser::Attribute_designatorContext::Attribute_designatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Attribute_designatorContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Attribute_designatorContext::RANGE() {
  return getToken(vhdlParser::RANGE, 0);
}

tree::TerminalNode* vhdlParser::Attribute_designatorContext::REVERSE_RANGE() {
  return getToken(vhdlParser::REVERSE_RANGE, 0);
}

tree::TerminalNode* vhdlParser::Attribute_designatorContext::ACROSS() {
  return getToken(vhdlParser::ACROSS, 0);
}

tree::TerminalNode* vhdlParser::Attribute_designatorContext::THROUGH() {
  return getToken(vhdlParser::THROUGH, 0);
}

tree::TerminalNode* vhdlParser::Attribute_designatorContext::REFERENCE() {
  return getToken(vhdlParser::REFERENCE, 0);
}

tree::TerminalNode* vhdlParser::Attribute_designatorContext::TOLERANCE() {
  return getToken(vhdlParser::TOLERANCE, 0);
}


size_t vhdlParser::Attribute_designatorContext::getRuleIndex() const {
  return vhdlParser::RuleAttribute_designator;
}

antlrcpp::Any vhdlParser::Attribute_designatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAttribute_designator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Attribute_designatorContext* vhdlParser::attribute_designator() {
  Attribute_designatorContext *_localctx = _tracker.createInstance<Attribute_designatorContext>(_ctx, getState());
  enterRule(_localctx, 46, vhdlParser::RuleAttribute_designator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(722);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(715);
        identifier();
        break;
      }

      case vhdlParser::RANGE: {
        enterOuterAlt(_localctx, 2);
        setState(716);
        match(vhdlParser::RANGE);
        break;
      }

      case vhdlParser::REVERSE_RANGE: {
        enterOuterAlt(_localctx, 3);
        setState(717);
        match(vhdlParser::REVERSE_RANGE);
        break;
      }

      case vhdlParser::ACROSS: {
        enterOuterAlt(_localctx, 4);
        setState(718);
        match(vhdlParser::ACROSS);
        break;
      }

      case vhdlParser::THROUGH: {
        enterOuterAlt(_localctx, 5);
        setState(719);
        match(vhdlParser::THROUGH);
        break;
      }

      case vhdlParser::REFERENCE: {
        enterOuterAlt(_localctx, 6);
        setState(720);
        match(vhdlParser::REFERENCE);
        break;
      }

      case vhdlParser::TOLERANCE: {
        enterOuterAlt(_localctx, 7);
        setState(721);
        match(vhdlParser::TOLERANCE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attribute_specificationContext ------------------------------------------------------------------

vhdlParser::Attribute_specificationContext::Attribute_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Attribute_specificationContext::ATTRIBUTE() {
  return getToken(vhdlParser::ATTRIBUTE, 0);
}

vhdlParser::Attribute_designatorContext* vhdlParser::Attribute_specificationContext::attribute_designator() {
  return getRuleContext<vhdlParser::Attribute_designatorContext>(0);
}

tree::TerminalNode* vhdlParser::Attribute_specificationContext::OF() {
  return getToken(vhdlParser::OF, 0);
}

vhdlParser::Entity_specificationContext* vhdlParser::Attribute_specificationContext::entity_specification() {
  return getRuleContext<vhdlParser::Entity_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Attribute_specificationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Attribute_specificationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Attribute_specificationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Attribute_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleAttribute_specification;
}

antlrcpp::Any vhdlParser::Attribute_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitAttribute_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Attribute_specificationContext* vhdlParser::attribute_specification() {
  Attribute_specificationContext *_localctx = _tracker.createInstance<Attribute_specificationContext>(_ctx, getState());
  enterRule(_localctx, 48, vhdlParser::RuleAttribute_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(724);
    match(vhdlParser::ATTRIBUTE);
    setState(725);
    attribute_designator();
    setState(726);
    match(vhdlParser::OF);
    setState(727);
    entity_specification();
    setState(728);
    match(vhdlParser::IS);
    setState(729);
    expression();
    setState(730);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Base_unit_declarationContext ------------------------------------------------------------------

vhdlParser::Base_unit_declarationContext::Base_unit_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Base_unit_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Base_unit_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Base_unit_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleBase_unit_declaration;
}

antlrcpp::Any vhdlParser::Base_unit_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBase_unit_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Base_unit_declarationContext* vhdlParser::base_unit_declaration() {
  Base_unit_declarationContext *_localctx = _tracker.createInstance<Base_unit_declarationContext>(_ctx, getState());
  enterRule(_localctx, 50, vhdlParser::RuleBase_unit_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(732);
    identifier();
    setState(733);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binding_indicationContext ------------------------------------------------------------------

vhdlParser::Binding_indicationContext::Binding_indicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Binding_indicationContext::USE() {
  return getToken(vhdlParser::USE, 0);
}

vhdlParser::Entity_aspectContext* vhdlParser::Binding_indicationContext::entity_aspect() {
  return getRuleContext<vhdlParser::Entity_aspectContext>(0);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::Binding_indicationContext::generic_map_aspect() {
  return getRuleContext<vhdlParser::Generic_map_aspectContext>(0);
}

vhdlParser::Port_map_aspectContext* vhdlParser::Binding_indicationContext::port_map_aspect() {
  return getRuleContext<vhdlParser::Port_map_aspectContext>(0);
}


size_t vhdlParser::Binding_indicationContext::getRuleIndex() const {
  return vhdlParser::RuleBinding_indication;
}

antlrcpp::Any vhdlParser::Binding_indicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBinding_indication(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Binding_indicationContext* vhdlParser::binding_indication() {
  Binding_indicationContext *_localctx = _tracker.createInstance<Binding_indicationContext>(_ctx, getState());
  enterRule(_localctx, 52, vhdlParser::RuleBinding_indication);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(737);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::USE) {
      setState(735);
      match(vhdlParser::USE);
      setState(736);
      entity_aspect();
    }
    setState(740);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::GENERIC) {
      setState(739);
      generic_map_aspect();
    }
    setState(743);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::PORT) {
      setState(742);
      port_map_aspect();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_configurationContext ------------------------------------------------------------------

vhdlParser::Block_configurationContext::Block_configurationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Block_configurationContext::FOR() {
  return getTokens(vhdlParser::FOR);
}

tree::TerminalNode* vhdlParser::Block_configurationContext::FOR(size_t i) {
  return getToken(vhdlParser::FOR, i);
}

vhdlParser::Block_specificationContext* vhdlParser::Block_configurationContext::block_specification() {
  return getRuleContext<vhdlParser::Block_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Block_configurationContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Block_configurationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<vhdlParser::Use_clauseContext *> vhdlParser::Block_configurationContext::use_clause() {
  return getRuleContexts<vhdlParser::Use_clauseContext>();
}

vhdlParser::Use_clauseContext* vhdlParser::Block_configurationContext::use_clause(size_t i) {
  return getRuleContext<vhdlParser::Use_clauseContext>(i);
}

std::vector<vhdlParser::Configuration_itemContext *> vhdlParser::Block_configurationContext::configuration_item() {
  return getRuleContexts<vhdlParser::Configuration_itemContext>();
}

vhdlParser::Configuration_itemContext* vhdlParser::Block_configurationContext::configuration_item(size_t i) {
  return getRuleContext<vhdlParser::Configuration_itemContext>(i);
}


size_t vhdlParser::Block_configurationContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_configuration;
}

antlrcpp::Any vhdlParser::Block_configurationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBlock_configuration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_configurationContext* vhdlParser::block_configuration() {
  Block_configurationContext *_localctx = _tracker.createInstance<Block_configurationContext>(_ctx, getState());
  enterRule(_localctx, 54, vhdlParser::RuleBlock_configuration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(745);
    match(vhdlParser::FOR);
    setState(746);
    block_specification();
    setState(750);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::USE) {
      setState(747);
      use_clause();
      setState(752);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(756);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::FOR) {
      setState(753);
      configuration_item();
      setState(758);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(759);
    match(vhdlParser::END);
    setState(760);
    match(vhdlParser::FOR);
    setState(761);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Block_declarative_itemContext::Block_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_declarationContext* vhdlParser::Block_declarative_itemContext::subprogram_declaration() {
  return getRuleContext<vhdlParser::Subprogram_declarationContext>(0);
}

vhdlParser::Subprogram_bodyContext* vhdlParser::Block_declarative_itemContext::subprogram_body() {
  return getRuleContext<vhdlParser::Subprogram_bodyContext>(0);
}

vhdlParser::Type_declarationContext* vhdlParser::Block_declarative_itemContext::type_declaration() {
  return getRuleContext<vhdlParser::Type_declarationContext>(0);
}

vhdlParser::Subtype_declarationContext* vhdlParser::Block_declarative_itemContext::subtype_declaration() {
  return getRuleContext<vhdlParser::Subtype_declarationContext>(0);
}

vhdlParser::Constant_declarationContext* vhdlParser::Block_declarative_itemContext::constant_declaration() {
  return getRuleContext<vhdlParser::Constant_declarationContext>(0);
}

vhdlParser::Signal_declarationContext* vhdlParser::Block_declarative_itemContext::signal_declaration() {
  return getRuleContext<vhdlParser::Signal_declarationContext>(0);
}

vhdlParser::Variable_declarationContext* vhdlParser::Block_declarative_itemContext::variable_declaration() {
  return getRuleContext<vhdlParser::Variable_declarationContext>(0);
}

vhdlParser::File_declarationContext* vhdlParser::Block_declarative_itemContext::file_declaration() {
  return getRuleContext<vhdlParser::File_declarationContext>(0);
}

vhdlParser::Alias_declarationContext* vhdlParser::Block_declarative_itemContext::alias_declaration() {
  return getRuleContext<vhdlParser::Alias_declarationContext>(0);
}

vhdlParser::Component_declarationContext* vhdlParser::Block_declarative_itemContext::component_declaration() {
  return getRuleContext<vhdlParser::Component_declarationContext>(0);
}

vhdlParser::Attribute_declarationContext* vhdlParser::Block_declarative_itemContext::attribute_declaration() {
  return getRuleContext<vhdlParser::Attribute_declarationContext>(0);
}

vhdlParser::Attribute_specificationContext* vhdlParser::Block_declarative_itemContext::attribute_specification() {
  return getRuleContext<vhdlParser::Attribute_specificationContext>(0);
}

vhdlParser::Configuration_specificationContext* vhdlParser::Block_declarative_itemContext::configuration_specification() {
  return getRuleContext<vhdlParser::Configuration_specificationContext>(0);
}

vhdlParser::Disconnection_specificationContext* vhdlParser::Block_declarative_itemContext::disconnection_specification() {
  return getRuleContext<vhdlParser::Disconnection_specificationContext>(0);
}

vhdlParser::Step_limit_specificationContext* vhdlParser::Block_declarative_itemContext::step_limit_specification() {
  return getRuleContext<vhdlParser::Step_limit_specificationContext>(0);
}

vhdlParser::Use_clauseContext* vhdlParser::Block_declarative_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}

vhdlParser::Group_template_declarationContext* vhdlParser::Block_declarative_itemContext::group_template_declaration() {
  return getRuleContext<vhdlParser::Group_template_declarationContext>(0);
}

vhdlParser::Group_declarationContext* vhdlParser::Block_declarative_itemContext::group_declaration() {
  return getRuleContext<vhdlParser::Group_declarationContext>(0);
}

vhdlParser::Nature_declarationContext* vhdlParser::Block_declarative_itemContext::nature_declaration() {
  return getRuleContext<vhdlParser::Nature_declarationContext>(0);
}

vhdlParser::Subnature_declarationContext* vhdlParser::Block_declarative_itemContext::subnature_declaration() {
  return getRuleContext<vhdlParser::Subnature_declarationContext>(0);
}

vhdlParser::Quantity_declarationContext* vhdlParser::Block_declarative_itemContext::quantity_declaration() {
  return getRuleContext<vhdlParser::Quantity_declarationContext>(0);
}

vhdlParser::Terminal_declarationContext* vhdlParser::Block_declarative_itemContext::terminal_declaration() {
  return getRuleContext<vhdlParser::Terminal_declarationContext>(0);
}


size_t vhdlParser::Block_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_declarative_item;
}

antlrcpp::Any vhdlParser::Block_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBlock_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_declarative_itemContext* vhdlParser::block_declarative_item() {
  Block_declarative_itemContext *_localctx = _tracker.createInstance<Block_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 56, vhdlParser::RuleBlock_declarative_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(785);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(763);
      subprogram_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(764);
      subprogram_body();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(765);
      type_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(766);
      subtype_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(767);
      constant_declaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(768);
      signal_declaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(769);
      variable_declaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(770);
      file_declaration();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(771);
      alias_declaration();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(772);
      component_declaration();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(773);
      attribute_declaration();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(774);
      attribute_specification();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(775);
      configuration_specification();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(776);
      disconnection_specification();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(777);
      step_limit_specification();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(778);
      use_clause();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(779);
      group_template_declaration();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(780);
      group_declaration();
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(781);
      nature_declaration();
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(782);
      subnature_declaration();
      break;
    }

    case 21: {
      enterOuterAlt(_localctx, 21);
      setState(783);
      quantity_declaration();
      break;
    }

    case 22: {
      enterOuterAlt(_localctx, 22);
      setState(784);
      terminal_declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_declarative_partContext ------------------------------------------------------------------

vhdlParser::Block_declarative_partContext::Block_declarative_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Block_declarative_itemContext *> vhdlParser::Block_declarative_partContext::block_declarative_item() {
  return getRuleContexts<vhdlParser::Block_declarative_itemContext>();
}

vhdlParser::Block_declarative_itemContext* vhdlParser::Block_declarative_partContext::block_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Block_declarative_itemContext>(i);
}


size_t vhdlParser::Block_declarative_partContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_declarative_part;
}

antlrcpp::Any vhdlParser::Block_declarative_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBlock_declarative_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_declarative_partContext* vhdlParser::block_declarative_part() {
  Block_declarative_partContext *_localctx = _tracker.createInstance<Block_declarative_partContext>(_ctx, getState());
  enterRule(_localctx, 58, vhdlParser::RuleBlock_declarative_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(790);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ALIAS)
      | (1ULL << vhdlParser::ATTRIBUTE)
      | (1ULL << vhdlParser::COMPONENT)
      | (1ULL << vhdlParser::CONSTANT)
      | (1ULL << vhdlParser::DISCONNECT)
      | (1ULL << vhdlParser::FILE)
      | (1ULL << vhdlParser::FOR)
      | (1ULL << vhdlParser::FUNCTION)
      | (1ULL << vhdlParser::GROUP)
      | (1ULL << vhdlParser::IMPURE)
      | (1ULL << vhdlParser::LIMIT)
      | (1ULL << vhdlParser::NATURE))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (vhdlParser::PROCEDURE - 69))
      | (1ULL << (vhdlParser::PURE - 69))
      | (1ULL << (vhdlParser::QUANTITY - 69))
      | (1ULL << (vhdlParser::SHARED - 69))
      | (1ULL << (vhdlParser::SIGNAL - 69))
      | (1ULL << (vhdlParser::SUBNATURE - 69))
      | (1ULL << (vhdlParser::SUBTYPE - 69))
      | (1ULL << (vhdlParser::TERMINAL - 69))
      | (1ULL << (vhdlParser::TYPE - 69))
      | (1ULL << (vhdlParser::USE - 69))
      | (1ULL << (vhdlParser::VARIABLE - 69)))) != 0)) {
      setState(787);
      block_declarative_item();
      setState(792);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_headerContext ------------------------------------------------------------------

vhdlParser::Block_headerContext::Block_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Generic_clauseContext* vhdlParser::Block_headerContext::generic_clause() {
  return getRuleContext<vhdlParser::Generic_clauseContext>(0);
}

vhdlParser::Port_clauseContext* vhdlParser::Block_headerContext::port_clause() {
  return getRuleContext<vhdlParser::Port_clauseContext>(0);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::Block_headerContext::generic_map_aspect() {
  return getRuleContext<vhdlParser::Generic_map_aspectContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Block_headerContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Block_headerContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}

vhdlParser::Port_map_aspectContext* vhdlParser::Block_headerContext::port_map_aspect() {
  return getRuleContext<vhdlParser::Port_map_aspectContext>(0);
}


size_t vhdlParser::Block_headerContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_header;
}

antlrcpp::Any vhdlParser::Block_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBlock_header(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_headerContext* vhdlParser::block_header() {
  Block_headerContext *_localctx = _tracker.createInstance<Block_headerContext>(_ctx, getState());
  enterRule(_localctx, 60, vhdlParser::RuleBlock_header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(799);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::GENERIC) {
      setState(793);
      generic_clause();
      setState(797);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::GENERIC) {
        setState(794);
        generic_map_aspect();
        setState(795);
        match(vhdlParser::SEMI);
      }
    }
    setState(807);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::PORT) {
      setState(801);
      port_clause();
      setState(805);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::PORT) {
        setState(802);
        port_map_aspect();
        setState(803);
        match(vhdlParser::SEMI);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_specificationContext ------------------------------------------------------------------

vhdlParser::Block_specificationContext::Block_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Block_specificationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Block_specificationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Index_specificationContext* vhdlParser::Block_specificationContext::index_specification() {
  return getRuleContext<vhdlParser::Index_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Block_specificationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

vhdlParser::NameContext* vhdlParser::Block_specificationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}


size_t vhdlParser::Block_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_specification;
}

antlrcpp::Any vhdlParser::Block_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBlock_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_specificationContext* vhdlParser::block_specification() {
  Block_specificationContext *_localctx = _tracker.createInstance<Block_specificationContext>(_ctx, getState());
  enterRule(_localctx, 62, vhdlParser::RuleBlock_specification);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(817);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(809);
      identifier();
      setState(814);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::LPAREN) {
        setState(810);
        match(vhdlParser::LPAREN);
        setState(811);
        index_specification();
        setState(812);
        match(vhdlParser::RPAREN);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(816);
      name();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_statementContext ------------------------------------------------------------------

vhdlParser::Block_statementContext::Block_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Label_colonContext* vhdlParser::Block_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Block_statementContext::BLOCK() {
  return getTokens(vhdlParser::BLOCK);
}

tree::TerminalNode* vhdlParser::Block_statementContext::BLOCK(size_t i) {
  return getToken(vhdlParser::BLOCK, i);
}

vhdlParser::Block_headerContext* vhdlParser::Block_statementContext::block_header() {
  return getRuleContext<vhdlParser::Block_headerContext>(0);
}

vhdlParser::Block_declarative_partContext* vhdlParser::Block_statementContext::block_declarative_part() {
  return getRuleContext<vhdlParser::Block_declarative_partContext>(0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::BEGIN() {
  return getToken(vhdlParser::BEGIN, 0);
}

vhdlParser::Block_statement_partContext* vhdlParser::Block_statementContext::block_statement_part() {
  return getRuleContext<vhdlParser::Block_statement_partContext>(0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Block_statementContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Block_statementContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Block_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Block_statementContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_statement;
}

antlrcpp::Any vhdlParser::Block_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBlock_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_statementContext* vhdlParser::block_statement() {
  Block_statementContext *_localctx = _tracker.createInstance<Block_statementContext>(_ctx, getState());
  enterRule(_localctx, 64, vhdlParser::RuleBlock_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(819);
    label_colon();
    setState(820);
    match(vhdlParser::BLOCK);
    setState(825);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LPAREN) {
      setState(821);
      match(vhdlParser::LPAREN);
      setState(822);
      expression();
      setState(823);
      match(vhdlParser::RPAREN);
    }
    setState(828);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IS) {
      setState(827);
      match(vhdlParser::IS);
    }
    setState(830);
    block_header();
    setState(831);
    block_declarative_part();
    setState(832);
    match(vhdlParser::BEGIN);
    setState(833);
    block_statement_part();
    setState(834);
    match(vhdlParser::END);
    setState(835);
    match(vhdlParser::BLOCK);
    setState(837);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(836);
      identifier();
    }
    setState(839);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_statement_partContext ------------------------------------------------------------------

vhdlParser::Block_statement_partContext::Block_statement_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Architecture_statementContext *> vhdlParser::Block_statement_partContext::architecture_statement() {
  return getRuleContexts<vhdlParser::Architecture_statementContext>();
}

vhdlParser::Architecture_statementContext* vhdlParser::Block_statement_partContext::architecture_statement(size_t i) {
  return getRuleContext<vhdlParser::Architecture_statementContext>(i);
}


size_t vhdlParser::Block_statement_partContext::getRuleIndex() const {
  return vhdlParser::RuleBlock_statement_part;
}

antlrcpp::Any vhdlParser::Block_statement_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBlock_statement_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Block_statement_partContext* vhdlParser::block_statement_part() {
  Block_statement_partContext *_localctx = _tracker.createInstance<Block_statement_partContext>(_ctx, getState());
  enterRule(_localctx, 66, vhdlParser::RuleBlock_statement_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(844);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ABS)
      | (1ULL << vhdlParser::ASSERT)
      | (1ULL << vhdlParser::BREAK)
      | (1ULL << vhdlParser::CASE)
      | (1ULL << vhdlParser::IF)
      | (1ULL << vhdlParser::NEW)
      | (1ULL << vhdlParser::NOT)
      | (1ULL << vhdlParser::NULL_SYM))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (vhdlParser::POSTPONED - 67))
      | (1ULL << (vhdlParser::PROCESS - 67))
      | (1ULL << (vhdlParser::PROCEDURAL - 67))
      | (1ULL << (vhdlParser::WITH - 67))
      | (1ULL << (vhdlParser::BASE_LITERAL - 67))
      | (1ULL << (vhdlParser::BIT_STRING_LITERAL - 67))
      | (1ULL << (vhdlParser::REAL_LITERAL - 67))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 67))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 67)))) != 0) || ((((_la - 131) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 131)) & ((1ULL << (vhdlParser::CHARACTER_LITERAL - 131))
      | (1ULL << (vhdlParser::STRING_LITERAL - 131))
      | (1ULL << (vhdlParser::LPAREN - 131))
      | (1ULL << (vhdlParser::PLUS - 131))
      | (1ULL << (vhdlParser::MINUS - 131))
      | (1ULL << (vhdlParser::INTEGER - 131)))) != 0)) {
      setState(841);
      architecture_statement();
      setState(846);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Branch_quantity_declarationContext ------------------------------------------------------------------

vhdlParser::Branch_quantity_declarationContext::Branch_quantity_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Branch_quantity_declarationContext::QUANTITY() {
  return getToken(vhdlParser::QUANTITY, 0);
}

vhdlParser::Terminal_aspectContext* vhdlParser::Branch_quantity_declarationContext::terminal_aspect() {
  return getRuleContext<vhdlParser::Terminal_aspectContext>(0);
}

tree::TerminalNode* vhdlParser::Branch_quantity_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Across_aspectContext* vhdlParser::Branch_quantity_declarationContext::across_aspect() {
  return getRuleContext<vhdlParser::Across_aspectContext>(0);
}

vhdlParser::Through_aspectContext* vhdlParser::Branch_quantity_declarationContext::through_aspect() {
  return getRuleContext<vhdlParser::Through_aspectContext>(0);
}


size_t vhdlParser::Branch_quantity_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleBranch_quantity_declaration;
}

antlrcpp::Any vhdlParser::Branch_quantity_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBranch_quantity_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Branch_quantity_declarationContext* vhdlParser::branch_quantity_declaration() {
  Branch_quantity_declarationContext *_localctx = _tracker.createInstance<Branch_quantity_declarationContext>(_ctx, getState());
  enterRule(_localctx, 68, vhdlParser::RuleBranch_quantity_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(847);
    match(vhdlParser::QUANTITY);
    setState(849);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(848);
      across_aspect();
      break;
    }

    }
    setState(852);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      setState(851);
      through_aspect();
      break;
    }

    }
    setState(854);
    terminal_aspect();
    setState(855);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Break_elementContext ------------------------------------------------------------------

vhdlParser::Break_elementContext::Break_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Break_elementContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Break_elementContext::ARROW() {
  return getToken(vhdlParser::ARROW, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Break_elementContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

vhdlParser::Break_selector_clauseContext* vhdlParser::Break_elementContext::break_selector_clause() {
  return getRuleContext<vhdlParser::Break_selector_clauseContext>(0);
}


size_t vhdlParser::Break_elementContext::getRuleIndex() const {
  return vhdlParser::RuleBreak_element;
}

antlrcpp::Any vhdlParser::Break_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBreak_element(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Break_elementContext* vhdlParser::break_element() {
  Break_elementContext *_localctx = _tracker.createInstance<Break_elementContext>(_ctx, getState());
  enterRule(_localctx, 70, vhdlParser::RuleBreak_element);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(858);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::FOR) {
      setState(857);
      break_selector_clause();
    }
    setState(860);
    name();
    setState(861);
    match(vhdlParser::ARROW);
    setState(862);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Break_listContext ------------------------------------------------------------------

vhdlParser::Break_listContext::Break_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Break_elementContext *> vhdlParser::Break_listContext::break_element() {
  return getRuleContexts<vhdlParser::Break_elementContext>();
}

vhdlParser::Break_elementContext* vhdlParser::Break_listContext::break_element(size_t i) {
  return getRuleContext<vhdlParser::Break_elementContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Break_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Break_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Break_listContext::getRuleIndex() const {
  return vhdlParser::RuleBreak_list;
}

antlrcpp::Any vhdlParser::Break_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBreak_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Break_listContext* vhdlParser::break_list() {
  Break_listContext *_localctx = _tracker.createInstance<Break_listContext>(_ctx, getState());
  enterRule(_localctx, 72, vhdlParser::RuleBreak_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(864);
    break_element();
    setState(869);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(865);
      match(vhdlParser::COMMA);
      setState(866);
      break_element();
      setState(871);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Break_selector_clauseContext ------------------------------------------------------------------

vhdlParser::Break_selector_clauseContext::Break_selector_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Break_selector_clauseContext::FOR() {
  return getToken(vhdlParser::FOR, 0);
}

vhdlParser::NameContext* vhdlParser::Break_selector_clauseContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Break_selector_clauseContext::USE() {
  return getToken(vhdlParser::USE, 0);
}


size_t vhdlParser::Break_selector_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleBreak_selector_clause;
}

antlrcpp::Any vhdlParser::Break_selector_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBreak_selector_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Break_selector_clauseContext* vhdlParser::break_selector_clause() {
  Break_selector_clauseContext *_localctx = _tracker.createInstance<Break_selector_clauseContext>(_ctx, getState());
  enterRule(_localctx, 74, vhdlParser::RuleBreak_selector_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(872);
    match(vhdlParser::FOR);
    setState(873);
    name();
    setState(874);
    match(vhdlParser::USE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Break_statementContext ------------------------------------------------------------------

vhdlParser::Break_statementContext::Break_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Break_statementContext::BREAK() {
  return getToken(vhdlParser::BREAK, 0);
}

tree::TerminalNode* vhdlParser::Break_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Break_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::Break_listContext* vhdlParser::Break_statementContext::break_list() {
  return getRuleContext<vhdlParser::Break_listContext>(0);
}

tree::TerminalNode* vhdlParser::Break_statementContext::WHEN() {
  return getToken(vhdlParser::WHEN, 0);
}

vhdlParser::ConditionContext* vhdlParser::Break_statementContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}


size_t vhdlParser::Break_statementContext::getRuleIndex() const {
  return vhdlParser::RuleBreak_statement;
}

antlrcpp::Any vhdlParser::Break_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitBreak_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Break_statementContext* vhdlParser::break_statement() {
  Break_statementContext *_localctx = _tracker.createInstance<Break_statementContext>(_ctx, getState());
  enterRule(_localctx, 76, vhdlParser::RuleBreak_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(877);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(876);
      label_colon();
    }
    setState(879);
    match(vhdlParser::BREAK);
    setState(881);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::FOR || _la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(880);
      break_list();
    }
    setState(885);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::WHEN) {
      setState(883);
      match(vhdlParser::WHEN);
      setState(884);
      condition();
    }
    setState(887);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_statementContext ------------------------------------------------------------------

vhdlParser::Case_statementContext::Case_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Case_statementContext::CASE() {
  return getTokens(vhdlParser::CASE);
}

tree::TerminalNode* vhdlParser::Case_statementContext::CASE(size_t i) {
  return getToken(vhdlParser::CASE, i);
}

vhdlParser::ExpressionContext* vhdlParser::Case_statementContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Case_statementContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

tree::TerminalNode* vhdlParser::Case_statementContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Case_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Case_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

std::vector<vhdlParser::Case_statement_alternativeContext *> vhdlParser::Case_statementContext::case_statement_alternative() {
  return getRuleContexts<vhdlParser::Case_statement_alternativeContext>();
}

vhdlParser::Case_statement_alternativeContext* vhdlParser::Case_statementContext::case_statement_alternative(size_t i) {
  return getRuleContext<vhdlParser::Case_statement_alternativeContext>(i);
}

vhdlParser::IdentifierContext* vhdlParser::Case_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Case_statementContext::getRuleIndex() const {
  return vhdlParser::RuleCase_statement;
}

antlrcpp::Any vhdlParser::Case_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitCase_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Case_statementContext* vhdlParser::case_statement() {
  Case_statementContext *_localctx = _tracker.createInstance<Case_statementContext>(_ctx, getState());
  enterRule(_localctx, 78, vhdlParser::RuleCase_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(890);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(889);
      label_colon();
    }
    setState(892);
    match(vhdlParser::CASE);
    setState(893);
    expression();
    setState(894);
    match(vhdlParser::IS);
    setState(896); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(895);
      case_statement_alternative();
      setState(898); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == vhdlParser::WHEN);
    setState(900);
    match(vhdlParser::END);
    setState(901);
    match(vhdlParser::CASE);
    setState(903);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(902);
      identifier();
    }
    setState(905);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_statement_alternativeContext ------------------------------------------------------------------

vhdlParser::Case_statement_alternativeContext::Case_statement_alternativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Case_statement_alternativeContext::WHEN() {
  return getToken(vhdlParser::WHEN, 0);
}

vhdlParser::ChoicesContext* vhdlParser::Case_statement_alternativeContext::choices() {
  return getRuleContext<vhdlParser::ChoicesContext>(0);
}

tree::TerminalNode* vhdlParser::Case_statement_alternativeContext::ARROW() {
  return getToken(vhdlParser::ARROW, 0);
}

vhdlParser::Sequence_of_statementsContext* vhdlParser::Case_statement_alternativeContext::sequence_of_statements() {
  return getRuleContext<vhdlParser::Sequence_of_statementsContext>(0);
}


size_t vhdlParser::Case_statement_alternativeContext::getRuleIndex() const {
  return vhdlParser::RuleCase_statement_alternative;
}

antlrcpp::Any vhdlParser::Case_statement_alternativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitCase_statement_alternative(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Case_statement_alternativeContext* vhdlParser::case_statement_alternative() {
  Case_statement_alternativeContext *_localctx = _tracker.createInstance<Case_statement_alternativeContext>(_ctx, getState());
  enterRule(_localctx, 80, vhdlParser::RuleCase_statement_alternative);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(907);
    match(vhdlParser::WHEN);
    setState(908);
    choices();
    setState(909);
    match(vhdlParser::ARROW);
    setState(910);
    sequence_of_statements();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChoiceContext ------------------------------------------------------------------

vhdlParser::ChoiceContext::ChoiceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::ChoiceContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

vhdlParser::Discrete_rangeContext* vhdlParser::ChoiceContext::discrete_range() {
  return getRuleContext<vhdlParser::Discrete_rangeContext>(0);
}

vhdlParser::Simple_expressionContext* vhdlParser::ChoiceContext::simple_expression() {
  return getRuleContext<vhdlParser::Simple_expressionContext>(0);
}

tree::TerminalNode* vhdlParser::ChoiceContext::OTHERS() {
  return getToken(vhdlParser::OTHERS, 0);
}


size_t vhdlParser::ChoiceContext::getRuleIndex() const {
  return vhdlParser::RuleChoice;
}

antlrcpp::Any vhdlParser::ChoiceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitChoice(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::ChoiceContext* vhdlParser::choice() {
  ChoiceContext *_localctx = _tracker.createInstance<ChoiceContext>(_ctx, getState());
  enterRule(_localctx, 82, vhdlParser::RuleChoice);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(916);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(912);
      identifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(913);
      discrete_range();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(914);
      simple_expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(915);
      match(vhdlParser::OTHERS);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChoicesContext ------------------------------------------------------------------

vhdlParser::ChoicesContext::ChoicesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::ChoiceContext *> vhdlParser::ChoicesContext::choice() {
  return getRuleContexts<vhdlParser::ChoiceContext>();
}

vhdlParser::ChoiceContext* vhdlParser::ChoicesContext::choice(size_t i) {
  return getRuleContext<vhdlParser::ChoiceContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::ChoicesContext::BAR() {
  return getTokens(vhdlParser::BAR);
}

tree::TerminalNode* vhdlParser::ChoicesContext::BAR(size_t i) {
  return getToken(vhdlParser::BAR, i);
}


size_t vhdlParser::ChoicesContext::getRuleIndex() const {
  return vhdlParser::RuleChoices;
}

antlrcpp::Any vhdlParser::ChoicesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitChoices(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::ChoicesContext* vhdlParser::choices() {
  ChoicesContext *_localctx = _tracker.createInstance<ChoicesContext>(_ctx, getState());
  enterRule(_localctx, 84, vhdlParser::RuleChoices);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(918);
    choice();
    setState(923);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::BAR) {
      setState(919);
      match(vhdlParser::BAR);
      setState(920);
      choice();
      setState(925);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_configurationContext ------------------------------------------------------------------

vhdlParser::Component_configurationContext::Component_configurationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Component_configurationContext::FOR() {
  return getTokens(vhdlParser::FOR);
}

tree::TerminalNode* vhdlParser::Component_configurationContext::FOR(size_t i) {
  return getToken(vhdlParser::FOR, i);
}

vhdlParser::Component_specificationContext* vhdlParser::Component_configurationContext::component_specification() {
  return getRuleContext<vhdlParser::Component_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Component_configurationContext::END() {
  return getToken(vhdlParser::END, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Component_configurationContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Component_configurationContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}

vhdlParser::Binding_indicationContext* vhdlParser::Component_configurationContext::binding_indication() {
  return getRuleContext<vhdlParser::Binding_indicationContext>(0);
}

vhdlParser::Block_configurationContext* vhdlParser::Component_configurationContext::block_configuration() {
  return getRuleContext<vhdlParser::Block_configurationContext>(0);
}


size_t vhdlParser::Component_configurationContext::getRuleIndex() const {
  return vhdlParser::RuleComponent_configuration;
}

antlrcpp::Any vhdlParser::Component_configurationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitComponent_configuration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Component_configurationContext* vhdlParser::component_configuration() {
  Component_configurationContext *_localctx = _tracker.createInstance<Component_configurationContext>(_ctx, getState());
  enterRule(_localctx, 86, vhdlParser::RuleComponent_configuration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(926);
    match(vhdlParser::FOR);
    setState(927);
    component_specification();
    setState(931);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::GENERIC

    || _la == vhdlParser::PORT || _la == vhdlParser::USE

    || _la == vhdlParser::SEMI) {
      setState(928);
      binding_indication();
      setState(929);
      match(vhdlParser::SEMI);
    }
    setState(934);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::FOR) {
      setState(933);
      block_configuration();
    }
    setState(936);
    match(vhdlParser::END);
    setState(937);
    match(vhdlParser::FOR);
    setState(938);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_declarationContext ------------------------------------------------------------------

vhdlParser::Component_declarationContext::Component_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Component_declarationContext::COMPONENT() {
  return getTokens(vhdlParser::COMPONENT);
}

tree::TerminalNode* vhdlParser::Component_declarationContext::COMPONENT(size_t i) {
  return getToken(vhdlParser::COMPONENT, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Component_declarationContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Component_declarationContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Component_declarationContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Component_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Component_declarationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::Generic_clauseContext* vhdlParser::Component_declarationContext::generic_clause() {
  return getRuleContext<vhdlParser::Generic_clauseContext>(0);
}

vhdlParser::Port_clauseContext* vhdlParser::Component_declarationContext::port_clause() {
  return getRuleContext<vhdlParser::Port_clauseContext>(0);
}


size_t vhdlParser::Component_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleComponent_declaration;
}

antlrcpp::Any vhdlParser::Component_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitComponent_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Component_declarationContext* vhdlParser::component_declaration() {
  Component_declarationContext *_localctx = _tracker.createInstance<Component_declarationContext>(_ctx, getState());
  enterRule(_localctx, 88, vhdlParser::RuleComponent_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(940);
    match(vhdlParser::COMPONENT);
    setState(941);
    identifier();
    setState(943);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IS) {
      setState(942);
      match(vhdlParser::IS);
    }
    setState(946);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::GENERIC) {
      setState(945);
      generic_clause();
    }
    setState(949);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::PORT) {
      setState(948);
      port_clause();
    }
    setState(951);
    match(vhdlParser::END);
    setState(952);
    match(vhdlParser::COMPONENT);
    setState(954);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(953);
      identifier();
    }
    setState(956);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_instantiation_statementContext ------------------------------------------------------------------

vhdlParser::Component_instantiation_statementContext::Component_instantiation_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Label_colonContext* vhdlParser::Component_instantiation_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::Instantiated_unitContext* vhdlParser::Component_instantiation_statementContext::instantiated_unit() {
  return getRuleContext<vhdlParser::Instantiated_unitContext>(0);
}

tree::TerminalNode* vhdlParser::Component_instantiation_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::Component_instantiation_statementContext::generic_map_aspect() {
  return getRuleContext<vhdlParser::Generic_map_aspectContext>(0);
}

vhdlParser::Port_map_aspectContext* vhdlParser::Component_instantiation_statementContext::port_map_aspect() {
  return getRuleContext<vhdlParser::Port_map_aspectContext>(0);
}


size_t vhdlParser::Component_instantiation_statementContext::getRuleIndex() const {
  return vhdlParser::RuleComponent_instantiation_statement;
}

antlrcpp::Any vhdlParser::Component_instantiation_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitComponent_instantiation_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Component_instantiation_statementContext* vhdlParser::component_instantiation_statement() {
  Component_instantiation_statementContext *_localctx = _tracker.createInstance<Component_instantiation_statementContext>(_ctx, getState());
  enterRule(_localctx, 90, vhdlParser::RuleComponent_instantiation_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(958);
    label_colon();
    setState(959);
    instantiated_unit();
    setState(961);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::GENERIC) {
      setState(960);
      generic_map_aspect();
    }
    setState(964);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::PORT) {
      setState(963);
      port_map_aspect();
    }
    setState(966);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_specificationContext ------------------------------------------------------------------

vhdlParser::Component_specificationContext::Component_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Instantiation_listContext* vhdlParser::Component_specificationContext::instantiation_list() {
  return getRuleContext<vhdlParser::Instantiation_listContext>(0);
}

tree::TerminalNode* vhdlParser::Component_specificationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::NameContext* vhdlParser::Component_specificationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}


size_t vhdlParser::Component_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleComponent_specification;
}

antlrcpp::Any vhdlParser::Component_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitComponent_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Component_specificationContext* vhdlParser::component_specification() {
  Component_specificationContext *_localctx = _tracker.createInstance<Component_specificationContext>(_ctx, getState());
  enterRule(_localctx, 92, vhdlParser::RuleComponent_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(968);
    instantiation_list();
    setState(969);
    match(vhdlParser::COLON);
    setState(970);
    name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Composite_nature_definitionContext ------------------------------------------------------------------

vhdlParser::Composite_nature_definitionContext::Composite_nature_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Array_nature_definitionContext* vhdlParser::Composite_nature_definitionContext::array_nature_definition() {
  return getRuleContext<vhdlParser::Array_nature_definitionContext>(0);
}

vhdlParser::Record_nature_definitionContext* vhdlParser::Composite_nature_definitionContext::record_nature_definition() {
  return getRuleContext<vhdlParser::Record_nature_definitionContext>(0);
}


size_t vhdlParser::Composite_nature_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleComposite_nature_definition;
}

antlrcpp::Any vhdlParser::Composite_nature_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitComposite_nature_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Composite_nature_definitionContext* vhdlParser::composite_nature_definition() {
  Composite_nature_definitionContext *_localctx = _tracker.createInstance<Composite_nature_definitionContext>(_ctx, getState());
  enterRule(_localctx, 94, vhdlParser::RuleComposite_nature_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(974);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::ARRAY: {
        enterOuterAlt(_localctx, 1);
        setState(972);
        array_nature_definition();
        break;
      }

      case vhdlParser::RECORD: {
        enterOuterAlt(_localctx, 2);
        setState(973);
        record_nature_definition();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Composite_type_definitionContext ------------------------------------------------------------------

vhdlParser::Composite_type_definitionContext::Composite_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Array_type_definitionContext* vhdlParser::Composite_type_definitionContext::array_type_definition() {
  return getRuleContext<vhdlParser::Array_type_definitionContext>(0);
}

vhdlParser::Record_type_definitionContext* vhdlParser::Composite_type_definitionContext::record_type_definition() {
  return getRuleContext<vhdlParser::Record_type_definitionContext>(0);
}


size_t vhdlParser::Composite_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleComposite_type_definition;
}

antlrcpp::Any vhdlParser::Composite_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitComposite_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Composite_type_definitionContext* vhdlParser::composite_type_definition() {
  Composite_type_definitionContext *_localctx = _tracker.createInstance<Composite_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 96, vhdlParser::RuleComposite_type_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(978);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::ARRAY: {
        enterOuterAlt(_localctx, 1);
        setState(976);
        array_type_definition();
        break;
      }

      case vhdlParser::RECORD: {
        enterOuterAlt(_localctx, 2);
        setState(977);
        record_type_definition();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_assertion_statementContext ------------------------------------------------------------------

vhdlParser::Concurrent_assertion_statementContext::Concurrent_assertion_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::AssertionContext* vhdlParser::Concurrent_assertion_statementContext::assertion() {
  return getRuleContext<vhdlParser::AssertionContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_assertion_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Concurrent_assertion_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_assertion_statementContext::POSTPONED() {
  return getToken(vhdlParser::POSTPONED, 0);
}


size_t vhdlParser::Concurrent_assertion_statementContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_assertion_statement;
}

antlrcpp::Any vhdlParser::Concurrent_assertion_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConcurrent_assertion_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_assertion_statementContext* vhdlParser::concurrent_assertion_statement() {
  Concurrent_assertion_statementContext *_localctx = _tracker.createInstance<Concurrent_assertion_statementContext>(_ctx, getState());
  enterRule(_localctx, 98, vhdlParser::RuleConcurrent_assertion_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(981);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(980);
      label_colon();
    }
    setState(984);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::POSTPONED) {
      setState(983);
      match(vhdlParser::POSTPONED);
    }
    setState(986);
    assertion();
    setState(987);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_break_statementContext ------------------------------------------------------------------

vhdlParser::Concurrent_break_statementContext::Concurrent_break_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Concurrent_break_statementContext::BREAK() {
  return getToken(vhdlParser::BREAK, 0);
}

tree::TerminalNode* vhdlParser::Concurrent_break_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Concurrent_break_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::Break_listContext* vhdlParser::Concurrent_break_statementContext::break_list() {
  return getRuleContext<vhdlParser::Break_listContext>(0);
}

vhdlParser::Sensitivity_clauseContext* vhdlParser::Concurrent_break_statementContext::sensitivity_clause() {
  return getRuleContext<vhdlParser::Sensitivity_clauseContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_break_statementContext::WHEN() {
  return getToken(vhdlParser::WHEN, 0);
}

vhdlParser::ConditionContext* vhdlParser::Concurrent_break_statementContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}


size_t vhdlParser::Concurrent_break_statementContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_break_statement;
}

antlrcpp::Any vhdlParser::Concurrent_break_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConcurrent_break_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_break_statementContext* vhdlParser::concurrent_break_statement() {
  Concurrent_break_statementContext *_localctx = _tracker.createInstance<Concurrent_break_statementContext>(_ctx, getState());
  enterRule(_localctx, 100, vhdlParser::RuleConcurrent_break_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(990);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(989);
      label_colon();
    }
    setState(992);
    match(vhdlParser::BREAK);
    setState(994);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::FOR || _la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(993);
      break_list();
    }
    setState(997);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::ON) {
      setState(996);
      sensitivity_clause();
    }
    setState(1001);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::WHEN) {
      setState(999);
      match(vhdlParser::WHEN);
      setState(1000);
      condition();
    }
    setState(1003);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_procedure_call_statementContext ------------------------------------------------------------------

vhdlParser::Concurrent_procedure_call_statementContext::Concurrent_procedure_call_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Procedure_callContext* vhdlParser::Concurrent_procedure_call_statementContext::procedure_call() {
  return getRuleContext<vhdlParser::Procedure_callContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_procedure_call_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Concurrent_procedure_call_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_procedure_call_statementContext::POSTPONED() {
  return getToken(vhdlParser::POSTPONED, 0);
}


size_t vhdlParser::Concurrent_procedure_call_statementContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_procedure_call_statement;
}

antlrcpp::Any vhdlParser::Concurrent_procedure_call_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConcurrent_procedure_call_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_procedure_call_statementContext* vhdlParser::concurrent_procedure_call_statement() {
  Concurrent_procedure_call_statementContext *_localctx = _tracker.createInstance<Concurrent_procedure_call_statementContext>(_ctx, getState());
  enterRule(_localctx, 102, vhdlParser::RuleConcurrent_procedure_call_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1006);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      setState(1005);
      label_colon();
      break;
    }

    }
    setState(1009);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::POSTPONED) {
      setState(1008);
      match(vhdlParser::POSTPONED);
    }
    setState(1011);
    procedure_call();
    setState(1012);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_signal_assignment_statementContext ------------------------------------------------------------------

vhdlParser::Concurrent_signal_assignment_statementContext::Concurrent_signal_assignment_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Concurrent_simple_signal_assignmentContext* vhdlParser::Concurrent_signal_assignment_statementContext::concurrent_simple_signal_assignment() {
  return getRuleContext<vhdlParser::Concurrent_simple_signal_assignmentContext>(0);
}

vhdlParser::Label_colonContext* vhdlParser::Concurrent_signal_assignment_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_signal_assignment_statementContext::POSTPONED() {
  return getToken(vhdlParser::POSTPONED, 0);
}

vhdlParser::Concurrent_conditional_signal_assignmentContext* vhdlParser::Concurrent_signal_assignment_statementContext::concurrent_conditional_signal_assignment() {
  return getRuleContext<vhdlParser::Concurrent_conditional_signal_assignmentContext>(0);
}

vhdlParser::Concurrent_selected_signal_assignmentContext* vhdlParser::Concurrent_signal_assignment_statementContext::concurrent_selected_signal_assignment() {
  return getRuleContext<vhdlParser::Concurrent_selected_signal_assignmentContext>(0);
}


size_t vhdlParser::Concurrent_signal_assignment_statementContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_signal_assignment_statement;
}

antlrcpp::Any vhdlParser::Concurrent_signal_assignment_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConcurrent_signal_assignment_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_signal_assignment_statementContext* vhdlParser::concurrent_signal_assignment_statement() {
  Concurrent_signal_assignment_statementContext *_localctx = _tracker.createInstance<Concurrent_signal_assignment_statementContext>(_ctx, getState());
  enterRule(_localctx, 104, vhdlParser::RuleConcurrent_signal_assignment_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1035);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1015);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
      case 1: {
        setState(1014);
        label_colon();
        break;
      }

      }
      setState(1018);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::POSTPONED) {
        setState(1017);
        match(vhdlParser::POSTPONED);
      }
      setState(1020);
      concurrent_simple_signal_assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1022);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx)) {
      case 1: {
        setState(1021);
        label_colon();
        break;
      }

      }
      setState(1025);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::POSTPONED) {
        setState(1024);
        match(vhdlParser::POSTPONED);
      }
      setState(1027);
      concurrent_conditional_signal_assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1029);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::BASIC_IDENTIFIER

      || _la == vhdlParser::EXTENDED_IDENTIFIER) {
        setState(1028);
        label_colon();
      }
      setState(1032);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::POSTPONED) {
        setState(1031);
        match(vhdlParser::POSTPONED);
      }
      setState(1034);
      concurrent_selected_signal_assignment();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_simple_signal_assignmentContext ------------------------------------------------------------------

vhdlParser::Concurrent_simple_signal_assignmentContext::Concurrent_simple_signal_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Concurrent_simple_signal_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_simple_signal_assignmentContext::LE() {
  return getToken(vhdlParser::LE, 0);
}

vhdlParser::OptsContext* vhdlParser::Concurrent_simple_signal_assignmentContext::opts() {
  return getRuleContext<vhdlParser::OptsContext>(0);
}

vhdlParser::WaveformContext* vhdlParser::Concurrent_simple_signal_assignmentContext::waveform() {
  return getRuleContext<vhdlParser::WaveformContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_simple_signal_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Concurrent_simple_signal_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_simple_signal_assignment;
}

antlrcpp::Any vhdlParser::Concurrent_simple_signal_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConcurrent_simple_signal_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_simple_signal_assignmentContext* vhdlParser::concurrent_simple_signal_assignment() {
  Concurrent_simple_signal_assignmentContext *_localctx = _tracker.createInstance<Concurrent_simple_signal_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 106, vhdlParser::RuleConcurrent_simple_signal_assignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1037);
    target();
    setState(1038);
    match(vhdlParser::LE);
    setState(1039);
    opts();
    setState(1040);
    waveform();
    setState(1041);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_conditional_signal_assignmentContext ------------------------------------------------------------------

vhdlParser::Concurrent_conditional_signal_assignmentContext::Concurrent_conditional_signal_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Concurrent_conditional_signal_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_conditional_signal_assignmentContext::LE() {
  return getToken(vhdlParser::LE, 0);
}

vhdlParser::OptsContext* vhdlParser::Concurrent_conditional_signal_assignmentContext::opts() {
  return getRuleContext<vhdlParser::OptsContext>(0);
}

vhdlParser::Conditional_waveformsContext* vhdlParser::Concurrent_conditional_signal_assignmentContext::conditional_waveforms() {
  return getRuleContext<vhdlParser::Conditional_waveformsContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_conditional_signal_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Concurrent_conditional_signal_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_conditional_signal_assignment;
}

antlrcpp::Any vhdlParser::Concurrent_conditional_signal_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConcurrent_conditional_signal_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_conditional_signal_assignmentContext* vhdlParser::concurrent_conditional_signal_assignment() {
  Concurrent_conditional_signal_assignmentContext *_localctx = _tracker.createInstance<Concurrent_conditional_signal_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 108, vhdlParser::RuleConcurrent_conditional_signal_assignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1043);
    target();
    setState(1044);
    match(vhdlParser::LE);
    setState(1045);
    opts();
    setState(1046);
    conditional_waveforms();
    setState(1047);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Concurrent_selected_signal_assignmentContext ------------------------------------------------------------------

vhdlParser::Concurrent_selected_signal_assignmentContext::Concurrent_selected_signal_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Concurrent_selected_signal_assignmentContext::WITH() {
  return getToken(vhdlParser::WITH, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Concurrent_selected_signal_assignmentContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_selected_signal_assignmentContext::SELECT() {
  return getToken(vhdlParser::SELECT, 0);
}

vhdlParser::TargetContext* vhdlParser::Concurrent_selected_signal_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_selected_signal_assignmentContext::LE() {
  return getToken(vhdlParser::LE, 0);
}

vhdlParser::OptsContext* vhdlParser::Concurrent_selected_signal_assignmentContext::opts() {
  return getRuleContext<vhdlParser::OptsContext>(0);
}

vhdlParser::Selected_waveformsContext* vhdlParser::Concurrent_selected_signal_assignmentContext::selected_waveforms() {
  return getRuleContext<vhdlParser::Selected_waveformsContext>(0);
}

tree::TerminalNode* vhdlParser::Concurrent_selected_signal_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Concurrent_selected_signal_assignmentContext::TERNARY() {
  return getToken(vhdlParser::TERNARY, 0);
}


size_t vhdlParser::Concurrent_selected_signal_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConcurrent_selected_signal_assignment;
}

antlrcpp::Any vhdlParser::Concurrent_selected_signal_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConcurrent_selected_signal_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Concurrent_selected_signal_assignmentContext* vhdlParser::concurrent_selected_signal_assignment() {
  Concurrent_selected_signal_assignmentContext *_localctx = _tracker.createInstance<Concurrent_selected_signal_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 110, vhdlParser::RuleConcurrent_selected_signal_assignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1049);
    match(vhdlParser::WITH);
    setState(1050);
    expression();
    setState(1051);
    match(vhdlParser::SELECT);
    setState(1052);
    target();
    setState(1054);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::TERNARY) {
      setState(1053);
      match(vhdlParser::TERNARY);
    }
    setState(1056);
    match(vhdlParser::LE);
    setState(1057);
    opts();
    setState(1058);
    selected_waveforms();
    setState(1059);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

vhdlParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::ExpressionContext* vhdlParser::ConditionContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::ConditionContext::getRuleIndex() const {
  return vhdlParser::RuleCondition;
}

antlrcpp::Any vhdlParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::ConditionContext* vhdlParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 112, vhdlParser::RuleCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1061);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_clauseContext ------------------------------------------------------------------

vhdlParser::Condition_clauseContext::Condition_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Condition_clauseContext::UNTIL() {
  return getToken(vhdlParser::UNTIL, 0);
}

vhdlParser::ConditionContext* vhdlParser::Condition_clauseContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}


size_t vhdlParser::Condition_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleCondition_clause;
}

antlrcpp::Any vhdlParser::Condition_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitCondition_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Condition_clauseContext* vhdlParser::condition_clause() {
  Condition_clauseContext *_localctx = _tracker.createInstance<Condition_clauseContext>(_ctx, getState());
  enterRule(_localctx, 114, vhdlParser::RuleCondition_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1063);
    match(vhdlParser::UNTIL);
    setState(1064);
    condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_signal_assignmentContext ------------------------------------------------------------------

vhdlParser::Conditional_signal_assignmentContext::Conditional_signal_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Conditional_waveform_assignmentContext* vhdlParser::Conditional_signal_assignmentContext::conditional_waveform_assignment() {
  return getRuleContext<vhdlParser::Conditional_waveform_assignmentContext>(0);
}

vhdlParser::Conditional_force_assignmentContext* vhdlParser::Conditional_signal_assignmentContext::conditional_force_assignment() {
  return getRuleContext<vhdlParser::Conditional_force_assignmentContext>(0);
}


size_t vhdlParser::Conditional_signal_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_signal_assignment;
}

antlrcpp::Any vhdlParser::Conditional_signal_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConditional_signal_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_signal_assignmentContext* vhdlParser::conditional_signal_assignment() {
  Conditional_signal_assignmentContext *_localctx = _tracker.createInstance<Conditional_signal_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 116, vhdlParser::RuleConditional_signal_assignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1068);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1066);
      conditional_waveform_assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1067);
      conditional_force_assignment();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_waveform_assignmentContext ------------------------------------------------------------------

vhdlParser::Conditional_waveform_assignmentContext::Conditional_waveform_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Conditional_waveform_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Conditional_waveform_assignmentContext::LE() {
  return getToken(vhdlParser::LE, 0);
}

vhdlParser::Conditional_waveformsContext* vhdlParser::Conditional_waveform_assignmentContext::conditional_waveforms() {
  return getRuleContext<vhdlParser::Conditional_waveformsContext>(0);
}

vhdlParser::Delay_mechanismContext* vhdlParser::Conditional_waveform_assignmentContext::delay_mechanism() {
  return getRuleContext<vhdlParser::Delay_mechanismContext>(0);
}


size_t vhdlParser::Conditional_waveform_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_waveform_assignment;
}

antlrcpp::Any vhdlParser::Conditional_waveform_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConditional_waveform_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_waveform_assignmentContext* vhdlParser::conditional_waveform_assignment() {
  Conditional_waveform_assignmentContext *_localctx = _tracker.createInstance<Conditional_waveform_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 118, vhdlParser::RuleConditional_waveform_assignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1070);
    target();
    setState(1071);
    match(vhdlParser::LE);
    setState(1073);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 40) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 40)) & ((1ULL << (vhdlParser::INERTIAL - 40))
      | (1ULL << (vhdlParser::REJECT - 40))
      | (1ULL << (vhdlParser::TRANSPORT - 40)))) != 0)) {
      setState(1072);
      delay_mechanism();
    }
    setState(1075);
    conditional_waveforms();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_force_assignmentContext ------------------------------------------------------------------

vhdlParser::Conditional_force_assignmentContext::Conditional_force_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Conditional_force_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Conditional_force_assignmentContext::LE() {
  return getToken(vhdlParser::LE, 0);
}

tree::TerminalNode* vhdlParser::Conditional_force_assignmentContext::FORCE() {
  return getToken(vhdlParser::FORCE, 0);
}

vhdlParser::Conditional_expressionContext* vhdlParser::Conditional_force_assignmentContext::conditional_expression() {
  return getRuleContext<vhdlParser::Conditional_expressionContext>(0);
}

vhdlParser::Force_modeContext* vhdlParser::Conditional_force_assignmentContext::force_mode() {
  return getRuleContext<vhdlParser::Force_modeContext>(0);
}


size_t vhdlParser::Conditional_force_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_force_assignment;
}

antlrcpp::Any vhdlParser::Conditional_force_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConditional_force_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_force_assignmentContext* vhdlParser::conditional_force_assignment() {
  Conditional_force_assignmentContext *_localctx = _tracker.createInstance<Conditional_force_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 120, vhdlParser::RuleConditional_force_assignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1077);
    target();
    setState(1078);
    match(vhdlParser::LE);
    setState(1079);
    match(vhdlParser::FORCE);
    setState(1081);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IN

    || _la == vhdlParser::OUT) {
      setState(1080);
      force_mode();
    }
    setState(1083);
    conditional_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_waveformsContext ------------------------------------------------------------------

vhdlParser::Conditional_waveformsContext::Conditional_waveformsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::WaveformContext *> vhdlParser::Conditional_waveformsContext::waveform() {
  return getRuleContexts<vhdlParser::WaveformContext>();
}

vhdlParser::WaveformContext* vhdlParser::Conditional_waveformsContext::waveform(size_t i) {
  return getRuleContext<vhdlParser::WaveformContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Conditional_waveformsContext::WHEN() {
  return getTokens(vhdlParser::WHEN);
}

tree::TerminalNode* vhdlParser::Conditional_waveformsContext::WHEN(size_t i) {
  return getToken(vhdlParser::WHEN, i);
}

std::vector<vhdlParser::ConditionContext *> vhdlParser::Conditional_waveformsContext::condition() {
  return getRuleContexts<vhdlParser::ConditionContext>();
}

vhdlParser::ConditionContext* vhdlParser::Conditional_waveformsContext::condition(size_t i) {
  return getRuleContext<vhdlParser::ConditionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Conditional_waveformsContext::ELSE() {
  return getTokens(vhdlParser::ELSE);
}

tree::TerminalNode* vhdlParser::Conditional_waveformsContext::ELSE(size_t i) {
  return getToken(vhdlParser::ELSE, i);
}


size_t vhdlParser::Conditional_waveformsContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_waveforms;
}

antlrcpp::Any vhdlParser::Conditional_waveformsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConditional_waveforms(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_waveformsContext* vhdlParser::conditional_waveforms() {
  Conditional_waveformsContext *_localctx = _tracker.createInstance<Conditional_waveformsContext>(_ctx, getState());
  enterRule(_localctx, 122, vhdlParser::RuleConditional_waveforms);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1085);
    waveform();
    setState(1086);
    match(vhdlParser::WHEN);
    setState(1087);
    condition();
    setState(1095);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1088);
        match(vhdlParser::ELSE);
        setState(1089);
        waveform();
        setState(1090);
        match(vhdlParser::WHEN);
        setState(1091);
        condition(); 
      }
      setState(1097);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
    }
    setState(1100);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
    case 1: {
      setState(1098);
      match(vhdlParser::ELSE);
      setState(1099);
      waveform();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_expressionContext ------------------------------------------------------------------

vhdlParser::Conditional_expressionContext::Conditional_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::Conditional_expressionContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::Conditional_expressionContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Conditional_expressionContext::WHEN() {
  return getTokens(vhdlParser::WHEN);
}

tree::TerminalNode* vhdlParser::Conditional_expressionContext::WHEN(size_t i) {
  return getToken(vhdlParser::WHEN, i);
}

std::vector<vhdlParser::ConditionContext *> vhdlParser::Conditional_expressionContext::condition() {
  return getRuleContexts<vhdlParser::ConditionContext>();
}

vhdlParser::ConditionContext* vhdlParser::Conditional_expressionContext::condition(size_t i) {
  return getRuleContext<vhdlParser::ConditionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Conditional_expressionContext::ELSE() {
  return getTokens(vhdlParser::ELSE);
}

tree::TerminalNode* vhdlParser::Conditional_expressionContext::ELSE(size_t i) {
  return getToken(vhdlParser::ELSE, i);
}


size_t vhdlParser::Conditional_expressionContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_expression;
}

antlrcpp::Any vhdlParser::Conditional_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConditional_expression(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_expressionContext* vhdlParser::conditional_expression() {
  Conditional_expressionContext *_localctx = _tracker.createInstance<Conditional_expressionContext>(_ctx, getState());
  enterRule(_localctx, 124, vhdlParser::RuleConditional_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1102);
    expression();
    setState(1103);
    match(vhdlParser::WHEN);
    setState(1104);
    condition();
    setState(1112);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1105);
        match(vhdlParser::ELSE);
        setState(1106);
        expression();
        setState(1107);
        match(vhdlParser::WHEN);
        setState(1108);
        condition(); 
      }
      setState(1114);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx);
    }
    setState(1117);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
    case 1: {
      setState(1115);
      match(vhdlParser::ELSE);
      setState(1116);
      expression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Configuration_declarationContext ------------------------------------------------------------------

vhdlParser::Configuration_declarationContext::Configuration_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Configuration_declarationContext::CONFIGURATION() {
  return getTokens(vhdlParser::CONFIGURATION);
}

tree::TerminalNode* vhdlParser::Configuration_declarationContext::CONFIGURATION(size_t i) {
  return getToken(vhdlParser::CONFIGURATION, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Configuration_declarationContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Configuration_declarationContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Configuration_declarationContext::OF() {
  return getToken(vhdlParser::OF, 0);
}

vhdlParser::NameContext* vhdlParser::Configuration_declarationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Configuration_declarationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::Configuration_declarative_partContext* vhdlParser::Configuration_declarationContext::configuration_declarative_part() {
  return getRuleContext<vhdlParser::Configuration_declarative_partContext>(0);
}

vhdlParser::Block_configurationContext* vhdlParser::Configuration_declarationContext::block_configuration() {
  return getRuleContext<vhdlParser::Block_configurationContext>(0);
}

tree::TerminalNode* vhdlParser::Configuration_declarationContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Configuration_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Configuration_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleConfiguration_declaration;
}

antlrcpp::Any vhdlParser::Configuration_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConfiguration_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Configuration_declarationContext* vhdlParser::configuration_declaration() {
  Configuration_declarationContext *_localctx = _tracker.createInstance<Configuration_declarationContext>(_ctx, getState());
  enterRule(_localctx, 126, vhdlParser::RuleConfiguration_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1119);
    match(vhdlParser::CONFIGURATION);
    setState(1120);
    identifier();
    setState(1121);
    match(vhdlParser::OF);
    setState(1122);
    name();
    setState(1123);
    match(vhdlParser::IS);
    setState(1124);
    configuration_declarative_part();
    setState(1125);
    block_configuration();
    setState(1126);
    match(vhdlParser::END);
    setState(1128);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::CONFIGURATION) {
      setState(1127);
      match(vhdlParser::CONFIGURATION);
    }
    setState(1131);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1130);
      identifier();
    }
    setState(1133);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Configuration_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Configuration_declarative_itemContext::Configuration_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Use_clauseContext* vhdlParser::Configuration_declarative_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}

vhdlParser::Attribute_specificationContext* vhdlParser::Configuration_declarative_itemContext::attribute_specification() {
  return getRuleContext<vhdlParser::Attribute_specificationContext>(0);
}

vhdlParser::Group_declarationContext* vhdlParser::Configuration_declarative_itemContext::group_declaration() {
  return getRuleContext<vhdlParser::Group_declarationContext>(0);
}


size_t vhdlParser::Configuration_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleConfiguration_declarative_item;
}

antlrcpp::Any vhdlParser::Configuration_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConfiguration_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Configuration_declarative_itemContext* vhdlParser::configuration_declarative_item() {
  Configuration_declarative_itemContext *_localctx = _tracker.createInstance<Configuration_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 128, vhdlParser::RuleConfiguration_declarative_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1138);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::USE: {
        enterOuterAlt(_localctx, 1);
        setState(1135);
        use_clause();
        break;
      }

      case vhdlParser::ATTRIBUTE: {
        enterOuterAlt(_localctx, 2);
        setState(1136);
        attribute_specification();
        break;
      }

      case vhdlParser::GROUP: {
        enterOuterAlt(_localctx, 3);
        setState(1137);
        group_declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Configuration_declarative_partContext ------------------------------------------------------------------

vhdlParser::Configuration_declarative_partContext::Configuration_declarative_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Configuration_declarative_itemContext *> vhdlParser::Configuration_declarative_partContext::configuration_declarative_item() {
  return getRuleContexts<vhdlParser::Configuration_declarative_itemContext>();
}

vhdlParser::Configuration_declarative_itemContext* vhdlParser::Configuration_declarative_partContext::configuration_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Configuration_declarative_itemContext>(i);
}


size_t vhdlParser::Configuration_declarative_partContext::getRuleIndex() const {
  return vhdlParser::RuleConfiguration_declarative_part;
}

antlrcpp::Any vhdlParser::Configuration_declarative_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConfiguration_declarative_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Configuration_declarative_partContext* vhdlParser::configuration_declarative_part() {
  Configuration_declarative_partContext *_localctx = _tracker.createInstance<Configuration_declarative_partContext>(_ctx, getState());
  enterRule(_localctx, 130, vhdlParser::RuleConfiguration_declarative_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1143);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::ATTRIBUTE

    || _la == vhdlParser::GROUP || _la == vhdlParser::USE) {
      setState(1140);
      configuration_declarative_item();
      setState(1145);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Configuration_itemContext ------------------------------------------------------------------

vhdlParser::Configuration_itemContext::Configuration_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Block_configurationContext* vhdlParser::Configuration_itemContext::block_configuration() {
  return getRuleContext<vhdlParser::Block_configurationContext>(0);
}

vhdlParser::Component_configurationContext* vhdlParser::Configuration_itemContext::component_configuration() {
  return getRuleContext<vhdlParser::Component_configurationContext>(0);
}


size_t vhdlParser::Configuration_itemContext::getRuleIndex() const {
  return vhdlParser::RuleConfiguration_item;
}

antlrcpp::Any vhdlParser::Configuration_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConfiguration_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Configuration_itemContext* vhdlParser::configuration_item() {
  Configuration_itemContext *_localctx = _tracker.createInstance<Configuration_itemContext>(_ctx, getState());
  enterRule(_localctx, 132, vhdlParser::RuleConfiguration_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1148);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1146);
      block_configuration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1147);
      component_configuration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Configuration_specificationContext ------------------------------------------------------------------

vhdlParser::Configuration_specificationContext::Configuration_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Configuration_specificationContext::FOR() {
  return getToken(vhdlParser::FOR, 0);
}

vhdlParser::Component_specificationContext* vhdlParser::Configuration_specificationContext::component_specification() {
  return getRuleContext<vhdlParser::Component_specificationContext>(0);
}

vhdlParser::Binding_indicationContext* vhdlParser::Configuration_specificationContext::binding_indication() {
  return getRuleContext<vhdlParser::Binding_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Configuration_specificationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Configuration_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleConfiguration_specification;
}

antlrcpp::Any vhdlParser::Configuration_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConfiguration_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Configuration_specificationContext* vhdlParser::configuration_specification() {
  Configuration_specificationContext *_localctx = _tracker.createInstance<Configuration_specificationContext>(_ctx, getState());
  enterRule(_localctx, 134, vhdlParser::RuleConfiguration_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1150);
    match(vhdlParser::FOR);
    setState(1151);
    component_specification();
    setState(1152);
    binding_indication();
    setState(1153);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_declarationContext ------------------------------------------------------------------

vhdlParser::Constant_declarationContext::Constant_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Constant_declarationContext::CONSTANT() {
  return getToken(vhdlParser::CONSTANT, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Constant_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Constant_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Constant_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Constant_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Constant_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Constant_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Constant_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleConstant_declaration;
}

antlrcpp::Any vhdlParser::Constant_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConstant_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Constant_declarationContext* vhdlParser::constant_declaration() {
  Constant_declarationContext *_localctx = _tracker.createInstance<Constant_declarationContext>(_ctx, getState());
  enterRule(_localctx, 136, vhdlParser::RuleConstant_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1155);
    match(vhdlParser::CONSTANT);
    setState(1156);
    identifier_list();
    setState(1157);
    match(vhdlParser::COLON);
    setState(1158);
    subtype_indication();
    setState(1161);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1159);
      match(vhdlParser::VARASGN);
      setState(1160);
      expression();
    }
    setState(1163);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constrained_array_definitionContext ------------------------------------------------------------------

vhdlParser::Constrained_array_definitionContext::Constrained_array_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Constrained_array_definitionContext::ARRAY() {
  return getToken(vhdlParser::ARRAY, 0);
}

vhdlParser::Index_constraintContext* vhdlParser::Constrained_array_definitionContext::index_constraint() {
  return getRuleContext<vhdlParser::Index_constraintContext>(0);
}

tree::TerminalNode* vhdlParser::Constrained_array_definitionContext::OF() {
  return getToken(vhdlParser::OF, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Constrained_array_definitionContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::Constrained_array_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleConstrained_array_definition;
}

antlrcpp::Any vhdlParser::Constrained_array_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConstrained_array_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Constrained_array_definitionContext* vhdlParser::constrained_array_definition() {
  Constrained_array_definitionContext *_localctx = _tracker.createInstance<Constrained_array_definitionContext>(_ctx, getState());
  enterRule(_localctx, 138, vhdlParser::RuleConstrained_array_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1165);
    match(vhdlParser::ARRAY);
    setState(1166);
    index_constraint();
    setState(1167);
    match(vhdlParser::OF);
    setState(1168);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constrained_nature_definitionContext ------------------------------------------------------------------

vhdlParser::Constrained_nature_definitionContext::Constrained_nature_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Constrained_nature_definitionContext::ARRAY() {
  return getToken(vhdlParser::ARRAY, 0);
}

vhdlParser::Index_constraintContext* vhdlParser::Constrained_nature_definitionContext::index_constraint() {
  return getRuleContext<vhdlParser::Index_constraintContext>(0);
}

tree::TerminalNode* vhdlParser::Constrained_nature_definitionContext::OF() {
  return getToken(vhdlParser::OF, 0);
}

vhdlParser::Subnature_indicationContext* vhdlParser::Constrained_nature_definitionContext::subnature_indication() {
  return getRuleContext<vhdlParser::Subnature_indicationContext>(0);
}


size_t vhdlParser::Constrained_nature_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleConstrained_nature_definition;
}

antlrcpp::Any vhdlParser::Constrained_nature_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConstrained_nature_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Constrained_nature_definitionContext* vhdlParser::constrained_nature_definition() {
  Constrained_nature_definitionContext *_localctx = _tracker.createInstance<Constrained_nature_definitionContext>(_ctx, getState());
  enterRule(_localctx, 140, vhdlParser::RuleConstrained_nature_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1170);
    match(vhdlParser::ARRAY);
    setState(1171);
    index_constraint();
    setState(1172);
    match(vhdlParser::OF);
    setState(1173);
    subnature_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstraintContext ------------------------------------------------------------------

vhdlParser::ConstraintContext::ConstraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Range_constraintContext* vhdlParser::ConstraintContext::range_constraint() {
  return getRuleContext<vhdlParser::Range_constraintContext>(0);
}

vhdlParser::Index_constraintContext* vhdlParser::ConstraintContext::index_constraint() {
  return getRuleContext<vhdlParser::Index_constraintContext>(0);
}


size_t vhdlParser::ConstraintContext::getRuleIndex() const {
  return vhdlParser::RuleConstraint;
}

antlrcpp::Any vhdlParser::ConstraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConstraint(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::ConstraintContext* vhdlParser::constraint() {
  ConstraintContext *_localctx = _tracker.createInstance<ConstraintContext>(_ctx, getState());
  enterRule(_localctx, 142, vhdlParser::RuleConstraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::RANGE: {
        enterOuterAlt(_localctx, 1);
        setState(1175);
        range_constraint();
        break;
      }

      case vhdlParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(1176);
        index_constraint();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Context_clauseContext ------------------------------------------------------------------

vhdlParser::Context_clauseContext::Context_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Context_itemContext *> vhdlParser::Context_clauseContext::context_item() {
  return getRuleContexts<vhdlParser::Context_itemContext>();
}

vhdlParser::Context_itemContext* vhdlParser::Context_clauseContext::context_item(size_t i) {
  return getRuleContext<vhdlParser::Context_itemContext>(i);
}


size_t vhdlParser::Context_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleContext_clause;
}

antlrcpp::Any vhdlParser::Context_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitContext_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Context_clauseContext* vhdlParser::context_clause() {
  Context_clauseContext *_localctx = _tracker.createInstance<Context_clauseContext>(_ctx, getState());
  enterRule(_localctx, 144, vhdlParser::RuleContext_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1182);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::LIBRARY

    || _la == vhdlParser::USE) {
      setState(1179);
      context_item();
      setState(1184);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Context_itemContext ------------------------------------------------------------------

vhdlParser::Context_itemContext::Context_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Library_clauseContext* vhdlParser::Context_itemContext::library_clause() {
  return getRuleContext<vhdlParser::Library_clauseContext>(0);
}

vhdlParser::Use_clauseContext* vhdlParser::Context_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}


size_t vhdlParser::Context_itemContext::getRuleIndex() const {
  return vhdlParser::RuleContext_item;
}

antlrcpp::Any vhdlParser::Context_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitContext_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Context_itemContext* vhdlParser::context_item() {
  Context_itemContext *_localctx = _tracker.createInstance<Context_itemContext>(_ctx, getState());
  enterRule(_localctx, 146, vhdlParser::RuleContext_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1187);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::LIBRARY: {
        enterOuterAlt(_localctx, 1);
        setState(1185);
        library_clause();
        break;
      }

      case vhdlParser::USE: {
        enterOuterAlt(_localctx, 2);
        setState(1186);
        use_clause();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Delay_mechanismContext ------------------------------------------------------------------

vhdlParser::Delay_mechanismContext::Delay_mechanismContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Delay_mechanismContext::TRANSPORT() {
  return getToken(vhdlParser::TRANSPORT, 0);
}

tree::TerminalNode* vhdlParser::Delay_mechanismContext::INERTIAL() {
  return getToken(vhdlParser::INERTIAL, 0);
}

tree::TerminalNode* vhdlParser::Delay_mechanismContext::REJECT() {
  return getToken(vhdlParser::REJECT, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Delay_mechanismContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Delay_mechanismContext::getRuleIndex() const {
  return vhdlParser::RuleDelay_mechanism;
}

antlrcpp::Any vhdlParser::Delay_mechanismContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitDelay_mechanism(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Delay_mechanismContext* vhdlParser::delay_mechanism() {
  Delay_mechanismContext *_localctx = _tracker.createInstance<Delay_mechanismContext>(_ctx, getState());
  enterRule(_localctx, 148, vhdlParser::RuleDelay_mechanism);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1195);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::TRANSPORT: {
        enterOuterAlt(_localctx, 1);
        setState(1189);
        match(vhdlParser::TRANSPORT);
        break;
      }

      case vhdlParser::INERTIAL:
      case vhdlParser::REJECT: {
        enterOuterAlt(_localctx, 2);
        setState(1192);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == vhdlParser::REJECT) {
          setState(1190);
          match(vhdlParser::REJECT);
          setState(1191);
          expression();
        }
        setState(1194);
        match(vhdlParser::INERTIAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Design_fileContext ------------------------------------------------------------------

vhdlParser::Design_fileContext::Design_fileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Design_fileContext::EOF() {
  return getToken(vhdlParser::EOF, 0);
}

std::vector<vhdlParser::Design_unitContext *> vhdlParser::Design_fileContext::design_unit() {
  return getRuleContexts<vhdlParser::Design_unitContext>();
}

vhdlParser::Design_unitContext* vhdlParser::Design_fileContext::design_unit(size_t i) {
  return getRuleContext<vhdlParser::Design_unitContext>(i);
}


size_t vhdlParser::Design_fileContext::getRuleIndex() const {
  return vhdlParser::RuleDesign_file;
}

antlrcpp::Any vhdlParser::Design_fileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitDesign_file(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Design_fileContext* vhdlParser::design_file() {
  Design_fileContext *_localctx = _tracker.createInstance<Design_fileContext>(_ctx, getState());
  enterRule(_localctx, 150, vhdlParser::RuleDesign_file);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1200);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ARCHITECTURE)
      | (1ULL << vhdlParser::CONFIGURATION)
      | (1ULL << vhdlParser::ENTITY)
      | (1ULL << vhdlParser::LIBRARY))) != 0) || _la == vhdlParser::PACKAGE

    || _la == vhdlParser::USE) {
      setState(1197);
      design_unit();
      setState(1202);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1203);
    match(vhdlParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Design_unitContext ------------------------------------------------------------------

vhdlParser::Design_unitContext::Design_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Context_clauseContext* vhdlParser::Design_unitContext::context_clause() {
  return getRuleContext<vhdlParser::Context_clauseContext>(0);
}

vhdlParser::Library_unitContext* vhdlParser::Design_unitContext::library_unit() {
  return getRuleContext<vhdlParser::Library_unitContext>(0);
}


size_t vhdlParser::Design_unitContext::getRuleIndex() const {
  return vhdlParser::RuleDesign_unit;
}

antlrcpp::Any vhdlParser::Design_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitDesign_unit(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Design_unitContext* vhdlParser::design_unit() {
  Design_unitContext *_localctx = _tracker.createInstance<Design_unitContext>(_ctx, getState());
  enterRule(_localctx, 152, vhdlParser::RuleDesign_unit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1205);
    context_clause();
    setState(1206);
    library_unit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

vhdlParser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::DesignatorContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::DesignatorContext::STRING_LITERAL() {
  return getToken(vhdlParser::STRING_LITERAL, 0);
}


size_t vhdlParser::DesignatorContext::getRuleIndex() const {
  return vhdlParser::RuleDesignator;
}

antlrcpp::Any vhdlParser::DesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitDesignator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::DesignatorContext* vhdlParser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 154, vhdlParser::RuleDesignator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1210);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1208);
        identifier();
        break;
      }

      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1209);
        match(vhdlParser::STRING_LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectionContext ------------------------------------------------------------------

vhdlParser::DirectionContext::DirectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::DirectionContext::TO() {
  return getToken(vhdlParser::TO, 0);
}

tree::TerminalNode* vhdlParser::DirectionContext::DOWNTO() {
  return getToken(vhdlParser::DOWNTO, 0);
}


size_t vhdlParser::DirectionContext::getRuleIndex() const {
  return vhdlParser::RuleDirection;
}

antlrcpp::Any vhdlParser::DirectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitDirection(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::DirectionContext* vhdlParser::direction() {
  DirectionContext *_localctx = _tracker.createInstance<DirectionContext>(_ctx, getState());
  enterRule(_localctx, 156, vhdlParser::RuleDirection);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1212);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::DOWNTO || _la == vhdlParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Disconnection_specificationContext ------------------------------------------------------------------

vhdlParser::Disconnection_specificationContext::Disconnection_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Disconnection_specificationContext::DISCONNECT() {
  return getToken(vhdlParser::DISCONNECT, 0);
}

vhdlParser::Guarded_signal_specificationContext* vhdlParser::Disconnection_specificationContext::guarded_signal_specification() {
  return getRuleContext<vhdlParser::Guarded_signal_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Disconnection_specificationContext::AFTER() {
  return getToken(vhdlParser::AFTER, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Disconnection_specificationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Disconnection_specificationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Disconnection_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleDisconnection_specification;
}

antlrcpp::Any vhdlParser::Disconnection_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitDisconnection_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Disconnection_specificationContext* vhdlParser::disconnection_specification() {
  Disconnection_specificationContext *_localctx = _tracker.createInstance<Disconnection_specificationContext>(_ctx, getState());
  enterRule(_localctx, 158, vhdlParser::RuleDisconnection_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1214);
    match(vhdlParser::DISCONNECT);
    setState(1215);
    guarded_signal_specification();
    setState(1216);
    match(vhdlParser::AFTER);
    setState(1217);
    expression();
    setState(1218);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Discrete_rangeContext ------------------------------------------------------------------

vhdlParser::Discrete_rangeContext::Discrete_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::RangeContext* vhdlParser::Discrete_rangeContext::range() {
  return getRuleContext<vhdlParser::RangeContext>(0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Discrete_rangeContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::Discrete_rangeContext::getRuleIndex() const {
  return vhdlParser::RuleDiscrete_range;
}

antlrcpp::Any vhdlParser::Discrete_rangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitDiscrete_range(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Discrete_rangeContext* vhdlParser::discrete_range() {
  Discrete_rangeContext *_localctx = _tracker.createInstance<Discrete_rangeContext>(_ctx, getState());
  enterRule(_localctx, 160, vhdlParser::RuleDiscrete_range);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1222);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1220);
      range();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1221);
      subtype_indication();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_associationContext ------------------------------------------------------------------

vhdlParser::Element_associationContext::Element_associationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::ExpressionContext* vhdlParser::Element_associationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

vhdlParser::ChoicesContext* vhdlParser::Element_associationContext::choices() {
  return getRuleContext<vhdlParser::ChoicesContext>(0);
}

tree::TerminalNode* vhdlParser::Element_associationContext::ARROW() {
  return getToken(vhdlParser::ARROW, 0);
}


size_t vhdlParser::Element_associationContext::getRuleIndex() const {
  return vhdlParser::RuleElement_association;
}

antlrcpp::Any vhdlParser::Element_associationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitElement_association(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Element_associationContext* vhdlParser::element_association() {
  Element_associationContext *_localctx = _tracker.createInstance<Element_associationContext>(_ctx, getState());
  enterRule(_localctx, 162, vhdlParser::RuleElement_association);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1227);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx)) {
    case 1: {
      setState(1224);
      choices();
      setState(1225);
      match(vhdlParser::ARROW);
      break;
    }

    }
    setState(1229);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_declarationContext ------------------------------------------------------------------

vhdlParser::Element_declarationContext::Element_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Identifier_listContext* vhdlParser::Element_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Element_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Element_subtype_definitionContext* vhdlParser::Element_declarationContext::element_subtype_definition() {
  return getRuleContext<vhdlParser::Element_subtype_definitionContext>(0);
}

tree::TerminalNode* vhdlParser::Element_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Element_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleElement_declaration;
}

antlrcpp::Any vhdlParser::Element_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitElement_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Element_declarationContext* vhdlParser::element_declaration() {
  Element_declarationContext *_localctx = _tracker.createInstance<Element_declarationContext>(_ctx, getState());
  enterRule(_localctx, 164, vhdlParser::RuleElement_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1231);
    identifier_list();
    setState(1232);
    match(vhdlParser::COLON);
    setState(1233);
    element_subtype_definition();
    setState(1234);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_subnature_definitionContext ------------------------------------------------------------------

vhdlParser::Element_subnature_definitionContext::Element_subnature_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subnature_indicationContext* vhdlParser::Element_subnature_definitionContext::subnature_indication() {
  return getRuleContext<vhdlParser::Subnature_indicationContext>(0);
}


size_t vhdlParser::Element_subnature_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleElement_subnature_definition;
}

antlrcpp::Any vhdlParser::Element_subnature_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitElement_subnature_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Element_subnature_definitionContext* vhdlParser::element_subnature_definition() {
  Element_subnature_definitionContext *_localctx = _tracker.createInstance<Element_subnature_definitionContext>(_ctx, getState());
  enterRule(_localctx, 166, vhdlParser::RuleElement_subnature_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1236);
    subnature_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_subtype_definitionContext ------------------------------------------------------------------

vhdlParser::Element_subtype_definitionContext::Element_subtype_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subtype_indicationContext* vhdlParser::Element_subtype_definitionContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::Element_subtype_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleElement_subtype_definition;
}

antlrcpp::Any vhdlParser::Element_subtype_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitElement_subtype_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Element_subtype_definitionContext* vhdlParser::element_subtype_definition() {
  Element_subtype_definitionContext *_localctx = _tracker.createInstance<Element_subtype_definitionContext>(_ctx, getState());
  enterRule(_localctx, 168, vhdlParser::RuleElement_subtype_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1238);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_aspectContext ------------------------------------------------------------------

vhdlParser::Entity_aspectContext::Entity_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Entity_aspectContext::ENTITY() {
  return getToken(vhdlParser::ENTITY, 0);
}

vhdlParser::NameContext* vhdlParser::Entity_aspectContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_aspectContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Entity_aspectContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_aspectContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Entity_aspectContext::CONFIGURATION() {
  return getToken(vhdlParser::CONFIGURATION, 0);
}

tree::TerminalNode* vhdlParser::Entity_aspectContext::OPEN() {
  return getToken(vhdlParser::OPEN, 0);
}


size_t vhdlParser::Entity_aspectContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_aspect;
}

antlrcpp::Any vhdlParser::Entity_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_aspectContext* vhdlParser::entity_aspect() {
  Entity_aspectContext *_localctx = _tracker.createInstance<Entity_aspectContext>(_ctx, getState());
  enterRule(_localctx, 170, vhdlParser::RuleEntity_aspect);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1251);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::ENTITY: {
        enterOuterAlt(_localctx, 1);
        setState(1240);
        match(vhdlParser::ENTITY);
        setState(1241);
        name();
        setState(1246);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == vhdlParser::LPAREN) {
          setState(1242);
          match(vhdlParser::LPAREN);
          setState(1243);
          identifier();
          setState(1244);
          match(vhdlParser::RPAREN);
        }
        break;
      }

      case vhdlParser::CONFIGURATION: {
        enterOuterAlt(_localctx, 2);
        setState(1248);
        match(vhdlParser::CONFIGURATION);
        setState(1249);
        name();
        break;
      }

      case vhdlParser::OPEN: {
        enterOuterAlt(_localctx, 3);
        setState(1250);
        match(vhdlParser::OPEN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_classContext ------------------------------------------------------------------

vhdlParser::Entity_classContext::Entity_classContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Entity_classContext::ENTITY() {
  return getToken(vhdlParser::ENTITY, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::ARCHITECTURE() {
  return getToken(vhdlParser::ARCHITECTURE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::CONFIGURATION() {
  return getToken(vhdlParser::CONFIGURATION, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::PROCEDURE() {
  return getToken(vhdlParser::PROCEDURE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::FUNCTION() {
  return getToken(vhdlParser::FUNCTION, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::PACKAGE() {
  return getToken(vhdlParser::PACKAGE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::TYPE() {
  return getToken(vhdlParser::TYPE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::SUBTYPE() {
  return getToken(vhdlParser::SUBTYPE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::CONSTANT() {
  return getToken(vhdlParser::CONSTANT, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::SIGNAL() {
  return getToken(vhdlParser::SIGNAL, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::VARIABLE() {
  return getToken(vhdlParser::VARIABLE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::COMPONENT() {
  return getToken(vhdlParser::COMPONENT, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::LABEL() {
  return getToken(vhdlParser::LABEL, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::LITERAL() {
  return getToken(vhdlParser::LITERAL, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::UNITS() {
  return getToken(vhdlParser::UNITS, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::GROUP() {
  return getToken(vhdlParser::GROUP, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::FILE() {
  return getToken(vhdlParser::FILE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::NATURE() {
  return getToken(vhdlParser::NATURE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::SUBNATURE() {
  return getToken(vhdlParser::SUBNATURE, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::QUANTITY() {
  return getToken(vhdlParser::QUANTITY, 0);
}

tree::TerminalNode* vhdlParser::Entity_classContext::TERMINAL() {
  return getToken(vhdlParser::TERMINAL, 0);
}


size_t vhdlParser::Entity_classContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_class;
}

antlrcpp::Any vhdlParser::Entity_classContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_class(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_classContext* vhdlParser::entity_class() {
  Entity_classContext *_localctx = _tracker.createInstance<Entity_classContext>(_ctx, getState());
  enterRule(_localctx, 172, vhdlParser::RuleEntity_class);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1253);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ARCHITECTURE)
      | (1ULL << vhdlParser::COMPONENT)
      | (1ULL << vhdlParser::CONFIGURATION)
      | (1ULL << vhdlParser::CONSTANT)
      | (1ULL << vhdlParser::ENTITY)
      | (1ULL << vhdlParser::FILE)
      | (1ULL << vhdlParser::FUNCTION)
      | (1ULL << vhdlParser::GROUP)
      | (1ULL << vhdlParser::LABEL)
      | (1ULL << vhdlParser::LITERAL)
      | (1ULL << vhdlParser::NATURE))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (vhdlParser::PACKAGE - 65))
      | (1ULL << (vhdlParser::PROCEDURE - 65))
      | (1ULL << (vhdlParser::QUANTITY - 65))
      | (1ULL << (vhdlParser::SIGNAL - 65))
      | (1ULL << (vhdlParser::SUBNATURE - 65))
      | (1ULL << (vhdlParser::SUBTYPE - 65))
      | (1ULL << (vhdlParser::TERMINAL - 65))
      | (1ULL << (vhdlParser::TYPE - 65))
      | (1ULL << (vhdlParser::UNITS - 65))
      | (1ULL << (vhdlParser::VARIABLE - 65)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_class_entryContext ------------------------------------------------------------------

vhdlParser::Entity_class_entryContext::Entity_class_entryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Entity_classContext* vhdlParser::Entity_class_entryContext::entity_class() {
  return getRuleContext<vhdlParser::Entity_classContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_class_entryContext::BOX() {
  return getToken(vhdlParser::BOX, 0);
}


size_t vhdlParser::Entity_class_entryContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_class_entry;
}

antlrcpp::Any vhdlParser::Entity_class_entryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_class_entry(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_class_entryContext* vhdlParser::entity_class_entry() {
  Entity_class_entryContext *_localctx = _tracker.createInstance<Entity_class_entryContext>(_ctx, getState());
  enterRule(_localctx, 174, vhdlParser::RuleEntity_class_entry);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1255);
    entity_class();
    setState(1257);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BOX) {
      setState(1256);
      match(vhdlParser::BOX);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_class_entry_listContext ------------------------------------------------------------------

vhdlParser::Entity_class_entry_listContext::Entity_class_entry_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Entity_class_entryContext *> vhdlParser::Entity_class_entry_listContext::entity_class_entry() {
  return getRuleContexts<vhdlParser::Entity_class_entryContext>();
}

vhdlParser::Entity_class_entryContext* vhdlParser::Entity_class_entry_listContext::entity_class_entry(size_t i) {
  return getRuleContext<vhdlParser::Entity_class_entryContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Entity_class_entry_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Entity_class_entry_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Entity_class_entry_listContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_class_entry_list;
}

antlrcpp::Any vhdlParser::Entity_class_entry_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_class_entry_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_class_entry_listContext* vhdlParser::entity_class_entry_list() {
  Entity_class_entry_listContext *_localctx = _tracker.createInstance<Entity_class_entry_listContext>(_ctx, getState());
  enterRule(_localctx, 176, vhdlParser::RuleEntity_class_entry_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1259);
    entity_class_entry();
    setState(1264);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1260);
      match(vhdlParser::COMMA);
      setState(1261);
      entity_class_entry();
      setState(1266);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_declarationContext ------------------------------------------------------------------

vhdlParser::Entity_declarationContext::Entity_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Entity_declarationContext::ENTITY() {
  return getTokens(vhdlParser::ENTITY);
}

tree::TerminalNode* vhdlParser::Entity_declarationContext::ENTITY(size_t i) {
  return getToken(vhdlParser::ENTITY, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Entity_declarationContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Entity_declarationContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Entity_declarationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::Entity_headerContext* vhdlParser::Entity_declarationContext::entity_header() {
  return getRuleContext<vhdlParser::Entity_headerContext>(0);
}

vhdlParser::Entity_declarative_partContext* vhdlParser::Entity_declarationContext::entity_declarative_part() {
  return getRuleContext<vhdlParser::Entity_declarative_partContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_declarationContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Entity_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Entity_declarationContext::BEGIN() {
  return getToken(vhdlParser::BEGIN, 0);
}

vhdlParser::Entity_statement_partContext* vhdlParser::Entity_declarationContext::entity_statement_part() {
  return getRuleContext<vhdlParser::Entity_statement_partContext>(0);
}


size_t vhdlParser::Entity_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_declaration;
}

antlrcpp::Any vhdlParser::Entity_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_declarationContext* vhdlParser::entity_declaration() {
  Entity_declarationContext *_localctx = _tracker.createInstance<Entity_declarationContext>(_ctx, getState());
  enterRule(_localctx, 178, vhdlParser::RuleEntity_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1267);
    match(vhdlParser::ENTITY);
    setState(1268);
    identifier();
    setState(1269);
    match(vhdlParser::IS);
    setState(1270);
    entity_header();
    setState(1271);
    entity_declarative_part();
    setState(1274);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BEGIN) {
      setState(1272);
      match(vhdlParser::BEGIN);
      setState(1273);
      entity_statement_part();
    }
    setState(1276);
    match(vhdlParser::END);
    setState(1278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::ENTITY) {
      setState(1277);
      match(vhdlParser::ENTITY);
    }
    setState(1281);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1280);
      identifier();
    }
    setState(1283);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Entity_declarative_itemContext::Entity_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_declarationContext* vhdlParser::Entity_declarative_itemContext::subprogram_declaration() {
  return getRuleContext<vhdlParser::Subprogram_declarationContext>(0);
}

vhdlParser::Subprogram_bodyContext* vhdlParser::Entity_declarative_itemContext::subprogram_body() {
  return getRuleContext<vhdlParser::Subprogram_bodyContext>(0);
}

vhdlParser::Type_declarationContext* vhdlParser::Entity_declarative_itemContext::type_declaration() {
  return getRuleContext<vhdlParser::Type_declarationContext>(0);
}

vhdlParser::Subtype_declarationContext* vhdlParser::Entity_declarative_itemContext::subtype_declaration() {
  return getRuleContext<vhdlParser::Subtype_declarationContext>(0);
}

vhdlParser::Constant_declarationContext* vhdlParser::Entity_declarative_itemContext::constant_declaration() {
  return getRuleContext<vhdlParser::Constant_declarationContext>(0);
}

vhdlParser::Signal_declarationContext* vhdlParser::Entity_declarative_itemContext::signal_declaration() {
  return getRuleContext<vhdlParser::Signal_declarationContext>(0);
}

vhdlParser::Variable_declarationContext* vhdlParser::Entity_declarative_itemContext::variable_declaration() {
  return getRuleContext<vhdlParser::Variable_declarationContext>(0);
}

vhdlParser::File_declarationContext* vhdlParser::Entity_declarative_itemContext::file_declaration() {
  return getRuleContext<vhdlParser::File_declarationContext>(0);
}

vhdlParser::Alias_declarationContext* vhdlParser::Entity_declarative_itemContext::alias_declaration() {
  return getRuleContext<vhdlParser::Alias_declarationContext>(0);
}

vhdlParser::Attribute_declarationContext* vhdlParser::Entity_declarative_itemContext::attribute_declaration() {
  return getRuleContext<vhdlParser::Attribute_declarationContext>(0);
}

vhdlParser::Attribute_specificationContext* vhdlParser::Entity_declarative_itemContext::attribute_specification() {
  return getRuleContext<vhdlParser::Attribute_specificationContext>(0);
}

vhdlParser::Disconnection_specificationContext* vhdlParser::Entity_declarative_itemContext::disconnection_specification() {
  return getRuleContext<vhdlParser::Disconnection_specificationContext>(0);
}

vhdlParser::Step_limit_specificationContext* vhdlParser::Entity_declarative_itemContext::step_limit_specification() {
  return getRuleContext<vhdlParser::Step_limit_specificationContext>(0);
}

vhdlParser::Use_clauseContext* vhdlParser::Entity_declarative_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}

vhdlParser::Group_template_declarationContext* vhdlParser::Entity_declarative_itemContext::group_template_declaration() {
  return getRuleContext<vhdlParser::Group_template_declarationContext>(0);
}

vhdlParser::Group_declarationContext* vhdlParser::Entity_declarative_itemContext::group_declaration() {
  return getRuleContext<vhdlParser::Group_declarationContext>(0);
}

vhdlParser::Nature_declarationContext* vhdlParser::Entity_declarative_itemContext::nature_declaration() {
  return getRuleContext<vhdlParser::Nature_declarationContext>(0);
}

vhdlParser::Subnature_declarationContext* vhdlParser::Entity_declarative_itemContext::subnature_declaration() {
  return getRuleContext<vhdlParser::Subnature_declarationContext>(0);
}

vhdlParser::Quantity_declarationContext* vhdlParser::Entity_declarative_itemContext::quantity_declaration() {
  return getRuleContext<vhdlParser::Quantity_declarationContext>(0);
}

vhdlParser::Terminal_declarationContext* vhdlParser::Entity_declarative_itemContext::terminal_declaration() {
  return getRuleContext<vhdlParser::Terminal_declarationContext>(0);
}


size_t vhdlParser::Entity_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_declarative_item;
}

antlrcpp::Any vhdlParser::Entity_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_declarative_itemContext* vhdlParser::entity_declarative_item() {
  Entity_declarative_itemContext *_localctx = _tracker.createInstance<Entity_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 180, vhdlParser::RuleEntity_declarative_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1305);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1285);
      subprogram_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1286);
      subprogram_body();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1287);
      type_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1288);
      subtype_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1289);
      constant_declaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1290);
      signal_declaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1291);
      variable_declaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(1292);
      file_declaration();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(1293);
      alias_declaration();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(1294);
      attribute_declaration();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(1295);
      attribute_specification();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(1296);
      disconnection_specification();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(1297);
      step_limit_specification();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(1298);
      use_clause();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(1299);
      group_template_declaration();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(1300);
      group_declaration();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(1301);
      nature_declaration();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(1302);
      subnature_declaration();
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(1303);
      quantity_declaration();
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(1304);
      terminal_declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_declarative_partContext ------------------------------------------------------------------

vhdlParser::Entity_declarative_partContext::Entity_declarative_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Entity_declarative_itemContext *> vhdlParser::Entity_declarative_partContext::entity_declarative_item() {
  return getRuleContexts<vhdlParser::Entity_declarative_itemContext>();
}

vhdlParser::Entity_declarative_itemContext* vhdlParser::Entity_declarative_partContext::entity_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Entity_declarative_itemContext>(i);
}


size_t vhdlParser::Entity_declarative_partContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_declarative_part;
}

antlrcpp::Any vhdlParser::Entity_declarative_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_declarative_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_declarative_partContext* vhdlParser::entity_declarative_part() {
  Entity_declarative_partContext *_localctx = _tracker.createInstance<Entity_declarative_partContext>(_ctx, getState());
  enterRule(_localctx, 182, vhdlParser::RuleEntity_declarative_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1310);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ALIAS)
      | (1ULL << vhdlParser::ATTRIBUTE)
      | (1ULL << vhdlParser::CONSTANT)
      | (1ULL << vhdlParser::DISCONNECT)
      | (1ULL << vhdlParser::FILE)
      | (1ULL << vhdlParser::FUNCTION)
      | (1ULL << vhdlParser::GROUP)
      | (1ULL << vhdlParser::IMPURE)
      | (1ULL << vhdlParser::LIMIT)
      | (1ULL << vhdlParser::NATURE))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (vhdlParser::PROCEDURE - 69))
      | (1ULL << (vhdlParser::PURE - 69))
      | (1ULL << (vhdlParser::QUANTITY - 69))
      | (1ULL << (vhdlParser::SHARED - 69))
      | (1ULL << (vhdlParser::SIGNAL - 69))
      | (1ULL << (vhdlParser::SUBNATURE - 69))
      | (1ULL << (vhdlParser::SUBTYPE - 69))
      | (1ULL << (vhdlParser::TERMINAL - 69))
      | (1ULL << (vhdlParser::TYPE - 69))
      | (1ULL << (vhdlParser::USE - 69))
      | (1ULL << (vhdlParser::VARIABLE - 69)))) != 0)) {
      setState(1307);
      entity_declarative_item();
      setState(1312);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_designatorContext ------------------------------------------------------------------

vhdlParser::Entity_designatorContext::Entity_designatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Entity_tagContext* vhdlParser::Entity_designatorContext::entity_tag() {
  return getRuleContext<vhdlParser::Entity_tagContext>(0);
}

vhdlParser::SignatureContext* vhdlParser::Entity_designatorContext::signature() {
  return getRuleContext<vhdlParser::SignatureContext>(0);
}


size_t vhdlParser::Entity_designatorContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_designator;
}

antlrcpp::Any vhdlParser::Entity_designatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_designator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_designatorContext* vhdlParser::entity_designator() {
  Entity_designatorContext *_localctx = _tracker.createInstance<Entity_designatorContext>(_ctx, getState());
  enterRule(_localctx, 184, vhdlParser::RuleEntity_designator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1313);
    entity_tag();
    setState(1315);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LBRACKET) {
      setState(1314);
      signature();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_headerContext ------------------------------------------------------------------

vhdlParser::Entity_headerContext::Entity_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Generic_clauseContext* vhdlParser::Entity_headerContext::generic_clause() {
  return getRuleContext<vhdlParser::Generic_clauseContext>(0);
}

vhdlParser::Port_clauseContext* vhdlParser::Entity_headerContext::port_clause() {
  return getRuleContext<vhdlParser::Port_clauseContext>(0);
}


size_t vhdlParser::Entity_headerContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_header;
}

antlrcpp::Any vhdlParser::Entity_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_header(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_headerContext* vhdlParser::entity_header() {
  Entity_headerContext *_localctx = _tracker.createInstance<Entity_headerContext>(_ctx, getState());
  enterRule(_localctx, 186, vhdlParser::RuleEntity_header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1318);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::GENERIC) {
      setState(1317);
      generic_clause();
    }
    setState(1321);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::PORT) {
      setState(1320);
      port_clause();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_name_listContext ------------------------------------------------------------------

vhdlParser::Entity_name_listContext::Entity_name_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Entity_designatorContext *> vhdlParser::Entity_name_listContext::entity_designator() {
  return getRuleContexts<vhdlParser::Entity_designatorContext>();
}

vhdlParser::Entity_designatorContext* vhdlParser::Entity_name_listContext::entity_designator(size_t i) {
  return getRuleContext<vhdlParser::Entity_designatorContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Entity_name_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Entity_name_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}

tree::TerminalNode* vhdlParser::Entity_name_listContext::OTHERS() {
  return getToken(vhdlParser::OTHERS, 0);
}

tree::TerminalNode* vhdlParser::Entity_name_listContext::ALL() {
  return getToken(vhdlParser::ALL, 0);
}


size_t vhdlParser::Entity_name_listContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_name_list;
}

antlrcpp::Any vhdlParser::Entity_name_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_name_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_name_listContext* vhdlParser::entity_name_list() {
  Entity_name_listContext *_localctx = _tracker.createInstance<Entity_name_listContext>(_ctx, getState());
  enterRule(_localctx, 188, vhdlParser::RuleEntity_name_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1333);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(1323);
        entity_designator();
        setState(1328);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::COMMA) {
          setState(1324);
          match(vhdlParser::COMMA);
          setState(1325);
          entity_designator();
          setState(1330);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case vhdlParser::OTHERS: {
        enterOuterAlt(_localctx, 2);
        setState(1331);
        match(vhdlParser::OTHERS);
        break;
      }

      case vhdlParser::ALL: {
        enterOuterAlt(_localctx, 3);
        setState(1332);
        match(vhdlParser::ALL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_specificationContext ------------------------------------------------------------------

vhdlParser::Entity_specificationContext::Entity_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Entity_name_listContext* vhdlParser::Entity_specificationContext::entity_name_list() {
  return getRuleContext<vhdlParser::Entity_name_listContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_specificationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Entity_classContext* vhdlParser::Entity_specificationContext::entity_class() {
  return getRuleContext<vhdlParser::Entity_classContext>(0);
}


size_t vhdlParser::Entity_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_specification;
}

antlrcpp::Any vhdlParser::Entity_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_specificationContext* vhdlParser::entity_specification() {
  Entity_specificationContext *_localctx = _tracker.createInstance<Entity_specificationContext>(_ctx, getState());
  enterRule(_localctx, 190, vhdlParser::RuleEntity_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1335);
    entity_name_list();
    setState(1336);
    match(vhdlParser::COLON);
    setState(1337);
    entity_class();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_statementContext ------------------------------------------------------------------

vhdlParser::Entity_statementContext::Entity_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Concurrent_assertion_statementContext* vhdlParser::Entity_statementContext::concurrent_assertion_statement() {
  return getRuleContext<vhdlParser::Concurrent_assertion_statementContext>(0);
}

vhdlParser::Process_statementContext* vhdlParser::Entity_statementContext::process_statement() {
  return getRuleContext<vhdlParser::Process_statementContext>(0);
}

vhdlParser::Concurrent_procedure_call_statementContext* vhdlParser::Entity_statementContext::concurrent_procedure_call_statement() {
  return getRuleContext<vhdlParser::Concurrent_procedure_call_statementContext>(0);
}


size_t vhdlParser::Entity_statementContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_statement;
}

antlrcpp::Any vhdlParser::Entity_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_statementContext* vhdlParser::entity_statement() {
  Entity_statementContext *_localctx = _tracker.createInstance<Entity_statementContext>(_ctx, getState());
  enterRule(_localctx, 192, vhdlParser::RuleEntity_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1342);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 118, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1339);
      concurrent_assertion_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1340);
      process_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1341);
      concurrent_procedure_call_statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_statement_partContext ------------------------------------------------------------------

vhdlParser::Entity_statement_partContext::Entity_statement_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Entity_statementContext *> vhdlParser::Entity_statement_partContext::entity_statement() {
  return getRuleContexts<vhdlParser::Entity_statementContext>();
}

vhdlParser::Entity_statementContext* vhdlParser::Entity_statement_partContext::entity_statement(size_t i) {
  return getRuleContext<vhdlParser::Entity_statementContext>(i);
}


size_t vhdlParser::Entity_statement_partContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_statement_part;
}

antlrcpp::Any vhdlParser::Entity_statement_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_statement_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_statement_partContext* vhdlParser::entity_statement_part() {
  Entity_statement_partContext *_localctx = _tracker.createInstance<Entity_statement_partContext>(_ctx, getState());
  enterRule(_localctx, 194, vhdlParser::RuleEntity_statement_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1347);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::ASSERT || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (vhdlParser::POSTPONED - 67))
      | (1ULL << (vhdlParser::PROCESS - 67))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 67))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 67)))) != 0)) {
      setState(1344);
      entity_statement();
      setState(1349);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entity_tagContext ------------------------------------------------------------------

vhdlParser::Entity_tagContext::Entity_tagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Entity_tagContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Entity_tagContext::CHARACTER_LITERAL() {
  return getToken(vhdlParser::CHARACTER_LITERAL, 0);
}

tree::TerminalNode* vhdlParser::Entity_tagContext::STRING_LITERAL() {
  return getToken(vhdlParser::STRING_LITERAL, 0);
}


size_t vhdlParser::Entity_tagContext::getRuleIndex() const {
  return vhdlParser::RuleEntity_tag;
}

antlrcpp::Any vhdlParser::Entity_tagContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEntity_tag(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Entity_tagContext* vhdlParser::entity_tag() {
  Entity_tagContext *_localctx = _tracker.createInstance<Entity_tagContext>(_ctx, getState());
  enterRule(_localctx, 196, vhdlParser::RuleEntity_tag);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1353);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1350);
        identifier();
        break;
      }

      case vhdlParser::CHARACTER_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1351);
        match(vhdlParser::CHARACTER_LITERAL);
        break;
      }

      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(1352);
        match(vhdlParser::STRING_LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enumeration_literalContext ------------------------------------------------------------------

vhdlParser::Enumeration_literalContext::Enumeration_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Enumeration_literalContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Enumeration_literalContext::CHARACTER_LITERAL() {
  return getToken(vhdlParser::CHARACTER_LITERAL, 0);
}


size_t vhdlParser::Enumeration_literalContext::getRuleIndex() const {
  return vhdlParser::RuleEnumeration_literal;
}

antlrcpp::Any vhdlParser::Enumeration_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEnumeration_literal(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Enumeration_literalContext* vhdlParser::enumeration_literal() {
  Enumeration_literalContext *_localctx = _tracker.createInstance<Enumeration_literalContext>(_ctx, getState());
  enterRule(_localctx, 198, vhdlParser::RuleEnumeration_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1357);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1355);
        identifier();
        break;
      }

      case vhdlParser::CHARACTER_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1356);
        match(vhdlParser::CHARACTER_LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enumeration_type_definitionContext ------------------------------------------------------------------

vhdlParser::Enumeration_type_definitionContext::Enumeration_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Enumeration_type_definitionContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Enumeration_literalContext *> vhdlParser::Enumeration_type_definitionContext::enumeration_literal() {
  return getRuleContexts<vhdlParser::Enumeration_literalContext>();
}

vhdlParser::Enumeration_literalContext* vhdlParser::Enumeration_type_definitionContext::enumeration_literal(size_t i) {
  return getRuleContext<vhdlParser::Enumeration_literalContext>(i);
}

tree::TerminalNode* vhdlParser::Enumeration_type_definitionContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Enumeration_type_definitionContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Enumeration_type_definitionContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Enumeration_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleEnumeration_type_definition;
}

antlrcpp::Any vhdlParser::Enumeration_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitEnumeration_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Enumeration_type_definitionContext* vhdlParser::enumeration_type_definition() {
  Enumeration_type_definitionContext *_localctx = _tracker.createInstance<Enumeration_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 200, vhdlParser::RuleEnumeration_type_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1359);
    match(vhdlParser::LPAREN);
    setState(1360);
    enumeration_literal();
    setState(1365);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1361);
      match(vhdlParser::COMMA);
      setState(1362);
      enumeration_literal();
      setState(1367);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1368);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Exit_statementContext ------------------------------------------------------------------

vhdlParser::Exit_statementContext::Exit_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Exit_statementContext::EXIT() {
  return getToken(vhdlParser::EXIT, 0);
}

tree::TerminalNode* vhdlParser::Exit_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Exit_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::IdentifierContext* vhdlParser::Exit_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Exit_statementContext::WHEN() {
  return getToken(vhdlParser::WHEN, 0);
}

vhdlParser::ConditionContext* vhdlParser::Exit_statementContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}


size_t vhdlParser::Exit_statementContext::getRuleIndex() const {
  return vhdlParser::RuleExit_statement;
}

antlrcpp::Any vhdlParser::Exit_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitExit_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Exit_statementContext* vhdlParser::exit_statement() {
  Exit_statementContext *_localctx = _tracker.createInstance<Exit_statementContext>(_ctx, getState());
  enterRule(_localctx, 202, vhdlParser::RuleExit_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1371);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1370);
      label_colon();
    }
    setState(1373);
    match(vhdlParser::EXIT);
    setState(1375);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1374);
      identifier();
    }
    setState(1379);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::WHEN) {
      setState(1377);
      match(vhdlParser::WHEN);
      setState(1378);
      condition();
    }
    setState(1381);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

vhdlParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::ExpressionContext::CONDITION_OPERATOR() {
  return getToken(vhdlParser::CONDITION_OPERATOR, 0);
}

vhdlParser::PrimaryContext* vhdlParser::ExpressionContext::primary() {
  return getRuleContext<vhdlParser::PrimaryContext>(0);
}

vhdlParser::Logical_expressionContext* vhdlParser::ExpressionContext::logical_expression() {
  return getRuleContext<vhdlParser::Logical_expressionContext>(0);
}


size_t vhdlParser::ExpressionContext::getRuleIndex() const {
  return vhdlParser::RuleExpression;
}

antlrcpp::Any vhdlParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::ExpressionContext* vhdlParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 204, vhdlParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1386);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::CONDITION_OPERATOR: {
        enterOuterAlt(_localctx, 1);
        setState(1383);
        match(vhdlParser::CONDITION_OPERATOR);
        setState(1384);
        primary();
        break;
      }

      case vhdlParser::ABS:
      case vhdlParser::NEW:
      case vhdlParser::NOT:
      case vhdlParser::NULL_SYM:
      case vhdlParser::BASE_LITERAL:
      case vhdlParser::BIT_STRING_LITERAL:
      case vhdlParser::REAL_LITERAL:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::LPAREN:
      case vhdlParser::PLUS:
      case vhdlParser::MINUS:
      case vhdlParser::INTEGER: {
        enterOuterAlt(_localctx, 2);
        setState(1385);
        logical_expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_expressionContext ------------------------------------------------------------------

vhdlParser::Logical_expressionContext::Logical_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::RelationContext *> vhdlParser::Logical_expressionContext::relation() {
  return getRuleContexts<vhdlParser::RelationContext>();
}

vhdlParser::RelationContext* vhdlParser::Logical_expressionContext::relation(size_t i) {
  return getRuleContext<vhdlParser::RelationContext>(i);
}

std::vector<vhdlParser::Logical_operatorContext *> vhdlParser::Logical_expressionContext::logical_operator() {
  return getRuleContexts<vhdlParser::Logical_operatorContext>();
}

vhdlParser::Logical_operatorContext* vhdlParser::Logical_expressionContext::logical_operator(size_t i) {
  return getRuleContext<vhdlParser::Logical_operatorContext>(i);
}


size_t vhdlParser::Logical_expressionContext::getRuleIndex() const {
  return vhdlParser::RuleLogical_expression;
}

antlrcpp::Any vhdlParser::Logical_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitLogical_expression(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Logical_expressionContext* vhdlParser::logical_expression() {
  Logical_expressionContext *_localctx = _tracker.createInstance<Logical_expressionContext>(_ctx, getState());
  enterRule(_localctx, 206, vhdlParser::RuleLogical_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1388);
    relation();
    setState(1394);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1389);
        logical_operator();
        setState(1390);
        relation(); 
      }
      setState(1396);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

vhdlParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::PrimaryContext *> vhdlParser::FactorContext::primary() {
  return getRuleContexts<vhdlParser::PrimaryContext>();
}

vhdlParser::PrimaryContext* vhdlParser::FactorContext::primary(size_t i) {
  return getRuleContext<vhdlParser::PrimaryContext>(i);
}

tree::TerminalNode* vhdlParser::FactorContext::DOUBLESTAR() {
  return getToken(vhdlParser::DOUBLESTAR, 0);
}

tree::TerminalNode* vhdlParser::FactorContext::ABS() {
  return getToken(vhdlParser::ABS, 0);
}

tree::TerminalNode* vhdlParser::FactorContext::NOT() {
  return getToken(vhdlParser::NOT, 0);
}


size_t vhdlParser::FactorContext::getRuleIndex() const {
  return vhdlParser::RuleFactor;
}

antlrcpp::Any vhdlParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::FactorContext* vhdlParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 208, vhdlParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1406);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::NEW:
      case vhdlParser::NULL_SYM:
      case vhdlParser::BASE_LITERAL:
      case vhdlParser::BIT_STRING_LITERAL:
      case vhdlParser::REAL_LITERAL:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::LPAREN:
      case vhdlParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(1397);
        primary();
        setState(1400);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx)) {
        case 1: {
          setState(1398);
          match(vhdlParser::DOUBLESTAR);
          setState(1399);
          primary();
          break;
        }

        }
        break;
      }

      case vhdlParser::ABS: {
        enterOuterAlt(_localctx, 2);
        setState(1402);
        match(vhdlParser::ABS);
        setState(1403);
        primary();
        break;
      }

      case vhdlParser::NOT: {
        enterOuterAlt(_localctx, 3);
        setState(1404);
        match(vhdlParser::NOT);
        setState(1405);
        primary();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- File_declarationContext ------------------------------------------------------------------

vhdlParser::File_declarationContext::File_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::File_declarationContext::FILE() {
  return getToken(vhdlParser::FILE, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::File_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::File_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::File_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::File_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::File_open_informationContext* vhdlParser::File_declarationContext::file_open_information() {
  return getRuleContext<vhdlParser::File_open_informationContext>(0);
}


size_t vhdlParser::File_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleFile_declaration;
}

antlrcpp::Any vhdlParser::File_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitFile_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::File_declarationContext* vhdlParser::file_declaration() {
  File_declarationContext *_localctx = _tracker.createInstance<File_declarationContext>(_ctx, getState());
  enterRule(_localctx, 210, vhdlParser::RuleFile_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1408);
    match(vhdlParser::FILE);
    setState(1409);
    identifier_list();
    setState(1410);
    match(vhdlParser::COLON);
    setState(1411);
    subtype_indication();
    setState(1413);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IS

    || _la == vhdlParser::OPEN) {
      setState(1412);
      file_open_information();
    }
    setState(1415);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- File_logical_nameContext ------------------------------------------------------------------

vhdlParser::File_logical_nameContext::File_logical_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::ExpressionContext* vhdlParser::File_logical_nameContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::File_logical_nameContext::getRuleIndex() const {
  return vhdlParser::RuleFile_logical_name;
}

antlrcpp::Any vhdlParser::File_logical_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitFile_logical_name(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::File_logical_nameContext* vhdlParser::file_logical_name() {
  File_logical_nameContext *_localctx = _tracker.createInstance<File_logical_nameContext>(_ctx, getState());
  enterRule(_localctx, 212, vhdlParser::RuleFile_logical_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1417);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- File_open_informationContext ------------------------------------------------------------------

vhdlParser::File_open_informationContext::File_open_informationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::File_open_informationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::File_logical_nameContext* vhdlParser::File_open_informationContext::file_logical_name() {
  return getRuleContext<vhdlParser::File_logical_nameContext>(0);
}

tree::TerminalNode* vhdlParser::File_open_informationContext::OPEN() {
  return getToken(vhdlParser::OPEN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::File_open_informationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::File_open_informationContext::getRuleIndex() const {
  return vhdlParser::RuleFile_open_information;
}

antlrcpp::Any vhdlParser::File_open_informationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitFile_open_information(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::File_open_informationContext* vhdlParser::file_open_information() {
  File_open_informationContext *_localctx = _tracker.createInstance<File_open_informationContext>(_ctx, getState());
  enterRule(_localctx, 214, vhdlParser::RuleFile_open_information);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1421);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::OPEN) {
      setState(1419);
      match(vhdlParser::OPEN);
      setState(1420);
      expression();
    }
    setState(1423);
    match(vhdlParser::IS);
    setState(1424);
    file_logical_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- File_type_definitionContext ------------------------------------------------------------------

vhdlParser::File_type_definitionContext::File_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::File_type_definitionContext::FILE() {
  return getToken(vhdlParser::FILE, 0);
}

tree::TerminalNode* vhdlParser::File_type_definitionContext::OF() {
  return getToken(vhdlParser::OF, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::File_type_definitionContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::File_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleFile_type_definition;
}

antlrcpp::Any vhdlParser::File_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitFile_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::File_type_definitionContext* vhdlParser::file_type_definition() {
  File_type_definitionContext *_localctx = _tracker.createInstance<File_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 216, vhdlParser::RuleFile_type_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1426);
    match(vhdlParser::FILE);
    setState(1427);
    match(vhdlParser::OF);
    setState(1428);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formal_parameter_listContext ------------------------------------------------------------------

vhdlParser::Formal_parameter_listContext::Formal_parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_listContext* vhdlParser::Formal_parameter_listContext::interface_list() {
  return getRuleContext<vhdlParser::Interface_listContext>(0);
}


size_t vhdlParser::Formal_parameter_listContext::getRuleIndex() const {
  return vhdlParser::RuleFormal_parameter_list;
}

antlrcpp::Any vhdlParser::Formal_parameter_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitFormal_parameter_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Formal_parameter_listContext* vhdlParser::formal_parameter_list() {
  Formal_parameter_listContext *_localctx = _tracker.createInstance<Formal_parameter_listContext>(_ctx, getState());
  enterRule(_localctx, 218, vhdlParser::RuleFormal_parameter_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1430);
    interface_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formal_partContext ------------------------------------------------------------------

vhdlParser::Formal_partContext::Formal_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Formal_partContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Formal_partContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

tree::TerminalNode* vhdlParser::Formal_partContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Formal_partContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

vhdlParser::Explicit_rangeContext* vhdlParser::Formal_partContext::explicit_range() {
  return getRuleContext<vhdlParser::Explicit_rangeContext>(0);
}


size_t vhdlParser::Formal_partContext::getRuleIndex() const {
  return vhdlParser::RuleFormal_part;
}

antlrcpp::Any vhdlParser::Formal_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitFormal_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Formal_partContext* vhdlParser::formal_part() {
  Formal_partContext *_localctx = _tracker.createInstance<Formal_partContext>(_ctx, getState());
  enterRule(_localctx, 220, vhdlParser::RuleFormal_part);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1441);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 133, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1432);
      identifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1433);
      identifier();
      setState(1434);
      match(vhdlParser::LPAREN);
      setState(1437);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx)) {
      case 1: {
        setState(1435);
        expression();
        break;
      }

      case 2: {
        setState(1436);
        explicit_range();
        break;
      }

      }
      setState(1439);
      match(vhdlParser::RPAREN);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Free_quantity_declarationContext ------------------------------------------------------------------

vhdlParser::Free_quantity_declarationContext::Free_quantity_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Free_quantity_declarationContext::QUANTITY() {
  return getToken(vhdlParser::QUANTITY, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Free_quantity_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Free_quantity_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Free_quantity_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Free_quantity_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Free_quantity_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Free_quantity_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Free_quantity_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleFree_quantity_declaration;
}

antlrcpp::Any vhdlParser::Free_quantity_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitFree_quantity_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Free_quantity_declarationContext* vhdlParser::free_quantity_declaration() {
  Free_quantity_declarationContext *_localctx = _tracker.createInstance<Free_quantity_declarationContext>(_ctx, getState());
  enterRule(_localctx, 222, vhdlParser::RuleFree_quantity_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1443);
    match(vhdlParser::QUANTITY);
    setState(1444);
    identifier_list();
    setState(1445);
    match(vhdlParser::COLON);
    setState(1446);
    subtype_indication();
    setState(1449);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1447);
      match(vhdlParser::VARASGN);
      setState(1448);
      expression();
    }
    setState(1451);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generate_statementContext ------------------------------------------------------------------

vhdlParser::Generate_statementContext::Generate_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::For_generate_statementContext* vhdlParser::Generate_statementContext::for_generate_statement() {
  return getRuleContext<vhdlParser::For_generate_statementContext>(0);
}

vhdlParser::If_generate_statementContext* vhdlParser::Generate_statementContext::if_generate_statement() {
  return getRuleContext<vhdlParser::If_generate_statementContext>(0);
}

vhdlParser::Case_generate_statementContext* vhdlParser::Generate_statementContext::case_generate_statement() {
  return getRuleContext<vhdlParser::Case_generate_statementContext>(0);
}


size_t vhdlParser::Generate_statementContext::getRuleIndex() const {
  return vhdlParser::RuleGenerate_statement;
}

antlrcpp::Any vhdlParser::Generate_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitGenerate_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generate_statementContext* vhdlParser::generate_statement() {
  Generate_statementContext *_localctx = _tracker.createInstance<Generate_statementContext>(_ctx, getState());
  enterRule(_localctx, 224, vhdlParser::RuleGenerate_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1456);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 135, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1453);
      for_generate_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1454);
      if_generate_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1455);
      case_generate_statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_generate_statementContext ------------------------------------------------------------------

vhdlParser::For_generate_statementContext::For_generate_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Label_colonContext* vhdlParser::For_generate_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

tree::TerminalNode* vhdlParser::For_generate_statementContext::FOR() {
  return getToken(vhdlParser::FOR, 0);
}

vhdlParser::Parameter_specificationContext* vhdlParser::For_generate_statementContext::parameter_specification() {
  return getRuleContext<vhdlParser::Parameter_specificationContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::For_generate_statementContext::GENERATE() {
  return getTokens(vhdlParser::GENERATE);
}

tree::TerminalNode* vhdlParser::For_generate_statementContext::GENERATE(size_t i) {
  return getToken(vhdlParser::GENERATE, i);
}

vhdlParser::Generate_statement_bodyContext* vhdlParser::For_generate_statementContext::generate_statement_body() {
  return getRuleContext<vhdlParser::Generate_statement_bodyContext>(0);
}

tree::TerminalNode* vhdlParser::For_generate_statementContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::For_generate_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::IdentifierContext* vhdlParser::For_generate_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::For_generate_statementContext::getRuleIndex() const {
  return vhdlParser::RuleFor_generate_statement;
}

antlrcpp::Any vhdlParser::For_generate_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitFor_generate_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::For_generate_statementContext* vhdlParser::for_generate_statement() {
  For_generate_statementContext *_localctx = _tracker.createInstance<For_generate_statementContext>(_ctx, getState());
  enterRule(_localctx, 226, vhdlParser::RuleFor_generate_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1458);
    label_colon();
    setState(1459);
    match(vhdlParser::FOR);
    setState(1460);
    parameter_specification();
    setState(1461);
    match(vhdlParser::GENERATE);
    setState(1462);
    generate_statement_body();
    setState(1463);
    match(vhdlParser::END);
    setState(1464);
    match(vhdlParser::GENERATE);
    setState(1466);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1465);
      identifier();
    }
    setState(1468);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_generate_statementContext ------------------------------------------------------------------

vhdlParser::If_generate_statementContext::If_generate_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::IF() {
  return getToken(vhdlParser::IF, 0);
}

std::vector<vhdlParser::ConditionContext *> vhdlParser::If_generate_statementContext::condition() {
  return getRuleContexts<vhdlParser::ConditionContext>();
}

vhdlParser::ConditionContext* vhdlParser::If_generate_statementContext::condition(size_t i) {
  return getRuleContext<vhdlParser::ConditionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::If_generate_statementContext::GENERATE() {
  return getTokens(vhdlParser::GENERATE);
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::GENERATE(size_t i) {
  return getToken(vhdlParser::GENERATE, i);
}

std::vector<vhdlParser::Generate_statement_bodyContext *> vhdlParser::If_generate_statementContext::generate_statement_body() {
  return getRuleContexts<vhdlParser::Generate_statement_bodyContext>();
}

vhdlParser::Generate_statement_bodyContext* vhdlParser::If_generate_statementContext::generate_statement_body(size_t i) {
  return getRuleContext<vhdlParser::Generate_statement_bodyContext>(i);
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::If_generate_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::If_generate_statementContext::ELSIF() {
  return getTokens(vhdlParser::ELSIF);
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::ELSIF(size_t i) {
  return getToken(vhdlParser::ELSIF, i);
}

tree::TerminalNode* vhdlParser::If_generate_statementContext::ELSE() {
  return getToken(vhdlParser::ELSE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::If_generate_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::If_generate_statementContext::getRuleIndex() const {
  return vhdlParser::RuleIf_generate_statement;
}

antlrcpp::Any vhdlParser::If_generate_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitIf_generate_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::If_generate_statementContext* vhdlParser::if_generate_statement() {
  If_generate_statementContext *_localctx = _tracker.createInstance<If_generate_statementContext>(_ctx, getState());
  enterRule(_localctx, 228, vhdlParser::RuleIf_generate_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1471);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1470);
      label_colon();
    }
    setState(1473);
    match(vhdlParser::IF);
    setState(1474);
    condition();
    setState(1475);
    match(vhdlParser::GENERATE);
    setState(1476);
    generate_statement_body();
    setState(1484);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::ELSIF) {
      setState(1477);
      match(vhdlParser::ELSIF);
      setState(1478);
      condition();
      setState(1479);
      match(vhdlParser::GENERATE);
      setState(1480);
      generate_statement_body();
      setState(1486);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1490);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::ELSE) {
      setState(1487);
      match(vhdlParser::ELSE);
      setState(1488);
      match(vhdlParser::GENERATE);
      setState(1489);
      generate_statement_body();
    }
    setState(1492);
    match(vhdlParser::END);
    setState(1493);
    match(vhdlParser::GENERATE);
    setState(1495);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1494);
      identifier();
    }
    setState(1497);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_generate_statementContext ------------------------------------------------------------------

vhdlParser::Case_generate_statementContext::Case_generate_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Case_generate_statementContext::CASE() {
  return getToken(vhdlParser::CASE, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Case_generate_statementContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Case_generate_statementContext::GENERATE() {
  return getTokens(vhdlParser::GENERATE);
}

tree::TerminalNode* vhdlParser::Case_generate_statementContext::GENERATE(size_t i) {
  return getToken(vhdlParser::GENERATE, i);
}

tree::TerminalNode* vhdlParser::Case_generate_statementContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Case_generate_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Case_generate_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

std::vector<vhdlParser::Case_generate_alternativeContext *> vhdlParser::Case_generate_statementContext::case_generate_alternative() {
  return getRuleContexts<vhdlParser::Case_generate_alternativeContext>();
}

vhdlParser::Case_generate_alternativeContext* vhdlParser::Case_generate_statementContext::case_generate_alternative(size_t i) {
  return getRuleContext<vhdlParser::Case_generate_alternativeContext>(i);
}

vhdlParser::IdentifierContext* vhdlParser::Case_generate_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Case_generate_statementContext::getRuleIndex() const {
  return vhdlParser::RuleCase_generate_statement;
}

antlrcpp::Any vhdlParser::Case_generate_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitCase_generate_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Case_generate_statementContext* vhdlParser::case_generate_statement() {
  Case_generate_statementContext *_localctx = _tracker.createInstance<Case_generate_statementContext>(_ctx, getState());
  enterRule(_localctx, 230, vhdlParser::RuleCase_generate_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1500);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1499);
      label_colon();
    }
    setState(1502);
    match(vhdlParser::CASE);
    setState(1503);
    expression();
    setState(1504);
    match(vhdlParser::GENERATE);
    setState(1506); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1505);
      case_generate_alternative();
      setState(1508); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == vhdlParser::WHEN);
    setState(1510);
    match(vhdlParser::END);
    setState(1511);
    match(vhdlParser::GENERATE);
    setState(1513);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1512);
      identifier();
    }
    setState(1515);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_generate_alternativeContext ------------------------------------------------------------------

vhdlParser::Case_generate_alternativeContext::Case_generate_alternativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Case_generate_alternativeContext::WHEN() {
  return getToken(vhdlParser::WHEN, 0);
}

vhdlParser::ChoicesContext* vhdlParser::Case_generate_alternativeContext::choices() {
  return getRuleContext<vhdlParser::ChoicesContext>(0);
}

tree::TerminalNode* vhdlParser::Case_generate_alternativeContext::ARROW() {
  return getToken(vhdlParser::ARROW, 0);
}

vhdlParser::Generate_statement_bodyContext* vhdlParser::Case_generate_alternativeContext::generate_statement_body() {
  return getRuleContext<vhdlParser::Generate_statement_bodyContext>(0);
}


size_t vhdlParser::Case_generate_alternativeContext::getRuleIndex() const {
  return vhdlParser::RuleCase_generate_alternative;
}

antlrcpp::Any vhdlParser::Case_generate_alternativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitCase_generate_alternative(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Case_generate_alternativeContext* vhdlParser::case_generate_alternative() {
  Case_generate_alternativeContext *_localctx = _tracker.createInstance<Case_generate_alternativeContext>(_ctx, getState());
  enterRule(_localctx, 232, vhdlParser::RuleCase_generate_alternative);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1517);
    match(vhdlParser::WHEN);
    setState(1518);
    choices();
    setState(1519);
    match(vhdlParser::ARROW);
    setState(1520);
    generate_statement_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generate_statement_bodyContext ------------------------------------------------------------------

vhdlParser::Generate_statement_bodyContext::Generate_statement_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Generate_statement_bodyContext::BEGIN() {
  return getToken(vhdlParser::BEGIN, 0);
}

std::vector<vhdlParser::Architecture_statementContext *> vhdlParser::Generate_statement_bodyContext::architecture_statement() {
  return getRuleContexts<vhdlParser::Architecture_statementContext>();
}

vhdlParser::Architecture_statementContext* vhdlParser::Generate_statement_bodyContext::architecture_statement(size_t i) {
  return getRuleContext<vhdlParser::Architecture_statementContext>(i);
}

std::vector<vhdlParser::Block_declarative_itemContext *> vhdlParser::Generate_statement_bodyContext::block_declarative_item() {
  return getRuleContexts<vhdlParser::Block_declarative_itemContext>();
}

vhdlParser::Block_declarative_itemContext* vhdlParser::Generate_statement_bodyContext::block_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Block_declarative_itemContext>(i);
}


size_t vhdlParser::Generate_statement_bodyContext::getRuleIndex() const {
  return vhdlParser::RuleGenerate_statement_body;
}

antlrcpp::Any vhdlParser::Generate_statement_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitGenerate_statement_body(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generate_statement_bodyContext* vhdlParser::generate_statement_body() {
  Generate_statement_bodyContext *_localctx = _tracker.createInstance<Generate_statement_bodyContext>(_ctx, getState());
  enterRule(_localctx, 234, vhdlParser::RuleGenerate_statement_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1529);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ALIAS)
      | (1ULL << vhdlParser::ATTRIBUTE)
      | (1ULL << vhdlParser::BEGIN)
      | (1ULL << vhdlParser::COMPONENT)
      | (1ULL << vhdlParser::CONSTANT)
      | (1ULL << vhdlParser::DISCONNECT)
      | (1ULL << vhdlParser::FILE)
      | (1ULL << vhdlParser::FOR)
      | (1ULL << vhdlParser::FUNCTION)
      | (1ULL << vhdlParser::GROUP)
      | (1ULL << vhdlParser::IMPURE)
      | (1ULL << vhdlParser::LIMIT)
      | (1ULL << vhdlParser::NATURE))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (vhdlParser::PROCEDURE - 69))
      | (1ULL << (vhdlParser::PURE - 69))
      | (1ULL << (vhdlParser::QUANTITY - 69))
      | (1ULL << (vhdlParser::SHARED - 69))
      | (1ULL << (vhdlParser::SIGNAL - 69))
      | (1ULL << (vhdlParser::SUBNATURE - 69))
      | (1ULL << (vhdlParser::SUBTYPE - 69))
      | (1ULL << (vhdlParser::TERMINAL - 69))
      | (1ULL << (vhdlParser::TYPE - 69))
      | (1ULL << (vhdlParser::USE - 69))
      | (1ULL << (vhdlParser::VARIABLE - 69)))) != 0)) {
      setState(1525);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << vhdlParser::ALIAS)
        | (1ULL << vhdlParser::ATTRIBUTE)
        | (1ULL << vhdlParser::COMPONENT)
        | (1ULL << vhdlParser::CONSTANT)
        | (1ULL << vhdlParser::DISCONNECT)
        | (1ULL << vhdlParser::FILE)
        | (1ULL << vhdlParser::FOR)
        | (1ULL << vhdlParser::FUNCTION)
        | (1ULL << vhdlParser::GROUP)
        | (1ULL << vhdlParser::IMPURE)
        | (1ULL << vhdlParser::LIMIT)
        | (1ULL << vhdlParser::NATURE))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 69)) & ((1ULL << (vhdlParser::PROCEDURE - 69))
        | (1ULL << (vhdlParser::PURE - 69))
        | (1ULL << (vhdlParser::QUANTITY - 69))
        | (1ULL << (vhdlParser::SHARED - 69))
        | (1ULL << (vhdlParser::SIGNAL - 69))
        | (1ULL << (vhdlParser::SUBNATURE - 69))
        | (1ULL << (vhdlParser::SUBTYPE - 69))
        | (1ULL << (vhdlParser::TERMINAL - 69))
        | (1ULL << (vhdlParser::TYPE - 69))
        | (1ULL << (vhdlParser::USE - 69))
        | (1ULL << (vhdlParser::VARIABLE - 69)))) != 0)) {
        setState(1522);
        block_declarative_item();
        setState(1527);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1528);
      match(vhdlParser::BEGIN);
    }
    setState(1534);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ABS)
      | (1ULL << vhdlParser::ASSERT)
      | (1ULL << vhdlParser::BREAK)
      | (1ULL << vhdlParser::CASE)
      | (1ULL << vhdlParser::IF)
      | (1ULL << vhdlParser::NEW)
      | (1ULL << vhdlParser::NOT)
      | (1ULL << vhdlParser::NULL_SYM))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (vhdlParser::POSTPONED - 67))
      | (1ULL << (vhdlParser::PROCESS - 67))
      | (1ULL << (vhdlParser::PROCEDURAL - 67))
      | (1ULL << (vhdlParser::WITH - 67))
      | (1ULL << (vhdlParser::BASE_LITERAL - 67))
      | (1ULL << (vhdlParser::BIT_STRING_LITERAL - 67))
      | (1ULL << (vhdlParser::REAL_LITERAL - 67))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 67))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 67)))) != 0) || ((((_la - 131) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 131)) & ((1ULL << (vhdlParser::CHARACTER_LITERAL - 131))
      | (1ULL << (vhdlParser::STRING_LITERAL - 131))
      | (1ULL << (vhdlParser::LPAREN - 131))
      | (1ULL << (vhdlParser::PLUS - 131))
      | (1ULL << (vhdlParser::MINUS - 131))
      | (1ULL << (vhdlParser::INTEGER - 131)))) != 0)) {
      setState(1531);
      architecture_statement();
      setState(1536);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generation_schemeContext ------------------------------------------------------------------

vhdlParser::Generation_schemeContext::Generation_schemeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Generation_schemeContext::FOR() {
  return getToken(vhdlParser::FOR, 0);
}

vhdlParser::Parameter_specificationContext* vhdlParser::Generation_schemeContext::parameter_specification() {
  return getRuleContext<vhdlParser::Parameter_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Generation_schemeContext::IF() {
  return getToken(vhdlParser::IF, 0);
}

vhdlParser::ConditionContext* vhdlParser::Generation_schemeContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}

tree::TerminalNode* vhdlParser::Generation_schemeContext::CASE() {
  return getToken(vhdlParser::CASE, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Generation_schemeContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Generation_schemeContext::getRuleIndex() const {
  return vhdlParser::RuleGeneration_scheme;
}

antlrcpp::Any vhdlParser::Generation_schemeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitGeneration_scheme(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generation_schemeContext* vhdlParser::generation_scheme() {
  Generation_schemeContext *_localctx = _tracker.createInstance<Generation_schemeContext>(_ctx, getState());
  enterRule(_localctx, 236, vhdlParser::RuleGeneration_scheme);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1543);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::FOR: {
        enterOuterAlt(_localctx, 1);
        setState(1537);
        match(vhdlParser::FOR);
        setState(1538);
        parameter_specification();
        break;
      }

      case vhdlParser::IF: {
        enterOuterAlt(_localctx, 2);
        setState(1539);
        match(vhdlParser::IF);
        setState(1540);
        condition();
        break;
      }

      case vhdlParser::CASE: {
        enterOuterAlt(_localctx, 3);
        setState(1541);
        match(vhdlParser::CASE);
        setState(1542);
        expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generic_clauseContext ------------------------------------------------------------------

vhdlParser::Generic_clauseContext::Generic_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Generic_clauseContext::GENERIC() {
  return getToken(vhdlParser::GENERIC, 0);
}

tree::TerminalNode* vhdlParser::Generic_clauseContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Generic_listContext* vhdlParser::Generic_clauseContext::generic_list() {
  return getRuleContext<vhdlParser::Generic_listContext>(0);
}

tree::TerminalNode* vhdlParser::Generic_clauseContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Generic_clauseContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Generic_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleGeneric_clause;
}

antlrcpp::Any vhdlParser::Generic_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitGeneric_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generic_clauseContext* vhdlParser::generic_clause() {
  Generic_clauseContext *_localctx = _tracker.createInstance<Generic_clauseContext>(_ctx, getState());
  enterRule(_localctx, 238, vhdlParser::RuleGeneric_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1545);
    match(vhdlParser::GENERIC);
    setState(1546);
    match(vhdlParser::LPAREN);
    setState(1547);
    generic_list();
    setState(1548);
    match(vhdlParser::RPAREN);
    setState(1549);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generic_listContext ------------------------------------------------------------------

vhdlParser::Generic_listContext::Generic_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Interface_constant_declarationContext *> vhdlParser::Generic_listContext::interface_constant_declaration() {
  return getRuleContexts<vhdlParser::Interface_constant_declarationContext>();
}

vhdlParser::Interface_constant_declarationContext* vhdlParser::Generic_listContext::interface_constant_declaration(size_t i) {
  return getRuleContext<vhdlParser::Interface_constant_declarationContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Generic_listContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Generic_listContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}


size_t vhdlParser::Generic_listContext::getRuleIndex() const {
  return vhdlParser::RuleGeneric_list;
}

antlrcpp::Any vhdlParser::Generic_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitGeneric_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generic_listContext* vhdlParser::generic_list() {
  Generic_listContext *_localctx = _tracker.createInstance<Generic_listContext>(_ctx, getState());
  enterRule(_localctx, 240, vhdlParser::RuleGeneric_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1551);
    interface_constant_declaration();
    setState(1556);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::SEMI) {
      setState(1552);
      match(vhdlParser::SEMI);
      setState(1553);
      interface_constant_declaration();
      setState(1558);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Generic_map_aspectContext ------------------------------------------------------------------

vhdlParser::Generic_map_aspectContext::Generic_map_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Generic_map_aspectContext::GENERIC() {
  return getToken(vhdlParser::GENERIC, 0);
}

tree::TerminalNode* vhdlParser::Generic_map_aspectContext::MAP() {
  return getToken(vhdlParser::MAP, 0);
}

tree::TerminalNode* vhdlParser::Generic_map_aspectContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Association_listContext* vhdlParser::Generic_map_aspectContext::association_list() {
  return getRuleContext<vhdlParser::Association_listContext>(0);
}

tree::TerminalNode* vhdlParser::Generic_map_aspectContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Generic_map_aspectContext::getRuleIndex() const {
  return vhdlParser::RuleGeneric_map_aspect;
}

antlrcpp::Any vhdlParser::Generic_map_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitGeneric_map_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Generic_map_aspectContext* vhdlParser::generic_map_aspect() {
  Generic_map_aspectContext *_localctx = _tracker.createInstance<Generic_map_aspectContext>(_ctx, getState());
  enterRule(_localctx, 242, vhdlParser::RuleGeneric_map_aspect);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1559);
    match(vhdlParser::GENERIC);
    setState(1560);
    match(vhdlParser::MAP);
    setState(1561);
    match(vhdlParser::LPAREN);
    setState(1562);
    association_list();
    setState(1563);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Group_constituentContext ------------------------------------------------------------------

vhdlParser::Group_constituentContext::Group_constituentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Group_constituentContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Group_constituentContext::CHARACTER_LITERAL() {
  return getToken(vhdlParser::CHARACTER_LITERAL, 0);
}


size_t vhdlParser::Group_constituentContext::getRuleIndex() const {
  return vhdlParser::RuleGroup_constituent;
}

antlrcpp::Any vhdlParser::Group_constituentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitGroup_constituent(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Group_constituentContext* vhdlParser::group_constituent() {
  Group_constituentContext *_localctx = _tracker.createInstance<Group_constituentContext>(_ctx, getState());
  enterRule(_localctx, 244, vhdlParser::RuleGroup_constituent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1567);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1565);
        name();
        break;
      }

      case vhdlParser::CHARACTER_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1566);
        match(vhdlParser::CHARACTER_LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Group_constituent_listContext ------------------------------------------------------------------

vhdlParser::Group_constituent_listContext::Group_constituent_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Group_constituentContext *> vhdlParser::Group_constituent_listContext::group_constituent() {
  return getRuleContexts<vhdlParser::Group_constituentContext>();
}

vhdlParser::Group_constituentContext* vhdlParser::Group_constituent_listContext::group_constituent(size_t i) {
  return getRuleContext<vhdlParser::Group_constituentContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Group_constituent_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Group_constituent_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Group_constituent_listContext::getRuleIndex() const {
  return vhdlParser::RuleGroup_constituent_list;
}

antlrcpp::Any vhdlParser::Group_constituent_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitGroup_constituent_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Group_constituent_listContext* vhdlParser::group_constituent_list() {
  Group_constituent_listContext *_localctx = _tracker.createInstance<Group_constituent_listContext>(_ctx, getState());
  enterRule(_localctx, 246, vhdlParser::RuleGroup_constituent_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1569);
    group_constituent();
    setState(1574);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1570);
      match(vhdlParser::COMMA);
      setState(1571);
      group_constituent();
      setState(1576);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Group_declarationContext ------------------------------------------------------------------

vhdlParser::Group_declarationContext::Group_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Group_declarationContext::GROUP() {
  return getToken(vhdlParser::GROUP, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Group_declarationContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::NameContext* vhdlParser::Group_declarationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Group_declarationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Group_constituent_listContext* vhdlParser::Group_declarationContext::group_constituent_list() {
  return getRuleContext<vhdlParser::Group_constituent_listContext>(0);
}

tree::TerminalNode* vhdlParser::Group_declarationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Group_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Group_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleGroup_declaration;
}

antlrcpp::Any vhdlParser::Group_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitGroup_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Group_declarationContext* vhdlParser::group_declaration() {
  Group_declarationContext *_localctx = _tracker.createInstance<Group_declarationContext>(_ctx, getState());
  enterRule(_localctx, 248, vhdlParser::RuleGroup_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1577);
    match(vhdlParser::GROUP);
    setState(1578);
    label_colon();
    setState(1579);
    name();
    setState(1580);
    match(vhdlParser::LPAREN);
    setState(1581);
    group_constituent_list();
    setState(1582);
    match(vhdlParser::RPAREN);
    setState(1583);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Group_template_declarationContext ------------------------------------------------------------------

vhdlParser::Group_template_declarationContext::Group_template_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Group_template_declarationContext::GROUP() {
  return getToken(vhdlParser::GROUP, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Group_template_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Group_template_declarationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

tree::TerminalNode* vhdlParser::Group_template_declarationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Entity_class_entry_listContext* vhdlParser::Group_template_declarationContext::entity_class_entry_list() {
  return getRuleContext<vhdlParser::Entity_class_entry_listContext>(0);
}

tree::TerminalNode* vhdlParser::Group_template_declarationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Group_template_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Group_template_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleGroup_template_declaration;
}

antlrcpp::Any vhdlParser::Group_template_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitGroup_template_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Group_template_declarationContext* vhdlParser::group_template_declaration() {
  Group_template_declarationContext *_localctx = _tracker.createInstance<Group_template_declarationContext>(_ctx, getState());
  enterRule(_localctx, 250, vhdlParser::RuleGroup_template_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1585);
    match(vhdlParser::GROUP);
    setState(1586);
    identifier();
    setState(1587);
    match(vhdlParser::IS);
    setState(1588);
    match(vhdlParser::LPAREN);
    setState(1589);
    entity_class_entry_list();
    setState(1590);
    match(vhdlParser::RPAREN);
    setState(1591);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Guarded_signal_specificationContext ------------------------------------------------------------------

vhdlParser::Guarded_signal_specificationContext::Guarded_signal_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Signal_listContext* vhdlParser::Guarded_signal_specificationContext::signal_list() {
  return getRuleContext<vhdlParser::Signal_listContext>(0);
}

tree::TerminalNode* vhdlParser::Guarded_signal_specificationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::NameContext* vhdlParser::Guarded_signal_specificationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}


size_t vhdlParser::Guarded_signal_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleGuarded_signal_specification;
}

antlrcpp::Any vhdlParser::Guarded_signal_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitGuarded_signal_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Guarded_signal_specificationContext* vhdlParser::guarded_signal_specification() {
  Guarded_signal_specificationContext *_localctx = _tracker.createInstance<Guarded_signal_specificationContext>(_ctx, getState());
  enterRule(_localctx, 252, vhdlParser::RuleGuarded_signal_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1593);
    signal_list();
    setState(1594);
    match(vhdlParser::COLON);
    setState(1595);
    name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

vhdlParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::IdentifierContext::BASIC_IDENTIFIER() {
  return getToken(vhdlParser::BASIC_IDENTIFIER, 0);
}

tree::TerminalNode* vhdlParser::IdentifierContext::EXTENDED_IDENTIFIER() {
  return getToken(vhdlParser::EXTENDED_IDENTIFIER, 0);
}


size_t vhdlParser::IdentifierContext::getRuleIndex() const {
  return vhdlParser::RuleIdentifier;
}

antlrcpp::Any vhdlParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::IdentifierContext* vhdlParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 254, vhdlParser::RuleIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1597);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Identifier_listContext ------------------------------------------------------------------

vhdlParser::Identifier_listContext::Identifier_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Identifier_listContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Identifier_listContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Identifier_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Identifier_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Identifier_listContext::getRuleIndex() const {
  return vhdlParser::RuleIdentifier_list;
}

antlrcpp::Any vhdlParser::Identifier_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitIdentifier_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Identifier_listContext* vhdlParser::identifier_list() {
  Identifier_listContext *_localctx = _tracker.createInstance<Identifier_listContext>(_ctx, getState());
  enterRule(_localctx, 256, vhdlParser::RuleIdentifier_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1599);
    identifier();
    setState(1604);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1600);
      match(vhdlParser::COMMA);
      setState(1601);
      identifier();
      setState(1606);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

vhdlParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::If_statementContext::IF() {
  return getTokens(vhdlParser::IF);
}

tree::TerminalNode* vhdlParser::If_statementContext::IF(size_t i) {
  return getToken(vhdlParser::IF, i);
}

std::vector<vhdlParser::ConditionContext *> vhdlParser::If_statementContext::condition() {
  return getRuleContexts<vhdlParser::ConditionContext>();
}

vhdlParser::ConditionContext* vhdlParser::If_statementContext::condition(size_t i) {
  return getRuleContext<vhdlParser::ConditionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::If_statementContext::THEN() {
  return getTokens(vhdlParser::THEN);
}

tree::TerminalNode* vhdlParser::If_statementContext::THEN(size_t i) {
  return getToken(vhdlParser::THEN, i);
}

std::vector<vhdlParser::Sequence_of_statementsContext *> vhdlParser::If_statementContext::sequence_of_statements() {
  return getRuleContexts<vhdlParser::Sequence_of_statementsContext>();
}

vhdlParser::Sequence_of_statementsContext* vhdlParser::If_statementContext::sequence_of_statements(size_t i) {
  return getRuleContext<vhdlParser::Sequence_of_statementsContext>(i);
}

tree::TerminalNode* vhdlParser::If_statementContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::If_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::If_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::If_statementContext::ELSIF() {
  return getTokens(vhdlParser::ELSIF);
}

tree::TerminalNode* vhdlParser::If_statementContext::ELSIF(size_t i) {
  return getToken(vhdlParser::ELSIF, i);
}

tree::TerminalNode* vhdlParser::If_statementContext::ELSE() {
  return getToken(vhdlParser::ELSE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::If_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::If_statementContext::getRuleIndex() const {
  return vhdlParser::RuleIf_statement;
}

antlrcpp::Any vhdlParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::If_statementContext* vhdlParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 258, vhdlParser::RuleIf_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1608);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1607);
      label_colon();
    }
    setState(1610);
    match(vhdlParser::IF);
    setState(1611);
    condition();
    setState(1612);
    match(vhdlParser::THEN);
    setState(1613);
    sequence_of_statements();
    setState(1621);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::ELSIF) {
      setState(1614);
      match(vhdlParser::ELSIF);
      setState(1615);
      condition();
      setState(1616);
      match(vhdlParser::THEN);
      setState(1617);
      sequence_of_statements();
      setState(1623);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1626);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::ELSE) {
      setState(1624);
      match(vhdlParser::ELSE);
      setState(1625);
      sequence_of_statements();
    }
    setState(1628);
    match(vhdlParser::END);
    setState(1629);
    match(vhdlParser::IF);
    setState(1631);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1630);
      identifier();
    }
    setState(1633);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Index_constraintContext ------------------------------------------------------------------

vhdlParser::Index_constraintContext::Index_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Index_constraintContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Discrete_rangeContext *> vhdlParser::Index_constraintContext::discrete_range() {
  return getRuleContexts<vhdlParser::Discrete_rangeContext>();
}

vhdlParser::Discrete_rangeContext* vhdlParser::Index_constraintContext::discrete_range(size_t i) {
  return getRuleContext<vhdlParser::Discrete_rangeContext>(i);
}

tree::TerminalNode* vhdlParser::Index_constraintContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Index_constraintContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Index_constraintContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Index_constraintContext::getRuleIndex() const {
  return vhdlParser::RuleIndex_constraint;
}

antlrcpp::Any vhdlParser::Index_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitIndex_constraint(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Index_constraintContext* vhdlParser::index_constraint() {
  Index_constraintContext *_localctx = _tracker.createInstance<Index_constraintContext>(_ctx, getState());
  enterRule(_localctx, 260, vhdlParser::RuleIndex_constraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1635);
    match(vhdlParser::LPAREN);
    setState(1636);
    discrete_range();
    setState(1641);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1637);
      match(vhdlParser::COMMA);
      setState(1638);
      discrete_range();
      setState(1643);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1644);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Index_specificationContext ------------------------------------------------------------------

vhdlParser::Index_specificationContext::Index_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Discrete_rangeContext* vhdlParser::Index_specificationContext::discrete_range() {
  return getRuleContext<vhdlParser::Discrete_rangeContext>(0);
}

vhdlParser::ExpressionContext* vhdlParser::Index_specificationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Index_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleIndex_specification;
}

antlrcpp::Any vhdlParser::Index_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitIndex_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Index_specificationContext* vhdlParser::index_specification() {
  Index_specificationContext *_localctx = _tracker.createInstance<Index_specificationContext>(_ctx, getState());
  enterRule(_localctx, 262, vhdlParser::RuleIndex_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1648);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 157, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1646);
      discrete_range();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1647);
      expression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Index_subtype_definitionContext ------------------------------------------------------------------

vhdlParser::Index_subtype_definitionContext::Index_subtype_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Index_subtype_definitionContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Index_subtype_definitionContext::RANGE() {
  return getToken(vhdlParser::RANGE, 0);
}

tree::TerminalNode* vhdlParser::Index_subtype_definitionContext::BOX() {
  return getToken(vhdlParser::BOX, 0);
}


size_t vhdlParser::Index_subtype_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleIndex_subtype_definition;
}

antlrcpp::Any vhdlParser::Index_subtype_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitIndex_subtype_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Index_subtype_definitionContext* vhdlParser::index_subtype_definition() {
  Index_subtype_definitionContext *_localctx = _tracker.createInstance<Index_subtype_definitionContext>(_ctx, getState());
  enterRule(_localctx, 264, vhdlParser::RuleIndex_subtype_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1650);
    name();
    setState(1651);
    match(vhdlParser::RANGE);
    setState(1652);
    match(vhdlParser::BOX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Instantiated_unitContext ------------------------------------------------------------------

vhdlParser::Instantiated_unitContext::Instantiated_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Instantiated_unitContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

tree::TerminalNode* vhdlParser::Instantiated_unitContext::COMPONENT() {
  return getToken(vhdlParser::COMPONENT, 0);
}

tree::TerminalNode* vhdlParser::Instantiated_unitContext::ENTITY() {
  return getToken(vhdlParser::ENTITY, 0);
}

tree::TerminalNode* vhdlParser::Instantiated_unitContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Instantiated_unitContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Instantiated_unitContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Instantiated_unitContext::CONFIGURATION() {
  return getToken(vhdlParser::CONFIGURATION, 0);
}


size_t vhdlParser::Instantiated_unitContext::getRuleIndex() const {
  return vhdlParser::RuleInstantiated_unit;
}

antlrcpp::Any vhdlParser::Instantiated_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInstantiated_unit(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Instantiated_unitContext* vhdlParser::instantiated_unit() {
  Instantiated_unitContext *_localctx = _tracker.createInstance<Instantiated_unitContext>(_ctx, getState());
  enterRule(_localctx, 266, vhdlParser::RuleInstantiated_unit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1668);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::COMPONENT:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1655);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == vhdlParser::COMPONENT) {
          setState(1654);
          match(vhdlParser::COMPONENT);
        }
        setState(1657);
        name();
        break;
      }

      case vhdlParser::ENTITY: {
        enterOuterAlt(_localctx, 2);
        setState(1658);
        match(vhdlParser::ENTITY);
        setState(1659);
        name();
        setState(1664);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == vhdlParser::LPAREN) {
          setState(1660);
          match(vhdlParser::LPAREN);
          setState(1661);
          identifier();
          setState(1662);
          match(vhdlParser::RPAREN);
        }
        break;
      }

      case vhdlParser::CONFIGURATION: {
        enterOuterAlt(_localctx, 3);
        setState(1666);
        match(vhdlParser::CONFIGURATION);
        setState(1667);
        name();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Instantiation_listContext ------------------------------------------------------------------

vhdlParser::Instantiation_listContext::Instantiation_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Instantiation_listContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Instantiation_listContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Instantiation_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Instantiation_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}

tree::TerminalNode* vhdlParser::Instantiation_listContext::OTHERS() {
  return getToken(vhdlParser::OTHERS, 0);
}

tree::TerminalNode* vhdlParser::Instantiation_listContext::ALL() {
  return getToken(vhdlParser::ALL, 0);
}


size_t vhdlParser::Instantiation_listContext::getRuleIndex() const {
  return vhdlParser::RuleInstantiation_list;
}

antlrcpp::Any vhdlParser::Instantiation_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInstantiation_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Instantiation_listContext* vhdlParser::instantiation_list() {
  Instantiation_listContext *_localctx = _tracker.createInstance<Instantiation_listContext>(_ctx, getState());
  enterRule(_localctx, 268, vhdlParser::RuleInstantiation_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1680);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1670);
        identifier();
        setState(1675);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::COMMA) {
          setState(1671);
          match(vhdlParser::COMMA);
          setState(1672);
          identifier();
          setState(1677);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case vhdlParser::OTHERS: {
        enterOuterAlt(_localctx, 2);
        setState(1678);
        match(vhdlParser::OTHERS);
        break;
      }

      case vhdlParser::ALL: {
        enterOuterAlt(_localctx, 3);
        setState(1679);
        match(vhdlParser::ALL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_constant_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_constant_declarationContext::Interface_constant_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Identifier_listContext* vhdlParser::Interface_constant_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_constant_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Interface_constant_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_constant_declarationContext::CONSTANT() {
  return getToken(vhdlParser::CONSTANT, 0);
}

tree::TerminalNode* vhdlParser::Interface_constant_declarationContext::IN() {
  return getToken(vhdlParser::IN, 0);
}

tree::TerminalNode* vhdlParser::Interface_constant_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Interface_constant_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Interface_constant_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_constant_declaration;
}

antlrcpp::Any vhdlParser::Interface_constant_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_constant_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_constant_declarationContext* vhdlParser::interface_constant_declaration() {
  Interface_constant_declarationContext *_localctx = _tracker.createInstance<Interface_constant_declarationContext>(_ctx, getState());
  enterRule(_localctx, 270, vhdlParser::RuleInterface_constant_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1683);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::CONSTANT) {
      setState(1682);
      match(vhdlParser::CONSTANT);
    }
    setState(1685);
    identifier_list();
    setState(1686);
    match(vhdlParser::COLON);
    setState(1688);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IN) {
      setState(1687);
      match(vhdlParser::IN);
    }
    setState(1690);
    subtype_indication();
    setState(1693);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1691);
      match(vhdlParser::VARASGN);
      setState(1692);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_declarationContext::Interface_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_constant_declarationContext* vhdlParser::Interface_declarationContext::interface_constant_declaration() {
  return getRuleContext<vhdlParser::Interface_constant_declarationContext>(0);
}

vhdlParser::Interface_signal_declarationContext* vhdlParser::Interface_declarationContext::interface_signal_declaration() {
  return getRuleContext<vhdlParser::Interface_signal_declarationContext>(0);
}

vhdlParser::Interface_variable_declarationContext* vhdlParser::Interface_declarationContext::interface_variable_declaration() {
  return getRuleContext<vhdlParser::Interface_variable_declarationContext>(0);
}

vhdlParser::Interface_file_declarationContext* vhdlParser::Interface_declarationContext::interface_file_declaration() {
  return getRuleContext<vhdlParser::Interface_file_declarationContext>(0);
}

vhdlParser::Interface_terminal_declarationContext* vhdlParser::Interface_declarationContext::interface_terminal_declaration() {
  return getRuleContext<vhdlParser::Interface_terminal_declarationContext>(0);
}

vhdlParser::Interface_quantity_declarationContext* vhdlParser::Interface_declarationContext::interface_quantity_declaration() {
  return getRuleContext<vhdlParser::Interface_quantity_declarationContext>(0);
}


size_t vhdlParser::Interface_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_declaration;
}

antlrcpp::Any vhdlParser::Interface_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_declarationContext* vhdlParser::interface_declaration() {
  Interface_declarationContext *_localctx = _tracker.createInstance<Interface_declarationContext>(_ctx, getState());
  enterRule(_localctx, 272, vhdlParser::RuleInterface_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1701);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1695);
      interface_constant_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1696);
      interface_signal_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1697);
      interface_variable_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1698);
      interface_file_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1699);
      interface_terminal_declaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1700);
      interface_quantity_declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_elementContext ------------------------------------------------------------------

vhdlParser::Interface_elementContext::Interface_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_declarationContext* vhdlParser::Interface_elementContext::interface_declaration() {
  return getRuleContext<vhdlParser::Interface_declarationContext>(0);
}


size_t vhdlParser::Interface_elementContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_element;
}

antlrcpp::Any vhdlParser::Interface_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_element(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_elementContext* vhdlParser::interface_element() {
  Interface_elementContext *_localctx = _tracker.createInstance<Interface_elementContext>(_ctx, getState());
  enterRule(_localctx, 274, vhdlParser::RuleInterface_element);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1703);
    interface_declaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_file_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_file_declarationContext::Interface_file_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Interface_file_declarationContext::FILE() {
  return getToken(vhdlParser::FILE, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Interface_file_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_file_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Interface_file_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}


size_t vhdlParser::Interface_file_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_file_declaration;
}

antlrcpp::Any vhdlParser::Interface_file_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_file_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_file_declarationContext* vhdlParser::interface_file_declaration() {
  Interface_file_declarationContext *_localctx = _tracker.createInstance<Interface_file_declarationContext>(_ctx, getState());
  enterRule(_localctx, 276, vhdlParser::RuleInterface_file_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1705);
    match(vhdlParser::FILE);
    setState(1706);
    identifier_list();
    setState(1707);
    match(vhdlParser::COLON);
    setState(1708);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_signal_listContext ------------------------------------------------------------------

vhdlParser::Interface_signal_listContext::Interface_signal_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Interface_signal_declarationContext *> vhdlParser::Interface_signal_listContext::interface_signal_declaration() {
  return getRuleContexts<vhdlParser::Interface_signal_declarationContext>();
}

vhdlParser::Interface_signal_declarationContext* vhdlParser::Interface_signal_listContext::interface_signal_declaration(size_t i) {
  return getRuleContext<vhdlParser::Interface_signal_declarationContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Interface_signal_listContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Interface_signal_listContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}


size_t vhdlParser::Interface_signal_listContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_signal_list;
}

antlrcpp::Any vhdlParser::Interface_signal_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_signal_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_signal_listContext* vhdlParser::interface_signal_list() {
  Interface_signal_listContext *_localctx = _tracker.createInstance<Interface_signal_listContext>(_ctx, getState());
  enterRule(_localctx, 278, vhdlParser::RuleInterface_signal_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1710);
    interface_signal_declaration();
    setState(1715);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::SEMI) {
      setState(1711);
      match(vhdlParser::SEMI);
      setState(1712);
      interface_signal_declaration();
      setState(1717);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_port_listContext ------------------------------------------------------------------

vhdlParser::Interface_port_listContext::Interface_port_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Interface_port_declarationContext *> vhdlParser::Interface_port_listContext::interface_port_declaration() {
  return getRuleContexts<vhdlParser::Interface_port_declarationContext>();
}

vhdlParser::Interface_port_declarationContext* vhdlParser::Interface_port_listContext::interface_port_declaration(size_t i) {
  return getRuleContext<vhdlParser::Interface_port_declarationContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Interface_port_listContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Interface_port_listContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}


size_t vhdlParser::Interface_port_listContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_port_list;
}

antlrcpp::Any vhdlParser::Interface_port_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_port_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_port_listContext* vhdlParser::interface_port_list() {
  Interface_port_listContext *_localctx = _tracker.createInstance<Interface_port_listContext>(_ctx, getState());
  enterRule(_localctx, 280, vhdlParser::RuleInterface_port_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1718);
    interface_port_declaration();
    setState(1723);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::SEMI) {
      setState(1719);
      match(vhdlParser::SEMI);
      setState(1720);
      interface_port_declaration();
      setState(1725);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_listContext ------------------------------------------------------------------

vhdlParser::Interface_listContext::Interface_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Interface_elementContext *> vhdlParser::Interface_listContext::interface_element() {
  return getRuleContexts<vhdlParser::Interface_elementContext>();
}

vhdlParser::Interface_elementContext* vhdlParser::Interface_listContext::interface_element(size_t i) {
  return getRuleContext<vhdlParser::Interface_elementContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Interface_listContext::SEMI() {
  return getTokens(vhdlParser::SEMI);
}

tree::TerminalNode* vhdlParser::Interface_listContext::SEMI(size_t i) {
  return getToken(vhdlParser::SEMI, i);
}


size_t vhdlParser::Interface_listContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_list;
}

antlrcpp::Any vhdlParser::Interface_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_listContext* vhdlParser::interface_list() {
  Interface_listContext *_localctx = _tracker.createInstance<Interface_listContext>(_ctx, getState());
  enterRule(_localctx, 282, vhdlParser::RuleInterface_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1726);
    interface_element();
    setState(1731);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::SEMI) {
      setState(1727);
      match(vhdlParser::SEMI);
      setState(1728);
      interface_element();
      setState(1733);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_quantity_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_quantity_declarationContext::Interface_quantity_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Interface_quantity_declarationContext::QUANTITY() {
  return getToken(vhdlParser::QUANTITY, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Interface_quantity_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_quantity_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Interface_quantity_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_quantity_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Interface_quantity_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_quantity_declarationContext::IN() {
  return getToken(vhdlParser::IN, 0);
}

tree::TerminalNode* vhdlParser::Interface_quantity_declarationContext::OUT() {
  return getToken(vhdlParser::OUT, 0);
}


size_t vhdlParser::Interface_quantity_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_quantity_declaration;
}

antlrcpp::Any vhdlParser::Interface_quantity_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_quantity_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_quantity_declarationContext* vhdlParser::interface_quantity_declaration() {
  Interface_quantity_declarationContext *_localctx = _tracker.createInstance<Interface_quantity_declarationContext>(_ctx, getState());
  enterRule(_localctx, 284, vhdlParser::RuleInterface_quantity_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1734);
    match(vhdlParser::QUANTITY);
    setState(1735);
    identifier_list();
    setState(1736);
    match(vhdlParser::COLON);
    setState(1738);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IN

    || _la == vhdlParser::OUT) {
      setState(1737);
      _la = _input->LA(1);
      if (!(_la == vhdlParser::IN

      || _la == vhdlParser::OUT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(1740);
    subtype_indication();
    setState(1743);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1741);
      match(vhdlParser::VARASGN);
      setState(1742);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_port_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_port_declarationContext::Interface_port_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Identifier_listContext* vhdlParser::Interface_port_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_port_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Signal_modeContext* vhdlParser::Interface_port_declarationContext::signal_mode() {
  return getRuleContext<vhdlParser::Signal_modeContext>(0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Interface_port_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_port_declarationContext::BUS() {
  return getToken(vhdlParser::BUS, 0);
}

tree::TerminalNode* vhdlParser::Interface_port_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Interface_port_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Interface_port_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_port_declaration;
}

antlrcpp::Any vhdlParser::Interface_port_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_port_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_port_declarationContext* vhdlParser::interface_port_declaration() {
  Interface_port_declarationContext *_localctx = _tracker.createInstance<Interface_port_declarationContext>(_ctx, getState());
  enterRule(_localctx, 286, vhdlParser::RuleInterface_port_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1745);
    identifier_list();
    setState(1746);
    match(vhdlParser::COLON);
    setState(1747);
    signal_mode();
    setState(1748);
    subtype_indication();
    setState(1750);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BUS) {
      setState(1749);
      match(vhdlParser::BUS);
    }
    setState(1754);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1752);
      match(vhdlParser::VARASGN);
      setState(1753);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_signal_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_signal_declarationContext::Interface_signal_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Interface_signal_declarationContext::SIGNAL() {
  return getToken(vhdlParser::SIGNAL, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Interface_signal_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_signal_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Interface_signal_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_signal_declarationContext::BUS() {
  return getToken(vhdlParser::BUS, 0);
}

tree::TerminalNode* vhdlParser::Interface_signal_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Interface_signal_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_signal_declarationContext::IN() {
  return getToken(vhdlParser::IN, 0);
}

tree::TerminalNode* vhdlParser::Interface_signal_declarationContext::OUT() {
  return getToken(vhdlParser::OUT, 0);
}

tree::TerminalNode* vhdlParser::Interface_signal_declarationContext::INOUT() {
  return getToken(vhdlParser::INOUT, 0);
}


size_t vhdlParser::Interface_signal_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_signal_declaration;
}

antlrcpp::Any vhdlParser::Interface_signal_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_signal_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_signal_declarationContext* vhdlParser::interface_signal_declaration() {
  Interface_signal_declarationContext *_localctx = _tracker.createInstance<Interface_signal_declarationContext>(_ctx, getState());
  enterRule(_localctx, 288, vhdlParser::RuleInterface_signal_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1756);
    match(vhdlParser::SIGNAL);
    setState(1757);
    identifier_list();
    setState(1758);
    match(vhdlParser::COLON);
    setState(1760);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 39) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 39)) & ((1ULL << (vhdlParser::IN - 39))
      | (1ULL << (vhdlParser::INOUT - 39))
      | (1ULL << (vhdlParser::OUT - 39)))) != 0)) {
      setState(1759);
      _la = _input->LA(1);
      if (!(((((_la - 39) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 39)) & ((1ULL << (vhdlParser::IN - 39))
        | (1ULL << (vhdlParser::INOUT - 39))
        | (1ULL << (vhdlParser::OUT - 39)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(1762);
    subtype_indication();
    setState(1764);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BUS) {
      setState(1763);
      match(vhdlParser::BUS);
    }
    setState(1768);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1766);
      match(vhdlParser::VARASGN);
      setState(1767);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_terminal_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_terminal_declarationContext::Interface_terminal_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Interface_terminal_declarationContext::TERMINAL() {
  return getToken(vhdlParser::TERMINAL, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Interface_terminal_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_terminal_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subnature_indicationContext* vhdlParser::Interface_terminal_declarationContext::subnature_indication() {
  return getRuleContext<vhdlParser::Subnature_indicationContext>(0);
}


size_t vhdlParser::Interface_terminal_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_terminal_declaration;
}

antlrcpp::Any vhdlParser::Interface_terminal_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_terminal_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_terminal_declarationContext* vhdlParser::interface_terminal_declaration() {
  Interface_terminal_declarationContext *_localctx = _tracker.createInstance<Interface_terminal_declarationContext>(_ctx, getState());
  enterRule(_localctx, 290, vhdlParser::RuleInterface_terminal_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1770);
    match(vhdlParser::TERMINAL);
    setState(1771);
    identifier_list();
    setState(1772);
    match(vhdlParser::COLON);
    setState(1773);
    subnature_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_variable_declarationContext ------------------------------------------------------------------

vhdlParser::Interface_variable_declarationContext::Interface_variable_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Identifier_listContext* vhdlParser::Interface_variable_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_variable_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Interface_variable_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_variable_declarationContext::VARIABLE() {
  return getToken(vhdlParser::VARIABLE, 0);
}

vhdlParser::Signal_modeContext* vhdlParser::Interface_variable_declarationContext::signal_mode() {
  return getRuleContext<vhdlParser::Signal_modeContext>(0);
}

tree::TerminalNode* vhdlParser::Interface_variable_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Interface_variable_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Interface_variable_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleInterface_variable_declaration;
}

antlrcpp::Any vhdlParser::Interface_variable_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitInterface_variable_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Interface_variable_declarationContext* vhdlParser::interface_variable_declaration() {
  Interface_variable_declarationContext *_localctx = _tracker.createInstance<Interface_variable_declarationContext>(_ctx, getState());
  enterRule(_localctx, 292, vhdlParser::RuleInterface_variable_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1776);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARIABLE) {
      setState(1775);
      match(vhdlParser::VARIABLE);
    }
    setState(1778);
    identifier_list();
    setState(1779);
    match(vhdlParser::COLON);
    setState(1781);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 16) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 16)) & ((1ULL << (vhdlParser::BUFFER - 16))
      | (1ULL << (vhdlParser::IN - 16))
      | (1ULL << (vhdlParser::INOUT - 16))
      | (1ULL << (vhdlParser::LINKAGE - 16))
      | (1ULL << (vhdlParser::OUT - 16)))) != 0)) {
      setState(1780);
      signal_mode();
    }
    setState(1783);
    subtype_indication();
    setState(1786);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(1784);
      match(vhdlParser::VARASGN);
      setState(1785);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Iteration_schemeContext ------------------------------------------------------------------

vhdlParser::Iteration_schemeContext::Iteration_schemeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Iteration_schemeContext::WHILE() {
  return getToken(vhdlParser::WHILE, 0);
}

vhdlParser::ConditionContext* vhdlParser::Iteration_schemeContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}

tree::TerminalNode* vhdlParser::Iteration_schemeContext::FOR() {
  return getToken(vhdlParser::FOR, 0);
}

vhdlParser::Parameter_specificationContext* vhdlParser::Iteration_schemeContext::parameter_specification() {
  return getRuleContext<vhdlParser::Parameter_specificationContext>(0);
}


size_t vhdlParser::Iteration_schemeContext::getRuleIndex() const {
  return vhdlParser::RuleIteration_scheme;
}

antlrcpp::Any vhdlParser::Iteration_schemeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitIteration_scheme(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Iteration_schemeContext* vhdlParser::iteration_scheme() {
  Iteration_schemeContext *_localctx = _tracker.createInstance<Iteration_schemeContext>(_ctx, getState());
  enterRule(_localctx, 294, vhdlParser::RuleIteration_scheme);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1792);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::WHILE: {
        enterOuterAlt(_localctx, 1);
        setState(1788);
        match(vhdlParser::WHILE);
        setState(1789);
        condition();
        break;
      }

      case vhdlParser::FOR: {
        enterOuterAlt(_localctx, 2);
        setState(1790);
        match(vhdlParser::FOR);
        setState(1791);
        parameter_specification();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Label_colonContext ------------------------------------------------------------------

vhdlParser::Label_colonContext::Label_colonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Label_colonContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Label_colonContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}


size_t vhdlParser::Label_colonContext::getRuleIndex() const {
  return vhdlParser::RuleLabel_colon;
}

antlrcpp::Any vhdlParser::Label_colonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitLabel_colon(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Label_colonContext* vhdlParser::label_colon() {
  Label_colonContext *_localctx = _tracker.createInstance<Label_colonContext>(_ctx, getState());
  enterRule(_localctx, 296, vhdlParser::RuleLabel_colon);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1794);
    identifier();
    setState(1795);
    match(vhdlParser::COLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Library_clauseContext ------------------------------------------------------------------

vhdlParser::Library_clauseContext::Library_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Library_clauseContext::LIBRARY() {
  return getToken(vhdlParser::LIBRARY, 0);
}

vhdlParser::Logical_name_listContext* vhdlParser::Library_clauseContext::logical_name_list() {
  return getRuleContext<vhdlParser::Logical_name_listContext>(0);
}

tree::TerminalNode* vhdlParser::Library_clauseContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Library_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleLibrary_clause;
}

antlrcpp::Any vhdlParser::Library_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitLibrary_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Library_clauseContext* vhdlParser::library_clause() {
  Library_clauseContext *_localctx = _tracker.createInstance<Library_clauseContext>(_ctx, getState());
  enterRule(_localctx, 298, vhdlParser::RuleLibrary_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1797);
    match(vhdlParser::LIBRARY);
    setState(1798);
    logical_name_list();
    setState(1799);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Library_unitContext ------------------------------------------------------------------

vhdlParser::Library_unitContext::Library_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Secondary_unitContext* vhdlParser::Library_unitContext::secondary_unit() {
  return getRuleContext<vhdlParser::Secondary_unitContext>(0);
}

vhdlParser::Primary_unitContext* vhdlParser::Library_unitContext::primary_unit() {
  return getRuleContext<vhdlParser::Primary_unitContext>(0);
}


size_t vhdlParser::Library_unitContext::getRuleIndex() const {
  return vhdlParser::RuleLibrary_unit;
}

antlrcpp::Any vhdlParser::Library_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitLibrary_unit(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Library_unitContext* vhdlParser::library_unit() {
  Library_unitContext *_localctx = _tracker.createInstance<Library_unitContext>(_ctx, getState());
  enterRule(_localctx, 300, vhdlParser::RuleLibrary_unit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1803);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 181, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1801);
      secondary_unit();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1802);
      primary_unit();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

vhdlParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::LiteralContext::NULL_SYM() {
  return getToken(vhdlParser::NULL_SYM, 0);
}

tree::TerminalNode* vhdlParser::LiteralContext::BIT_STRING_LITERAL() {
  return getToken(vhdlParser::BIT_STRING_LITERAL, 0);
}

tree::TerminalNode* vhdlParser::LiteralContext::STRING_LITERAL() {
  return getToken(vhdlParser::STRING_LITERAL, 0);
}

vhdlParser::Enumeration_literalContext* vhdlParser::LiteralContext::enumeration_literal() {
  return getRuleContext<vhdlParser::Enumeration_literalContext>(0);
}

vhdlParser::Numeric_literalContext* vhdlParser::LiteralContext::numeric_literal() {
  return getRuleContext<vhdlParser::Numeric_literalContext>(0);
}


size_t vhdlParser::LiteralContext::getRuleIndex() const {
  return vhdlParser::RuleLiteral;
}

antlrcpp::Any vhdlParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::LiteralContext* vhdlParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 302, vhdlParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1810);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::NULL_SYM: {
        enterOuterAlt(_localctx, 1);
        setState(1805);
        match(vhdlParser::NULL_SYM);
        break;
      }

      case vhdlParser::BIT_STRING_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1806);
        match(vhdlParser::BIT_STRING_LITERAL);
        break;
      }

      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(1807);
        match(vhdlParser::STRING_LITERAL);
        break;
      }

      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(1808);
        enumeration_literal();
        break;
      }

      case vhdlParser::BASE_LITERAL:
      case vhdlParser::REAL_LITERAL:
      case vhdlParser::INTEGER: {
        enterOuterAlt(_localctx, 5);
        setState(1809);
        numeric_literal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_nameContext ------------------------------------------------------------------

vhdlParser::Logical_nameContext::Logical_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Logical_nameContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Logical_nameContext::getRuleIndex() const {
  return vhdlParser::RuleLogical_name;
}

antlrcpp::Any vhdlParser::Logical_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitLogical_name(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Logical_nameContext* vhdlParser::logical_name() {
  Logical_nameContext *_localctx = _tracker.createInstance<Logical_nameContext>(_ctx, getState());
  enterRule(_localctx, 304, vhdlParser::RuleLogical_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1812);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_name_listContext ------------------------------------------------------------------

vhdlParser::Logical_name_listContext::Logical_name_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Logical_nameContext *> vhdlParser::Logical_name_listContext::logical_name() {
  return getRuleContexts<vhdlParser::Logical_nameContext>();
}

vhdlParser::Logical_nameContext* vhdlParser::Logical_name_listContext::logical_name(size_t i) {
  return getRuleContext<vhdlParser::Logical_nameContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Logical_name_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Logical_name_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Logical_name_listContext::getRuleIndex() const {
  return vhdlParser::RuleLogical_name_list;
}

antlrcpp::Any vhdlParser::Logical_name_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitLogical_name_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Logical_name_listContext* vhdlParser::logical_name_list() {
  Logical_name_listContext *_localctx = _tracker.createInstance<Logical_name_listContext>(_ctx, getState());
  enterRule(_localctx, 306, vhdlParser::RuleLogical_name_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1814);
    logical_name();
    setState(1819);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1815);
      match(vhdlParser::COMMA);
      setState(1816);
      logical_name();
      setState(1821);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_operatorContext ------------------------------------------------------------------

vhdlParser::Logical_operatorContext::Logical_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::AND() {
  return getToken(vhdlParser::AND, 0);
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::OR() {
  return getToken(vhdlParser::OR, 0);
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::NAND() {
  return getToken(vhdlParser::NAND, 0);
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::NOR() {
  return getToken(vhdlParser::NOR, 0);
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::XOR() {
  return getToken(vhdlParser::XOR, 0);
}

tree::TerminalNode* vhdlParser::Logical_operatorContext::XNOR() {
  return getToken(vhdlParser::XNOR, 0);
}


size_t vhdlParser::Logical_operatorContext::getRuleIndex() const {
  return vhdlParser::RuleLogical_operator;
}

antlrcpp::Any vhdlParser::Logical_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitLogical_operator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Logical_operatorContext* vhdlParser::logical_operator() {
  Logical_operatorContext *_localctx = _tracker.createInstance<Logical_operatorContext>(_ctx, getState());
  enterRule(_localctx, 308, vhdlParser::RuleLogical_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1822);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::AND)
      | (1ULL << vhdlParser::NAND)
      | (1ULL << vhdlParser::NOR)
      | (1ULL << vhdlParser::OR))) != 0) || _la == vhdlParser::XNOR

    || _la == vhdlParser::XOR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Loop_statementContext ------------------------------------------------------------------

vhdlParser::Loop_statementContext::Loop_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Loop_statementContext::LOOP() {
  return getTokens(vhdlParser::LOOP);
}

tree::TerminalNode* vhdlParser::Loop_statementContext::LOOP(size_t i) {
  return getToken(vhdlParser::LOOP, i);
}

vhdlParser::Sequence_of_statementsContext* vhdlParser::Loop_statementContext::sequence_of_statements() {
  return getRuleContext<vhdlParser::Sequence_of_statementsContext>(0);
}

tree::TerminalNode* vhdlParser::Loop_statementContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Loop_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Loop_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::Iteration_schemeContext* vhdlParser::Loop_statementContext::iteration_scheme() {
  return getRuleContext<vhdlParser::Iteration_schemeContext>(0);
}

vhdlParser::IdentifierContext* vhdlParser::Loop_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Loop_statementContext::getRuleIndex() const {
  return vhdlParser::RuleLoop_statement;
}

antlrcpp::Any vhdlParser::Loop_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitLoop_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Loop_statementContext* vhdlParser::loop_statement() {
  Loop_statementContext *_localctx = _tracker.createInstance<Loop_statementContext>(_ctx, getState());
  enterRule(_localctx, 310, vhdlParser::RuleLoop_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1825);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1824);
      label_colon();
    }
    setState(1828);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::FOR || _la == vhdlParser::WHILE) {
      setState(1827);
      iteration_scheme();
    }
    setState(1830);
    match(vhdlParser::LOOP);
    setState(1831);
    sequence_of_statements();
    setState(1832);
    match(vhdlParser::END);
    setState(1833);
    match(vhdlParser::LOOP);
    setState(1835);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1834);
      identifier();
    }
    setState(1837);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signal_modeContext ------------------------------------------------------------------

vhdlParser::Signal_modeContext::Signal_modeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Signal_modeContext::IN() {
  return getToken(vhdlParser::IN, 0);
}

tree::TerminalNode* vhdlParser::Signal_modeContext::OUT() {
  return getToken(vhdlParser::OUT, 0);
}

tree::TerminalNode* vhdlParser::Signal_modeContext::INOUT() {
  return getToken(vhdlParser::INOUT, 0);
}

tree::TerminalNode* vhdlParser::Signal_modeContext::BUFFER() {
  return getToken(vhdlParser::BUFFER, 0);
}

tree::TerminalNode* vhdlParser::Signal_modeContext::LINKAGE() {
  return getToken(vhdlParser::LINKAGE, 0);
}


size_t vhdlParser::Signal_modeContext::getRuleIndex() const {
  return vhdlParser::RuleSignal_mode;
}

antlrcpp::Any vhdlParser::Signal_modeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSignal_mode(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Signal_modeContext* vhdlParser::signal_mode() {
  Signal_modeContext *_localctx = _tracker.createInstance<Signal_modeContext>(_ctx, getState());
  enterRule(_localctx, 312, vhdlParser::RuleSignal_mode);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1839);
    _la = _input->LA(1);
    if (!(((((_la - 16) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 16)) & ((1ULL << (vhdlParser::BUFFER - 16))
      | (1ULL << (vhdlParser::IN - 16))
      | (1ULL << (vhdlParser::INOUT - 16))
      | (1ULL << (vhdlParser::LINKAGE - 16))
      | (1ULL << (vhdlParser::OUT - 16)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Multiplying_operatorContext ------------------------------------------------------------------

vhdlParser::Multiplying_operatorContext::Multiplying_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Multiplying_operatorContext::MUL() {
  return getToken(vhdlParser::MUL, 0);
}

tree::TerminalNode* vhdlParser::Multiplying_operatorContext::DIV() {
  return getToken(vhdlParser::DIV, 0);
}

tree::TerminalNode* vhdlParser::Multiplying_operatorContext::MOD() {
  return getToken(vhdlParser::MOD, 0);
}

tree::TerminalNode* vhdlParser::Multiplying_operatorContext::REM() {
  return getToken(vhdlParser::REM, 0);
}


size_t vhdlParser::Multiplying_operatorContext::getRuleIndex() const {
  return vhdlParser::RuleMultiplying_operator;
}

antlrcpp::Any vhdlParser::Multiplying_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitMultiplying_operator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Multiplying_operatorContext* vhdlParser::multiplying_operator() {
  Multiplying_operatorContext *_localctx = _tracker.createInstance<Multiplying_operatorContext>(_ctx, getState());
  enterRule(_localctx, 314, vhdlParser::RuleMultiplying_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1841);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::MOD

    || _la == vhdlParser::REM || _la == vhdlParser::MUL

    || _la == vhdlParser::DIV)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

vhdlParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Selected_nameContext* vhdlParser::NameContext::selected_name() {
  return getRuleContext<vhdlParser::Selected_nameContext>(0);
}

std::vector<vhdlParser::Name_partContext *> vhdlParser::NameContext::name_part() {
  return getRuleContexts<vhdlParser::Name_partContext>();
}

vhdlParser::Name_partContext* vhdlParser::NameContext::name_part(size_t i) {
  return getRuleContext<vhdlParser::Name_partContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::NameContext::DOT() {
  return getTokens(vhdlParser::DOT);
}

tree::TerminalNode* vhdlParser::NameContext::DOT(size_t i) {
  return getToken(vhdlParser::DOT, i);
}


size_t vhdlParser::NameContext::getRuleIndex() const {
  return vhdlParser::RuleName;
}

antlrcpp::Any vhdlParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::NameContext* vhdlParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 316, vhdlParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1852);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 188, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1843);
      selected_name();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1844);
      name_part();
      setState(1849);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 187, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1845);
          match(vhdlParser::DOT);
          setState(1846);
          name_part(); 
        }
        setState(1851);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 187, _ctx);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Name_partContext ------------------------------------------------------------------

vhdlParser::Name_partContext::Name_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Selected_nameContext* vhdlParser::Name_partContext::selected_name() {
  return getRuleContext<vhdlParser::Selected_nameContext>(0);
}

std::vector<vhdlParser::Name_part_specificatorContext *> vhdlParser::Name_partContext::name_part_specificator() {
  return getRuleContexts<vhdlParser::Name_part_specificatorContext>();
}

vhdlParser::Name_part_specificatorContext* vhdlParser::Name_partContext::name_part_specificator(size_t i) {
  return getRuleContext<vhdlParser::Name_part_specificatorContext>(i);
}


size_t vhdlParser::Name_partContext::getRuleIndex() const {
  return vhdlParser::RuleName_part;
}

antlrcpp::Any vhdlParser::Name_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitName_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Name_partContext* vhdlParser::name_part() {
  Name_partContext *_localctx = _tracker.createInstance<Name_partContext>(_ctx, getState());
  enterRule(_localctx, 318, vhdlParser::RuleName_part);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1854);
    selected_name();
    setState(1858);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 189, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1855);
        name_part_specificator(); 
      }
      setState(1860);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 189, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Name_part_specificatorContext ------------------------------------------------------------------

vhdlParser::Name_part_specificatorContext::Name_part_specificatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Name_attribute_partContext* vhdlParser::Name_part_specificatorContext::name_attribute_part() {
  return getRuleContext<vhdlParser::Name_attribute_partContext>(0);
}

vhdlParser::Name_function_call_or_indexed_partContext* vhdlParser::Name_part_specificatorContext::name_function_call_or_indexed_part() {
  return getRuleContext<vhdlParser::Name_function_call_or_indexed_partContext>(0);
}

vhdlParser::Name_slice_partContext* vhdlParser::Name_part_specificatorContext::name_slice_part() {
  return getRuleContext<vhdlParser::Name_slice_partContext>(0);
}


size_t vhdlParser::Name_part_specificatorContext::getRuleIndex() const {
  return vhdlParser::RuleName_part_specificator;
}

antlrcpp::Any vhdlParser::Name_part_specificatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitName_part_specificator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Name_part_specificatorContext* vhdlParser::name_part_specificator() {
  Name_part_specificatorContext *_localctx = _tracker.createInstance<Name_part_specificatorContext>(_ctx, getState());
  enterRule(_localctx, 320, vhdlParser::RuleName_part_specificator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1864);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 190, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1861);
      name_attribute_part();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1862);
      name_function_call_or_indexed_part();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1863);
      name_slice_part();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Name_attribute_partContext ------------------------------------------------------------------

vhdlParser::Name_attribute_partContext::Name_attribute_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Name_attribute_partContext::APOSTROPHE() {
  return getToken(vhdlParser::APOSTROPHE, 0);
}

vhdlParser::Attribute_designatorContext* vhdlParser::Name_attribute_partContext::attribute_designator() {
  return getRuleContext<vhdlParser::Attribute_designatorContext>(0);
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::Name_attribute_partContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::Name_attribute_partContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Name_attribute_partContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Name_attribute_partContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Name_attribute_partContext::getRuleIndex() const {
  return vhdlParser::RuleName_attribute_part;
}

antlrcpp::Any vhdlParser::Name_attribute_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitName_attribute_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Name_attribute_partContext* vhdlParser::name_attribute_part() {
  Name_attribute_partContext *_localctx = _tracker.createInstance<Name_attribute_partContext>(_ctx, getState());
  enterRule(_localctx, 322, vhdlParser::RuleName_attribute_part);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1866);
    match(vhdlParser::APOSTROPHE);
    setState(1867);
    attribute_designator();
    setState(1876);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 192, _ctx)) {
    case 1: {
      setState(1868);
      expression();
      setState(1873);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 191, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1869);
          match(vhdlParser::COMMA);
          setState(1870);
          expression(); 
        }
        setState(1875);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 191, _ctx);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Name_function_call_or_indexed_partContext ------------------------------------------------------------------

vhdlParser::Name_function_call_or_indexed_partContext::Name_function_call_or_indexed_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Name_function_call_or_indexed_partContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

tree::TerminalNode* vhdlParser::Name_function_call_or_indexed_partContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

vhdlParser::Actual_parameter_partContext* vhdlParser::Name_function_call_or_indexed_partContext::actual_parameter_part() {
  return getRuleContext<vhdlParser::Actual_parameter_partContext>(0);
}


size_t vhdlParser::Name_function_call_or_indexed_partContext::getRuleIndex() const {
  return vhdlParser::RuleName_function_call_or_indexed_part;
}

antlrcpp::Any vhdlParser::Name_function_call_or_indexed_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitName_function_call_or_indexed_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Name_function_call_or_indexed_partContext* vhdlParser::name_function_call_or_indexed_part() {
  Name_function_call_or_indexed_partContext *_localctx = _tracker.createInstance<Name_function_call_or_indexed_partContext>(_ctx, getState());
  enterRule(_localctx, 324, vhdlParser::RuleName_function_call_or_indexed_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1878);
    match(vhdlParser::LPAREN);
    setState(1880);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ABS)
      | (1ULL << vhdlParser::NEW)
      | (1ULL << vhdlParser::NOT)
      | (1ULL << vhdlParser::NULL_SYM)
      | (1ULL << vhdlParser::OPEN))) != 0) || ((((_la - 114) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 114)) & ((1ULL << (vhdlParser::BASE_LITERAL - 114))
      | (1ULL << (vhdlParser::BIT_STRING_LITERAL - 114))
      | (1ULL << (vhdlParser::REAL_LITERAL - 114))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 114))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 114))
      | (1ULL << (vhdlParser::CHARACTER_LITERAL - 114))
      | (1ULL << (vhdlParser::STRING_LITERAL - 114))
      | (1ULL << (vhdlParser::LPAREN - 114))
      | (1ULL << (vhdlParser::PLUS - 114))
      | (1ULL << (vhdlParser::MINUS - 114))
      | (1ULL << (vhdlParser::CONDITION_OPERATOR - 114))
      | (1ULL << (vhdlParser::INTEGER - 114)))) != 0)) {
      setState(1879);
      actual_parameter_part();
    }
    setState(1882);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Name_slice_partContext ------------------------------------------------------------------

vhdlParser::Name_slice_partContext::Name_slice_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Name_slice_partContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Explicit_rangeContext *> vhdlParser::Name_slice_partContext::explicit_range() {
  return getRuleContexts<vhdlParser::Explicit_rangeContext>();
}

vhdlParser::Explicit_rangeContext* vhdlParser::Name_slice_partContext::explicit_range(size_t i) {
  return getRuleContext<vhdlParser::Explicit_rangeContext>(i);
}

tree::TerminalNode* vhdlParser::Name_slice_partContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Name_slice_partContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Name_slice_partContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Name_slice_partContext::getRuleIndex() const {
  return vhdlParser::RuleName_slice_part;
}

antlrcpp::Any vhdlParser::Name_slice_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitName_slice_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Name_slice_partContext* vhdlParser::name_slice_part() {
  Name_slice_partContext *_localctx = _tracker.createInstance<Name_slice_partContext>(_ctx, getState());
  enterRule(_localctx, 326, vhdlParser::RuleName_slice_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1884);
    match(vhdlParser::LPAREN);
    setState(1885);
    explicit_range();
    setState(1890);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(1886);
      match(vhdlParser::COMMA);
      setState(1887);
      explicit_range();
      setState(1892);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1893);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selected_nameContext ------------------------------------------------------------------

vhdlParser::Selected_nameContext::Selected_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Selected_nameContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Selected_nameContext::DOT() {
  return getTokens(vhdlParser::DOT);
}

tree::TerminalNode* vhdlParser::Selected_nameContext::DOT(size_t i) {
  return getToken(vhdlParser::DOT, i);
}

std::vector<vhdlParser::SuffixContext *> vhdlParser::Selected_nameContext::suffix() {
  return getRuleContexts<vhdlParser::SuffixContext>();
}

vhdlParser::SuffixContext* vhdlParser::Selected_nameContext::suffix(size_t i) {
  return getRuleContext<vhdlParser::SuffixContext>(i);
}


size_t vhdlParser::Selected_nameContext::getRuleIndex() const {
  return vhdlParser::RuleSelected_name;
}

antlrcpp::Any vhdlParser::Selected_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSelected_name(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Selected_nameContext* vhdlParser::selected_name() {
  Selected_nameContext *_localctx = _tracker.createInstance<Selected_nameContext>(_ctx, getState());
  enterRule(_localctx, 328, vhdlParser::RuleSelected_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1895);
    identifier();
    setState(1900);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 195, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1896);
        match(vhdlParser::DOT);
        setState(1897);
        suffix(); 
      }
      setState(1902);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 195, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Nature_declarationContext ------------------------------------------------------------------

vhdlParser::Nature_declarationContext::Nature_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Nature_declarationContext::NATURE() {
  return getToken(vhdlParser::NATURE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Nature_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Nature_declarationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::Nature_definitionContext* vhdlParser::Nature_declarationContext::nature_definition() {
  return getRuleContext<vhdlParser::Nature_definitionContext>(0);
}

tree::TerminalNode* vhdlParser::Nature_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Nature_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleNature_declaration;
}

antlrcpp::Any vhdlParser::Nature_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitNature_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Nature_declarationContext* vhdlParser::nature_declaration() {
  Nature_declarationContext *_localctx = _tracker.createInstance<Nature_declarationContext>(_ctx, getState());
  enterRule(_localctx, 330, vhdlParser::RuleNature_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1903);
    match(vhdlParser::NATURE);
    setState(1904);
    identifier();
    setState(1905);
    match(vhdlParser::IS);
    setState(1906);
    nature_definition();
    setState(1907);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Nature_definitionContext ------------------------------------------------------------------

vhdlParser::Nature_definitionContext::Nature_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Scalar_nature_definitionContext* vhdlParser::Nature_definitionContext::scalar_nature_definition() {
  return getRuleContext<vhdlParser::Scalar_nature_definitionContext>(0);
}

vhdlParser::Composite_nature_definitionContext* vhdlParser::Nature_definitionContext::composite_nature_definition() {
  return getRuleContext<vhdlParser::Composite_nature_definitionContext>(0);
}


size_t vhdlParser::Nature_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleNature_definition;
}

antlrcpp::Any vhdlParser::Nature_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitNature_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Nature_definitionContext* vhdlParser::nature_definition() {
  Nature_definitionContext *_localctx = _tracker.createInstance<Nature_definitionContext>(_ctx, getState());
  enterRule(_localctx, 332, vhdlParser::RuleNature_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1911);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1909);
        scalar_nature_definition();
        break;
      }

      case vhdlParser::ARRAY:
      case vhdlParser::RECORD: {
        enterOuterAlt(_localctx, 2);
        setState(1910);
        composite_nature_definition();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Nature_element_declarationContext ------------------------------------------------------------------

vhdlParser::Nature_element_declarationContext::Nature_element_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Identifier_listContext* vhdlParser::Nature_element_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Nature_element_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Element_subnature_definitionContext* vhdlParser::Nature_element_declarationContext::element_subnature_definition() {
  return getRuleContext<vhdlParser::Element_subnature_definitionContext>(0);
}


size_t vhdlParser::Nature_element_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleNature_element_declaration;
}

antlrcpp::Any vhdlParser::Nature_element_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitNature_element_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Nature_element_declarationContext* vhdlParser::nature_element_declaration() {
  Nature_element_declarationContext *_localctx = _tracker.createInstance<Nature_element_declarationContext>(_ctx, getState());
  enterRule(_localctx, 334, vhdlParser::RuleNature_element_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1913);
    identifier_list();
    setState(1914);
    match(vhdlParser::COLON);
    setState(1915);
    element_subnature_definition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Next_statementContext ------------------------------------------------------------------

vhdlParser::Next_statementContext::Next_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Next_statementContext::NEXT() {
  return getToken(vhdlParser::NEXT, 0);
}

tree::TerminalNode* vhdlParser::Next_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Next_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::IdentifierContext* vhdlParser::Next_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Next_statementContext::WHEN() {
  return getToken(vhdlParser::WHEN, 0);
}

vhdlParser::ConditionContext* vhdlParser::Next_statementContext::condition() {
  return getRuleContext<vhdlParser::ConditionContext>(0);
}


size_t vhdlParser::Next_statementContext::getRuleIndex() const {
  return vhdlParser::RuleNext_statement;
}

antlrcpp::Any vhdlParser::Next_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitNext_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Next_statementContext* vhdlParser::next_statement() {
  Next_statementContext *_localctx = _tracker.createInstance<Next_statementContext>(_ctx, getState());
  enterRule(_localctx, 336, vhdlParser::RuleNext_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1918);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1917);
      label_colon();
    }
    setState(1920);
    match(vhdlParser::NEXT);
    setState(1922);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1921);
      identifier();
    }
    setState(1926);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::WHEN) {
      setState(1924);
      match(vhdlParser::WHEN);
      setState(1925);
      condition();
    }
    setState(1928);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Numeric_literalContext ------------------------------------------------------------------

vhdlParser::Numeric_literalContext::Numeric_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Abstract_literalContext* vhdlParser::Numeric_literalContext::abstract_literal() {
  return getRuleContext<vhdlParser::Abstract_literalContext>(0);
}

vhdlParser::Physical_literalContext* vhdlParser::Numeric_literalContext::physical_literal() {
  return getRuleContext<vhdlParser::Physical_literalContext>(0);
}


size_t vhdlParser::Numeric_literalContext::getRuleIndex() const {
  return vhdlParser::RuleNumeric_literal;
}

antlrcpp::Any vhdlParser::Numeric_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitNumeric_literal(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Numeric_literalContext* vhdlParser::numeric_literal() {
  Numeric_literalContext *_localctx = _tracker.createInstance<Numeric_literalContext>(_ctx, getState());
  enterRule(_localctx, 338, vhdlParser::RuleNumeric_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1932);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 200, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1930);
      abstract_literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1931);
      physical_literal();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_declarationContext ------------------------------------------------------------------

vhdlParser::Object_declarationContext::Object_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Constant_declarationContext* vhdlParser::Object_declarationContext::constant_declaration() {
  return getRuleContext<vhdlParser::Constant_declarationContext>(0);
}

vhdlParser::Signal_declarationContext* vhdlParser::Object_declarationContext::signal_declaration() {
  return getRuleContext<vhdlParser::Signal_declarationContext>(0);
}

vhdlParser::Variable_declarationContext* vhdlParser::Object_declarationContext::variable_declaration() {
  return getRuleContext<vhdlParser::Variable_declarationContext>(0);
}

vhdlParser::File_declarationContext* vhdlParser::Object_declarationContext::file_declaration() {
  return getRuleContext<vhdlParser::File_declarationContext>(0);
}

vhdlParser::Terminal_declarationContext* vhdlParser::Object_declarationContext::terminal_declaration() {
  return getRuleContext<vhdlParser::Terminal_declarationContext>(0);
}

vhdlParser::Quantity_declarationContext* vhdlParser::Object_declarationContext::quantity_declaration() {
  return getRuleContext<vhdlParser::Quantity_declarationContext>(0);
}


size_t vhdlParser::Object_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleObject_declaration;
}

antlrcpp::Any vhdlParser::Object_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitObject_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Object_declarationContext* vhdlParser::object_declaration() {
  Object_declarationContext *_localctx = _tracker.createInstance<Object_declarationContext>(_ctx, getState());
  enterRule(_localctx, 340, vhdlParser::RuleObject_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1940);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::CONSTANT: {
        enterOuterAlt(_localctx, 1);
        setState(1934);
        constant_declaration();
        break;
      }

      case vhdlParser::SIGNAL: {
        enterOuterAlt(_localctx, 2);
        setState(1935);
        signal_declaration();
        break;
      }

      case vhdlParser::SHARED:
      case vhdlParser::VARIABLE: {
        enterOuterAlt(_localctx, 3);
        setState(1936);
        variable_declaration();
        break;
      }

      case vhdlParser::FILE: {
        enterOuterAlt(_localctx, 4);
        setState(1937);
        file_declaration();
        break;
      }

      case vhdlParser::TERMINAL: {
        enterOuterAlt(_localctx, 5);
        setState(1938);
        terminal_declaration();
        break;
      }

      case vhdlParser::QUANTITY: {
        enterOuterAlt(_localctx, 6);
        setState(1939);
        quantity_declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OptsContext ------------------------------------------------------------------

vhdlParser::OptsContext::OptsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::OptsContext::GUARDED() {
  return getToken(vhdlParser::GUARDED, 0);
}

vhdlParser::Delay_mechanismContext* vhdlParser::OptsContext::delay_mechanism() {
  return getRuleContext<vhdlParser::Delay_mechanismContext>(0);
}


size_t vhdlParser::OptsContext::getRuleIndex() const {
  return vhdlParser::RuleOpts;
}

antlrcpp::Any vhdlParser::OptsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitOpts(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::OptsContext* vhdlParser::opts() {
  OptsContext *_localctx = _tracker.createInstance<OptsContext>(_ctx, getState());
  enterRule(_localctx, 342, vhdlParser::RuleOpts);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1943);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::GUARDED) {
      setState(1942);
      match(vhdlParser::GUARDED);
    }
    setState(1946);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 40) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 40)) & ((1ULL << (vhdlParser::INERTIAL - 40))
      | (1ULL << (vhdlParser::REJECT - 40))
      | (1ULL << (vhdlParser::TRANSPORT - 40)))) != 0)) {
      setState(1945);
      delay_mechanism();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Package_bodyContext ------------------------------------------------------------------

vhdlParser::Package_bodyContext::Package_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Package_bodyContext::PACKAGE() {
  return getTokens(vhdlParser::PACKAGE);
}

tree::TerminalNode* vhdlParser::Package_bodyContext::PACKAGE(size_t i) {
  return getToken(vhdlParser::PACKAGE, i);
}

std::vector<tree::TerminalNode *> vhdlParser::Package_bodyContext::BODY() {
  return getTokens(vhdlParser::BODY);
}

tree::TerminalNode* vhdlParser::Package_bodyContext::BODY(size_t i) {
  return getToken(vhdlParser::BODY, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Package_bodyContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Package_bodyContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Package_bodyContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::Package_body_declarative_partContext* vhdlParser::Package_bodyContext::package_body_declarative_part() {
  return getRuleContext<vhdlParser::Package_body_declarative_partContext>(0);
}

tree::TerminalNode* vhdlParser::Package_bodyContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Package_bodyContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Package_bodyContext::getRuleIndex() const {
  return vhdlParser::RulePackage_body;
}

antlrcpp::Any vhdlParser::Package_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPackage_body(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Package_bodyContext* vhdlParser::package_body() {
  Package_bodyContext *_localctx = _tracker.createInstance<Package_bodyContext>(_ctx, getState());
  enterRule(_localctx, 344, vhdlParser::RulePackage_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1948);
    match(vhdlParser::PACKAGE);
    setState(1949);
    match(vhdlParser::BODY);
    setState(1950);
    identifier();
    setState(1951);
    match(vhdlParser::IS);
    setState(1952);
    package_body_declarative_part();
    setState(1953);
    match(vhdlParser::END);
    setState(1956);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::PACKAGE) {
      setState(1954);
      match(vhdlParser::PACKAGE);
      setState(1955);
      match(vhdlParser::BODY);
    }
    setState(1959);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1958);
      identifier();
    }
    setState(1961);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Package_body_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Package_body_declarative_itemContext::Package_body_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_declarationContext* vhdlParser::Package_body_declarative_itemContext::subprogram_declaration() {
  return getRuleContext<vhdlParser::Subprogram_declarationContext>(0);
}

vhdlParser::Subprogram_bodyContext* vhdlParser::Package_body_declarative_itemContext::subprogram_body() {
  return getRuleContext<vhdlParser::Subprogram_bodyContext>(0);
}

vhdlParser::Type_declarationContext* vhdlParser::Package_body_declarative_itemContext::type_declaration() {
  return getRuleContext<vhdlParser::Type_declarationContext>(0);
}

vhdlParser::Subtype_declarationContext* vhdlParser::Package_body_declarative_itemContext::subtype_declaration() {
  return getRuleContext<vhdlParser::Subtype_declarationContext>(0);
}

vhdlParser::Constant_declarationContext* vhdlParser::Package_body_declarative_itemContext::constant_declaration() {
  return getRuleContext<vhdlParser::Constant_declarationContext>(0);
}

vhdlParser::Variable_declarationContext* vhdlParser::Package_body_declarative_itemContext::variable_declaration() {
  return getRuleContext<vhdlParser::Variable_declarationContext>(0);
}

vhdlParser::File_declarationContext* vhdlParser::Package_body_declarative_itemContext::file_declaration() {
  return getRuleContext<vhdlParser::File_declarationContext>(0);
}

vhdlParser::Alias_declarationContext* vhdlParser::Package_body_declarative_itemContext::alias_declaration() {
  return getRuleContext<vhdlParser::Alias_declarationContext>(0);
}

vhdlParser::Use_clauseContext* vhdlParser::Package_body_declarative_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}

vhdlParser::Group_template_declarationContext* vhdlParser::Package_body_declarative_itemContext::group_template_declaration() {
  return getRuleContext<vhdlParser::Group_template_declarationContext>(0);
}

vhdlParser::Group_declarationContext* vhdlParser::Package_body_declarative_itemContext::group_declaration() {
  return getRuleContext<vhdlParser::Group_declarationContext>(0);
}


size_t vhdlParser::Package_body_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RulePackage_body_declarative_item;
}

antlrcpp::Any vhdlParser::Package_body_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPackage_body_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Package_body_declarative_itemContext* vhdlParser::package_body_declarative_item() {
  Package_body_declarative_itemContext *_localctx = _tracker.createInstance<Package_body_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 346, vhdlParser::RulePackage_body_declarative_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1974);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 206, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1963);
      subprogram_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1964);
      subprogram_body();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1965);
      type_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1966);
      subtype_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1967);
      constant_declaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1968);
      variable_declaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1969);
      file_declaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(1970);
      alias_declaration();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(1971);
      use_clause();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(1972);
      group_template_declaration();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(1973);
      group_declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Package_body_declarative_partContext ------------------------------------------------------------------

vhdlParser::Package_body_declarative_partContext::Package_body_declarative_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Package_body_declarative_itemContext *> vhdlParser::Package_body_declarative_partContext::package_body_declarative_item() {
  return getRuleContexts<vhdlParser::Package_body_declarative_itemContext>();
}

vhdlParser::Package_body_declarative_itemContext* vhdlParser::Package_body_declarative_partContext::package_body_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Package_body_declarative_itemContext>(i);
}


size_t vhdlParser::Package_body_declarative_partContext::getRuleIndex() const {
  return vhdlParser::RulePackage_body_declarative_part;
}

antlrcpp::Any vhdlParser::Package_body_declarative_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPackage_body_declarative_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Package_body_declarative_partContext* vhdlParser::package_body_declarative_part() {
  Package_body_declarative_partContext *_localctx = _tracker.createInstance<Package_body_declarative_partContext>(_ctx, getState());
  enterRule(_localctx, 348, vhdlParser::RulePackage_body_declarative_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1979);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ALIAS)
      | (1ULL << vhdlParser::CONSTANT)
      | (1ULL << vhdlParser::FILE)
      | (1ULL << vhdlParser::FUNCTION)
      | (1ULL << vhdlParser::GROUP)
      | (1ULL << vhdlParser::IMPURE))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (vhdlParser::PROCEDURE - 69))
      | (1ULL << (vhdlParser::PURE - 69))
      | (1ULL << (vhdlParser::SHARED - 69))
      | (1ULL << (vhdlParser::SUBTYPE - 69))
      | (1ULL << (vhdlParser::TYPE - 69))
      | (1ULL << (vhdlParser::USE - 69))
      | (1ULL << (vhdlParser::VARIABLE - 69)))) != 0)) {
      setState(1976);
      package_body_declarative_item();
      setState(1981);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Package_declarationContext ------------------------------------------------------------------

vhdlParser::Package_declarationContext::Package_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Package_declarationContext::PACKAGE() {
  return getTokens(vhdlParser::PACKAGE);
}

tree::TerminalNode* vhdlParser::Package_declarationContext::PACKAGE(size_t i) {
  return getToken(vhdlParser::PACKAGE, i);
}

std::vector<vhdlParser::IdentifierContext *> vhdlParser::Package_declarationContext::identifier() {
  return getRuleContexts<vhdlParser::IdentifierContext>();
}

vhdlParser::IdentifierContext* vhdlParser::Package_declarationContext::identifier(size_t i) {
  return getRuleContext<vhdlParser::IdentifierContext>(i);
}

tree::TerminalNode* vhdlParser::Package_declarationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::Package_declarative_partContext* vhdlParser::Package_declarationContext::package_declarative_part() {
  return getRuleContext<vhdlParser::Package_declarative_partContext>(0);
}

tree::TerminalNode* vhdlParser::Package_declarationContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Package_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Package_declarationContext::getRuleIndex() const {
  return vhdlParser::RulePackage_declaration;
}

antlrcpp::Any vhdlParser::Package_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPackage_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Package_declarationContext* vhdlParser::package_declaration() {
  Package_declarationContext *_localctx = _tracker.createInstance<Package_declarationContext>(_ctx, getState());
  enterRule(_localctx, 350, vhdlParser::RulePackage_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1982);
    match(vhdlParser::PACKAGE);
    setState(1983);
    identifier();
    setState(1984);
    match(vhdlParser::IS);
    setState(1985);
    package_declarative_part();
    setState(1986);
    match(vhdlParser::END);
    setState(1988);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::PACKAGE) {
      setState(1987);
      match(vhdlParser::PACKAGE);
    }
    setState(1991);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(1990);
      identifier();
    }
    setState(1993);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Package_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Package_declarative_itemContext::Package_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_declarationContext* vhdlParser::Package_declarative_itemContext::subprogram_declaration() {
  return getRuleContext<vhdlParser::Subprogram_declarationContext>(0);
}

vhdlParser::Type_declarationContext* vhdlParser::Package_declarative_itemContext::type_declaration() {
  return getRuleContext<vhdlParser::Type_declarationContext>(0);
}

vhdlParser::Subtype_declarationContext* vhdlParser::Package_declarative_itemContext::subtype_declaration() {
  return getRuleContext<vhdlParser::Subtype_declarationContext>(0);
}

vhdlParser::Constant_declarationContext* vhdlParser::Package_declarative_itemContext::constant_declaration() {
  return getRuleContext<vhdlParser::Constant_declarationContext>(0);
}

vhdlParser::Signal_declarationContext* vhdlParser::Package_declarative_itemContext::signal_declaration() {
  return getRuleContext<vhdlParser::Signal_declarationContext>(0);
}

vhdlParser::Variable_declarationContext* vhdlParser::Package_declarative_itemContext::variable_declaration() {
  return getRuleContext<vhdlParser::Variable_declarationContext>(0);
}

vhdlParser::File_declarationContext* vhdlParser::Package_declarative_itemContext::file_declaration() {
  return getRuleContext<vhdlParser::File_declarationContext>(0);
}

vhdlParser::Alias_declarationContext* vhdlParser::Package_declarative_itemContext::alias_declaration() {
  return getRuleContext<vhdlParser::Alias_declarationContext>(0);
}

vhdlParser::Component_declarationContext* vhdlParser::Package_declarative_itemContext::component_declaration() {
  return getRuleContext<vhdlParser::Component_declarationContext>(0);
}

vhdlParser::Attribute_declarationContext* vhdlParser::Package_declarative_itemContext::attribute_declaration() {
  return getRuleContext<vhdlParser::Attribute_declarationContext>(0);
}

vhdlParser::Attribute_specificationContext* vhdlParser::Package_declarative_itemContext::attribute_specification() {
  return getRuleContext<vhdlParser::Attribute_specificationContext>(0);
}

vhdlParser::Disconnection_specificationContext* vhdlParser::Package_declarative_itemContext::disconnection_specification() {
  return getRuleContext<vhdlParser::Disconnection_specificationContext>(0);
}

vhdlParser::Use_clauseContext* vhdlParser::Package_declarative_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}

vhdlParser::Group_template_declarationContext* vhdlParser::Package_declarative_itemContext::group_template_declaration() {
  return getRuleContext<vhdlParser::Group_template_declarationContext>(0);
}

vhdlParser::Group_declarationContext* vhdlParser::Package_declarative_itemContext::group_declaration() {
  return getRuleContext<vhdlParser::Group_declarationContext>(0);
}

vhdlParser::Nature_declarationContext* vhdlParser::Package_declarative_itemContext::nature_declaration() {
  return getRuleContext<vhdlParser::Nature_declarationContext>(0);
}

vhdlParser::Subnature_declarationContext* vhdlParser::Package_declarative_itemContext::subnature_declaration() {
  return getRuleContext<vhdlParser::Subnature_declarationContext>(0);
}

vhdlParser::Terminal_declarationContext* vhdlParser::Package_declarative_itemContext::terminal_declaration() {
  return getRuleContext<vhdlParser::Terminal_declarationContext>(0);
}


size_t vhdlParser::Package_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RulePackage_declarative_item;
}

antlrcpp::Any vhdlParser::Package_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPackage_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Package_declarative_itemContext* vhdlParser::package_declarative_item() {
  Package_declarative_itemContext *_localctx = _tracker.createInstance<Package_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 352, vhdlParser::RulePackage_declarative_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2013);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 210, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1995);
      subprogram_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1996);
      type_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1997);
      subtype_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1998);
      constant_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1999);
      signal_declaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(2000);
      variable_declaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(2001);
      file_declaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(2002);
      alias_declaration();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(2003);
      component_declaration();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(2004);
      attribute_declaration();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(2005);
      attribute_specification();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(2006);
      disconnection_specification();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(2007);
      use_clause();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(2008);
      group_template_declaration();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(2009);
      group_declaration();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(2010);
      nature_declaration();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(2011);
      subnature_declaration();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(2012);
      terminal_declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Package_declarative_partContext ------------------------------------------------------------------

vhdlParser::Package_declarative_partContext::Package_declarative_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Package_declarative_itemContext *> vhdlParser::Package_declarative_partContext::package_declarative_item() {
  return getRuleContexts<vhdlParser::Package_declarative_itemContext>();
}

vhdlParser::Package_declarative_itemContext* vhdlParser::Package_declarative_partContext::package_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Package_declarative_itemContext>(i);
}


size_t vhdlParser::Package_declarative_partContext::getRuleIndex() const {
  return vhdlParser::RulePackage_declarative_part;
}

antlrcpp::Any vhdlParser::Package_declarative_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPackage_declarative_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Package_declarative_partContext* vhdlParser::package_declarative_part() {
  Package_declarative_partContext *_localctx = _tracker.createInstance<Package_declarative_partContext>(_ctx, getState());
  enterRule(_localctx, 354, vhdlParser::RulePackage_declarative_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2018);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ALIAS)
      | (1ULL << vhdlParser::ATTRIBUTE)
      | (1ULL << vhdlParser::COMPONENT)
      | (1ULL << vhdlParser::CONSTANT)
      | (1ULL << vhdlParser::DISCONNECT)
      | (1ULL << vhdlParser::FILE)
      | (1ULL << vhdlParser::FUNCTION)
      | (1ULL << vhdlParser::GROUP)
      | (1ULL << vhdlParser::IMPURE)
      | (1ULL << vhdlParser::NATURE))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (vhdlParser::PROCEDURE - 69))
      | (1ULL << (vhdlParser::PURE - 69))
      | (1ULL << (vhdlParser::SHARED - 69))
      | (1ULL << (vhdlParser::SIGNAL - 69))
      | (1ULL << (vhdlParser::SUBNATURE - 69))
      | (1ULL << (vhdlParser::SUBTYPE - 69))
      | (1ULL << (vhdlParser::TERMINAL - 69))
      | (1ULL << (vhdlParser::TYPE - 69))
      | (1ULL << (vhdlParser::USE - 69))
      | (1ULL << (vhdlParser::VARIABLE - 69)))) != 0)) {
      setState(2015);
      package_declarative_item();
      setState(2020);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_specificationContext ------------------------------------------------------------------

vhdlParser::Parameter_specificationContext::Parameter_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Parameter_specificationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Parameter_specificationContext::IN() {
  return getToken(vhdlParser::IN, 0);
}

vhdlParser::Discrete_rangeContext* vhdlParser::Parameter_specificationContext::discrete_range() {
  return getRuleContext<vhdlParser::Discrete_rangeContext>(0);
}


size_t vhdlParser::Parameter_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleParameter_specification;
}

antlrcpp::Any vhdlParser::Parameter_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitParameter_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Parameter_specificationContext* vhdlParser::parameter_specification() {
  Parameter_specificationContext *_localctx = _tracker.createInstance<Parameter_specificationContext>(_ctx, getState());
  enterRule(_localctx, 356, vhdlParser::RuleParameter_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2021);
    identifier();
    setState(2022);
    match(vhdlParser::IN);
    setState(2023);
    discrete_range();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Physical_literalContext ------------------------------------------------------------------

vhdlParser::Physical_literalContext::Physical_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Abstract_literalContext* vhdlParser::Physical_literalContext::abstract_literal() {
  return getRuleContext<vhdlParser::Abstract_literalContext>(0);
}

vhdlParser::IdentifierContext* vhdlParser::Physical_literalContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Physical_literalContext::getRuleIndex() const {
  return vhdlParser::RulePhysical_literal;
}

antlrcpp::Any vhdlParser::Physical_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPhysical_literal(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Physical_literalContext* vhdlParser::physical_literal() {
  Physical_literalContext *_localctx = _tracker.createInstance<Physical_literalContext>(_ctx, getState());
  enterRule(_localctx, 358, vhdlParser::RulePhysical_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2025);
    abstract_literal();

    setState(2026);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Physical_type_definitionContext ------------------------------------------------------------------

vhdlParser::Physical_type_definitionContext::Physical_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Range_constraintContext* vhdlParser::Physical_type_definitionContext::range_constraint() {
  return getRuleContext<vhdlParser::Range_constraintContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Physical_type_definitionContext::UNITS() {
  return getTokens(vhdlParser::UNITS);
}

tree::TerminalNode* vhdlParser::Physical_type_definitionContext::UNITS(size_t i) {
  return getToken(vhdlParser::UNITS, i);
}

vhdlParser::Base_unit_declarationContext* vhdlParser::Physical_type_definitionContext::base_unit_declaration() {
  return getRuleContext<vhdlParser::Base_unit_declarationContext>(0);
}

tree::TerminalNode* vhdlParser::Physical_type_definitionContext::END() {
  return getToken(vhdlParser::END, 0);
}

std::vector<vhdlParser::Secondary_unit_declarationContext *> vhdlParser::Physical_type_definitionContext::secondary_unit_declaration() {
  return getRuleContexts<vhdlParser::Secondary_unit_declarationContext>();
}

vhdlParser::Secondary_unit_declarationContext* vhdlParser::Physical_type_definitionContext::secondary_unit_declaration(size_t i) {
  return getRuleContext<vhdlParser::Secondary_unit_declarationContext>(i);
}

vhdlParser::IdentifierContext* vhdlParser::Physical_type_definitionContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Physical_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RulePhysical_type_definition;
}

antlrcpp::Any vhdlParser::Physical_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPhysical_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Physical_type_definitionContext* vhdlParser::physical_type_definition() {
  Physical_type_definitionContext *_localctx = _tracker.createInstance<Physical_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 360, vhdlParser::RulePhysical_type_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2028);
    range_constraint();
    setState(2029);
    match(vhdlParser::UNITS);
    setState(2030);
    base_unit_declaration();
    setState(2034);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2031);
      secondary_unit_declaration();
      setState(2036);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2037);
    match(vhdlParser::END);
    setState(2038);
    match(vhdlParser::UNITS);
    setState(2040);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2039);
      identifier();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Port_clauseContext ------------------------------------------------------------------

vhdlParser::Port_clauseContext::Port_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Port_clauseContext::PORT() {
  return getToken(vhdlParser::PORT, 0);
}

tree::TerminalNode* vhdlParser::Port_clauseContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Port_listContext* vhdlParser::Port_clauseContext::port_list() {
  return getRuleContext<vhdlParser::Port_listContext>(0);
}

tree::TerminalNode* vhdlParser::Port_clauseContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Port_clauseContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Port_clauseContext::getRuleIndex() const {
  return vhdlParser::RulePort_clause;
}

antlrcpp::Any vhdlParser::Port_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPort_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Port_clauseContext* vhdlParser::port_clause() {
  Port_clauseContext *_localctx = _tracker.createInstance<Port_clauseContext>(_ctx, getState());
  enterRule(_localctx, 362, vhdlParser::RulePort_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2042);
    match(vhdlParser::PORT);
    setState(2043);
    match(vhdlParser::LPAREN);
    setState(2044);
    port_list();
    setState(2045);
    match(vhdlParser::RPAREN);
    setState(2046);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Port_listContext ------------------------------------------------------------------

vhdlParser::Port_listContext::Port_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Interface_port_listContext* vhdlParser::Port_listContext::interface_port_list() {
  return getRuleContext<vhdlParser::Interface_port_listContext>(0);
}


size_t vhdlParser::Port_listContext::getRuleIndex() const {
  return vhdlParser::RulePort_list;
}

antlrcpp::Any vhdlParser::Port_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPort_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Port_listContext* vhdlParser::port_list() {
  Port_listContext *_localctx = _tracker.createInstance<Port_listContext>(_ctx, getState());
  enterRule(_localctx, 364, vhdlParser::RulePort_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2048);
    interface_port_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Port_map_aspectContext ------------------------------------------------------------------

vhdlParser::Port_map_aspectContext::Port_map_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Port_map_aspectContext::PORT() {
  return getToken(vhdlParser::PORT, 0);
}

tree::TerminalNode* vhdlParser::Port_map_aspectContext::MAP() {
  return getToken(vhdlParser::MAP, 0);
}

tree::TerminalNode* vhdlParser::Port_map_aspectContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Association_listContext* vhdlParser::Port_map_aspectContext::association_list() {
  return getRuleContext<vhdlParser::Association_listContext>(0);
}

tree::TerminalNode* vhdlParser::Port_map_aspectContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Port_map_aspectContext::getRuleIndex() const {
  return vhdlParser::RulePort_map_aspect;
}

antlrcpp::Any vhdlParser::Port_map_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPort_map_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Port_map_aspectContext* vhdlParser::port_map_aspect() {
  Port_map_aspectContext *_localctx = _tracker.createInstance<Port_map_aspectContext>(_ctx, getState());
  enterRule(_localctx, 366, vhdlParser::RulePort_map_aspect);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2050);
    match(vhdlParser::PORT);
    setState(2051);
    match(vhdlParser::MAP);
    setState(2052);
    match(vhdlParser::LPAREN);
    setState(2053);
    association_list();
    setState(2054);
    match(vhdlParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

vhdlParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::LiteralContext* vhdlParser::PrimaryContext::literal() {
  return getRuleContext<vhdlParser::LiteralContext>(0);
}

vhdlParser::Qualified_expressionContext* vhdlParser::PrimaryContext::qualified_expression() {
  return getRuleContext<vhdlParser::Qualified_expressionContext>(0);
}

tree::TerminalNode* vhdlParser::PrimaryContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::PrimaryContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::PrimaryContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

vhdlParser::AllocatorContext* vhdlParser::PrimaryContext::allocator() {
  return getRuleContext<vhdlParser::AllocatorContext>(0);
}

vhdlParser::AggregateContext* vhdlParser::PrimaryContext::aggregate() {
  return getRuleContext<vhdlParser::AggregateContext>(0);
}

vhdlParser::NameContext* vhdlParser::PrimaryContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}


size_t vhdlParser::PrimaryContext::getRuleIndex() const {
  return vhdlParser::RulePrimary;
}

antlrcpp::Any vhdlParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::PrimaryContext* vhdlParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 368, vhdlParser::RulePrimary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2065);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 214, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2056);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2057);
      qualified_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2058);
      match(vhdlParser::LPAREN);
      setState(2059);
      expression();
      setState(2060);
      match(vhdlParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(2062);
      allocator();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(2063);
      aggregate();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(2064);
      name();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primary_unitContext ------------------------------------------------------------------

vhdlParser::Primary_unitContext::Primary_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Entity_declarationContext* vhdlParser::Primary_unitContext::entity_declaration() {
  return getRuleContext<vhdlParser::Entity_declarationContext>(0);
}

vhdlParser::Configuration_declarationContext* vhdlParser::Primary_unitContext::configuration_declaration() {
  return getRuleContext<vhdlParser::Configuration_declarationContext>(0);
}

vhdlParser::Package_declarationContext* vhdlParser::Primary_unitContext::package_declaration() {
  return getRuleContext<vhdlParser::Package_declarationContext>(0);
}


size_t vhdlParser::Primary_unitContext::getRuleIndex() const {
  return vhdlParser::RulePrimary_unit;
}

antlrcpp::Any vhdlParser::Primary_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitPrimary_unit(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Primary_unitContext* vhdlParser::primary_unit() {
  Primary_unitContext *_localctx = _tracker.createInstance<Primary_unitContext>(_ctx, getState());
  enterRule(_localctx, 370, vhdlParser::RulePrimary_unit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2070);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::ENTITY: {
        enterOuterAlt(_localctx, 1);
        setState(2067);
        entity_declaration();
        break;
      }

      case vhdlParser::CONFIGURATION: {
        enterOuterAlt(_localctx, 2);
        setState(2068);
        configuration_declaration();
        break;
      }

      case vhdlParser::PACKAGE: {
        enterOuterAlt(_localctx, 3);
        setState(2069);
        package_declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Procedural_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Procedural_declarative_itemContext::Procedural_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_declarationContext* vhdlParser::Procedural_declarative_itemContext::subprogram_declaration() {
  return getRuleContext<vhdlParser::Subprogram_declarationContext>(0);
}

vhdlParser::Subprogram_bodyContext* vhdlParser::Procedural_declarative_itemContext::subprogram_body() {
  return getRuleContext<vhdlParser::Subprogram_bodyContext>(0);
}

vhdlParser::Type_declarationContext* vhdlParser::Procedural_declarative_itemContext::type_declaration() {
  return getRuleContext<vhdlParser::Type_declarationContext>(0);
}

vhdlParser::Subtype_declarationContext* vhdlParser::Procedural_declarative_itemContext::subtype_declaration() {
  return getRuleContext<vhdlParser::Subtype_declarationContext>(0);
}

vhdlParser::Constant_declarationContext* vhdlParser::Procedural_declarative_itemContext::constant_declaration() {
  return getRuleContext<vhdlParser::Constant_declarationContext>(0);
}

vhdlParser::Variable_declarationContext* vhdlParser::Procedural_declarative_itemContext::variable_declaration() {
  return getRuleContext<vhdlParser::Variable_declarationContext>(0);
}

vhdlParser::Alias_declarationContext* vhdlParser::Procedural_declarative_itemContext::alias_declaration() {
  return getRuleContext<vhdlParser::Alias_declarationContext>(0);
}

vhdlParser::Attribute_declarationContext* vhdlParser::Procedural_declarative_itemContext::attribute_declaration() {
  return getRuleContext<vhdlParser::Attribute_declarationContext>(0);
}

vhdlParser::Attribute_specificationContext* vhdlParser::Procedural_declarative_itemContext::attribute_specification() {
  return getRuleContext<vhdlParser::Attribute_specificationContext>(0);
}

vhdlParser::Use_clauseContext* vhdlParser::Procedural_declarative_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}

vhdlParser::Group_template_declarationContext* vhdlParser::Procedural_declarative_itemContext::group_template_declaration() {
  return getRuleContext<vhdlParser::Group_template_declarationContext>(0);
}

vhdlParser::Group_declarationContext* vhdlParser::Procedural_declarative_itemContext::group_declaration() {
  return getRuleContext<vhdlParser::Group_declarationContext>(0);
}


size_t vhdlParser::Procedural_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleProcedural_declarative_item;
}

antlrcpp::Any vhdlParser::Procedural_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitProcedural_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Procedural_declarative_itemContext* vhdlParser::procedural_declarative_item() {
  Procedural_declarative_itemContext *_localctx = _tracker.createInstance<Procedural_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 372, vhdlParser::RuleProcedural_declarative_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2084);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 216, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2072);
      subprogram_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2073);
      subprogram_body();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2074);
      type_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(2075);
      subtype_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(2076);
      constant_declaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(2077);
      variable_declaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(2078);
      alias_declaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(2079);
      attribute_declaration();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(2080);
      attribute_specification();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(2081);
      use_clause();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(2082);
      group_template_declaration();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(2083);
      group_declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Procedural_declarative_partContext ------------------------------------------------------------------

vhdlParser::Procedural_declarative_partContext::Procedural_declarative_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Procedural_declarative_itemContext *> vhdlParser::Procedural_declarative_partContext::procedural_declarative_item() {
  return getRuleContexts<vhdlParser::Procedural_declarative_itemContext>();
}

vhdlParser::Procedural_declarative_itemContext* vhdlParser::Procedural_declarative_partContext::procedural_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Procedural_declarative_itemContext>(i);
}


size_t vhdlParser::Procedural_declarative_partContext::getRuleIndex() const {
  return vhdlParser::RuleProcedural_declarative_part;
}

antlrcpp::Any vhdlParser::Procedural_declarative_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitProcedural_declarative_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Procedural_declarative_partContext* vhdlParser::procedural_declarative_part() {
  Procedural_declarative_partContext *_localctx = _tracker.createInstance<Procedural_declarative_partContext>(_ctx, getState());
  enterRule(_localctx, 374, vhdlParser::RuleProcedural_declarative_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2089);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ALIAS)
      | (1ULL << vhdlParser::ATTRIBUTE)
      | (1ULL << vhdlParser::CONSTANT)
      | (1ULL << vhdlParser::FUNCTION)
      | (1ULL << vhdlParser::GROUP)
      | (1ULL << vhdlParser::IMPURE))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (vhdlParser::PROCEDURE - 69))
      | (1ULL << (vhdlParser::PURE - 69))
      | (1ULL << (vhdlParser::SHARED - 69))
      | (1ULL << (vhdlParser::SUBTYPE - 69))
      | (1ULL << (vhdlParser::TYPE - 69))
      | (1ULL << (vhdlParser::USE - 69))
      | (1ULL << (vhdlParser::VARIABLE - 69)))) != 0)) {
      setState(2086);
      procedural_declarative_item();
      setState(2091);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Procedural_statement_partContext ------------------------------------------------------------------

vhdlParser::Procedural_statement_partContext::Procedural_statement_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Sequential_statementContext *> vhdlParser::Procedural_statement_partContext::sequential_statement() {
  return getRuleContexts<vhdlParser::Sequential_statementContext>();
}

vhdlParser::Sequential_statementContext* vhdlParser::Procedural_statement_partContext::sequential_statement(size_t i) {
  return getRuleContext<vhdlParser::Sequential_statementContext>(i);
}


size_t vhdlParser::Procedural_statement_partContext::getRuleIndex() const {
  return vhdlParser::RuleProcedural_statement_part;
}

antlrcpp::Any vhdlParser::Procedural_statement_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitProcedural_statement_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Procedural_statement_partContext* vhdlParser::procedural_statement_part() {
  Procedural_statement_partContext *_localctx = _tracker.createInstance<Procedural_statement_partContext>(_ctx, getState());
  enterRule(_localctx, 376, vhdlParser::RuleProcedural_statement_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2095);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ASSERT)
      | (1ULL << vhdlParser::BREAK)
      | (1ULL << vhdlParser::CASE)
      | (1ULL << vhdlParser::EXIT)
      | (1ULL << vhdlParser::FOR)
      | (1ULL << vhdlParser::IF)
      | (1ULL << vhdlParser::LOOP)
      | (1ULL << vhdlParser::NEXT)
      | (1ULL << vhdlParser::NULL_SYM))) != 0) || ((((_la - 81) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 81)) & ((1ULL << (vhdlParser::REPORT - 81))
      | (1ULL << (vhdlParser::RETURN - 81))
      | (1ULL << (vhdlParser::WAIT - 81))
      | (1ULL << (vhdlParser::WITH - 81))
      | (1ULL << (vhdlParser::WHILE - 81))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 81))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 81)))) != 0) || _la == vhdlParser::LPAREN) {
      setState(2092);
      sequential_statement();
      setState(2097);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Procedure_callContext ------------------------------------------------------------------

vhdlParser::Procedure_callContext::Procedure_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Selected_nameContext* vhdlParser::Procedure_callContext::selected_name() {
  return getRuleContext<vhdlParser::Selected_nameContext>(0);
}

tree::TerminalNode* vhdlParser::Procedure_callContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Actual_parameter_partContext* vhdlParser::Procedure_callContext::actual_parameter_part() {
  return getRuleContext<vhdlParser::Actual_parameter_partContext>(0);
}

tree::TerminalNode* vhdlParser::Procedure_callContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Procedure_callContext::getRuleIndex() const {
  return vhdlParser::RuleProcedure_call;
}

antlrcpp::Any vhdlParser::Procedure_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitProcedure_call(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Procedure_callContext* vhdlParser::procedure_call() {
  Procedure_callContext *_localctx = _tracker.createInstance<Procedure_callContext>(_ctx, getState());
  enterRule(_localctx, 378, vhdlParser::RuleProcedure_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2098);
    selected_name();
    setState(2103);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LPAREN) {
      setState(2099);
      match(vhdlParser::LPAREN);
      setState(2100);
      actual_parameter_part();
      setState(2101);
      match(vhdlParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Procedure_call_statementContext ------------------------------------------------------------------

vhdlParser::Procedure_call_statementContext::Procedure_call_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Procedure_callContext* vhdlParser::Procedure_call_statementContext::procedure_call() {
  return getRuleContext<vhdlParser::Procedure_callContext>(0);
}

tree::TerminalNode* vhdlParser::Procedure_call_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Procedure_call_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}


size_t vhdlParser::Procedure_call_statementContext::getRuleIndex() const {
  return vhdlParser::RuleProcedure_call_statement;
}

antlrcpp::Any vhdlParser::Procedure_call_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitProcedure_call_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Procedure_call_statementContext* vhdlParser::procedure_call_statement() {
  Procedure_call_statementContext *_localctx = _tracker.createInstance<Procedure_call_statementContext>(_ctx, getState());
  enterRule(_localctx, 380, vhdlParser::RuleProcedure_call_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2106);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 220, _ctx)) {
    case 1: {
      setState(2105);
      label_colon();
      break;
    }

    }
    setState(2108);
    procedure_call();
    setState(2109);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Process_declarative_itemContext::Process_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_declarationContext* vhdlParser::Process_declarative_itemContext::subprogram_declaration() {
  return getRuleContext<vhdlParser::Subprogram_declarationContext>(0);
}

vhdlParser::Subprogram_bodyContext* vhdlParser::Process_declarative_itemContext::subprogram_body() {
  return getRuleContext<vhdlParser::Subprogram_bodyContext>(0);
}

vhdlParser::Type_declarationContext* vhdlParser::Process_declarative_itemContext::type_declaration() {
  return getRuleContext<vhdlParser::Type_declarationContext>(0);
}

vhdlParser::Subtype_declarationContext* vhdlParser::Process_declarative_itemContext::subtype_declaration() {
  return getRuleContext<vhdlParser::Subtype_declarationContext>(0);
}

vhdlParser::Constant_declarationContext* vhdlParser::Process_declarative_itemContext::constant_declaration() {
  return getRuleContext<vhdlParser::Constant_declarationContext>(0);
}

vhdlParser::Variable_declarationContext* vhdlParser::Process_declarative_itemContext::variable_declaration() {
  return getRuleContext<vhdlParser::Variable_declarationContext>(0);
}

vhdlParser::File_declarationContext* vhdlParser::Process_declarative_itemContext::file_declaration() {
  return getRuleContext<vhdlParser::File_declarationContext>(0);
}

vhdlParser::Alias_declarationContext* vhdlParser::Process_declarative_itemContext::alias_declaration() {
  return getRuleContext<vhdlParser::Alias_declarationContext>(0);
}

vhdlParser::Attribute_declarationContext* vhdlParser::Process_declarative_itemContext::attribute_declaration() {
  return getRuleContext<vhdlParser::Attribute_declarationContext>(0);
}

vhdlParser::Attribute_specificationContext* vhdlParser::Process_declarative_itemContext::attribute_specification() {
  return getRuleContext<vhdlParser::Attribute_specificationContext>(0);
}

vhdlParser::Use_clauseContext* vhdlParser::Process_declarative_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}

vhdlParser::Group_template_declarationContext* vhdlParser::Process_declarative_itemContext::group_template_declaration() {
  return getRuleContext<vhdlParser::Group_template_declarationContext>(0);
}

vhdlParser::Group_declarationContext* vhdlParser::Process_declarative_itemContext::group_declaration() {
  return getRuleContext<vhdlParser::Group_declarationContext>(0);
}


size_t vhdlParser::Process_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleProcess_declarative_item;
}

antlrcpp::Any vhdlParser::Process_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitProcess_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Process_declarative_itemContext* vhdlParser::process_declarative_item() {
  Process_declarative_itemContext *_localctx = _tracker.createInstance<Process_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 382, vhdlParser::RuleProcess_declarative_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2124);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 221, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2111);
      subprogram_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2112);
      subprogram_body();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2113);
      type_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(2114);
      subtype_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(2115);
      constant_declaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(2116);
      variable_declaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(2117);
      file_declaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(2118);
      alias_declaration();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(2119);
      attribute_declaration();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(2120);
      attribute_specification();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(2121);
      use_clause();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(2122);
      group_template_declaration();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(2123);
      group_declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_declarative_partContext ------------------------------------------------------------------

vhdlParser::Process_declarative_partContext::Process_declarative_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Process_declarative_itemContext *> vhdlParser::Process_declarative_partContext::process_declarative_item() {
  return getRuleContexts<vhdlParser::Process_declarative_itemContext>();
}

vhdlParser::Process_declarative_itemContext* vhdlParser::Process_declarative_partContext::process_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Process_declarative_itemContext>(i);
}


size_t vhdlParser::Process_declarative_partContext::getRuleIndex() const {
  return vhdlParser::RuleProcess_declarative_part;
}

antlrcpp::Any vhdlParser::Process_declarative_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitProcess_declarative_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Process_declarative_partContext* vhdlParser::process_declarative_part() {
  Process_declarative_partContext *_localctx = _tracker.createInstance<Process_declarative_partContext>(_ctx, getState());
  enterRule(_localctx, 384, vhdlParser::RuleProcess_declarative_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ALIAS)
      | (1ULL << vhdlParser::ATTRIBUTE)
      | (1ULL << vhdlParser::CONSTANT)
      | (1ULL << vhdlParser::FILE)
      | (1ULL << vhdlParser::FUNCTION)
      | (1ULL << vhdlParser::GROUP)
      | (1ULL << vhdlParser::IMPURE))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (vhdlParser::PROCEDURE - 69))
      | (1ULL << (vhdlParser::PURE - 69))
      | (1ULL << (vhdlParser::SHARED - 69))
      | (1ULL << (vhdlParser::SUBTYPE - 69))
      | (1ULL << (vhdlParser::TYPE - 69))
      | (1ULL << (vhdlParser::USE - 69))
      | (1ULL << (vhdlParser::VARIABLE - 69)))) != 0)) {
      setState(2126);
      process_declarative_item();
      setState(2131);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_statementContext ------------------------------------------------------------------

vhdlParser::Process_statementContext::Process_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Process_statementContext::PROCESS() {
  return getTokens(vhdlParser::PROCESS);
}

tree::TerminalNode* vhdlParser::Process_statementContext::PROCESS(size_t i) {
  return getToken(vhdlParser::PROCESS, i);
}

vhdlParser::Process_declarative_partContext* vhdlParser::Process_statementContext::process_declarative_part() {
  return getRuleContext<vhdlParser::Process_declarative_partContext>(0);
}

tree::TerminalNode* vhdlParser::Process_statementContext::BEGIN() {
  return getToken(vhdlParser::BEGIN, 0);
}

vhdlParser::Process_statement_partContext* vhdlParser::Process_statementContext::process_statement_part() {
  return getRuleContext<vhdlParser::Process_statement_partContext>(0);
}

tree::TerminalNode* vhdlParser::Process_statementContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Process_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Process_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Process_statementContext::POSTPONED() {
  return getTokens(vhdlParser::POSTPONED);
}

tree::TerminalNode* vhdlParser::Process_statementContext::POSTPONED(size_t i) {
  return getToken(vhdlParser::POSTPONED, i);
}

tree::TerminalNode* vhdlParser::Process_statementContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Sensitivity_listContext* vhdlParser::Process_statementContext::sensitivity_list() {
  return getRuleContext<vhdlParser::Sensitivity_listContext>(0);
}

tree::TerminalNode* vhdlParser::Process_statementContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Process_statementContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Process_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Process_statementContext::getRuleIndex() const {
  return vhdlParser::RuleProcess_statement;
}

antlrcpp::Any vhdlParser::Process_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitProcess_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Process_statementContext* vhdlParser::process_statement() {
  Process_statementContext *_localctx = _tracker.createInstance<Process_statementContext>(_ctx, getState());
  enterRule(_localctx, 386, vhdlParser::RuleProcess_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2133);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2132);
      label_colon();
    }
    setState(2136);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::POSTPONED) {
      setState(2135);
      match(vhdlParser::POSTPONED);
    }
    setState(2138);
    match(vhdlParser::PROCESS);
    setState(2143);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LPAREN) {
      setState(2139);
      match(vhdlParser::LPAREN);
      setState(2140);
      sensitivity_list();
      setState(2141);
      match(vhdlParser::RPAREN);
    }
    setState(2146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IS) {
      setState(2145);
      match(vhdlParser::IS);
    }
    setState(2148);
    process_declarative_part();
    setState(2149);
    match(vhdlParser::BEGIN);
    setState(2150);
    process_statement_part();
    setState(2151);
    match(vhdlParser::END);
    setState(2153);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::POSTPONED) {
      setState(2152);
      match(vhdlParser::POSTPONED);
    }
    setState(2155);
    match(vhdlParser::PROCESS);
    setState(2157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2156);
      identifier();
    }
    setState(2159);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_statement_partContext ------------------------------------------------------------------

vhdlParser::Process_statement_partContext::Process_statement_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Sequential_statementContext *> vhdlParser::Process_statement_partContext::sequential_statement() {
  return getRuleContexts<vhdlParser::Sequential_statementContext>();
}

vhdlParser::Sequential_statementContext* vhdlParser::Process_statement_partContext::sequential_statement(size_t i) {
  return getRuleContext<vhdlParser::Sequential_statementContext>(i);
}


size_t vhdlParser::Process_statement_partContext::getRuleIndex() const {
  return vhdlParser::RuleProcess_statement_part;
}

antlrcpp::Any vhdlParser::Process_statement_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitProcess_statement_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Process_statement_partContext* vhdlParser::process_statement_part() {
  Process_statement_partContext *_localctx = _tracker.createInstance<Process_statement_partContext>(_ctx, getState());
  enterRule(_localctx, 388, vhdlParser::RuleProcess_statement_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ASSERT)
      | (1ULL << vhdlParser::BREAK)
      | (1ULL << vhdlParser::CASE)
      | (1ULL << vhdlParser::EXIT)
      | (1ULL << vhdlParser::FOR)
      | (1ULL << vhdlParser::IF)
      | (1ULL << vhdlParser::LOOP)
      | (1ULL << vhdlParser::NEXT)
      | (1ULL << vhdlParser::NULL_SYM))) != 0) || ((((_la - 81) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 81)) & ((1ULL << (vhdlParser::REPORT - 81))
      | (1ULL << (vhdlParser::RETURN - 81))
      | (1ULL << (vhdlParser::WAIT - 81))
      | (1ULL << (vhdlParser::WITH - 81))
      | (1ULL << (vhdlParser::WHILE - 81))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 81))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 81)))) != 0) || _la == vhdlParser::LPAREN) {
      setState(2161);
      sequential_statement();
      setState(2166);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Qualified_expressionContext ------------------------------------------------------------------

vhdlParser::Qualified_expressionContext::Qualified_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subtype_indicationContext* vhdlParser::Qualified_expressionContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Qualified_expressionContext::APOSTROPHE() {
  return getToken(vhdlParser::APOSTROPHE, 0);
}

vhdlParser::AggregateContext* vhdlParser::Qualified_expressionContext::aggregate() {
  return getRuleContext<vhdlParser::AggregateContext>(0);
}

tree::TerminalNode* vhdlParser::Qualified_expressionContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Qualified_expressionContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Qualified_expressionContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Qualified_expressionContext::getRuleIndex() const {
  return vhdlParser::RuleQualified_expression;
}

antlrcpp::Any vhdlParser::Qualified_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitQualified_expression(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Qualified_expressionContext* vhdlParser::qualified_expression() {
  Qualified_expressionContext *_localctx = _tracker.createInstance<Qualified_expressionContext>(_ctx, getState());
  enterRule(_localctx, 390, vhdlParser::RuleQualified_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2167);
    subtype_indication();
    setState(2168);
    match(vhdlParser::APOSTROPHE);
    setState(2174);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 230, _ctx)) {
    case 1: {
      setState(2169);
      aggregate();
      break;
    }

    case 2: {
      setState(2170);
      match(vhdlParser::LPAREN);
      setState(2171);
      expression();
      setState(2172);
      match(vhdlParser::RPAREN);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Quantity_declarationContext ------------------------------------------------------------------

vhdlParser::Quantity_declarationContext::Quantity_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Free_quantity_declarationContext* vhdlParser::Quantity_declarationContext::free_quantity_declaration() {
  return getRuleContext<vhdlParser::Free_quantity_declarationContext>(0);
}

vhdlParser::Branch_quantity_declarationContext* vhdlParser::Quantity_declarationContext::branch_quantity_declaration() {
  return getRuleContext<vhdlParser::Branch_quantity_declarationContext>(0);
}

vhdlParser::Source_quantity_declarationContext* vhdlParser::Quantity_declarationContext::source_quantity_declaration() {
  return getRuleContext<vhdlParser::Source_quantity_declarationContext>(0);
}


size_t vhdlParser::Quantity_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleQuantity_declaration;
}

antlrcpp::Any vhdlParser::Quantity_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitQuantity_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Quantity_declarationContext* vhdlParser::quantity_declaration() {
  Quantity_declarationContext *_localctx = _tracker.createInstance<Quantity_declarationContext>(_ctx, getState());
  enterRule(_localctx, 392, vhdlParser::RuleQuantity_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2179);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 231, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2176);
      free_quantity_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2177);
      branch_quantity_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2178);
      source_quantity_declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Quantity_listContext ------------------------------------------------------------------

vhdlParser::Quantity_listContext::Quantity_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::NameContext *> vhdlParser::Quantity_listContext::name() {
  return getRuleContexts<vhdlParser::NameContext>();
}

vhdlParser::NameContext* vhdlParser::Quantity_listContext::name(size_t i) {
  return getRuleContext<vhdlParser::NameContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Quantity_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Quantity_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}

tree::TerminalNode* vhdlParser::Quantity_listContext::OTHERS() {
  return getToken(vhdlParser::OTHERS, 0);
}

tree::TerminalNode* vhdlParser::Quantity_listContext::ALL() {
  return getToken(vhdlParser::ALL, 0);
}


size_t vhdlParser::Quantity_listContext::getRuleIndex() const {
  return vhdlParser::RuleQuantity_list;
}

antlrcpp::Any vhdlParser::Quantity_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitQuantity_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Quantity_listContext* vhdlParser::quantity_list() {
  Quantity_listContext *_localctx = _tracker.createInstance<Quantity_listContext>(_ctx, getState());
  enterRule(_localctx, 394, vhdlParser::RuleQuantity_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2191);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(2181);
        name();
        setState(2186);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::COMMA) {
          setState(2182);
          match(vhdlParser::COMMA);
          setState(2183);
          name();
          setState(2188);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case vhdlParser::OTHERS: {
        enterOuterAlt(_localctx, 2);
        setState(2189);
        match(vhdlParser::OTHERS);
        break;
      }

      case vhdlParser::ALL: {
        enterOuterAlt(_localctx, 3);
        setState(2190);
        match(vhdlParser::ALL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Quantity_specificationContext ------------------------------------------------------------------

vhdlParser::Quantity_specificationContext::Quantity_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Quantity_listContext* vhdlParser::Quantity_specificationContext::quantity_list() {
  return getRuleContext<vhdlParser::Quantity_listContext>(0);
}

tree::TerminalNode* vhdlParser::Quantity_specificationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::NameContext* vhdlParser::Quantity_specificationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}


size_t vhdlParser::Quantity_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleQuantity_specification;
}

antlrcpp::Any vhdlParser::Quantity_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitQuantity_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Quantity_specificationContext* vhdlParser::quantity_specification() {
  Quantity_specificationContext *_localctx = _tracker.createInstance<Quantity_specificationContext>(_ctx, getState());
  enterRule(_localctx, 396, vhdlParser::RuleQuantity_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2193);
    quantity_list();
    setState(2194);
    match(vhdlParser::COLON);
    setState(2195);
    name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeContext ------------------------------------------------------------------

vhdlParser::RangeContext::RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Explicit_rangeContext* vhdlParser::RangeContext::explicit_range() {
  return getRuleContext<vhdlParser::Explicit_rangeContext>(0);
}

vhdlParser::NameContext* vhdlParser::RangeContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}


size_t vhdlParser::RangeContext::getRuleIndex() const {
  return vhdlParser::RuleRange;
}

antlrcpp::Any vhdlParser::RangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitRange(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::RangeContext* vhdlParser::range() {
  RangeContext *_localctx = _tracker.createInstance<RangeContext>(_ctx, getState());
  enterRule(_localctx, 398, vhdlParser::RuleRange);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2199);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 234, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2197);
      explicit_range();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2198);
      name();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Explicit_rangeContext ------------------------------------------------------------------

vhdlParser::Explicit_rangeContext::Explicit_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Simple_expressionContext *> vhdlParser::Explicit_rangeContext::simple_expression() {
  return getRuleContexts<vhdlParser::Simple_expressionContext>();
}

vhdlParser::Simple_expressionContext* vhdlParser::Explicit_rangeContext::simple_expression(size_t i) {
  return getRuleContext<vhdlParser::Simple_expressionContext>(i);
}

vhdlParser::DirectionContext* vhdlParser::Explicit_rangeContext::direction() {
  return getRuleContext<vhdlParser::DirectionContext>(0);
}


size_t vhdlParser::Explicit_rangeContext::getRuleIndex() const {
  return vhdlParser::RuleExplicit_range;
}

antlrcpp::Any vhdlParser::Explicit_rangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitExplicit_range(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Explicit_rangeContext* vhdlParser::explicit_range() {
  Explicit_rangeContext *_localctx = _tracker.createInstance<Explicit_rangeContext>(_ctx, getState());
  enterRule(_localctx, 400, vhdlParser::RuleExplicit_range);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2201);
    simple_expression();
    setState(2202);
    direction();
    setState(2203);
    simple_expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Range_constraintContext ------------------------------------------------------------------

vhdlParser::Range_constraintContext::Range_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Range_constraintContext::RANGE() {
  return getToken(vhdlParser::RANGE, 0);
}

vhdlParser::RangeContext* vhdlParser::Range_constraintContext::range() {
  return getRuleContext<vhdlParser::RangeContext>(0);
}


size_t vhdlParser::Range_constraintContext::getRuleIndex() const {
  return vhdlParser::RuleRange_constraint;
}

antlrcpp::Any vhdlParser::Range_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitRange_constraint(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Range_constraintContext* vhdlParser::range_constraint() {
  Range_constraintContext *_localctx = _tracker.createInstance<Range_constraintContext>(_ctx, getState());
  enterRule(_localctx, 402, vhdlParser::RuleRange_constraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2205);
    match(vhdlParser::RANGE);
    setState(2206);
    range();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Record_nature_definitionContext ------------------------------------------------------------------

vhdlParser::Record_nature_definitionContext::Record_nature_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Record_nature_definitionContext::RECORD() {
  return getTokens(vhdlParser::RECORD);
}

tree::TerminalNode* vhdlParser::Record_nature_definitionContext::RECORD(size_t i) {
  return getToken(vhdlParser::RECORD, i);
}

tree::TerminalNode* vhdlParser::Record_nature_definitionContext::END() {
  return getToken(vhdlParser::END, 0);
}

std::vector<vhdlParser::Nature_element_declarationContext *> vhdlParser::Record_nature_definitionContext::nature_element_declaration() {
  return getRuleContexts<vhdlParser::Nature_element_declarationContext>();
}

vhdlParser::Nature_element_declarationContext* vhdlParser::Record_nature_definitionContext::nature_element_declaration(size_t i) {
  return getRuleContext<vhdlParser::Nature_element_declarationContext>(i);
}

vhdlParser::IdentifierContext* vhdlParser::Record_nature_definitionContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Record_nature_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleRecord_nature_definition;
}

antlrcpp::Any vhdlParser::Record_nature_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitRecord_nature_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Record_nature_definitionContext* vhdlParser::record_nature_definition() {
  Record_nature_definitionContext *_localctx = _tracker.createInstance<Record_nature_definitionContext>(_ctx, getState());
  enterRule(_localctx, 404, vhdlParser::RuleRecord_nature_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2208);
    match(vhdlParser::RECORD);
    setState(2210); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(2209);
      nature_element_declaration();
      setState(2212); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER);
    setState(2214);
    match(vhdlParser::END);
    setState(2215);
    match(vhdlParser::RECORD);
    setState(2217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2216);
      identifier();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Record_type_definitionContext ------------------------------------------------------------------

vhdlParser::Record_type_definitionContext::Record_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Record_type_definitionContext::RECORD() {
  return getTokens(vhdlParser::RECORD);
}

tree::TerminalNode* vhdlParser::Record_type_definitionContext::RECORD(size_t i) {
  return getToken(vhdlParser::RECORD, i);
}

tree::TerminalNode* vhdlParser::Record_type_definitionContext::END() {
  return getToken(vhdlParser::END, 0);
}

std::vector<vhdlParser::Element_declarationContext *> vhdlParser::Record_type_definitionContext::element_declaration() {
  return getRuleContexts<vhdlParser::Element_declarationContext>();
}

vhdlParser::Element_declarationContext* vhdlParser::Record_type_definitionContext::element_declaration(size_t i) {
  return getRuleContext<vhdlParser::Element_declarationContext>(i);
}

vhdlParser::IdentifierContext* vhdlParser::Record_type_definitionContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Record_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleRecord_type_definition;
}

antlrcpp::Any vhdlParser::Record_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitRecord_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Record_type_definitionContext* vhdlParser::record_type_definition() {
  Record_type_definitionContext *_localctx = _tracker.createInstance<Record_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 406, vhdlParser::RuleRecord_type_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2219);
    match(vhdlParser::RECORD);
    setState(2221); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(2220);
      element_declaration();
      setState(2223); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER);
    setState(2225);
    match(vhdlParser::END);
    setState(2226);
    match(vhdlParser::RECORD);
    setState(2228);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2227);
      identifier();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationContext ------------------------------------------------------------------

vhdlParser::RelationContext::RelationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Shift_expressionContext *> vhdlParser::RelationContext::shift_expression() {
  return getRuleContexts<vhdlParser::Shift_expressionContext>();
}

vhdlParser::Shift_expressionContext* vhdlParser::RelationContext::shift_expression(size_t i) {
  return getRuleContext<vhdlParser::Shift_expressionContext>(i);
}

vhdlParser::Relational_operatorContext* vhdlParser::RelationContext::relational_operator() {
  return getRuleContext<vhdlParser::Relational_operatorContext>(0);
}


size_t vhdlParser::RelationContext::getRuleIndex() const {
  return vhdlParser::RuleRelation;
}

antlrcpp::Any vhdlParser::RelationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitRelation(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::RelationContext* vhdlParser::relation() {
  RelationContext *_localctx = _tracker.createInstance<RelationContext>(_ctx, getState());
  enterRule(_localctx, 408, vhdlParser::RuleRelation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2230);
    shift_expression();
    setState(2234);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 239, _ctx)) {
    case 1: {
      setState(2231);
      relational_operator();
      setState(2232);
      shift_expression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Relational_operatorContext ------------------------------------------------------------------

vhdlParser::Relational_operatorContext::Relational_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::EQ() {
  return getToken(vhdlParser::EQ, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::NEQ() {
  return getToken(vhdlParser::NEQ, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::LOWERTHAN() {
  return getToken(vhdlParser::LOWERTHAN, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::LE() {
  return getToken(vhdlParser::LE, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::GREATERTHAN() {
  return getToken(vhdlParser::GREATERTHAN, 0);
}

tree::TerminalNode* vhdlParser::Relational_operatorContext::GE() {
  return getToken(vhdlParser::GE, 0);
}


size_t vhdlParser::Relational_operatorContext::getRuleIndex() const {
  return vhdlParser::RuleRelational_operator;
}

antlrcpp::Any vhdlParser::Relational_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitRelational_operator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Relational_operatorContext* vhdlParser::relational_operator() {
  Relational_operatorContext *_localctx = _tracker.createInstance<Relational_operatorContext>(_ctx, getState());
  enterRule(_localctx, 410, vhdlParser::RuleRelational_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2236);
    _la = _input->LA(1);
    if (!(((((_la - 136) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 136)) & ((1ULL << (vhdlParser::LE - 136))
      | (1ULL << (vhdlParser::GE - 136))
      | (1ULL << (vhdlParser::NEQ - 136))
      | (1ULL << (vhdlParser::LOWERTHAN - 136))
      | (1ULL << (vhdlParser::GREATERTHAN - 136))
      | (1ULL << (vhdlParser::EQ - 136)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Report_statementContext ------------------------------------------------------------------

vhdlParser::Report_statementContext::Report_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Report_statementContext::REPORT() {
  return getToken(vhdlParser::REPORT, 0);
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::Report_statementContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::Report_statementContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

tree::TerminalNode* vhdlParser::Report_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Report_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

tree::TerminalNode* vhdlParser::Report_statementContext::SEVERITY() {
  return getToken(vhdlParser::SEVERITY, 0);
}


size_t vhdlParser::Report_statementContext::getRuleIndex() const {
  return vhdlParser::RuleReport_statement;
}

antlrcpp::Any vhdlParser::Report_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitReport_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Report_statementContext* vhdlParser::report_statement() {
  Report_statementContext *_localctx = _tracker.createInstance<Report_statementContext>(_ctx, getState());
  enterRule(_localctx, 412, vhdlParser::RuleReport_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2239);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2238);
      label_colon();
    }
    setState(2241);
    match(vhdlParser::REPORT);
    setState(2242);
    expression();
    setState(2245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::SEVERITY) {
      setState(2243);
      match(vhdlParser::SEVERITY);
      setState(2244);
      expression();
    }
    setState(2247);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

vhdlParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Return_statementContext::RETURN() {
  return getToken(vhdlParser::RETURN, 0);
}

tree::TerminalNode* vhdlParser::Return_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Return_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::ExpressionContext* vhdlParser::Return_statementContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Return_statementContext::getRuleIndex() const {
  return vhdlParser::RuleReturn_statement;
}

antlrcpp::Any vhdlParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Return_statementContext* vhdlParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 414, vhdlParser::RuleReturn_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2250);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2249);
      label_colon();
    }
    setState(2252);
    match(vhdlParser::RETURN);
    setState(2254);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ABS)
      | (1ULL << vhdlParser::NEW)
      | (1ULL << vhdlParser::NOT)
      | (1ULL << vhdlParser::NULL_SYM))) != 0) || ((((_la - 114) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 114)) & ((1ULL << (vhdlParser::BASE_LITERAL - 114))
      | (1ULL << (vhdlParser::BIT_STRING_LITERAL - 114))
      | (1ULL << (vhdlParser::REAL_LITERAL - 114))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 114))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 114))
      | (1ULL << (vhdlParser::CHARACTER_LITERAL - 114))
      | (1ULL << (vhdlParser::STRING_LITERAL - 114))
      | (1ULL << (vhdlParser::LPAREN - 114))
      | (1ULL << (vhdlParser::PLUS - 114))
      | (1ULL << (vhdlParser::MINUS - 114))
      | (1ULL << (vhdlParser::CONDITION_OPERATOR - 114))
      | (1ULL << (vhdlParser::INTEGER - 114)))) != 0)) {
      setState(2253);
      expression();
    }
    setState(2256);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Scalar_nature_definitionContext ------------------------------------------------------------------

vhdlParser::Scalar_nature_definitionContext::Scalar_nature_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::NameContext *> vhdlParser::Scalar_nature_definitionContext::name() {
  return getRuleContexts<vhdlParser::NameContext>();
}

vhdlParser::NameContext* vhdlParser::Scalar_nature_definitionContext::name(size_t i) {
  return getRuleContext<vhdlParser::NameContext>(i);
}

tree::TerminalNode* vhdlParser::Scalar_nature_definitionContext::ACROSS() {
  return getToken(vhdlParser::ACROSS, 0);
}

tree::TerminalNode* vhdlParser::Scalar_nature_definitionContext::THROUGH() {
  return getToken(vhdlParser::THROUGH, 0);
}

tree::TerminalNode* vhdlParser::Scalar_nature_definitionContext::REFERENCE() {
  return getToken(vhdlParser::REFERENCE, 0);
}


size_t vhdlParser::Scalar_nature_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleScalar_nature_definition;
}

antlrcpp::Any vhdlParser::Scalar_nature_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitScalar_nature_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Scalar_nature_definitionContext* vhdlParser::scalar_nature_definition() {
  Scalar_nature_definitionContext *_localctx = _tracker.createInstance<Scalar_nature_definitionContext>(_ctx, getState());
  enterRule(_localctx, 416, vhdlParser::RuleScalar_nature_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2258);
    name();
    setState(2259);
    match(vhdlParser::ACROSS);
    setState(2260);
    name();
    setState(2261);
    match(vhdlParser::THROUGH);
    setState(2262);
    name();
    setState(2263);
    match(vhdlParser::REFERENCE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Scalar_type_definitionContext ------------------------------------------------------------------

vhdlParser::Scalar_type_definitionContext::Scalar_type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Physical_type_definitionContext* vhdlParser::Scalar_type_definitionContext::physical_type_definition() {
  return getRuleContext<vhdlParser::Physical_type_definitionContext>(0);
}

vhdlParser::Enumeration_type_definitionContext* vhdlParser::Scalar_type_definitionContext::enumeration_type_definition() {
  return getRuleContext<vhdlParser::Enumeration_type_definitionContext>(0);
}

vhdlParser::Range_constraintContext* vhdlParser::Scalar_type_definitionContext::range_constraint() {
  return getRuleContext<vhdlParser::Range_constraintContext>(0);
}


size_t vhdlParser::Scalar_type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleScalar_type_definition;
}

antlrcpp::Any vhdlParser::Scalar_type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitScalar_type_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Scalar_type_definitionContext* vhdlParser::scalar_type_definition() {
  Scalar_type_definitionContext *_localctx = _tracker.createInstance<Scalar_type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 418, vhdlParser::RuleScalar_type_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2268);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 244, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2265);
      physical_type_definition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2266);
      enumeration_type_definition();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2267);
      range_constraint();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Secondary_unitContext ------------------------------------------------------------------

vhdlParser::Secondary_unitContext::Secondary_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Architecture_bodyContext* vhdlParser::Secondary_unitContext::architecture_body() {
  return getRuleContext<vhdlParser::Architecture_bodyContext>(0);
}

vhdlParser::Package_bodyContext* vhdlParser::Secondary_unitContext::package_body() {
  return getRuleContext<vhdlParser::Package_bodyContext>(0);
}


size_t vhdlParser::Secondary_unitContext::getRuleIndex() const {
  return vhdlParser::RuleSecondary_unit;
}

antlrcpp::Any vhdlParser::Secondary_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSecondary_unit(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Secondary_unitContext* vhdlParser::secondary_unit() {
  Secondary_unitContext *_localctx = _tracker.createInstance<Secondary_unitContext>(_ctx, getState());
  enterRule(_localctx, 420, vhdlParser::RuleSecondary_unit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2272);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::ARCHITECTURE: {
        enterOuterAlt(_localctx, 1);
        setState(2270);
        architecture_body();
        break;
      }

      case vhdlParser::PACKAGE: {
        enterOuterAlt(_localctx, 2);
        setState(2271);
        package_body();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Secondary_unit_declarationContext ------------------------------------------------------------------

vhdlParser::Secondary_unit_declarationContext::Secondary_unit_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::Secondary_unit_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Secondary_unit_declarationContext::EQ() {
  return getToken(vhdlParser::EQ, 0);
}

vhdlParser::Physical_literalContext* vhdlParser::Secondary_unit_declarationContext::physical_literal() {
  return getRuleContext<vhdlParser::Physical_literalContext>(0);
}

tree::TerminalNode* vhdlParser::Secondary_unit_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Secondary_unit_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleSecondary_unit_declaration;
}

antlrcpp::Any vhdlParser::Secondary_unit_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSecondary_unit_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Secondary_unit_declarationContext* vhdlParser::secondary_unit_declaration() {
  Secondary_unit_declarationContext *_localctx = _tracker.createInstance<Secondary_unit_declarationContext>(_ctx, getState());
  enterRule(_localctx, 422, vhdlParser::RuleSecondary_unit_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2274);
    identifier();
    setState(2275);
    match(vhdlParser::EQ);
    setState(2276);
    physical_literal();
    setState(2277);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selected_signal_assignmentContext ------------------------------------------------------------------

vhdlParser::Selected_signal_assignmentContext::Selected_signal_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Selected_signal_assignmentContext::WITH() {
  return getToken(vhdlParser::WITH, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Selected_signal_assignmentContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_signal_assignmentContext::SELECT() {
  return getToken(vhdlParser::SELECT, 0);
}

vhdlParser::TargetContext* vhdlParser::Selected_signal_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_signal_assignmentContext::LE() {
  return getToken(vhdlParser::LE, 0);
}

vhdlParser::OptsContext* vhdlParser::Selected_signal_assignmentContext::opts() {
  return getRuleContext<vhdlParser::OptsContext>(0);
}

vhdlParser::Selected_waveformsContext* vhdlParser::Selected_signal_assignmentContext::selected_waveforms() {
  return getRuleContext<vhdlParser::Selected_waveformsContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_signal_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Selected_signal_assignmentContext::TERNARY() {
  return getToken(vhdlParser::TERNARY, 0);
}


size_t vhdlParser::Selected_signal_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSelected_signal_assignment;
}

antlrcpp::Any vhdlParser::Selected_signal_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSelected_signal_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Selected_signal_assignmentContext* vhdlParser::selected_signal_assignment() {
  Selected_signal_assignmentContext *_localctx = _tracker.createInstance<Selected_signal_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 424, vhdlParser::RuleSelected_signal_assignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2279);
    match(vhdlParser::WITH);
    setState(2280);
    expression();
    setState(2281);
    match(vhdlParser::SELECT);
    setState(2283);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::TERNARY) {
      setState(2282);
      match(vhdlParser::TERNARY);
    }
    setState(2285);
    target();
    setState(2286);
    match(vhdlParser::LE);
    setState(2287);
    opts();
    setState(2288);
    selected_waveforms();
    setState(2289);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selected_waveformsContext ------------------------------------------------------------------

vhdlParser::Selected_waveformsContext::Selected_waveformsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::WaveformContext *> vhdlParser::Selected_waveformsContext::waveform() {
  return getRuleContexts<vhdlParser::WaveformContext>();
}

vhdlParser::WaveformContext* vhdlParser::Selected_waveformsContext::waveform(size_t i) {
  return getRuleContext<vhdlParser::WaveformContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Selected_waveformsContext::WHEN() {
  return getTokens(vhdlParser::WHEN);
}

tree::TerminalNode* vhdlParser::Selected_waveformsContext::WHEN(size_t i) {
  return getToken(vhdlParser::WHEN, i);
}

std::vector<vhdlParser::ChoicesContext *> vhdlParser::Selected_waveformsContext::choices() {
  return getRuleContexts<vhdlParser::ChoicesContext>();
}

vhdlParser::ChoicesContext* vhdlParser::Selected_waveformsContext::choices(size_t i) {
  return getRuleContext<vhdlParser::ChoicesContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Selected_waveformsContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Selected_waveformsContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Selected_waveformsContext::getRuleIndex() const {
  return vhdlParser::RuleSelected_waveforms;
}

antlrcpp::Any vhdlParser::Selected_waveformsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSelected_waveforms(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Selected_waveformsContext* vhdlParser::selected_waveforms() {
  Selected_waveformsContext *_localctx = _tracker.createInstance<Selected_waveformsContext>(_ctx, getState());
  enterRule(_localctx, 426, vhdlParser::RuleSelected_waveforms);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2291);
    waveform();
    setState(2292);
    match(vhdlParser::WHEN);
    setState(2293);
    choices();
    setState(2301);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(2294);
      match(vhdlParser::COMMA);
      setState(2295);
      waveform();
      setState(2296);
      match(vhdlParser::WHEN);
      setState(2297);
      choices();
      setState(2303);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sensitivity_clauseContext ------------------------------------------------------------------

vhdlParser::Sensitivity_clauseContext::Sensitivity_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Sensitivity_clauseContext::ON() {
  return getToken(vhdlParser::ON, 0);
}

vhdlParser::Sensitivity_listContext* vhdlParser::Sensitivity_clauseContext::sensitivity_list() {
  return getRuleContext<vhdlParser::Sensitivity_listContext>(0);
}


size_t vhdlParser::Sensitivity_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleSensitivity_clause;
}

antlrcpp::Any vhdlParser::Sensitivity_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSensitivity_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Sensitivity_clauseContext* vhdlParser::sensitivity_clause() {
  Sensitivity_clauseContext *_localctx = _tracker.createInstance<Sensitivity_clauseContext>(_ctx, getState());
  enterRule(_localctx, 428, vhdlParser::RuleSensitivity_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2304);
    match(vhdlParser::ON);
    setState(2305);
    sensitivity_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sensitivity_listContext ------------------------------------------------------------------

vhdlParser::Sensitivity_listContext::Sensitivity_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::NameContext *> vhdlParser::Sensitivity_listContext::name() {
  return getRuleContexts<vhdlParser::NameContext>();
}

vhdlParser::NameContext* vhdlParser::Sensitivity_listContext::name(size_t i) {
  return getRuleContext<vhdlParser::NameContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Sensitivity_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Sensitivity_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}

tree::TerminalNode* vhdlParser::Sensitivity_listContext::ALL() {
  return getToken(vhdlParser::ALL, 0);
}


size_t vhdlParser::Sensitivity_listContext::getRuleIndex() const {
  return vhdlParser::RuleSensitivity_list;
}

antlrcpp::Any vhdlParser::Sensitivity_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSensitivity_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Sensitivity_listContext* vhdlParser::sensitivity_list() {
  Sensitivity_listContext *_localctx = _tracker.createInstance<Sensitivity_listContext>(_ctx, getState());
  enterRule(_localctx, 430, vhdlParser::RuleSensitivity_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2316);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(2307);
        name();
        setState(2312);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::COMMA) {
          setState(2308);
          match(vhdlParser::COMMA);
          setState(2309);
          name();
          setState(2314);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case vhdlParser::ALL: {
        enterOuterAlt(_localctx, 2);
        setState(2315);
        match(vhdlParser::ALL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sequence_of_statementsContext ------------------------------------------------------------------

vhdlParser::Sequence_of_statementsContext::Sequence_of_statementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Sequential_statementContext *> vhdlParser::Sequence_of_statementsContext::sequential_statement() {
  return getRuleContexts<vhdlParser::Sequential_statementContext>();
}

vhdlParser::Sequential_statementContext* vhdlParser::Sequence_of_statementsContext::sequential_statement(size_t i) {
  return getRuleContext<vhdlParser::Sequential_statementContext>(i);
}


size_t vhdlParser::Sequence_of_statementsContext::getRuleIndex() const {
  return vhdlParser::RuleSequence_of_statements;
}

antlrcpp::Any vhdlParser::Sequence_of_statementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSequence_of_statements(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Sequence_of_statementsContext* vhdlParser::sequence_of_statements() {
  Sequence_of_statementsContext *_localctx = _tracker.createInstance<Sequence_of_statementsContext>(_ctx, getState());
  enterRule(_localctx, 432, vhdlParser::RuleSequence_of_statements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2321);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ASSERT)
      | (1ULL << vhdlParser::BREAK)
      | (1ULL << vhdlParser::CASE)
      | (1ULL << vhdlParser::EXIT)
      | (1ULL << vhdlParser::FOR)
      | (1ULL << vhdlParser::IF)
      | (1ULL << vhdlParser::LOOP)
      | (1ULL << vhdlParser::NEXT)
      | (1ULL << vhdlParser::NULL_SYM))) != 0) || ((((_la - 81) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 81)) & ((1ULL << (vhdlParser::REPORT - 81))
      | (1ULL << (vhdlParser::RETURN - 81))
      | (1ULL << (vhdlParser::WAIT - 81))
      | (1ULL << (vhdlParser::WITH - 81))
      | (1ULL << (vhdlParser::WHILE - 81))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 81))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 81)))) != 0) || _la == vhdlParser::LPAREN) {
      setState(2318);
      sequential_statement();
      setState(2323);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sequential_statementContext ------------------------------------------------------------------

vhdlParser::Sequential_statementContext::Sequential_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Wait_statementContext* vhdlParser::Sequential_statementContext::wait_statement() {
  return getRuleContext<vhdlParser::Wait_statementContext>(0);
}

vhdlParser::Assertion_statementContext* vhdlParser::Sequential_statementContext::assertion_statement() {
  return getRuleContext<vhdlParser::Assertion_statementContext>(0);
}

vhdlParser::Report_statementContext* vhdlParser::Sequential_statementContext::report_statement() {
  return getRuleContext<vhdlParser::Report_statementContext>(0);
}

vhdlParser::Signal_assignment_statementContext* vhdlParser::Sequential_statementContext::signal_assignment_statement() {
  return getRuleContext<vhdlParser::Signal_assignment_statementContext>(0);
}

vhdlParser::Variable_assignment_statementContext* vhdlParser::Sequential_statementContext::variable_assignment_statement() {
  return getRuleContext<vhdlParser::Variable_assignment_statementContext>(0);
}

vhdlParser::If_statementContext* vhdlParser::Sequential_statementContext::if_statement() {
  return getRuleContext<vhdlParser::If_statementContext>(0);
}

vhdlParser::Case_statementContext* vhdlParser::Sequential_statementContext::case_statement() {
  return getRuleContext<vhdlParser::Case_statementContext>(0);
}

vhdlParser::Loop_statementContext* vhdlParser::Sequential_statementContext::loop_statement() {
  return getRuleContext<vhdlParser::Loop_statementContext>(0);
}

vhdlParser::Next_statementContext* vhdlParser::Sequential_statementContext::next_statement() {
  return getRuleContext<vhdlParser::Next_statementContext>(0);
}

vhdlParser::Exit_statementContext* vhdlParser::Sequential_statementContext::exit_statement() {
  return getRuleContext<vhdlParser::Exit_statementContext>(0);
}

vhdlParser::Return_statementContext* vhdlParser::Sequential_statementContext::return_statement() {
  return getRuleContext<vhdlParser::Return_statementContext>(0);
}

tree::TerminalNode* vhdlParser::Sequential_statementContext::NULL_SYM() {
  return getToken(vhdlParser::NULL_SYM, 0);
}

tree::TerminalNode* vhdlParser::Sequential_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Sequential_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::Break_statementContext* vhdlParser::Sequential_statementContext::break_statement() {
  return getRuleContext<vhdlParser::Break_statementContext>(0);
}

vhdlParser::Procedure_call_statementContext* vhdlParser::Sequential_statementContext::procedure_call_statement() {
  return getRuleContext<vhdlParser::Procedure_call_statementContext>(0);
}


size_t vhdlParser::Sequential_statementContext::getRuleIndex() const {
  return vhdlParser::RuleSequential_statement;
}

antlrcpp::Any vhdlParser::Sequential_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSequential_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Sequential_statementContext* vhdlParser::sequential_statement() {
  Sequential_statementContext *_localctx = _tracker.createInstance<Sequential_statementContext>(_ctx, getState());
  enterRule(_localctx, 434, vhdlParser::RuleSequential_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2342);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 252, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2324);
      wait_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2325);
      assertion_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2326);
      report_statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(2327);
      signal_assignment_statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(2328);
      variable_assignment_statement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(2329);
      if_statement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(2330);
      case_statement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(2331);
      loop_statement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(2332);
      next_statement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(2333);
      exit_statement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(2334);
      return_statement();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(2336);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::BASIC_IDENTIFIER

      || _la == vhdlParser::EXTENDED_IDENTIFIER) {
        setState(2335);
        label_colon();
      }
      setState(2338);
      match(vhdlParser::NULL_SYM);
      setState(2339);
      match(vhdlParser::SEMI);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(2340);
      break_statement();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(2341);
      procedure_call_statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Shift_expressionContext ------------------------------------------------------------------

vhdlParser::Shift_expressionContext::Shift_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Simple_expressionContext *> vhdlParser::Shift_expressionContext::simple_expression() {
  return getRuleContexts<vhdlParser::Simple_expressionContext>();
}

vhdlParser::Simple_expressionContext* vhdlParser::Shift_expressionContext::simple_expression(size_t i) {
  return getRuleContext<vhdlParser::Simple_expressionContext>(i);
}

vhdlParser::Shift_operatorContext* vhdlParser::Shift_expressionContext::shift_operator() {
  return getRuleContext<vhdlParser::Shift_operatorContext>(0);
}


size_t vhdlParser::Shift_expressionContext::getRuleIndex() const {
  return vhdlParser::RuleShift_expression;
}

antlrcpp::Any vhdlParser::Shift_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitShift_expression(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Shift_expressionContext* vhdlParser::shift_expression() {
  Shift_expressionContext *_localctx = _tracker.createInstance<Shift_expressionContext>(_ctx, getState());
  enterRule(_localctx, 436, vhdlParser::RuleShift_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2344);
    simple_expression();
    setState(2348);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 253, _ctx)) {
    case 1: {
      setState(2345);
      shift_operator();
      setState(2346);
      simple_expression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Shift_operatorContext ------------------------------------------------------------------

vhdlParser::Shift_operatorContext::Shift_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::SLL() {
  return getToken(vhdlParser::SLL, 0);
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::SRL() {
  return getToken(vhdlParser::SRL, 0);
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::SLA() {
  return getToken(vhdlParser::SLA, 0);
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::SRA() {
  return getToken(vhdlParser::SRA, 0);
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::ROL() {
  return getToken(vhdlParser::ROL, 0);
}

tree::TerminalNode* vhdlParser::Shift_operatorContext::ROR() {
  return getToken(vhdlParser::ROR, 0);
}


size_t vhdlParser::Shift_operatorContext::getRuleIndex() const {
  return vhdlParser::RuleShift_operator;
}

antlrcpp::Any vhdlParser::Shift_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitShift_operator(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Shift_operatorContext* vhdlParser::shift_operator() {
  Shift_operatorContext *_localctx = _tracker.createInstance<Shift_operatorContext>(_ctx, getState());
  enterRule(_localctx, 438, vhdlParser::RuleShift_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2350);
    _la = _input->LA(1);
    if (!(((((_la - 83) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 83)) & ((1ULL << (vhdlParser::ROL - 83))
      | (1ULL << (vhdlParser::ROR - 83))
      | (1ULL << (vhdlParser::SLA - 83))
      | (1ULL << (vhdlParser::SLL - 83))
      | (1ULL << (vhdlParser::SRA - 83))
      | (1ULL << (vhdlParser::SRL - 83)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signal_assignment_statementContext ------------------------------------------------------------------

vhdlParser::Signal_assignment_statementContext::Signal_assignment_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Simple_signal_assignmentContext* vhdlParser::Signal_assignment_statementContext::simple_signal_assignment() {
  return getRuleContext<vhdlParser::Simple_signal_assignmentContext>(0);
}

vhdlParser::Label_colonContext* vhdlParser::Signal_assignment_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::Conditional_signal_assignmentContext* vhdlParser::Signal_assignment_statementContext::conditional_signal_assignment() {
  return getRuleContext<vhdlParser::Conditional_signal_assignmentContext>(0);
}

vhdlParser::Selected_signal_assignmentContext* vhdlParser::Signal_assignment_statementContext::selected_signal_assignment() {
  return getRuleContext<vhdlParser::Selected_signal_assignmentContext>(0);
}


size_t vhdlParser::Signal_assignment_statementContext::getRuleIndex() const {
  return vhdlParser::RuleSignal_assignment_statement;
}

antlrcpp::Any vhdlParser::Signal_assignment_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSignal_assignment_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Signal_assignment_statementContext* vhdlParser::signal_assignment_statement() {
  Signal_assignment_statementContext *_localctx = _tracker.createInstance<Signal_assignment_statementContext>(_ctx, getState());
  enterRule(_localctx, 440, vhdlParser::RuleSignal_assignment_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2364);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 257, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2353);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 254, _ctx)) {
      case 1: {
        setState(2352);
        label_colon();
        break;
      }

      }
      setState(2355);
      simple_signal_assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2357);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 255, _ctx)) {
      case 1: {
        setState(2356);
        label_colon();
        break;
      }

      }
      setState(2359);
      conditional_signal_assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2361);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::BASIC_IDENTIFIER

      || _la == vhdlParser::EXTENDED_IDENTIFIER) {
        setState(2360);
        label_colon();
      }
      setState(2363);
      selected_signal_assignment();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_signal_assignmentContext ------------------------------------------------------------------

vhdlParser::Simple_signal_assignmentContext::Simple_signal_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Simple_waveform_assignmentContext* vhdlParser::Simple_signal_assignmentContext::simple_waveform_assignment() {
  return getRuleContext<vhdlParser::Simple_waveform_assignmentContext>(0);
}

vhdlParser::Simple_force_assignmentContext* vhdlParser::Simple_signal_assignmentContext::simple_force_assignment() {
  return getRuleContext<vhdlParser::Simple_force_assignmentContext>(0);
}

vhdlParser::Simple_release_assignmentContext* vhdlParser::Simple_signal_assignmentContext::simple_release_assignment() {
  return getRuleContext<vhdlParser::Simple_release_assignmentContext>(0);
}


size_t vhdlParser::Simple_signal_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_signal_assignment;
}

antlrcpp::Any vhdlParser::Simple_signal_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimple_signal_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_signal_assignmentContext* vhdlParser::simple_signal_assignment() {
  Simple_signal_assignmentContext *_localctx = _tracker.createInstance<Simple_signal_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 442, vhdlParser::RuleSimple_signal_assignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2369);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 258, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2366);
      simple_waveform_assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2367);
      simple_force_assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2368);
      simple_release_assignment();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_waveform_assignmentContext ------------------------------------------------------------------

vhdlParser::Simple_waveform_assignmentContext::Simple_waveform_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Simple_waveform_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_waveform_assignmentContext::LE() {
  return getToken(vhdlParser::LE, 0);
}

vhdlParser::WaveformContext* vhdlParser::Simple_waveform_assignmentContext::waveform() {
  return getRuleContext<vhdlParser::WaveformContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_waveform_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Delay_mechanismContext* vhdlParser::Simple_waveform_assignmentContext::delay_mechanism() {
  return getRuleContext<vhdlParser::Delay_mechanismContext>(0);
}


size_t vhdlParser::Simple_waveform_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_waveform_assignment;
}

antlrcpp::Any vhdlParser::Simple_waveform_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimple_waveform_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_waveform_assignmentContext* vhdlParser::simple_waveform_assignment() {
  Simple_waveform_assignmentContext *_localctx = _tracker.createInstance<Simple_waveform_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 444, vhdlParser::RuleSimple_waveform_assignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2371);
    target();
    setState(2372);
    match(vhdlParser::LE);
    setState(2374);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 40) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 40)) & ((1ULL << (vhdlParser::INERTIAL - 40))
      | (1ULL << (vhdlParser::REJECT - 40))
      | (1ULL << (vhdlParser::TRANSPORT - 40)))) != 0)) {
      setState(2373);
      delay_mechanism();
    }
    setState(2376);
    waveform();
    setState(2377);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_force_assignmentContext ------------------------------------------------------------------

vhdlParser::Simple_force_assignmentContext::Simple_force_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Simple_force_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_force_assignmentContext::LE() {
  return getToken(vhdlParser::LE, 0);
}

tree::TerminalNode* vhdlParser::Simple_force_assignmentContext::FORCE() {
  return getToken(vhdlParser::FORCE, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Simple_force_assignmentContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_force_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Force_modeContext* vhdlParser::Simple_force_assignmentContext::force_mode() {
  return getRuleContext<vhdlParser::Force_modeContext>(0);
}


size_t vhdlParser::Simple_force_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_force_assignment;
}

antlrcpp::Any vhdlParser::Simple_force_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimple_force_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_force_assignmentContext* vhdlParser::simple_force_assignment() {
  Simple_force_assignmentContext *_localctx = _tracker.createInstance<Simple_force_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 446, vhdlParser::RuleSimple_force_assignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2379);
    target();
    setState(2380);
    match(vhdlParser::LE);
    setState(2381);
    match(vhdlParser::FORCE);
    setState(2383);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IN

    || _la == vhdlParser::OUT) {
      setState(2382);
      force_mode();
    }
    setState(2385);
    expression();
    setState(2386);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_release_assignmentContext ------------------------------------------------------------------

vhdlParser::Simple_release_assignmentContext::Simple_release_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Simple_release_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_release_assignmentContext::LE() {
  return getToken(vhdlParser::LE, 0);
}

tree::TerminalNode* vhdlParser::Simple_release_assignmentContext::RELEASE() {
  return getToken(vhdlParser::RELEASE, 0);
}

tree::TerminalNode* vhdlParser::Simple_release_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Force_modeContext* vhdlParser::Simple_release_assignmentContext::force_mode() {
  return getRuleContext<vhdlParser::Force_modeContext>(0);
}


size_t vhdlParser::Simple_release_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_release_assignment;
}

antlrcpp::Any vhdlParser::Simple_release_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimple_release_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_release_assignmentContext* vhdlParser::simple_release_assignment() {
  Simple_release_assignmentContext *_localctx = _tracker.createInstance<Simple_release_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 448, vhdlParser::RuleSimple_release_assignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2388);
    target();
    setState(2389);
    match(vhdlParser::LE);
    setState(2390);
    match(vhdlParser::RELEASE);
    setState(2392);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IN

    || _la == vhdlParser::OUT) {
      setState(2391);
      force_mode();
    }
    setState(2394);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Force_modeContext ------------------------------------------------------------------

vhdlParser::Force_modeContext::Force_modeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Force_modeContext::IN() {
  return getToken(vhdlParser::IN, 0);
}

tree::TerminalNode* vhdlParser::Force_modeContext::OUT() {
  return getToken(vhdlParser::OUT, 0);
}


size_t vhdlParser::Force_modeContext::getRuleIndex() const {
  return vhdlParser::RuleForce_mode;
}

antlrcpp::Any vhdlParser::Force_modeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitForce_mode(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Force_modeContext* vhdlParser::force_mode() {
  Force_modeContext *_localctx = _tracker.createInstance<Force_modeContext>(_ctx, getState());
  enterRule(_localctx, 450, vhdlParser::RuleForce_mode);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2396);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::IN

    || _la == vhdlParser::OUT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signal_declarationContext ------------------------------------------------------------------

vhdlParser::Signal_declarationContext::Signal_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Signal_declarationContext::SIGNAL() {
  return getToken(vhdlParser::SIGNAL, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Signal_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Signal_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Signal_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Signal_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Signal_kindContext* vhdlParser::Signal_declarationContext::signal_kind() {
  return getRuleContext<vhdlParser::Signal_kindContext>(0);
}

tree::TerminalNode* vhdlParser::Signal_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Signal_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Signal_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleSignal_declaration;
}

antlrcpp::Any vhdlParser::Signal_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSignal_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Signal_declarationContext* vhdlParser::signal_declaration() {
  Signal_declarationContext *_localctx = _tracker.createInstance<Signal_declarationContext>(_ctx, getState());
  enterRule(_localctx, 452, vhdlParser::RuleSignal_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2398);
    match(vhdlParser::SIGNAL);
    setState(2399);
    identifier_list();
    setState(2400);
    match(vhdlParser::COLON);
    setState(2401);
    subtype_indication();
    setState(2403);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BUS

    || _la == vhdlParser::REGISTER) {
      setState(2402);
      signal_kind();
    }
    setState(2407);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(2405);
      match(vhdlParser::VARASGN);
      setState(2406);
      expression();
    }
    setState(2409);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signal_kindContext ------------------------------------------------------------------

vhdlParser::Signal_kindContext::Signal_kindContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Signal_kindContext::REGISTER() {
  return getToken(vhdlParser::REGISTER, 0);
}

tree::TerminalNode* vhdlParser::Signal_kindContext::BUS() {
  return getToken(vhdlParser::BUS, 0);
}


size_t vhdlParser::Signal_kindContext::getRuleIndex() const {
  return vhdlParser::RuleSignal_kind;
}

antlrcpp::Any vhdlParser::Signal_kindContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSignal_kind(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Signal_kindContext* vhdlParser::signal_kind() {
  Signal_kindContext *_localctx = _tracker.createInstance<Signal_kindContext>(_ctx, getState());
  enterRule(_localctx, 454, vhdlParser::RuleSignal_kind);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2411);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::BUS

    || _la == vhdlParser::REGISTER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signal_listContext ------------------------------------------------------------------

vhdlParser::Signal_listContext::Signal_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::NameContext *> vhdlParser::Signal_listContext::name() {
  return getRuleContexts<vhdlParser::NameContext>();
}

vhdlParser::NameContext* vhdlParser::Signal_listContext::name(size_t i) {
  return getRuleContext<vhdlParser::NameContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Signal_listContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Signal_listContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}

tree::TerminalNode* vhdlParser::Signal_listContext::OTHERS() {
  return getToken(vhdlParser::OTHERS, 0);
}

tree::TerminalNode* vhdlParser::Signal_listContext::ALL() {
  return getToken(vhdlParser::ALL, 0);
}


size_t vhdlParser::Signal_listContext::getRuleIndex() const {
  return vhdlParser::RuleSignal_list;
}

antlrcpp::Any vhdlParser::Signal_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSignal_list(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Signal_listContext* vhdlParser::signal_list() {
  Signal_listContext *_localctx = _tracker.createInstance<Signal_listContext>(_ctx, getState());
  enterRule(_localctx, 456, vhdlParser::RuleSignal_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2423);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(2413);
        name();
        setState(2418);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::COMMA) {
          setState(2414);
          match(vhdlParser::COMMA);
          setState(2415);
          name();
          setState(2420);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case vhdlParser::OTHERS: {
        enterOuterAlt(_localctx, 2);
        setState(2421);
        match(vhdlParser::OTHERS);
        break;
      }

      case vhdlParser::ALL: {
        enterOuterAlt(_localctx, 3);
        setState(2422);
        match(vhdlParser::ALL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignatureContext ------------------------------------------------------------------

vhdlParser::SignatureContext::SignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::SignatureContext::LBRACKET() {
  return getToken(vhdlParser::LBRACKET, 0);
}

tree::TerminalNode* vhdlParser::SignatureContext::RBRACKET() {
  return getToken(vhdlParser::RBRACKET, 0);
}

std::vector<vhdlParser::NameContext *> vhdlParser::SignatureContext::name() {
  return getRuleContexts<vhdlParser::NameContext>();
}

vhdlParser::NameContext* vhdlParser::SignatureContext::name(size_t i) {
  return getRuleContext<vhdlParser::NameContext>(i);
}

tree::TerminalNode* vhdlParser::SignatureContext::RETURN() {
  return getToken(vhdlParser::RETURN, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::SignatureContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::SignatureContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::SignatureContext::getRuleIndex() const {
  return vhdlParser::RuleSignature;
}

antlrcpp::Any vhdlParser::SignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSignature(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::SignatureContext* vhdlParser::signature() {
  SignatureContext *_localctx = _tracker.createInstance<SignatureContext>(_ctx, getState());
  enterRule(_localctx, 458, vhdlParser::RuleSignature);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2425);
    match(vhdlParser::LBRACKET);
    setState(2434);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2426);
      name();
      setState(2431);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == vhdlParser::COMMA) {
        setState(2427);
        match(vhdlParser::COMMA);
        setState(2428);
        name();
        setState(2433);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(2438);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::RETURN) {
      setState(2436);
      match(vhdlParser::RETURN);
      setState(2437);
      name();
    }
    setState(2440);
    match(vhdlParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

vhdlParser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::TermContext *> vhdlParser::Simple_expressionContext::term() {
  return getRuleContexts<vhdlParser::TermContext>();
}

vhdlParser::TermContext* vhdlParser::Simple_expressionContext::term(size_t i) {
  return getRuleContext<vhdlParser::TermContext>(i);
}

std::vector<vhdlParser::Adding_operatorContext *> vhdlParser::Simple_expressionContext::adding_operator() {
  return getRuleContexts<vhdlParser::Adding_operatorContext>();
}

vhdlParser::Adding_operatorContext* vhdlParser::Simple_expressionContext::adding_operator(size_t i) {
  return getRuleContext<vhdlParser::Adding_operatorContext>(i);
}

tree::TerminalNode* vhdlParser::Simple_expressionContext::PLUS() {
  return getToken(vhdlParser::PLUS, 0);
}

tree::TerminalNode* vhdlParser::Simple_expressionContext::MINUS() {
  return getToken(vhdlParser::MINUS, 0);
}


size_t vhdlParser::Simple_expressionContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_expression;
}

antlrcpp::Any vhdlParser::Simple_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimple_expression(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_expressionContext* vhdlParser::simple_expression() {
  Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, getState());
  enterRule(_localctx, 460, vhdlParser::RuleSimple_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2443);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::PLUS

    || _la == vhdlParser::MINUS) {
      setState(2442);
      _la = _input->LA(1);
      if (!(_la == vhdlParser::PLUS

      || _la == vhdlParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(2445);
    term();
    setState(2451);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 270, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(2446);
        adding_operator();
        setState(2447);
        term(); 
      }
      setState(2453);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 270, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_simultaneous_statementContext ------------------------------------------------------------------

vhdlParser::Simple_simultaneous_statementContext::Simple_simultaneous_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Simple_expressionContext *> vhdlParser::Simple_simultaneous_statementContext::simple_expression() {
  return getRuleContexts<vhdlParser::Simple_expressionContext>();
}

vhdlParser::Simple_expressionContext* vhdlParser::Simple_simultaneous_statementContext::simple_expression(size_t i) {
  return getRuleContext<vhdlParser::Simple_expressionContext>(i);
}

tree::TerminalNode* vhdlParser::Simple_simultaneous_statementContext::ASSIGN() {
  return getToken(vhdlParser::ASSIGN, 0);
}

tree::TerminalNode* vhdlParser::Simple_simultaneous_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Simple_simultaneous_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::Tolerance_aspectContext* vhdlParser::Simple_simultaneous_statementContext::tolerance_aspect() {
  return getRuleContext<vhdlParser::Tolerance_aspectContext>(0);
}


size_t vhdlParser::Simple_simultaneous_statementContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_simultaneous_statement;
}

antlrcpp::Any vhdlParser::Simple_simultaneous_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimple_simultaneous_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_simultaneous_statementContext* vhdlParser::simple_simultaneous_statement() {
  Simple_simultaneous_statementContext *_localctx = _tracker.createInstance<Simple_simultaneous_statementContext>(_ctx, getState());
  enterRule(_localctx, 462, vhdlParser::RuleSimple_simultaneous_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2455);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 271, _ctx)) {
    case 1: {
      setState(2454);
      label_colon();
      break;
    }

    }
    setState(2457);
    simple_expression();
    setState(2458);
    match(vhdlParser::ASSIGN);
    setState(2459);
    simple_expression();
    setState(2461);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::TOLERANCE) {
      setState(2460);
      tolerance_aspect();
    }
    setState(2463);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simultaneous_alternativeContext ------------------------------------------------------------------

vhdlParser::Simultaneous_alternativeContext::Simultaneous_alternativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Simultaneous_alternativeContext::WHEN() {
  return getToken(vhdlParser::WHEN, 0);
}

vhdlParser::ChoicesContext* vhdlParser::Simultaneous_alternativeContext::choices() {
  return getRuleContext<vhdlParser::ChoicesContext>(0);
}

tree::TerminalNode* vhdlParser::Simultaneous_alternativeContext::ARROW() {
  return getToken(vhdlParser::ARROW, 0);
}

vhdlParser::Simultaneous_statement_partContext* vhdlParser::Simultaneous_alternativeContext::simultaneous_statement_part() {
  return getRuleContext<vhdlParser::Simultaneous_statement_partContext>(0);
}


size_t vhdlParser::Simultaneous_alternativeContext::getRuleIndex() const {
  return vhdlParser::RuleSimultaneous_alternative;
}

antlrcpp::Any vhdlParser::Simultaneous_alternativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimultaneous_alternative(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simultaneous_alternativeContext* vhdlParser::simultaneous_alternative() {
  Simultaneous_alternativeContext *_localctx = _tracker.createInstance<Simultaneous_alternativeContext>(_ctx, getState());
  enterRule(_localctx, 464, vhdlParser::RuleSimultaneous_alternative);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2465);
    match(vhdlParser::WHEN);
    setState(2466);
    choices();
    setState(2467);
    match(vhdlParser::ARROW);
    setState(2468);
    simultaneous_statement_part();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simultaneous_case_statementContext ------------------------------------------------------------------

vhdlParser::Simultaneous_case_statementContext::Simultaneous_case_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Simultaneous_case_statementContext::CASE() {
  return getTokens(vhdlParser::CASE);
}

tree::TerminalNode* vhdlParser::Simultaneous_case_statementContext::CASE(size_t i) {
  return getToken(vhdlParser::CASE, i);
}

vhdlParser::ExpressionContext* vhdlParser::Simultaneous_case_statementContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Simultaneous_case_statementContext::USE() {
  return getToken(vhdlParser::USE, 0);
}

tree::TerminalNode* vhdlParser::Simultaneous_case_statementContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Simultaneous_case_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Simultaneous_case_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

std::vector<vhdlParser::Simultaneous_alternativeContext *> vhdlParser::Simultaneous_case_statementContext::simultaneous_alternative() {
  return getRuleContexts<vhdlParser::Simultaneous_alternativeContext>();
}

vhdlParser::Simultaneous_alternativeContext* vhdlParser::Simultaneous_case_statementContext::simultaneous_alternative(size_t i) {
  return getRuleContext<vhdlParser::Simultaneous_alternativeContext>(i);
}

vhdlParser::IdentifierContext* vhdlParser::Simultaneous_case_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Simultaneous_case_statementContext::getRuleIndex() const {
  return vhdlParser::RuleSimultaneous_case_statement;
}

antlrcpp::Any vhdlParser::Simultaneous_case_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimultaneous_case_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simultaneous_case_statementContext* vhdlParser::simultaneous_case_statement() {
  Simultaneous_case_statementContext *_localctx = _tracker.createInstance<Simultaneous_case_statementContext>(_ctx, getState());
  enterRule(_localctx, 466, vhdlParser::RuleSimultaneous_case_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2471);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2470);
      label_colon();
    }
    setState(2473);
    match(vhdlParser::CASE);
    setState(2474);
    expression();
    setState(2475);
    match(vhdlParser::USE);
    setState(2477); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(2476);
      simultaneous_alternative();
      setState(2479); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == vhdlParser::WHEN);
    setState(2481);
    match(vhdlParser::END);
    setState(2482);
    match(vhdlParser::CASE);
    setState(2484);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2483);
      identifier();
    }
    setState(2486);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simultaneous_if_statementContext ------------------------------------------------------------------

vhdlParser::Simultaneous_if_statementContext::Simultaneous_if_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Simultaneous_if_statementContext::IF() {
  return getToken(vhdlParser::IF, 0);
}

std::vector<vhdlParser::ConditionContext *> vhdlParser::Simultaneous_if_statementContext::condition() {
  return getRuleContexts<vhdlParser::ConditionContext>();
}

vhdlParser::ConditionContext* vhdlParser::Simultaneous_if_statementContext::condition(size_t i) {
  return getRuleContext<vhdlParser::ConditionContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::Simultaneous_if_statementContext::USE() {
  return getTokens(vhdlParser::USE);
}

tree::TerminalNode* vhdlParser::Simultaneous_if_statementContext::USE(size_t i) {
  return getToken(vhdlParser::USE, i);
}

std::vector<vhdlParser::Simultaneous_statement_partContext *> vhdlParser::Simultaneous_if_statementContext::simultaneous_statement_part() {
  return getRuleContexts<vhdlParser::Simultaneous_statement_partContext>();
}

vhdlParser::Simultaneous_statement_partContext* vhdlParser::Simultaneous_if_statementContext::simultaneous_statement_part(size_t i) {
  return getRuleContext<vhdlParser::Simultaneous_statement_partContext>(i);
}

tree::TerminalNode* vhdlParser::Simultaneous_if_statementContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Simultaneous_if_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Simultaneous_if_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Simultaneous_if_statementContext::ELSIF() {
  return getTokens(vhdlParser::ELSIF);
}

tree::TerminalNode* vhdlParser::Simultaneous_if_statementContext::ELSIF(size_t i) {
  return getToken(vhdlParser::ELSIF, i);
}

tree::TerminalNode* vhdlParser::Simultaneous_if_statementContext::ELSE() {
  return getToken(vhdlParser::ELSE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Simultaneous_if_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Simultaneous_if_statementContext::getRuleIndex() const {
  return vhdlParser::RuleSimultaneous_if_statement;
}

antlrcpp::Any vhdlParser::Simultaneous_if_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimultaneous_if_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simultaneous_if_statementContext* vhdlParser::simultaneous_if_statement() {
  Simultaneous_if_statementContext *_localctx = _tracker.createInstance<Simultaneous_if_statementContext>(_ctx, getState());
  enterRule(_localctx, 468, vhdlParser::RuleSimultaneous_if_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2489);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2488);
      label_colon();
    }
    setState(2491);
    match(vhdlParser::IF);
    setState(2492);
    condition();
    setState(2493);
    match(vhdlParser::USE);
    setState(2494);
    simultaneous_statement_part();
    setState(2502);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::ELSIF) {
      setState(2495);
      match(vhdlParser::ELSIF);
      setState(2496);
      condition();
      setState(2497);
      match(vhdlParser::USE);
      setState(2498);
      simultaneous_statement_part();
      setState(2504);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2507);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::ELSE) {
      setState(2505);
      match(vhdlParser::ELSE);
      setState(2506);
      simultaneous_statement_part();
    }
    setState(2509);
    match(vhdlParser::END);
    setState(2510);
    match(vhdlParser::USE);
    setState(2512);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2511);
      identifier();
    }
    setState(2514);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simultaneous_procedural_statementContext ------------------------------------------------------------------

vhdlParser::Simultaneous_procedural_statementContext::Simultaneous_procedural_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> vhdlParser::Simultaneous_procedural_statementContext::PROCEDURAL() {
  return getTokens(vhdlParser::PROCEDURAL);
}

tree::TerminalNode* vhdlParser::Simultaneous_procedural_statementContext::PROCEDURAL(size_t i) {
  return getToken(vhdlParser::PROCEDURAL, i);
}

vhdlParser::Procedural_declarative_partContext* vhdlParser::Simultaneous_procedural_statementContext::procedural_declarative_part() {
  return getRuleContext<vhdlParser::Procedural_declarative_partContext>(0);
}

tree::TerminalNode* vhdlParser::Simultaneous_procedural_statementContext::BEGIN() {
  return getToken(vhdlParser::BEGIN, 0);
}

vhdlParser::Procedural_statement_partContext* vhdlParser::Simultaneous_procedural_statementContext::procedural_statement_part() {
  return getRuleContext<vhdlParser::Procedural_statement_partContext>(0);
}

tree::TerminalNode* vhdlParser::Simultaneous_procedural_statementContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Simultaneous_procedural_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Simultaneous_procedural_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

tree::TerminalNode* vhdlParser::Simultaneous_procedural_statementContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Simultaneous_procedural_statementContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}


size_t vhdlParser::Simultaneous_procedural_statementContext::getRuleIndex() const {
  return vhdlParser::RuleSimultaneous_procedural_statement;
}

antlrcpp::Any vhdlParser::Simultaneous_procedural_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimultaneous_procedural_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simultaneous_procedural_statementContext* vhdlParser::simultaneous_procedural_statement() {
  Simultaneous_procedural_statementContext *_localctx = _tracker.createInstance<Simultaneous_procedural_statementContext>(_ctx, getState());
  enterRule(_localctx, 470, vhdlParser::RuleSimultaneous_procedural_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2517);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2516);
      label_colon();
    }
    setState(2519);
    match(vhdlParser::PROCEDURAL);
    setState(2521);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IS) {
      setState(2520);
      match(vhdlParser::IS);
    }
    setState(2523);
    procedural_declarative_part();
    setState(2524);
    match(vhdlParser::BEGIN);
    setState(2525);
    procedural_statement_part();
    setState(2526);
    match(vhdlParser::END);
    setState(2527);
    match(vhdlParser::PROCEDURAL);
    setState(2529);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2528);
      identifier();
    }
    setState(2531);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simultaneous_statementContext ------------------------------------------------------------------

vhdlParser::Simultaneous_statementContext::Simultaneous_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Simple_simultaneous_statementContext* vhdlParser::Simultaneous_statementContext::simple_simultaneous_statement() {
  return getRuleContext<vhdlParser::Simple_simultaneous_statementContext>(0);
}

vhdlParser::Simultaneous_if_statementContext* vhdlParser::Simultaneous_statementContext::simultaneous_if_statement() {
  return getRuleContext<vhdlParser::Simultaneous_if_statementContext>(0);
}

vhdlParser::Simultaneous_case_statementContext* vhdlParser::Simultaneous_statementContext::simultaneous_case_statement() {
  return getRuleContext<vhdlParser::Simultaneous_case_statementContext>(0);
}

vhdlParser::Simultaneous_procedural_statementContext* vhdlParser::Simultaneous_statementContext::simultaneous_procedural_statement() {
  return getRuleContext<vhdlParser::Simultaneous_procedural_statementContext>(0);
}

tree::TerminalNode* vhdlParser::Simultaneous_statementContext::NULL_SYM() {
  return getToken(vhdlParser::NULL_SYM, 0);
}

tree::TerminalNode* vhdlParser::Simultaneous_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Simultaneous_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}


size_t vhdlParser::Simultaneous_statementContext::getRuleIndex() const {
  return vhdlParser::RuleSimultaneous_statement;
}

antlrcpp::Any vhdlParser::Simultaneous_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimultaneous_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simultaneous_statementContext* vhdlParser::simultaneous_statement() {
  Simultaneous_statementContext *_localctx = _tracker.createInstance<Simultaneous_statementContext>(_ctx, getState());
  enterRule(_localctx, 472, vhdlParser::RuleSimultaneous_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2542);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 284, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2533);
      simple_simultaneous_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2534);
      simultaneous_if_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2535);
      simultaneous_case_statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(2536);
      simultaneous_procedural_statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(2538);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::BASIC_IDENTIFIER

      || _la == vhdlParser::EXTENDED_IDENTIFIER) {
        setState(2537);
        label_colon();
      }
      setState(2540);
      match(vhdlParser::NULL_SYM);
      setState(2541);
      match(vhdlParser::SEMI);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simultaneous_statement_partContext ------------------------------------------------------------------

vhdlParser::Simultaneous_statement_partContext::Simultaneous_statement_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Simultaneous_statementContext *> vhdlParser::Simultaneous_statement_partContext::simultaneous_statement() {
  return getRuleContexts<vhdlParser::Simultaneous_statementContext>();
}

vhdlParser::Simultaneous_statementContext* vhdlParser::Simultaneous_statement_partContext::simultaneous_statement(size_t i) {
  return getRuleContext<vhdlParser::Simultaneous_statementContext>(i);
}


size_t vhdlParser::Simultaneous_statement_partContext::getRuleIndex() const {
  return vhdlParser::RuleSimultaneous_statement_part;
}

antlrcpp::Any vhdlParser::Simultaneous_statement_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimultaneous_statement_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simultaneous_statement_partContext* vhdlParser::simultaneous_statement_part() {
  Simultaneous_statement_partContext *_localctx = _tracker.createInstance<Simultaneous_statement_partContext>(_ctx, getState());
  enterRule(_localctx, 474, vhdlParser::RuleSimultaneous_statement_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2547);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ABS)
      | (1ULL << vhdlParser::CASE)
      | (1ULL << vhdlParser::IF)
      | (1ULL << vhdlParser::NEW)
      | (1ULL << vhdlParser::NOT)
      | (1ULL << vhdlParser::NULL_SYM))) != 0) || ((((_la - 70) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 70)) & ((1ULL << (vhdlParser::PROCEDURAL - 70))
      | (1ULL << (vhdlParser::BASE_LITERAL - 70))
      | (1ULL << (vhdlParser::BIT_STRING_LITERAL - 70))
      | (1ULL << (vhdlParser::REAL_LITERAL - 70))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 70))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 70))
      | (1ULL << (vhdlParser::CHARACTER_LITERAL - 70))
      | (1ULL << (vhdlParser::STRING_LITERAL - 70)))) != 0) || ((((_la - 146) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 146)) & ((1ULL << (vhdlParser::LPAREN - 146))
      | (1ULL << (vhdlParser::PLUS - 146))
      | (1ULL << (vhdlParser::MINUS - 146))
      | (1ULL << (vhdlParser::INTEGER - 146)))) != 0)) {
      setState(2544);
      simultaneous_statement();
      setState(2549);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Source_aspectContext ------------------------------------------------------------------

vhdlParser::Source_aspectContext::Source_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Source_aspectContext::SPECTRUM() {
  return getToken(vhdlParser::SPECTRUM, 0);
}

std::vector<vhdlParser::Simple_expressionContext *> vhdlParser::Source_aspectContext::simple_expression() {
  return getRuleContexts<vhdlParser::Simple_expressionContext>();
}

vhdlParser::Simple_expressionContext* vhdlParser::Source_aspectContext::simple_expression(size_t i) {
  return getRuleContext<vhdlParser::Simple_expressionContext>(i);
}

tree::TerminalNode* vhdlParser::Source_aspectContext::COMMA() {
  return getToken(vhdlParser::COMMA, 0);
}

tree::TerminalNode* vhdlParser::Source_aspectContext::NOISE() {
  return getToken(vhdlParser::NOISE, 0);
}


size_t vhdlParser::Source_aspectContext::getRuleIndex() const {
  return vhdlParser::RuleSource_aspect;
}

antlrcpp::Any vhdlParser::Source_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSource_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Source_aspectContext* vhdlParser::source_aspect() {
  Source_aspectContext *_localctx = _tracker.createInstance<Source_aspectContext>(_ctx, getState());
  enterRule(_localctx, 476, vhdlParser::RuleSource_aspect);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2557);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::SPECTRUM: {
        enterOuterAlt(_localctx, 1);
        setState(2550);
        match(vhdlParser::SPECTRUM);
        setState(2551);
        simple_expression();
        setState(2552);
        match(vhdlParser::COMMA);
        setState(2553);
        simple_expression();
        break;
      }

      case vhdlParser::NOISE: {
        enterOuterAlt(_localctx, 2);
        setState(2555);
        match(vhdlParser::NOISE);
        setState(2556);
        simple_expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Source_quantity_declarationContext ------------------------------------------------------------------

vhdlParser::Source_quantity_declarationContext::Source_quantity_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Source_quantity_declarationContext::QUANTITY() {
  return getToken(vhdlParser::QUANTITY, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Source_quantity_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Source_quantity_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Source_quantity_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

vhdlParser::Source_aspectContext* vhdlParser::Source_quantity_declarationContext::source_aspect() {
  return getRuleContext<vhdlParser::Source_aspectContext>(0);
}

tree::TerminalNode* vhdlParser::Source_quantity_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Source_quantity_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleSource_quantity_declaration;
}

antlrcpp::Any vhdlParser::Source_quantity_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSource_quantity_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Source_quantity_declarationContext* vhdlParser::source_quantity_declaration() {
  Source_quantity_declarationContext *_localctx = _tracker.createInstance<Source_quantity_declarationContext>(_ctx, getState());
  enterRule(_localctx, 478, vhdlParser::RuleSource_quantity_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2559);
    match(vhdlParser::QUANTITY);
    setState(2560);
    identifier_list();
    setState(2561);
    match(vhdlParser::COLON);
    setState(2562);
    subtype_indication();
    setState(2563);
    source_aspect();
    setState(2564);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Step_limit_specificationContext ------------------------------------------------------------------

vhdlParser::Step_limit_specificationContext::Step_limit_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Step_limit_specificationContext::LIMIT() {
  return getToken(vhdlParser::LIMIT, 0);
}

vhdlParser::Quantity_specificationContext* vhdlParser::Step_limit_specificationContext::quantity_specification() {
  return getRuleContext<vhdlParser::Quantity_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Step_limit_specificationContext::WITH() {
  return getToken(vhdlParser::WITH, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Step_limit_specificationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Step_limit_specificationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Step_limit_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleStep_limit_specification;
}

antlrcpp::Any vhdlParser::Step_limit_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitStep_limit_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Step_limit_specificationContext* vhdlParser::step_limit_specification() {
  Step_limit_specificationContext *_localctx = _tracker.createInstance<Step_limit_specificationContext>(_ctx, getState());
  enterRule(_localctx, 480, vhdlParser::RuleStep_limit_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2566);
    match(vhdlParser::LIMIT);
    setState(2567);
    quantity_specification();
    setState(2568);
    match(vhdlParser::WITH);
    setState(2569);
    expression();
    setState(2570);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subnature_declarationContext ------------------------------------------------------------------

vhdlParser::Subnature_declarationContext::Subnature_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Subnature_declarationContext::SUBNATURE() {
  return getToken(vhdlParser::SUBNATURE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Subnature_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Subnature_declarationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::Subnature_indicationContext* vhdlParser::Subnature_declarationContext::subnature_indication() {
  return getRuleContext<vhdlParser::Subnature_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Subnature_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Subnature_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleSubnature_declaration;
}

antlrcpp::Any vhdlParser::Subnature_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSubnature_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subnature_declarationContext* vhdlParser::subnature_declaration() {
  Subnature_declarationContext *_localctx = _tracker.createInstance<Subnature_declarationContext>(_ctx, getState());
  enterRule(_localctx, 482, vhdlParser::RuleSubnature_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2572);
    match(vhdlParser::SUBNATURE);
    setState(2573);
    identifier();
    setState(2574);
    match(vhdlParser::IS);
    setState(2575);
    subnature_indication();
    setState(2576);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subnature_indicationContext ------------------------------------------------------------------

vhdlParser::Subnature_indicationContext::Subnature_indicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::Subnature_indicationContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

vhdlParser::Index_constraintContext* vhdlParser::Subnature_indicationContext::index_constraint() {
  return getRuleContext<vhdlParser::Index_constraintContext>(0);
}

tree::TerminalNode* vhdlParser::Subnature_indicationContext::TOLERANCE() {
  return getToken(vhdlParser::TOLERANCE, 0);
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::Subnature_indicationContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::Subnature_indicationContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

tree::TerminalNode* vhdlParser::Subnature_indicationContext::ACROSS() {
  return getToken(vhdlParser::ACROSS, 0);
}

tree::TerminalNode* vhdlParser::Subnature_indicationContext::THROUGH() {
  return getToken(vhdlParser::THROUGH, 0);
}


size_t vhdlParser::Subnature_indicationContext::getRuleIndex() const {
  return vhdlParser::RuleSubnature_indication;
}

antlrcpp::Any vhdlParser::Subnature_indicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSubnature_indication(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subnature_indicationContext* vhdlParser::subnature_indication() {
  Subnature_indicationContext *_localctx = _tracker.createInstance<Subnature_indicationContext>(_ctx, getState());
  enterRule(_localctx, 484, vhdlParser::RuleSubnature_indication);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2578);
    name();
    setState(2580);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LPAREN) {
      setState(2579);
      index_constraint();
    }
    setState(2588);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::TOLERANCE) {
      setState(2582);
      match(vhdlParser::TOLERANCE);
      setState(2583);
      expression();
      setState(2584);
      match(vhdlParser::ACROSS);
      setState(2585);
      expression();
      setState(2586);
      match(vhdlParser::THROUGH);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_bodyContext ------------------------------------------------------------------

vhdlParser::Subprogram_bodyContext::Subprogram_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_specificationContext* vhdlParser::Subprogram_bodyContext::subprogram_specification() {
  return getRuleContext<vhdlParser::Subprogram_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Subprogram_bodyContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::Subprogram_declarative_partContext* vhdlParser::Subprogram_bodyContext::subprogram_declarative_part() {
  return getRuleContext<vhdlParser::Subprogram_declarative_partContext>(0);
}

tree::TerminalNode* vhdlParser::Subprogram_bodyContext::BEGIN() {
  return getToken(vhdlParser::BEGIN, 0);
}

vhdlParser::Subprogram_statement_partContext* vhdlParser::Subprogram_bodyContext::subprogram_statement_part() {
  return getRuleContext<vhdlParser::Subprogram_statement_partContext>(0);
}

tree::TerminalNode* vhdlParser::Subprogram_bodyContext::END() {
  return getToken(vhdlParser::END, 0);
}

tree::TerminalNode* vhdlParser::Subprogram_bodyContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Subprogram_kindContext* vhdlParser::Subprogram_bodyContext::subprogram_kind() {
  return getRuleContext<vhdlParser::Subprogram_kindContext>(0);
}

vhdlParser::DesignatorContext* vhdlParser::Subprogram_bodyContext::designator() {
  return getRuleContext<vhdlParser::DesignatorContext>(0);
}


size_t vhdlParser::Subprogram_bodyContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_body;
}

antlrcpp::Any vhdlParser::Subprogram_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSubprogram_body(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_bodyContext* vhdlParser::subprogram_body() {
  Subprogram_bodyContext *_localctx = _tracker.createInstance<Subprogram_bodyContext>(_ctx, getState());
  enterRule(_localctx, 486, vhdlParser::RuleSubprogram_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2590);
    subprogram_specification();
    setState(2591);
    match(vhdlParser::IS);
    setState(2592);
    subprogram_declarative_part();
    setState(2593);
    match(vhdlParser::BEGIN);
    setState(2594);
    subprogram_statement_part();
    setState(2595);
    match(vhdlParser::END);
    setState(2597);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::FUNCTION

    || _la == vhdlParser::PROCEDURE) {
      setState(2596);
      subprogram_kind();
    }
    setState(2600);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 121) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 121)) & ((1ULL << (vhdlParser::BASIC_IDENTIFIER - 121))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 121))
      | (1ULL << (vhdlParser::STRING_LITERAL - 121)))) != 0)) {
      setState(2599);
      designator();
    }
    setState(2602);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_declarationContext ------------------------------------------------------------------

vhdlParser::Subprogram_declarationContext::Subprogram_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_specificationContext* vhdlParser::Subprogram_declarationContext::subprogram_specification() {
  return getRuleContext<vhdlParser::Subprogram_specificationContext>(0);
}

tree::TerminalNode* vhdlParser::Subprogram_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Subprogram_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_declaration;
}

antlrcpp::Any vhdlParser::Subprogram_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSubprogram_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_declarationContext* vhdlParser::subprogram_declaration() {
  Subprogram_declarationContext *_localctx = _tracker.createInstance<Subprogram_declarationContext>(_ctx, getState());
  enterRule(_localctx, 488, vhdlParser::RuleSubprogram_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2604);
    subprogram_specification();
    setState(2605);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_declarative_itemContext ------------------------------------------------------------------

vhdlParser::Subprogram_declarative_itemContext::Subprogram_declarative_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Subprogram_declarationContext* vhdlParser::Subprogram_declarative_itemContext::subprogram_declaration() {
  return getRuleContext<vhdlParser::Subprogram_declarationContext>(0);
}

vhdlParser::Subprogram_bodyContext* vhdlParser::Subprogram_declarative_itemContext::subprogram_body() {
  return getRuleContext<vhdlParser::Subprogram_bodyContext>(0);
}

vhdlParser::Type_declarationContext* vhdlParser::Subprogram_declarative_itemContext::type_declaration() {
  return getRuleContext<vhdlParser::Type_declarationContext>(0);
}

vhdlParser::Subtype_declarationContext* vhdlParser::Subprogram_declarative_itemContext::subtype_declaration() {
  return getRuleContext<vhdlParser::Subtype_declarationContext>(0);
}

vhdlParser::Constant_declarationContext* vhdlParser::Subprogram_declarative_itemContext::constant_declaration() {
  return getRuleContext<vhdlParser::Constant_declarationContext>(0);
}

vhdlParser::Variable_declarationContext* vhdlParser::Subprogram_declarative_itemContext::variable_declaration() {
  return getRuleContext<vhdlParser::Variable_declarationContext>(0);
}

vhdlParser::File_declarationContext* vhdlParser::Subprogram_declarative_itemContext::file_declaration() {
  return getRuleContext<vhdlParser::File_declarationContext>(0);
}

vhdlParser::Alias_declarationContext* vhdlParser::Subprogram_declarative_itemContext::alias_declaration() {
  return getRuleContext<vhdlParser::Alias_declarationContext>(0);
}

vhdlParser::Attribute_declarationContext* vhdlParser::Subprogram_declarative_itemContext::attribute_declaration() {
  return getRuleContext<vhdlParser::Attribute_declarationContext>(0);
}

vhdlParser::Attribute_specificationContext* vhdlParser::Subprogram_declarative_itemContext::attribute_specification() {
  return getRuleContext<vhdlParser::Attribute_specificationContext>(0);
}

vhdlParser::Use_clauseContext* vhdlParser::Subprogram_declarative_itemContext::use_clause() {
  return getRuleContext<vhdlParser::Use_clauseContext>(0);
}

vhdlParser::Group_template_declarationContext* vhdlParser::Subprogram_declarative_itemContext::group_template_declaration() {
  return getRuleContext<vhdlParser::Group_template_declarationContext>(0);
}

vhdlParser::Group_declarationContext* vhdlParser::Subprogram_declarative_itemContext::group_declaration() {
  return getRuleContext<vhdlParser::Group_declarationContext>(0);
}


size_t vhdlParser::Subprogram_declarative_itemContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_declarative_item;
}

antlrcpp::Any vhdlParser::Subprogram_declarative_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSubprogram_declarative_item(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_declarative_itemContext* vhdlParser::subprogram_declarative_item() {
  Subprogram_declarative_itemContext *_localctx = _tracker.createInstance<Subprogram_declarative_itemContext>(_ctx, getState());
  enterRule(_localctx, 490, vhdlParser::RuleSubprogram_declarative_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2620);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 291, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2607);
      subprogram_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2608);
      subprogram_body();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2609);
      type_declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(2610);
      subtype_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(2611);
      constant_declaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(2612);
      variable_declaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(2613);
      file_declaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(2614);
      alias_declaration();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(2615);
      attribute_declaration();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(2616);
      attribute_specification();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(2617);
      use_clause();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(2618);
      group_template_declaration();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(2619);
      group_declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_declarative_partContext ------------------------------------------------------------------

vhdlParser::Subprogram_declarative_partContext::Subprogram_declarative_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Subprogram_declarative_itemContext *> vhdlParser::Subprogram_declarative_partContext::subprogram_declarative_item() {
  return getRuleContexts<vhdlParser::Subprogram_declarative_itemContext>();
}

vhdlParser::Subprogram_declarative_itemContext* vhdlParser::Subprogram_declarative_partContext::subprogram_declarative_item(size_t i) {
  return getRuleContext<vhdlParser::Subprogram_declarative_itemContext>(i);
}


size_t vhdlParser::Subprogram_declarative_partContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_declarative_part;
}

antlrcpp::Any vhdlParser::Subprogram_declarative_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSubprogram_declarative_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_declarative_partContext* vhdlParser::subprogram_declarative_part() {
  Subprogram_declarative_partContext *_localctx = _tracker.createInstance<Subprogram_declarative_partContext>(_ctx, getState());
  enterRule(_localctx, 492, vhdlParser::RuleSubprogram_declarative_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2625);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ALIAS)
      | (1ULL << vhdlParser::ATTRIBUTE)
      | (1ULL << vhdlParser::CONSTANT)
      | (1ULL << vhdlParser::FILE)
      | (1ULL << vhdlParser::FUNCTION)
      | (1ULL << vhdlParser::GROUP)
      | (1ULL << vhdlParser::IMPURE))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (vhdlParser::PROCEDURE - 69))
      | (1ULL << (vhdlParser::PURE - 69))
      | (1ULL << (vhdlParser::SHARED - 69))
      | (1ULL << (vhdlParser::SUBTYPE - 69))
      | (1ULL << (vhdlParser::TYPE - 69))
      | (1ULL << (vhdlParser::USE - 69))
      | (1ULL << (vhdlParser::VARIABLE - 69)))) != 0)) {
      setState(2622);
      subprogram_declarative_item();
      setState(2627);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_kindContext ------------------------------------------------------------------

vhdlParser::Subprogram_kindContext::Subprogram_kindContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Subprogram_kindContext::PROCEDURE() {
  return getToken(vhdlParser::PROCEDURE, 0);
}

tree::TerminalNode* vhdlParser::Subprogram_kindContext::FUNCTION() {
  return getToken(vhdlParser::FUNCTION, 0);
}


size_t vhdlParser::Subprogram_kindContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_kind;
}

antlrcpp::Any vhdlParser::Subprogram_kindContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSubprogram_kind(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_kindContext* vhdlParser::subprogram_kind() {
  Subprogram_kindContext *_localctx = _tracker.createInstance<Subprogram_kindContext>(_ctx, getState());
  enterRule(_localctx, 494, vhdlParser::RuleSubprogram_kind);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2628);
    _la = _input->LA(1);
    if (!(_la == vhdlParser::FUNCTION

    || _la == vhdlParser::PROCEDURE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_specificationContext ------------------------------------------------------------------

vhdlParser::Subprogram_specificationContext::Subprogram_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Procedure_specificationContext* vhdlParser::Subprogram_specificationContext::procedure_specification() {
  return getRuleContext<vhdlParser::Procedure_specificationContext>(0);
}

vhdlParser::Function_specificationContext* vhdlParser::Subprogram_specificationContext::function_specification() {
  return getRuleContext<vhdlParser::Function_specificationContext>(0);
}


size_t vhdlParser::Subprogram_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_specification;
}

antlrcpp::Any vhdlParser::Subprogram_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSubprogram_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_specificationContext* vhdlParser::subprogram_specification() {
  Subprogram_specificationContext *_localctx = _tracker.createInstance<Subprogram_specificationContext>(_ctx, getState());
  enterRule(_localctx, 496, vhdlParser::RuleSubprogram_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2632);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::PROCEDURE: {
        enterOuterAlt(_localctx, 1);
        setState(2630);
        procedure_specification();
        break;
      }

      case vhdlParser::FUNCTION:
      case vhdlParser::IMPURE:
      case vhdlParser::PURE: {
        enterOuterAlt(_localctx, 2);
        setState(2631);
        function_specification();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Procedure_specificationContext ------------------------------------------------------------------

vhdlParser::Procedure_specificationContext::Procedure_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Procedure_specificationContext::PROCEDURE() {
  return getToken(vhdlParser::PROCEDURE, 0);
}

vhdlParser::DesignatorContext* vhdlParser::Procedure_specificationContext::designator() {
  return getRuleContext<vhdlParser::DesignatorContext>(0);
}

tree::TerminalNode* vhdlParser::Procedure_specificationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Formal_parameter_listContext* vhdlParser::Procedure_specificationContext::formal_parameter_list() {
  return getRuleContext<vhdlParser::Formal_parameter_listContext>(0);
}

tree::TerminalNode* vhdlParser::Procedure_specificationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}


size_t vhdlParser::Procedure_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleProcedure_specification;
}

antlrcpp::Any vhdlParser::Procedure_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitProcedure_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Procedure_specificationContext* vhdlParser::procedure_specification() {
  Procedure_specificationContext *_localctx = _tracker.createInstance<Procedure_specificationContext>(_ctx, getState());
  enterRule(_localctx, 498, vhdlParser::RuleProcedure_specification);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2634);
    match(vhdlParser::PROCEDURE);
    setState(2635);
    designator();
    setState(2640);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LPAREN) {
      setState(2636);
      match(vhdlParser::LPAREN);
      setState(2637);
      formal_parameter_list();
      setState(2638);
      match(vhdlParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_specificationContext ------------------------------------------------------------------

vhdlParser::Function_specificationContext::Function_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Function_specificationContext::FUNCTION() {
  return getToken(vhdlParser::FUNCTION, 0);
}

vhdlParser::DesignatorContext* vhdlParser::Function_specificationContext::designator() {
  return getRuleContext<vhdlParser::DesignatorContext>(0);
}

tree::TerminalNode* vhdlParser::Function_specificationContext::RETURN() {
  return getToken(vhdlParser::RETURN, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Function_specificationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Function_specificationContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

vhdlParser::Formal_parameter_listContext* vhdlParser::Function_specificationContext::formal_parameter_list() {
  return getRuleContext<vhdlParser::Formal_parameter_listContext>(0);
}

tree::TerminalNode* vhdlParser::Function_specificationContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Function_specificationContext::PURE() {
  return getToken(vhdlParser::PURE, 0);
}

tree::TerminalNode* vhdlParser::Function_specificationContext::IMPURE() {
  return getToken(vhdlParser::IMPURE, 0);
}


size_t vhdlParser::Function_specificationContext::getRuleIndex() const {
  return vhdlParser::RuleFunction_specification;
}

antlrcpp::Any vhdlParser::Function_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitFunction_specification(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Function_specificationContext* vhdlParser::function_specification() {
  Function_specificationContext *_localctx = _tracker.createInstance<Function_specificationContext>(_ctx, getState());
  enterRule(_localctx, 500, vhdlParser::RuleFunction_specification);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2643);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IMPURE

    || _la == vhdlParser::PURE) {
      setState(2642);
      _la = _input->LA(1);
      if (!(_la == vhdlParser::IMPURE

      || _la == vhdlParser::PURE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(2645);
    match(vhdlParser::FUNCTION);
    setState(2646);
    designator();
    setState(2651);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::LPAREN) {
      setState(2647);
      match(vhdlParser::LPAREN);
      setState(2648);
      formal_parameter_list();
      setState(2649);
      match(vhdlParser::RPAREN);
    }
    setState(2653);
    match(vhdlParser::RETURN);
    setState(2654);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_statement_partContext ------------------------------------------------------------------

vhdlParser::Subprogram_statement_partContext::Subprogram_statement_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Sequential_statementContext *> vhdlParser::Subprogram_statement_partContext::sequential_statement() {
  return getRuleContexts<vhdlParser::Sequential_statementContext>();
}

vhdlParser::Sequential_statementContext* vhdlParser::Subprogram_statement_partContext::sequential_statement(size_t i) {
  return getRuleContext<vhdlParser::Sequential_statementContext>(i);
}


size_t vhdlParser::Subprogram_statement_partContext::getRuleIndex() const {
  return vhdlParser::RuleSubprogram_statement_part;
}

antlrcpp::Any vhdlParser::Subprogram_statement_partContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSubprogram_statement_part(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subprogram_statement_partContext* vhdlParser::subprogram_statement_part() {
  Subprogram_statement_partContext *_localctx = _tracker.createInstance<Subprogram_statement_partContext>(_ctx, getState());
  enterRule(_localctx, 502, vhdlParser::RuleSubprogram_statement_part);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2659);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << vhdlParser::ASSERT)
      | (1ULL << vhdlParser::BREAK)
      | (1ULL << vhdlParser::CASE)
      | (1ULL << vhdlParser::EXIT)
      | (1ULL << vhdlParser::FOR)
      | (1ULL << vhdlParser::IF)
      | (1ULL << vhdlParser::LOOP)
      | (1ULL << vhdlParser::NEXT)
      | (1ULL << vhdlParser::NULL_SYM))) != 0) || ((((_la - 81) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 81)) & ((1ULL << (vhdlParser::REPORT - 81))
      | (1ULL << (vhdlParser::RETURN - 81))
      | (1ULL << (vhdlParser::WAIT - 81))
      | (1ULL << (vhdlParser::WITH - 81))
      | (1ULL << (vhdlParser::WHILE - 81))
      | (1ULL << (vhdlParser::BASIC_IDENTIFIER - 81))
      | (1ULL << (vhdlParser::EXTENDED_IDENTIFIER - 81)))) != 0) || _la == vhdlParser::LPAREN) {
      setState(2656);
      sequential_statement();
      setState(2661);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subtype_declarationContext ------------------------------------------------------------------

vhdlParser::Subtype_declarationContext::Subtype_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Subtype_declarationContext::SUBTYPE() {
  return getToken(vhdlParser::SUBTYPE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Subtype_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Subtype_declarationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Subtype_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Subtype_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Subtype_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleSubtype_declaration;
}

antlrcpp::Any vhdlParser::Subtype_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSubtype_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subtype_declarationContext* vhdlParser::subtype_declaration() {
  Subtype_declarationContext *_localctx = _tracker.createInstance<Subtype_declarationContext>(_ctx, getState());
  enterRule(_localctx, 504, vhdlParser::RuleSubtype_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2662);
    match(vhdlParser::SUBTYPE);
    setState(2663);
    identifier();
    setState(2664);
    match(vhdlParser::IS);
    setState(2665);
    subtype_indication();
    setState(2666);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subtype_indicationContext ------------------------------------------------------------------

vhdlParser::Subtype_indicationContext::Subtype_indicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Selected_nameContext *> vhdlParser::Subtype_indicationContext::selected_name() {
  return getRuleContexts<vhdlParser::Selected_nameContext>();
}

vhdlParser::Selected_nameContext* vhdlParser::Subtype_indicationContext::selected_name(size_t i) {
  return getRuleContext<vhdlParser::Selected_nameContext>(i);
}

std::vector<vhdlParser::ConstraintContext *> vhdlParser::Subtype_indicationContext::constraint() {
  return getRuleContexts<vhdlParser::ConstraintContext>();
}

vhdlParser::ConstraintContext* vhdlParser::Subtype_indicationContext::constraint(size_t i) {
  return getRuleContext<vhdlParser::ConstraintContext>(i);
}

vhdlParser::Tolerance_aspectContext* vhdlParser::Subtype_indicationContext::tolerance_aspect() {
  return getRuleContext<vhdlParser::Tolerance_aspectContext>(0);
}


size_t vhdlParser::Subtype_indicationContext::getRuleIndex() const {
  return vhdlParser::RuleSubtype_indication;
}

antlrcpp::Any vhdlParser::Subtype_indicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSubtype_indication(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Subtype_indicationContext* vhdlParser::subtype_indication() {
  Subtype_indicationContext *_localctx = _tracker.createInstance<Subtype_indicationContext>(_ctx, getState());
  enterRule(_localctx, 506, vhdlParser::RuleSubtype_indication);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2668);
    selected_name();
    setState(2670);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 298, _ctx)) {
    case 1: {
      setState(2669);
      selected_name();
      break;
    }

    }
    setState(2675);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 299, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(2672);
        constraint(); 
      }
      setState(2677);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 299, _ctx);
    }
    setState(2679);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 300, _ctx)) {
    case 1: {
      setState(2678);
      tolerance_aspect();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuffixContext ------------------------------------------------------------------

vhdlParser::SuffixContext::SuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::IdentifierContext* vhdlParser::SuffixContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::SuffixContext::CHARACTER_LITERAL() {
  return getToken(vhdlParser::CHARACTER_LITERAL, 0);
}

tree::TerminalNode* vhdlParser::SuffixContext::STRING_LITERAL() {
  return getToken(vhdlParser::STRING_LITERAL, 0);
}

tree::TerminalNode* vhdlParser::SuffixContext::ALL() {
  return getToken(vhdlParser::ALL, 0);
}


size_t vhdlParser::SuffixContext::getRuleIndex() const {
  return vhdlParser::RuleSuffix;
}

antlrcpp::Any vhdlParser::SuffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSuffix(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::SuffixContext* vhdlParser::suffix() {
  SuffixContext *_localctx = _tracker.createInstance<SuffixContext>(_ctx, getState());
  enterRule(_localctx, 508, vhdlParser::RuleSuffix);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2685);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(2681);
        identifier();
        break;
      }

      case vhdlParser::CHARACTER_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(2682);
        match(vhdlParser::CHARACTER_LITERAL);
        break;
      }

      case vhdlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(2683);
        match(vhdlParser::STRING_LITERAL);
        break;
      }

      case vhdlParser::ALL: {
        enterOuterAlt(_localctx, 4);
        setState(2684);
        match(vhdlParser::ALL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetContext ------------------------------------------------------------------

vhdlParser::TargetContext::TargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::NameContext* vhdlParser::TargetContext::name() {
  return getRuleContext<vhdlParser::NameContext>(0);
}

vhdlParser::AggregateContext* vhdlParser::TargetContext::aggregate() {
  return getRuleContext<vhdlParser::AggregateContext>(0);
}


size_t vhdlParser::TargetContext::getRuleIndex() const {
  return vhdlParser::RuleTarget;
}

antlrcpp::Any vhdlParser::TargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitTarget(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::TargetContext* vhdlParser::target() {
  TargetContext *_localctx = _tracker.createInstance<TargetContext>(_ctx, getState());
  enterRule(_localctx, 510, vhdlParser::RuleTarget);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2689);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(2687);
        name();
        break;
      }

      case vhdlParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(2688);
        aggregate();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

vhdlParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::FactorContext *> vhdlParser::TermContext::factor() {
  return getRuleContexts<vhdlParser::FactorContext>();
}

vhdlParser::FactorContext* vhdlParser::TermContext::factor(size_t i) {
  return getRuleContext<vhdlParser::FactorContext>(i);
}

std::vector<vhdlParser::Multiplying_operatorContext *> vhdlParser::TermContext::multiplying_operator() {
  return getRuleContexts<vhdlParser::Multiplying_operatorContext>();
}

vhdlParser::Multiplying_operatorContext* vhdlParser::TermContext::multiplying_operator(size_t i) {
  return getRuleContext<vhdlParser::Multiplying_operatorContext>(i);
}


size_t vhdlParser::TermContext::getRuleIndex() const {
  return vhdlParser::RuleTerm;
}

antlrcpp::Any vhdlParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::TermContext* vhdlParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 512, vhdlParser::RuleTerm);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2691);
    factor();
    setState(2697);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 303, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(2692);
        multiplying_operator();
        setState(2693);
        factor(); 
      }
      setState(2699);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 303, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Terminal_aspectContext ------------------------------------------------------------------

vhdlParser::Terminal_aspectContext::Terminal_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::NameContext *> vhdlParser::Terminal_aspectContext::name() {
  return getRuleContexts<vhdlParser::NameContext>();
}

vhdlParser::NameContext* vhdlParser::Terminal_aspectContext::name(size_t i) {
  return getRuleContext<vhdlParser::NameContext>(i);
}

tree::TerminalNode* vhdlParser::Terminal_aspectContext::TO() {
  return getToken(vhdlParser::TO, 0);
}


size_t vhdlParser::Terminal_aspectContext::getRuleIndex() const {
  return vhdlParser::RuleTerminal_aspect;
}

antlrcpp::Any vhdlParser::Terminal_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitTerminal_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Terminal_aspectContext* vhdlParser::terminal_aspect() {
  Terminal_aspectContext *_localctx = _tracker.createInstance<Terminal_aspectContext>(_ctx, getState());
  enterRule(_localctx, 514, vhdlParser::RuleTerminal_aspect);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2700);
    name();
    setState(2703);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::TO) {
      setState(2701);
      match(vhdlParser::TO);
      setState(2702);
      name();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Terminal_declarationContext ------------------------------------------------------------------

vhdlParser::Terminal_declarationContext::Terminal_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Terminal_declarationContext::TERMINAL() {
  return getToken(vhdlParser::TERMINAL, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Terminal_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Terminal_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subnature_indicationContext* vhdlParser::Terminal_declarationContext::subnature_indication() {
  return getRuleContext<vhdlParser::Subnature_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Terminal_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Terminal_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleTerminal_declaration;
}

antlrcpp::Any vhdlParser::Terminal_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitTerminal_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Terminal_declarationContext* vhdlParser::terminal_declaration() {
  Terminal_declarationContext *_localctx = _tracker.createInstance<Terminal_declarationContext>(_ctx, getState());
  enterRule(_localctx, 516, vhdlParser::RuleTerminal_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2705);
    match(vhdlParser::TERMINAL);
    setState(2706);
    identifier_list();
    setState(2707);
    match(vhdlParser::COLON);
    setState(2708);
    subnature_indication();
    setState(2709);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Through_aspectContext ------------------------------------------------------------------

vhdlParser::Through_aspectContext::Through_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Identifier_listContext* vhdlParser::Through_aspectContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Through_aspectContext::THROUGH() {
  return getToken(vhdlParser::THROUGH, 0);
}

vhdlParser::Tolerance_aspectContext* vhdlParser::Through_aspectContext::tolerance_aspect() {
  return getRuleContext<vhdlParser::Tolerance_aspectContext>(0);
}

tree::TerminalNode* vhdlParser::Through_aspectContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Through_aspectContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Through_aspectContext::getRuleIndex() const {
  return vhdlParser::RuleThrough_aspect;
}

antlrcpp::Any vhdlParser::Through_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitThrough_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Through_aspectContext* vhdlParser::through_aspect() {
  Through_aspectContext *_localctx = _tracker.createInstance<Through_aspectContext>(_ctx, getState());
  enterRule(_localctx, 518, vhdlParser::RuleThrough_aspect);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2711);
    identifier_list();
    setState(2713);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::TOLERANCE) {
      setState(2712);
      tolerance_aspect();
    }
    setState(2717);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(2715);
      match(vhdlParser::VARASGN);
      setState(2716);
      expression();
    }
    setState(2719);
    match(vhdlParser::THROUGH);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Timeout_clauseContext ------------------------------------------------------------------

vhdlParser::Timeout_clauseContext::Timeout_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Timeout_clauseContext::FOR() {
  return getToken(vhdlParser::FOR, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Timeout_clauseContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Timeout_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleTimeout_clause;
}

antlrcpp::Any vhdlParser::Timeout_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitTimeout_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Timeout_clauseContext* vhdlParser::timeout_clause() {
  Timeout_clauseContext *_localctx = _tracker.createInstance<Timeout_clauseContext>(_ctx, getState());
  enterRule(_localctx, 520, vhdlParser::RuleTimeout_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2721);
    match(vhdlParser::FOR);
    setState(2722);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tolerance_aspectContext ------------------------------------------------------------------

vhdlParser::Tolerance_aspectContext::Tolerance_aspectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Tolerance_aspectContext::TOLERANCE() {
  return getToken(vhdlParser::TOLERANCE, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Tolerance_aspectContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Tolerance_aspectContext::getRuleIndex() const {
  return vhdlParser::RuleTolerance_aspect;
}

antlrcpp::Any vhdlParser::Tolerance_aspectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitTolerance_aspect(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Tolerance_aspectContext* vhdlParser::tolerance_aspect() {
  Tolerance_aspectContext *_localctx = _tracker.createInstance<Tolerance_aspectContext>(_ctx, getState());
  enterRule(_localctx, 522, vhdlParser::RuleTolerance_aspect);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2724);
    match(vhdlParser::TOLERANCE);
    setState(2725);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_declarationContext ------------------------------------------------------------------

vhdlParser::Type_declarationContext::Type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Type_declarationContext::TYPE() {
  return getToken(vhdlParser::TYPE, 0);
}

vhdlParser::IdentifierContext* vhdlParser::Type_declarationContext::identifier() {
  return getRuleContext<vhdlParser::IdentifierContext>(0);
}

tree::TerminalNode* vhdlParser::Type_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Type_declarationContext::IS() {
  return getToken(vhdlParser::IS, 0);
}

vhdlParser::Type_definitionContext* vhdlParser::Type_declarationContext::type_definition() {
  return getRuleContext<vhdlParser::Type_definitionContext>(0);
}


size_t vhdlParser::Type_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleType_declaration;
}

antlrcpp::Any vhdlParser::Type_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitType_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Type_declarationContext* vhdlParser::type_declaration() {
  Type_declarationContext *_localctx = _tracker.createInstance<Type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 524, vhdlParser::RuleType_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2727);
    match(vhdlParser::TYPE);
    setState(2728);
    identifier();
    setState(2731);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::IS) {
      setState(2729);
      match(vhdlParser::IS);
      setState(2730);
      type_definition();
    }
    setState(2733);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_definitionContext ------------------------------------------------------------------

vhdlParser::Type_definitionContext::Type_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Scalar_type_definitionContext* vhdlParser::Type_definitionContext::scalar_type_definition() {
  return getRuleContext<vhdlParser::Scalar_type_definitionContext>(0);
}

vhdlParser::Composite_type_definitionContext* vhdlParser::Type_definitionContext::composite_type_definition() {
  return getRuleContext<vhdlParser::Composite_type_definitionContext>(0);
}

vhdlParser::Access_type_definitionContext* vhdlParser::Type_definitionContext::access_type_definition() {
  return getRuleContext<vhdlParser::Access_type_definitionContext>(0);
}

vhdlParser::File_type_definitionContext* vhdlParser::Type_definitionContext::file_type_definition() {
  return getRuleContext<vhdlParser::File_type_definitionContext>(0);
}


size_t vhdlParser::Type_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleType_definition;
}

antlrcpp::Any vhdlParser::Type_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitType_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Type_definitionContext* vhdlParser::type_definition() {
  Type_definitionContext *_localctx = _tracker.createInstance<Type_definitionContext>(_ctx, getState());
  enterRule(_localctx, 526, vhdlParser::RuleType_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2739);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::RANGE:
      case vhdlParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(2735);
        scalar_type_definition();
        break;
      }

      case vhdlParser::ARRAY:
      case vhdlParser::RECORD: {
        enterOuterAlt(_localctx, 2);
        setState(2736);
        composite_type_definition();
        break;
      }

      case vhdlParser::ACCESS: {
        enterOuterAlt(_localctx, 3);
        setState(2737);
        access_type_definition();
        break;
      }

      case vhdlParser::FILE: {
        enterOuterAlt(_localctx, 4);
        setState(2738);
        file_type_definition();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unconstrained_array_definitionContext ------------------------------------------------------------------

vhdlParser::Unconstrained_array_definitionContext::Unconstrained_array_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Unconstrained_array_definitionContext::ARRAY() {
  return getToken(vhdlParser::ARRAY, 0);
}

tree::TerminalNode* vhdlParser::Unconstrained_array_definitionContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Index_subtype_definitionContext *> vhdlParser::Unconstrained_array_definitionContext::index_subtype_definition() {
  return getRuleContexts<vhdlParser::Index_subtype_definitionContext>();
}

vhdlParser::Index_subtype_definitionContext* vhdlParser::Unconstrained_array_definitionContext::index_subtype_definition(size_t i) {
  return getRuleContext<vhdlParser::Index_subtype_definitionContext>(i);
}

tree::TerminalNode* vhdlParser::Unconstrained_array_definitionContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Unconstrained_array_definitionContext::OF() {
  return getToken(vhdlParser::OF, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Unconstrained_array_definitionContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Unconstrained_array_definitionContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Unconstrained_array_definitionContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Unconstrained_array_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleUnconstrained_array_definition;
}

antlrcpp::Any vhdlParser::Unconstrained_array_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitUnconstrained_array_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Unconstrained_array_definitionContext* vhdlParser::unconstrained_array_definition() {
  Unconstrained_array_definitionContext *_localctx = _tracker.createInstance<Unconstrained_array_definitionContext>(_ctx, getState());
  enterRule(_localctx, 528, vhdlParser::RuleUnconstrained_array_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2741);
    match(vhdlParser::ARRAY);
    setState(2742);
    match(vhdlParser::LPAREN);
    setState(2743);
    index_subtype_definition();
    setState(2748);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(2744);
      match(vhdlParser::COMMA);
      setState(2745);
      index_subtype_definition();
      setState(2750);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2751);
    match(vhdlParser::RPAREN);
    setState(2752);
    match(vhdlParser::OF);
    setState(2753);
    subtype_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unconstrained_nature_definitionContext ------------------------------------------------------------------

vhdlParser::Unconstrained_nature_definitionContext::Unconstrained_nature_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Unconstrained_nature_definitionContext::ARRAY() {
  return getToken(vhdlParser::ARRAY, 0);
}

tree::TerminalNode* vhdlParser::Unconstrained_nature_definitionContext::LPAREN() {
  return getToken(vhdlParser::LPAREN, 0);
}

std::vector<vhdlParser::Index_subtype_definitionContext *> vhdlParser::Unconstrained_nature_definitionContext::index_subtype_definition() {
  return getRuleContexts<vhdlParser::Index_subtype_definitionContext>();
}

vhdlParser::Index_subtype_definitionContext* vhdlParser::Unconstrained_nature_definitionContext::index_subtype_definition(size_t i) {
  return getRuleContext<vhdlParser::Index_subtype_definitionContext>(i);
}

tree::TerminalNode* vhdlParser::Unconstrained_nature_definitionContext::RPAREN() {
  return getToken(vhdlParser::RPAREN, 0);
}

tree::TerminalNode* vhdlParser::Unconstrained_nature_definitionContext::OF() {
  return getToken(vhdlParser::OF, 0);
}

vhdlParser::Subnature_indicationContext* vhdlParser::Unconstrained_nature_definitionContext::subnature_indication() {
  return getRuleContext<vhdlParser::Subnature_indicationContext>(0);
}

std::vector<tree::TerminalNode *> vhdlParser::Unconstrained_nature_definitionContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Unconstrained_nature_definitionContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Unconstrained_nature_definitionContext::getRuleIndex() const {
  return vhdlParser::RuleUnconstrained_nature_definition;
}

antlrcpp::Any vhdlParser::Unconstrained_nature_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitUnconstrained_nature_definition(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Unconstrained_nature_definitionContext* vhdlParser::unconstrained_nature_definition() {
  Unconstrained_nature_definitionContext *_localctx = _tracker.createInstance<Unconstrained_nature_definitionContext>(_ctx, getState());
  enterRule(_localctx, 530, vhdlParser::RuleUnconstrained_nature_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2755);
    match(vhdlParser::ARRAY);
    setState(2756);
    match(vhdlParser::LPAREN);
    setState(2757);
    index_subtype_definition();
    setState(2762);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(2758);
      match(vhdlParser::COMMA);
      setState(2759);
      index_subtype_definition();
      setState(2764);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2765);
    match(vhdlParser::RPAREN);
    setState(2766);
    match(vhdlParser::OF);
    setState(2767);
    subnature_indication();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Use_clauseContext ------------------------------------------------------------------

vhdlParser::Use_clauseContext::Use_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Use_clauseContext::USE() {
  return getToken(vhdlParser::USE, 0);
}

std::vector<vhdlParser::Selected_nameContext *> vhdlParser::Use_clauseContext::selected_name() {
  return getRuleContexts<vhdlParser::Selected_nameContext>();
}

vhdlParser::Selected_nameContext* vhdlParser::Use_clauseContext::selected_name(size_t i) {
  return getRuleContext<vhdlParser::Selected_nameContext>(i);
}

tree::TerminalNode* vhdlParser::Use_clauseContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> vhdlParser::Use_clauseContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::Use_clauseContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}


size_t vhdlParser::Use_clauseContext::getRuleIndex() const {
  return vhdlParser::RuleUse_clause;
}

antlrcpp::Any vhdlParser::Use_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitUse_clause(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Use_clauseContext* vhdlParser::use_clause() {
  Use_clauseContext *_localctx = _tracker.createInstance<Use_clauseContext>(_ctx, getState());
  enterRule(_localctx, 532, vhdlParser::RuleUse_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2769);
    match(vhdlParser::USE);
    setState(2770);
    selected_name();
    setState(2775);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == vhdlParser::COMMA) {
      setState(2771);
      match(vhdlParser::COMMA);
      setState(2772);
      selected_name();
      setState(2777);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2778);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_assignment_statementContext ------------------------------------------------------------------

vhdlParser::Variable_assignment_statementContext::Variable_assignment_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::Simple_variable_assignmentContext* vhdlParser::Variable_assignment_statementContext::simple_variable_assignment() {
  return getRuleContext<vhdlParser::Simple_variable_assignmentContext>(0);
}

vhdlParser::Label_colonContext* vhdlParser::Variable_assignment_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::Conditional_variable_assignmentContext* vhdlParser::Variable_assignment_statementContext::conditional_variable_assignment() {
  return getRuleContext<vhdlParser::Conditional_variable_assignmentContext>(0);
}

vhdlParser::Selected_variable_assignmentContext* vhdlParser::Variable_assignment_statementContext::selected_variable_assignment() {
  return getRuleContext<vhdlParser::Selected_variable_assignmentContext>(0);
}


size_t vhdlParser::Variable_assignment_statementContext::getRuleIndex() const {
  return vhdlParser::RuleVariable_assignment_statement;
}

antlrcpp::Any vhdlParser::Variable_assignment_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitVariable_assignment_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Variable_assignment_statementContext* vhdlParser::variable_assignment_statement() {
  Variable_assignment_statementContext *_localctx = _tracker.createInstance<Variable_assignment_statementContext>(_ctx, getState());
  enterRule(_localctx, 534, vhdlParser::RuleVariable_assignment_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2792);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 315, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2781);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 312, _ctx)) {
      case 1: {
        setState(2780);
        label_colon();
        break;
      }

      }
      setState(2783);
      simple_variable_assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2785);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 313, _ctx)) {
      case 1: {
        setState(2784);
        label_colon();
        break;
      }

      }
      setState(2787);
      conditional_variable_assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2789);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == vhdlParser::BASIC_IDENTIFIER

      || _la == vhdlParser::EXTENDED_IDENTIFIER) {
        setState(2788);
        label_colon();
      }
      setState(2791);
      selected_variable_assignment();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_variable_assignmentContext ------------------------------------------------------------------

vhdlParser::Simple_variable_assignmentContext::Simple_variable_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Simple_variable_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_variable_assignmentContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Simple_variable_assignmentContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Simple_variable_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Simple_variable_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSimple_variable_assignment;
}

antlrcpp::Any vhdlParser::Simple_variable_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSimple_variable_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Simple_variable_assignmentContext* vhdlParser::simple_variable_assignment() {
  Simple_variable_assignmentContext *_localctx = _tracker.createInstance<Simple_variable_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 536, vhdlParser::RuleSimple_variable_assignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2794);
    target();
    setState(2795);
    match(vhdlParser::VARASGN);
    setState(2796);
    expression();
    setState(2797);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_variable_assignmentContext ------------------------------------------------------------------

vhdlParser::Conditional_variable_assignmentContext::Conditional_variable_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

vhdlParser::TargetContext* vhdlParser::Conditional_variable_assignmentContext::target() {
  return getRuleContext<vhdlParser::TargetContext>(0);
}

tree::TerminalNode* vhdlParser::Conditional_variable_assignmentContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::Conditional_expressionContext* vhdlParser::Conditional_variable_assignmentContext::conditional_expression() {
  return getRuleContext<vhdlParser::Conditional_expressionContext>(0);
}

tree::TerminalNode* vhdlParser::Conditional_variable_assignmentContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}


size_t vhdlParser::Conditional_variable_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleConditional_variable_assignment;
}

antlrcpp::Any vhdlParser::Conditional_variable_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitConditional_variable_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Conditional_variable_assignmentContext* vhdlParser::conditional_variable_assignment() {
  Conditional_variable_assignmentContext *_localctx = _tracker.createInstance<Conditional_variable_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 538, vhdlParser::RuleConditional_variable_assignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2799);
    target();
    setState(2800);
    match(vhdlParser::VARASGN);
    setState(2801);
    conditional_expression();
    setState(2802);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selected_variable_assignmentContext ------------------------------------------------------------------

vhdlParser::Selected_variable_assignmentContext::Selected_variable_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Selected_variable_assignmentContext::WITH() {
  return getToken(vhdlParser::WITH, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Selected_variable_assignmentContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}

tree::TerminalNode* vhdlParser::Selected_variable_assignmentContext::SELECT() {
  return getToken(vhdlParser::SELECT, 0);
}

tree::TerminalNode* vhdlParser::Selected_variable_assignmentContext::TERNARY() {
  return getToken(vhdlParser::TERNARY, 0);
}


size_t vhdlParser::Selected_variable_assignmentContext::getRuleIndex() const {
  return vhdlParser::RuleSelected_variable_assignment;
}

antlrcpp::Any vhdlParser::Selected_variable_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitSelected_variable_assignment(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Selected_variable_assignmentContext* vhdlParser::selected_variable_assignment() {
  Selected_variable_assignmentContext *_localctx = _tracker.createInstance<Selected_variable_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 540, vhdlParser::RuleSelected_variable_assignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2804);
    match(vhdlParser::WITH);
    setState(2805);
    expression();
    setState(2806);
    match(vhdlParser::SELECT);
    setState(2808);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::TERNARY) {
      setState(2807);
      match(vhdlParser::TERNARY);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declarationContext ------------------------------------------------------------------

vhdlParser::Variable_declarationContext::Variable_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Variable_declarationContext::VARIABLE() {
  return getToken(vhdlParser::VARIABLE, 0);
}

vhdlParser::Identifier_listContext* vhdlParser::Variable_declarationContext::identifier_list() {
  return getRuleContext<vhdlParser::Identifier_listContext>(0);
}

tree::TerminalNode* vhdlParser::Variable_declarationContext::COLON() {
  return getToken(vhdlParser::COLON, 0);
}

vhdlParser::Subtype_indicationContext* vhdlParser::Variable_declarationContext::subtype_indication() {
  return getRuleContext<vhdlParser::Subtype_indicationContext>(0);
}

tree::TerminalNode* vhdlParser::Variable_declarationContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

tree::TerminalNode* vhdlParser::Variable_declarationContext::SHARED() {
  return getToken(vhdlParser::SHARED, 0);
}

tree::TerminalNode* vhdlParser::Variable_declarationContext::VARASGN() {
  return getToken(vhdlParser::VARASGN, 0);
}

vhdlParser::ExpressionContext* vhdlParser::Variable_declarationContext::expression() {
  return getRuleContext<vhdlParser::ExpressionContext>(0);
}


size_t vhdlParser::Variable_declarationContext::getRuleIndex() const {
  return vhdlParser::RuleVariable_declaration;
}

antlrcpp::Any vhdlParser::Variable_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitVariable_declaration(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Variable_declarationContext* vhdlParser::variable_declaration() {
  Variable_declarationContext *_localctx = _tracker.createInstance<Variable_declarationContext>(_ctx, getState());
  enterRule(_localctx, 542, vhdlParser::RuleVariable_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2811);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::SHARED) {
      setState(2810);
      match(vhdlParser::SHARED);
    }
    setState(2813);
    match(vhdlParser::VARIABLE);
    setState(2814);
    identifier_list();
    setState(2815);
    match(vhdlParser::COLON);
    setState(2816);
    subtype_indication();
    setState(2819);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::VARASGN) {
      setState(2817);
      match(vhdlParser::VARASGN);
      setState(2818);
      expression();
    }
    setState(2821);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Wait_statementContext ------------------------------------------------------------------

vhdlParser::Wait_statementContext::Wait_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* vhdlParser::Wait_statementContext::WAIT() {
  return getToken(vhdlParser::WAIT, 0);
}

tree::TerminalNode* vhdlParser::Wait_statementContext::SEMI() {
  return getToken(vhdlParser::SEMI, 0);
}

vhdlParser::Label_colonContext* vhdlParser::Wait_statementContext::label_colon() {
  return getRuleContext<vhdlParser::Label_colonContext>(0);
}

vhdlParser::Sensitivity_clauseContext* vhdlParser::Wait_statementContext::sensitivity_clause() {
  return getRuleContext<vhdlParser::Sensitivity_clauseContext>(0);
}

vhdlParser::Condition_clauseContext* vhdlParser::Wait_statementContext::condition_clause() {
  return getRuleContext<vhdlParser::Condition_clauseContext>(0);
}

vhdlParser::Timeout_clauseContext* vhdlParser::Wait_statementContext::timeout_clause() {
  return getRuleContext<vhdlParser::Timeout_clauseContext>(0);
}


size_t vhdlParser::Wait_statementContext::getRuleIndex() const {
  return vhdlParser::RuleWait_statement;
}

antlrcpp::Any vhdlParser::Wait_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitWait_statement(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Wait_statementContext* vhdlParser::wait_statement() {
  Wait_statementContext *_localctx = _tracker.createInstance<Wait_statementContext>(_ctx, getState());
  enterRule(_localctx, 544, vhdlParser::RuleWait_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2824);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::BASIC_IDENTIFIER

    || _la == vhdlParser::EXTENDED_IDENTIFIER) {
      setState(2823);
      label_colon();
    }
    setState(2826);
    match(vhdlParser::WAIT);
    setState(2828);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::ON) {
      setState(2827);
      sensitivity_clause();
    }
    setState(2831);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::UNTIL) {
      setState(2830);
      condition_clause();
    }
    setState(2834);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::FOR) {
      setState(2833);
      timeout_clause();
    }
    setState(2836);
    match(vhdlParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WaveformContext ------------------------------------------------------------------

vhdlParser::WaveformContext::WaveformContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::Waveform_elementContext *> vhdlParser::WaveformContext::waveform_element() {
  return getRuleContexts<vhdlParser::Waveform_elementContext>();
}

vhdlParser::Waveform_elementContext* vhdlParser::WaveformContext::waveform_element(size_t i) {
  return getRuleContext<vhdlParser::Waveform_elementContext>(i);
}

std::vector<tree::TerminalNode *> vhdlParser::WaveformContext::COMMA() {
  return getTokens(vhdlParser::COMMA);
}

tree::TerminalNode* vhdlParser::WaveformContext::COMMA(size_t i) {
  return getToken(vhdlParser::COMMA, i);
}

tree::TerminalNode* vhdlParser::WaveformContext::UNAFFECTED() {
  return getToken(vhdlParser::UNAFFECTED, 0);
}


size_t vhdlParser::WaveformContext::getRuleIndex() const {
  return vhdlParser::RuleWaveform;
}

antlrcpp::Any vhdlParser::WaveformContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitWaveform(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::WaveformContext* vhdlParser::waveform() {
  WaveformContext *_localctx = _tracker.createInstance<WaveformContext>(_ctx, getState());
  enterRule(_localctx, 546, vhdlParser::RuleWaveform);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2847);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case vhdlParser::ABS:
      case vhdlParser::NEW:
      case vhdlParser::NOT:
      case vhdlParser::NULL_SYM:
      case vhdlParser::BASE_LITERAL:
      case vhdlParser::BIT_STRING_LITERAL:
      case vhdlParser::REAL_LITERAL:
      case vhdlParser::BASIC_IDENTIFIER:
      case vhdlParser::EXTENDED_IDENTIFIER:
      case vhdlParser::CHARACTER_LITERAL:
      case vhdlParser::STRING_LITERAL:
      case vhdlParser::LPAREN:
      case vhdlParser::PLUS:
      case vhdlParser::MINUS:
      case vhdlParser::CONDITION_OPERATOR:
      case vhdlParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(2838);
        waveform_element();
        setState(2843);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == vhdlParser::COMMA) {
          setState(2839);
          match(vhdlParser::COMMA);
          setState(2840);
          waveform_element();
          setState(2845);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case vhdlParser::UNAFFECTED: {
        enterOuterAlt(_localctx, 2);
        setState(2846);
        match(vhdlParser::UNAFFECTED);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Waveform_elementContext ------------------------------------------------------------------

vhdlParser::Waveform_elementContext::Waveform_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<vhdlParser::ExpressionContext *> vhdlParser::Waveform_elementContext::expression() {
  return getRuleContexts<vhdlParser::ExpressionContext>();
}

vhdlParser::ExpressionContext* vhdlParser::Waveform_elementContext::expression(size_t i) {
  return getRuleContext<vhdlParser::ExpressionContext>(i);
}

tree::TerminalNode* vhdlParser::Waveform_elementContext::AFTER() {
  return getToken(vhdlParser::AFTER, 0);
}


size_t vhdlParser::Waveform_elementContext::getRuleIndex() const {
  return vhdlParser::RuleWaveform_element;
}

antlrcpp::Any vhdlParser::Waveform_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<vhdlVisitor*>(visitor))
    return parserVisitor->visitWaveform_element(this);
  else
    return visitor->visitChildren(this);
}

vhdlParser::Waveform_elementContext* vhdlParser::waveform_element() {
  Waveform_elementContext *_localctx = _tracker.createInstance<Waveform_elementContext>(_ctx, getState());
  enterRule(_localctx, 548, vhdlParser::RuleWaveform_element);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2849);
    expression();
    setState(2852);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == vhdlParser::AFTER) {
      setState(2850);
      match(vhdlParser::AFTER);
      setState(2851);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> vhdlParser::_decisionToDFA;
atn::PredictionContextCache vhdlParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN vhdlParser::_atn;
std::vector<uint16_t> vhdlParser::_serializedATN;

std::vector<std::string> vhdlParser::_ruleNames = {
  "abstract_literal", "access_type_definition", "across_aspect", "actual_designator", 
  "actual_parameter_part", "actual_part", "adding_operator", "aggregate", 
  "alias_declaration", "alias_designator", "alias_indication", "allocator", 
  "architecture_body", "architecture_declarative_part", "architecture_statement", 
  "architecture_statement_part", "array_nature_definition", "array_type_definition", 
  "assertion", "assertion_statement", "association_element", "association_list", 
  "attribute_declaration", "attribute_designator", "attribute_specification", 
  "base_unit_declaration", "binding_indication", "block_configuration", 
  "block_declarative_item", "block_declarative_part", "block_header", "block_specification", 
  "block_statement", "block_statement_part", "branch_quantity_declaration", 
  "break_element", "break_list", "break_selector_clause", "break_statement", 
  "case_statement", "case_statement_alternative", "choice", "choices", "component_configuration", 
  "component_declaration", "component_instantiation_statement", "component_specification", 
  "composite_nature_definition", "composite_type_definition", "concurrent_assertion_statement", 
  "concurrent_break_statement", "concurrent_procedure_call_statement", "concurrent_signal_assignment_statement", 
  "concurrent_simple_signal_assignment", "concurrent_conditional_signal_assignment", 
  "concurrent_selected_signal_assignment", "condition", "condition_clause", 
  "conditional_signal_assignment", "conditional_waveform_assignment", "conditional_force_assignment", 
  "conditional_waveforms", "conditional_expression", "configuration_declaration", 
  "configuration_declarative_item", "configuration_declarative_part", "configuration_item", 
  "configuration_specification", "constant_declaration", "constrained_array_definition", 
  "constrained_nature_definition", "constraint", "context_clause", "context_item", 
  "delay_mechanism", "design_file", "design_unit", "designator", "direction", 
  "disconnection_specification", "discrete_range", "element_association", 
  "element_declaration", "element_subnature_definition", "element_subtype_definition", 
  "entity_aspect", "entity_class", "entity_class_entry", "entity_class_entry_list", 
  "entity_declaration", "entity_declarative_item", "entity_declarative_part", 
  "entity_designator", "entity_header", "entity_name_list", "entity_specification", 
  "entity_statement", "entity_statement_part", "entity_tag", "enumeration_literal", 
  "enumeration_type_definition", "exit_statement", "expression", "logical_expression", 
  "factor", "file_declaration", "file_logical_name", "file_open_information", 
  "file_type_definition", "formal_parameter_list", "formal_part", "free_quantity_declaration", 
  "generate_statement", "for_generate_statement", "if_generate_statement", 
  "case_generate_statement", "case_generate_alternative", "generate_statement_body", 
  "generation_scheme", "generic_clause", "generic_list", "generic_map_aspect", 
  "group_constituent", "group_constituent_list", "group_declaration", "group_template_declaration", 
  "guarded_signal_specification", "identifier", "identifier_list", "if_statement", 
  "index_constraint", "index_specification", "index_subtype_definition", 
  "instantiated_unit", "instantiation_list", "interface_constant_declaration", 
  "interface_declaration", "interface_element", "interface_file_declaration", 
  "interface_signal_list", "interface_port_list", "interface_list", "interface_quantity_declaration", 
  "interface_port_declaration", "interface_signal_declaration", "interface_terminal_declaration", 
  "interface_variable_declaration", "iteration_scheme", "label_colon", "library_clause", 
  "library_unit", "literal", "logical_name", "logical_name_list", "logical_operator", 
  "loop_statement", "signal_mode", "multiplying_operator", "name", "name_part", 
  "name_part_specificator", "name_attribute_part", "name_function_call_or_indexed_part", 
  "name_slice_part", "selected_name", "nature_declaration", "nature_definition", 
  "nature_element_declaration", "next_statement", "numeric_literal", "object_declaration", 
  "opts", "package_body", "package_body_declarative_item", "package_body_declarative_part", 
  "package_declaration", "package_declarative_item", "package_declarative_part", 
  "parameter_specification", "physical_literal", "physical_type_definition", 
  "port_clause", "port_list", "port_map_aspect", "primary", "primary_unit", 
  "procedural_declarative_item", "procedural_declarative_part", "procedural_statement_part", 
  "procedure_call", "procedure_call_statement", "process_declarative_item", 
  "process_declarative_part", "process_statement", "process_statement_part", 
  "qualified_expression", "quantity_declaration", "quantity_list", "quantity_specification", 
  "range", "explicit_range", "range_constraint", "record_nature_definition", 
  "record_type_definition", "relation", "relational_operator", "report_statement", 
  "return_statement", "scalar_nature_definition", "scalar_type_definition", 
  "secondary_unit", "secondary_unit_declaration", "selected_signal_assignment", 
  "selected_waveforms", "sensitivity_clause", "sensitivity_list", "sequence_of_statements", 
  "sequential_statement", "shift_expression", "shift_operator", "signal_assignment_statement", 
  "simple_signal_assignment", "simple_waveform_assignment", "simple_force_assignment", 
  "simple_release_assignment", "force_mode", "signal_declaration", "signal_kind", 
  "signal_list", "signature", "simple_expression", "simple_simultaneous_statement", 
  "simultaneous_alternative", "simultaneous_case_statement", "simultaneous_if_statement", 
  "simultaneous_procedural_statement", "simultaneous_statement", "simultaneous_statement_part", 
  "source_aspect", "source_quantity_declaration", "step_limit_specification", 
  "subnature_declaration", "subnature_indication", "subprogram_body", "subprogram_declaration", 
  "subprogram_declarative_item", "subprogram_declarative_part", "subprogram_kind", 
  "subprogram_specification", "procedure_specification", "function_specification", 
  "subprogram_statement_part", "subtype_declaration", "subtype_indication", 
  "suffix", "target", "term", "terminal_aspect", "terminal_declaration", 
  "through_aspect", "timeout_clause", "tolerance_aspect", "type_declaration", 
  "type_definition", "unconstrained_array_definition", "unconstrained_nature_definition", 
  "use_clause", "variable_assignment_statement", "simple_variable_assignment", 
  "conditional_variable_assignment", "selected_variable_assignment", "variable_declaration", 
  "wait_statement", "waveform", "waveform_element"
};

std::vector<std::string> vhdlParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "'\n'", "'\r'", "", "", "", "'**'", "'=='", "'<='", "'>='", 
  "'=>'", "'/='", "':='", "'<>'", "'\"'", "';'", "','", "'&'", "'('", "')'", 
  "'['", "']'", "':'", "'*'", "'/'", "'+'", "'-'", "'<'", "'>'", "'='", 
  "'|'", "'.'", "'\\'", "'?'", "", "", "", "", "", "", "", "'''"
};

std::vector<std::string> vhdlParser::_symbolicNames = {
  "", "ABS", "ACCESS", "ACROSS", "AFTER", "ALIAS", "ALL", "AND", "ARCHITECTURE", 
  "ARRAY", "ASSERT", "ATTRIBUTE", "BEGIN", "BLOCK", "BODY", "BREAK", "BUFFER", 
  "BUS", "CASE", "COMPONENT", "CONFIGURATION", "CONSTANT", "DISCONNECT", 
  "DOWNTO", "END", "ENTITY", "ELSE", "ELSIF", "EXIT", "FILE", "FOR", "FORCE", 
  "FUNCTION", "GENERATE", "GENERIC", "GROUP", "GUARDED", "IF", "IMPURE", 
  "IN", "INERTIAL", "INOUT", "IS", "LABEL", "LIBRARY", "LIMIT", "LINKAGE", 
  "LITERAL", "LOOP", "MAP", "MOD", "NAND", "NATURE", "NEW", "NEXT", "NOISE", 
  "NOR", "NOT", "NULL_SYM", "OF", "ON", "OPEN", "OR", "OTHERS", "OUT", "PACKAGE", 
  "PORT", "POSTPONED", "PROCESS", "PROCEDURE", "PROCEDURAL", "PURE", "QUANTITY", 
  "RANGE", "REVERSE_RANGE", "REJECT", "REM", "RECORD", "REFERENCE", "REGISTER", 
  "RELEASE", "REPORT", "RETURN", "ROL", "ROR", "SELECT", "SEVERITY", "SHARED", 
  "SIGNAL", "SLA", "SLL", "SPECTRUM", "SRA", "SRL", "SUBNATURE", "SUBTYPE", 
  "TERMINAL", "THEN", "THROUGH", "TO", "TOLERANCE", "TRANSPORT", "TYPE", 
  "UNAFFECTED", "UNITS", "UNTIL", "USE", "VARIABLE", "WAIT", "WITH", "WHEN", 
  "WHILE", "XNOR", "XOR", "BASE_LITERAL", "BIT_STRING_LITERAL", "BIT_STRING_LITERAL_BINARY", 
  "BIT_STRING_LITERAL_OCTAL", "BIT_STRING_LITERAL_HEX", "BIT_STRING_LITERAL_DEC", 
  "REAL_LITERAL", "BASIC_IDENTIFIER", "EXTENDED_IDENTIFIER", "LETTER", "LOWER_CASE_LETTER", 
  "UPPER_CASE_LETTER", "COMMENT", "TAB", "SPACE", "NEWLINE", "CR", "CHARACTER_LITERAL", 
  "STRING_LITERAL", "OTHER_SPECIAL_CHARACTER", "DOUBLESTAR", "ASSIGN", "LE", 
  "GE", "ARROW", "NEQ", "VARASGN", "BOX", "DBLQUOTE", "SEMI", "COMMA", "AMPERSAND", 
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "COLON", "MUL", "DIV", "PLUS", 
  "MINUS", "LOWERTHAN", "GREATERTHAN", "EQ", "BAR", "DOT", "BACKSLASH", 
  "TERNARY", "CONDITION_OPERATOR", "EXPONENT", "HEXDIGIT", "INTEGER", "DIGIT", 
  "BASED_INTEGER", "EXTENDED_DIGIT", "APOSTROPHE"
};

dfa::Vocabulary vhdlParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> vhdlParser::_tokenNames;

vhdlParser::Initializer::Initializer() {
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

  static uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0xab, 0xb29, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 
       0x9, 0x5c, 0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 
       0x9, 0x5f, 0x4, 0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 
       0x9, 0x62, 0x4, 0x63, 0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 
       0x9, 0x65, 0x4, 0x66, 0x9, 0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 
       0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 
       0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 0x6d, 0x9, 0x6d, 0x4, 0x6e, 
       0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x4, 0x70, 0x9, 0x70, 0x4, 0x71, 
       0x9, 0x71, 0x4, 0x72, 0x9, 0x72, 0x4, 0x73, 0x9, 0x73, 0x4, 0x74, 
       0x9, 0x74, 0x4, 0x75, 0x9, 0x75, 0x4, 0x76, 0x9, 0x76, 0x4, 0x77, 
       0x9, 0x77, 0x4, 0x78, 0x9, 0x78, 0x4, 0x79, 0x9, 0x79, 0x4, 0x7a, 
       0x9, 0x7a, 0x4, 0x7b, 0x9, 0x7b, 0x4, 0x7c, 0x9, 0x7c, 0x4, 0x7d, 
       0x9, 0x7d, 0x4, 0x7e, 0x9, 0x7e, 0x4, 0x7f, 0x9, 0x7f, 0x4, 0x80, 
       0x9, 0x80, 0x4, 0x81, 0x9, 0x81, 0x4, 0x82, 0x9, 0x82, 0x4, 0x83, 
       0x9, 0x83, 0x4, 0x84, 0x9, 0x84, 0x4, 0x85, 0x9, 0x85, 0x4, 0x86, 
       0x9, 0x86, 0x4, 0x87, 0x9, 0x87, 0x4, 0x88, 0x9, 0x88, 0x4, 0x89, 
       0x9, 0x89, 0x4, 0x8a, 0x9, 0x8a, 0x4, 0x8b, 0x9, 0x8b, 0x4, 0x8c, 
       0x9, 0x8c, 0x4, 0x8d, 0x9, 0x8d, 0x4, 0x8e, 0x9, 0x8e, 0x4, 0x8f, 
       0x9, 0x8f, 0x4, 0x90, 0x9, 0x90, 0x4, 0x91, 0x9, 0x91, 0x4, 0x92, 
       0x9, 0x92, 0x4, 0x93, 0x9, 0x93, 0x4, 0x94, 0x9, 0x94, 0x4, 0x95, 
       0x9, 0x95, 0x4, 0x96, 0x9, 0x96, 0x4, 0x97, 0x9, 0x97, 0x4, 0x98, 
       0x9, 0x98, 0x4, 0x99, 0x9, 0x99, 0x4, 0x9a, 0x9, 0x9a, 0x4, 0x9b, 
       0x9, 0x9b, 0x4, 0x9c, 0x9, 0x9c, 0x4, 0x9d, 0x9, 0x9d, 0x4, 0x9e, 
       0x9, 0x9e, 0x4, 0x9f, 0x9, 0x9f, 0x4, 0xa0, 0x9, 0xa0, 0x4, 0xa1, 
       0x9, 0xa1, 0x4, 0xa2, 0x9, 0xa2, 0x4, 0xa3, 0x9, 0xa3, 0x4, 0xa4, 
       0x9, 0xa4, 0x4, 0xa5, 0x9, 0xa5, 0x4, 0xa6, 0x9, 0xa6, 0x4, 0xa7, 
       0x9, 0xa7, 0x4, 0xa8, 0x9, 0xa8, 0x4, 0xa9, 0x9, 0xa9, 0x4, 0xaa, 
       0x9, 0xaa, 0x4, 0xab, 0x9, 0xab, 0x4, 0xac, 0x9, 0xac, 0x4, 0xad, 
       0x9, 0xad, 0x4, 0xae, 0x9, 0xae, 0x4, 0xaf, 0x9, 0xaf, 0x4, 0xb0, 
       0x9, 0xb0, 0x4, 0xb1, 0x9, 0xb1, 0x4, 0xb2, 0x9, 0xb2, 0x4, 0xb3, 
       0x9, 0xb3, 0x4, 0xb4, 0x9, 0xb4, 0x4, 0xb5, 0x9, 0xb5, 0x4, 0xb6, 
       0x9, 0xb6, 0x4, 0xb7, 0x9, 0xb7, 0x4, 0xb8, 0x9, 0xb8, 0x4, 0xb9, 
       0x9, 0xb9, 0x4, 0xba, 0x9, 0xba, 0x4, 0xbb, 0x9, 0xbb, 0x4, 0xbc, 
       0x9, 0xbc, 0x4, 0xbd, 0x9, 0xbd, 0x4, 0xbe, 0x9, 0xbe, 0x4, 0xbf, 
       0x9, 0xbf, 0x4, 0xc0, 0x9, 0xc0, 0x4, 0xc1, 0x9, 0xc1, 0x4, 0xc2, 
       0x9, 0xc2, 0x4, 0xc3, 0x9, 0xc3, 0x4, 0xc4, 0x9, 0xc4, 0x4, 0xc5, 
       0x9, 0xc5, 0x4, 0xc6, 0x9, 0xc6, 0x4, 0xc7, 0x9, 0xc7, 0x4, 0xc8, 
       0x9, 0xc8, 0x4, 0xc9, 0x9, 0xc9, 0x4, 0xca, 0x9, 0xca, 0x4, 0xcb, 
       0x9, 0xcb, 0x4, 0xcc, 0x9, 0xcc, 0x4, 0xcd, 0x9, 0xcd, 0x4, 0xce, 
       0x9, 0xce, 0x4, 0xcf, 0x9, 0xcf, 0x4, 0xd0, 0x9, 0xd0, 0x4, 0xd1, 
       0x9, 0xd1, 0x4, 0xd2, 0x9, 0xd2, 0x4, 0xd3, 0x9, 0xd3, 0x4, 0xd4, 
       0x9, 0xd4, 0x4, 0xd5, 0x9, 0xd5, 0x4, 0xd6, 0x9, 0xd6, 0x4, 0xd7, 
       0x9, 0xd7, 0x4, 0xd8, 0x9, 0xd8, 0x4, 0xd9, 0x9, 0xd9, 0x4, 0xda, 
       0x9, 0xda, 0x4, 0xdb, 0x9, 0xdb, 0x4, 0xdc, 0x9, 0xdc, 0x4, 0xdd, 
       0x9, 0xdd, 0x4, 0xde, 0x9, 0xde, 0x4, 0xdf, 0x9, 0xdf, 0x4, 0xe0, 
       0x9, 0xe0, 0x4, 0xe1, 0x9, 0xe1, 0x4, 0xe2, 0x9, 0xe2, 0x4, 0xe3, 
       0x9, 0xe3, 0x4, 0xe4, 0x9, 0xe4, 0x4, 0xe5, 0x9, 0xe5, 0x4, 0xe6, 
       0x9, 0xe6, 0x4, 0xe7, 0x9, 0xe7, 0x4, 0xe8, 0x9, 0xe8, 0x4, 0xe9, 
       0x9, 0xe9, 0x4, 0xea, 0x9, 0xea, 0x4, 0xeb, 0x9, 0xeb, 0x4, 0xec, 
       0x9, 0xec, 0x4, 0xed, 0x9, 0xed, 0x4, 0xee, 0x9, 0xee, 0x4, 0xef, 
       0x9, 0xef, 0x4, 0xf0, 0x9, 0xf0, 0x4, 0xf1, 0x9, 0xf1, 0x4, 0xf2, 
       0x9, 0xf2, 0x4, 0xf3, 0x9, 0xf3, 0x4, 0xf4, 0x9, 0xf4, 0x4, 0xf5, 
       0x9, 0xf5, 0x4, 0xf6, 0x9, 0xf6, 0x4, 0xf7, 0x9, 0xf7, 0x4, 0xf8, 
       0x9, 0xf8, 0x4, 0xf9, 0x9, 0xf9, 0x4, 0xfa, 0x9, 0xfa, 0x4, 0xfb, 
       0x9, 0xfb, 0x4, 0xfc, 0x9, 0xfc, 0x4, 0xfd, 0x9, 0xfd, 0x4, 0xfe, 
       0x9, 0xfe, 0x4, 0xff, 0x9, 0xff, 0x4, 0x100, 0x9, 0x100, 0x4, 0x101, 
       0x9, 0x101, 0x4, 0x102, 0x9, 0x102, 0x4, 0x103, 0x9, 0x103, 0x4, 
       0x104, 0x9, 0x104, 0x4, 0x105, 0x9, 0x105, 0x4, 0x106, 0x9, 0x106, 
       0x4, 0x107, 0x9, 0x107, 0x4, 0x108, 0x9, 0x108, 0x4, 0x109, 0x9, 
       0x109, 0x4, 0x10a, 0x9, 0x10a, 0x4, 0x10b, 0x9, 0x10b, 0x4, 0x10c, 
       0x9, 0x10c, 0x4, 0x10d, 0x9, 0x10d, 0x4, 0x10e, 0x9, 0x10e, 0x4, 
       0x10f, 0x9, 0x10f, 0x4, 0x110, 0x9, 0x110, 0x4, 0x111, 0x9, 0x111, 
       0x4, 0x112, 0x9, 0x112, 0x4, 0x113, 0x9, 0x113, 0x4, 0x114, 0x9, 
       0x114, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
       0x3, 0x4, 0x5, 0x4, 0x230, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
       0x234, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
       0x23a, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x244, 0xa, 0x7, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x24c, 
       0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x24f, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x257, 0xa, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x25c, 0xa, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x263, 0xa, 0xb, 
       0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x267, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x5, 0xd, 0x26c, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x5, 0xe, 0x278, 0xa, 0xe, 0x3, 0xe, 0x5, 0xe, 0x27b, 0xa, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x7, 0xf, 0x280, 0xa, 0xf, 0xc, 0xf, 
       0xe, 0xf, 0x283, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 
       0x10, 0x288, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x28c, 0xa, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x290, 0xa, 0x10, 0x3, 0x10, 
       0x5, 0x10, 0x293, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x5, 0x10, 0x29a, 0xa, 0x10, 0x3, 0x11, 0x7, 0x11, 
       0x29d, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x2a0, 0xb, 0x11, 0x3, 0x12, 
       0x3, 0x12, 0x5, 0x12, 0x2a4, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x5, 
       0x13, 0x2a8, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
       0x5, 0x14, 0x2ae, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x2b2, 
       0xa, 0x14, 0x3, 0x15, 0x5, 0x15, 0x2b5, 0xa, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x2bd, 
       0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x7, 0x17, 0x2c4, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x2c7, 0xb, 0x17, 
       0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x5, 0x19, 0x2d5, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 
       0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x2e4, 0xa, 0x1c, 
       0x3, 0x1c, 0x5, 0x1c, 0x2e7, 0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x2ea, 
       0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x2ef, 0xa, 
       0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x2f2, 0xb, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 
       0x2f5, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x2f8, 0xb, 0x1d, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x5, 0x1e, 0x314, 0xa, 0x1e, 0x3, 0x1f, 0x7, 0x1f, 0x317, 
       0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x31a, 0xb, 0x1f, 0x3, 0x20, 0x3, 
       0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x320, 0xa, 0x20, 0x5, 0x20, 
       0x322, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 
       0x20, 0x328, 0xa, 0x20, 0x5, 0x20, 0x32a, 0xa, 0x20, 0x3, 0x21, 0x3, 
       0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x331, 0xa, 0x21, 
       0x3, 0x21, 0x5, 0x21, 0x334, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 
       0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x33c, 0xa, 0x22, 
       0x3, 0x22, 0x5, 0x22, 0x33f, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
       0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x348, 
       0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x7, 0x23, 0x34d, 0xa, 
       0x23, 0xc, 0x23, 0xe, 0x23, 0x350, 0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 
       0x5, 0x24, 0x354, 0xa, 0x24, 0x3, 0x24, 0x5, 0x24, 0x357, 0xa, 0x24, 
       0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x5, 0x25, 0x35d, 0xa, 
       0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x7, 0x26, 0x366, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 
       0x369, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
       0x28, 0x5, 0x28, 0x370, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 
       0x374, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x378, 0xa, 0x28, 
       0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x5, 0x29, 0x37d, 0xa, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x6, 0x29, 0x383, 0xa, 0x29, 
       0xd, 0x29, 0xe, 0x29, 0x384, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 
       0x29, 0x38a, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
       0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
       0x3, 0x2b, 0x5, 0x2b, 0x397, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
       0x2c, 0x7, 0x2c, 0x39c, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x39f, 0xb, 
       0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 
       0x2d, 0x3a6, 0xa, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x3a9, 0xa, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x5, 0x2e, 0x3b2, 0xa, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x3b5, 0xa, 
       0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x3b8, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
       0x3, 0x2e, 0x5, 0x2e, 0x3bd, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x3c4, 0xa, 0x2f, 0x3, 0x2f, 
       0x5, 0x2f, 0x3c7, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 
       0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x3d1, 
       0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x3d5, 0xa, 0x32, 0x3, 
       0x33, 0x5, 0x33, 0x3d8, 0xa, 0x33, 0x3, 0x33, 0x5, 0x33, 0x3db, 0xa, 
       0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x5, 0x34, 0x3e1, 
       0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x3e5, 0xa, 0x34, 0x3, 
       0x34, 0x5, 0x34, 0x3e8, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 
       0x3ec, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x5, 0x35, 0x3f1, 
       0xa, 0x35, 0x3, 0x35, 0x5, 0x35, 0x3f4, 0xa, 0x35, 0x3, 0x35, 0x3, 
       0x35, 0x3, 0x35, 0x3, 0x36, 0x5, 0x36, 0x3fa, 0xa, 0x36, 0x3, 0x36, 
       0x5, 0x36, 0x3fd, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x401, 
       0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x404, 0xa, 0x36, 0x3, 0x36, 0x3, 
       0x36, 0x5, 0x36, 0x408, 0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x40b, 0xa, 
       0x36, 0x3, 0x36, 0x5, 0x36, 0x40e, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 
       0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 
       0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 
       0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x421, 0xa, 0x39, 0x3, 
       0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 
       0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x5, 
       0x3c, 0x42f, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 
       0x434, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 
       0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x43c, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
       0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
       0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 0x448, 0xa, 0x3f, 0xc, 0x3f, 0xe, 
       0x3f, 0x44b, 0xb, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x44f, 0xa, 
       0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
       0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x459, 0xa, 0x40, 0xc, 0x40, 
       0xe, 0x40, 0x45c, 0xb, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x460, 
       0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
       0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x46b, 0xa, 
       0x41, 0x3, 0x41, 0x5, 0x41, 0x46e, 0xa, 0x41, 0x3, 0x41, 0x3, 0x41, 
       0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x475, 0xa, 0x42, 0x3, 
       0x43, 0x7, 0x43, 0x478, 0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x47b, 0xb, 
       0x43, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x47f, 0xa, 0x44, 0x3, 0x45, 
       0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 
       0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x48c, 0xa, 
       0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 
       0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
       0x48, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x49c, 0xa, 0x49, 0x3, 0x4a, 
       0x7, 0x4a, 0x49f, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 0x4a2, 0xb, 0x4a, 
       0x3, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x4a6, 0xa, 0x4b, 0x3, 0x4c, 0x3, 
       0x4c, 0x3, 0x4c, 0x5, 0x4c, 0x4ab, 0xa, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 
       0x4ae, 0xa, 0x4c, 0x3, 0x4d, 0x7, 0x4d, 0x4b1, 0xa, 0x4d, 0xc, 0x4d, 
       0xe, 0x4d, 0x4b4, 0xb, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 
       0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x4bd, 0xa, 0x4f, 
       0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 
       0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 0x4c9, 0xa, 
       0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 0x4ce, 0xa, 0x53, 
       0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 
       0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 
       0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x5, 0x57, 
       0x4e1, 0xa, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x5, 0x57, 0x4e6, 
       0xa, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 
       0x4ec, 0xa, 0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x7, 0x5a, 0x4f1, 
       0xa, 0x5a, 0xc, 0x5a, 0xe, 0x5a, 0x4f4, 0xb, 0x5a, 0x3, 0x5b, 0x3, 
       0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x5, 
       0x5b, 0x4fd, 0xa, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x501, 0xa, 
       0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x504, 0xa, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 
       0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 
       0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 
       0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 
       0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x51c, 0xa, 0x5c, 0x3, 0x5d, 0x7, 
       0x5d, 0x51f, 0xa, 0x5d, 0xc, 0x5d, 0xe, 0x5d, 0x522, 0xb, 0x5d, 0x3, 
       0x5e, 0x3, 0x5e, 0x5, 0x5e, 0x526, 0xa, 0x5e, 0x3, 0x5f, 0x5, 0x5f, 
       0x529, 0xa, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x52c, 0xa, 0x5f, 0x3, 0x60, 
       0x3, 0x60, 0x3, 0x60, 0x7, 0x60, 0x531, 0xa, 0x60, 0xc, 0x60, 0xe, 
       0x60, 0x534, 0xb, 0x60, 0x3, 0x60, 0x3, 0x60, 0x5, 0x60, 0x538, 0xa, 
       0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x62, 0x3, 
       0x62, 0x3, 0x62, 0x5, 0x62, 0x541, 0xa, 0x62, 0x3, 0x63, 0x7, 0x63, 
       0x544, 0xa, 0x63, 0xc, 0x63, 0xe, 0x63, 0x547, 0xb, 0x63, 0x3, 0x64, 
       0x3, 0x64, 0x3, 0x64, 0x5, 0x64, 0x54c, 0xa, 0x64, 0x3, 0x65, 0x3, 
       0x65, 0x5, 0x65, 0x550, 0xa, 0x65, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 
       0x3, 0x66, 0x7, 0x66, 0x556, 0xa, 0x66, 0xc, 0x66, 0xe, 0x66, 0x559, 
       0xb, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x67, 0x5, 0x67, 0x55e, 0xa, 
       0x67, 0x3, 0x67, 0x3, 0x67, 0x5, 0x67, 0x562, 0xa, 0x67, 0x3, 0x67, 
       0x3, 0x67, 0x5, 0x67, 0x566, 0xa, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 
       0x68, 0x3, 0x68, 0x3, 0x68, 0x5, 0x68, 0x56d, 0xa, 0x68, 0x3, 0x69, 
       0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x7, 0x69, 0x573, 0xa, 0x69, 0xc, 
       0x69, 0xe, 0x69, 0x576, 0xb, 0x69, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 
       0x5, 0x6a, 0x57b, 0xa, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x3, 
       0x6a, 0x5, 0x6a, 0x581, 0xa, 0x6a, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 
       0x3, 0x6b, 0x3, 0x6b, 0x5, 0x6b, 0x588, 0xa, 0x6b, 0x3, 0x6b, 0x3, 
       0x6b, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6d, 0x3, 0x6d, 0x5, 0x6d, 0x590, 
       0xa, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6e, 0x3, 0x6e, 
       0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x70, 0x3, 0x70, 
       0x3, 0x70, 0x3, 0x70, 0x3, 0x70, 0x5, 0x70, 0x5a0, 0xa, 0x70, 0x3, 
       0x70, 0x3, 0x70, 0x5, 0x70, 0x5a4, 0xa, 0x70, 0x3, 0x71, 0x3, 0x71, 
       0x3, 0x71, 0x3, 0x71, 0x3, 0x71, 0x3, 0x71, 0x5, 0x71, 0x5ac, 0xa, 
       0x71, 0x3, 0x71, 0x3, 0x71, 0x3, 0x72, 0x3, 0x72, 0x3, 0x72, 0x5, 
       0x72, 0x5b3, 0xa, 0x72, 0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 
       0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 0x5, 0x73, 0x5bd, 0xa, 
       0x73, 0x3, 0x73, 0x3, 0x73, 0x3, 0x74, 0x5, 0x74, 0x5c2, 0xa, 0x74, 
       0x3, 0x74, 0x3, 0x74, 0x3, 0x74, 0x3, 0x74, 0x3, 0x74, 0x3, 0x74, 
       0x3, 0x74, 0x3, 0x74, 0x3, 0x74, 0x7, 0x74, 0x5cd, 0xa, 0x74, 0xc, 
       0x74, 0xe, 0x74, 0x5d0, 0xb, 0x74, 0x3, 0x74, 0x3, 0x74, 0x3, 0x74, 
       0x5, 0x74, 0x5d5, 0xa, 0x74, 0x3, 0x74, 0x3, 0x74, 0x3, 0x74, 0x5, 
       0x74, 0x5da, 0xa, 0x74, 0x3, 0x74, 0x3, 0x74, 0x3, 0x75, 0x5, 0x75, 
       0x5df, 0xa, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x6, 
       0x75, 0x5e5, 0xa, 0x75, 0xd, 0x75, 0xe, 0x75, 0x5e6, 0x3, 0x75, 0x3, 
       0x75, 0x3, 0x75, 0x5, 0x75, 0x5ec, 0xa, 0x75, 0x3, 0x75, 0x3, 0x75, 
       0x3, 0x76, 0x3, 0x76, 0x3, 0x76, 0x3, 0x76, 0x3, 0x76, 0x3, 0x77, 
       0x7, 0x77, 0x5f6, 0xa, 0x77, 0xc, 0x77, 0xe, 0x77, 0x5f9, 0xb, 0x77, 
       0x3, 0x77, 0x5, 0x77, 0x5fc, 0xa, 0x77, 0x3, 0x77, 0x7, 0x77, 0x5ff, 
       0xa, 0x77, 0xc, 0x77, 0xe, 0x77, 0x602, 0xb, 0x77, 0x3, 0x78, 0x3, 
       0x78, 0x3, 0x78, 0x3, 0x78, 0x3, 0x78, 0x3, 0x78, 0x5, 0x78, 0x60a, 
       0xa, 0x78, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 
       0x3, 0x79, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x7, 0x7a, 0x615, 0xa, 
       0x7a, 0xc, 0x7a, 0xe, 0x7a, 0x618, 0xb, 0x7a, 0x3, 0x7b, 0x3, 0x7b, 
       0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7c, 0x3, 0x7c, 
       0x5, 0x7c, 0x622, 0xa, 0x7c, 0x3, 0x7d, 0x3, 0x7d, 0x3, 0x7d, 0x7, 
       0x7d, 0x627, 0xa, 0x7d, 0xc, 0x7d, 0xe, 0x7d, 0x62a, 0xb, 0x7d, 0x3, 
       0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 
       0x7e, 0x3, 0x7e, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 
       0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x80, 0x3, 0x80, 0x3, 
       0x80, 0x3, 0x80, 0x3, 0x81, 0x3, 0x81, 0x3, 0x82, 0x3, 0x82, 0x3, 
       0x82, 0x7, 0x82, 0x645, 0xa, 0x82, 0xc, 0x82, 0xe, 0x82, 0x648, 0xb, 
       0x82, 0x3, 0x83, 0x5, 0x83, 0x64b, 0xa, 0x83, 0x3, 0x83, 0x3, 0x83, 
       0x3, 0x83, 0x3, 0x83, 0x3, 0x83, 0x3, 0x83, 0x3, 0x83, 0x3, 0x83, 
       0x3, 0x83, 0x7, 0x83, 0x656, 0xa, 0x83, 0xc, 0x83, 0xe, 0x83, 0x659, 
       0xb, 0x83, 0x3, 0x83, 0x3, 0x83, 0x5, 0x83, 0x65d, 0xa, 0x83, 0x3, 
       0x83, 0x3, 0x83, 0x3, 0x83, 0x5, 0x83, 0x662, 0xa, 0x83, 0x3, 0x83, 
       0x3, 0x83, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x7, 0x84, 
       0x66a, 0xa, 0x84, 0xc, 0x84, 0xe, 0x84, 0x66d, 0xb, 0x84, 0x3, 0x84, 
       0x3, 0x84, 0x3, 0x85, 0x3, 0x85, 0x5, 0x85, 0x673, 0xa, 0x85, 0x3, 
       0x86, 0x3, 0x86, 0x3, 0x86, 0x3, 0x86, 0x3, 0x87, 0x5, 0x87, 0x67a, 
       0xa, 0x87, 0x3, 0x87, 0x3, 0x87, 0x3, 0x87, 0x3, 0x87, 0x3, 0x87, 
       0x3, 0x87, 0x3, 0x87, 0x5, 0x87, 0x683, 0xa, 0x87, 0x3, 0x87, 0x3, 
       0x87, 0x5, 0x87, 0x687, 0xa, 0x87, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 
       0x7, 0x88, 0x68c, 0xa, 0x88, 0xc, 0x88, 0xe, 0x88, 0x68f, 0xb, 0x88, 
       0x3, 0x88, 0x3, 0x88, 0x5, 0x88, 0x693, 0xa, 0x88, 0x3, 0x89, 0x5, 
       0x89, 0x696, 0xa, 0x89, 0x3, 0x89, 0x3, 0x89, 0x3, 0x89, 0x5, 0x89, 
       0x69b, 0xa, 0x89, 0x3, 0x89, 0x3, 0x89, 0x3, 0x89, 0x5, 0x89, 0x6a0, 
       0xa, 0x89, 0x3, 0x8a, 0x3, 0x8a, 0x3, 0x8a, 0x3, 0x8a, 0x3, 0x8a, 
       0x3, 0x8a, 0x5, 0x8a, 0x6a8, 0xa, 0x8a, 0x3, 0x8b, 0x3, 0x8b, 0x3, 
       0x8c, 0x3, 0x8c, 0x3, 0x8c, 0x3, 0x8c, 0x3, 0x8c, 0x3, 0x8d, 0x3, 
       0x8d, 0x3, 0x8d, 0x7, 0x8d, 0x6b4, 0xa, 0x8d, 0xc, 0x8d, 0xe, 0x8d, 
       0x6b7, 0xb, 0x8d, 0x3, 0x8e, 0x3, 0x8e, 0x3, 0x8e, 0x7, 0x8e, 0x6bc, 
       0xa, 0x8e, 0xc, 0x8e, 0xe, 0x8e, 0x6bf, 0xb, 0x8e, 0x3, 0x8f, 0x3, 
       0x8f, 0x3, 0x8f, 0x7, 0x8f, 0x6c4, 0xa, 0x8f, 0xc, 0x8f, 0xe, 0x8f, 
       0x6c7, 0xb, 0x8f, 0x3, 0x90, 0x3, 0x90, 0x3, 0x90, 0x3, 0x90, 0x5, 
       0x90, 0x6cd, 0xa, 0x90, 0x3, 0x90, 0x3, 0x90, 0x3, 0x90, 0x5, 0x90, 
       0x6d2, 0xa, 0x90, 0x3, 0x91, 0x3, 0x91, 0x3, 0x91, 0x3, 0x91, 0x3, 
       0x91, 0x5, 0x91, 0x6d9, 0xa, 0x91, 0x3, 0x91, 0x3, 0x91, 0x5, 0x91, 
       0x6dd, 0xa, 0x91, 0x3, 0x92, 0x3, 0x92, 0x3, 0x92, 0x3, 0x92, 0x5, 
       0x92, 0x6e3, 0xa, 0x92, 0x3, 0x92, 0x3, 0x92, 0x5, 0x92, 0x6e7, 0xa, 
       0x92, 0x3, 0x92, 0x3, 0x92, 0x5, 0x92, 0x6eb, 0xa, 0x92, 0x3, 0x93, 
       0x3, 0x93, 0x3, 0x93, 0x3, 0x93, 0x3, 0x93, 0x3, 0x94, 0x5, 0x94, 
       0x6f3, 0xa, 0x94, 0x3, 0x94, 0x3, 0x94, 0x3, 0x94, 0x5, 0x94, 0x6f8, 
       0xa, 0x94, 0x3, 0x94, 0x3, 0x94, 0x3, 0x94, 0x5, 0x94, 0x6fd, 0xa, 
       0x94, 0x3, 0x95, 0x3, 0x95, 0x3, 0x95, 0x3, 0x95, 0x5, 0x95, 0x703, 
       0xa, 0x95, 0x3, 0x96, 0x3, 0x96, 0x3, 0x96, 0x3, 0x97, 0x3, 0x97, 
       0x3, 0x97, 0x3, 0x97, 0x3, 0x98, 0x3, 0x98, 0x5, 0x98, 0x70e, 0xa, 
       0x98, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x5, 
       0x99, 0x715, 0xa, 0x99, 0x3, 0x9a, 0x3, 0x9a, 0x3, 0x9b, 0x3, 0x9b, 
       0x3, 0x9b, 0x7, 0x9b, 0x71c, 0xa, 0x9b, 0xc, 0x9b, 0xe, 0x9b, 0x71f, 
       0xb, 0x9b, 0x3, 0x9c, 0x3, 0x9c, 0x3, 0x9d, 0x5, 0x9d, 0x724, 0xa, 
       0x9d, 0x3, 0x9d, 0x5, 0x9d, 0x727, 0xa, 0x9d, 0x3, 0x9d, 0x3, 0x9d, 
       0x3, 0x9d, 0x3, 0x9d, 0x3, 0x9d, 0x5, 0x9d, 0x72e, 0xa, 0x9d, 0x3, 
       0x9d, 0x3, 0x9d, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9f, 0x3, 0x9f, 0x3, 
       0xa0, 0x3, 0xa0, 0x3, 0xa0, 0x3, 0xa0, 0x7, 0xa0, 0x73a, 0xa, 0xa0, 
       0xc, 0xa0, 0xe, 0xa0, 0x73d, 0xb, 0xa0, 0x5, 0xa0, 0x73f, 0xa, 0xa0, 
       0x3, 0xa1, 0x3, 0xa1, 0x7, 0xa1, 0x743, 0xa, 0xa1, 0xc, 0xa1, 0xe, 
       0xa1, 0x746, 0xb, 0xa1, 0x3, 0xa2, 0x3, 0xa2, 0x3, 0xa2, 0x5, 0xa2, 
       0x74b, 0xa, 0xa2, 0x3, 0xa3, 0x3, 0xa3, 0x3, 0xa3, 0x3, 0xa3, 0x3, 
       0xa3, 0x7, 0xa3, 0x752, 0xa, 0xa3, 0xc, 0xa3, 0xe, 0xa3, 0x755, 0xb, 
       0xa3, 0x5, 0xa3, 0x757, 0xa, 0xa3, 0x3, 0xa4, 0x3, 0xa4, 0x5, 0xa4, 
       0x75b, 0xa, 0xa4, 0x3, 0xa4, 0x3, 0xa4, 0x3, 0xa5, 0x3, 0xa5, 0x3, 
       0xa5, 0x3, 0xa5, 0x7, 0xa5, 0x763, 0xa, 0xa5, 0xc, 0xa5, 0xe, 0xa5, 
       0x766, 0xb, 0xa5, 0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa6, 0x3, 0xa6, 0x3, 
       0xa6, 0x7, 0xa6, 0x76d, 0xa, 0xa6, 0xc, 0xa6, 0xe, 0xa6, 0x770, 0xb, 
       0xa6, 0x3, 0xa7, 0x3, 0xa7, 0x3, 0xa7, 0x3, 0xa7, 0x3, 0xa7, 0x3, 
       0xa7, 0x3, 0xa8, 0x3, 0xa8, 0x5, 0xa8, 0x77a, 0xa, 0xa8, 0x3, 0xa9, 
       0x3, 0xa9, 0x3, 0xa9, 0x3, 0xa9, 0x3, 0xaa, 0x5, 0xaa, 0x781, 0xa, 
       0xaa, 0x3, 0xaa, 0x3, 0xaa, 0x5, 0xaa, 0x785, 0xa, 0xaa, 0x3, 0xaa, 
       0x3, 0xaa, 0x5, 0xaa, 0x789, 0xa, 0xaa, 0x3, 0xaa, 0x3, 0xaa, 0x3, 
       0xab, 0x3, 0xab, 0x5, 0xab, 0x78f, 0xa, 0xab, 0x3, 0xac, 0x3, 0xac, 
       0x3, 0xac, 0x3, 0xac, 0x3, 0xac, 0x3, 0xac, 0x5, 0xac, 0x797, 0xa, 
       0xac, 0x3, 0xad, 0x5, 0xad, 0x79a, 0xa, 0xad, 0x3, 0xad, 0x5, 0xad, 
       0x79d, 0xa, 0xad, 0x3, 0xae, 0x3, 0xae, 0x3, 0xae, 0x3, 0xae, 0x3, 
       0xae, 0x3, 0xae, 0x3, 0xae, 0x3, 0xae, 0x5, 0xae, 0x7a7, 0xa, 0xae, 
       0x3, 0xae, 0x5, 0xae, 0x7aa, 0xa, 0xae, 0x3, 0xae, 0x3, 0xae, 0x3, 
       0xaf, 0x3, 0xaf, 0x3, 0xaf, 0x3, 0xaf, 0x3, 0xaf, 0x3, 0xaf, 0x3, 
       0xaf, 0x3, 0xaf, 0x3, 0xaf, 0x3, 0xaf, 0x3, 0xaf, 0x5, 0xaf, 0x7b9, 
       0xa, 0xaf, 0x3, 0xb0, 0x7, 0xb0, 0x7bc, 0xa, 0xb0, 0xc, 0xb0, 0xe, 
       0xb0, 0x7bf, 0xb, 0xb0, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 
       0x3, 0xb1, 0x3, 0xb1, 0x5, 0xb1, 0x7c7, 0xa, 0xb1, 0x3, 0xb1, 0x5, 
       0xb1, 0x7ca, 0xa, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb2, 0x3, 0xb2, 
       0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 
       0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 
       0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x5, 0xb2, 0x7e0, 0xa, 
       0xb2, 0x3, 0xb3, 0x7, 0xb3, 0x7e3, 0xa, 0xb3, 0xc, 0xb3, 0xe, 0xb3, 
       0x7e6, 0xb, 0xb3, 0x3, 0xb4, 0x3, 0xb4, 0x3, 0xb4, 0x3, 0xb4, 0x3, 
       0xb5, 0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x3, 
       0xb6, 0x7, 0xb6, 0x7f3, 0xa, 0xb6, 0xc, 0xb6, 0xe, 0xb6, 0x7f6, 0xb, 
       0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x5, 0xb6, 0x7fb, 0xa, 0xb6, 
       0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb7, 
       0x3, 0xb8, 0x3, 0xb8, 0x3, 0xb9, 0x3, 0xb9, 0x3, 0xb9, 0x3, 0xb9, 
       0x3, 0xb9, 0x3, 0xb9, 0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 
       0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x5, 0xba, 
       0x814, 0xa, 0xba, 0x3, 0xbb, 0x3, 0xbb, 0x3, 0xbb, 0x5, 0xbb, 0x819, 
       0xa, 0xbb, 0x3, 0xbc, 0x3, 0xbc, 0x3, 0xbc, 0x3, 0xbc, 0x3, 0xbc, 
       0x3, 0xbc, 0x3, 0xbc, 0x3, 0xbc, 0x3, 0xbc, 0x3, 0xbc, 0x3, 0xbc, 
       0x3, 0xbc, 0x5, 0xbc, 0x827, 0xa, 0xbc, 0x3, 0xbd, 0x7, 0xbd, 0x82a, 
       0xa, 0xbd, 0xc, 0xbd, 0xe, 0xbd, 0x82d, 0xb, 0xbd, 0x3, 0xbe, 0x7, 
       0xbe, 0x830, 0xa, 0xbe, 0xc, 0xbe, 0xe, 0xbe, 0x833, 0xb, 0xbe, 0x3, 
       0xbf, 0x3, 0xbf, 0x3, 0xbf, 0x3, 0xbf, 0x3, 0xbf, 0x5, 0xbf, 0x83a, 
       0xa, 0xbf, 0x3, 0xc0, 0x5, 0xc0, 0x83d, 0xa, 0xc0, 0x3, 0xc0, 0x3, 
       0xc0, 0x3, 0xc0, 0x3, 0xc1, 0x3, 0xc1, 0x3, 0xc1, 0x3, 0xc1, 0x3, 
       0xc1, 0x3, 0xc1, 0x3, 0xc1, 0x3, 0xc1, 0x3, 0xc1, 0x3, 0xc1, 0x3, 
       0xc1, 0x3, 0xc1, 0x3, 0xc1, 0x5, 0xc1, 0x84f, 0xa, 0xc1, 0x3, 0xc2, 
       0x7, 0xc2, 0x852, 0xa, 0xc2, 0xc, 0xc2, 0xe, 0xc2, 0x855, 0xb, 0xc2, 
       0x3, 0xc3, 0x5, 0xc3, 0x858, 0xa, 0xc3, 0x3, 0xc3, 0x5, 0xc3, 0x85b, 
       0xa, 0xc3, 0x3, 0xc3, 0x3, 0xc3, 0x3, 0xc3, 0x3, 0xc3, 0x3, 0xc3, 
       0x5, 0xc3, 0x862, 0xa, 0xc3, 0x3, 0xc3, 0x5, 0xc3, 0x865, 0xa, 0xc3, 
       0x3, 0xc3, 0x3, 0xc3, 0x3, 0xc3, 0x3, 0xc3, 0x3, 0xc3, 0x5, 0xc3, 
       0x86c, 0xa, 0xc3, 0x3, 0xc3, 0x3, 0xc3, 0x5, 0xc3, 0x870, 0xa, 0xc3, 
       0x3, 0xc3, 0x3, 0xc3, 0x3, 0xc4, 0x7, 0xc4, 0x875, 0xa, 0xc4, 0xc, 
       0xc4, 0xe, 0xc4, 0x878, 0xb, 0xc4, 0x3, 0xc5, 0x3, 0xc5, 0x3, 0xc5, 
       0x3, 0xc5, 0x3, 0xc5, 0x3, 0xc5, 0x3, 0xc5, 0x5, 0xc5, 0x881, 0xa, 
       0xc5, 0x3, 0xc6, 0x3, 0xc6, 0x3, 0xc6, 0x5, 0xc6, 0x886, 0xa, 0xc6, 
       0x3, 0xc7, 0x3, 0xc7, 0x3, 0xc7, 0x7, 0xc7, 0x88b, 0xa, 0xc7, 0xc, 
       0xc7, 0xe, 0xc7, 0x88e, 0xb, 0xc7, 0x3, 0xc7, 0x3, 0xc7, 0x5, 0xc7, 
       0x892, 0xa, 0xc7, 0x3, 0xc8, 0x3, 0xc8, 0x3, 0xc8, 0x3, 0xc8, 0x3, 
       0xc9, 0x3, 0xc9, 0x5, 0xc9, 0x89a, 0xa, 0xc9, 0x3, 0xca, 0x3, 0xca, 
       0x3, 0xca, 0x3, 0xca, 0x3, 0xcb, 0x3, 0xcb, 0x3, 0xcb, 0x3, 0xcc, 
       0x3, 0xcc, 0x6, 0xcc, 0x8a5, 0xa, 0xcc, 0xd, 0xcc, 0xe, 0xcc, 0x8a6, 
       0x3, 0xcc, 0x3, 0xcc, 0x3, 0xcc, 0x5, 0xcc, 0x8ac, 0xa, 0xcc, 0x3, 
       0xcd, 0x3, 0xcd, 0x6, 0xcd, 0x8b0, 0xa, 0xcd, 0xd, 0xcd, 0xe, 0xcd, 
       0x8b1, 0x3, 0xcd, 0x3, 0xcd, 0x3, 0xcd, 0x5, 0xcd, 0x8b7, 0xa, 0xcd, 
       0x3, 0xce, 0x3, 0xce, 0x3, 0xce, 0x3, 0xce, 0x5, 0xce, 0x8bd, 0xa, 
       0xce, 0x3, 0xcf, 0x3, 0xcf, 0x3, 0xd0, 0x5, 0xd0, 0x8c2, 0xa, 0xd0, 
       0x3, 0xd0, 0x3, 0xd0, 0x3, 0xd0, 0x3, 0xd0, 0x5, 0xd0, 0x8c8, 0xa, 
       0xd0, 0x3, 0xd0, 0x3, 0xd0, 0x3, 0xd1, 0x5, 0xd1, 0x8cd, 0xa, 0xd1, 
       0x3, 0xd1, 0x3, 0xd1, 0x5, 0xd1, 0x8d1, 0xa, 0xd1, 0x3, 0xd1, 0x3, 
       0xd1, 0x3, 0xd2, 0x3, 0xd2, 0x3, 0xd2, 0x3, 0xd2, 0x3, 0xd2, 0x3, 
       0xd2, 0x3, 0xd2, 0x3, 0xd3, 0x3, 0xd3, 0x3, 0xd3, 0x5, 0xd3, 0x8df, 
       0xa, 0xd3, 0x3, 0xd4, 0x3, 0xd4, 0x5, 0xd4, 0x8e3, 0xa, 0xd4, 0x3, 
       0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x3, 0xd5, 0x3, 0xd6, 0x3, 
       0xd6, 0x3, 0xd6, 0x3, 0xd6, 0x5, 0xd6, 0x8ee, 0xa, 0xd6, 0x3, 0xd6, 
       0x3, 0xd6, 0x3, 0xd6, 0x3, 0xd6, 0x3, 0xd6, 0x3, 0xd6, 0x3, 0xd7, 
       0x3, 0xd7, 0x3, 0xd7, 0x3, 0xd7, 0x3, 0xd7, 0x3, 0xd7, 0x3, 0xd7, 
       0x3, 0xd7, 0x7, 0xd7, 0x8fe, 0xa, 0xd7, 0xc, 0xd7, 0xe, 0xd7, 0x901, 
       0xb, 0xd7, 0x3, 0xd8, 0x3, 0xd8, 0x3, 0xd8, 0x3, 0xd9, 0x3, 0xd9, 
       0x3, 0xd9, 0x7, 0xd9, 0x909, 0xa, 0xd9, 0xc, 0xd9, 0xe, 0xd9, 0x90c, 
       0xb, 0xd9, 0x3, 0xd9, 0x5, 0xd9, 0x90f, 0xa, 0xd9, 0x3, 0xda, 0x7, 
       0xda, 0x912, 0xa, 0xda, 0xc, 0xda, 0xe, 0xda, 0x915, 0xb, 0xda, 0x3, 
       0xdb, 0x3, 0xdb, 0x3, 0xdb, 0x3, 0xdb, 0x3, 0xdb, 0x3, 0xdb, 0x3, 
       0xdb, 0x3, 0xdb, 0x3, 0xdb, 0x3, 0xdb, 0x3, 0xdb, 0x3, 0xdb, 0x5, 
       0xdb, 0x923, 0xa, 0xdb, 0x3, 0xdb, 0x3, 0xdb, 0x3, 0xdb, 0x3, 0xdb, 
       0x5, 0xdb, 0x929, 0xa, 0xdb, 0x3, 0xdc, 0x3, 0xdc, 0x3, 0xdc, 0x3, 
       0xdc, 0x5, 0xdc, 0x92f, 0xa, 0xdc, 0x3, 0xdd, 0x3, 0xdd, 0x3, 0xde, 
       0x5, 0xde, 0x934, 0xa, 0xde, 0x3, 0xde, 0x3, 0xde, 0x5, 0xde, 0x938, 
       0xa, 0xde, 0x3, 0xde, 0x3, 0xde, 0x5, 0xde, 0x93c, 0xa, 0xde, 0x3, 
       0xde, 0x5, 0xde, 0x93f, 0xa, 0xde, 0x3, 0xdf, 0x3, 0xdf, 0x3, 0xdf, 
       0x5, 0xdf, 0x944, 0xa, 0xdf, 0x3, 0xe0, 0x3, 0xe0, 0x3, 0xe0, 0x5, 
       0xe0, 0x949, 0xa, 0xe0, 0x3, 0xe0, 0x3, 0xe0, 0x3, 0xe0, 0x3, 0xe1, 
       0x3, 0xe1, 0x3, 0xe1, 0x3, 0xe1, 0x5, 0xe1, 0x952, 0xa, 0xe1, 0x3, 
       0xe1, 0x3, 0xe1, 0x3, 0xe1, 0x3, 0xe2, 0x3, 0xe2, 0x3, 0xe2, 0x3, 
       0xe2, 0x5, 0xe2, 0x95b, 0xa, 0xe2, 0x3, 0xe2, 0x3, 0xe2, 0x3, 0xe3, 
       0x3, 0xe3, 0x3, 0xe4, 0x3, 0xe4, 0x3, 0xe4, 0x3, 0xe4, 0x3, 0xe4, 
       0x5, 0xe4, 0x966, 0xa, 0xe4, 0x3, 0xe4, 0x3, 0xe4, 0x5, 0xe4, 0x96a, 
       0xa, 0xe4, 0x3, 0xe4, 0x3, 0xe4, 0x3, 0xe5, 0x3, 0xe5, 0x3, 0xe6, 
       0x3, 0xe6, 0x3, 0xe6, 0x7, 0xe6, 0x973, 0xa, 0xe6, 0xc, 0xe6, 0xe, 
       0xe6, 0x976, 0xb, 0xe6, 0x3, 0xe6, 0x3, 0xe6, 0x5, 0xe6, 0x97a, 0xa, 
       0xe6, 0x3, 0xe7, 0x3, 0xe7, 0x3, 0xe7, 0x3, 0xe7, 0x7, 0xe7, 0x980, 
       0xa, 0xe7, 0xc, 0xe7, 0xe, 0xe7, 0x983, 0xb, 0xe7, 0x5, 0xe7, 0x985, 
       0xa, 0xe7, 0x3, 0xe7, 0x3, 0xe7, 0x5, 0xe7, 0x989, 0xa, 0xe7, 0x3, 
       0xe7, 0x3, 0xe7, 0x3, 0xe8, 0x5, 0xe8, 0x98e, 0xa, 0xe8, 0x3, 0xe8, 
       0x3, 0xe8, 0x3, 0xe8, 0x3, 0xe8, 0x7, 0xe8, 0x994, 0xa, 0xe8, 0xc, 
       0xe8, 0xe, 0xe8, 0x997, 0xb, 0xe8, 0x3, 0xe9, 0x5, 0xe9, 0x99a, 0xa, 
       0xe9, 0x3, 0xe9, 0x3, 0xe9, 0x3, 0xe9, 0x3, 0xe9, 0x5, 0xe9, 0x9a0, 
       0xa, 0xe9, 0x3, 0xe9, 0x3, 0xe9, 0x3, 0xea, 0x3, 0xea, 0x3, 0xea, 
       0x3, 0xea, 0x3, 0xea, 0x3, 0xeb, 0x5, 0xeb, 0x9aa, 0xa, 0xeb, 0x3, 
       0xeb, 0x3, 0xeb, 0x3, 0xeb, 0x3, 0xeb, 0x6, 0xeb, 0x9b0, 0xa, 0xeb, 
       0xd, 0xeb, 0xe, 0xeb, 0x9b1, 0x3, 0xeb, 0x3, 0xeb, 0x3, 0xeb, 0x5, 
       0xeb, 0x9b7, 0xa, 0xeb, 0x3, 0xeb, 0x3, 0xeb, 0x3, 0xec, 0x5, 0xec, 
       0x9bc, 0xa, 0xec, 0x3, 0xec, 0x3, 0xec, 0x3, 0xec, 0x3, 0xec, 0x3, 
       0xec, 0x3, 0xec, 0x3, 0xec, 0x3, 0xec, 0x3, 0xec, 0x7, 0xec, 0x9c7, 
       0xa, 0xec, 0xc, 0xec, 0xe, 0xec, 0x9ca, 0xb, 0xec, 0x3, 0xec, 0x3, 
       0xec, 0x5, 0xec, 0x9ce, 0xa, 0xec, 0x3, 0xec, 0x3, 0xec, 0x3, 0xec, 
       0x5, 0xec, 0x9d3, 0xa, 0xec, 0x3, 0xec, 0x3, 0xec, 0x3, 0xed, 0x5, 
       0xed, 0x9d8, 0xa, 0xed, 0x3, 0xed, 0x3, 0xed, 0x5, 0xed, 0x9dc, 0xa, 
       0xed, 0x3, 0xed, 0x3, 0xed, 0x3, 0xed, 0x3, 0xed, 0x3, 0xed, 0x3, 
       0xed, 0x5, 0xed, 0x9e4, 0xa, 0xed, 0x3, 0xed, 0x3, 0xed, 0x3, 0xee, 
       0x3, 0xee, 0x3, 0xee, 0x3, 0xee, 0x3, 0xee, 0x5, 0xee, 0x9ed, 0xa, 
       0xee, 0x3, 0xee, 0x3, 0xee, 0x5, 0xee, 0x9f1, 0xa, 0xee, 0x3, 0xef, 
       0x7, 0xef, 0x9f4, 0xa, 0xef, 0xc, 0xef, 0xe, 0xef, 0x9f7, 0xb, 0xef, 
       0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 0x3, 0xf0, 
       0x3, 0xf0, 0x5, 0xf0, 0xa00, 0xa, 0xf0, 0x3, 0xf1, 0x3, 0xf1, 0x3, 
       0xf1, 0x3, 0xf1, 0x3, 0xf1, 0x3, 0xf1, 0x3, 0xf1, 0x3, 0xf2, 0x3, 
       0xf2, 0x3, 0xf2, 0x3, 0xf2, 0x3, 0xf2, 0x3, 0xf2, 0x3, 0xf3, 0x3, 
       0xf3, 0x3, 0xf3, 0x3, 0xf3, 0x3, 0xf3, 0x3, 0xf3, 0x3, 0xf4, 0x3, 
       0xf4, 0x5, 0xf4, 0xa17, 0xa, 0xf4, 0x3, 0xf4, 0x3, 0xf4, 0x3, 0xf4, 
       0x3, 0xf4, 0x3, 0xf4, 0x3, 0xf4, 0x5, 0xf4, 0xa1f, 0xa, 0xf4, 0x3, 
       0xf5, 0x3, 0xf5, 0x3, 0xf5, 0x3, 0xf5, 0x3, 0xf5, 0x3, 0xf5, 0x3, 
       0xf5, 0x5, 0xf5, 0xa28, 0xa, 0xf5, 0x3, 0xf5, 0x5, 0xf5, 0xa2b, 0xa, 
       0xf5, 0x3, 0xf5, 0x3, 0xf5, 0x3, 0xf6, 0x3, 0xf6, 0x3, 0xf6, 0x3, 
       0xf7, 0x3, 0xf7, 0x3, 0xf7, 0x3, 0xf7, 0x3, 0xf7, 0x3, 0xf7, 0x3, 
       0xf7, 0x3, 0xf7, 0x3, 0xf7, 0x3, 0xf7, 0x3, 0xf7, 0x3, 0xf7, 0x3, 
       0xf7, 0x5, 0xf7, 0xa3f, 0xa, 0xf7, 0x3, 0xf8, 0x7, 0xf8, 0xa42, 0xa, 
       0xf8, 0xc, 0xf8, 0xe, 0xf8, 0xa45, 0xb, 0xf8, 0x3, 0xf9, 0x3, 0xf9, 
       0x3, 0xfa, 0x3, 0xfa, 0x5, 0xfa, 0xa4b, 0xa, 0xfa, 0x3, 0xfb, 0x3, 
       0xfb, 0x3, 0xfb, 0x3, 0xfb, 0x3, 0xfb, 0x3, 0xfb, 0x5, 0xfb, 0xa53, 
       0xa, 0xfb, 0x3, 0xfc, 0x5, 0xfc, 0xa56, 0xa, 0xfc, 0x3, 0xfc, 0x3, 
       0xfc, 0x3, 0xfc, 0x3, 0xfc, 0x3, 0xfc, 0x3, 0xfc, 0x5, 0xfc, 0xa5e, 
       0xa, 0xfc, 0x3, 0xfc, 0x3, 0xfc, 0x3, 0xfc, 0x3, 0xfd, 0x7, 0xfd, 
       0xa64, 0xa, 0xfd, 0xc, 0xfd, 0xe, 0xfd, 0xa67, 0xb, 0xfd, 0x3, 0xfe, 
       0x3, 0xfe, 0x3, 0xfe, 0x3, 0xfe, 0x3, 0xfe, 0x3, 0xfe, 0x3, 0xff, 
       0x3, 0xff, 0x5, 0xff, 0xa71, 0xa, 0xff, 0x3, 0xff, 0x7, 0xff, 0xa74, 
       0xa, 0xff, 0xc, 0xff, 0xe, 0xff, 0xa77, 0xb, 0xff, 0x3, 0xff, 0x5, 
       0xff, 0xa7a, 0xa, 0xff, 0x3, 0x100, 0x3, 0x100, 0x3, 0x100, 0x3, 
       0x100, 0x5, 0x100, 0xa80, 0xa, 0x100, 0x3, 0x101, 0x3, 0x101, 0x5, 
       0x101, 0xa84, 0xa, 0x101, 0x3, 0x102, 0x3, 0x102, 0x3, 0x102, 0x3, 
       0x102, 0x7, 0x102, 0xa8a, 0xa, 0x102, 0xc, 0x102, 0xe, 0x102, 0xa8d, 
       0xb, 0x102, 0x3, 0x103, 0x3, 0x103, 0x3, 0x103, 0x5, 0x103, 0xa92, 
       0xa, 0x103, 0x3, 0x104, 0x3, 0x104, 0x3, 0x104, 0x3, 0x104, 0x3, 
       0x104, 0x3, 0x104, 0x3, 0x105, 0x3, 0x105, 0x5, 0x105, 0xa9c, 0xa, 
       0x105, 0x3, 0x105, 0x3, 0x105, 0x5, 0x105, 0xaa0, 0xa, 0x105, 0x3, 
       0x105, 0x3, 0x105, 0x3, 0x106, 0x3, 0x106, 0x3, 0x106, 0x3, 0x107, 
       0x3, 0x107, 0x3, 0x107, 0x3, 0x108, 0x3, 0x108, 0x3, 0x108, 0x3, 
       0x108, 0x5, 0x108, 0xaae, 0xa, 0x108, 0x3, 0x108, 0x3, 0x108, 0x3, 
       0x109, 0x3, 0x109, 0x3, 0x109, 0x3, 0x109, 0x5, 0x109, 0xab6, 0xa, 
       0x109, 0x3, 0x10a, 0x3, 0x10a, 0x3, 0x10a, 0x3, 0x10a, 0x3, 0x10a, 
       0x7, 0x10a, 0xabd, 0xa, 0x10a, 0xc, 0x10a, 0xe, 0x10a, 0xac0, 0xb, 
       0x10a, 0x3, 0x10a, 0x3, 0x10a, 0x3, 0x10a, 0x3, 0x10a, 0x3, 0x10b, 
       0x3, 0x10b, 0x3, 0x10b, 0x3, 0x10b, 0x3, 0x10b, 0x7, 0x10b, 0xacb, 
       0xa, 0x10b, 0xc, 0x10b, 0xe, 0x10b, 0xace, 0xb, 0x10b, 0x3, 0x10b, 
       0x3, 0x10b, 0x3, 0x10b, 0x3, 0x10b, 0x3, 0x10c, 0x3, 0x10c, 0x3, 
       0x10c, 0x3, 0x10c, 0x7, 0x10c, 0xad8, 0xa, 0x10c, 0xc, 0x10c, 0xe, 
       0x10c, 0xadb, 0xb, 0x10c, 0x3, 0x10c, 0x3, 0x10c, 0x3, 0x10d, 0x5, 
       0x10d, 0xae0, 0xa, 0x10d, 0x3, 0x10d, 0x3, 0x10d, 0x5, 0x10d, 0xae4, 
       0xa, 0x10d, 0x3, 0x10d, 0x3, 0x10d, 0x5, 0x10d, 0xae8, 0xa, 0x10d, 
       0x3, 0x10d, 0x5, 0x10d, 0xaeb, 0xa, 0x10d, 0x3, 0x10e, 0x3, 0x10e, 
       0x3, 0x10e, 0x3, 0x10e, 0x3, 0x10e, 0x3, 0x10f, 0x3, 0x10f, 0x3, 
       0x10f, 0x3, 0x10f, 0x3, 0x10f, 0x3, 0x110, 0x3, 0x110, 0x3, 0x110, 
       0x3, 0x110, 0x5, 0x110, 0xafb, 0xa, 0x110, 0x3, 0x111, 0x5, 0x111, 
       0xafe, 0xa, 0x111, 0x3, 0x111, 0x3, 0x111, 0x3, 0x111, 0x3, 0x111, 
       0x3, 0x111, 0x3, 0x111, 0x5, 0x111, 0xb06, 0xa, 0x111, 0x3, 0x111, 
       0x3, 0x111, 0x3, 0x112, 0x5, 0x112, 0xb0b, 0xa, 0x112, 0x3, 0x112, 
       0x3, 0x112, 0x5, 0x112, 0xb0f, 0xa, 0x112, 0x3, 0x112, 0x5, 0x112, 
       0xb12, 0xa, 0x112, 0x3, 0x112, 0x5, 0x112, 0xb15, 0xa, 0x112, 0x3, 
       0x112, 0x3, 0x112, 0x3, 0x113, 0x3, 0x113, 0x3, 0x113, 0x7, 0x113, 
       0xb1c, 0xa, 0x113, 0xc, 0x113, 0xe, 0x113, 0xb1f, 0xb, 0x113, 0x3, 
       0x113, 0x5, 0x113, 0xb22, 0xa, 0x113, 0x3, 0x114, 0x3, 0x114, 0x3, 
       0x114, 0x5, 0x114, 0xb27, 0xa, 0x114, 0x3, 0x114, 0x2, 0x2, 0x115, 
       0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
       0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
       0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 
       0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 
       0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 
       0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 
       0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 
       0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 
       0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 
       0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde, 
       0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 0xf4, 
       0xf6, 0xf8, 0xfa, 0xfc, 0xfe, 0x100, 0x102, 0x104, 0x106, 0x108, 
       0x10a, 0x10c, 0x10e, 0x110, 0x112, 0x114, 0x116, 0x118, 0x11a, 0x11c, 
       0x11e, 0x120, 0x122, 0x124, 0x126, 0x128, 0x12a, 0x12c, 0x12e, 0x130, 
       0x132, 0x134, 0x136, 0x138, 0x13a, 0x13c, 0x13e, 0x140, 0x142, 0x144, 
       0x146, 0x148, 0x14a, 0x14c, 0x14e, 0x150, 0x152, 0x154, 0x156, 0x158, 
       0x15a, 0x15c, 0x15e, 0x160, 0x162, 0x164, 0x166, 0x168, 0x16a, 0x16c, 
       0x16e, 0x170, 0x172, 0x174, 0x176, 0x178, 0x17a, 0x17c, 0x17e, 0x180, 
       0x182, 0x184, 0x186, 0x188, 0x18a, 0x18c, 0x18e, 0x190, 0x192, 0x194, 
       0x196, 0x198, 0x19a, 0x19c, 0x19e, 0x1a0, 0x1a2, 0x1a4, 0x1a6, 0x1a8, 
       0x1aa, 0x1ac, 0x1ae, 0x1b0, 0x1b2, 0x1b4, 0x1b6, 0x1b8, 0x1ba, 0x1bc, 
       0x1be, 0x1c0, 0x1c2, 0x1c4, 0x1c6, 0x1c8, 0x1ca, 0x1cc, 0x1ce, 0x1d0, 
       0x1d2, 0x1d4, 0x1d6, 0x1d8, 0x1da, 0x1dc, 0x1de, 0x1e0, 0x1e2, 0x1e4, 
       0x1e6, 0x1e8, 0x1ea, 0x1ec, 0x1ee, 0x1f0, 0x1f2, 0x1f4, 0x1f6, 0x1f8, 
       0x1fa, 0x1fc, 0x1fe, 0x200, 0x202, 0x204, 0x206, 0x208, 0x20a, 0x20c, 
       0x20e, 0x210, 0x212, 0x214, 0x216, 0x218, 0x21a, 0x21c, 0x21e, 0x220, 
       0x222, 0x224, 0x226, 0x2, 0x12, 0x5, 0x2, 0x74, 0x74, 0x7a, 0x7a, 
       0xa7, 0xa7, 0x4, 0x2, 0x93, 0x93, 0x9b, 0x9c, 0x4, 0x2, 0x19, 0x19, 
       0x65, 0x65, 0x13, 0x2, 0xa, 0xa, 0x15, 0x17, 0x1b, 0x1b, 0x1f, 0x1f, 
       0x22, 0x22, 0x25, 0x25, 0x2d, 0x2d, 0x31, 0x31, 0x36, 0x36, 0x43, 
       0x43, 0x47, 0x47, 0x4a, 0x4a, 0x5a, 0x5a, 0x60, 0x62, 0x68, 0x68, 
       0x6a, 0x6a, 0x6d, 0x6d, 0x3, 0x2, 0x7b, 0x7c, 0x4, 0x2, 0x29, 0x29, 
       0x42, 0x42, 0x5, 0x2, 0x29, 0x29, 0x2b, 0x2b, 0x42, 0x42, 0x7, 0x2, 
       0x9, 0x9, 0x35, 0x35, 0x3a, 0x3a, 0x40, 0x40, 0x72, 0x73, 0x7, 0x2, 
       0x12, 0x12, 0x29, 0x29, 0x2b, 0x2b, 0x30, 0x30, 0x42, 0x42, 0x5, 
       0x2, 0x34, 0x34, 0x4e, 0x4e, 0x99, 0x9a, 0x5, 0x2, 0x8a, 0x8b, 0x8d, 
       0x8d, 0x9d, 0x9f, 0x5, 0x2, 0x55, 0x56, 0x5b, 0x5c, 0x5e, 0x5f, 0x4, 
       0x2, 0x13, 0x13, 0x51, 0x51, 0x3, 0x2, 0x9b, 0x9c, 0x4, 0x2, 0x22, 
       0x22, 0x47, 0x47, 0x4, 0x2, 0x28, 0x28, 0x49, 0x49, 0x2, 0xbff, 0x2, 
       0x228, 0x3, 0x2, 0x2, 0x2, 0x4, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x22d, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0x239, 0x3, 0x2, 0x2, 0x2, 0xa, 0x23b, 0x3, 
       0x2, 0x2, 0x2, 0xc, 0x243, 0x3, 0x2, 0x2, 0x2, 0xe, 0x245, 0x3, 0x2, 
       0x2, 0x2, 0x10, 0x247, 0x3, 0x2, 0x2, 0x2, 0x12, 0x252, 0x3, 0x2, 
       0x2, 0x2, 0x14, 0x262, 0x3, 0x2, 0x2, 0x2, 0x16, 0x266, 0x3, 0x2, 
       0x2, 0x2, 0x18, 0x268, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x26d, 0x3, 0x2, 
       0x2, 0x2, 0x1c, 0x281, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x299, 0x3, 0x2, 
       0x2, 0x2, 0x20, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x22, 0x2a3, 0x3, 0x2, 
       0x2, 0x2, 0x24, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x26, 0x2a9, 0x3, 0x2, 
       0x2, 0x2, 0x28, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2bc, 0x3, 0x2, 
       0x2, 0x2, 0x2c, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c8, 0x3, 0x2, 
       0x2, 0x2, 0x30, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x32, 0x2d6, 0x3, 0x2, 
       0x2, 0x2, 0x34, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x36, 0x2e3, 0x3, 0x2, 
       0x2, 0x2, 0x38, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x313, 0x3, 0x2, 
       0x2, 0x2, 0x3c, 0x318, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x321, 0x3, 0x2, 
       0x2, 0x2, 0x40, 0x333, 0x3, 0x2, 0x2, 0x2, 0x42, 0x335, 0x3, 0x2, 
       0x2, 0x2, 0x44, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x46, 0x351, 0x3, 0x2, 
       0x2, 0x2, 0x48, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x362, 0x3, 0x2, 
       0x2, 0x2, 0x4c, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x36f, 0x3, 0x2, 
       0x2, 0x2, 0x50, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x52, 0x38d, 0x3, 0x2, 
       0x2, 0x2, 0x54, 0x396, 0x3, 0x2, 0x2, 0x2, 0x56, 0x398, 0x3, 0x2, 
       0x2, 0x2, 0x58, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x3ae, 0x3, 0x2, 
       0x2, 0x2, 0x5c, 0x3c0, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x3ca, 0x3, 0x2, 
       0x2, 0x2, 0x60, 0x3d0, 0x3, 0x2, 0x2, 0x2, 0x62, 0x3d4, 0x3, 0x2, 
       0x2, 0x2, 0x64, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0x66, 0x3e0, 0x3, 0x2, 
       0x2, 0x2, 0x68, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x40d, 0x3, 0x2, 
       0x2, 0x2, 0x6c, 0x40f, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x415, 0x3, 0x2, 
       0x2, 0x2, 0x70, 0x41b, 0x3, 0x2, 0x2, 0x2, 0x72, 0x427, 0x3, 0x2, 
       0x2, 0x2, 0x74, 0x429, 0x3, 0x2, 0x2, 0x2, 0x76, 0x42e, 0x3, 0x2, 
       0x2, 0x2, 0x78, 0x430, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x437, 0x3, 0x2, 
       0x2, 0x2, 0x7c, 0x43f, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x450, 0x3, 0x2, 
       0x2, 0x2, 0x80, 0x461, 0x3, 0x2, 0x2, 0x2, 0x82, 0x474, 0x3, 0x2, 
       0x2, 0x2, 0x84, 0x479, 0x3, 0x2, 0x2, 0x2, 0x86, 0x47e, 0x3, 0x2, 
       0x2, 0x2, 0x88, 0x480, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x485, 0x3, 0x2, 
       0x2, 0x2, 0x8c, 0x48f, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x494, 0x3, 0x2, 
       0x2, 0x2, 0x90, 0x49b, 0x3, 0x2, 0x2, 0x2, 0x92, 0x4a0, 0x3, 0x2, 
       0x2, 0x2, 0x94, 0x4a5, 0x3, 0x2, 0x2, 0x2, 0x96, 0x4ad, 0x3, 0x2, 
       0x2, 0x2, 0x98, 0x4b2, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x4b7, 0x3, 0x2, 
       0x2, 0x2, 0x9c, 0x4bc, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x4be, 0x3, 0x2, 
       0x2, 0x2, 0xa0, 0x4c0, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x4c8, 0x3, 0x2, 
       0x2, 0x2, 0xa4, 0x4cd, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x4d1, 0x3, 0x2, 
       0x2, 0x2, 0xa8, 0x4d6, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x4d8, 0x3, 0x2, 
       0x2, 0x2, 0xac, 0x4e5, 0x3, 0x2, 0x2, 0x2, 0xae, 0x4e7, 0x3, 0x2, 
       0x2, 0x2, 0xb0, 0x4e9, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x4ed, 0x3, 0x2, 
       0x2, 0x2, 0xb4, 0x4f5, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x51b, 0x3, 0x2, 
       0x2, 0x2, 0xb8, 0x520, 0x3, 0x2, 0x2, 0x2, 0xba, 0x523, 0x3, 0x2, 
       0x2, 0x2, 0xbc, 0x528, 0x3, 0x2, 0x2, 0x2, 0xbe, 0x537, 0x3, 0x2, 
       0x2, 0x2, 0xc0, 0x539, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x540, 0x3, 0x2, 
       0x2, 0x2, 0xc4, 0x545, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x54b, 0x3, 0x2, 
       0x2, 0x2, 0xc8, 0x54f, 0x3, 0x2, 0x2, 0x2, 0xca, 0x551, 0x3, 0x2, 
       0x2, 0x2, 0xcc, 0x55d, 0x3, 0x2, 0x2, 0x2, 0xce, 0x56c, 0x3, 0x2, 
       0x2, 0x2, 0xd0, 0x56e, 0x3, 0x2, 0x2, 0x2, 0xd2, 0x580, 0x3, 0x2, 
       0x2, 0x2, 0xd4, 0x582, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x58b, 0x3, 0x2, 
       0x2, 0x2, 0xd8, 0x58f, 0x3, 0x2, 0x2, 0x2, 0xda, 0x594, 0x3, 0x2, 
       0x2, 0x2, 0xdc, 0x598, 0x3, 0x2, 0x2, 0x2, 0xde, 0x5a3, 0x3, 0x2, 
       0x2, 0x2, 0xe0, 0x5a5, 0x3, 0x2, 0x2, 0x2, 0xe2, 0x5b2, 0x3, 0x2, 
       0x2, 0x2, 0xe4, 0x5b4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0x5c1, 0x3, 0x2, 
       0x2, 0x2, 0xe8, 0x5de, 0x3, 0x2, 0x2, 0x2, 0xea, 0x5ef, 0x3, 0x2, 
       0x2, 0x2, 0xec, 0x5fb, 0x3, 0x2, 0x2, 0x2, 0xee, 0x609, 0x3, 0x2, 
       0x2, 0x2, 0xf0, 0x60b, 0x3, 0x2, 0x2, 0x2, 0xf2, 0x611, 0x3, 0x2, 
       0x2, 0x2, 0xf4, 0x619, 0x3, 0x2, 0x2, 0x2, 0xf6, 0x621, 0x3, 0x2, 
       0x2, 0x2, 0xf8, 0x623, 0x3, 0x2, 0x2, 0x2, 0xfa, 0x62b, 0x3, 0x2, 
       0x2, 0x2, 0xfc, 0x633, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x63b, 0x3, 0x2, 
       0x2, 0x2, 0x100, 0x63f, 0x3, 0x2, 0x2, 0x2, 0x102, 0x641, 0x3, 0x2, 
       0x2, 0x2, 0x104, 0x64a, 0x3, 0x2, 0x2, 0x2, 0x106, 0x665, 0x3, 0x2, 
       0x2, 0x2, 0x108, 0x672, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x674, 0x3, 0x2, 
       0x2, 0x2, 0x10c, 0x686, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x692, 0x3, 0x2, 
       0x2, 0x2, 0x110, 0x695, 0x3, 0x2, 0x2, 0x2, 0x112, 0x6a7, 0x3, 0x2, 
       0x2, 0x2, 0x114, 0x6a9, 0x3, 0x2, 0x2, 0x2, 0x116, 0x6ab, 0x3, 0x2, 
       0x2, 0x2, 0x118, 0x6b0, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x6b8, 0x3, 0x2, 
       0x2, 0x2, 0x11c, 0x6c0, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x6c8, 0x3, 0x2, 
       0x2, 0x2, 0x120, 0x6d3, 0x3, 0x2, 0x2, 0x2, 0x122, 0x6de, 0x3, 0x2, 
       0x2, 0x2, 0x124, 0x6ec, 0x3, 0x2, 0x2, 0x2, 0x126, 0x6f2, 0x3, 0x2, 
       0x2, 0x2, 0x128, 0x702, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x704, 0x3, 0x2, 
       0x2, 0x2, 0x12c, 0x707, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x70d, 0x3, 0x2, 
       0x2, 0x2, 0x130, 0x714, 0x3, 0x2, 0x2, 0x2, 0x132, 0x716, 0x3, 0x2, 
       0x2, 0x2, 0x134, 0x718, 0x3, 0x2, 0x2, 0x2, 0x136, 0x720, 0x3, 0x2, 
       0x2, 0x2, 0x138, 0x723, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x731, 0x3, 0x2, 
       0x2, 0x2, 0x13c, 0x733, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x73e, 0x3, 0x2, 
       0x2, 0x2, 0x140, 0x740, 0x3, 0x2, 0x2, 0x2, 0x142, 0x74a, 0x3, 0x2, 
       0x2, 0x2, 0x144, 0x74c, 0x3, 0x2, 0x2, 0x2, 0x146, 0x758, 0x3, 0x2, 
       0x2, 0x2, 0x148, 0x75e, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x769, 0x3, 0x2, 
       0x2, 0x2, 0x14c, 0x771, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x779, 0x3, 0x2, 
       0x2, 0x2, 0x150, 0x77b, 0x3, 0x2, 0x2, 0x2, 0x152, 0x780, 0x3, 0x2, 
       0x2, 0x2, 0x154, 0x78e, 0x3, 0x2, 0x2, 0x2, 0x156, 0x796, 0x3, 0x2, 
       0x2, 0x2, 0x158, 0x799, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x79e, 0x3, 0x2, 
       0x2, 0x2, 0x15c, 0x7b8, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x7bd, 0x3, 0x2, 
       0x2, 0x2, 0x160, 0x7c0, 0x3, 0x2, 0x2, 0x2, 0x162, 0x7df, 0x3, 0x2, 
       0x2, 0x2, 0x164, 0x7e4, 0x3, 0x2, 0x2, 0x2, 0x166, 0x7e7, 0x3, 0x2, 
       0x2, 0x2, 0x168, 0x7eb, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x7ee, 0x3, 0x2, 
       0x2, 0x2, 0x16c, 0x7fc, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x802, 0x3, 0x2, 
       0x2, 0x2, 0x170, 0x804, 0x3, 0x2, 0x2, 0x2, 0x172, 0x813, 0x3, 0x2, 
       0x2, 0x2, 0x174, 0x818, 0x3, 0x2, 0x2, 0x2, 0x176, 0x826, 0x3, 0x2, 
       0x2, 0x2, 0x178, 0x82b, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x831, 0x3, 0x2, 
       0x2, 0x2, 0x17c, 0x834, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x83c, 0x3, 0x2, 
       0x2, 0x2, 0x180, 0x84e, 0x3, 0x2, 0x2, 0x2, 0x182, 0x853, 0x3, 0x2, 
       0x2, 0x2, 0x184, 0x857, 0x3, 0x2, 0x2, 0x2, 0x186, 0x876, 0x3, 0x2, 
       0x2, 0x2, 0x188, 0x879, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x885, 0x3, 0x2, 
       0x2, 0x2, 0x18c, 0x891, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x893, 0x3, 0x2, 
       0x2, 0x2, 0x190, 0x899, 0x3, 0x2, 0x2, 0x2, 0x192, 0x89b, 0x3, 0x2, 
       0x2, 0x2, 0x194, 0x89f, 0x3, 0x2, 0x2, 0x2, 0x196, 0x8a2, 0x3, 0x2, 
       0x2, 0x2, 0x198, 0x8ad, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x8b8, 0x3, 0x2, 
       0x2, 0x2, 0x19c, 0x8be, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x8c1, 0x3, 0x2, 
       0x2, 0x2, 0x1a0, 0x8cc, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x8d4, 0x3, 0x2, 
       0x2, 0x2, 0x1a4, 0x8de, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x8e2, 0x3, 0x2, 
       0x2, 0x2, 0x1a8, 0x8e4, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x8e9, 0x3, 0x2, 
       0x2, 0x2, 0x1ac, 0x8f5, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x902, 0x3, 0x2, 
       0x2, 0x2, 0x1b0, 0x90e, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x913, 0x3, 0x2, 
       0x2, 0x2, 0x1b4, 0x928, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x92a, 0x3, 0x2, 
       0x2, 0x2, 0x1b8, 0x930, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x93e, 0x3, 0x2, 
       0x2, 0x2, 0x1bc, 0x943, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x945, 0x3, 0x2, 
       0x2, 0x2, 0x1c0, 0x94d, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x956, 0x3, 0x2, 
       0x2, 0x2, 0x1c4, 0x95e, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x960, 0x3, 0x2, 
       0x2, 0x2, 0x1c8, 0x96d, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x979, 0x3, 0x2, 
       0x2, 0x2, 0x1cc, 0x97b, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x98d, 0x3, 0x2, 
       0x2, 0x2, 0x1d0, 0x999, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x9a3, 0x3, 0x2, 
       0x2, 0x2, 0x1d4, 0x9a9, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x9bb, 0x3, 0x2, 
       0x2, 0x2, 0x1d8, 0x9d7, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x9f0, 0x3, 0x2, 
       0x2, 0x2, 0x1dc, 0x9f5, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x9ff, 0x3, 0x2, 
       0x2, 0x2, 0x1e0, 0xa01, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0xa08, 0x3, 0x2, 
       0x2, 0x2, 0x1e4, 0xa0e, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0xa14, 0x3, 0x2, 
       0x2, 0x2, 0x1e8, 0xa20, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0xa2e, 0x3, 0x2, 
       0x2, 0x2, 0x1ec, 0xa3e, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0xa43, 0x3, 0x2, 
       0x2, 0x2, 0x1f0, 0xa46, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0xa4a, 0x3, 0x2, 
       0x2, 0x2, 0x1f4, 0xa4c, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0xa55, 0x3, 0x2, 
       0x2, 0x2, 0x1f8, 0xa65, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0xa68, 0x3, 0x2, 
       0x2, 0x2, 0x1fc, 0xa6e, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0xa7f, 0x3, 0x2, 
       0x2, 0x2, 0x200, 0xa83, 0x3, 0x2, 0x2, 0x2, 0x202, 0xa85, 0x3, 0x2, 
       0x2, 0x2, 0x204, 0xa8e, 0x3, 0x2, 0x2, 0x2, 0x206, 0xa93, 0x3, 0x2, 
       0x2, 0x2, 0x208, 0xa99, 0x3, 0x2, 0x2, 0x2, 0x20a, 0xaa3, 0x3, 0x2, 
       0x2, 0x2, 0x20c, 0xaa6, 0x3, 0x2, 0x2, 0x2, 0x20e, 0xaa9, 0x3, 0x2, 
       0x2, 0x2, 0x210, 0xab5, 0x3, 0x2, 0x2, 0x2, 0x212, 0xab7, 0x3, 0x2, 
       0x2, 0x2, 0x214, 0xac5, 0x3, 0x2, 0x2, 0x2, 0x216, 0xad3, 0x3, 0x2, 
       0x2, 0x2, 0x218, 0xaea, 0x3, 0x2, 0x2, 0x2, 0x21a, 0xaec, 0x3, 0x2, 
       0x2, 0x2, 0x21c, 0xaf1, 0x3, 0x2, 0x2, 0x2, 0x21e, 0xaf6, 0x3, 0x2, 
       0x2, 0x2, 0x220, 0xafd, 0x3, 0x2, 0x2, 0x2, 0x222, 0xb0a, 0x3, 0x2, 
       0x2, 0x2, 0x224, 0xb21, 0x3, 0x2, 0x2, 0x2, 0x226, 0xb23, 0x3, 0x2, 
       0x2, 0x2, 0x228, 0x229, 0x9, 0x2, 0x2, 0x2, 0x229, 0x3, 0x3, 0x2, 
       0x2, 0x2, 0x22a, 0x22b, 0x7, 0x4, 0x2, 0x2, 0x22b, 0x22c, 0x5, 0x1fc, 
       0xff, 0x2, 0x22c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22f, 0x5, 0x102, 
       0x82, 0x2, 0x22e, 0x230, 0x5, 0x20c, 0x107, 0x2, 0x22f, 0x22e, 0x3, 
       0x2, 0x2, 0x2, 0x22f, 0x230, 0x3, 0x2, 0x2, 0x2, 0x230, 0x233, 0x3, 
       0x2, 0x2, 0x2, 0x231, 0x232, 0x7, 0x8e, 0x2, 0x2, 0x232, 0x234, 0x5, 
       0xce, 0x68, 0x2, 0x233, 0x231, 0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 
       0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x3, 0x2, 0x2, 0x2, 0x235, 0x236, 
       0x7, 0x5, 0x2, 0x2, 0x236, 0x7, 0x3, 0x2, 0x2, 0x2, 0x237, 0x23a, 
       0x5, 0xce, 0x68, 0x2, 0x238, 0x23a, 0x7, 0x3f, 0x2, 0x2, 0x239, 0x237, 
       0x3, 0x2, 0x2, 0x2, 0x239, 0x238, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x9, 
       0x3, 0x2, 0x2, 0x2, 0x23b, 0x23c, 0x5, 0x2c, 0x17, 0x2, 0x23c, 0xb, 
       0x3, 0x2, 0x2, 0x2, 0x23d, 0x23e, 0x5, 0x13e, 0xa0, 0x2, 0x23e, 0x23f, 
       0x7, 0x94, 0x2, 0x2, 0x23f, 0x240, 0x5, 0x8, 0x5, 0x2, 0x240, 0x241, 
       0x7, 0x95, 0x2, 0x2, 0x241, 0x244, 0x3, 0x2, 0x2, 0x2, 0x242, 0x244, 
       0x5, 0x8, 0x5, 0x2, 0x243, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x243, 0x242, 
       0x3, 0x2, 0x2, 0x2, 0x244, 0xd, 0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 
       0x9, 0x3, 0x2, 0x2, 0x246, 0xf, 0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 
       0x7, 0x94, 0x2, 0x2, 0x248, 0x24d, 0x5, 0xa4, 0x53, 0x2, 0x249, 0x24a, 
       0x7, 0x92, 0x2, 0x2, 0x24a, 0x24c, 0x5, 0xa4, 0x53, 0x2, 0x24b, 0x249, 
       0x3, 0x2, 0x2, 0x2, 0x24c, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24b, 
       0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x250, 
       0x3, 0x2, 0x2, 0x2, 0x24f, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x250, 0x251, 
       0x7, 0x95, 0x2, 0x2, 0x251, 0x11, 0x3, 0x2, 0x2, 0x2, 0x252, 0x253, 
       0x7, 0x7, 0x2, 0x2, 0x253, 0x256, 0x5, 0x14, 0xb, 0x2, 0x254, 0x255, 
       0x7, 0x98, 0x2, 0x2, 0x255, 0x257, 0x5, 0x16, 0xc, 0x2, 0x256, 0x254, 
       0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 0x3, 0x2, 0x2, 0x2, 0x257, 0x258, 
       0x3, 0x2, 0x2, 0x2, 0x258, 0x259, 0x7, 0x2c, 0x2, 0x2, 0x259, 0x25b, 
       0x5, 0x13e, 0xa0, 0x2, 0x25a, 0x25c, 0x5, 0x1cc, 0xe7, 0x2, 0x25b, 
       0x25a, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25c, 
       0x25d, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 0x7, 0x91, 0x2, 0x2, 0x25e, 
       0x13, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x263, 0x5, 0x100, 0x81, 0x2, 0x260, 
       0x263, 0x7, 0x85, 0x2, 0x2, 0x261, 0x263, 0x7, 0x86, 0x2, 0x2, 0x262, 
       0x25f, 0x3, 0x2, 0x2, 0x2, 0x262, 0x260, 0x3, 0x2, 0x2, 0x2, 0x262, 
       0x261, 0x3, 0x2, 0x2, 0x2, 0x263, 0x15, 0x3, 0x2, 0x2, 0x2, 0x264, 
       0x267, 0x5, 0x1e6, 0xf4, 0x2, 0x265, 0x267, 0x5, 0x1fc, 0xff, 0x2, 
       0x266, 0x264, 0x3, 0x2, 0x2, 0x2, 0x266, 0x265, 0x3, 0x2, 0x2, 0x2, 
       0x267, 0x17, 0x3, 0x2, 0x2, 0x2, 0x268, 0x26b, 0x7, 0x37, 0x2, 0x2, 
       0x269, 0x26c, 0x5, 0x188, 0xc5, 0x2, 0x26a, 0x26c, 0x5, 0x1fc, 0xff, 
       0x2, 0x26b, 0x269, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26a, 0x3, 0x2, 0x2, 
       0x2, 0x26c, 0x19, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x7, 0xa, 0x2, 
       0x2, 0x26e, 0x26f, 0x5, 0x100, 0x81, 0x2, 0x26f, 0x270, 0x7, 0x3d, 
       0x2, 0x2, 0x270, 0x271, 0x5, 0x100, 0x81, 0x2, 0x271, 0x272, 0x7, 
       0x2c, 0x2, 0x2, 0x272, 0x273, 0x5, 0x1c, 0xf, 0x2, 0x273, 0x274, 
       0x7, 0xe, 0x2, 0x2, 0x274, 0x275, 0x5, 0x20, 0x11, 0x2, 0x275, 0x277, 
       0x7, 0x1a, 0x2, 0x2, 0x276, 0x278, 0x7, 0xa, 0x2, 0x2, 0x277, 0x276, 
       0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 0x3, 0x2, 0x2, 0x2, 0x278, 0x27a, 
       0x3, 0x2, 0x2, 0x2, 0x279, 0x27b, 0x5, 0x100, 0x81, 0x2, 0x27a, 0x279, 
       0x3, 0x2, 0x2, 0x2, 0x27a, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x27c, 
       0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x7, 0x91, 0x2, 0x2, 0x27d, 0x1b, 
       0x3, 0x2, 0x2, 0x2, 0x27e, 0x280, 0x5, 0x3a, 0x1e, 0x2, 0x27f, 0x27e, 
       0x3, 0x2, 0x2, 0x2, 0x280, 0x283, 0x3, 0x2, 0x2, 0x2, 0x281, 0x27f, 
       0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 0x3, 0x2, 0x2, 0x2, 0x282, 0x1d, 
       0x3, 0x2, 0x2, 0x2, 0x283, 0x281, 0x3, 0x2, 0x2, 0x2, 0x284, 0x29a, 
       0x5, 0x42, 0x22, 0x2, 0x285, 0x29a, 0x5, 0x184, 0xc3, 0x2, 0x286, 
       0x288, 0x5, 0x12a, 0x96, 0x2, 0x287, 0x286, 0x3, 0x2, 0x2, 0x2, 0x287, 
       0x288, 0x3, 0x2, 0x2, 0x2, 0x288, 0x289, 0x3, 0x2, 0x2, 0x2, 0x289, 
       0x29a, 0x5, 0x68, 0x35, 0x2, 0x28a, 0x28c, 0x5, 0x12a, 0x96, 0x2, 
       0x28b, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28c, 0x3, 0x2, 0x2, 0x2, 
       0x28c, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x29a, 0x5, 0x64, 0x33, 
       0x2, 0x28e, 0x290, 0x5, 0x12a, 0x96, 0x2, 0x28f, 0x28e, 0x3, 0x2, 
       0x2, 0x2, 0x28f, 0x290, 0x3, 0x2, 0x2, 0x2, 0x290, 0x292, 0x3, 0x2, 
       0x2, 0x2, 0x291, 0x293, 0x7, 0x45, 0x2, 0x2, 0x292, 0x291, 0x3, 0x2, 
       0x2, 0x2, 0x292, 0x293, 0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 0x3, 0x2, 
       0x2, 0x2, 0x294, 0x29a, 0x5, 0x6a, 0x36, 0x2, 0x295, 0x29a, 0x5, 
       0x5c, 0x2f, 0x2, 0x296, 0x29a, 0x5, 0xe2, 0x72, 0x2, 0x297, 0x29a, 
       0x5, 0x66, 0x34, 0x2, 0x298, 0x29a, 0x5, 0x1da, 0xee, 0x2, 0x299, 
       0x284, 0x3, 0x2, 0x2, 0x2, 0x299, 0x285, 0x3, 0x2, 0x2, 0x2, 0x299, 
       0x287, 0x3, 0x2, 0x2, 0x2, 0x299, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x299, 
       0x28f, 0x3, 0x2, 0x2, 0x2, 0x299, 0x295, 0x3, 0x2, 0x2, 0x2, 0x299, 
       0x296, 0x3, 0x2, 0x2, 0x2, 0x299, 0x297, 0x3, 0x2, 0x2, 0x2, 0x299, 
       0x298, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x29b, 
       0x29d, 0x5, 0x1e, 0x10, 0x2, 0x29c, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29d, 
       0x2a0, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x29e, 
       0x29f, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x21, 0x3, 0x2, 0x2, 0x2, 0x2a0, 
       0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a4, 0x5, 0x214, 0x10b, 0x2, 
       0x2a2, 0x2a4, 0x5, 0x8e, 0x48, 0x2, 0x2a3, 0x2a1, 0x3, 0x2, 0x2, 
       0x2, 0x2a3, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x23, 0x3, 0x2, 0x2, 
       0x2, 0x2a5, 0x2a8, 0x5, 0x212, 0x10a, 0x2, 0x2a6, 0x2a8, 0x5, 0x8c, 
       0x47, 0x2, 0x2a7, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a6, 0x3, 0x2, 
       0x2, 0x2, 0x2a8, 0x25, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 0x7, 0xc, 
       0x2, 0x2, 0x2aa, 0x2ad, 0x5, 0x72, 0x3a, 0x2, 0x2ab, 0x2ac, 0x7, 
       0x53, 0x2, 0x2, 0x2ac, 0x2ae, 0x5, 0xce, 0x68, 0x2, 0x2ad, 0x2ab, 
       0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2b1, 
       0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x7, 0x58, 0x2, 0x2, 0x2b0, 0x2b2, 
       0x5, 0xce, 0x68, 0x2, 0x2b1, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 
       0x3, 0x2, 0x2, 0x2, 0x2b2, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2b5, 
       0x5, 0x12a, 0x96, 0x2, 0x2b4, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b5, 
       0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b7, 
       0x5, 0x26, 0x14, 0x2, 0x2b7, 0x2b8, 0x7, 0x91, 0x2, 0x2, 0x2b8, 0x29, 
       0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2ba, 0x5, 0xde, 0x70, 0x2, 0x2ba, 0x2bb, 
       0x7, 0x8c, 0x2, 0x2, 0x2bb, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2b9, 
       0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 
       0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x5, 0xc, 0x7, 0x2, 0x2bf, 0x2b, 
       0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c5, 0x5, 0x2a, 0x16, 0x2, 0x2c1, 0x2c2, 
       0x7, 0x92, 0x2, 0x2, 0x2c2, 0x2c4, 0x5, 0x2a, 0x16, 0x2, 0x2c3, 0x2c1, 
       0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c3, 
       0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2d, 
       0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 
       0x7, 0xd, 0x2, 0x2, 0x2c9, 0x2ca, 0x5, 0x12a, 0x96, 0x2, 0x2ca, 0x2cb, 
       0x5, 0x13e, 0xa0, 0x2, 0x2cb, 0x2cc, 0x7, 0x91, 0x2, 0x2, 0x2cc, 
       0x2f, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2d5, 0x5, 0x100, 0x81, 0x2, 0x2ce, 
       0x2d5, 0x7, 0x4b, 0x2, 0x2, 0x2cf, 0x2d5, 0x7, 0x4c, 0x2, 0x2, 0x2d0, 
       0x2d5, 0x7, 0x5, 0x2, 0x2, 0x2d1, 0x2d5, 0x7, 0x64, 0x2, 0x2, 0x2d2, 
       0x2d5, 0x7, 0x50, 0x2, 0x2, 0x2d3, 0x2d5, 0x7, 0x66, 0x2, 0x2, 0x2d4, 
       0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2d4, 
       0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d4, 
       0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d4, 
       0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2d6, 
       0x2d7, 0x7, 0xd, 0x2, 0x2, 0x2d7, 0x2d8, 0x5, 0x30, 0x19, 0x2, 0x2d8, 
       0x2d9, 0x7, 0x3d, 0x2, 0x2, 0x2d9, 0x2da, 0x5, 0xc0, 0x61, 0x2, 0x2da, 
       0x2db, 0x7, 0x2c, 0x2, 0x2, 0x2db, 0x2dc, 0x5, 0xce, 0x68, 0x2, 0x2dc, 
       0x2dd, 0x7, 0x91, 0x2, 0x2, 0x2dd, 0x33, 0x3, 0x2, 0x2, 0x2, 0x2de, 
       0x2df, 0x5, 0x100, 0x81, 0x2, 0x2df, 0x2e0, 0x7, 0x91, 0x2, 0x2, 
       0x2e0, 0x35, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x7, 0x6c, 0x2, 0x2, 
       0x2e2, 0x2e4, 0x5, 0xac, 0x57, 0x2, 0x2e3, 0x2e1, 0x3, 0x2, 0x2, 
       0x2, 0x2e3, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e6, 0x3, 0x2, 0x2, 
       0x2, 0x2e5, 0x2e7, 0x5, 0xf4, 0x7b, 0x2, 0x2e6, 0x2e5, 0x3, 0x2, 
       0x2, 0x2, 0x2e6, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e9, 0x3, 0x2, 
       0x2, 0x2, 0x2e8, 0x2ea, 0x5, 0x170, 0xb9, 0x2, 0x2e9, 0x2e8, 0x3, 
       0x2, 0x2, 0x2, 0x2e9, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x37, 0x3, 
       0x2, 0x2, 0x2, 0x2eb, 0x2ec, 0x7, 0x20, 0x2, 0x2, 0x2ec, 0x2f0, 0x5, 
       0x40, 0x21, 0x2, 0x2ed, 0x2ef, 0x5, 0x216, 0x10c, 0x2, 0x2ee, 0x2ed, 
       0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2ee, 
       0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f6, 
       0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f5, 
       0x5, 0x86, 0x44, 0x2, 0x2f4, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f8, 
       0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f7, 
       0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f6, 
       0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fa, 0x7, 0x1a, 0x2, 0x2, 0x2fa, 0x2fb, 
       0x7, 0x20, 0x2, 0x2, 0x2fb, 0x2fc, 0x7, 0x91, 0x2, 0x2, 0x2fc, 0x39, 
       0x3, 0x2, 0x2, 0x2, 0x2fd, 0x314, 0x5, 0x1ea, 0xf6, 0x2, 0x2fe, 0x314, 
       0x5, 0x1e8, 0xf5, 0x2, 0x2ff, 0x314, 0x5, 0x20e, 0x108, 0x2, 0x300, 
       0x314, 0x5, 0x1fa, 0xfe, 0x2, 0x301, 0x314, 0x5, 0x8a, 0x46, 0x2, 
       0x302, 0x314, 0x5, 0x1c6, 0xe4, 0x2, 0x303, 0x314, 0x5, 0x220, 0x111, 
       0x2, 0x304, 0x314, 0x5, 0xd4, 0x6b, 0x2, 0x305, 0x314, 0x5, 0x12, 
       0xa, 0x2, 0x306, 0x314, 0x5, 0x5a, 0x2e, 0x2, 0x307, 0x314, 0x5, 
       0x2e, 0x18, 0x2, 0x308, 0x314, 0x5, 0x32, 0x1a, 0x2, 0x309, 0x314, 
       0x5, 0x88, 0x45, 0x2, 0x30a, 0x314, 0x5, 0xa0, 0x51, 0x2, 0x30b, 
       0x314, 0x5, 0x1e2, 0xf2, 0x2, 0x30c, 0x314, 0x5, 0x216, 0x10c, 0x2, 
       0x30d, 0x314, 0x5, 0xfc, 0x7f, 0x2, 0x30e, 0x314, 0x5, 0xfa, 0x7e, 
       0x2, 0x30f, 0x314, 0x5, 0x14c, 0xa7, 0x2, 0x310, 0x314, 0x5, 0x1e4, 
       0xf3, 0x2, 0x311, 0x314, 0x5, 0x18a, 0xc6, 0x2, 0x312, 0x314, 0x5, 
       0x206, 0x104, 0x2, 0x313, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x313, 0x2fe, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x313, 0x300, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x301, 0x3, 0x2, 0x2, 0x2, 0x313, 0x302, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x303, 0x3, 0x2, 0x2, 0x2, 0x313, 0x304, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x305, 0x3, 0x2, 0x2, 0x2, 0x313, 0x306, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x307, 0x3, 0x2, 0x2, 0x2, 0x313, 0x308, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x309, 0x3, 0x2, 0x2, 0x2, 0x313, 0x30a, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x313, 0x30c, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x313, 0x30e, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x313, 0x310, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x311, 0x3, 0x2, 0x2, 0x2, 0x313, 0x312, 
       0x3, 0x2, 0x2, 0x2, 0x314, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x315, 0x317, 
       0x5, 0x3a, 0x1e, 0x2, 0x316, 0x315, 0x3, 0x2, 0x2, 0x2, 0x317, 0x31a, 
       0x3, 0x2, 0x2, 0x2, 0x318, 0x316, 0x3, 0x2, 0x2, 0x2, 0x318, 0x319, 
       0x3, 0x2, 0x2, 0x2, 0x319, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x318, 
       0x3, 0x2, 0x2, 0x2, 0x31b, 0x31f, 0x5, 0xf0, 0x79, 0x2, 0x31c, 0x31d, 
       0x5, 0xf4, 0x7b, 0x2, 0x31d, 0x31e, 0x7, 0x91, 0x2, 0x2, 0x31e, 0x320, 
       0x3, 0x2, 0x2, 0x2, 0x31f, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x320, 
       0x3, 0x2, 0x2, 0x2, 0x320, 0x322, 0x3, 0x2, 0x2, 0x2, 0x321, 0x31b, 
       0x3, 0x2, 0x2, 0x2, 0x321, 0x322, 0x3, 0x2, 0x2, 0x2, 0x322, 0x329, 
       0x3, 0x2, 0x2, 0x2, 0x323, 0x327, 0x5, 0x16c, 0xb7, 0x2, 0x324, 0x325, 
       0x5, 0x170, 0xb9, 0x2, 0x325, 0x326, 0x7, 0x91, 0x2, 0x2, 0x326, 
       0x328, 0x3, 0x2, 0x2, 0x2, 0x327, 0x324, 0x3, 0x2, 0x2, 0x2, 0x327, 
       0x328, 0x3, 0x2, 0x2, 0x2, 0x328, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x329, 
       0x323, 0x3, 0x2, 0x2, 0x2, 0x329, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x32a, 
       0x3f, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x330, 0x5, 0x100, 0x81, 0x2, 0x32c, 
       0x32d, 0x7, 0x94, 0x2, 0x2, 0x32d, 0x32e, 0x5, 0x108, 0x85, 0x2, 
       0x32e, 0x32f, 0x7, 0x95, 0x2, 0x2, 0x32f, 0x331, 0x3, 0x2, 0x2, 0x2, 
       0x330, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x330, 0x331, 0x3, 0x2, 0x2, 0x2, 
       0x331, 0x334, 0x3, 0x2, 0x2, 0x2, 0x332, 0x334, 0x5, 0x13e, 0xa0, 
       0x2, 0x333, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x333, 0x332, 0x3, 0x2, 0x2, 
       0x2, 0x334, 0x41, 0x3, 0x2, 0x2, 0x2, 0x335, 0x336, 0x5, 0x12a, 0x96, 
       0x2, 0x336, 0x33b, 0x7, 0xf, 0x2, 0x2, 0x337, 0x338, 0x7, 0x94, 0x2, 
       0x2, 0x338, 0x339, 0x5, 0xce, 0x68, 0x2, 0x339, 0x33a, 0x7, 0x95, 
       0x2, 0x2, 0x33a, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x337, 0x3, 0x2, 
       0x2, 0x2, 0x33b, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33e, 0x3, 0x2, 
       0x2, 0x2, 0x33d, 0x33f, 0x7, 0x2c, 0x2, 0x2, 0x33e, 0x33d, 0x3, 0x2, 
       0x2, 0x2, 0x33e, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x340, 0x3, 0x2, 
       0x2, 0x2, 0x340, 0x341, 0x5, 0x3e, 0x20, 0x2, 0x341, 0x342, 0x5, 
       0x3c, 0x1f, 0x2, 0x342, 0x343, 0x7, 0xe, 0x2, 0x2, 0x343, 0x344, 
       0x5, 0x44, 0x23, 0x2, 0x344, 0x345, 0x7, 0x1a, 0x2, 0x2, 0x345, 0x347, 
       0x7, 0xf, 0x2, 0x2, 0x346, 0x348, 0x5, 0x100, 0x81, 0x2, 0x347, 0x346, 
       0x3, 0x2, 0x2, 0x2, 0x347, 0x348, 0x3, 0x2, 0x2, 0x2, 0x348, 0x349, 
       0x3, 0x2, 0x2, 0x2, 0x349, 0x34a, 0x7, 0x91, 0x2, 0x2, 0x34a, 0x43, 
       0x3, 0x2, 0x2, 0x2, 0x34b, 0x34d, 0x5, 0x1e, 0x10, 0x2, 0x34c, 0x34b, 
       0x3, 0x2, 0x2, 0x2, 0x34d, 0x350, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x34c, 
       0x3, 0x2, 0x2, 0x2, 0x34e, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x34f, 0x45, 
       0x3, 0x2, 0x2, 0x2, 0x350, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x351, 0x353, 
       0x7, 0x4a, 0x2, 0x2, 0x352, 0x354, 0x5, 0x6, 0x4, 0x2, 0x353, 0x352, 
       0x3, 0x2, 0x2, 0x2, 0x353, 0x354, 0x3, 0x2, 0x2, 0x2, 0x354, 0x356, 
       0x3, 0x2, 0x2, 0x2, 0x355, 0x357, 0x5, 0x208, 0x105, 0x2, 0x356, 
       0x355, 0x3, 0x2, 0x2, 0x2, 0x356, 0x357, 0x3, 0x2, 0x2, 0x2, 0x357, 
       0x358, 0x3, 0x2, 0x2, 0x2, 0x358, 0x359, 0x5, 0x204, 0x103, 0x2, 
       0x359, 0x35a, 0x7, 0x91, 0x2, 0x2, 0x35a, 0x47, 0x3, 0x2, 0x2, 0x2, 
       0x35b, 0x35d, 0x5, 0x4c, 0x27, 0x2, 0x35c, 0x35b, 0x3, 0x2, 0x2, 
       0x2, 0x35c, 0x35d, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x35e, 0x3, 0x2, 0x2, 
       0x2, 0x35e, 0x35f, 0x5, 0x13e, 0xa0, 0x2, 0x35f, 0x360, 0x7, 0x8c, 
       0x2, 0x2, 0x360, 0x361, 0x5, 0xce, 0x68, 0x2, 0x361, 0x49, 0x3, 0x2, 
       0x2, 0x2, 0x362, 0x367, 0x5, 0x48, 0x25, 0x2, 0x363, 0x364, 0x7, 
       0x92, 0x2, 0x2, 0x364, 0x366, 0x5, 0x48, 0x25, 0x2, 0x365, 0x363, 
       0x3, 0x2, 0x2, 0x2, 0x366, 0x369, 0x3, 0x2, 0x2, 0x2, 0x367, 0x365, 
       0x3, 0x2, 0x2, 0x2, 0x367, 0x368, 0x3, 0x2, 0x2, 0x2, 0x368, 0x4b, 
       0x3, 0x2, 0x2, 0x2, 0x369, 0x367, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x36b, 
       0x7, 0x20, 0x2, 0x2, 0x36b, 0x36c, 0x5, 0x13e, 0xa0, 0x2, 0x36c, 
       0x36d, 0x7, 0x6c, 0x2, 0x2, 0x36d, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x36e, 
       0x370, 0x5, 0x12a, 0x96, 0x2, 0x36f, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x36f, 
       0x370, 0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 0x3, 0x2, 0x2, 0x2, 0x371, 
       0x373, 0x7, 0x11, 0x2, 0x2, 0x372, 0x374, 0x5, 0x4a, 0x26, 0x2, 0x373, 
       0x372, 0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 0x3, 0x2, 0x2, 0x2, 0x374, 
       0x377, 0x3, 0x2, 0x2, 0x2, 0x375, 0x376, 0x7, 0x70, 0x2, 0x2, 0x376, 
       0x378, 0x5, 0x72, 0x3a, 0x2, 0x377, 0x375, 0x3, 0x2, 0x2, 0x2, 0x377, 
       0x378, 0x3, 0x2, 0x2, 0x2, 0x378, 0x379, 0x3, 0x2, 0x2, 0x2, 0x379, 
       0x37a, 0x7, 0x91, 0x2, 0x2, 0x37a, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x37b, 
       0x37d, 0x5, 0x12a, 0x96, 0x2, 0x37c, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37c, 
       0x37d, 0x3, 0x2, 0x2, 0x2, 0x37d, 0x37e, 0x3, 0x2, 0x2, 0x2, 0x37e, 
       0x37f, 0x7, 0x14, 0x2, 0x2, 0x37f, 0x380, 0x5, 0xce, 0x68, 0x2, 0x380, 
       0x382, 0x7, 0x2c, 0x2, 0x2, 0x381, 0x383, 0x5, 0x52, 0x2a, 0x2, 0x382, 
       0x381, 0x3, 0x2, 0x2, 0x2, 0x383, 0x384, 0x3, 0x2, 0x2, 0x2, 0x384, 
       0x382, 0x3, 0x2, 0x2, 0x2, 0x384, 0x385, 0x3, 0x2, 0x2, 0x2, 0x385, 
       0x386, 0x3, 0x2, 0x2, 0x2, 0x386, 0x387, 0x7, 0x1a, 0x2, 0x2, 0x387, 
       0x389, 0x7, 0x14, 0x2, 0x2, 0x388, 0x38a, 0x5, 0x100, 0x81, 0x2, 
       0x389, 0x388, 0x3, 0x2, 0x2, 0x2, 0x389, 0x38a, 0x3, 0x2, 0x2, 0x2, 
       0x38a, 0x38b, 0x3, 0x2, 0x2, 0x2, 0x38b, 0x38c, 0x7, 0x91, 0x2, 0x2, 
       0x38c, 0x51, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x38e, 0x7, 0x70, 0x2, 0x2, 
       0x38e, 0x38f, 0x5, 0x56, 0x2c, 0x2, 0x38f, 0x390, 0x7, 0x8c, 0x2, 
       0x2, 0x390, 0x391, 0x5, 0x1b2, 0xda, 0x2, 0x391, 0x53, 0x3, 0x2, 
       0x2, 0x2, 0x392, 0x397, 0x5, 0x100, 0x81, 0x2, 0x393, 0x397, 0x5, 
       0xa2, 0x52, 0x2, 0x394, 0x397, 0x5, 0x1ce, 0xe8, 0x2, 0x395, 0x397, 
       0x7, 0x41, 0x2, 0x2, 0x396, 0x392, 0x3, 0x2, 0x2, 0x2, 0x396, 0x393, 
       0x3, 0x2, 0x2, 0x2, 0x396, 0x394, 0x3, 0x2, 0x2, 0x2, 0x396, 0x395, 
       0x3, 0x2, 0x2, 0x2, 0x397, 0x55, 0x3, 0x2, 0x2, 0x2, 0x398, 0x39d, 
       0x5, 0x54, 0x2b, 0x2, 0x399, 0x39a, 0x7, 0xa0, 0x2, 0x2, 0x39a, 0x39c, 
       0x5, 0x54, 0x2b, 0x2, 0x39b, 0x399, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x39f, 
       0x3, 0x2, 0x2, 0x2, 0x39d, 0x39b, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 
       0x3, 0x2, 0x2, 0x2, 0x39e, 0x57, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x39d, 
       0x3, 0x2, 0x2, 0x2, 0x3a0, 0x3a1, 0x7, 0x20, 0x2, 0x2, 0x3a1, 0x3a5, 
       0x5, 0x5e, 0x30, 0x2, 0x3a2, 0x3a3, 0x5, 0x36, 0x1c, 0x2, 0x3a3, 
       0x3a4, 0x7, 0x91, 0x2, 0x2, 0x3a4, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a5, 
       0x3a2, 0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
       0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a9, 0x5, 0x38, 0x1d, 0x2, 0x3a8, 
       0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3a9, 
       0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3ab, 0x7, 0x1a, 0x2, 0x2, 0x3ab, 
       0x3ac, 0x7, 0x20, 0x2, 0x2, 0x3ac, 0x3ad, 0x7, 0x91, 0x2, 0x2, 0x3ad, 
       0x59, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3af, 0x7, 0x15, 0x2, 0x2, 0x3af, 
       0x3b1, 0x5, 0x100, 0x81, 0x2, 0x3b0, 0x3b2, 0x7, 0x2c, 0x2, 0x2, 
       0x3b1, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b1, 0x3b2, 0x3, 0x2, 0x2, 0x2, 
       0x3b2, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b3, 0x3b5, 0x5, 0xf0, 0x79, 
       0x2, 0x3b4, 0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3b5, 0x3, 0x2, 0x2, 
       0x2, 0x3b5, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3b6, 0x3b8, 0x5, 0x16c, 
       0xb7, 0x2, 0x3b7, 0x3b6, 0x3, 0x2, 0x2, 0x2, 0x3b7, 0x3b8, 0x3, 0x2, 
       0x2, 0x2, 0x3b8, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b9, 0x3ba, 0x7, 0x1a, 
       0x2, 0x2, 0x3ba, 0x3bc, 0x7, 0x15, 0x2, 0x2, 0x3bb, 0x3bd, 0x5, 0x100, 
       0x81, 0x2, 0x3bc, 0x3bb, 0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3bd, 0x3, 0x2, 
       0x2, 0x2, 0x3bd, 0x3be, 0x3, 0x2, 0x2, 0x2, 0x3be, 0x3bf, 0x7, 0x91, 
       0x2, 0x2, 0x3bf, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x3c0, 0x3c1, 0x5, 0x12a, 
       0x96, 0x2, 0x3c1, 0x3c3, 0x5, 0x10c, 0x87, 0x2, 0x3c2, 0x3c4, 0x5, 
       0xf4, 0x7b, 0x2, 0x3c3, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c3, 0x3c4, 
       0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3c7, 
       0x5, 0x170, 0xb9, 0x2, 0x3c6, 0x3c5, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c7, 
       0x3, 0x2, 0x2, 0x2, 0x3c7, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3c9, 
       0x7, 0x91, 0x2, 0x2, 0x3c9, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3cb, 
       0x5, 0x10e, 0x88, 0x2, 0x3cb, 0x3cc, 0x7, 0x98, 0x2, 0x2, 0x3cc, 
       0x3cd, 0x5, 0x13e, 0xa0, 0x2, 0x3cd, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x3ce, 
       0x3d1, 0x5, 0x22, 0x12, 0x2, 0x3cf, 0x3d1, 0x5, 0x196, 0xcc, 0x2, 
       0x3d0, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3cf, 0x3, 0x2, 0x2, 0x2, 
       0x3d1, 0x61, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3d5, 0x5, 0x24, 0x13, 0x2, 
       0x3d3, 0x3d5, 0x5, 0x198, 0xcd, 0x2, 0x3d4, 0x3d2, 0x3, 0x2, 0x2, 
       0x2, 0x3d4, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3d5, 0x63, 0x3, 0x2, 0x2, 
       0x2, 0x3d6, 0x3d8, 0x5, 0x12a, 0x96, 0x2, 0x3d7, 0x3d6, 0x3, 0x2, 
       0x2, 0x2, 0x3d7, 0x3d8, 0x3, 0x2, 0x2, 0x2, 0x3d8, 0x3da, 0x3, 0x2, 
       0x2, 0x2, 0x3d9, 0x3db, 0x7, 0x45, 0x2, 0x2, 0x3da, 0x3d9, 0x3, 0x2, 
       0x2, 0x2, 0x3da, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3dc, 0x3, 0x2, 
       0x2, 0x2, 0x3dc, 0x3dd, 0x5, 0x26, 0x14, 0x2, 0x3dd, 0x3de, 0x7, 
       0x91, 0x2, 0x2, 0x3de, 0x65, 0x3, 0x2, 0x2, 0x2, 0x3df, 0x3e1, 0x5, 
       0x12a, 0x96, 0x2, 0x3e0, 0x3df, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3e1, 
       0x3, 0x2, 0x2, 0x2, 0x3e1, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e2, 0x3e4, 
       0x7, 0x11, 0x2, 0x2, 0x3e3, 0x3e5, 0x5, 0x4a, 0x26, 0x2, 0x3e4, 0x3e3, 
       0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3e5, 0x3e7, 
       0x3, 0x2, 0x2, 0x2, 0x3e6, 0x3e8, 0x5, 0x1ae, 0xd8, 0x2, 0x3e7, 0x3e6, 
       0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e8, 0x3, 0x2, 0x2, 0x2, 0x3e8, 0x3eb, 
       0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3ea, 0x7, 0x70, 0x2, 0x2, 0x3ea, 0x3ec, 
       0x5, 0x72, 0x3a, 0x2, 0x3eb, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3ec, 
       0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ed, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3ee, 
       0x7, 0x91, 0x2, 0x2, 0x3ee, 0x67, 0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3f1, 
       0x5, 0x12a, 0x96, 0x2, 0x3f0, 0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3f1, 
       0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0x3f2, 0x3f4, 
       0x7, 0x45, 0x2, 0x2, 0x3f3, 0x3f2, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f4, 
       0x3, 0x2, 0x2, 0x2, 0x3f4, 0x3f5, 0x3, 0x2, 0x2, 0x2, 0x3f5, 0x3f6, 
       0x5, 0x17c, 0xbf, 0x2, 0x3f6, 0x3f7, 0x7, 0x91, 0x2, 0x2, 0x3f7, 
       0x69, 0x3, 0x2, 0x2, 0x2, 0x3f8, 0x3fa, 0x5, 0x12a, 0x96, 0x2, 0x3f9, 
       0x3f8, 0x3, 0x2, 0x2, 0x2, 0x3f9, 0x3fa, 0x3, 0x2, 0x2, 0x2, 0x3fa, 
       0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fb, 0x3fd, 0x7, 0x45, 0x2, 0x2, 0x3fc, 
       0x3fb, 0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3fd, 
       0x3fe, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x40e, 0x5, 0x6c, 0x37, 0x2, 0x3ff, 
       0x401, 0x5, 0x12a, 0x96, 0x2, 0x400, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0x400, 
       0x401, 0x3, 0x2, 0x2, 0x2, 0x401, 0x403, 0x3, 0x2, 0x2, 0x2, 0x402, 
       0x404, 0x7, 0x45, 0x2, 0x2, 0x403, 0x402, 0x3, 0x2, 0x2, 0x2, 0x403, 
       0x404, 0x3, 0x2, 0x2, 0x2, 0x404, 0x405, 0x3, 0x2, 0x2, 0x2, 0x405, 
       0x40e, 0x5, 0x6e, 0x38, 0x2, 0x406, 0x408, 0x5, 0x12a, 0x96, 0x2, 
       0x407, 0x406, 0x3, 0x2, 0x2, 0x2, 0x407, 0x408, 0x3, 0x2, 0x2, 0x2, 
       0x408, 0x40a, 0x3, 0x2, 0x2, 0x2, 0x409, 0x40b, 0x7, 0x45, 0x2, 0x2, 
       0x40a, 0x409, 0x3, 0x2, 0x2, 0x2, 0x40a, 0x40b, 0x3, 0x2, 0x2, 0x2, 
       0x40b, 0x40c, 0x3, 0x2, 0x2, 0x2, 0x40c, 0x40e, 0x5, 0x70, 0x39, 
       0x2, 0x40d, 0x3f9, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x400, 0x3, 0x2, 0x2, 
       0x2, 0x40d, 0x407, 0x3, 0x2, 0x2, 0x2, 0x40e, 0x6b, 0x3, 0x2, 0x2, 
       0x2, 0x40f, 0x410, 0x5, 0x200, 0x101, 0x2, 0x410, 0x411, 0x7, 0x8a, 
       0x2, 0x2, 0x411, 0x412, 0x5, 0x158, 0xad, 0x2, 0x412, 0x413, 0x5, 
       0x224, 0x113, 0x2, 0x413, 0x414, 0x7, 0x91, 0x2, 0x2, 0x414, 0x6d, 
       0x3, 0x2, 0x2, 0x2, 0x415, 0x416, 0x5, 0x200, 0x101, 0x2, 0x416, 
       0x417, 0x7, 0x8a, 0x2, 0x2, 0x417, 0x418, 0x5, 0x158, 0xad, 0x2, 
       0x418, 0x419, 0x5, 0x7c, 0x3f, 0x2, 0x419, 0x41a, 0x7, 0x91, 0x2, 
       0x2, 0x41a, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x41b, 0x41c, 0x7, 0x6f, 0x2, 
       0x2, 0x41c, 0x41d, 0x5, 0xce, 0x68, 0x2, 0x41d, 0x41e, 0x7, 0x57, 
       0x2, 0x2, 0x41e, 0x420, 0x5, 0x200, 0x101, 0x2, 0x41f, 0x421, 0x7, 
       0xa3, 0x2, 0x2, 0x420, 0x41f, 0x3, 0x2, 0x2, 0x2, 0x420, 0x421, 0x3, 
       0x2, 0x2, 0x2, 0x421, 0x422, 0x3, 0x2, 0x2, 0x2, 0x422, 0x423, 0x7, 
       0x8a, 0x2, 0x2, 0x423, 0x424, 0x5, 0x158, 0xad, 0x2, 0x424, 0x425, 
       0x5, 0x1ac, 0xd7, 0x2, 0x425, 0x426, 0x7, 0x91, 0x2, 0x2, 0x426, 
       0x71, 0x3, 0x2, 0x2, 0x2, 0x427, 0x428, 0x5, 0xce, 0x68, 0x2, 0x428, 
       0x73, 0x3, 0x2, 0x2, 0x2, 0x429, 0x42a, 0x7, 0x6b, 0x2, 0x2, 0x42a, 
       0x42b, 0x5, 0x72, 0x3a, 0x2, 0x42b, 0x75, 0x3, 0x2, 0x2, 0x2, 0x42c, 
       0x42f, 0x5, 0x78, 0x3d, 0x2, 0x42d, 0x42f, 0x5, 0x7a, 0x3e, 0x2, 
       0x42e, 0x42c, 0x3, 0x2, 0x2, 0x2, 0x42e, 0x42d, 0x3, 0x2, 0x2, 0x2, 
       0x42f, 0x77, 0x3, 0x2, 0x2, 0x2, 0x430, 0x431, 0x5, 0x200, 0x101, 
       0x2, 0x431, 0x433, 0x7, 0x8a, 0x2, 0x2, 0x432, 0x434, 0x5, 0x96, 
       0x4c, 0x2, 0x433, 0x432, 0x3, 0x2, 0x2, 0x2, 0x433, 0x434, 0x3, 0x2, 
       0x2, 0x2, 0x434, 0x435, 0x3, 0x2, 0x2, 0x2, 0x435, 0x436, 0x5, 0x7c, 
       0x3f, 0x2, 0x436, 0x79, 0x3, 0x2, 0x2, 0x2, 0x437, 0x438, 0x5, 0x200, 
       0x101, 0x2, 0x438, 0x439, 0x7, 0x8a, 0x2, 0x2, 0x439, 0x43b, 0x7, 
       0x21, 0x2, 0x2, 0x43a, 0x43c, 0x5, 0x1c4, 0xe3, 0x2, 0x43b, 0x43a, 
       0x3, 0x2, 0x2, 0x2, 0x43b, 0x43c, 0x3, 0x2, 0x2, 0x2, 0x43c, 0x43d, 
       0x3, 0x2, 0x2, 0x2, 0x43d, 0x43e, 0x5, 0x7e, 0x40, 0x2, 0x43e, 0x7b, 
       0x3, 0x2, 0x2, 0x2, 0x43f, 0x440, 0x5, 0x224, 0x113, 0x2, 0x440, 
       0x441, 0x7, 0x70, 0x2, 0x2, 0x441, 0x449, 0x5, 0x72, 0x3a, 0x2, 0x442, 
       0x443, 0x7, 0x1c, 0x2, 0x2, 0x443, 0x444, 0x5, 0x224, 0x113, 0x2, 
       0x444, 0x445, 0x7, 0x70, 0x2, 0x2, 0x445, 0x446, 0x5, 0x72, 0x3a, 
       0x2, 0x446, 0x448, 0x3, 0x2, 0x2, 0x2, 0x447, 0x442, 0x3, 0x2, 0x2, 
       0x2, 0x448, 0x44b, 0x3, 0x2, 0x2, 0x2, 0x449, 0x447, 0x3, 0x2, 0x2, 
       0x2, 0x449, 0x44a, 0x3, 0x2, 0x2, 0x2, 0x44a, 0x44e, 0x3, 0x2, 0x2, 
       0x2, 0x44b, 0x449, 0x3, 0x2, 0x2, 0x2, 0x44c, 0x44d, 0x7, 0x1c, 0x2, 
       0x2, 0x44d, 0x44f, 0x5, 0x224, 0x113, 0x2, 0x44e, 0x44c, 0x3, 0x2, 
       0x2, 0x2, 0x44e, 0x44f, 0x3, 0x2, 0x2, 0x2, 0x44f, 0x7d, 0x3, 0x2, 
       0x2, 0x2, 0x450, 0x451, 0x5, 0xce, 0x68, 0x2, 0x451, 0x452, 0x7, 
       0x70, 0x2, 0x2, 0x452, 0x45a, 0x5, 0x72, 0x3a, 0x2, 0x453, 0x454, 
       0x7, 0x1c, 0x2, 0x2, 0x454, 0x455, 0x5, 0xce, 0x68, 0x2, 0x455, 0x456, 
       0x7, 0x70, 0x2, 0x2, 0x456, 0x457, 0x5, 0x72, 0x3a, 0x2, 0x457, 0x459, 
       0x3, 0x2, 0x2, 0x2, 0x458, 0x453, 0x3, 0x2, 0x2, 0x2, 0x459, 0x45c, 
       0x3, 0x2, 0x2, 0x2, 0x45a, 0x458, 0x3, 0x2, 0x2, 0x2, 0x45a, 0x45b, 
       0x3, 0x2, 0x2, 0x2, 0x45b, 0x45f, 0x3, 0x2, 0x2, 0x2, 0x45c, 0x45a, 
       0x3, 0x2, 0x2, 0x2, 0x45d, 0x45e, 0x7, 0x1c, 0x2, 0x2, 0x45e, 0x460, 
       0x5, 0xce, 0x68, 0x2, 0x45f, 0x45d, 0x3, 0x2, 0x2, 0x2, 0x45f, 0x460, 
       0x3, 0x2, 0x2, 0x2, 0x460, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x461, 0x462, 
       0x7, 0x16, 0x2, 0x2, 0x462, 0x463, 0x5, 0x100, 0x81, 0x2, 0x463, 
       0x464, 0x7, 0x3d, 0x2, 0x2, 0x464, 0x465, 0x5, 0x13e, 0xa0, 0x2, 
       0x465, 0x466, 0x7, 0x2c, 0x2, 0x2, 0x466, 0x467, 0x5, 0x84, 0x43, 
       0x2, 0x467, 0x468, 0x5, 0x38, 0x1d, 0x2, 0x468, 0x46a, 0x7, 0x1a, 
       0x2, 0x2, 0x469, 0x46b, 0x7, 0x16, 0x2, 0x2, 0x46a, 0x469, 0x3, 0x2, 
       0x2, 0x2, 0x46a, 0x46b, 0x3, 0x2, 0x2, 0x2, 0x46b, 0x46d, 0x3, 0x2, 
       0x2, 0x2, 0x46c, 0x46e, 0x5, 0x100, 0x81, 0x2, 0x46d, 0x46c, 0x3, 
       0x2, 0x2, 0x2, 0x46d, 0x46e, 0x3, 0x2, 0x2, 0x2, 0x46e, 0x46f, 0x3, 
       0x2, 0x2, 0x2, 0x46f, 0x470, 0x7, 0x91, 0x2, 0x2, 0x470, 0x81, 0x3, 
       0x2, 0x2, 0x2, 0x471, 0x475, 0x5, 0x216, 0x10c, 0x2, 0x472, 0x475, 
       0x5, 0x32, 0x1a, 0x2, 0x473, 0x475, 0x5, 0xfa, 0x7e, 0x2, 0x474, 
       0x471, 0x3, 0x2, 0x2, 0x2, 0x474, 0x472, 0x3, 0x2, 0x2, 0x2, 0x474, 
       0x473, 0x3, 0x2, 0x2, 0x2, 0x475, 0x83, 0x3, 0x2, 0x2, 0x2, 0x476, 
       0x478, 0x5, 0x82, 0x42, 0x2, 0x477, 0x476, 0x3, 0x2, 0x2, 0x2, 0x478, 
       0x47b, 0x3, 0x2, 0x2, 0x2, 0x479, 0x477, 0x3, 0x2, 0x2, 0x2, 0x479, 
       0x47a, 0x3, 0x2, 0x2, 0x2, 0x47a, 0x85, 0x3, 0x2, 0x2, 0x2, 0x47b, 
       0x479, 0x3, 0x2, 0x2, 0x2, 0x47c, 0x47f, 0x5, 0x38, 0x1d, 0x2, 0x47d, 
       0x47f, 0x5, 0x58, 0x2d, 0x2, 0x47e, 0x47c, 0x3, 0x2, 0x2, 0x2, 0x47e, 
       0x47d, 0x3, 0x2, 0x2, 0x2, 0x47f, 0x87, 0x3, 0x2, 0x2, 0x2, 0x480, 
       0x481, 0x7, 0x20, 0x2, 0x2, 0x481, 0x482, 0x5, 0x5e, 0x30, 0x2, 0x482, 
       0x483, 0x5, 0x36, 0x1c, 0x2, 0x483, 0x484, 0x7, 0x91, 0x2, 0x2, 0x484, 
       0x89, 0x3, 0x2, 0x2, 0x2, 0x485, 0x486, 0x7, 0x17, 0x2, 0x2, 0x486, 
       0x487, 0x5, 0x102, 0x82, 0x2, 0x487, 0x488, 0x7, 0x98, 0x2, 0x2, 
       0x488, 0x48b, 0x5, 0x1fc, 0xff, 0x2, 0x489, 0x48a, 0x7, 0x8e, 0x2, 
       0x2, 0x48a, 0x48c, 0x5, 0xce, 0x68, 0x2, 0x48b, 0x489, 0x3, 0x2, 
       0x2, 0x2, 0x48b, 0x48c, 0x3, 0x2, 0x2, 0x2, 0x48c, 0x48d, 0x3, 0x2, 
       0x2, 0x2, 0x48d, 0x48e, 0x7, 0x91, 0x2, 0x2, 0x48e, 0x8b, 0x3, 0x2, 
       0x2, 0x2, 0x48f, 0x490, 0x7, 0xb, 0x2, 0x2, 0x490, 0x491, 0x5, 0x106, 
       0x84, 0x2, 0x491, 0x492, 0x7, 0x3d, 0x2, 0x2, 0x492, 0x493, 0x5, 
       0x1fc, 0xff, 0x2, 0x493, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x494, 0x495, 
       0x7, 0xb, 0x2, 0x2, 0x495, 0x496, 0x5, 0x106, 0x84, 0x2, 0x496, 0x497, 
       0x7, 0x3d, 0x2, 0x2, 0x497, 0x498, 0x5, 0x1e6, 0xf4, 0x2, 0x498, 
       0x8f, 0x3, 0x2, 0x2, 0x2, 0x499, 0x49c, 0x5, 0x194, 0xcb, 0x2, 0x49a, 
       0x49c, 0x5, 0x106, 0x84, 0x2, 0x49b, 0x499, 0x3, 0x2, 0x2, 0x2, 0x49b, 
       0x49a, 0x3, 0x2, 0x2, 0x2, 0x49c, 0x91, 0x3, 0x2, 0x2, 0x2, 0x49d, 
       0x49f, 0x5, 0x94, 0x4b, 0x2, 0x49e, 0x49d, 0x3, 0x2, 0x2, 0x2, 0x49f, 
       0x4a2, 0x3, 0x2, 0x2, 0x2, 0x4a0, 0x49e, 0x3, 0x2, 0x2, 0x2, 0x4a0, 
       0x4a1, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0x93, 0x3, 0x2, 0x2, 0x2, 0x4a2, 
       0x4a0, 0x3, 0x2, 0x2, 0x2, 0x4a3, 0x4a6, 0x5, 0x12c, 0x97, 0x2, 0x4a4, 
       0x4a6, 0x5, 0x216, 0x10c, 0x2, 0x4a5, 0x4a3, 0x3, 0x2, 0x2, 0x2, 
       0x4a5, 0x4a4, 0x3, 0x2, 0x2, 0x2, 0x4a6, 0x95, 0x3, 0x2, 0x2, 0x2, 
       0x4a7, 0x4ae, 0x7, 0x67, 0x2, 0x2, 0x4a8, 0x4a9, 0x7, 0x4d, 0x2, 
       0x2, 0x4a9, 0x4ab, 0x5, 0xce, 0x68, 0x2, 0x4aa, 0x4a8, 0x3, 0x2, 
       0x2, 0x2, 0x4aa, 0x4ab, 0x3, 0x2, 0x2, 0x2, 0x4ab, 0x4ac, 0x3, 0x2, 
       0x2, 0x2, 0x4ac, 0x4ae, 0x7, 0x2a, 0x2, 0x2, 0x4ad, 0x4a7, 0x3, 0x2, 
       0x2, 0x2, 0x4ad, 0x4aa, 0x3, 0x2, 0x2, 0x2, 0x4ae, 0x97, 0x3, 0x2, 
       0x2, 0x2, 0x4af, 0x4b1, 0x5, 0x9a, 0x4e, 0x2, 0x4b0, 0x4af, 0x3, 
       0x2, 0x2, 0x2, 0x4b1, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4b2, 0x4b0, 0x3, 
       0x2, 0x2, 0x2, 0x4b2, 0x4b3, 0x3, 0x2, 0x2, 0x2, 0x4b3, 0x4b5, 0x3, 
       0x2, 0x2, 0x2, 0x4b4, 0x4b2, 0x3, 0x2, 0x2, 0x2, 0x4b5, 0x4b6, 0x7, 
       0x2, 0x2, 0x3, 0x4b6, 0x99, 0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4b8, 0x5, 
       0x92, 0x4a, 0x2, 0x4b8, 0x4b9, 0x5, 0x12e, 0x98, 0x2, 0x4b9, 0x9b, 
       0x3, 0x2, 0x2, 0x2, 0x4ba, 0x4bd, 0x5, 0x100, 0x81, 0x2, 0x4bb, 0x4bd, 
       0x7, 0x86, 0x2, 0x2, 0x4bc, 0x4ba, 0x3, 0x2, 0x2, 0x2, 0x4bc, 0x4bb, 
       0x3, 0x2, 0x2, 0x2, 0x4bd, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x4be, 0x4bf, 
       0x9, 0x4, 0x2, 0x2, 0x4bf, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4c1, 
       0x7, 0x18, 0x2, 0x2, 0x4c1, 0x4c2, 0x5, 0xfe, 0x80, 0x2, 0x4c2, 0x4c3, 
       0x7, 0x6, 0x2, 0x2, 0x4c3, 0x4c4, 0x5, 0xce, 0x68, 0x2, 0x4c4, 0x4c5, 
       0x7, 0x91, 0x2, 0x2, 0x4c5, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x4c6, 0x4c9, 
       0x5, 0x190, 0xc9, 0x2, 0x4c7, 0x4c9, 0x5, 0x1fc, 0xff, 0x2, 0x4c8, 
       0x4c6, 0x3, 0x2, 0x2, 0x2, 0x4c8, 0x4c7, 0x3, 0x2, 0x2, 0x2, 0x4c9, 
       0xa3, 0x3, 0x2, 0x2, 0x2, 0x4ca, 0x4cb, 0x5, 0x56, 0x2c, 0x2, 0x4cb, 
       0x4cc, 0x7, 0x8c, 0x2, 0x2, 0x4cc, 0x4ce, 0x3, 0x2, 0x2, 0x2, 0x4cd, 
       0x4ca, 0x3, 0x2, 0x2, 0x2, 0x4cd, 0x4ce, 0x3, 0x2, 0x2, 0x2, 0x4ce, 
       0x4cf, 0x3, 0x2, 0x2, 0x2, 0x4cf, 0x4d0, 0x5, 0xce, 0x68, 0x2, 0x4d0, 
       0xa5, 0x3, 0x2, 0x2, 0x2, 0x4d1, 0x4d2, 0x5, 0x102, 0x82, 0x2, 0x4d2, 
       0x4d3, 0x7, 0x98, 0x2, 0x2, 0x4d3, 0x4d4, 0x5, 0xaa, 0x56, 0x2, 0x4d4, 
       0x4d5, 0x7, 0x91, 0x2, 0x2, 0x4d5, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x4d6, 
       0x4d7, 0x5, 0x1e6, 0xf4, 0x2, 0x4d7, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x4d8, 
       0x4d9, 0x5, 0x1fc, 0xff, 0x2, 0x4d9, 0xab, 0x3, 0x2, 0x2, 0x2, 0x4da, 
       0x4db, 0x7, 0x1b, 0x2, 0x2, 0x4db, 0x4e0, 0x5, 0x13e, 0xa0, 0x2, 
       0x4dc, 0x4dd, 0x7, 0x94, 0x2, 0x2, 0x4dd, 0x4de, 0x5, 0x100, 0x81, 
       0x2, 0x4de, 0x4df, 0x7, 0x95, 0x2, 0x2, 0x4df, 0x4e1, 0x3, 0x2, 0x2, 
       0x2, 0x4e0, 0x4dc, 0x3, 0x2, 0x2, 0x2, 0x4e0, 0x4e1, 0x3, 0x2, 0x2, 
       0x2, 0x4e1, 0x4e6, 0x3, 0x2, 0x2, 0x2, 0x4e2, 0x4e3, 0x7, 0x16, 0x2, 
       0x2, 0x4e3, 0x4e6, 0x5, 0x13e, 0xa0, 0x2, 0x4e4, 0x4e6, 0x7, 0x3f, 
       0x2, 0x2, 0x4e5, 0x4da, 0x3, 0x2, 0x2, 0x2, 0x4e5, 0x4e2, 0x3, 0x2, 
       0x2, 0x2, 0x4e5, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4e6, 0xad, 0x3, 0x2, 
       0x2, 0x2, 0x4e7, 0x4e8, 0x9, 0x5, 0x2, 0x2, 0x4e8, 0xaf, 0x3, 0x2, 
       0x2, 0x2, 0x4e9, 0x4eb, 0x5, 0xae, 0x58, 0x2, 0x4ea, 0x4ec, 0x7, 
       0x8f, 0x2, 0x2, 0x4eb, 0x4ea, 0x3, 0x2, 0x2, 0x2, 0x4eb, 0x4ec, 0x3, 
       0x2, 0x2, 0x2, 0x4ec, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x4ed, 0x4f2, 0x5, 
       0xb0, 0x59, 0x2, 0x4ee, 0x4ef, 0x7, 0x92, 0x2, 0x2, 0x4ef, 0x4f1, 
       0x5, 0xb0, 0x59, 0x2, 0x4f0, 0x4ee, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4f4, 
       0x3, 0x2, 0x2, 0x2, 0x4f2, 0x4f0, 0x3, 0x2, 0x2, 0x2, 0x4f2, 0x4f3, 
       0x3, 0x2, 0x2, 0x2, 0x4f3, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x4f4, 0x4f2, 
       0x3, 0x2, 0x2, 0x2, 0x4f5, 0x4f6, 0x7, 0x1b, 0x2, 0x2, 0x4f6, 0x4f7, 
       0x5, 0x100, 0x81, 0x2, 0x4f7, 0x4f8, 0x7, 0x2c, 0x2, 0x2, 0x4f8, 
       0x4f9, 0x5, 0xbc, 0x5f, 0x2, 0x4f9, 0x4fc, 0x5, 0xb8, 0x5d, 0x2, 
       0x4fa, 0x4fb, 0x7, 0xe, 0x2, 0x2, 0x4fb, 0x4fd, 0x5, 0xc4, 0x63, 
       0x2, 0x4fc, 0x4fa, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fd, 0x3, 0x2, 0x2, 
       0x2, 0x4fd, 0x4fe, 0x3, 0x2, 0x2, 0x2, 0x4fe, 0x500, 0x7, 0x1a, 0x2, 
       0x2, 0x4ff, 0x501, 0x7, 0x1b, 0x2, 0x2, 0x500, 0x4ff, 0x3, 0x2, 0x2, 
       0x2, 0x500, 0x501, 0x3, 0x2, 0x2, 0x2, 0x501, 0x503, 0x3, 0x2, 0x2, 
       0x2, 0x502, 0x504, 0x5, 0x100, 0x81, 0x2, 0x503, 0x502, 0x3, 0x2, 
       0x2, 0x2, 0x503, 0x504, 0x3, 0x2, 0x2, 0x2, 0x504, 0x505, 0x3, 0x2, 
       0x2, 0x2, 0x505, 0x506, 0x7, 0x91, 0x2, 0x2, 0x506, 0xb5, 0x3, 0x2, 
       0x2, 0x2, 0x507, 0x51c, 0x5, 0x1ea, 0xf6, 0x2, 0x508, 0x51c, 0x5, 
       0x1e8, 0xf5, 0x2, 0x509, 0x51c, 0x5, 0x20e, 0x108, 0x2, 0x50a, 0x51c, 
       0x5, 0x1fa, 0xfe, 0x2, 0x50b, 0x51c, 0x5, 0x8a, 0x46, 0x2, 0x50c, 
       0x51c, 0x5, 0x1c6, 0xe4, 0x2, 0x50d, 0x51c, 0x5, 0x220, 0x111, 0x2, 
       0x50e, 0x51c, 0x5, 0xd4, 0x6b, 0x2, 0x50f, 0x51c, 0x5, 0x12, 0xa, 
       0x2, 0x510, 0x51c, 0x5, 0x2e, 0x18, 0x2, 0x511, 0x51c, 0x5, 0x32, 
       0x1a, 0x2, 0x512, 0x51c, 0x5, 0xa0, 0x51, 0x2, 0x513, 0x51c, 0x5, 
       0x1e2, 0xf2, 0x2, 0x514, 0x51c, 0x5, 0x216, 0x10c, 0x2, 0x515, 0x51c, 
       0x5, 0xfc, 0x7f, 0x2, 0x516, 0x51c, 0x5, 0xfa, 0x7e, 0x2, 0x517, 
       0x51c, 0x5, 0x14c, 0xa7, 0x2, 0x518, 0x51c, 0x5, 0x1e4, 0xf3, 0x2, 
       0x519, 0x51c, 0x5, 0x18a, 0xc6, 0x2, 0x51a, 0x51c, 0x5, 0x206, 0x104, 
       0x2, 0x51b, 0x507, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x508, 0x3, 0x2, 0x2, 
       0x2, 0x51b, 0x509, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x50a, 0x3, 0x2, 0x2, 
       0x2, 0x51b, 0x50b, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x50c, 0x3, 0x2, 0x2, 
       0x2, 0x51b, 0x50d, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x50e, 0x3, 0x2, 0x2, 
       0x2, 0x51b, 0x50f, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x510, 0x3, 0x2, 0x2, 
       0x2, 0x51b, 0x511, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x512, 0x3, 0x2, 0x2, 
       0x2, 0x51b, 0x513, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x514, 0x3, 0x2, 0x2, 
       0x2, 0x51b, 0x515, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x516, 0x3, 0x2, 0x2, 
       0x2, 0x51b, 0x517, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x518, 0x3, 0x2, 0x2, 
       0x2, 0x51b, 0x519, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x51a, 0x3, 0x2, 0x2, 
       0x2, 0x51c, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x51d, 0x51f, 0x5, 0xb6, 0x5c, 
       0x2, 0x51e, 0x51d, 0x3, 0x2, 0x2, 0x2, 0x51f, 0x522, 0x3, 0x2, 0x2, 
       0x2, 0x520, 0x51e, 0x3, 0x2, 0x2, 0x2, 0x520, 0x521, 0x3, 0x2, 0x2, 
       0x2, 0x521, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x522, 0x520, 0x3, 0x2, 0x2, 
       0x2, 0x523, 0x525, 0x5, 0xc6, 0x64, 0x2, 0x524, 0x526, 0x5, 0x1cc, 
       0xe7, 0x2, 0x525, 0x524, 0x3, 0x2, 0x2, 0x2, 0x525, 0x526, 0x3, 0x2, 
       0x2, 0x2, 0x526, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x527, 0x529, 0x5, 0xf0, 
       0x79, 0x2, 0x528, 0x527, 0x3, 0x2, 0x2, 0x2, 0x528, 0x529, 0x3, 0x2, 
       0x2, 0x2, 0x529, 0x52b, 0x3, 0x2, 0x2, 0x2, 0x52a, 0x52c, 0x5, 0x16c, 
       0xb7, 0x2, 0x52b, 0x52a, 0x3, 0x2, 0x2, 0x2, 0x52b, 0x52c, 0x3, 0x2, 
       0x2, 0x2, 0x52c, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x52d, 0x532, 0x5, 0xba, 
       0x5e, 0x2, 0x52e, 0x52f, 0x7, 0x92, 0x2, 0x2, 0x52f, 0x531, 0x5, 
       0xba, 0x5e, 0x2, 0x530, 0x52e, 0x3, 0x2, 0x2, 0x2, 0x531, 0x534, 
       0x3, 0x2, 0x2, 0x2, 0x532, 0x530, 0x3, 0x2, 0x2, 0x2, 0x532, 0x533, 
       0x3, 0x2, 0x2, 0x2, 0x533, 0x538, 0x3, 0x2, 0x2, 0x2, 0x534, 0x532, 
       0x3, 0x2, 0x2, 0x2, 0x535, 0x538, 0x7, 0x41, 0x2, 0x2, 0x536, 0x538, 
       0x7, 0x8, 0x2, 0x2, 0x537, 0x52d, 0x3, 0x2, 0x2, 0x2, 0x537, 0x535, 
       0x3, 0x2, 0x2, 0x2, 0x537, 0x536, 0x3, 0x2, 0x2, 0x2, 0x538, 0xbf, 
       0x3, 0x2, 0x2, 0x2, 0x539, 0x53a, 0x5, 0xbe, 0x60, 0x2, 0x53a, 0x53b, 
       0x7, 0x98, 0x2, 0x2, 0x53b, 0x53c, 0x5, 0xae, 0x58, 0x2, 0x53c, 0xc1, 
       0x3, 0x2, 0x2, 0x2, 0x53d, 0x541, 0x5, 0x64, 0x33, 0x2, 0x53e, 0x541, 
       0x5, 0x184, 0xc3, 0x2, 0x53f, 0x541, 0x5, 0x68, 0x35, 0x2, 0x540, 
       0x53d, 0x3, 0x2, 0x2, 0x2, 0x540, 0x53e, 0x3, 0x2, 0x2, 0x2, 0x540, 
       0x53f, 0x3, 0x2, 0x2, 0x2, 0x541, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x542, 
       0x544, 0x5, 0xc2, 0x62, 0x2, 0x543, 0x542, 0x3, 0x2, 0x2, 0x2, 0x544, 
       0x547, 0x3, 0x2, 0x2, 0x2, 0x545, 0x543, 0x3, 0x2, 0x2, 0x2, 0x545, 
       0x546, 0x3, 0x2, 0x2, 0x2, 0x546, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x547, 
       0x545, 0x3, 0x2, 0x2, 0x2, 0x548, 0x54c, 0x5, 0x100, 0x81, 0x2, 0x549, 
       0x54c, 0x7, 0x85, 0x2, 0x2, 0x54a, 0x54c, 0x7, 0x86, 0x2, 0x2, 0x54b, 
       0x548, 0x3, 0x2, 0x2, 0x2, 0x54b, 0x549, 0x3, 0x2, 0x2, 0x2, 0x54b, 
       0x54a, 0x3, 0x2, 0x2, 0x2, 0x54c, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x54d, 
       0x550, 0x5, 0x100, 0x81, 0x2, 0x54e, 0x550, 0x7, 0x85, 0x2, 0x2, 
       0x54f, 0x54d, 0x3, 0x2, 0x2, 0x2, 0x54f, 0x54e, 0x3, 0x2, 0x2, 0x2, 
       0x550, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x551, 0x552, 0x7, 0x94, 0x2, 0x2, 
       0x552, 0x557, 0x5, 0xc8, 0x65, 0x2, 0x553, 0x554, 0x7, 0x92, 0x2, 
       0x2, 0x554, 0x556, 0x5, 0xc8, 0x65, 0x2, 0x555, 0x553, 0x3, 0x2, 
       0x2, 0x2, 0x556, 0x559, 0x3, 0x2, 0x2, 0x2, 0x557, 0x555, 0x3, 0x2, 
       0x2, 0x2, 0x557, 0x558, 0x3, 0x2, 0x2, 0x2, 0x558, 0x55a, 0x3, 0x2, 
       0x2, 0x2, 0x559, 0x557, 0x3, 0x2, 0x2, 0x2, 0x55a, 0x55b, 0x7, 0x95, 
       0x2, 0x2, 0x55b, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x55c, 0x55e, 0x5, 0x12a, 
       0x96, 0x2, 0x55d, 0x55c, 0x3, 0x2, 0x2, 0x2, 0x55d, 0x55e, 0x3, 0x2, 
       0x2, 0x2, 0x55e, 0x55f, 0x3, 0x2, 0x2, 0x2, 0x55f, 0x561, 0x7, 0x1e, 
       0x2, 0x2, 0x560, 0x562, 0x5, 0x100, 0x81, 0x2, 0x561, 0x560, 0x3, 
       0x2, 0x2, 0x2, 0x561, 0x562, 0x3, 0x2, 0x2, 0x2, 0x562, 0x565, 0x3, 
       0x2, 0x2, 0x2, 0x563, 0x564, 0x7, 0x70, 0x2, 0x2, 0x564, 0x566, 0x5, 
       0x72, 0x3a, 0x2, 0x565, 0x563, 0x3, 0x2, 0x2, 0x2, 0x565, 0x566, 
       0x3, 0x2, 0x2, 0x2, 0x566, 0x567, 0x3, 0x2, 0x2, 0x2, 0x567, 0x568, 
       0x7, 0x91, 0x2, 0x2, 0x568, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x569, 0x56a, 
       0x7, 0xa4, 0x2, 0x2, 0x56a, 0x56d, 0x5, 0x172, 0xba, 0x2, 0x56b, 
       0x56d, 0x5, 0xd0, 0x69, 0x2, 0x56c, 0x569, 0x3, 0x2, 0x2, 0x2, 0x56c, 
       0x56b, 0x3, 0x2, 0x2, 0x2, 0x56d, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x56e, 
       0x574, 0x5, 0x19a, 0xce, 0x2, 0x56f, 0x570, 0x5, 0x136, 0x9c, 0x2, 
       0x570, 0x571, 0x5, 0x19a, 0xce, 0x2, 0x571, 0x573, 0x3, 0x2, 0x2, 
       0x2, 0x572, 0x56f, 0x3, 0x2, 0x2, 0x2, 0x573, 0x576, 0x3, 0x2, 0x2, 
       0x2, 0x574, 0x572, 0x3, 0x2, 0x2, 0x2, 0x574, 0x575, 0x3, 0x2, 0x2, 
       0x2, 0x575, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x576, 0x574, 0x3, 0x2, 0x2, 
       0x2, 0x577, 0x57a, 0x5, 0x172, 0xba, 0x2, 0x578, 0x579, 0x7, 0x88, 
       0x2, 0x2, 0x579, 0x57b, 0x5, 0x172, 0xba, 0x2, 0x57a, 0x578, 0x3, 
       0x2, 0x2, 0x2, 0x57a, 0x57b, 0x3, 0x2, 0x2, 0x2, 0x57b, 0x581, 0x3, 
       0x2, 0x2, 0x2, 0x57c, 0x57d, 0x7, 0x3, 0x2, 0x2, 0x57d, 0x581, 0x5, 
       0x172, 0xba, 0x2, 0x57e, 0x57f, 0x7, 0x3b, 0x2, 0x2, 0x57f, 0x581, 
       0x5, 0x172, 0xba, 0x2, 0x580, 0x577, 0x3, 0x2, 0x2, 0x2, 0x580, 0x57c, 
       0x3, 0x2, 0x2, 0x2, 0x580, 0x57e, 0x3, 0x2, 0x2, 0x2, 0x581, 0xd3, 
       0x3, 0x2, 0x2, 0x2, 0x582, 0x583, 0x7, 0x1f, 0x2, 0x2, 0x583, 0x584, 
       0x5, 0x102, 0x82, 0x2, 0x584, 0x585, 0x7, 0x98, 0x2, 0x2, 0x585, 
       0x587, 0x5, 0x1fc, 0xff, 0x2, 0x586, 0x588, 0x5, 0xd8, 0x6d, 0x2, 
       0x587, 0x586, 0x3, 0x2, 0x2, 0x2, 0x587, 0x588, 0x3, 0x2, 0x2, 0x2, 
       0x588, 0x589, 0x3, 0x2, 0x2, 0x2, 0x589, 0x58a, 0x7, 0x91, 0x2, 0x2, 
       0x58a, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x58b, 0x58c, 0x5, 0xce, 0x68, 0x2, 
       0x58c, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x58d, 0x58e, 0x7, 0x3f, 0x2, 0x2, 
       0x58e, 0x590, 0x5, 0xce, 0x68, 0x2, 0x58f, 0x58d, 0x3, 0x2, 0x2, 
       0x2, 0x58f, 0x590, 0x3, 0x2, 0x2, 0x2, 0x590, 0x591, 0x3, 0x2, 0x2, 
       0x2, 0x591, 0x592, 0x7, 0x2c, 0x2, 0x2, 0x592, 0x593, 0x5, 0xd6, 
       0x6c, 0x2, 0x593, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x594, 0x595, 0x7, 0x1f, 
       0x2, 0x2, 0x595, 0x596, 0x7, 0x3d, 0x2, 0x2, 0x596, 0x597, 0x5, 0x1fc, 
       0xff, 0x2, 0x597, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x598, 0x599, 0x5, 0x11c, 
       0x8f, 0x2, 0x599, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x59a, 0x5a4, 0x5, 0x100, 
       0x81, 0x2, 0x59b, 0x59c, 0x5, 0x100, 0x81, 0x2, 0x59c, 0x59f, 0x7, 
       0x94, 0x2, 0x2, 0x59d, 0x5a0, 0x5, 0xce, 0x68, 0x2, 0x59e, 0x5a0, 
       0x5, 0x192, 0xca, 0x2, 0x59f, 0x59d, 0x3, 0x2, 0x2, 0x2, 0x59f, 0x59e, 
       0x3, 0x2, 0x2, 0x2, 0x5a0, 0x5a1, 0x3, 0x2, 0x2, 0x2, 0x5a1, 0x5a2, 
       0x7, 0x95, 0x2, 0x2, 0x5a2, 0x5a4, 0x3, 0x2, 0x2, 0x2, 0x5a3, 0x59a, 
       0x3, 0x2, 0x2, 0x2, 0x5a3, 0x59b, 0x3, 0x2, 0x2, 0x2, 0x5a4, 0xdf, 
       0x3, 0x2, 0x2, 0x2, 0x5a5, 0x5a6, 0x7, 0x4a, 0x2, 0x2, 0x5a6, 0x5a7, 
       0x5, 0x102, 0x82, 0x2, 0x5a7, 0x5a8, 0x7, 0x98, 0x2, 0x2, 0x5a8, 
       0x5ab, 0x5, 0x1fc, 0xff, 0x2, 0x5a9, 0x5aa, 0x7, 0x8e, 0x2, 0x2, 
       0x5aa, 0x5ac, 0x5, 0xce, 0x68, 0x2, 0x5ab, 0x5a9, 0x3, 0x2, 0x2, 
       0x2, 0x5ab, 0x5ac, 0x3, 0x2, 0x2, 0x2, 0x5ac, 0x5ad, 0x3, 0x2, 0x2, 
       0x2, 0x5ad, 0x5ae, 0x7, 0x91, 0x2, 0x2, 0x5ae, 0xe1, 0x3, 0x2, 0x2, 
       0x2, 0x5af, 0x5b3, 0x5, 0xe4, 0x73, 0x2, 0x5b0, 0x5b3, 0x5, 0xe6, 
       0x74, 0x2, 0x5b1, 0x5b3, 0x5, 0xe8, 0x75, 0x2, 0x5b2, 0x5af, 0x3, 
       0x2, 0x2, 0x2, 0x5b2, 0x5b0, 0x3, 0x2, 0x2, 0x2, 0x5b2, 0x5b1, 0x3, 
       0x2, 0x2, 0x2, 0x5b3, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x5b4, 0x5b5, 0x5, 
       0x12a, 0x96, 0x2, 0x5b5, 0x5b6, 0x7, 0x20, 0x2, 0x2, 0x5b6, 0x5b7, 
       0x5, 0x166, 0xb4, 0x2, 0x5b7, 0x5b8, 0x7, 0x23, 0x2, 0x2, 0x5b8, 
       0x5b9, 0x5, 0xec, 0x77, 0x2, 0x5b9, 0x5ba, 0x7, 0x1a, 0x2, 0x2, 0x5ba, 
       0x5bc, 0x7, 0x23, 0x2, 0x2, 0x5bb, 0x5bd, 0x5, 0x100, 0x81, 0x2, 
       0x5bc, 0x5bb, 0x3, 0x2, 0x2, 0x2, 0x5bc, 0x5bd, 0x3, 0x2, 0x2, 0x2, 
       0x5bd, 0x5be, 0x3, 0x2, 0x2, 0x2, 0x5be, 0x5bf, 0x7, 0x91, 0x2, 0x2, 
       0x5bf, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x5c0, 0x5c2, 0x5, 0x12a, 0x96, 
       0x2, 0x5c1, 0x5c0, 0x3, 0x2, 0x2, 0x2, 0x5c1, 0x5c2, 0x3, 0x2, 0x2, 
       0x2, 0x5c2, 0x5c3, 0x3, 0x2, 0x2, 0x2, 0x5c3, 0x5c4, 0x7, 0x27, 0x2, 
       0x2, 0x5c4, 0x5c5, 0x5, 0x72, 0x3a, 0x2, 0x5c5, 0x5c6, 0x7, 0x23, 
       0x2, 0x2, 0x5c6, 0x5ce, 0x5, 0xec, 0x77, 0x2, 0x5c7, 0x5c8, 0x7, 
       0x1d, 0x2, 0x2, 0x5c8, 0x5c9, 0x5, 0x72, 0x3a, 0x2, 0x5c9, 0x5ca, 
       0x7, 0x23, 0x2, 0x2, 0x5ca, 0x5cb, 0x5, 0xec, 0x77, 0x2, 0x5cb, 0x5cd, 
       0x3, 0x2, 0x2, 0x2, 0x5cc, 0x5c7, 0x3, 0x2, 0x2, 0x2, 0x5cd, 0x5d0, 
       0x3, 0x2, 0x2, 0x2, 0x5ce, 0x5cc, 0x3, 0x2, 0x2, 0x2, 0x5ce, 0x5cf, 
       0x3, 0x2, 0x2, 0x2, 0x5cf, 0x5d4, 0x3, 0x2, 0x2, 0x2, 0x5d0, 0x5ce, 
       0x3, 0x2, 0x2, 0x2, 0x5d1, 0x5d2, 0x7, 0x1c, 0x2, 0x2, 0x5d2, 0x5d3, 
       0x7, 0x23, 0x2, 0x2, 0x5d3, 0x5d5, 0x5, 0xec, 0x77, 0x2, 0x5d4, 0x5d1, 
       0x3, 0x2, 0x2, 0x2, 0x5d4, 0x5d5, 0x3, 0x2, 0x2, 0x2, 0x5d5, 0x5d6, 
       0x3, 0x2, 0x2, 0x2, 0x5d6, 0x5d7, 0x7, 0x1a, 0x2, 0x2, 0x5d7, 0x5d9, 
       0x7, 0x23, 0x2, 0x2, 0x5d8, 0x5da, 0x5, 0x100, 0x81, 0x2, 0x5d9, 
       0x5d8, 0x3, 0x2, 0x2, 0x2, 0x5d9, 0x5da, 0x3, 0x2, 0x2, 0x2, 0x5da, 
       0x5db, 0x3, 0x2, 0x2, 0x2, 0x5db, 0x5dc, 0x7, 0x91, 0x2, 0x2, 0x5dc, 
       0xe7, 0x3, 0x2, 0x2, 0x2, 0x5dd, 0x5df, 0x5, 0x12a, 0x96, 0x2, 0x5de, 
       0x5dd, 0x3, 0x2, 0x2, 0x2, 0x5de, 0x5df, 0x3, 0x2, 0x2, 0x2, 0x5df, 
       0x5e0, 0x3, 0x2, 0x2, 0x2, 0x5e0, 0x5e1, 0x7, 0x14, 0x2, 0x2, 0x5e1, 
       0x5e2, 0x5, 0xce, 0x68, 0x2, 0x5e2, 0x5e4, 0x7, 0x23, 0x2, 0x2, 0x5e3, 
       0x5e5, 0x5, 0xea, 0x76, 0x2, 0x5e4, 0x5e3, 0x3, 0x2, 0x2, 0x2, 0x5e5, 
       0x5e6, 0x3, 0x2, 0x2, 0x2, 0x5e6, 0x5e4, 0x3, 0x2, 0x2, 0x2, 0x5e6, 
       0x5e7, 0x3, 0x2, 0x2, 0x2, 0x5e7, 0x5e8, 0x3, 0x2, 0x2, 0x2, 0x5e8, 
       0x5e9, 0x7, 0x1a, 0x2, 0x2, 0x5e9, 0x5eb, 0x7, 0x23, 0x2, 0x2, 0x5ea, 
       0x5ec, 0x5, 0x100, 0x81, 0x2, 0x5eb, 0x5ea, 0x3, 0x2, 0x2, 0x2, 0x5eb, 
       0x5ec, 0x3, 0x2, 0x2, 0x2, 0x5ec, 0x5ed, 0x3, 0x2, 0x2, 0x2, 0x5ed, 
       0x5ee, 0x7, 0x91, 0x2, 0x2, 0x5ee, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x5ef, 
       0x5f0, 0x7, 0x70, 0x2, 0x2, 0x5f0, 0x5f1, 0x5, 0x56, 0x2c, 0x2, 0x5f1, 
       0x5f2, 0x7, 0x8c, 0x2, 0x2, 0x5f2, 0x5f3, 0x5, 0xec, 0x77, 0x2, 0x5f3, 
       0xeb, 0x3, 0x2, 0x2, 0x2, 0x5f4, 0x5f6, 0x5, 0x3a, 0x1e, 0x2, 0x5f5, 
       0x5f4, 0x3, 0x2, 0x2, 0x2, 0x5f6, 0x5f9, 0x3, 0x2, 0x2, 0x2, 0x5f7, 
       0x5f5, 0x3, 0x2, 0x2, 0x2, 0x5f7, 0x5f8, 0x3, 0x2, 0x2, 0x2, 0x5f8, 
       0x5fa, 0x3, 0x2, 0x2, 0x2, 0x5f9, 0x5f7, 0x3, 0x2, 0x2, 0x2, 0x5fa, 
       0x5fc, 0x7, 0xe, 0x2, 0x2, 0x5fb, 0x5f7, 0x3, 0x2, 0x2, 0x2, 0x5fb, 
       0x5fc, 0x3, 0x2, 0x2, 0x2, 0x5fc, 0x600, 0x3, 0x2, 0x2, 0x2, 0x5fd, 
       0x5ff, 0x5, 0x1e, 0x10, 0x2, 0x5fe, 0x5fd, 0x3, 0x2, 0x2, 0x2, 0x5ff, 
       0x602, 0x3, 0x2, 0x2, 0x2, 0x600, 0x5fe, 0x3, 0x2, 0x2, 0x2, 0x600, 
       0x601, 0x3, 0x2, 0x2, 0x2, 0x601, 0xed, 0x3, 0x2, 0x2, 0x2, 0x602, 
       0x600, 0x3, 0x2, 0x2, 0x2, 0x603, 0x604, 0x7, 0x20, 0x2, 0x2, 0x604, 
       0x60a, 0x5, 0x166, 0xb4, 0x2, 0x605, 0x606, 0x7, 0x27, 0x2, 0x2, 
       0x606, 0x60a, 0x5, 0x72, 0x3a, 0x2, 0x607, 0x608, 0x7, 0x14, 0x2, 
       0x2, 0x608, 0x60a, 0x5, 0xce, 0x68, 0x2, 0x609, 0x603, 0x3, 0x2, 
       0x2, 0x2, 0x609, 0x605, 0x3, 0x2, 0x2, 0x2, 0x609, 0x607, 0x3, 0x2, 
       0x2, 0x2, 0x60a, 0xef, 0x3, 0x2, 0x2, 0x2, 0x60b, 0x60c, 0x7, 0x24, 
       0x2, 0x2, 0x60c, 0x60d, 0x7, 0x94, 0x2, 0x2, 0x60d, 0x60e, 0x5, 0xf2, 
       0x7a, 0x2, 0x60e, 0x60f, 0x7, 0x95, 0x2, 0x2, 0x60f, 0x610, 0x7, 
       0x91, 0x2, 0x2, 0x610, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x611, 0x616, 0x5, 
       0x110, 0x89, 0x2, 0x612, 0x613, 0x7, 0x91, 0x2, 0x2, 0x613, 0x615, 
       0x5, 0x110, 0x89, 0x2, 0x614, 0x612, 0x3, 0x2, 0x2, 0x2, 0x615, 0x618, 
       0x3, 0x2, 0x2, 0x2, 0x616, 0x614, 0x3, 0x2, 0x2, 0x2, 0x616, 0x617, 
       0x3, 0x2, 0x2, 0x2, 0x617, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x618, 0x616, 
       0x3, 0x2, 0x2, 0x2, 0x619, 0x61a, 0x7, 0x24, 0x2, 0x2, 0x61a, 0x61b, 
       0x7, 0x33, 0x2, 0x2, 0x61b, 0x61c, 0x7, 0x94, 0x2, 0x2, 0x61c, 0x61d, 
       0x5, 0x2c, 0x17, 0x2, 0x61d, 0x61e, 0x7, 0x95, 0x2, 0x2, 0x61e, 0xf5, 
       0x3, 0x2, 0x2, 0x2, 0x61f, 0x622, 0x5, 0x13e, 0xa0, 0x2, 0x620, 0x622, 
       0x7, 0x85, 0x2, 0x2, 0x621, 0x61f, 0x3, 0x2, 0x2, 0x2, 0x621, 0x620, 
       0x3, 0x2, 0x2, 0x2, 0x622, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x623, 0x628, 
       0x5, 0xf6, 0x7c, 0x2, 0x624, 0x625, 0x7, 0x92, 0x2, 0x2, 0x625, 0x627, 
       0x5, 0xf6, 0x7c, 0x2, 0x626, 0x624, 0x3, 0x2, 0x2, 0x2, 0x627, 0x62a, 
       0x3, 0x2, 0x2, 0x2, 0x628, 0x626, 0x3, 0x2, 0x2, 0x2, 0x628, 0x629, 
       0x3, 0x2, 0x2, 0x2, 0x629, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x62a, 0x628, 
       0x3, 0x2, 0x2, 0x2, 0x62b, 0x62c, 0x7, 0x25, 0x2, 0x2, 0x62c, 0x62d, 
       0x5, 0x12a, 0x96, 0x2, 0x62d, 0x62e, 0x5, 0x13e, 0xa0, 0x2, 0x62e, 
       0x62f, 0x7, 0x94, 0x2, 0x2, 0x62f, 0x630, 0x5, 0xf8, 0x7d, 0x2, 0x630, 
       0x631, 0x7, 0x95, 0x2, 0x2, 0x631, 0x632, 0x7, 0x91, 0x2, 0x2, 0x632, 
       0xfb, 0x3, 0x2, 0x2, 0x2, 0x633, 0x634, 0x7, 0x25, 0x2, 0x2, 0x634, 
       0x635, 0x5, 0x100, 0x81, 0x2, 0x635, 0x636, 0x7, 0x2c, 0x2, 0x2, 
       0x636, 0x637, 0x7, 0x94, 0x2, 0x2, 0x637, 0x638, 0x5, 0xb2, 0x5a, 
       0x2, 0x638, 0x639, 0x7, 0x95, 0x2, 0x2, 0x639, 0x63a, 0x7, 0x91, 
       0x2, 0x2, 0x63a, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x63b, 0x63c, 0x5, 0x1ca, 
       0xe6, 0x2, 0x63c, 0x63d, 0x7, 0x98, 0x2, 0x2, 0x63d, 0x63e, 0x5, 
       0x13e, 0xa0, 0x2, 0x63e, 0xff, 0x3, 0x2, 0x2, 0x2, 0x63f, 0x640, 
       0x9, 0x6, 0x2, 0x2, 0x640, 0x101, 0x3, 0x2, 0x2, 0x2, 0x641, 0x646, 
       0x5, 0x100, 0x81, 0x2, 0x642, 0x643, 0x7, 0x92, 0x2, 0x2, 0x643, 
       0x645, 0x5, 0x100, 0x81, 0x2, 0x644, 0x642, 0x3, 0x2, 0x2, 0x2, 0x645, 
       0x648, 0x3, 0x2, 0x2, 0x2, 0x646, 0x644, 0x3, 0x2, 0x2, 0x2, 0x646, 
       0x647, 0x3, 0x2, 0x2, 0x2, 0x647, 0x103, 0x3, 0x2, 0x2, 0x2, 0x648, 
       0x646, 0x3, 0x2, 0x2, 0x2, 0x649, 0x64b, 0x5, 0x12a, 0x96, 0x2, 0x64a, 
       0x649, 0x3, 0x2, 0x2, 0x2, 0x64a, 0x64b, 0x3, 0x2, 0x2, 0x2, 0x64b, 
       0x64c, 0x3, 0x2, 0x2, 0x2, 0x64c, 0x64d, 0x7, 0x27, 0x2, 0x2, 0x64d, 
       0x64e, 0x5, 0x72, 0x3a, 0x2, 0x64e, 0x64f, 0x7, 0x63, 0x2, 0x2, 0x64f, 
       0x657, 0x5, 0x1b2, 0xda, 0x2, 0x650, 0x651, 0x7, 0x1d, 0x2, 0x2, 
       0x651, 0x652, 0x5, 0x72, 0x3a, 0x2, 0x652, 0x653, 0x7, 0x63, 0x2, 
       0x2, 0x653, 0x654, 0x5, 0x1b2, 0xda, 0x2, 0x654, 0x656, 0x3, 0x2, 
       0x2, 0x2, 0x655, 0x650, 0x3, 0x2, 0x2, 0x2, 0x656, 0x659, 0x3, 0x2, 
       0x2, 0x2, 0x657, 0x655, 0x3, 0x2, 0x2, 0x2, 0x657, 0x658, 0x3, 0x2, 
       0x2, 0x2, 0x658, 0x65c, 0x3, 0x2, 0x2, 0x2, 0x659, 0x657, 0x3, 0x2, 
       0x2, 0x2, 0x65a, 0x65b, 0x7, 0x1c, 0x2, 0x2, 0x65b, 0x65d, 0x5, 0x1b2, 
       0xda, 0x2, 0x65c, 0x65a, 0x3, 0x2, 0x2, 0x2, 0x65c, 0x65d, 0x3, 0x2, 
       0x2, 0x2, 0x65d, 0x65e, 0x3, 0x2, 0x2, 0x2, 0x65e, 0x65f, 0x7, 0x1a, 
       0x2, 0x2, 0x65f, 0x661, 0x7, 0x27, 0x2, 0x2, 0x660, 0x662, 0x5, 0x100, 
       0x81, 0x2, 0x661, 0x660, 0x3, 0x2, 0x2, 0x2, 0x661, 0x662, 0x3, 0x2, 
       0x2, 0x2, 0x662, 0x663, 0x3, 0x2, 0x2, 0x2, 0x663, 0x664, 0x7, 0x91, 
       0x2, 0x2, 0x664, 0x105, 0x3, 0x2, 0x2, 0x2, 0x665, 0x666, 0x7, 0x94, 
       0x2, 0x2, 0x666, 0x66b, 0x5, 0xa2, 0x52, 0x2, 0x667, 0x668, 0x7, 
       0x92, 0x2, 0x2, 0x668, 0x66a, 0x5, 0xa2, 0x52, 0x2, 0x669, 0x667, 
       0x3, 0x2, 0x2, 0x2, 0x66a, 0x66d, 0x3, 0x2, 0x2, 0x2, 0x66b, 0x669, 
       0x3, 0x2, 0x2, 0x2, 0x66b, 0x66c, 0x3, 0x2, 0x2, 0x2, 0x66c, 0x66e, 
       0x3, 0x2, 0x2, 0x2, 0x66d, 0x66b, 0x3, 0x2, 0x2, 0x2, 0x66e, 0x66f, 
       0x7, 0x95, 0x2, 0x2, 0x66f, 0x107, 0x3, 0x2, 0x2, 0x2, 0x670, 0x673, 
       0x5, 0xa2, 0x52, 0x2, 0x671, 0x673, 0x5, 0xce, 0x68, 0x2, 0x672, 
       0x670, 0x3, 0x2, 0x2, 0x2, 0x672, 0x671, 0x3, 0x2, 0x2, 0x2, 0x673, 
       0x109, 0x3, 0x2, 0x2, 0x2, 0x674, 0x675, 0x5, 0x13e, 0xa0, 0x2, 0x675, 
       0x676, 0x7, 0x4b, 0x2, 0x2, 0x676, 0x677, 0x7, 0x8f, 0x2, 0x2, 0x677, 
       0x10b, 0x3, 0x2, 0x2, 0x2, 0x678, 0x67a, 0x7, 0x15, 0x2, 0x2, 0x679, 
       0x678, 0x3, 0x2, 0x2, 0x2, 0x679, 0x67a, 0x3, 0x2, 0x2, 0x2, 0x67a, 
       0x67b, 0x3, 0x2, 0x2, 0x2, 0x67b, 0x687, 0x5, 0x13e, 0xa0, 0x2, 0x67c, 
       0x67d, 0x7, 0x1b, 0x2, 0x2, 0x67d, 0x682, 0x5, 0x13e, 0xa0, 0x2, 
       0x67e, 0x67f, 0x7, 0x94, 0x2, 0x2, 0x67f, 0x680, 0x5, 0x100, 0x81, 
       0x2, 0x680, 0x681, 0x7, 0x95, 0x2, 0x2, 0x681, 0x683, 0x3, 0x2, 0x2, 
       0x2, 0x682, 0x67e, 0x3, 0x2, 0x2, 0x2, 0x682, 0x683, 0x3, 0x2, 0x2, 
       0x2, 0x683, 0x687, 0x3, 0x2, 0x2, 0x2, 0x684, 0x685, 0x7, 0x16, 0x2, 
       0x2, 0x685, 0x687, 0x5, 0x13e, 0xa0, 0x2, 0x686, 0x679, 0x3, 0x2, 
       0x2, 0x2, 0x686, 0x67c, 0x3, 0x2, 0x2, 0x2, 0x686, 0x684, 0x3, 0x2, 
       0x2, 0x2, 0x687, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x688, 0x68d, 0x5, 0x100, 
       0x81, 0x2, 0x689, 0x68a, 0x7, 0x92, 0x2, 0x2, 0x68a, 0x68c, 0x5, 
       0x100, 0x81, 0x2, 0x68b, 0x689, 0x3, 0x2, 0x2, 0x2, 0x68c, 0x68f, 
       0x3, 0x2, 0x2, 0x2, 0x68d, 0x68b, 0x3, 0x2, 0x2, 0x2, 0x68d, 0x68e, 
       0x3, 0x2, 0x2, 0x2, 0x68e, 0x693, 0x3, 0x2, 0x2, 0x2, 0x68f, 0x68d, 
       0x3, 0x2, 0x2, 0x2, 0x690, 0x693, 0x7, 0x41, 0x2, 0x2, 0x691, 0x693, 
       0x7, 0x8, 0x2, 0x2, 0x692, 0x688, 0x3, 0x2, 0x2, 0x2, 0x692, 0x690, 
       0x3, 0x2, 0x2, 0x2, 0x692, 0x691, 0x3, 0x2, 0x2, 0x2, 0x693, 0x10f, 
       0x3, 0x2, 0x2, 0x2, 0x694, 0x696, 0x7, 0x17, 0x2, 0x2, 0x695, 0x694, 
       0x3, 0x2, 0x2, 0x2, 0x695, 0x696, 0x3, 0x2, 0x2, 0x2, 0x696, 0x697, 
       0x3, 0x2, 0x2, 0x2, 0x697, 0x698, 0x5, 0x102, 0x82, 0x2, 0x698, 0x69a, 
       0x7, 0x98, 0x2, 0x2, 0x699, 0x69b, 0x7, 0x29, 0x2, 0x2, 0x69a, 0x699, 
       0x3, 0x2, 0x2, 0x2, 0x69a, 0x69b, 0x3, 0x2, 0x2, 0x2, 0x69b, 0x69c, 
       0x3, 0x2, 0x2, 0x2, 0x69c, 0x69f, 0x5, 0x1fc, 0xff, 0x2, 0x69d, 0x69e, 
       0x7, 0x8e, 0x2, 0x2, 0x69e, 0x6a0, 0x5, 0xce, 0x68, 0x2, 0x69f, 0x69d, 
       0x3, 0x2, 0x2, 0x2, 0x69f, 0x6a0, 0x3, 0x2, 0x2, 0x2, 0x6a0, 0x111, 
       0x3, 0x2, 0x2, 0x2, 0x6a1, 0x6a8, 0x5, 0x110, 0x89, 0x2, 0x6a2, 0x6a8, 
       0x5, 0x122, 0x92, 0x2, 0x6a3, 0x6a8, 0x5, 0x126, 0x94, 0x2, 0x6a4, 
       0x6a8, 0x5, 0x116, 0x8c, 0x2, 0x6a5, 0x6a8, 0x5, 0x124, 0x93, 0x2, 
       0x6a6, 0x6a8, 0x5, 0x11e, 0x90, 0x2, 0x6a7, 0x6a1, 0x3, 0x2, 0x2, 
       0x2, 0x6a7, 0x6a2, 0x3, 0x2, 0x2, 0x2, 0x6a7, 0x6a3, 0x3, 0x2, 0x2, 
       0x2, 0x6a7, 0x6a4, 0x3, 0x2, 0x2, 0x2, 0x6a7, 0x6a5, 0x3, 0x2, 0x2, 
       0x2, 0x6a7, 0x6a6, 0x3, 0x2, 0x2, 0x2, 0x6a8, 0x113, 0x3, 0x2, 0x2, 
       0x2, 0x6a9, 0x6aa, 0x5, 0x112, 0x8a, 0x2, 0x6aa, 0x115, 0x3, 0x2, 
       0x2, 0x2, 0x6ab, 0x6ac, 0x7, 0x1f, 0x2, 0x2, 0x6ac, 0x6ad, 0x5, 0x102, 
       0x82, 0x2, 0x6ad, 0x6ae, 0x7, 0x98, 0x2, 0x2, 0x6ae, 0x6af, 0x5, 
       0x1fc, 0xff, 0x2, 0x6af, 0x117, 0x3, 0x2, 0x2, 0x2, 0x6b0, 0x6b5, 
       0x5, 0x122, 0x92, 0x2, 0x6b1, 0x6b2, 0x7, 0x91, 0x2, 0x2, 0x6b2, 
       0x6b4, 0x5, 0x122, 0x92, 0x2, 0x6b3, 0x6b1, 0x3, 0x2, 0x2, 0x2, 0x6b4, 
       0x6b7, 0x3, 0x2, 0x2, 0x2, 0x6b5, 0x6b3, 0x3, 0x2, 0x2, 0x2, 0x6b5, 
       0x6b6, 0x3, 0x2, 0x2, 0x2, 0x6b6, 0x119, 0x3, 0x2, 0x2, 0x2, 0x6b7, 
       0x6b5, 0x3, 0x2, 0x2, 0x2, 0x6b8, 0x6bd, 0x5, 0x120, 0x91, 0x2, 0x6b9, 
       0x6ba, 0x7, 0x91, 0x2, 0x2, 0x6ba, 0x6bc, 0x5, 0x120, 0x91, 0x2, 
       0x6bb, 0x6b9, 0x3, 0x2, 0x2, 0x2, 0x6bc, 0x6bf, 0x3, 0x2, 0x2, 0x2, 
       0x6bd, 0x6bb, 0x3, 0x2, 0x2, 0x2, 0x6bd, 0x6be, 0x3, 0x2, 0x2, 0x2, 
       0x6be, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x6bf, 0x6bd, 0x3, 0x2, 0x2, 0x2, 
       0x6c0, 0x6c5, 0x5, 0x114, 0x8b, 0x2, 0x6c1, 0x6c2, 0x7, 0x91, 0x2, 
       0x2, 0x6c2, 0x6c4, 0x5, 0x114, 0x8b, 0x2, 0x6c3, 0x6c1, 0x3, 0x2, 
       0x2, 0x2, 0x6c4, 0x6c7, 0x3, 0x2, 0x2, 0x2, 0x6c5, 0x6c3, 0x3, 0x2, 
       0x2, 0x2, 0x6c5, 0x6c6, 0x3, 0x2, 0x2, 0x2, 0x6c6, 0x11d, 0x3, 0x2, 
       0x2, 0x2, 0x6c7, 0x6c5, 0x3, 0x2, 0x2, 0x2, 0x6c8, 0x6c9, 0x7, 0x4a, 
       0x2, 0x2, 0x6c9, 0x6ca, 0x5, 0x102, 0x82, 0x2, 0x6ca, 0x6cc, 0x7, 
       0x98, 0x2, 0x2, 0x6cb, 0x6cd, 0x9, 0x7, 0x2, 0x2, 0x6cc, 0x6cb, 0x3, 
       0x2, 0x2, 0x2, 0x6cc, 0x6cd, 0x3, 0x2, 0x2, 0x2, 0x6cd, 0x6ce, 0x3, 
       0x2, 0x2, 0x2, 0x6ce, 0x6d1, 0x5, 0x1fc, 0xff, 0x2, 0x6cf, 0x6d0, 
       0x7, 0x8e, 0x2, 0x2, 0x6d0, 0x6d2, 0x5, 0xce, 0x68, 0x2, 0x6d1, 0x6cf, 
       0x3, 0x2, 0x2, 0x2, 0x6d1, 0x6d2, 0x3, 0x2, 0x2, 0x2, 0x6d2, 0x11f, 
       0x3, 0x2, 0x2, 0x2, 0x6d3, 0x6d4, 0x5, 0x102, 0x82, 0x2, 0x6d4, 0x6d5, 
       0x7, 0x98, 0x2, 0x2, 0x6d5, 0x6d6, 0x5, 0x13a, 0x9e, 0x2, 0x6d6, 
       0x6d8, 0x5, 0x1fc, 0xff, 0x2, 0x6d7, 0x6d9, 0x7, 0x13, 0x2, 0x2, 
       0x6d8, 0x6d7, 0x3, 0x2, 0x2, 0x2, 0x6d8, 0x6d9, 0x3, 0x2, 0x2, 0x2, 
       0x6d9, 0x6dc, 0x3, 0x2, 0x2, 0x2, 0x6da, 0x6db, 0x7, 0x8e, 0x2, 0x2, 
       0x6db, 0x6dd, 0x5, 0xce, 0x68, 0x2, 0x6dc, 0x6da, 0x3, 0x2, 0x2, 
       0x2, 0x6dc, 0x6dd, 0x3, 0x2, 0x2, 0x2, 0x6dd, 0x121, 0x3, 0x2, 0x2, 
       0x2, 0x6de, 0x6df, 0x7, 0x5a, 0x2, 0x2, 0x6df, 0x6e0, 0x5, 0x102, 
       0x82, 0x2, 0x6e0, 0x6e2, 0x7, 0x98, 0x2, 0x2, 0x6e1, 0x6e3, 0x9, 
       0x8, 0x2, 0x2, 0x6e2, 0x6e1, 0x3, 0x2, 0x2, 0x2, 0x6e2, 0x6e3, 0x3, 
       0x2, 0x2, 0x2, 0x6e3, 0x6e4, 0x3, 0x2, 0x2, 0x2, 0x6e4, 0x6e6, 0x5, 
       0x1fc, 0xff, 0x2, 0x6e5, 0x6e7, 0x7, 0x13, 0x2, 0x2, 0x6e6, 0x6e5, 
       0x3, 0x2, 0x2, 0x2, 0x6e6, 0x6e7, 0x3, 0x2, 0x2, 0x2, 0x6e7, 0x6ea, 
       0x3, 0x2, 0x2, 0x2, 0x6e8, 0x6e9, 0x7, 0x8e, 0x2, 0x2, 0x6e9, 0x6eb, 
       0x5, 0xce, 0x68, 0x2, 0x6ea, 0x6e8, 0x3, 0x2, 0x2, 0x2, 0x6ea, 0x6eb, 
       0x3, 0x2, 0x2, 0x2, 0x6eb, 0x123, 0x3, 0x2, 0x2, 0x2, 0x6ec, 0x6ed, 
       0x7, 0x62, 0x2, 0x2, 0x6ed, 0x6ee, 0x5, 0x102, 0x82, 0x2, 0x6ee, 
       0x6ef, 0x7, 0x98, 0x2, 0x2, 0x6ef, 0x6f0, 0x5, 0x1e6, 0xf4, 0x2, 
       0x6f0, 0x125, 0x3, 0x2, 0x2, 0x2, 0x6f1, 0x6f3, 0x7, 0x6d, 0x2, 0x2, 
       0x6f2, 0x6f1, 0x3, 0x2, 0x2, 0x2, 0x6f2, 0x6f3, 0x3, 0x2, 0x2, 0x2, 
       0x6f3, 0x6f4, 0x3, 0x2, 0x2, 0x2, 0x6f4, 0x6f5, 0x5, 0x102, 0x82, 
       0x2, 0x6f5, 0x6f7, 0x7, 0x98, 0x2, 0x2, 0x6f6, 0x6f8, 0x5, 0x13a, 
       0x9e, 0x2, 0x6f7, 0x6f6, 0x3, 0x2, 0x2, 0x2, 0x6f7, 0x6f8, 0x3, 0x2, 
       0x2, 0x2, 0x6f8, 0x6f9, 0x3, 0x2, 0x2, 0x2, 0x6f9, 0x6fc, 0x5, 0x1fc, 
       0xff, 0x2, 0x6fa, 0x6fb, 0x7, 0x8e, 0x2, 0x2, 0x6fb, 0x6fd, 0x5, 
       0xce, 0x68, 0x2, 0x6fc, 0x6fa, 0x3, 0x2, 0x2, 0x2, 0x6fc, 0x6fd, 
       0x3, 0x2, 0x2, 0x2, 0x6fd, 0x127, 0x3, 0x2, 0x2, 0x2, 0x6fe, 0x6ff, 
       0x7, 0x71, 0x2, 0x2, 0x6ff, 0x703, 0x5, 0x72, 0x3a, 0x2, 0x700, 0x701, 
       0x7, 0x20, 0x2, 0x2, 0x701, 0x703, 0x5, 0x166, 0xb4, 0x2, 0x702, 
       0x6fe, 0x3, 0x2, 0x2, 0x2, 0x702, 0x700, 0x3, 0x2, 0x2, 0x2, 0x703, 
       0x129, 0x3, 0x2, 0x2, 0x2, 0x704, 0x705, 0x5, 0x100, 0x81, 0x2, 0x705, 
       0x706, 0x7, 0x98, 0x2, 0x2, 0x706, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x707, 
       0x708, 0x7, 0x2e, 0x2, 0x2, 0x708, 0x709, 0x5, 0x134, 0x9b, 0x2, 
       0x709, 0x70a, 0x7, 0x91, 0x2, 0x2, 0x70a, 0x12d, 0x3, 0x2, 0x2, 0x2, 
       0x70b, 0x70e, 0x5, 0x1a6, 0xd4, 0x2, 0x70c, 0x70e, 0x5, 0x174, 0xbb, 
       0x2, 0x70d, 0x70b, 0x3, 0x2, 0x2, 0x2, 0x70d, 0x70c, 0x3, 0x2, 0x2, 
       0x2, 0x70e, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x70f, 0x715, 0x7, 0x3c, 0x2, 
       0x2, 0x710, 0x715, 0x7, 0x75, 0x2, 0x2, 0x711, 0x715, 0x7, 0x86, 
       0x2, 0x2, 0x712, 0x715, 0x5, 0xc8, 0x65, 0x2, 0x713, 0x715, 0x5, 
       0x154, 0xab, 0x2, 0x714, 0x70f, 0x3, 0x2, 0x2, 0x2, 0x714, 0x710, 
       0x3, 0x2, 0x2, 0x2, 0x714, 0x711, 0x3, 0x2, 0x2, 0x2, 0x714, 0x712, 
       0x3, 0x2, 0x2, 0x2, 0x714, 0x713, 0x3, 0x2, 0x2, 0x2, 0x715, 0x131, 
       0x3, 0x2, 0x2, 0x2, 0x716, 0x717, 0x5, 0x100, 0x81, 0x2, 0x717, 0x133, 
       0x3, 0x2, 0x2, 0x2, 0x718, 0x71d, 0x5, 0x132, 0x9a, 0x2, 0x719, 0x71a, 
       0x7, 0x92, 0x2, 0x2, 0x71a, 0x71c, 0x5, 0x132, 0x9a, 0x2, 0x71b, 
       0x719, 0x3, 0x2, 0x2, 0x2, 0x71c, 0x71f, 0x3, 0x2, 0x2, 0x2, 0x71d, 
       0x71b, 0x3, 0x2, 0x2, 0x2, 0x71d, 0x71e, 0x3, 0x2, 0x2, 0x2, 0x71e, 
       0x135, 0x3, 0x2, 0x2, 0x2, 0x71f, 0x71d, 0x3, 0x2, 0x2, 0x2, 0x720, 
       0x721, 0x9, 0x9, 0x2, 0x2, 0x721, 0x137, 0x3, 0x2, 0x2, 0x2, 0x722, 
       0x724, 0x5, 0x12a, 0x96, 0x2, 0x723, 0x722, 0x3, 0x2, 0x2, 0x2, 0x723, 
       0x724, 0x3, 0x2, 0x2, 0x2, 0x724, 0x726, 0x3, 0x2, 0x2, 0x2, 0x725, 
       0x727, 0x5, 0x128, 0x95, 0x2, 0x726, 0x725, 0x3, 0x2, 0x2, 0x2, 0x726, 
       0x727, 0x3, 0x2, 0x2, 0x2, 0x727, 0x728, 0x3, 0x2, 0x2, 0x2, 0x728, 
       0x729, 0x7, 0x32, 0x2, 0x2, 0x729, 0x72a, 0x5, 0x1b2, 0xda, 0x2, 
       0x72a, 0x72b, 0x7, 0x1a, 0x2, 0x2, 0x72b, 0x72d, 0x7, 0x32, 0x2, 
       0x2, 0x72c, 0x72e, 0x5, 0x100, 0x81, 0x2, 0x72d, 0x72c, 0x3, 0x2, 
       0x2, 0x2, 0x72d, 0x72e, 0x3, 0x2, 0x2, 0x2, 0x72e, 0x72f, 0x3, 0x2, 
       0x2, 0x2, 0x72f, 0x730, 0x7, 0x91, 0x2, 0x2, 0x730, 0x139, 0x3, 0x2, 
       0x2, 0x2, 0x731, 0x732, 0x9, 0xa, 0x2, 0x2, 0x732, 0x13b, 0x3, 0x2, 
       0x2, 0x2, 0x733, 0x734, 0x9, 0xb, 0x2, 0x2, 0x734, 0x13d, 0x3, 0x2, 
       0x2, 0x2, 0x735, 0x73f, 0x5, 0x14a, 0xa6, 0x2, 0x736, 0x73b, 0x5, 
       0x140, 0xa1, 0x2, 0x737, 0x738, 0x7, 0xa1, 0x2, 0x2, 0x738, 0x73a, 
       0x5, 0x140, 0xa1, 0x2, 0x739, 0x737, 0x3, 0x2, 0x2, 0x2, 0x73a, 0x73d, 
       0x3, 0x2, 0x2, 0x2, 0x73b, 0x739, 0x3, 0x2, 0x2, 0x2, 0x73b, 0x73c, 
       0x3, 0x2, 0x2, 0x2, 0x73c, 0x73f, 0x3, 0x2, 0x2, 0x2, 0x73d, 0x73b, 
       0x3, 0x2, 0x2, 0x2, 0x73e, 0x735, 0x3, 0x2, 0x2, 0x2, 0x73e, 0x736, 
       0x3, 0x2, 0x2, 0x2, 0x73f, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x740, 0x744, 
       0x5, 0x14a, 0xa6, 0x2, 0x741, 0x743, 0x5, 0x142, 0xa2, 0x2, 0x742, 
       0x741, 0x3, 0x2, 0x2, 0x2, 0x743, 0x746, 0x3, 0x2, 0x2, 0x2, 0x744, 
       0x742, 0x3, 0x2, 0x2, 0x2, 0x744, 0x745, 0x3, 0x2, 0x2, 0x2, 0x745, 
       0x141, 0x3, 0x2, 0x2, 0x2, 0x746, 0x744, 0x3, 0x2, 0x2, 0x2, 0x747, 
       0x74b, 0x5, 0x144, 0xa3, 0x2, 0x748, 0x74b, 0x5, 0x146, 0xa4, 0x2, 
       0x749, 0x74b, 0x5, 0x148, 0xa5, 0x2, 0x74a, 0x747, 0x3, 0x2, 0x2, 
       0x2, 0x74a, 0x748, 0x3, 0x2, 0x2, 0x2, 0x74a, 0x749, 0x3, 0x2, 0x2, 
       0x2, 0x74b, 0x143, 0x3, 0x2, 0x2, 0x2, 0x74c, 0x74d, 0x7, 0xab, 0x2, 
       0x2, 0x74d, 0x756, 0x5, 0x30, 0x19, 0x2, 0x74e, 0x753, 0x5, 0xce, 
       0x68, 0x2, 0x74f, 0x750, 0x7, 0x92, 0x2, 0x2, 0x750, 0x752, 0x5, 
       0xce, 0x68, 0x2, 0x751, 0x74f, 0x3, 0x2, 0x2, 0x2, 0x752, 0x755, 
       0x3, 0x2, 0x2, 0x2, 0x753, 0x751, 0x3, 0x2, 0x2, 0x2, 0x753, 0x754, 
       0x3, 0x2, 0x2, 0x2, 0x754, 0x757, 0x3, 0x2, 0x2, 0x2, 0x755, 0x753, 
       0x3, 0x2, 0x2, 0x2, 0x756, 0x74e, 0x3, 0x2, 0x2, 0x2, 0x756, 0x757, 
       0x3, 0x2, 0x2, 0x2, 0x757, 0x145, 0x3, 0x2, 0x2, 0x2, 0x758, 0x75a, 
       0x7, 0x94, 0x2, 0x2, 0x759, 0x75b, 0x5, 0xa, 0x6, 0x2, 0x75a, 0x759, 
       0x3, 0x2, 0x2, 0x2, 0x75a, 0x75b, 0x3, 0x2, 0x2, 0x2, 0x75b, 0x75c, 
       0x3, 0x2, 0x2, 0x2, 0x75c, 0x75d, 0x7, 0x95, 0x2, 0x2, 0x75d, 0x147, 
       0x3, 0x2, 0x2, 0x2, 0x75e, 0x75f, 0x7, 0x94, 0x2, 0x2, 0x75f, 0x764, 
       0x5, 0x192, 0xca, 0x2, 0x760, 0x761, 0x7, 0x92, 0x2, 0x2, 0x761, 
       0x763, 0x5, 0x192, 0xca, 0x2, 0x762, 0x760, 0x3, 0x2, 0x2, 0x2, 0x763, 
       0x766, 0x3, 0x2, 0x2, 0x2, 0x764, 0x762, 0x3, 0x2, 0x2, 0x2, 0x764, 
       0x765, 0x3, 0x2, 0x2, 0x2, 0x765, 0x767, 0x3, 0x2, 0x2, 0x2, 0x766, 
       0x764, 0x3, 0x2, 0x2, 0x2, 0x767, 0x768, 0x7, 0x95, 0x2, 0x2, 0x768, 
       0x149, 0x3, 0x2, 0x2, 0x2, 0x769, 0x76e, 0x5, 0x100, 0x81, 0x2, 0x76a, 
       0x76b, 0x7, 0xa1, 0x2, 0x2, 0x76b, 0x76d, 0x5, 0x1fe, 0x100, 0x2, 
       0x76c, 0x76a, 0x3, 0x2, 0x2, 0x2, 0x76d, 0x770, 0x3, 0x2, 0x2, 0x2, 
       0x76e, 0x76c, 0x3, 0x2, 0x2, 0x2, 0x76e, 0x76f, 0x3, 0x2, 0x2, 0x2, 
       0x76f, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x770, 0x76e, 0x3, 0x2, 0x2, 0x2, 
       0x771, 0x772, 0x7, 0x36, 0x2, 0x2, 0x772, 0x773, 0x5, 0x100, 0x81, 
       0x2, 0x773, 0x774, 0x7, 0x2c, 0x2, 0x2, 0x774, 0x775, 0x5, 0x14e, 
       0xa8, 0x2, 0x775, 0x776, 0x7, 0x91, 0x2, 0x2, 0x776, 0x14d, 0x3, 
       0x2, 0x2, 0x2, 0x777, 0x77a, 0x5, 0x1a2, 0xd2, 0x2, 0x778, 0x77a, 
       0x5, 0x60, 0x31, 0x2, 0x779, 0x777, 0x3, 0x2, 0x2, 0x2, 0x779, 0x778, 
       0x3, 0x2, 0x2, 0x2, 0x77a, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x77b, 0x77c, 
       0x5, 0x102, 0x82, 0x2, 0x77c, 0x77d, 0x7, 0x98, 0x2, 0x2, 0x77d, 
       0x77e, 0x5, 0xa8, 0x55, 0x2, 0x77e, 0x151, 0x3, 0x2, 0x2, 0x2, 0x77f, 
       0x781, 0x5, 0x12a, 0x96, 0x2, 0x780, 0x77f, 0x3, 0x2, 0x2, 0x2, 0x780, 
       0x781, 0x3, 0x2, 0x2, 0x2, 0x781, 0x782, 0x3, 0x2, 0x2, 0x2, 0x782, 
       0x784, 0x7, 0x38, 0x2, 0x2, 0x783, 0x785, 0x5, 0x100, 0x81, 0x2, 
       0x784, 0x783, 0x3, 0x2, 0x2, 0x2, 0x784, 0x785, 0x3, 0x2, 0x2, 0x2, 
       0x785, 0x788, 0x3, 0x2, 0x2, 0x2, 0x786, 0x787, 0x7, 0x70, 0x2, 0x2, 
       0x787, 0x789, 0x5, 0x72, 0x3a, 0x2, 0x788, 0x786, 0x3, 0x2, 0x2, 
       0x2, 0x788, 0x789, 0x3, 0x2, 0x2, 0x2, 0x789, 0x78a, 0x3, 0x2, 0x2, 
       0x2, 0x78a, 0x78b, 0x7, 0x91, 0x2, 0x2, 0x78b, 0x153, 0x3, 0x2, 0x2, 
       0x2, 0x78c, 0x78f, 0x5, 0x2, 0x2, 0x2, 0x78d, 0x78f, 0x5, 0x168, 
       0xb5, 0x2, 0x78e, 0x78c, 0x3, 0x2, 0x2, 0x2, 0x78e, 0x78d, 0x3, 0x2, 
       0x2, 0x2, 0x78f, 0x155, 0x3, 0x2, 0x2, 0x2, 0x790, 0x797, 0x5, 0x8a, 
       0x46, 0x2, 0x791, 0x797, 0x5, 0x1c6, 0xe4, 0x2, 0x792, 0x797, 0x5, 
       0x220, 0x111, 0x2, 0x793, 0x797, 0x5, 0xd4, 0x6b, 0x2, 0x794, 0x797, 
       0x5, 0x206, 0x104, 0x2, 0x795, 0x797, 0x5, 0x18a, 0xc6, 0x2, 0x796, 
       0x790, 0x3, 0x2, 0x2, 0x2, 0x796, 0x791, 0x3, 0x2, 0x2, 0x2, 0x796, 
       0x792, 0x3, 0x2, 0x2, 0x2, 0x796, 0x793, 0x3, 0x2, 0x2, 0x2, 0x796, 
       0x794, 0x3, 0x2, 0x2, 0x2, 0x796, 0x795, 0x3, 0x2, 0x2, 0x2, 0x797, 
       0x157, 0x3, 0x2, 0x2, 0x2, 0x798, 0x79a, 0x7, 0x26, 0x2, 0x2, 0x799, 
       0x798, 0x3, 0x2, 0x2, 0x2, 0x799, 0x79a, 0x3, 0x2, 0x2, 0x2, 0x79a, 
       0x79c, 0x3, 0x2, 0x2, 0x2, 0x79b, 0x79d, 0x5, 0x96, 0x4c, 0x2, 0x79c, 
       0x79b, 0x3, 0x2, 0x2, 0x2, 0x79c, 0x79d, 0x3, 0x2, 0x2, 0x2, 0x79d, 
       0x159, 0x3, 0x2, 0x2, 0x2, 0x79e, 0x79f, 0x7, 0x43, 0x2, 0x2, 0x79f, 
       0x7a0, 0x7, 0x10, 0x2, 0x2, 0x7a0, 0x7a1, 0x5, 0x100, 0x81, 0x2, 
       0x7a1, 0x7a2, 0x7, 0x2c, 0x2, 0x2, 0x7a2, 0x7a3, 0x5, 0x15e, 0xb0, 
       0x2, 0x7a3, 0x7a6, 0x7, 0x1a, 0x2, 0x2, 0x7a4, 0x7a5, 0x7, 0x43, 
       0x2, 0x2, 0x7a5, 0x7a7, 0x7, 0x10, 0x2, 0x2, 0x7a6, 0x7a4, 0x3, 0x2, 
       0x2, 0x2, 0x7a6, 0x7a7, 0x3, 0x2, 0x2, 0x2, 0x7a7, 0x7a9, 0x3, 0x2, 
       0x2, 0x2, 0x7a8, 0x7aa, 0x5, 0x100, 0x81, 0x2, 0x7a9, 0x7a8, 0x3, 
       0x2, 0x2, 0x2, 0x7a9, 0x7aa, 0x3, 0x2, 0x2, 0x2, 0x7aa, 0x7ab, 0x3, 
       0x2, 0x2, 0x2, 0x7ab, 0x7ac, 0x7, 0x91, 0x2, 0x2, 0x7ac, 0x15b, 0x3, 
       0x2, 0x2, 0x2, 0x7ad, 0x7b9, 0x5, 0x1ea, 0xf6, 0x2, 0x7ae, 0x7b9, 
       0x5, 0x1e8, 0xf5, 0x2, 0x7af, 0x7b9, 0x5, 0x20e, 0x108, 0x2, 0x7b0, 
       0x7b9, 0x5, 0x1fa, 0xfe, 0x2, 0x7b1, 0x7b9, 0x5, 0x8a, 0x46, 0x2, 
       0x7b2, 0x7b9, 0x5, 0x220, 0x111, 0x2, 0x7b3, 0x7b9, 0x5, 0xd4, 0x6b, 
       0x2, 0x7b4, 0x7b9, 0x5, 0x12, 0xa, 0x2, 0x7b5, 0x7b9, 0x5, 0x216, 
       0x10c, 0x2, 0x7b6, 0x7b9, 0x5, 0xfc, 0x7f, 0x2, 0x7b7, 0x7b9, 0x5, 
       0xfa, 0x7e, 0x2, 0x7b8, 0x7ad, 0x3, 0x2, 0x2, 0x2, 0x7b8, 0x7ae, 
       0x3, 0x2, 0x2, 0x2, 0x7b8, 0x7af, 0x3, 0x2, 0x2, 0x2, 0x7b8, 0x7b0, 
       0x3, 0x2, 0x2, 0x2, 0x7b8, 0x7b1, 0x3, 0x2, 0x2, 0x2, 0x7b8, 0x7b2, 
       0x3, 0x2, 0x2, 0x2, 0x7b8, 0x7b3, 0x3, 0x2, 0x2, 0x2, 0x7b8, 0x7b4, 
       0x3, 0x2, 0x2, 0x2, 0x7b8, 0x7b5, 0x3, 0x2, 0x2, 0x2, 0x7b8, 0x7b6, 
       0x3, 0x2, 0x2, 0x2, 0x7b8, 0x7b7, 0x3, 0x2, 0x2, 0x2, 0x7b9, 0x15d, 
       0x3, 0x2, 0x2, 0x2, 0x7ba, 0x7bc, 0x5, 0x15c, 0xaf, 0x2, 0x7bb, 0x7ba, 
       0x3, 0x2, 0x2, 0x2, 0x7bc, 0x7bf, 0x3, 0x2, 0x2, 0x2, 0x7bd, 0x7bb, 
       0x3, 0x2, 0x2, 0x2, 0x7bd, 0x7be, 0x3, 0x2, 0x2, 0x2, 0x7be, 0x15f, 
       0x3, 0x2, 0x2, 0x2, 0x7bf, 0x7bd, 0x3, 0x2, 0x2, 0x2, 0x7c0, 0x7c1, 
       0x7, 0x43, 0x2, 0x2, 0x7c1, 0x7c2, 0x5, 0x100, 0x81, 0x2, 0x7c2, 
       0x7c3, 0x7, 0x2c, 0x2, 0x2, 0x7c3, 0x7c4, 0x5, 0x164, 0xb3, 0x2, 
       0x7c4, 0x7c6, 0x7, 0x1a, 0x2, 0x2, 0x7c5, 0x7c7, 0x7, 0x43, 0x2, 
       0x2, 0x7c6, 0x7c5, 0x3, 0x2, 0x2, 0x2, 0x7c6, 0x7c7, 0x3, 0x2, 0x2, 
       0x2, 0x7c7, 0x7c9, 0x3, 0x2, 0x2, 0x2, 0x7c8, 0x7ca, 0x5, 0x100, 
       0x81, 0x2, 0x7c9, 0x7c8, 0x3, 0x2, 0x2, 0x2, 0x7c9, 0x7ca, 0x3, 0x2, 
       0x2, 0x2, 0x7ca, 0x7cb, 0x3, 0x2, 0x2, 0x2, 0x7cb, 0x7cc, 0x7, 0x91, 
       0x2, 0x2, 0x7cc, 0x161, 0x3, 0x2, 0x2, 0x2, 0x7cd, 0x7e0, 0x5, 0x1ea, 
       0xf6, 0x2, 0x7ce, 0x7e0, 0x5, 0x20e, 0x108, 0x2, 0x7cf, 0x7e0, 0x5, 
       0x1fa, 0xfe, 0x2, 0x7d0, 0x7e0, 0x5, 0x8a, 0x46, 0x2, 0x7d1, 0x7e0, 
       0x5, 0x1c6, 0xe4, 0x2, 0x7d2, 0x7e0, 0x5, 0x220, 0x111, 0x2, 0x7d3, 
       0x7e0, 0x5, 0xd4, 0x6b, 0x2, 0x7d4, 0x7e0, 0x5, 0x12, 0xa, 0x2, 0x7d5, 
       0x7e0, 0x5, 0x5a, 0x2e, 0x2, 0x7d6, 0x7e0, 0x5, 0x2e, 0x18, 0x2, 
       0x7d7, 0x7e0, 0x5, 0x32, 0x1a, 0x2, 0x7d8, 0x7e0, 0x5, 0xa0, 0x51, 
       0x2, 0x7d9, 0x7e0, 0x5, 0x216, 0x10c, 0x2, 0x7da, 0x7e0, 0x5, 0xfc, 
       0x7f, 0x2, 0x7db, 0x7e0, 0x5, 0xfa, 0x7e, 0x2, 0x7dc, 0x7e0, 0x5, 
       0x14c, 0xa7, 0x2, 0x7dd, 0x7e0, 0x5, 0x1e4, 0xf3, 0x2, 0x7de, 0x7e0, 
       0x5, 0x206, 0x104, 0x2, 0x7df, 0x7cd, 0x3, 0x2, 0x2, 0x2, 0x7df, 
       0x7ce, 0x3, 0x2, 0x2, 0x2, 0x7df, 0x7cf, 0x3, 0x2, 0x2, 0x2, 0x7df, 
       0x7d0, 0x3, 0x2, 0x2, 0x2, 0x7df, 0x7d1, 0x3, 0x2, 0x2, 0x2, 0x7df, 
       0x7d2, 0x3, 0x2, 0x2, 0x2, 0x7df, 0x7d3, 0x3, 0x2, 0x2, 0x2, 0x7df, 
       0x7d4, 0x3, 0x2, 0x2, 0x2, 0x7df, 0x7d5, 0x3, 0x2, 0x2, 0x2, 0x7df, 
       0x7d6, 0x3, 0x2, 0x2, 0x2, 0x7df, 0x7d7, 0x3, 0x2, 0x2, 0x2, 0x7df, 
       0x7d8, 0x3, 0x2, 0x2, 0x2, 0x7df, 0x7d9, 0x3, 0x2, 0x2, 0x2, 0x7df, 
       0x7da, 0x3, 0x2, 0x2, 0x2, 0x7df, 0x7db, 0x3, 0x2, 0x2, 0x2, 0x7df, 
       0x7dc, 0x3, 0x2, 0x2, 0x2, 0x7df, 0x7dd, 0x3, 0x2, 0x2, 0x2, 0x7df, 
       0x7de, 0x3, 0x2, 0x2, 0x2, 0x7e0, 0x163, 0x3, 0x2, 0x2, 0x2, 0x7e1, 
       0x7e3, 0x5, 0x162, 0xb2, 0x2, 0x7e2, 0x7e1, 0x3, 0x2, 0x2, 0x2, 0x7e3, 
       0x7e6, 0x3, 0x2, 0x2, 0x2, 0x7e4, 0x7e2, 0x3, 0x2, 0x2, 0x2, 0x7e4, 
       0x7e5, 0x3, 0x2, 0x2, 0x2, 0x7e5, 0x165, 0x3, 0x2, 0x2, 0x2, 0x7e6, 
       0x7e4, 0x3, 0x2, 0x2, 0x2, 0x7e7, 0x7e8, 0x5, 0x100, 0x81, 0x2, 0x7e8, 
       0x7e9, 0x7, 0x29, 0x2, 0x2, 0x7e9, 0x7ea, 0x5, 0xa2, 0x52, 0x2, 0x7ea, 
       0x167, 0x3, 0x2, 0x2, 0x2, 0x7eb, 0x7ec, 0x5, 0x2, 0x2, 0x2, 0x7ec, 
       0x7ed, 0x5, 0x100, 0x81, 0x2, 0x7ed, 0x169, 0x3, 0x2, 0x2, 0x2, 0x7ee, 
       0x7ef, 0x5, 0x194, 0xcb, 0x2, 0x7ef, 0x7f0, 0x7, 0x6a, 0x2, 0x2, 
       0x7f0, 0x7f4, 0x5, 0x34, 0x1b, 0x2, 0x7f1, 0x7f3, 0x5, 0x1a8, 0xd5, 
       0x2, 0x7f2, 0x7f1, 0x3, 0x2, 0x2, 0x2, 0x7f3, 0x7f6, 0x3, 0x2, 0x2, 
       0x2, 0x7f4, 0x7f2, 0x3, 0x2, 0x2, 0x2, 0x7f4, 0x7f5, 0x3, 0x2, 0x2, 
       0x2, 0x7f5, 0x7f7, 0x3, 0x2, 0x2, 0x2, 0x7f6, 0x7f4, 0x3, 0x2, 0x2, 
       0x2, 0x7f7, 0x7f8, 0x7, 0x1a, 0x2, 0x2, 0x7f8, 0x7fa, 0x7, 0x6a, 
       0x2, 0x2, 0x7f9, 0x7fb, 0x5, 0x100, 0x81, 0x2, 0x7fa, 0x7f9, 0x3, 
       0x2, 0x2, 0x2, 0x7fa, 0x7fb, 0x3, 0x2, 0x2, 0x2, 0x7fb, 0x16b, 0x3, 
       0x2, 0x2, 0x2, 0x7fc, 0x7fd, 0x7, 0x44, 0x2, 0x2, 0x7fd, 0x7fe, 0x7, 
       0x94, 0x2, 0x2, 0x7fe, 0x7ff, 0x5, 0x16e, 0xb8, 0x2, 0x7ff, 0x800, 
       0x7, 0x95, 0x2, 0x2, 0x800, 0x801, 0x7, 0x91, 0x2, 0x2, 0x801, 0x16d, 
       0x3, 0x2, 0x2, 0x2, 0x802, 0x803, 0x5, 0x11a, 0x8e, 0x2, 0x803, 0x16f, 
       0x3, 0x2, 0x2, 0x2, 0x804, 0x805, 0x7, 0x44, 0x2, 0x2, 0x805, 0x806, 
       0x7, 0x33, 0x2, 0x2, 0x806, 0x807, 0x7, 0x94, 0x2, 0x2, 0x807, 0x808, 
       0x5, 0x2c, 0x17, 0x2, 0x808, 0x809, 0x7, 0x95, 0x2, 0x2, 0x809, 0x171, 
       0x3, 0x2, 0x2, 0x2, 0x80a, 0x814, 0x5, 0x130, 0x99, 0x2, 0x80b, 0x814, 
       0x5, 0x188, 0xc5, 0x2, 0x80c, 0x80d, 0x7, 0x94, 0x2, 0x2, 0x80d, 
       0x80e, 0x5, 0xce, 0x68, 0x2, 0x80e, 0x80f, 0x7, 0x95, 0x2, 0x2, 0x80f, 
       0x814, 0x3, 0x2, 0x2, 0x2, 0x810, 0x814, 0x5, 0x18, 0xd, 0x2, 0x811, 
       0x814, 0x5, 0x10, 0x9, 0x2, 0x812, 0x814, 0x5, 0x13e, 0xa0, 0x2, 
       0x813, 0x80a, 0x3, 0x2, 0x2, 0x2, 0x813, 0x80b, 0x3, 0x2, 0x2, 0x2, 
       0x813, 0x80c, 0x3, 0x2, 0x2, 0x2, 0x813, 0x810, 0x3, 0x2, 0x2, 0x2, 
       0x813, 0x811, 0x3, 0x2, 0x2, 0x2, 0x813, 0x812, 0x3, 0x2, 0x2, 0x2, 
       0x814, 0x173, 0x3, 0x2, 0x2, 0x2, 0x815, 0x819, 0x5, 0xb4, 0x5b, 
       0x2, 0x816, 0x819, 0x5, 0x80, 0x41, 0x2, 0x817, 0x819, 0x5, 0x160, 
       0xb1, 0x2, 0x818, 0x815, 0x3, 0x2, 0x2, 0x2, 0x818, 0x816, 0x3, 0x2, 
       0x2, 0x2, 0x818, 0x817, 0x3, 0x2, 0x2, 0x2, 0x819, 0x175, 0x3, 0x2, 
       0x2, 0x2, 0x81a, 0x827, 0x5, 0x1ea, 0xf6, 0x2, 0x81b, 0x827, 0x5, 
       0x1e8, 0xf5, 0x2, 0x81c, 0x827, 0x5, 0x20e, 0x108, 0x2, 0x81d, 0x827, 
       0x5, 0x1fa, 0xfe, 0x2, 0x81e, 0x827, 0x5, 0x8a, 0x46, 0x2, 0x81f, 
       0x827, 0x5, 0x220, 0x111, 0x2, 0x820, 0x827, 0x5, 0x12, 0xa, 0x2, 
       0x821, 0x827, 0x5, 0x2e, 0x18, 0x2, 0x822, 0x827, 0x5, 0x32, 0x1a, 
       0x2, 0x823, 0x827, 0x5, 0x216, 0x10c, 0x2, 0x824, 0x827, 0x5, 0xfc, 
       0x7f, 0x2, 0x825, 0x827, 0x5, 0xfa, 0x7e, 0x2, 0x826, 0x81a, 0x3, 
       0x2, 0x2, 0x2, 0x826, 0x81b, 0x3, 0x2, 0x2, 0x2, 0x826, 0x81c, 0x3, 
       0x2, 0x2, 0x2, 0x826, 0x81d, 0x3, 0x2, 0x2, 0x2, 0x826, 0x81e, 0x3, 
       0x2, 0x2, 0x2, 0x826, 0x81f, 0x3, 0x2, 0x2, 0x2, 0x826, 0x820, 0x3, 
       0x2, 0x2, 0x2, 0x826, 0x821, 0x3, 0x2, 0x2, 0x2, 0x826, 0x822, 0x3, 
       0x2, 0x2, 0x2, 0x826, 0x823, 0x3, 0x2, 0x2, 0x2, 0x826, 0x824, 0x3, 
       0x2, 0x2, 0x2, 0x826, 0x825, 0x3, 0x2, 0x2, 0x2, 0x827, 0x177, 0x3, 
       0x2, 0x2, 0x2, 0x828, 0x82a, 0x5, 0x176, 0xbc, 0x2, 0x829, 0x828, 
       0x3, 0x2, 0x2, 0x2, 0x82a, 0x82d, 0x3, 0x2, 0x2, 0x2, 0x82b, 0x829, 
       0x3, 0x2, 0x2, 0x2, 0x82b, 0x82c, 0x3, 0x2, 0x2, 0x2, 0x82c, 0x179, 
       0x3, 0x2, 0x2, 0x2, 0x82d, 0x82b, 0x3, 0x2, 0x2, 0x2, 0x82e, 0x830, 
       0x5, 0x1b4, 0xdb, 0x2, 0x82f, 0x82e, 0x3, 0x2, 0x2, 0x2, 0x830, 0x833, 
       0x3, 0x2, 0x2, 0x2, 0x831, 0x82f, 0x3, 0x2, 0x2, 0x2, 0x831, 0x832, 
       0x3, 0x2, 0x2, 0x2, 0x832, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x833, 0x831, 
       0x3, 0x2, 0x2, 0x2, 0x834, 0x839, 0x5, 0x14a, 0xa6, 0x2, 0x835, 0x836, 
       0x7, 0x94, 0x2, 0x2, 0x836, 0x837, 0x5, 0xa, 0x6, 0x2, 0x837, 0x838, 
       0x7, 0x95, 0x2, 0x2, 0x838, 0x83a, 0x3, 0x2, 0x2, 0x2, 0x839, 0x835, 
       0x3, 0x2, 0x2, 0x2, 0x839, 0x83a, 0x3, 0x2, 0x2, 0x2, 0x83a, 0x17d, 
       0x3, 0x2, 0x2, 0x2, 0x83b, 0x83d, 0x5, 0x12a, 0x96, 0x2, 0x83c, 0x83b, 
       0x3, 0x2, 0x2, 0x2, 0x83c, 0x83d, 0x3, 0x2, 0x2, 0x2, 0x83d, 0x83e, 
       0x3, 0x2, 0x2, 0x2, 0x83e, 0x83f, 0x5, 0x17c, 0xbf, 0x2, 0x83f, 0x840, 
       0x7, 0x91, 0x2, 0x2, 0x840, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x841, 0x84f, 
       0x5, 0x1ea, 0xf6, 0x2, 0x842, 0x84f, 0x5, 0x1e8, 0xf5, 0x2, 0x843, 
       0x84f, 0x5, 0x20e, 0x108, 0x2, 0x844, 0x84f, 0x5, 0x1fa, 0xfe, 0x2, 
       0x845, 0x84f, 0x5, 0x8a, 0x46, 0x2, 0x846, 0x84f, 0x5, 0x220, 0x111, 
       0x2, 0x847, 0x84f, 0x5, 0xd4, 0x6b, 0x2, 0x848, 0x84f, 0x5, 0x12, 
       0xa, 0x2, 0x849, 0x84f, 0x5, 0x2e, 0x18, 0x2, 0x84a, 0x84f, 0x5, 
       0x32, 0x1a, 0x2, 0x84b, 0x84f, 0x5, 0x216, 0x10c, 0x2, 0x84c, 0x84f, 
       0x5, 0xfc, 0x7f, 0x2, 0x84d, 0x84f, 0x5, 0xfa, 0x7e, 0x2, 0x84e, 
       0x841, 0x3, 0x2, 0x2, 0x2, 0x84e, 0x842, 0x3, 0x2, 0x2, 0x2, 0x84e, 
       0x843, 0x3, 0x2, 0x2, 0x2, 0x84e, 0x844, 0x3, 0x2, 0x2, 0x2, 0x84e, 
       0x845, 0x3, 0x2, 0x2, 0x2, 0x84e, 0x846, 0x3, 0x2, 0x2, 0x2, 0x84e, 
       0x847, 0x3, 0x2, 0x2, 0x2, 0x84e, 0x848, 0x3, 0x2, 0x2, 0x2, 0x84e, 
       0x849, 0x3, 0x2, 0x2, 0x2, 0x84e, 0x84a, 0x3, 0x2, 0x2, 0x2, 0x84e, 
       0x84b, 0x3, 0x2, 0x2, 0x2, 0x84e, 0x84c, 0x3, 0x2, 0x2, 0x2, 0x84e, 
       0x84d, 0x3, 0x2, 0x2, 0x2, 0x84f, 0x181, 0x3, 0x2, 0x2, 0x2, 0x850, 
       0x852, 0x5, 0x180, 0xc1, 0x2, 0x851, 0x850, 0x3, 0x2, 0x2, 0x2, 0x852, 
       0x855, 0x3, 0x2, 0x2, 0x2, 0x853, 0x851, 0x3, 0x2, 0x2, 0x2, 0x853, 
       0x854, 0x3, 0x2, 0x2, 0x2, 0x854, 0x183, 0x3, 0x2, 0x2, 0x2, 0x855, 
       0x853, 0x3, 0x2, 0x2, 0x2, 0x856, 0x858, 0x5, 0x12a, 0x96, 0x2, 0x857, 
       0x856, 0x3, 0x2, 0x2, 0x2, 0x857, 0x858, 0x3, 0x2, 0x2, 0x2, 0x858, 
       0x85a, 0x3, 0x2, 0x2, 0x2, 0x859, 0x85b, 0x7, 0x45, 0x2, 0x2, 0x85a, 
       0x859, 0x3, 0x2, 0x2, 0x2, 0x85a, 0x85b, 0x3, 0x2, 0x2, 0x2, 0x85b, 
       0x85c, 0x3, 0x2, 0x2, 0x2, 0x85c, 0x861, 0x7, 0x46, 0x2, 0x2, 0x85d, 
       0x85e, 0x7, 0x94, 0x2, 0x2, 0x85e, 0x85f, 0x5, 0x1b0, 0xd9, 0x2, 
       0x85f, 0x860, 0x7, 0x95, 0x2, 0x2, 0x860, 0x862, 0x3, 0x2, 0x2, 0x2, 
       0x861, 0x85d, 0x3, 0x2, 0x2, 0x2, 0x861, 0x862, 0x3, 0x2, 0x2, 0x2, 
       0x862, 0x864, 0x3, 0x2, 0x2, 0x2, 0x863, 0x865, 0x7, 0x2c, 0x2, 0x2, 
       0x864, 0x863, 0x3, 0x2, 0x2, 0x2, 0x864, 0x865, 0x3, 0x2, 0x2, 0x2, 
       0x865, 0x866, 0x3, 0x2, 0x2, 0x2, 0x866, 0x867, 0x5, 0x182, 0xc2, 
       0x2, 0x867, 0x868, 0x7, 0xe, 0x2, 0x2, 0x868, 0x869, 0x5, 0x186, 
       0xc4, 0x2, 0x869, 0x86b, 0x7, 0x1a, 0x2, 0x2, 0x86a, 0x86c, 0x7, 
       0x45, 0x2, 0x2, 0x86b, 0x86a, 0x3, 0x2, 0x2, 0x2, 0x86b, 0x86c, 0x3, 
       0x2, 0x2, 0x2, 0x86c, 0x86d, 0x3, 0x2, 0x2, 0x2, 0x86d, 0x86f, 0x7, 
       0x46, 0x2, 0x2, 0x86e, 0x870, 0x5, 0x100, 0x81, 0x2, 0x86f, 0x86e, 
       0x3, 0x2, 0x2, 0x2, 0x86f, 0x870, 0x3, 0x2, 0x2, 0x2, 0x870, 0x871, 
       0x3, 0x2, 0x2, 0x2, 0x871, 0x872, 0x7, 0x91, 0x2, 0x2, 0x872, 0x185, 
       0x3, 0x2, 0x2, 0x2, 0x873, 0x875, 0x5, 0x1b4, 0xdb, 0x2, 0x874, 0x873, 
       0x3, 0x2, 0x2, 0x2, 0x875, 0x878, 0x3, 0x2, 0x2, 0x2, 0x876, 0x874, 
       0x3, 0x2, 0x2, 0x2, 0x876, 0x877, 0x3, 0x2, 0x2, 0x2, 0x877, 0x187, 
       0x3, 0x2, 0x2, 0x2, 0x878, 0x876, 0x3, 0x2, 0x2, 0x2, 0x879, 0x87a, 
       0x5, 0x1fc, 0xff, 0x2, 0x87a, 0x880, 0x7, 0xab, 0x2, 0x2, 0x87b, 
       0x881, 0x5, 0x10, 0x9, 0x2, 0x87c, 0x87d, 0x7, 0x94, 0x2, 0x2, 0x87d, 
       0x87e, 0x5, 0xce, 0x68, 0x2, 0x87e, 0x87f, 0x7, 0x95, 0x2, 0x2, 0x87f, 
       0x881, 0x3, 0x2, 0x2, 0x2, 0x880, 0x87b, 0x3, 0x2, 0x2, 0x2, 0x880, 
       0x87c, 0x3, 0x2, 0x2, 0x2, 0x881, 0x189, 0x3, 0x2, 0x2, 0x2, 0x882, 
       0x886, 0x5, 0xe0, 0x71, 0x2, 0x883, 0x886, 0x5, 0x46, 0x24, 0x2, 
       0x884, 0x886, 0x5, 0x1e0, 0xf1, 0x2, 0x885, 0x882, 0x3, 0x2, 0x2, 
       0x2, 0x885, 0x883, 0x3, 0x2, 0x2, 0x2, 0x885, 0x884, 0x3, 0x2, 0x2, 
       0x2, 0x886, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x887, 0x88c, 0x5, 0x13e, 
       0xa0, 0x2, 0x888, 0x889, 0x7, 0x92, 0x2, 0x2, 0x889, 0x88b, 0x5, 
       0x13e, 0xa0, 0x2, 0x88a, 0x888, 0x3, 0x2, 0x2, 0x2, 0x88b, 0x88e, 
       0x3, 0x2, 0x2, 0x2, 0x88c, 0x88a, 0x3, 0x2, 0x2, 0x2, 0x88c, 0x88d, 
       0x3, 0x2, 0x2, 0x2, 0x88d, 0x892, 0x3, 0x2, 0x2, 0x2, 0x88e, 0x88c, 
       0x3, 0x2, 0x2, 0x2, 0x88f, 0x892, 0x7, 0x41, 0x2, 0x2, 0x890, 0x892, 
       0x7, 0x8, 0x2, 0x2, 0x891, 0x887, 0x3, 0x2, 0x2, 0x2, 0x891, 0x88f, 
       0x3, 0x2, 0x2, 0x2, 0x891, 0x890, 0x3, 0x2, 0x2, 0x2, 0x892, 0x18d, 
       0x3, 0x2, 0x2, 0x2, 0x893, 0x894, 0x5, 0x18c, 0xc7, 0x2, 0x894, 0x895, 
       0x7, 0x98, 0x2, 0x2, 0x895, 0x896, 0x5, 0x13e, 0xa0, 0x2, 0x896, 
       0x18f, 0x3, 0x2, 0x2, 0x2, 0x897, 0x89a, 0x5, 0x192, 0xca, 0x2, 0x898, 
       0x89a, 0x5, 0x13e, 0xa0, 0x2, 0x899, 0x897, 0x3, 0x2, 0x2, 0x2, 0x899, 
       0x898, 0x3, 0x2, 0x2, 0x2, 0x89a, 0x191, 0x3, 0x2, 0x2, 0x2, 0x89b, 
       0x89c, 0x5, 0x1ce, 0xe8, 0x2, 0x89c, 0x89d, 0x5, 0x9e, 0x50, 0x2, 
       0x89d, 0x89e, 0x5, 0x1ce, 0xe8, 0x2, 0x89e, 0x193, 0x3, 0x2, 0x2, 
       0x2, 0x89f, 0x8a0, 0x7, 0x4b, 0x2, 0x2, 0x8a0, 0x8a1, 0x5, 0x190, 
       0xc9, 0x2, 0x8a1, 0x195, 0x3, 0x2, 0x2, 0x2, 0x8a2, 0x8a4, 0x7, 0x4f, 
       0x2, 0x2, 0x8a3, 0x8a5, 0x5, 0x150, 0xa9, 0x2, 0x8a4, 0x8a3, 0x3, 
       0x2, 0x2, 0x2, 0x8a5, 0x8a6, 0x3, 0x2, 0x2, 0x2, 0x8a6, 0x8a4, 0x3, 
       0x2, 0x2, 0x2, 0x8a6, 0x8a7, 0x3, 0x2, 0x2, 0x2, 0x8a7, 0x8a8, 0x3, 
       0x2, 0x2, 0x2, 0x8a8, 0x8a9, 0x7, 0x1a, 0x2, 0x2, 0x8a9, 0x8ab, 0x7, 
       0x4f, 0x2, 0x2, 0x8aa, 0x8ac, 0x5, 0x100, 0x81, 0x2, 0x8ab, 0x8aa, 
       0x3, 0x2, 0x2, 0x2, 0x8ab, 0x8ac, 0x3, 0x2, 0x2, 0x2, 0x8ac, 0x197, 
       0x3, 0x2, 0x2, 0x2, 0x8ad, 0x8af, 0x7, 0x4f, 0x2, 0x2, 0x8ae, 0x8b0, 
       0x5, 0xa6, 0x54, 0x2, 0x8af, 0x8ae, 0x3, 0x2, 0x2, 0x2, 0x8b0, 0x8b1, 
       0x3, 0x2, 0x2, 0x2, 0x8b1, 0x8af, 0x3, 0x2, 0x2, 0x2, 0x8b1, 0x8b2, 
       0x3, 0x2, 0x2, 0x2, 0x8b2, 0x8b3, 0x3, 0x2, 0x2, 0x2, 0x8b3, 0x8b4, 
       0x7, 0x1a, 0x2, 0x2, 0x8b4, 0x8b6, 0x7, 0x4f, 0x2, 0x2, 0x8b5, 0x8b7, 
       0x5, 0x100, 0x81, 0x2, 0x8b6, 0x8b5, 0x3, 0x2, 0x2, 0x2, 0x8b6, 0x8b7, 
       0x3, 0x2, 0x2, 0x2, 0x8b7, 0x199, 0x3, 0x2, 0x2, 0x2, 0x8b8, 0x8bc, 
       0x5, 0x1b6, 0xdc, 0x2, 0x8b9, 0x8ba, 0x5, 0x19c, 0xcf, 0x2, 0x8ba, 
       0x8bb, 0x5, 0x1b6, 0xdc, 0x2, 0x8bb, 0x8bd, 0x3, 0x2, 0x2, 0x2, 0x8bc, 
       0x8b9, 0x3, 0x2, 0x2, 0x2, 0x8bc, 0x8bd, 0x3, 0x2, 0x2, 0x2, 0x8bd, 
       0x19b, 0x3, 0x2, 0x2, 0x2, 0x8be, 0x8bf, 0x9, 0xc, 0x2, 0x2, 0x8bf, 
       0x19d, 0x3, 0x2, 0x2, 0x2, 0x8c0, 0x8c2, 0x5, 0x12a, 0x96, 0x2, 0x8c1, 
       0x8c0, 0x3, 0x2, 0x2, 0x2, 0x8c1, 0x8c2, 0x3, 0x2, 0x2, 0x2, 0x8c2, 
       0x8c3, 0x3, 0x2, 0x2, 0x2, 0x8c3, 0x8c4, 0x7, 0x53, 0x2, 0x2, 0x8c4, 
       0x8c7, 0x5, 0xce, 0x68, 0x2, 0x8c5, 0x8c6, 0x7, 0x58, 0x2, 0x2, 0x8c6, 
       0x8c8, 0x5, 0xce, 0x68, 0x2, 0x8c7, 0x8c5, 0x3, 0x2, 0x2, 0x2, 0x8c7, 
       0x8c8, 0x3, 0x2, 0x2, 0x2, 0x8c8, 0x8c9, 0x3, 0x2, 0x2, 0x2, 0x8c9, 
       0x8ca, 0x7, 0x91, 0x2, 0x2, 0x8ca, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x8cb, 
       0x8cd, 0x5, 0x12a, 0x96, 0x2, 0x8cc, 0x8cb, 0x3, 0x2, 0x2, 0x2, 0x8cc, 
       0x8cd, 0x3, 0x2, 0x2, 0x2, 0x8cd, 0x8ce, 0x3, 0x2, 0x2, 0x2, 0x8ce, 
       0x8d0, 0x7, 0x54, 0x2, 0x2, 0x8cf, 0x8d1, 0x5, 0xce, 0x68, 0x2, 0x8d0, 
       0x8cf, 0x3, 0x2, 0x2, 0x2, 0x8d0, 0x8d1, 0x3, 0x2, 0x2, 0x2, 0x8d1, 
       0x8d2, 0x3, 0x2, 0x2, 0x2, 0x8d2, 0x8d3, 0x7, 0x91, 0x2, 0x2, 0x8d3, 
       0x1a1, 0x3, 0x2, 0x2, 0x2, 0x8d4, 0x8d5, 0x5, 0x13e, 0xa0, 0x2, 0x8d5, 
       0x8d6, 0x7, 0x5, 0x2, 0x2, 0x8d6, 0x8d7, 0x5, 0x13e, 0xa0, 0x2, 0x8d7, 
       0x8d8, 0x7, 0x64, 0x2, 0x2, 0x8d8, 0x8d9, 0x5, 0x13e, 0xa0, 0x2, 
       0x8d9, 0x8da, 0x7, 0x50, 0x2, 0x2, 0x8da, 0x1a3, 0x3, 0x2, 0x2, 0x2, 
       0x8db, 0x8df, 0x5, 0x16a, 0xb6, 0x2, 0x8dc, 0x8df, 0x5, 0xca, 0x66, 
       0x2, 0x8dd, 0x8df, 0x5, 0x194, 0xcb, 0x2, 0x8de, 0x8db, 0x3, 0x2, 
       0x2, 0x2, 0x8de, 0x8dc, 0x3, 0x2, 0x2, 0x2, 0x8de, 0x8dd, 0x3, 0x2, 
       0x2, 0x2, 0x8df, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x8e0, 0x8e3, 0x5, 0x1a, 
       0xe, 0x2, 0x8e1, 0x8e3, 0x5, 0x15a, 0xae, 0x2, 0x8e2, 0x8e0, 0x3, 
       0x2, 0x2, 0x2, 0x8e2, 0x8e1, 0x3, 0x2, 0x2, 0x2, 0x8e3, 0x1a7, 0x3, 
       0x2, 0x2, 0x2, 0x8e4, 0x8e5, 0x5, 0x100, 0x81, 0x2, 0x8e5, 0x8e6, 
       0x7, 0x9f, 0x2, 0x2, 0x8e6, 0x8e7, 0x5, 0x168, 0xb5, 0x2, 0x8e7, 
       0x8e8, 0x7, 0x91, 0x2, 0x2, 0x8e8, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x8e9, 
       0x8ea, 0x7, 0x6f, 0x2, 0x2, 0x8ea, 0x8eb, 0x5, 0xce, 0x68, 0x2, 0x8eb, 
       0x8ed, 0x7, 0x57, 0x2, 0x2, 0x8ec, 0x8ee, 0x7, 0xa3, 0x2, 0x2, 0x8ed, 
       0x8ec, 0x3, 0x2, 0x2, 0x2, 0x8ed, 0x8ee, 0x3, 0x2, 0x2, 0x2, 0x8ee, 
       0x8ef, 0x3, 0x2, 0x2, 0x2, 0x8ef, 0x8f0, 0x5, 0x200, 0x101, 0x2, 
       0x8f0, 0x8f1, 0x7, 0x8a, 0x2, 0x2, 0x8f1, 0x8f2, 0x5, 0x158, 0xad, 
       0x2, 0x8f2, 0x8f3, 0x5, 0x1ac, 0xd7, 0x2, 0x8f3, 0x8f4, 0x7, 0x91, 
       0x2, 0x2, 0x8f4, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x8f5, 0x8f6, 0x5, 0x224, 
       0x113, 0x2, 0x8f6, 0x8f7, 0x7, 0x70, 0x2, 0x2, 0x8f7, 0x8ff, 0x5, 
       0x56, 0x2c, 0x2, 0x8f8, 0x8f9, 0x7, 0x92, 0x2, 0x2, 0x8f9, 0x8fa, 
       0x5, 0x224, 0x113, 0x2, 0x8fa, 0x8fb, 0x7, 0x70, 0x2, 0x2, 0x8fb, 
       0x8fc, 0x5, 0x56, 0x2c, 0x2, 0x8fc, 0x8fe, 0x3, 0x2, 0x2, 0x2, 0x8fd, 
       0x8f8, 0x3, 0x2, 0x2, 0x2, 0x8fe, 0x901, 0x3, 0x2, 0x2, 0x2, 0x8ff, 
       0x8fd, 0x3, 0x2, 0x2, 0x2, 0x8ff, 0x900, 0x3, 0x2, 0x2, 0x2, 0x900, 
       0x1ad, 0x3, 0x2, 0x2, 0x2, 0x901, 0x8ff, 0x3, 0x2, 0x2, 0x2, 0x902, 
       0x903, 0x7, 0x3e, 0x2, 0x2, 0x903, 0x904, 0x5, 0x1b0, 0xd9, 0x2, 
       0x904, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x905, 0x90a, 0x5, 0x13e, 0xa0, 
       0x2, 0x906, 0x907, 0x7, 0x92, 0x2, 0x2, 0x907, 0x909, 0x5, 0x13e, 
       0xa0, 0x2, 0x908, 0x906, 0x3, 0x2, 0x2, 0x2, 0x909, 0x90c, 0x3, 0x2, 
       0x2, 0x2, 0x90a, 0x908, 0x3, 0x2, 0x2, 0x2, 0x90a, 0x90b, 0x3, 0x2, 
       0x2, 0x2, 0x90b, 0x90f, 0x3, 0x2, 0x2, 0x2, 0x90c, 0x90a, 0x3, 0x2, 
       0x2, 0x2, 0x90d, 0x90f, 0x7, 0x8, 0x2, 0x2, 0x90e, 0x905, 0x3, 0x2, 
       0x2, 0x2, 0x90e, 0x90d, 0x3, 0x2, 0x2, 0x2, 0x90f, 0x1b1, 0x3, 0x2, 
       0x2, 0x2, 0x910, 0x912, 0x5, 0x1b4, 0xdb, 0x2, 0x911, 0x910, 0x3, 
       0x2, 0x2, 0x2, 0x912, 0x915, 0x3, 0x2, 0x2, 0x2, 0x913, 0x911, 0x3, 
       0x2, 0x2, 0x2, 0x913, 0x914, 0x3, 0x2, 0x2, 0x2, 0x914, 0x1b3, 0x3, 
       0x2, 0x2, 0x2, 0x915, 0x913, 0x3, 0x2, 0x2, 0x2, 0x916, 0x929, 0x5, 
       0x222, 0x112, 0x2, 0x917, 0x929, 0x5, 0x28, 0x15, 0x2, 0x918, 0x929, 
       0x5, 0x19e, 0xd0, 0x2, 0x919, 0x929, 0x5, 0x1ba, 0xde, 0x2, 0x91a, 
       0x929, 0x5, 0x218, 0x10d, 0x2, 0x91b, 0x929, 0x5, 0x104, 0x83, 0x2, 
       0x91c, 0x929, 0x5, 0x50, 0x29, 0x2, 0x91d, 0x929, 0x5, 0x138, 0x9d, 
       0x2, 0x91e, 0x929, 0x5, 0x152, 0xaa, 0x2, 0x91f, 0x929, 0x5, 0xcc, 
       0x67, 0x2, 0x920, 0x929, 0x5, 0x1a0, 0xd1, 0x2, 0x921, 0x923, 0x5, 
       0x12a, 0x96, 0x2, 0x922, 0x921, 0x3, 0x2, 0x2, 0x2, 0x922, 0x923, 
       0x3, 0x2, 0x2, 0x2, 0x923, 0x924, 0x3, 0x2, 0x2, 0x2, 0x924, 0x925, 
       0x7, 0x3c, 0x2, 0x2, 0x925, 0x929, 0x7, 0x91, 0x2, 0x2, 0x926, 0x929, 
       0x5, 0x4e, 0x28, 0x2, 0x927, 0x929, 0x5, 0x17e, 0xc0, 0x2, 0x928, 
       0x916, 0x3, 0x2, 0x2, 0x2, 0x928, 0x917, 0x3, 0x2, 0x2, 0x2, 0x928, 
       0x918, 0x3, 0x2, 0x2, 0x2, 0x928, 0x919, 0x3, 0x2, 0x2, 0x2, 0x928, 
       0x91a, 0x3, 0x2, 0x2, 0x2, 0x928, 0x91b, 0x3, 0x2, 0x2, 0x2, 0x928, 
       0x91c, 0x3, 0x2, 0x2, 0x2, 0x928, 0x91d, 0x3, 0x2, 0x2, 0x2, 0x928, 
       0x91e, 0x3, 0x2, 0x2, 0x2, 0x928, 0x91f, 0x3, 0x2, 0x2, 0x2, 0x928, 
       0x920, 0x3, 0x2, 0x2, 0x2, 0x928, 0x922, 0x3, 0x2, 0x2, 0x2, 0x928, 
       0x926, 0x3, 0x2, 0x2, 0x2, 0x928, 0x927, 0x3, 0x2, 0x2, 0x2, 0x929, 
       0x1b5, 0x3, 0x2, 0x2, 0x2, 0x92a, 0x92e, 0x5, 0x1ce, 0xe8, 0x2, 0x92b, 
       0x92c, 0x5, 0x1b8, 0xdd, 0x2, 0x92c, 0x92d, 0x5, 0x1ce, 0xe8, 0x2, 
       0x92d, 0x92f, 0x3, 0x2, 0x2, 0x2, 0x92e, 0x92b, 0x3, 0x2, 0x2, 0x2, 
       0x92e, 0x92f, 0x3, 0x2, 0x2, 0x2, 0x92f, 0x1b7, 0x3, 0x2, 0x2, 0x2, 
       0x930, 0x931, 0x9, 0xd, 0x2, 0x2, 0x931, 0x1b9, 0x3, 0x2, 0x2, 0x2, 
       0x932, 0x934, 0x5, 0x12a, 0x96, 0x2, 0x933, 0x932, 0x3, 0x2, 0x2, 
       0x2, 0x933, 0x934, 0x3, 0x2, 0x2, 0x2, 0x934, 0x935, 0x3, 0x2, 0x2, 
       0x2, 0x935, 0x93f, 0x5, 0x1bc, 0xdf, 0x2, 0x936, 0x938, 0x5, 0x12a, 
       0x96, 0x2, 0x937, 0x936, 0x3, 0x2, 0x2, 0x2, 0x937, 0x938, 0x3, 0x2, 
       0x2, 0x2, 0x938, 0x939, 0x3, 0x2, 0x2, 0x2, 0x939, 0x93f, 0x5, 0x76, 
       0x3c, 0x2, 0x93a, 0x93c, 0x5, 0x12a, 0x96, 0x2, 0x93b, 0x93a, 0x3, 
       0x2, 0x2, 0x2, 0x93b, 0x93c, 0x3, 0x2, 0x2, 0x2, 0x93c, 0x93d, 0x3, 
       0x2, 0x2, 0x2, 0x93d, 0x93f, 0x5, 0x1aa, 0xd6, 0x2, 0x93e, 0x933, 
       0x3, 0x2, 0x2, 0x2, 0x93e, 0x937, 0x3, 0x2, 0x2, 0x2, 0x93e, 0x93b, 
       0x3, 0x2, 0x2, 0x2, 0x93f, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x940, 0x944, 
       0x5, 0x1be, 0xe0, 0x2, 0x941, 0x944, 0x5, 0x1c0, 0xe1, 0x2, 0x942, 
       0x944, 0x5, 0x1c2, 0xe2, 0x2, 0x943, 0x940, 0x3, 0x2, 0x2, 0x2, 0x943, 
       0x941, 0x3, 0x2, 0x2, 0x2, 0x943, 0x942, 0x3, 0x2, 0x2, 0x2, 0x944, 
       0x1bd, 0x3, 0x2, 0x2, 0x2, 0x945, 0x946, 0x5, 0x200, 0x101, 0x2, 
       0x946, 0x948, 0x7, 0x8a, 0x2, 0x2, 0x947, 0x949, 0x5, 0x96, 0x4c, 
       0x2, 0x948, 0x947, 0x3, 0x2, 0x2, 0x2, 0x948, 0x949, 0x3, 0x2, 0x2, 
       0x2, 0x949, 0x94a, 0x3, 0x2, 0x2, 0x2, 0x94a, 0x94b, 0x5, 0x224, 
       0x113, 0x2, 0x94b, 0x94c, 0x7, 0x91, 0x2, 0x2, 0x94c, 0x1bf, 0x3, 
       0x2, 0x2, 0x2, 0x94d, 0x94e, 0x5, 0x200, 0x101, 0x2, 0x94e, 0x94f, 
       0x7, 0x8a, 0x2, 0x2, 0x94f, 0x951, 0x7, 0x21, 0x2, 0x2, 0x950, 0x952, 
       0x5, 0x1c4, 0xe3, 0x2, 0x951, 0x950, 0x3, 0x2, 0x2, 0x2, 0x951, 0x952, 
       0x3, 0x2, 0x2, 0x2, 0x952, 0x953, 0x3, 0x2, 0x2, 0x2, 0x953, 0x954, 
       0x5, 0xce, 0x68, 0x2, 0x954, 0x955, 0x7, 0x91, 0x2, 0x2, 0x955, 0x1c1, 
       0x3, 0x2, 0x2, 0x2, 0x956, 0x957, 0x5, 0x200, 0x101, 0x2, 0x957, 
       0x958, 0x7, 0x8a, 0x2, 0x2, 0x958, 0x95a, 0x7, 0x52, 0x2, 0x2, 0x959, 
       0x95b, 0x5, 0x1c4, 0xe3, 0x2, 0x95a, 0x959, 0x3, 0x2, 0x2, 0x2, 0x95a, 
       0x95b, 0x3, 0x2, 0x2, 0x2, 0x95b, 0x95c, 0x3, 0x2, 0x2, 0x2, 0x95c, 
       0x95d, 0x7, 0x91, 0x2, 0x2, 0x95d, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x95e, 
       0x95f, 0x9, 0x7, 0x2, 0x2, 0x95f, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x960, 
       0x961, 0x7, 0x5a, 0x2, 0x2, 0x961, 0x962, 0x5, 0x102, 0x82, 0x2, 
       0x962, 0x963, 0x7, 0x98, 0x2, 0x2, 0x963, 0x965, 0x5, 0x1fc, 0xff, 
       0x2, 0x964, 0x966, 0x5, 0x1c8, 0xe5, 0x2, 0x965, 0x964, 0x3, 0x2, 
       0x2, 0x2, 0x965, 0x966, 0x3, 0x2, 0x2, 0x2, 0x966, 0x969, 0x3, 0x2, 
       0x2, 0x2, 0x967, 0x968, 0x7, 0x8e, 0x2, 0x2, 0x968, 0x96a, 0x5, 0xce, 
       0x68, 0x2, 0x969, 0x967, 0x3, 0x2, 0x2, 0x2, 0x969, 0x96a, 0x3, 0x2, 
       0x2, 0x2, 0x96a, 0x96b, 0x3, 0x2, 0x2, 0x2, 0x96b, 0x96c, 0x7, 0x91, 
       0x2, 0x2, 0x96c, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x96d, 0x96e, 0x9, 0xe, 
       0x2, 0x2, 0x96e, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x96f, 0x974, 0x5, 0x13e, 
       0xa0, 0x2, 0x970, 0x971, 0x7, 0x92, 0x2, 0x2, 0x971, 0x973, 0x5, 
       0x13e, 0xa0, 0x2, 0x972, 0x970, 0x3, 0x2, 0x2, 0x2, 0x973, 0x976, 
       0x3, 
  };
  static uint16_t serializedATNSegment1[] = {
    0x2, 0x2, 0x2, 0x974, 0x972, 0x3, 0x2, 0x2, 0x2, 0x974, 0x975, 0x3, 
       0x2, 0x2, 0x2, 0x975, 0x97a, 0x3, 0x2, 0x2, 0x2, 0x976, 0x974, 0x3, 
       0x2, 0x2, 0x2, 0x977, 0x97a, 0x7, 0x41, 0x2, 0x2, 0x978, 0x97a, 0x7, 
       0x8, 0x2, 0x2, 0x979, 0x96f, 0x3, 0x2, 0x2, 0x2, 0x979, 0x977, 0x3, 
       0x2, 0x2, 0x2, 0x979, 0x978, 0x3, 0x2, 0x2, 0x2, 0x97a, 0x1cb, 0x3, 
       0x2, 0x2, 0x2, 0x97b, 0x984, 0x7, 0x96, 0x2, 0x2, 0x97c, 0x981, 0x5, 
       0x13e, 0xa0, 0x2, 0x97d, 0x97e, 0x7, 0x92, 0x2, 0x2, 0x97e, 0x980, 
       0x5, 0x13e, 0xa0, 0x2, 0x97f, 0x97d, 0x3, 0x2, 0x2, 0x2, 0x980, 0x983, 
       0x3, 0x2, 0x2, 0x2, 0x981, 0x97f, 0x3, 0x2, 0x2, 0x2, 0x981, 0x982, 
       0x3, 0x2, 0x2, 0x2, 0x982, 0x985, 0x3, 0x2, 0x2, 0x2, 0x983, 0x981, 
       0x3, 0x2, 0x2, 0x2, 0x984, 0x97c, 0x3, 0x2, 0x2, 0x2, 0x984, 0x985, 
       0x3, 0x2, 0x2, 0x2, 0x985, 0x988, 0x3, 0x2, 0x2, 0x2, 0x986, 0x987, 
       0x7, 0x54, 0x2, 0x2, 0x987, 0x989, 0x5, 0x13e, 0xa0, 0x2, 0x988, 
       0x986, 0x3, 0x2, 0x2, 0x2, 0x988, 0x989, 0x3, 0x2, 0x2, 0x2, 0x989, 
       0x98a, 0x3, 0x2, 0x2, 0x2, 0x98a, 0x98b, 0x7, 0x97, 0x2, 0x2, 0x98b, 
       0x1cd, 0x3, 0x2, 0x2, 0x2, 0x98c, 0x98e, 0x9, 0xf, 0x2, 0x2, 0x98d, 
       0x98c, 0x3, 0x2, 0x2, 0x2, 0x98d, 0x98e, 0x3, 0x2, 0x2, 0x2, 0x98e, 
       0x98f, 0x3, 0x2, 0x2, 0x2, 0x98f, 0x995, 0x5, 0x202, 0x102, 0x2, 
       0x990, 0x991, 0x5, 0xe, 0x8, 0x2, 0x991, 0x992, 0x5, 0x202, 0x102, 
       0x2, 0x992, 0x994, 0x3, 0x2, 0x2, 0x2, 0x993, 0x990, 0x3, 0x2, 0x2, 
       0x2, 0x994, 0x997, 0x3, 0x2, 0x2, 0x2, 0x995, 0x993, 0x3, 0x2, 0x2, 
       0x2, 0x995, 0x996, 0x3, 0x2, 0x2, 0x2, 0x996, 0x1cf, 0x3, 0x2, 0x2, 
       0x2, 0x997, 0x995, 0x3, 0x2, 0x2, 0x2, 0x998, 0x99a, 0x5, 0x12a, 
       0x96, 0x2, 0x999, 0x998, 0x3, 0x2, 0x2, 0x2, 0x999, 0x99a, 0x3, 0x2, 
       0x2, 0x2, 0x99a, 0x99b, 0x3, 0x2, 0x2, 0x2, 0x99b, 0x99c, 0x5, 0x1ce, 
       0xe8, 0x2, 0x99c, 0x99d, 0x7, 0x89, 0x2, 0x2, 0x99d, 0x99f, 0x5, 
       0x1ce, 0xe8, 0x2, 0x99e, 0x9a0, 0x5, 0x20c, 0x107, 0x2, 0x99f, 0x99e, 
       0x3, 0x2, 0x2, 0x2, 0x99f, 0x9a0, 0x3, 0x2, 0x2, 0x2, 0x9a0, 0x9a1, 
       0x3, 0x2, 0x2, 0x2, 0x9a1, 0x9a2, 0x7, 0x91, 0x2, 0x2, 0x9a2, 0x1d1, 
       0x3, 0x2, 0x2, 0x2, 0x9a3, 0x9a4, 0x7, 0x70, 0x2, 0x2, 0x9a4, 0x9a5, 
       0x5, 0x56, 0x2c, 0x2, 0x9a5, 0x9a6, 0x7, 0x8c, 0x2, 0x2, 0x9a6, 0x9a7, 
       0x5, 0x1dc, 0xef, 0x2, 0x9a7, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x9a8, 0x9aa, 
       0x5, 0x12a, 0x96, 0x2, 0x9a9, 0x9a8, 0x3, 0x2, 0x2, 0x2, 0x9a9, 0x9aa, 
       0x3, 0x2, 0x2, 0x2, 0x9aa, 0x9ab, 0x3, 0x2, 0x2, 0x2, 0x9ab, 0x9ac, 
       0x7, 0x14, 0x2, 0x2, 0x9ac, 0x9ad, 0x5, 0xce, 0x68, 0x2, 0x9ad, 0x9af, 
       0x7, 0x6c, 0x2, 0x2, 0x9ae, 0x9b0, 0x5, 0x1d2, 0xea, 0x2, 0x9af, 
       0x9ae, 0x3, 0x2, 0x2, 0x2, 0x9b0, 0x9b1, 0x3, 0x2, 0x2, 0x2, 0x9b1, 
       0x9af, 0x3, 0x2, 0x2, 0x2, 0x9b1, 0x9b2, 0x3, 0x2, 0x2, 0x2, 0x9b2, 
       0x9b3, 0x3, 0x2, 0x2, 0x2, 0x9b3, 0x9b4, 0x7, 0x1a, 0x2, 0x2, 0x9b4, 
       0x9b6, 0x7, 0x14, 0x2, 0x2, 0x9b5, 0x9b7, 0x5, 0x100, 0x81, 0x2, 
       0x9b6, 0x9b5, 0x3, 0x2, 0x2, 0x2, 0x9b6, 0x9b7, 0x3, 0x2, 0x2, 0x2, 
       0x9b7, 0x9b8, 0x3, 0x2, 0x2, 0x2, 0x9b8, 0x9b9, 0x7, 0x91, 0x2, 0x2, 
       0x9b9, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x9ba, 0x9bc, 0x5, 0x12a, 0x96, 
       0x2, 0x9bb, 0x9ba, 0x3, 0x2, 0x2, 0x2, 0x9bb, 0x9bc, 0x3, 0x2, 0x2, 
       0x2, 0x9bc, 0x9bd, 0x3, 0x2, 0x2, 0x2, 0x9bd, 0x9be, 0x7, 0x27, 0x2, 
       0x2, 0x9be, 0x9bf, 0x5, 0x72, 0x3a, 0x2, 0x9bf, 0x9c0, 0x7, 0x6c, 
       0x2, 0x2, 0x9c0, 0x9c8, 0x5, 0x1dc, 0xef, 0x2, 0x9c1, 0x9c2, 0x7, 
       0x1d, 0x2, 0x2, 0x9c2, 0x9c3, 0x5, 0x72, 0x3a, 0x2, 0x9c3, 0x9c4, 
       0x7, 0x6c, 0x2, 0x2, 0x9c4, 0x9c5, 0x5, 0x1dc, 0xef, 0x2, 0x9c5, 
       0x9c7, 0x3, 0x2, 0x2, 0x2, 0x9c6, 0x9c1, 0x3, 0x2, 0x2, 0x2, 0x9c7, 
       0x9ca, 0x3, 0x2, 0x2, 0x2, 0x9c8, 0x9c6, 0x3, 0x2, 0x2, 0x2, 0x9c8, 
       0x9c9, 0x3, 0x2, 0x2, 0x2, 0x9c9, 0x9cd, 0x3, 0x2, 0x2, 0x2, 0x9ca, 
       0x9c8, 0x3, 0x2, 0x2, 0x2, 0x9cb, 0x9cc, 0x7, 0x1c, 0x2, 0x2, 0x9cc, 
       0x9ce, 0x5, 0x1dc, 0xef, 0x2, 0x9cd, 0x9cb, 0x3, 0x2, 0x2, 0x2, 0x9cd, 
       0x9ce, 0x3, 0x2, 0x2, 0x2, 0x9ce, 0x9cf, 0x3, 0x2, 0x2, 0x2, 0x9cf, 
       0x9d0, 0x7, 0x1a, 0x2, 0x2, 0x9d0, 0x9d2, 0x7, 0x6c, 0x2, 0x2, 0x9d1, 
       0x9d3, 0x5, 0x100, 0x81, 0x2, 0x9d2, 0x9d1, 0x3, 0x2, 0x2, 0x2, 0x9d2, 
       0x9d3, 0x3, 0x2, 0x2, 0x2, 0x9d3, 0x9d4, 0x3, 0x2, 0x2, 0x2, 0x9d4, 
       0x9d5, 0x7, 0x91, 0x2, 0x2, 0x9d5, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x9d6, 
       0x9d8, 0x5, 0x12a, 0x96, 0x2, 0x9d7, 0x9d6, 0x3, 0x2, 0x2, 0x2, 0x9d7, 
       0x9d8, 0x3, 0x2, 0x2, 0x2, 0x9d8, 0x9d9, 0x3, 0x2, 0x2, 0x2, 0x9d9, 
       0x9db, 0x7, 0x48, 0x2, 0x2, 0x9da, 0x9dc, 0x7, 0x2c, 0x2, 0x2, 0x9db, 
       0x9da, 0x3, 0x2, 0x2, 0x2, 0x9db, 0x9dc, 0x3, 0x2, 0x2, 0x2, 0x9dc, 
       0x9dd, 0x3, 0x2, 0x2, 0x2, 0x9dd, 0x9de, 0x5, 0x178, 0xbd, 0x2, 0x9de, 
       0x9df, 0x7, 0xe, 0x2, 0x2, 0x9df, 0x9e0, 0x5, 0x17a, 0xbe, 0x2, 0x9e0, 
       0x9e1, 0x7, 0x1a, 0x2, 0x2, 0x9e1, 0x9e3, 0x7, 0x48, 0x2, 0x2, 0x9e2, 
       0x9e4, 0x5, 0x100, 0x81, 0x2, 0x9e3, 0x9e2, 0x3, 0x2, 0x2, 0x2, 0x9e3, 
       0x9e4, 0x3, 0x2, 0x2, 0x2, 0x9e4, 0x9e5, 0x3, 0x2, 0x2, 0x2, 0x9e5, 
       0x9e6, 0x7, 0x91, 0x2, 0x2, 0x9e6, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x9e7, 
       0x9f1, 0x5, 0x1d0, 0xe9, 0x2, 0x9e8, 0x9f1, 0x5, 0x1d6, 0xec, 0x2, 
       0x9e9, 0x9f1, 0x5, 0x1d4, 0xeb, 0x2, 0x9ea, 0x9f1, 0x5, 0x1d8, 0xed, 
       0x2, 0x9eb, 0x9ed, 0x5, 0x12a, 0x96, 0x2, 0x9ec, 0x9eb, 0x3, 0x2, 
       0x2, 0x2, 0x9ec, 0x9ed, 0x3, 0x2, 0x2, 0x2, 0x9ed, 0x9ee, 0x3, 0x2, 
       0x2, 0x2, 0x9ee, 0x9ef, 0x7, 0x3c, 0x2, 0x2, 0x9ef, 0x9f1, 0x7, 0x91, 
       0x2, 0x2, 0x9f0, 0x9e7, 0x3, 0x2, 0x2, 0x2, 0x9f0, 0x9e8, 0x3, 0x2, 
       0x2, 0x2, 0x9f0, 0x9e9, 0x3, 0x2, 0x2, 0x2, 0x9f0, 0x9ea, 0x3, 0x2, 
       0x2, 0x2, 0x9f0, 0x9ec, 0x3, 0x2, 0x2, 0x2, 0x9f1, 0x1db, 0x3, 0x2, 
       0x2, 0x2, 0x9f2, 0x9f4, 0x5, 0x1da, 0xee, 0x2, 0x9f3, 0x9f2, 0x3, 
       0x2, 0x2, 0x2, 0x9f4, 0x9f7, 0x3, 0x2, 0x2, 0x2, 0x9f5, 0x9f3, 0x3, 
       0x2, 0x2, 0x2, 0x9f5, 0x9f6, 0x3, 0x2, 0x2, 0x2, 0x9f6, 0x1dd, 0x3, 
       0x2, 0x2, 0x2, 0x9f7, 0x9f5, 0x3, 0x2, 0x2, 0x2, 0x9f8, 0x9f9, 0x7, 
       0x5d, 0x2, 0x2, 0x9f9, 0x9fa, 0x5, 0x1ce, 0xe8, 0x2, 0x9fa, 0x9fb, 
       0x7, 0x92, 0x2, 0x2, 0x9fb, 0x9fc, 0x5, 0x1ce, 0xe8, 0x2, 0x9fc, 
       0xa00, 0x3, 0x2, 0x2, 0x2, 0x9fd, 0x9fe, 0x7, 0x39, 0x2, 0x2, 0x9fe, 
       0xa00, 0x5, 0x1ce, 0xe8, 0x2, 0x9ff, 0x9f8, 0x3, 0x2, 0x2, 0x2, 0x9ff, 
       0x9fd, 0x3, 0x2, 0x2, 0x2, 0xa00, 0x1df, 0x3, 0x2, 0x2, 0x2, 0xa01, 
       0xa02, 0x7, 0x4a, 0x2, 0x2, 0xa02, 0xa03, 0x5, 0x102, 0x82, 0x2, 
       0xa03, 0xa04, 0x7, 0x98, 0x2, 0x2, 0xa04, 0xa05, 0x5, 0x1fc, 0xff, 
       0x2, 0xa05, 0xa06, 0x5, 0x1de, 0xf0, 0x2, 0xa06, 0xa07, 0x7, 0x91, 
       0x2, 0x2, 0xa07, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0xa08, 0xa09, 0x7, 0x2f, 
       0x2, 0x2, 0xa09, 0xa0a, 0x5, 0x18e, 0xc8, 0x2, 0xa0a, 0xa0b, 0x7, 
       0x6f, 0x2, 0x2, 0xa0b, 0xa0c, 0x5, 0xce, 0x68, 0x2, 0xa0c, 0xa0d, 
       0x7, 0x91, 0x2, 0x2, 0xa0d, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0xa0e, 0xa0f, 
       0x7, 0x60, 0x2, 0x2, 0xa0f, 0xa10, 0x5, 0x100, 0x81, 0x2, 0xa10, 
       0xa11, 0x7, 0x2c, 0x2, 0x2, 0xa11, 0xa12, 0x5, 0x1e6, 0xf4, 0x2, 
       0xa12, 0xa13, 0x7, 0x91, 0x2, 0x2, 0xa13, 0x1e5, 0x3, 0x2, 0x2, 0x2, 
       0xa14, 0xa16, 0x5, 0x13e, 0xa0, 0x2, 0xa15, 0xa17, 0x5, 0x106, 0x84, 
       0x2, 0xa16, 0xa15, 0x3, 0x2, 0x2, 0x2, 0xa16, 0xa17, 0x3, 0x2, 0x2, 
       0x2, 0xa17, 0xa1e, 0x3, 0x2, 0x2, 0x2, 0xa18, 0xa19, 0x7, 0x66, 0x2, 
       0x2, 0xa19, 0xa1a, 0x5, 0xce, 0x68, 0x2, 0xa1a, 0xa1b, 0x7, 0x5, 
       0x2, 0x2, 0xa1b, 0xa1c, 0x5, 0xce, 0x68, 0x2, 0xa1c, 0xa1d, 0x7, 
       0x64, 0x2, 0x2, 0xa1d, 0xa1f, 0x3, 0x2, 0x2, 0x2, 0xa1e, 0xa18, 0x3, 
       0x2, 0x2, 0x2, 0xa1e, 0xa1f, 0x3, 0x2, 0x2, 0x2, 0xa1f, 0x1e7, 0x3, 
       0x2, 0x2, 0x2, 0xa20, 0xa21, 0x5, 0x1f2, 0xfa, 0x2, 0xa21, 0xa22, 
       0x7, 0x2c, 0x2, 0x2, 0xa22, 0xa23, 0x5, 0x1ee, 0xf8, 0x2, 0xa23, 
       0xa24, 0x7, 0xe, 0x2, 0x2, 0xa24, 0xa25, 0x5, 0x1f8, 0xfd, 0x2, 0xa25, 
       0xa27, 0x7, 0x1a, 0x2, 0x2, 0xa26, 0xa28, 0x5, 0x1f0, 0xf9, 0x2, 
       0xa27, 0xa26, 0x3, 0x2, 0x2, 0x2, 0xa27, 0xa28, 0x3, 0x2, 0x2, 0x2, 
       0xa28, 0xa2a, 0x3, 0x2, 0x2, 0x2, 0xa29, 0xa2b, 0x5, 0x9c, 0x4f, 
       0x2, 0xa2a, 0xa29, 0x3, 0x2, 0x2, 0x2, 0xa2a, 0xa2b, 0x3, 0x2, 0x2, 
       0x2, 0xa2b, 0xa2c, 0x3, 0x2, 0x2, 0x2, 0xa2c, 0xa2d, 0x7, 0x91, 0x2, 
       0x2, 0xa2d, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0xa2e, 0xa2f, 0x5, 0x1f2, 
       0xfa, 0x2, 0xa2f, 0xa30, 0x7, 0x91, 0x2, 0x2, 0xa30, 0x1eb, 0x3, 
       0x2, 0x2, 0x2, 0xa31, 0xa3f, 0x5, 0x1ea, 0xf6, 0x2, 0xa32, 0xa3f, 
       0x5, 0x1e8, 0xf5, 0x2, 0xa33, 0xa3f, 0x5, 0x20e, 0x108, 0x2, 0xa34, 
       0xa3f, 0x5, 0x1fa, 0xfe, 0x2, 0xa35, 0xa3f, 0x5, 0x8a, 0x46, 0x2, 
       0xa36, 0xa3f, 0x5, 0x220, 0x111, 0x2, 0xa37, 0xa3f, 0x5, 0xd4, 0x6b, 
       0x2, 0xa38, 0xa3f, 0x5, 0x12, 0xa, 0x2, 0xa39, 0xa3f, 0x5, 0x2e, 
       0x18, 0x2, 0xa3a, 0xa3f, 0x5, 0x32, 0x1a, 0x2, 0xa3b, 0xa3f, 0x5, 
       0x216, 0x10c, 0x2, 0xa3c, 0xa3f, 0x5, 0xfc, 0x7f, 0x2, 0xa3d, 0xa3f, 
       0x5, 0xfa, 0x7e, 0x2, 0xa3e, 0xa31, 0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa32, 
       0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa33, 0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa34, 
       0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa35, 0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa36, 
       0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa37, 0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa38, 
       0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa39, 0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa3a, 
       0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa3b, 0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa3c, 
       0x3, 0x2, 0x2, 0x2, 0xa3e, 0xa3d, 0x3, 0x2, 0x2, 0x2, 0xa3f, 0x1ed, 
       0x3, 0x2, 0x2, 0x2, 0xa40, 0xa42, 0x5, 0x1ec, 0xf7, 0x2, 0xa41, 0xa40, 
       0x3, 0x2, 0x2, 0x2, 0xa42, 0xa45, 0x3, 0x2, 0x2, 0x2, 0xa43, 0xa41, 
       0x3, 0x2, 0x2, 0x2, 0xa43, 0xa44, 0x3, 0x2, 0x2, 0x2, 0xa44, 0x1ef, 
       0x3, 0x2, 0x2, 0x2, 0xa45, 0xa43, 0x3, 0x2, 0x2, 0x2, 0xa46, 0xa47, 
       0x9, 0x10, 0x2, 0x2, 0xa47, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0xa48, 0xa4b, 
       0x5, 0x1f4, 0xfb, 0x2, 0xa49, 0xa4b, 0x5, 0x1f6, 0xfc, 0x2, 0xa4a, 
       0xa48, 0x3, 0x2, 0x2, 0x2, 0xa4a, 0xa49, 0x3, 0x2, 0x2, 0x2, 0xa4b, 
       0x1f3, 0x3, 0x2, 0x2, 0x2, 0xa4c, 0xa4d, 0x7, 0x47, 0x2, 0x2, 0xa4d, 
       0xa52, 0x5, 0x9c, 0x4f, 0x2, 0xa4e, 0xa4f, 0x7, 0x94, 0x2, 0x2, 0xa4f, 
       0xa50, 0x5, 0xdc, 0x6f, 0x2, 0xa50, 0xa51, 0x7, 0x95, 0x2, 0x2, 0xa51, 
       0xa53, 0x3, 0x2, 0x2, 0x2, 0xa52, 0xa4e, 0x3, 0x2, 0x2, 0x2, 0xa52, 
       0xa53, 0x3, 0x2, 0x2, 0x2, 0xa53, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0xa54, 
       0xa56, 0x9, 0x11, 0x2, 0x2, 0xa55, 0xa54, 0x3, 0x2, 0x2, 0x2, 0xa55, 
       0xa56, 0x3, 0x2, 0x2, 0x2, 0xa56, 0xa57, 0x3, 0x2, 0x2, 0x2, 0xa57, 
       0xa58, 0x7, 0x22, 0x2, 0x2, 0xa58, 0xa5d, 0x5, 0x9c, 0x4f, 0x2, 0xa59, 
       0xa5a, 0x7, 0x94, 0x2, 0x2, 0xa5a, 0xa5b, 0x5, 0xdc, 0x6f, 0x2, 0xa5b, 
       0xa5c, 0x7, 0x95, 0x2, 0x2, 0xa5c, 0xa5e, 0x3, 0x2, 0x2, 0x2, 0xa5d, 
       0xa59, 0x3, 0x2, 0x2, 0x2, 0xa5d, 0xa5e, 0x3, 0x2, 0x2, 0x2, 0xa5e, 
       0xa5f, 0x3, 0x2, 0x2, 0x2, 0xa5f, 0xa60, 0x7, 0x54, 0x2, 0x2, 0xa60, 
       0xa61, 0x5, 0x1fc, 0xff, 0x2, 0xa61, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0xa62, 
       0xa64, 0x5, 0x1b4, 0xdb, 0x2, 0xa63, 0xa62, 0x3, 0x2, 0x2, 0x2, 0xa64, 
       0xa67, 0x3, 0x2, 0x2, 0x2, 0xa65, 0xa63, 0x3, 0x2, 0x2, 0x2, 0xa65, 
       0xa66, 0x3, 0x2, 0x2, 0x2, 0xa66, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0xa67, 
       0xa65, 0x3, 0x2, 0x2, 0x2, 0xa68, 0xa69, 0x7, 0x61, 0x2, 0x2, 0xa69, 
       0xa6a, 0x5, 0x100, 0x81, 0x2, 0xa6a, 0xa6b, 0x7, 0x2c, 0x2, 0x2, 
       0xa6b, 0xa6c, 0x5, 0x1fc, 0xff, 0x2, 0xa6c, 0xa6d, 0x7, 0x91, 0x2, 
       0x2, 0xa6d, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0xa6e, 0xa70, 0x5, 0x14a, 
       0xa6, 0x2, 0xa6f, 0xa71, 0x5, 0x14a, 0xa6, 0x2, 0xa70, 0xa6f, 0x3, 
       0x2, 0x2, 0x2, 0xa70, 0xa71, 0x3, 0x2, 0x2, 0x2, 0xa71, 0xa75, 0x3, 
       0x2, 0x2, 0x2, 0xa72, 0xa74, 0x5, 0x90, 0x49, 0x2, 0xa73, 0xa72, 
       0x3, 0x2, 0x2, 0x2, 0xa74, 0xa77, 0x3, 0x2, 0x2, 0x2, 0xa75, 0xa73, 
       0x3, 0x2, 0x2, 0x2, 0xa75, 0xa76, 0x3, 0x2, 0x2, 0x2, 0xa76, 0xa79, 
       0x3, 0x2, 0x2, 0x2, 0xa77, 0xa75, 0x3, 0x2, 0x2, 0x2, 0xa78, 0xa7a, 
       0x5, 0x20c, 0x107, 0x2, 0xa79, 0xa78, 0x3, 0x2, 0x2, 0x2, 0xa79, 
       0xa7a, 0x3, 0x2, 0x2, 0x2, 0xa7a, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0xa7b, 
       0xa80, 0x5, 0x100, 0x81, 0x2, 0xa7c, 0xa80, 0x7, 0x85, 0x2, 0x2, 
       0xa7d, 0xa80, 0x7, 0x86, 0x2, 0x2, 0xa7e, 0xa80, 0x7, 0x8, 0x2, 0x2, 
       0xa7f, 0xa7b, 0x3, 0x2, 0x2, 0x2, 0xa7f, 0xa7c, 0x3, 0x2, 0x2, 0x2, 
       0xa7f, 0xa7d, 0x3, 0x2, 0x2, 0x2, 0xa7f, 0xa7e, 0x3, 0x2, 0x2, 0x2, 
       0xa80, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0xa81, 0xa84, 0x5, 0x13e, 0xa0, 
       0x2, 0xa82, 0xa84, 0x5, 0x10, 0x9, 0x2, 0xa83, 0xa81, 0x3, 0x2, 0x2, 
       0x2, 0xa83, 0xa82, 0x3, 0x2, 0x2, 0x2, 0xa84, 0x201, 0x3, 0x2, 0x2, 
       0x2, 0xa85, 0xa8b, 0x5, 0xd2, 0x6a, 0x2, 0xa86, 0xa87, 0x5, 0x13c, 
       0x9f, 0x2, 0xa87, 0xa88, 0x5, 0xd2, 0x6a, 0x2, 0xa88, 0xa8a, 0x3, 
       0x2, 0x2, 0x2, 0xa89, 0xa86, 0x3, 0x2, 0x2, 0x2, 0xa8a, 0xa8d, 0x3, 
       0x2, 0x2, 0x2, 0xa8b, 0xa89, 0x3, 0x2, 0x2, 0x2, 0xa8b, 0xa8c, 0x3, 
       0x2, 0x2, 0x2, 0xa8c, 0x203, 0x3, 0x2, 0x2, 0x2, 0xa8d, 0xa8b, 0x3, 
       0x2, 0x2, 0x2, 0xa8e, 0xa91, 0x5, 0x13e, 0xa0, 0x2, 0xa8f, 0xa90, 
       0x7, 0x65, 0x2, 0x2, 0xa90, 0xa92, 0x5, 0x13e, 0xa0, 0x2, 0xa91, 
       0xa8f, 0x3, 0x2, 0x2, 0x2, 0xa91, 0xa92, 0x3, 0x2, 0x2, 0x2, 0xa92, 
       0x205, 0x3, 0x2, 0x2, 0x2, 0xa93, 0xa94, 0x7, 0x62, 0x2, 0x2, 0xa94, 
       0xa95, 0x5, 0x102, 0x82, 0x2, 0xa95, 0xa96, 0x7, 0x98, 0x2, 0x2, 
       0xa96, 0xa97, 0x5, 0x1e6, 0xf4, 0x2, 0xa97, 0xa98, 0x7, 0x91, 0x2, 
       0x2, 0xa98, 0x207, 0x3, 0x2, 0x2, 0x2, 0xa99, 0xa9b, 0x5, 0x102, 
       0x82, 0x2, 0xa9a, 0xa9c, 0x5, 0x20c, 0x107, 0x2, 0xa9b, 0xa9a, 0x3, 
       0x2, 0x2, 0x2, 0xa9b, 0xa9c, 0x3, 0x2, 0x2, 0x2, 0xa9c, 0xa9f, 0x3, 
       0x2, 0x2, 0x2, 0xa9d, 0xa9e, 0x7, 0x8e, 0x2, 0x2, 0xa9e, 0xaa0, 0x5, 
       0xce, 0x68, 0x2, 0xa9f, 0xa9d, 0x3, 0x2, 0x2, 0x2, 0xa9f, 0xaa0, 
       0x3, 0x2, 0x2, 0x2, 0xaa0, 0xaa1, 0x3, 0x2, 0x2, 0x2, 0xaa1, 0xaa2, 
       0x7, 0x64, 0x2, 0x2, 0xaa2, 0x209, 0x3, 0x2, 0x2, 0x2, 0xaa3, 0xaa4, 
       0x7, 0x20, 0x2, 0x2, 0xaa4, 0xaa5, 0x5, 0xce, 0x68, 0x2, 0xaa5, 0x20b, 
       0x3, 0x2, 0x2, 0x2, 0xaa6, 0xaa7, 0x7, 0x66, 0x2, 0x2, 0xaa7, 0xaa8, 
       0x5, 0xce, 0x68, 0x2, 0xaa8, 0x20d, 0x3, 0x2, 0x2, 0x2, 0xaa9, 0xaaa, 
       0x7, 0x68, 0x2, 0x2, 0xaaa, 0xaad, 0x5, 0x100, 0x81, 0x2, 0xaab, 
       0xaac, 0x7, 0x2c, 0x2, 0x2, 0xaac, 0xaae, 0x5, 0x210, 0x109, 0x2, 
       0xaad, 0xaab, 0x3, 0x2, 0x2, 0x2, 0xaad, 0xaae, 0x3, 0x2, 0x2, 0x2, 
       0xaae, 0xaaf, 0x3, 0x2, 0x2, 0x2, 0xaaf, 0xab0, 0x7, 0x91, 0x2, 0x2, 
       0xab0, 0x20f, 0x3, 0x2, 0x2, 0x2, 0xab1, 0xab6, 0x5, 0x1a4, 0xd3, 
       0x2, 0xab2, 0xab6, 0x5, 0x62, 0x32, 0x2, 0xab3, 0xab6, 0x5, 0x4, 
       0x3, 0x2, 0xab4, 0xab6, 0x5, 0xda, 0x6e, 0x2, 0xab5, 0xab1, 0x3, 
       0x2, 0x2, 0x2, 0xab5, 0xab2, 0x3, 0x2, 0x2, 0x2, 0xab5, 0xab3, 0x3, 
       0x2, 0x2, 0x2, 0xab5, 0xab4, 0x3, 0x2, 0x2, 0x2, 0xab6, 0x211, 0x3, 
       0x2, 0x2, 0x2, 0xab7, 0xab8, 0x7, 0xb, 0x2, 0x2, 0xab8, 0xab9, 0x7, 
       0x94, 0x2, 0x2, 0xab9, 0xabe, 0x5, 0x10a, 0x86, 0x2, 0xaba, 0xabb, 
       0x7, 0x92, 0x2, 0x2, 0xabb, 0xabd, 0x5, 0x10a, 0x86, 0x2, 0xabc, 
       0xaba, 0x3, 0x2, 0x2, 0x2, 0xabd, 0xac0, 0x3, 0x2, 0x2, 0x2, 0xabe, 
       0xabc, 0x3, 0x2, 0x2, 0x2, 0xabe, 0xabf, 0x3, 0x2, 0x2, 0x2, 0xabf, 
       0xac1, 0x3, 0x2, 0x2, 0x2, 0xac0, 0xabe, 0x3, 0x2, 0x2, 0x2, 0xac1, 
       0xac2, 0x7, 0x95, 0x2, 0x2, 0xac2, 0xac3, 0x7, 0x3d, 0x2, 0x2, 0xac3, 
       0xac4, 0x5, 0x1fc, 0xff, 0x2, 0xac4, 0x213, 0x3, 0x2, 0x2, 0x2, 0xac5, 
       0xac6, 0x7, 0xb, 0x2, 0x2, 0xac6, 0xac7, 0x7, 0x94, 0x2, 0x2, 0xac7, 
       0xacc, 0x5, 0x10a, 0x86, 0x2, 0xac8, 0xac9, 0x7, 0x92, 0x2, 0x2, 
       0xac9, 0xacb, 0x5, 0x10a, 0x86, 0x2, 0xaca, 0xac8, 0x3, 0x2, 0x2, 
       0x2, 0xacb, 0xace, 0x3, 0x2, 0x2, 0x2, 0xacc, 0xaca, 0x3, 0x2, 0x2, 
       0x2, 0xacc, 0xacd, 0x3, 0x2, 0x2, 0x2, 0xacd, 0xacf, 0x3, 0x2, 0x2, 
       0x2, 0xace, 0xacc, 0x3, 0x2, 0x2, 0x2, 0xacf, 0xad0, 0x7, 0x95, 0x2, 
       0x2, 0xad0, 0xad1, 0x7, 0x3d, 0x2, 0x2, 0xad1, 0xad2, 0x5, 0x1e6, 
       0xf4, 0x2, 0xad2, 0x215, 0x3, 0x2, 0x2, 0x2, 0xad3, 0xad4, 0x7, 0x6c, 
       0x2, 0x2, 0xad4, 0xad9, 0x5, 0x14a, 0xa6, 0x2, 0xad5, 0xad6, 0x7, 
       0x92, 0x2, 0x2, 0xad6, 0xad8, 0x5, 0x14a, 0xa6, 0x2, 0xad7, 0xad5, 
       0x3, 0x2, 0x2, 0x2, 0xad8, 0xadb, 0x3, 0x2, 0x2, 0x2, 0xad9, 0xad7, 
       0x3, 0x2, 0x2, 0x2, 0xad9, 0xada, 0x3, 0x2, 0x2, 0x2, 0xada, 0xadc, 
       0x3, 0x2, 0x2, 0x2, 0xadb, 0xad9, 0x3, 0x2, 0x2, 0x2, 0xadc, 0xadd, 
       0x7, 0x91, 0x2, 0x2, 0xadd, 0x217, 0x3, 0x2, 0x2, 0x2, 0xade, 0xae0, 
       0x5, 0x12a, 0x96, 0x2, 0xadf, 0xade, 0x3, 0x2, 0x2, 0x2, 0xadf, 0xae0, 
       0x3, 0x2, 0x2, 0x2, 0xae0, 0xae1, 0x3, 0x2, 0x2, 0x2, 0xae1, 0xaeb, 
       0x5, 0x21a, 0x10e, 0x2, 0xae2, 0xae4, 0x5, 0x12a, 0x96, 0x2, 0xae3, 
       0xae2, 0x3, 0x2, 0x2, 0x2, 0xae3, 0xae4, 0x3, 0x2, 0x2, 0x2, 0xae4, 
       0xae5, 0x3, 0x2, 0x2, 0x2, 0xae5, 0xaeb, 0x5, 0x21c, 0x10f, 0x2, 
       0xae6, 0xae8, 0x5, 0x12a, 0x96, 0x2, 0xae7, 0xae6, 0x3, 0x2, 0x2, 
       0x2, 0xae7, 0xae8, 0x3, 0x2, 0x2, 0x2, 0xae8, 0xae9, 0x3, 0x2, 0x2, 
       0x2, 0xae9, 0xaeb, 0x5, 0x21e, 0x110, 0x2, 0xaea, 0xadf, 0x3, 0x2, 
       0x2, 0x2, 0xaea, 0xae3, 0x3, 0x2, 0x2, 0x2, 0xaea, 0xae7, 0x3, 0x2, 
       0x2, 0x2, 0xaeb, 0x219, 0x3, 0x2, 0x2, 0x2, 0xaec, 0xaed, 0x5, 0x200, 
       0x101, 0x2, 0xaed, 0xaee, 0x7, 0x8e, 0x2, 0x2, 0xaee, 0xaef, 0x5, 
       0xce, 0x68, 0x2, 0xaef, 0xaf0, 0x7, 0x91, 0x2, 0x2, 0xaf0, 0x21b, 
       0x3, 0x2, 0x2, 0x2, 0xaf1, 0xaf2, 0x5, 0x200, 0x101, 0x2, 0xaf2, 
       0xaf3, 0x7, 0x8e, 0x2, 0x2, 0xaf3, 0xaf4, 0x5, 0x7e, 0x40, 0x2, 0xaf4, 
       0xaf5, 0x7, 0x91, 0x2, 0x2, 0xaf5, 0x21d, 0x3, 0x2, 0x2, 0x2, 0xaf6, 
       0xaf7, 0x7, 0x6f, 0x2, 0x2, 0xaf7, 0xaf8, 0x5, 0xce, 0x68, 0x2, 0xaf8, 
       0xafa, 0x7, 0x57, 0x2, 0x2, 0xaf9, 0xafb, 0x7, 0xa3, 0x2, 0x2, 0xafa, 
       0xaf9, 0x3, 0x2, 0x2, 0x2, 0xafa, 0xafb, 0x3, 0x2, 0x2, 0x2, 0xafb, 
       0x21f, 0x3, 0x2, 0x2, 0x2, 0xafc, 0xafe, 0x7, 0x59, 0x2, 0x2, 0xafd, 
       0xafc, 0x3, 0x2, 0x2, 0x2, 0xafd, 0xafe, 0x3, 0x2, 0x2, 0x2, 0xafe, 
       0xaff, 0x3, 0x2, 0x2, 0x2, 0xaff, 0xb00, 0x7, 0x6d, 0x2, 0x2, 0xb00, 
       0xb01, 0x5, 0x102, 0x82, 0x2, 0xb01, 0xb02, 0x7, 0x98, 0x2, 0x2, 
       0xb02, 0xb05, 0x5, 0x1fc, 0xff, 0x2, 0xb03, 0xb04, 0x7, 0x8e, 0x2, 
       0x2, 0xb04, 0xb06, 0x5, 0xce, 0x68, 0x2, 0xb05, 0xb03, 0x3, 0x2, 
       0x2, 0x2, 0xb05, 0xb06, 0x3, 0x2, 0x2, 0x2, 0xb06, 0xb07, 0x3, 0x2, 
       0x2, 0x2, 0xb07, 0xb08, 0x7, 0x91, 0x2, 0x2, 0xb08, 0x221, 0x3, 0x2, 
       0x2, 0x2, 0xb09, 0xb0b, 0x5, 0x12a, 0x96, 0x2, 0xb0a, 0xb09, 0x3, 
       0x2, 0x2, 0x2, 0xb0a, 0xb0b, 0x3, 0x2, 0x2, 0x2, 0xb0b, 0xb0c, 0x3, 
       0x2, 0x2, 0x2, 0xb0c, 0xb0e, 0x7, 0x6e, 0x2, 0x2, 0xb0d, 0xb0f, 0x5, 
       0x1ae, 0xd8, 0x2, 0xb0e, 0xb0d, 0x3, 0x2, 0x2, 0x2, 0xb0e, 0xb0f, 
       0x3, 0x2, 0x2, 0x2, 0xb0f, 0xb11, 0x3, 0x2, 0x2, 0x2, 0xb10, 0xb12, 
       0x5, 0x74, 0x3b, 0x2, 0xb11, 0xb10, 0x3, 0x2, 0x2, 0x2, 0xb11, 0xb12, 
       0x3, 0x2, 0x2, 0x2, 0xb12, 0xb14, 0x3, 0x2, 0x2, 0x2, 0xb13, 0xb15, 
       0x5, 0x20a, 0x106, 0x2, 0xb14, 0xb13, 0x3, 0x2, 0x2, 0x2, 0xb14, 
       0xb15, 0x3, 0x2, 0x2, 0x2, 0xb15, 0xb16, 0x3, 0x2, 0x2, 0x2, 0xb16, 
       0xb17, 0x7, 0x91, 0x2, 0x2, 0xb17, 0x223, 0x3, 0x2, 0x2, 0x2, 0xb18, 
       0xb1d, 0x5, 0x226, 0x114, 0x2, 0xb19, 0xb1a, 0x7, 0x92, 0x2, 0x2, 
       0xb1a, 0xb1c, 0x5, 0x226, 0x114, 0x2, 0xb1b, 0xb19, 0x3, 0x2, 0x2, 
       0x2, 0xb1c, 0xb1f, 0x3, 0x2, 0x2, 0x2, 0xb1d, 0xb1b, 0x3, 0x2, 0x2, 
       0x2, 0xb1d, 0xb1e, 0x3, 0x2, 0x2, 0x2, 0xb1e, 0xb22, 0x3, 0x2, 0x2, 
       0x2, 0xb1f, 0xb1d, 0x3, 0x2, 0x2, 0x2, 0xb20, 0xb22, 0x7, 0x69, 0x2, 
       0x2, 0xb21, 0xb18, 0x3, 0x2, 0x2, 0x2, 0xb21, 0xb20, 0x3, 0x2, 0x2, 
       0x2, 0xb22, 0x225, 0x3, 0x2, 0x2, 0x2, 0xb23, 0xb26, 0x5, 0xce, 0x68, 
       0x2, 0xb24, 0xb25, 0x7, 0x6, 0x2, 0x2, 0xb25, 0xb27, 0x5, 0xce, 0x68, 
       0x2, 0xb26, 0xb24, 0x3, 0x2, 0x2, 0x2, 0xb26, 0xb27, 0x3, 0x2, 0x2, 
       0x2, 0xb27, 0x227, 0x3, 0x2, 0x2, 0x2, 0x148, 0x22f, 0x233, 0x239, 
       0x243, 0x24d, 0x256, 0x25b, 0x262, 0x266, 0x26b, 0x277, 0x27a, 0x281, 
       0x287, 0x28b, 0x28f, 0x292, 0x299, 0x29e, 0x2a3, 0x2a7, 0x2ad, 0x2b1, 
       0x2b4, 0x2bc, 0x2c5, 0x2d4, 0x2e3, 0x2e6, 0x2e9, 0x2f0, 0x2f6, 0x313, 
       0x318, 0x31f, 0x321, 0x327, 0x329, 0x330, 0x333, 0x33b, 0x33e, 0x347, 
       0x34e, 0x353, 0x356, 0x35c, 0x367, 0x36f, 0x373, 0x377, 0x37c, 0x384, 
       0x389, 0x396, 0x39d, 0x3a5, 0x3a8, 0x3b1, 0x3b4, 0x3b7, 0x3bc, 0x3c3, 
       0x3c6, 0x3d0, 0x3d4, 0x3d7, 0x3da, 0x3e0, 0x3e4, 0x3e7, 0x3eb, 0x3f0, 
       0x3f3, 0x3f9, 0x3fc, 0x400, 0x403, 0x407, 0x40a, 0x40d, 0x420, 0x42e, 
       0x433, 0x43b, 0x449, 0x44e, 0x45a, 0x45f, 0x46a, 0x46d, 0x474, 0x479, 
       0x47e, 0x48b, 0x49b, 0x4a0, 0x4a5, 0x4aa, 0x4ad, 0x4b2, 0x4bc, 0x4c8, 
       0x4cd, 0x4e0, 0x4e5, 0x4eb, 0x4f2, 0x4fc, 0x500, 0x503, 0x51b, 0x520, 
       0x525, 0x528, 0x52b, 0x532, 0x537, 0x540, 0x545, 0x54b, 0x54f, 0x557, 
       0x55d, 0x561, 0x565, 0x56c, 0x574, 0x57a, 0x580, 0x587, 0x58f, 0x59f, 
       0x5a3, 0x5ab, 0x5b2, 0x5bc, 0x5c1, 0x5ce, 0x5d4, 0x5d9, 0x5de, 0x5e6, 
       0x5eb, 0x5f7, 0x5fb, 0x600, 0x609, 0x616, 0x621, 0x628, 0x646, 0x64a, 
       0x657, 0x65c, 0x661, 0x66b, 0x672, 0x679, 0x682, 0x686, 0x68d, 0x692, 
       0x695, 0x69a, 0x69f, 0x6a7, 0x6b5, 0x6bd, 0x6c5, 0x6cc, 0x6d1, 0x6d8, 
       0x6dc, 0x6e2, 0x6e6, 0x6ea, 0x6f2, 0x6f7, 0x6fc, 0x702, 0x70d, 0x714, 
       0x71d, 0x723, 0x726, 0x72d, 0x73b, 0x73e, 0x744, 0x74a, 0x753, 0x756, 
       0x75a, 0x764, 0x76e, 0x779, 0x780, 0x784, 0x788, 0x78e, 0x796, 0x799, 
       0x79c, 0x7a6, 0x7a9, 0x7b8, 0x7bd, 0x7c6, 0x7c9, 0x7df, 0x7e4, 0x7f4, 
       0x7fa, 0x813, 0x818, 0x826, 0x82b, 0x831, 0x839, 0x83c, 0x84e, 0x853, 
       0x857, 0x85a, 0x861, 0x864, 0x86b, 0x86f, 0x876, 0x880, 0x885, 0x88c, 
       0x891, 0x899, 0x8a6, 0x8ab, 0x8b1, 0x8b6, 0x8bc, 0x8c1, 0x8c7, 0x8cc, 
       0x8d0, 0x8de, 0x8e2, 0x8ed, 0x8ff, 0x90a, 0x90e, 0x913, 0x922, 0x928, 
       0x92e, 0x933, 0x937, 0x93b, 0x93e, 0x943, 0x948, 0x951, 0x95a, 0x965, 
       0x969, 0x974, 0x979, 0x981, 0x984, 0x988, 0x98d, 0x995, 0x999, 0x99f, 
       0x9a9, 0x9b1, 0x9b6, 0x9bb, 0x9c8, 0x9cd, 0x9d2, 0x9d7, 0x9db, 0x9e3, 
       0x9ec, 0x9f0, 0x9f5, 0x9ff, 0xa16, 0xa1e, 0xa27, 0xa2a, 0xa3e, 0xa43, 
       0xa4a, 0xa52, 0xa55, 0xa5d, 0xa65, 0xa70, 0xa75, 0xa79, 0xa7f, 0xa83, 
       0xa8b, 0xa91, 0xa9b, 0xa9f, 0xaad, 0xab5, 0xabe, 0xacc, 0xad9, 0xadf, 
       0xae3, 0xae7, 0xaea, 0xafa, 0xafd, 0xb05, 0xb0a, 0xb0e, 0xb11, 0xb14, 
       0xb1d, 0xb21, 0xb26, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));
  _serializedATN.insert(_serializedATN.end(), serializedATNSegment1,
    serializedATNSegment1 + sizeof(serializedATNSegment1) / sizeof(serializedATNSegment1[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

vhdlParser::Initializer vhdlParser::_init;
