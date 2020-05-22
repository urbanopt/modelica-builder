
// Generated from /var/antlrResult/modelica.g4 by ANTLR 4.8


#include "modelicaListener.h"
#include "modelicaVisitor.h"

#include "modelicaParser.h"


using namespace antlrcpp;
using namespace antlr4;

modelicaParser::modelicaParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

modelicaParser::~modelicaParser() {
  delete _interpreter;
}

std::string modelicaParser::getGrammarFileName() const {
  return "modelica.g4";
}

const std::vector<std::string>& modelicaParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& modelicaParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Stored_definitionContext ------------------------------------------------------------------

modelicaParser::Stored_definitionContext::Stored_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::Within_statementContext *> modelicaParser::Stored_definitionContext::within_statement() {
  return getRuleContexts<modelicaParser::Within_statementContext>();
}

modelicaParser::Within_statementContext* modelicaParser::Stored_definitionContext::within_statement(size_t i) {
  return getRuleContext<modelicaParser::Within_statementContext>(i);
}

std::vector<modelicaParser::Class_definitionContext *> modelicaParser::Stored_definitionContext::class_definition() {
  return getRuleContexts<modelicaParser::Class_definitionContext>();
}

modelicaParser::Class_definitionContext* modelicaParser::Stored_definitionContext::class_definition(size_t i) {
  return getRuleContext<modelicaParser::Class_definitionContext>(i);
}


size_t modelicaParser::Stored_definitionContext::getRuleIndex() const {
  return modelicaParser::RuleStored_definition;
}

void modelicaParser::Stored_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStored_definition(this);
}

void modelicaParser::Stored_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStored_definition(this);
}


antlrcpp::Any modelicaParser::Stored_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitStored_definition(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Stored_definitionContext* modelicaParser::stored_definition() {
  Stored_definitionContext *_localctx = _tracker.createInstance<Stored_definitionContext>(_ctx, getState());
  enterRule(_localctx, 0, modelicaParser::RuleStored_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__2) {
      setState(164);
      within_statement();
      setState(169);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(178);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__0)
      | (1ULL << modelicaParser::T__3)
      | (1ULL << modelicaParser::T__4)
      | (1ULL << modelicaParser::T__5)
      | (1ULL << modelicaParser::T__6)
      | (1ULL << modelicaParser::T__7)
      | (1ULL << modelicaParser::T__8)
      | (1ULL << modelicaParser::T__9)
      | (1ULL << modelicaParser::T__10)
      | (1ULL << modelicaParser::T__11)
      | (1ULL << modelicaParser::T__12)
      | (1ULL << modelicaParser::T__13)
      | (1ULL << modelicaParser::T__14)
      | (1ULL << modelicaParser::T__15)
      | (1ULL << modelicaParser::T__16))) != 0)) {
      setState(171);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::T__0) {
        setState(170);
        match(modelicaParser::T__0);
      }
      setState(173);
      class_definition();
      setState(174);
      match(modelicaParser::T__1);
      setState(180);
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

//----------------- Within_statementContext ------------------------------------------------------------------

modelicaParser::Within_statementContext::Within_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::NameContext* modelicaParser::Within_statementContext::name() {
  return getRuleContext<modelicaParser::NameContext>(0);
}


size_t modelicaParser::Within_statementContext::getRuleIndex() const {
  return modelicaParser::RuleWithin_statement;
}

void modelicaParser::Within_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithin_statement(this);
}

void modelicaParser::Within_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithin_statement(this);
}


antlrcpp::Any modelicaParser::Within_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitWithin_statement(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Within_statementContext* modelicaParser::within_statement() {
  Within_statementContext *_localctx = _tracker.createInstance<Within_statementContext>(_ctx, getState());
  enterRule(_localctx, 2, modelicaParser::RuleWithin_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(modelicaParser::T__2);
    setState(183);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__86

    || _la == modelicaParser::IDENT) {
      setState(182);
      name();
    }
    setState(185);
    match(modelicaParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_definitionContext ------------------------------------------------------------------

modelicaParser::Class_definitionContext::Class_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Class_prefixesContext* modelicaParser::Class_definitionContext::class_prefixes() {
  return getRuleContext<modelicaParser::Class_prefixesContext>(0);
}

modelicaParser::Class_specifierContext* modelicaParser::Class_definitionContext::class_specifier() {
  return getRuleContext<modelicaParser::Class_specifierContext>(0);
}


size_t modelicaParser::Class_definitionContext::getRuleIndex() const {
  return modelicaParser::RuleClass_definition;
}

void modelicaParser::Class_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClass_definition(this);
}

void modelicaParser::Class_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClass_definition(this);
}


antlrcpp::Any modelicaParser::Class_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitClass_definition(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Class_definitionContext* modelicaParser::class_definition() {
  Class_definitionContext *_localctx = _tracker.createInstance<Class_definitionContext>(_ctx, getState());
  enterRule(_localctx, 4, modelicaParser::RuleClass_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__3) {
      setState(187);
      match(modelicaParser::T__3);
    }
    setState(190);
    class_prefixes();
    setState(191);
    class_specifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_specifierContext ------------------------------------------------------------------

modelicaParser::Class_specifierContext::Class_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Long_class_specifierContext* modelicaParser::Class_specifierContext::long_class_specifier() {
  return getRuleContext<modelicaParser::Long_class_specifierContext>(0);
}

modelicaParser::Short_class_specifierContext* modelicaParser::Class_specifierContext::short_class_specifier() {
  return getRuleContext<modelicaParser::Short_class_specifierContext>(0);
}

modelicaParser::Der_class_specifierContext* modelicaParser::Class_specifierContext::der_class_specifier() {
  return getRuleContext<modelicaParser::Der_class_specifierContext>(0);
}


size_t modelicaParser::Class_specifierContext::getRuleIndex() const {
  return modelicaParser::RuleClass_specifier;
}

void modelicaParser::Class_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClass_specifier(this);
}

void modelicaParser::Class_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClass_specifier(this);
}


antlrcpp::Any modelicaParser::Class_specifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitClass_specifier(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Class_specifierContext* modelicaParser::class_specifier() {
  Class_specifierContext *_localctx = _tracker.createInstance<Class_specifierContext>(_ctx, getState());
  enterRule(_localctx, 6, modelicaParser::RuleClass_specifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(196);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(193);
      long_class_specifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(194);
      short_class_specifier();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(195);
      der_class_specifier();
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

//----------------- Class_prefixesContext ------------------------------------------------------------------

modelicaParser::Class_prefixesContext::Class_prefixesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t modelicaParser::Class_prefixesContext::getRuleIndex() const {
  return modelicaParser::RuleClass_prefixes;
}

void modelicaParser::Class_prefixesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClass_prefixes(this);
}

void modelicaParser::Class_prefixesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClass_prefixes(this);
}


antlrcpp::Any modelicaParser::Class_prefixesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitClass_prefixes(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Class_prefixesContext* modelicaParser::class_prefixes() {
  Class_prefixesContext *_localctx = _tracker.createInstance<Class_prefixesContext>(_ctx, getState());
  enterRule(_localctx, 8, modelicaParser::RuleClass_prefixes);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__4) {
      setState(198);
      match(modelicaParser::T__4);
    }
    setState(222);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(201);
      match(modelicaParser::T__5);
      break;
    }

    case 2: {
      setState(202);
      match(modelicaParser::T__6);
      break;
    }

    case 3: {
      setState(204);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::T__7) {
        setState(203);
        match(modelicaParser::T__7);
      }
      setState(206);
      match(modelicaParser::T__8);
      break;
    }

    case 4: {
      setState(207);
      match(modelicaParser::T__9);
      break;
    }

    case 5: {
      setState(209);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::T__10) {
        setState(208);
        match(modelicaParser::T__10);
      }
      setState(211);
      match(modelicaParser::T__11);
      break;
    }

    case 6: {
      setState(212);
      match(modelicaParser::T__12);
      break;
    }

    case 7: {
      setState(213);
      match(modelicaParser::T__13);
      break;
    }

    case 8: {
      setState(215);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::T__14

      || _la == modelicaParser::T__15) {
        setState(214);
        _la = _input->LA(1);
        if (!(_la == modelicaParser::T__14

        || _la == modelicaParser::T__15)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(218);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::T__7) {
        setState(217);
        match(modelicaParser::T__7);
      }
      setState(220);
      match(modelicaParser::T__16);
      break;
    }

    case 9: {
      setState(221);
      match(modelicaParser::T__7);
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

//----------------- Long_class_specifierContext ------------------------------------------------------------------

modelicaParser::Long_class_specifierContext::Long_class_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> modelicaParser::Long_class_specifierContext::IDENT() {
  return getTokens(modelicaParser::IDENT);
}

tree::TerminalNode* modelicaParser::Long_class_specifierContext::IDENT(size_t i) {
  return getToken(modelicaParser::IDENT, i);
}

modelicaParser::CompositionContext* modelicaParser::Long_class_specifierContext::composition() {
  return getRuleContext<modelicaParser::CompositionContext>(0);
}

modelicaParser::String_commentContext* modelicaParser::Long_class_specifierContext::string_comment() {
  return getRuleContext<modelicaParser::String_commentContext>(0);
}

modelicaParser::Class_modificationContext* modelicaParser::Long_class_specifierContext::class_modification() {
  return getRuleContext<modelicaParser::Class_modificationContext>(0);
}


size_t modelicaParser::Long_class_specifierContext::getRuleIndex() const {
  return modelicaParser::RuleLong_class_specifier;
}

void modelicaParser::Long_class_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLong_class_specifier(this);
}

void modelicaParser::Long_class_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLong_class_specifier(this);
}


antlrcpp::Any modelicaParser::Long_class_specifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitLong_class_specifier(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Long_class_specifierContext* modelicaParser::long_class_specifier() {
  Long_class_specifierContext *_localctx = _tracker.createInstance<Long_class_specifierContext>(_ctx, getState());
  enterRule(_localctx, 10, modelicaParser::RuleLong_class_specifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(244);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(224);
        match(modelicaParser::IDENT);
        setState(226);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == modelicaParser::STRING) {
          setState(225);
          string_comment();
        }
        setState(228);
        composition();
        setState(229);
        match(modelicaParser::T__17);
        setState(230);
        match(modelicaParser::IDENT);
        break;
      }

      case modelicaParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(232);
        match(modelicaParser::T__18);
        setState(233);
        match(modelicaParser::IDENT);
        setState(235);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == modelicaParser::T__21) {
          setState(234);
          class_modification();
        }
        setState(238);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == modelicaParser::STRING) {
          setState(237);
          string_comment();
        }
        setState(240);
        composition();
        setState(241);
        match(modelicaParser::T__17);
        setState(242);
        match(modelicaParser::IDENT);
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

//----------------- Short_class_specifierContext ------------------------------------------------------------------

modelicaParser::Short_class_specifierContext::Short_class_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* modelicaParser::Short_class_specifierContext::IDENT() {
  return getToken(modelicaParser::IDENT, 0);
}

modelicaParser::Base_prefixContext* modelicaParser::Short_class_specifierContext::base_prefix() {
  return getRuleContext<modelicaParser::Base_prefixContext>(0);
}

modelicaParser::NameContext* modelicaParser::Short_class_specifierContext::name() {
  return getRuleContext<modelicaParser::NameContext>(0);
}

modelicaParser::Array_subscriptsContext* modelicaParser::Short_class_specifierContext::array_subscripts() {
  return getRuleContext<modelicaParser::Array_subscriptsContext>(0);
}

modelicaParser::Class_modificationContext* modelicaParser::Short_class_specifierContext::class_modification() {
  return getRuleContext<modelicaParser::Class_modificationContext>(0);
}

modelicaParser::CommentContext* modelicaParser::Short_class_specifierContext::comment() {
  return getRuleContext<modelicaParser::CommentContext>(0);
}

modelicaParser::Enum_listContext* modelicaParser::Short_class_specifierContext::enum_list() {
  return getRuleContext<modelicaParser::Enum_listContext>(0);
}


size_t modelicaParser::Short_class_specifierContext::getRuleIndex() const {
  return modelicaParser::RuleShort_class_specifier;
}

void modelicaParser::Short_class_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShort_class_specifier(this);
}

void modelicaParser::Short_class_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShort_class_specifier(this);
}


antlrcpp::Any modelicaParser::Short_class_specifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitShort_class_specifier(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Short_class_specifierContext* modelicaParser::short_class_specifier() {
  Short_class_specifierContext *_localctx = _tracker.createInstance<Short_class_specifierContext>(_ctx, getState());
  enterRule(_localctx, 12, modelicaParser::RuleShort_class_specifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(273);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(246);
      match(modelicaParser::IDENT);
      setState(247);
      match(modelicaParser::T__19);
      setState(248);
      base_prefix();
      setState(249);
      name();
      setState(251);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::T__83) {
        setState(250);
        array_subscripts();
      }
      setState(254);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::T__21) {
        setState(253);
        class_modification();
      }
      setState(257);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::STRING) {
        setState(256);
        comment();
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(259);
      match(modelicaParser::IDENT);
      setState(260);
      match(modelicaParser::T__19);
      setState(261);
      match(modelicaParser::T__20);
      setState(262);
      match(modelicaParser::T__21);
      setState(267);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case modelicaParser::T__23:
        case modelicaParser::IDENT: {
          setState(264);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == modelicaParser::IDENT) {
            setState(263);
            enum_list();
          }
          break;
        }

        case modelicaParser::T__22: {
          setState(266);
          match(modelicaParser::T__22);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(269);
      match(modelicaParser::T__23);
      setState(271);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::STRING) {
        setState(270);
        comment();
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

//----------------- Der_class_specifierContext ------------------------------------------------------------------

modelicaParser::Der_class_specifierContext::Der_class_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> modelicaParser::Der_class_specifierContext::IDENT() {
  return getTokens(modelicaParser::IDENT);
}

tree::TerminalNode* modelicaParser::Der_class_specifierContext::IDENT(size_t i) {
  return getToken(modelicaParser::IDENT, i);
}

modelicaParser::NameContext* modelicaParser::Der_class_specifierContext::name() {
  return getRuleContext<modelicaParser::NameContext>(0);
}

modelicaParser::CommentContext* modelicaParser::Der_class_specifierContext::comment() {
  return getRuleContext<modelicaParser::CommentContext>(0);
}


size_t modelicaParser::Der_class_specifierContext::getRuleIndex() const {
  return modelicaParser::RuleDer_class_specifier;
}

void modelicaParser::Der_class_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDer_class_specifier(this);
}

void modelicaParser::Der_class_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDer_class_specifier(this);
}


antlrcpp::Any modelicaParser::Der_class_specifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitDer_class_specifier(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Der_class_specifierContext* modelicaParser::der_class_specifier() {
  Der_class_specifierContext *_localctx = _tracker.createInstance<Der_class_specifierContext>(_ctx, getState());
  enterRule(_localctx, 14, modelicaParser::RuleDer_class_specifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    match(modelicaParser::IDENT);
    setState(276);
    match(modelicaParser::T__19);
    setState(277);
    match(modelicaParser::T__24);
    setState(278);
    match(modelicaParser::T__21);
    setState(279);
    name();
    setState(280);
    match(modelicaParser::T__25);
    setState(281);
    match(modelicaParser::IDENT);
    setState(286);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__25) {
      setState(282);
      match(modelicaParser::T__25);
      setState(283);
      match(modelicaParser::IDENT);
      setState(288);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(289);
    match(modelicaParser::T__23);
    setState(291);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::STRING) {
      setState(290);
      comment();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Base_prefixContext ------------------------------------------------------------------

modelicaParser::Base_prefixContext::Base_prefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Type_prefix_connectorContext* modelicaParser::Base_prefixContext::type_prefix_connector() {
  return getRuleContext<modelicaParser::Type_prefix_connectorContext>(0);
}

modelicaParser::Type_prefix_variabilityContext* modelicaParser::Base_prefixContext::type_prefix_variability() {
  return getRuleContext<modelicaParser::Type_prefix_variabilityContext>(0);
}

modelicaParser::Type_prefix_ioContext* modelicaParser::Base_prefixContext::type_prefix_io() {
  return getRuleContext<modelicaParser::Type_prefix_ioContext>(0);
}


size_t modelicaParser::Base_prefixContext::getRuleIndex() const {
  return modelicaParser::RuleBase_prefix;
}

void modelicaParser::Base_prefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBase_prefix(this);
}

void modelicaParser::Base_prefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBase_prefix(this);
}


antlrcpp::Any modelicaParser::Base_prefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitBase_prefix(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Base_prefixContext* modelicaParser::base_prefix() {
  Base_prefixContext *_localctx = _tracker.createInstance<Base_prefixContext>(_ctx, getState());
  enterRule(_localctx, 16, modelicaParser::RuleBase_prefix);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__38

    || _la == modelicaParser::T__39) {
      setState(293);
      type_prefix_connector();
    }
    setState(297);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__40)
      | (1ULL << modelicaParser::T__41)
      | (1ULL << modelicaParser::T__42))) != 0)) {
      setState(296);
      type_prefix_variability();
    }
    setState(300);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__43

    || _la == modelicaParser::T__44) {
      setState(299);
      type_prefix_io();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_listContext ------------------------------------------------------------------

modelicaParser::Enum_listContext::Enum_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::Enumeration_literalContext *> modelicaParser::Enum_listContext::enumeration_literal() {
  return getRuleContexts<modelicaParser::Enumeration_literalContext>();
}

modelicaParser::Enumeration_literalContext* modelicaParser::Enum_listContext::enumeration_literal(size_t i) {
  return getRuleContext<modelicaParser::Enumeration_literalContext>(i);
}


size_t modelicaParser::Enum_listContext::getRuleIndex() const {
  return modelicaParser::RuleEnum_list;
}

void modelicaParser::Enum_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_list(this);
}

void modelicaParser::Enum_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_list(this);
}


antlrcpp::Any modelicaParser::Enum_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitEnum_list(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Enum_listContext* modelicaParser::enum_list() {
  Enum_listContext *_localctx = _tracker.createInstance<Enum_listContext>(_ctx, getState());
  enterRule(_localctx, 18, modelicaParser::RuleEnum_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    enumeration_literal();
    setState(307);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__25) {
      setState(303);
      match(modelicaParser::T__25);
      setState(304);
      enumeration_literal();
      setState(309);
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

//----------------- Enumeration_literalContext ------------------------------------------------------------------

modelicaParser::Enumeration_literalContext::Enumeration_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* modelicaParser::Enumeration_literalContext::IDENT() {
  return getToken(modelicaParser::IDENT, 0);
}

modelicaParser::CommentContext* modelicaParser::Enumeration_literalContext::comment() {
  return getRuleContext<modelicaParser::CommentContext>(0);
}


size_t modelicaParser::Enumeration_literalContext::getRuleIndex() const {
  return modelicaParser::RuleEnumeration_literal;
}

void modelicaParser::Enumeration_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumeration_literal(this);
}

void modelicaParser::Enumeration_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumeration_literal(this);
}


antlrcpp::Any modelicaParser::Enumeration_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitEnumeration_literal(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Enumeration_literalContext* modelicaParser::enumeration_literal() {
  Enumeration_literalContext *_localctx = _tracker.createInstance<Enumeration_literalContext>(_ctx, getState());
  enterRule(_localctx, 20, modelicaParser::RuleEnumeration_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(modelicaParser::IDENT);
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::STRING) {
      setState(311);
      comment();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompositionContext ------------------------------------------------------------------

modelicaParser::CompositionContext::CompositionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::Element_listContext *> modelicaParser::CompositionContext::element_list() {
  return getRuleContexts<modelicaParser::Element_listContext>();
}

modelicaParser::Element_listContext* modelicaParser::CompositionContext::element_list(size_t i) {
  return getRuleContext<modelicaParser::Element_listContext>(i);
}

std::vector<modelicaParser::Equation_sectionContext *> modelicaParser::CompositionContext::equation_section() {
  return getRuleContexts<modelicaParser::Equation_sectionContext>();
}

modelicaParser::Equation_sectionContext* modelicaParser::CompositionContext::equation_section(size_t i) {
  return getRuleContext<modelicaParser::Equation_sectionContext>(i);
}

std::vector<modelicaParser::Algorithm_sectionContext *> modelicaParser::CompositionContext::algorithm_section() {
  return getRuleContexts<modelicaParser::Algorithm_sectionContext>();
}

modelicaParser::Algorithm_sectionContext* modelicaParser::CompositionContext::algorithm_section(size_t i) {
  return getRuleContext<modelicaParser::Algorithm_sectionContext>(i);
}

modelicaParser::Model_annotationContext* modelicaParser::CompositionContext::model_annotation() {
  return getRuleContext<modelicaParser::Model_annotationContext>(0);
}

modelicaParser::Language_specificationContext* modelicaParser::CompositionContext::language_specification() {
  return getRuleContext<modelicaParser::Language_specificationContext>(0);
}

modelicaParser::External_function_callContext* modelicaParser::CompositionContext::external_function_call() {
  return getRuleContext<modelicaParser::External_function_callContext>(0);
}

modelicaParser::AnnotationContext* modelicaParser::CompositionContext::annotation() {
  return getRuleContext<modelicaParser::AnnotationContext>(0);
}


size_t modelicaParser::CompositionContext::getRuleIndex() const {
  return modelicaParser::RuleComposition;
}

void modelicaParser::CompositionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComposition(this);
}

void modelicaParser::CompositionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComposition(this);
}


antlrcpp::Any modelicaParser::CompositionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitComposition(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::CompositionContext* modelicaParser::composition() {
  CompositionContext *_localctx = _tracker.createInstance<CompositionContext>(_ctx, getState());
  enterRule(_localctx, 22, modelicaParser::RuleComposition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    element_list();
    setState(323);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__26)
      | (1ULL << modelicaParser::T__27)
      | (1ULL << modelicaParser::T__48)
      | (1ULL << modelicaParser::T__49)
      | (1ULL << modelicaParser::T__50))) != 0)) {
      setState(321);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
      case 1: {
        setState(315);
        match(modelicaParser::T__26);
        setState(316);
        element_list();
        break;
      }

      case 2: {
        setState(317);
        match(modelicaParser::T__27);
        setState(318);
        element_list();
        break;
      }

      case 3: {
        setState(319);
        equation_section();
        break;
      }

      case 4: {
        setState(320);
        algorithm_section();
        break;
      }

      }
      setState(325);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(337);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__28) {
      setState(326);
      match(modelicaParser::T__28);
      setState(328);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::STRING) {
        setState(327);
        language_specification();
      }
      setState(331);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::T__86

      || _la == modelicaParser::IDENT) {
        setState(330);
        external_function_call();
      }
      setState(334);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::T__87) {
        setState(333);
        annotation();
      }
      setState(336);
      match(modelicaParser::T__1);
    }
    setState(342);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__87) {
      setState(339);
      model_annotation();
      setState(340);
      match(modelicaParser::T__1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Language_specificationContext ------------------------------------------------------------------

modelicaParser::Language_specificationContext::Language_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* modelicaParser::Language_specificationContext::STRING() {
  return getToken(modelicaParser::STRING, 0);
}


size_t modelicaParser::Language_specificationContext::getRuleIndex() const {
  return modelicaParser::RuleLanguage_specification;
}

void modelicaParser::Language_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLanguage_specification(this);
}

void modelicaParser::Language_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLanguage_specification(this);
}


antlrcpp::Any modelicaParser::Language_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitLanguage_specification(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Language_specificationContext* modelicaParser::language_specification() {
  Language_specificationContext *_localctx = _tracker.createInstance<Language_specificationContext>(_ctx, getState());
  enterRule(_localctx, 24, modelicaParser::RuleLanguage_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    match(modelicaParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- External_function_callContext ------------------------------------------------------------------

modelicaParser::External_function_callContext::External_function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* modelicaParser::External_function_callContext::IDENT() {
  return getToken(modelicaParser::IDENT, 0);
}

modelicaParser::Component_referenceContext* modelicaParser::External_function_callContext::component_reference() {
  return getRuleContext<modelicaParser::Component_referenceContext>(0);
}

modelicaParser::Expression_listContext* modelicaParser::External_function_callContext::expression_list() {
  return getRuleContext<modelicaParser::Expression_listContext>(0);
}


size_t modelicaParser::External_function_callContext::getRuleIndex() const {
  return modelicaParser::RuleExternal_function_call;
}

void modelicaParser::External_function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternal_function_call(this);
}

void modelicaParser::External_function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternal_function_call(this);
}


antlrcpp::Any modelicaParser::External_function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitExternal_function_call(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::External_function_callContext* modelicaParser::external_function_call() {
  External_function_callContext *_localctx = _tracker.createInstance<External_function_callContext>(_ctx, getState());
  enterRule(_localctx, 26, modelicaParser::RuleExternal_function_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(349);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      setState(346);
      component_reference();
      setState(347);
      match(modelicaParser::T__19);
      break;
    }

    }
    setState(351);
    match(modelicaParser::IDENT);
    setState(352);
    match(modelicaParser::T__21);
    setState(354);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__17)
      | (1ULL << modelicaParser::T__21)
      | (1ULL << modelicaParser::T__24)
      | (1ULL << modelicaParser::T__45)
      | (1ULL << modelicaParser::T__48))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (modelicaParser::T__65 - 66))
      | (1ULL << (modelicaParser::T__72 - 66))
      | (1ULL << (modelicaParser::T__73 - 66))
      | (1ULL << (modelicaParser::T__74 - 66))
      | (1ULL << (modelicaParser::T__75 - 66))
      | (1ULL << (modelicaParser::T__81 - 66))
      | (1ULL << (modelicaParser::T__82 - 66))
      | (1ULL << (modelicaParser::T__83 - 66))
      | (1ULL << (modelicaParser::T__85 - 66))
      | (1ULL << (modelicaParser::T__86 - 66))
      | (1ULL << (modelicaParser::IDENT - 66))
      | (1ULL << (modelicaParser::STRING - 66))
      | (1ULL << (modelicaParser::UNSIGNED_NUMBER - 66)))) != 0)) {
      setState(353);
      expression_list();
    }
    setState(356);
    match(modelicaParser::T__23);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_listContext ------------------------------------------------------------------

modelicaParser::Element_listContext::Element_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::ElementContext *> modelicaParser::Element_listContext::element() {
  return getRuleContexts<modelicaParser::ElementContext>();
}

modelicaParser::ElementContext* modelicaParser::Element_listContext::element(size_t i) {
  return getRuleContext<modelicaParser::ElementContext>(i);
}


size_t modelicaParser::Element_listContext::getRuleIndex() const {
  return modelicaParser::RuleElement_list;
}

void modelicaParser::Element_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_list(this);
}

void modelicaParser::Element_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_list(this);
}


antlrcpp::Any modelicaParser::Element_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitElement_list(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Element_listContext* modelicaParser::element_list() {
  Element_listContext *_localctx = _tracker.createInstance<Element_listContext>(_ctx, getState());
  enterRule(_localctx, 28, modelicaParser::RuleElement_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__0)
      | (1ULL << modelicaParser::T__3)
      | (1ULL << modelicaParser::T__4)
      | (1ULL << modelicaParser::T__5)
      | (1ULL << modelicaParser::T__6)
      | (1ULL << modelicaParser::T__7)
      | (1ULL << modelicaParser::T__8)
      | (1ULL << modelicaParser::T__9)
      | (1ULL << modelicaParser::T__10)
      | (1ULL << modelicaParser::T__11)
      | (1ULL << modelicaParser::T__12)
      | (1ULL << modelicaParser::T__13)
      | (1ULL << modelicaParser::T__14)
      | (1ULL << modelicaParser::T__15)
      | (1ULL << modelicaParser::T__16)
      | (1ULL << modelicaParser::T__18)
      | (1ULL << modelicaParser::T__29)
      | (1ULL << modelicaParser::T__30)
      | (1ULL << modelicaParser::T__31)
      | (1ULL << modelicaParser::T__32)
      | (1ULL << modelicaParser::T__33)
      | (1ULL << modelicaParser::T__38)
      | (1ULL << modelicaParser::T__39)
      | (1ULL << modelicaParser::T__40)
      | (1ULL << modelicaParser::T__41)
      | (1ULL << modelicaParser::T__42)
      | (1ULL << modelicaParser::T__43)
      | (1ULL << modelicaParser::T__44))) != 0) || _la == modelicaParser::T__86

    || _la == modelicaParser::IDENT) {
      setState(358);
      element();
      setState(363);
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

//----------------- ElementContext ------------------------------------------------------------------

modelicaParser::ElementContext::ElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Import_clauseContext* modelicaParser::ElementContext::import_clause() {
  return getRuleContext<modelicaParser::Import_clauseContext>(0);
}

modelicaParser::Extends_clauseContext* modelicaParser::ElementContext::extends_clause() {
  return getRuleContext<modelicaParser::Extends_clauseContext>(0);
}

modelicaParser::Class_definitionContext* modelicaParser::ElementContext::class_definition() {
  return getRuleContext<modelicaParser::Class_definitionContext>(0);
}

modelicaParser::Component_clauseContext* modelicaParser::ElementContext::component_clause() {
  return getRuleContext<modelicaParser::Component_clauseContext>(0);
}

modelicaParser::Constraining_clauseContext* modelicaParser::ElementContext::constraining_clause() {
  return getRuleContext<modelicaParser::Constraining_clauseContext>(0);
}

modelicaParser::CommentContext* modelicaParser::ElementContext::comment() {
  return getRuleContext<modelicaParser::CommentContext>(0);
}


size_t modelicaParser::ElementContext::getRuleIndex() const {
  return modelicaParser::RuleElement;
}

void modelicaParser::ElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement(this);
}

void modelicaParser::ElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement(this);
}


antlrcpp::Any modelicaParser::ElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitElement(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::ElementContext* modelicaParser::element() {
  ElementContext *_localctx = _tracker.createInstance<ElementContext>(_ctx, getState());
  enterRule(_localctx, 30, modelicaParser::RuleElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::T__33: {
        setState(364);
        import_clause();
        break;
      }

      case modelicaParser::T__18: {
        setState(365);
        extends_clause();
        break;
      }

      case modelicaParser::T__0:
      case modelicaParser::T__3:
      case modelicaParser::T__4:
      case modelicaParser::T__5:
      case modelicaParser::T__6:
      case modelicaParser::T__7:
      case modelicaParser::T__8:
      case modelicaParser::T__9:
      case modelicaParser::T__10:
      case modelicaParser::T__11:
      case modelicaParser::T__12:
      case modelicaParser::T__13:
      case modelicaParser::T__14:
      case modelicaParser::T__15:
      case modelicaParser::T__16:
      case modelicaParser::T__29:
      case modelicaParser::T__30:
      case modelicaParser::T__31:
      case modelicaParser::T__32:
      case modelicaParser::T__38:
      case modelicaParser::T__39:
      case modelicaParser::T__40:
      case modelicaParser::T__41:
      case modelicaParser::T__42:
      case modelicaParser::T__43:
      case modelicaParser::T__44:
      case modelicaParser::T__86:
      case modelicaParser::IDENT: {
        setState(367);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == modelicaParser::T__29) {
          setState(366);
          match(modelicaParser::T__29);
        }
        setState(370);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == modelicaParser::T__0) {
          setState(369);
          match(modelicaParser::T__0);
        }
        setState(373);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == modelicaParser::T__30) {
          setState(372);
          match(modelicaParser::T__30);
        }
        setState(376);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == modelicaParser::T__31) {
          setState(375);
          match(modelicaParser::T__31);
        }
        setState(392);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case modelicaParser::T__3:
          case modelicaParser::T__4:
          case modelicaParser::T__5:
          case modelicaParser::T__6:
          case modelicaParser::T__7:
          case modelicaParser::T__8:
          case modelicaParser::T__9:
          case modelicaParser::T__10:
          case modelicaParser::T__11:
          case modelicaParser::T__12:
          case modelicaParser::T__13:
          case modelicaParser::T__14:
          case modelicaParser::T__15:
          case modelicaParser::T__16:
          case modelicaParser::T__38:
          case modelicaParser::T__39:
          case modelicaParser::T__40:
          case modelicaParser::T__41:
          case modelicaParser::T__42:
          case modelicaParser::T__43:
          case modelicaParser::T__44:
          case modelicaParser::T__86:
          case modelicaParser::IDENT: {
            setState(380);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case modelicaParser::T__3:
              case modelicaParser::T__4:
              case modelicaParser::T__5:
              case modelicaParser::T__6:
              case modelicaParser::T__7:
              case modelicaParser::T__8:
              case modelicaParser::T__9:
              case modelicaParser::T__10:
              case modelicaParser::T__11:
              case modelicaParser::T__12:
              case modelicaParser::T__13:
              case modelicaParser::T__14:
              case modelicaParser::T__15:
              case modelicaParser::T__16: {
                setState(378);
                class_definition();
                break;
              }

              case modelicaParser::T__38:
              case modelicaParser::T__39:
              case modelicaParser::T__40:
              case modelicaParser::T__41:
              case modelicaParser::T__42:
              case modelicaParser::T__43:
              case modelicaParser::T__44:
              case modelicaParser::T__86:
              case modelicaParser::IDENT: {
                setState(379);
                component_clause();
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            break;
          }

          case modelicaParser::T__32: {
            setState(382);
            match(modelicaParser::T__32);
            setState(385);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case modelicaParser::T__3:
              case modelicaParser::T__4:
              case modelicaParser::T__5:
              case modelicaParser::T__6:
              case modelicaParser::T__7:
              case modelicaParser::T__8:
              case modelicaParser::T__9:
              case modelicaParser::T__10:
              case modelicaParser::T__11:
              case modelicaParser::T__12:
              case modelicaParser::T__13:
              case modelicaParser::T__14:
              case modelicaParser::T__15:
              case modelicaParser::T__16: {
                setState(383);
                class_definition();
                break;
              }

              case modelicaParser::T__38:
              case modelicaParser::T__39:
              case modelicaParser::T__40:
              case modelicaParser::T__41:
              case modelicaParser::T__42:
              case modelicaParser::T__43:
              case modelicaParser::T__44:
              case modelicaParser::T__86:
              case modelicaParser::IDENT: {
                setState(384);
                component_clause();
                break;
              }

            default:
              throw NoViableAltException(this);
            }
            setState(390);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == modelicaParser::T__37) {
              setState(387);
              constraining_clause();
              setState(388);
              comment();
            }
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(396);
    match(modelicaParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_clauseContext ------------------------------------------------------------------

modelicaParser::Import_clauseContext::Import_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* modelicaParser::Import_clauseContext::IDENT() {
  return getToken(modelicaParser::IDENT, 0);
}

modelicaParser::NameContext* modelicaParser::Import_clauseContext::name() {
  return getRuleContext<modelicaParser::NameContext>(0);
}

modelicaParser::Import_listContext* modelicaParser::Import_clauseContext::import_list() {
  return getRuleContext<modelicaParser::Import_listContext>(0);
}

modelicaParser::CommentContext* modelicaParser::Import_clauseContext::comment() {
  return getRuleContext<modelicaParser::CommentContext>(0);
}


size_t modelicaParser::Import_clauseContext::getRuleIndex() const {
  return modelicaParser::RuleImport_clause;
}

void modelicaParser::Import_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImport_clause(this);
}

void modelicaParser::Import_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImport_clause(this);
}


antlrcpp::Any modelicaParser::Import_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitImport_clause(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Import_clauseContext* modelicaParser::import_clause() {
  Import_clauseContext *_localctx = _tracker.createInstance<Import_clauseContext>(_ctx, getState());
  enterRule(_localctx, 32, modelicaParser::RuleImport_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(398);
    match(modelicaParser::T__33);
    setState(411);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      setState(399);
      match(modelicaParser::IDENT);
      setState(400);
      match(modelicaParser::T__19);
      setState(401);
      name();
      break;
    }

    case 2: {
      setState(402);
      name();
      setState(403);
      match(modelicaParser::T__34);
      break;
    }

    case 3: {
      setState(405);
      name();
      setState(406);
      match(modelicaParser::T__35);
      setState(407);
      import_list();
      setState(408);
      match(modelicaParser::T__36);
      break;
    }

    case 4: {
      setState(410);
      name();
      break;
    }

    }
    setState(414);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::STRING) {
      setState(413);
      comment();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_listContext ------------------------------------------------------------------

modelicaParser::Import_listContext::Import_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> modelicaParser::Import_listContext::IDENT() {
  return getTokens(modelicaParser::IDENT);
}

tree::TerminalNode* modelicaParser::Import_listContext::IDENT(size_t i) {
  return getToken(modelicaParser::IDENT, i);
}


size_t modelicaParser::Import_listContext::getRuleIndex() const {
  return modelicaParser::RuleImport_list;
}

void modelicaParser::Import_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImport_list(this);
}

void modelicaParser::Import_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImport_list(this);
}


antlrcpp::Any modelicaParser::Import_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitImport_list(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Import_listContext* modelicaParser::import_list() {
  Import_listContext *_localctx = _tracker.createInstance<Import_listContext>(_ctx, getState());
  enterRule(_localctx, 34, modelicaParser::RuleImport_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    match(modelicaParser::IDENT);
    setState(421);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__25) {
      setState(417);
      match(modelicaParser::T__25);
      setState(418);
      match(modelicaParser::IDENT);
      setState(423);
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

//----------------- Extends_clauseContext ------------------------------------------------------------------

modelicaParser::Extends_clauseContext::Extends_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::NameContext* modelicaParser::Extends_clauseContext::name() {
  return getRuleContext<modelicaParser::NameContext>(0);
}

modelicaParser::Class_modificationContext* modelicaParser::Extends_clauseContext::class_modification() {
  return getRuleContext<modelicaParser::Class_modificationContext>(0);
}

modelicaParser::AnnotationContext* modelicaParser::Extends_clauseContext::annotation() {
  return getRuleContext<modelicaParser::AnnotationContext>(0);
}


size_t modelicaParser::Extends_clauseContext::getRuleIndex() const {
  return modelicaParser::RuleExtends_clause;
}

void modelicaParser::Extends_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtends_clause(this);
}

void modelicaParser::Extends_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtends_clause(this);
}


antlrcpp::Any modelicaParser::Extends_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitExtends_clause(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Extends_clauseContext* modelicaParser::extends_clause() {
  Extends_clauseContext *_localctx = _tracker.createInstance<Extends_clauseContext>(_ctx, getState());
  enterRule(_localctx, 36, modelicaParser::RuleExtends_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    match(modelicaParser::T__18);
    setState(425);
    name();
    setState(427);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__21) {
      setState(426);
      class_modification();
    }
    setState(430);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__87) {
      setState(429);
      annotation();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constraining_clauseContext ------------------------------------------------------------------

modelicaParser::Constraining_clauseContext::Constraining_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::NameContext* modelicaParser::Constraining_clauseContext::name() {
  return getRuleContext<modelicaParser::NameContext>(0);
}

modelicaParser::Class_modificationContext* modelicaParser::Constraining_clauseContext::class_modification() {
  return getRuleContext<modelicaParser::Class_modificationContext>(0);
}


size_t modelicaParser::Constraining_clauseContext::getRuleIndex() const {
  return modelicaParser::RuleConstraining_clause;
}

void modelicaParser::Constraining_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstraining_clause(this);
}

void modelicaParser::Constraining_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstraining_clause(this);
}


antlrcpp::Any modelicaParser::Constraining_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitConstraining_clause(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Constraining_clauseContext* modelicaParser::constraining_clause() {
  Constraining_clauseContext *_localctx = _tracker.createInstance<Constraining_clauseContext>(_ctx, getState());
  enterRule(_localctx, 38, modelicaParser::RuleConstraining_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    match(modelicaParser::T__37);
    setState(433);
    name();
    setState(435);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__21) {
      setState(434);
      class_modification();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_clauseContext ------------------------------------------------------------------

modelicaParser::Component_clauseContext::Component_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Type_specifierContext* modelicaParser::Component_clauseContext::type_specifier() {
  return getRuleContext<modelicaParser::Type_specifierContext>(0);
}

modelicaParser::Component_listContext* modelicaParser::Component_clauseContext::component_list() {
  return getRuleContext<modelicaParser::Component_listContext>(0);
}

modelicaParser::Type_prefix_connectorContext* modelicaParser::Component_clauseContext::type_prefix_connector() {
  return getRuleContext<modelicaParser::Type_prefix_connectorContext>(0);
}

modelicaParser::Type_prefix_variabilityContext* modelicaParser::Component_clauseContext::type_prefix_variability() {
  return getRuleContext<modelicaParser::Type_prefix_variabilityContext>(0);
}

modelicaParser::Type_prefix_ioContext* modelicaParser::Component_clauseContext::type_prefix_io() {
  return getRuleContext<modelicaParser::Type_prefix_ioContext>(0);
}

modelicaParser::Array_subscriptsContext* modelicaParser::Component_clauseContext::array_subscripts() {
  return getRuleContext<modelicaParser::Array_subscriptsContext>(0);
}


size_t modelicaParser::Component_clauseContext::getRuleIndex() const {
  return modelicaParser::RuleComponent_clause;
}

void modelicaParser::Component_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_clause(this);
}

void modelicaParser::Component_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_clause(this);
}


antlrcpp::Any modelicaParser::Component_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitComponent_clause(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Component_clauseContext* modelicaParser::component_clause() {
  Component_clauseContext *_localctx = _tracker.createInstance<Component_clauseContext>(_ctx, getState());
  enterRule(_localctx, 40, modelicaParser::RuleComponent_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(438);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__38

    || _la == modelicaParser::T__39) {
      setState(437);
      type_prefix_connector();
    }
    setState(441);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__40)
      | (1ULL << modelicaParser::T__41)
      | (1ULL << modelicaParser::T__42))) != 0)) {
      setState(440);
      type_prefix_variability();
    }
    setState(444);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__43

    || _la == modelicaParser::T__44) {
      setState(443);
      type_prefix_io();
    }
    setState(446);
    type_specifier();
    setState(448);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__83) {
      setState(447);
      array_subscripts();
    }
    setState(450);
    component_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_prefix_connectorContext ------------------------------------------------------------------

modelicaParser::Type_prefix_connectorContext::Type_prefix_connectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t modelicaParser::Type_prefix_connectorContext::getRuleIndex() const {
  return modelicaParser::RuleType_prefix_connector;
}

void modelicaParser::Type_prefix_connectorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_prefix_connector(this);
}

void modelicaParser::Type_prefix_connectorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_prefix_connector(this);
}


antlrcpp::Any modelicaParser::Type_prefix_connectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitType_prefix_connector(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Type_prefix_connectorContext* modelicaParser::type_prefix_connector() {
  Type_prefix_connectorContext *_localctx = _tracker.createInstance<Type_prefix_connectorContext>(_ctx, getState());
  enterRule(_localctx, 42, modelicaParser::RuleType_prefix_connector);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    _la = _input->LA(1);
    if (!(_la == modelicaParser::T__38

    || _la == modelicaParser::T__39)) {
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

//----------------- Type_prefix_variabilityContext ------------------------------------------------------------------

modelicaParser::Type_prefix_variabilityContext::Type_prefix_variabilityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t modelicaParser::Type_prefix_variabilityContext::getRuleIndex() const {
  return modelicaParser::RuleType_prefix_variability;
}

void modelicaParser::Type_prefix_variabilityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_prefix_variability(this);
}

void modelicaParser::Type_prefix_variabilityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_prefix_variability(this);
}


antlrcpp::Any modelicaParser::Type_prefix_variabilityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitType_prefix_variability(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Type_prefix_variabilityContext* modelicaParser::type_prefix_variability() {
  Type_prefix_variabilityContext *_localctx = _tracker.createInstance<Type_prefix_variabilityContext>(_ctx, getState());
  enterRule(_localctx, 44, modelicaParser::RuleType_prefix_variability);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__40)
      | (1ULL << modelicaParser::T__41)
      | (1ULL << modelicaParser::T__42))) != 0))) {
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

//----------------- Type_prefix_ioContext ------------------------------------------------------------------

modelicaParser::Type_prefix_ioContext::Type_prefix_ioContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t modelicaParser::Type_prefix_ioContext::getRuleIndex() const {
  return modelicaParser::RuleType_prefix_io;
}

void modelicaParser::Type_prefix_ioContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_prefix_io(this);
}

void modelicaParser::Type_prefix_ioContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_prefix_io(this);
}


antlrcpp::Any modelicaParser::Type_prefix_ioContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitType_prefix_io(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Type_prefix_ioContext* modelicaParser::type_prefix_io() {
  Type_prefix_ioContext *_localctx = _tracker.createInstance<Type_prefix_ioContext>(_ctx, getState());
  enterRule(_localctx, 46, modelicaParser::RuleType_prefix_io);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(456);
    _la = _input->LA(1);
    if (!(_la == modelicaParser::T__43

    || _la == modelicaParser::T__44)) {
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

//----------------- Type_specifierContext ------------------------------------------------------------------

modelicaParser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::NameContext* modelicaParser::Type_specifierContext::name() {
  return getRuleContext<modelicaParser::NameContext>(0);
}


size_t modelicaParser::Type_specifierContext::getRuleIndex() const {
  return modelicaParser::RuleType_specifier;
}

void modelicaParser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void modelicaParser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}


antlrcpp::Any modelicaParser::Type_specifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitType_specifier(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Type_specifierContext* modelicaParser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 48, modelicaParser::RuleType_specifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(458);
    name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_listContext ------------------------------------------------------------------

modelicaParser::Component_listContext::Component_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::Component_declarationContext *> modelicaParser::Component_listContext::component_declaration() {
  return getRuleContexts<modelicaParser::Component_declarationContext>();
}

modelicaParser::Component_declarationContext* modelicaParser::Component_listContext::component_declaration(size_t i) {
  return getRuleContext<modelicaParser::Component_declarationContext>(i);
}


size_t modelicaParser::Component_listContext::getRuleIndex() const {
  return modelicaParser::RuleComponent_list;
}

void modelicaParser::Component_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_list(this);
}

void modelicaParser::Component_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_list(this);
}


antlrcpp::Any modelicaParser::Component_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitComponent_list(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Component_listContext* modelicaParser::component_list() {
  Component_listContext *_localctx = _tracker.createInstance<Component_listContext>(_ctx, getState());
  enterRule(_localctx, 50, modelicaParser::RuleComponent_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    component_declaration();
    setState(465);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__25) {
      setState(461);
      match(modelicaParser::T__25);
      setState(462);
      component_declaration();
      setState(467);
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

//----------------- Component_declarationContext ------------------------------------------------------------------

modelicaParser::Component_declarationContext::Component_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::DeclarationContext* modelicaParser::Component_declarationContext::declaration() {
  return getRuleContext<modelicaParser::DeclarationContext>(0);
}

modelicaParser::Condition_attributeContext* modelicaParser::Component_declarationContext::condition_attribute() {
  return getRuleContext<modelicaParser::Condition_attributeContext>(0);
}

modelicaParser::CommentContext* modelicaParser::Component_declarationContext::comment() {
  return getRuleContext<modelicaParser::CommentContext>(0);
}


size_t modelicaParser::Component_declarationContext::getRuleIndex() const {
  return modelicaParser::RuleComponent_declaration;
}

void modelicaParser::Component_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_declaration(this);
}

void modelicaParser::Component_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_declaration(this);
}


antlrcpp::Any modelicaParser::Component_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitComponent_declaration(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Component_declarationContext* modelicaParser::component_declaration() {
  Component_declarationContext *_localctx = _tracker.createInstance<Component_declarationContext>(_ctx, getState());
  enterRule(_localctx, 52, modelicaParser::RuleComponent_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(468);
    declaration();
    setState(470);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__45) {
      setState(469);
      condition_attribute();
    }
    setState(473);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::STRING) {
      setState(472);
      comment();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_attributeContext ------------------------------------------------------------------

modelicaParser::Condition_attributeContext::Condition_attributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::ExpressionContext* modelicaParser::Condition_attributeContext::expression() {
  return getRuleContext<modelicaParser::ExpressionContext>(0);
}


size_t modelicaParser::Condition_attributeContext::getRuleIndex() const {
  return modelicaParser::RuleCondition_attribute;
}

void modelicaParser::Condition_attributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondition_attribute(this);
}

void modelicaParser::Condition_attributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondition_attribute(this);
}


antlrcpp::Any modelicaParser::Condition_attributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitCondition_attribute(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Condition_attributeContext* modelicaParser::condition_attribute() {
  Condition_attributeContext *_localctx = _tracker.createInstance<Condition_attributeContext>(_ctx, getState());
  enterRule(_localctx, 54, modelicaParser::RuleCondition_attribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(475);
    match(modelicaParser::T__45);
    setState(476);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

modelicaParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* modelicaParser::DeclarationContext::IDENT() {
  return getToken(modelicaParser::IDENT, 0);
}

modelicaParser::Array_subscriptsContext* modelicaParser::DeclarationContext::array_subscripts() {
  return getRuleContext<modelicaParser::Array_subscriptsContext>(0);
}

modelicaParser::ModificationContext* modelicaParser::DeclarationContext::modification() {
  return getRuleContext<modelicaParser::ModificationContext>(0);
}


size_t modelicaParser::DeclarationContext::getRuleIndex() const {
  return modelicaParser::RuleDeclaration;
}

void modelicaParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void modelicaParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any modelicaParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::DeclarationContext* modelicaParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 56, modelicaParser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(478);
    match(modelicaParser::IDENT);
    setState(480);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__83) {
      setState(479);
      array_subscripts();
    }
    setState(483);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__19)
      | (1ULL << modelicaParser::T__21)
      | (1ULL << modelicaParser::T__46))) != 0)) {
      setState(482);
      modification();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModificationContext ------------------------------------------------------------------

modelicaParser::ModificationContext::ModificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Class_modificationContext* modelicaParser::ModificationContext::class_modification() {
  return getRuleContext<modelicaParser::Class_modificationContext>(0);
}

modelicaParser::ExpressionContext* modelicaParser::ModificationContext::expression() {
  return getRuleContext<modelicaParser::ExpressionContext>(0);
}


size_t modelicaParser::ModificationContext::getRuleIndex() const {
  return modelicaParser::RuleModification;
}

void modelicaParser::ModificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModification(this);
}

void modelicaParser::ModificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModification(this);
}


antlrcpp::Any modelicaParser::ModificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitModification(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::ModificationContext* modelicaParser::modification() {
  ModificationContext *_localctx = _tracker.createInstance<ModificationContext>(_ctx, getState());
  enterRule(_localctx, 58, modelicaParser::RuleModification);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(494);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::T__21: {
        enterOuterAlt(_localctx, 1);
        setState(485);
        class_modification();
        setState(488);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == modelicaParser::T__19) {
          setState(486);
          match(modelicaParser::T__19);
          setState(487);
          expression();
        }
        break;
      }

      case modelicaParser::T__19: {
        enterOuterAlt(_localctx, 2);
        setState(490);
        match(modelicaParser::T__19);
        setState(491);
        expression();
        break;
      }

      case modelicaParser::T__46: {
        enterOuterAlt(_localctx, 3);
        setState(492);
        match(modelicaParser::T__46);
        setState(493);
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

//----------------- Class_modificationContext ------------------------------------------------------------------

modelicaParser::Class_modificationContext::Class_modificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Argument_listContext* modelicaParser::Class_modificationContext::argument_list() {
  return getRuleContext<modelicaParser::Argument_listContext>(0);
}


size_t modelicaParser::Class_modificationContext::getRuleIndex() const {
  return modelicaParser::RuleClass_modification;
}

void modelicaParser::Class_modificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClass_modification(this);
}

void modelicaParser::Class_modificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClass_modification(this);
}


antlrcpp::Any modelicaParser::Class_modificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitClass_modification(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Class_modificationContext* modelicaParser::class_modification() {
  Class_modificationContext *_localctx = _tracker.createInstance<Class_modificationContext>(_ctx, getState());
  enterRule(_localctx, 60, modelicaParser::RuleClass_modification);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    match(modelicaParser::T__21);
    setState(498);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__0)
      | (1ULL << modelicaParser::T__29)
      | (1ULL << modelicaParser::T__32)
      | (1ULL << modelicaParser::T__47))) != 0) || _la == modelicaParser::T__86

    || _la == modelicaParser::IDENT) {
      setState(497);
      argument_list();
    }
    setState(500);
    match(modelicaParser::T__23);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

modelicaParser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::ArgumentContext *> modelicaParser::Argument_listContext::argument() {
  return getRuleContexts<modelicaParser::ArgumentContext>();
}

modelicaParser::ArgumentContext* modelicaParser::Argument_listContext::argument(size_t i) {
  return getRuleContext<modelicaParser::ArgumentContext>(i);
}


size_t modelicaParser::Argument_listContext::getRuleIndex() const {
  return modelicaParser::RuleArgument_list;
}

void modelicaParser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void modelicaParser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}


antlrcpp::Any modelicaParser::Argument_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitArgument_list(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Argument_listContext* modelicaParser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 62, modelicaParser::RuleArgument_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(502);
    argument();
    setState(507);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__25) {
      setState(503);
      match(modelicaParser::T__25);
      setState(504);
      argument();
      setState(509);
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

//----------------- ArgumentContext ------------------------------------------------------------------

modelicaParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Element_modification_or_replaceableContext* modelicaParser::ArgumentContext::element_modification_or_replaceable() {
  return getRuleContext<modelicaParser::Element_modification_or_replaceableContext>(0);
}

modelicaParser::Element_redeclarationContext* modelicaParser::ArgumentContext::element_redeclaration() {
  return getRuleContext<modelicaParser::Element_redeclarationContext>(0);
}


size_t modelicaParser::ArgumentContext::getRuleIndex() const {
  return modelicaParser::RuleArgument;
}

void modelicaParser::ArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument(this);
}

void modelicaParser::ArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument(this);
}


antlrcpp::Any modelicaParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::ArgumentContext* modelicaParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 64, modelicaParser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(512);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::T__0:
      case modelicaParser::T__32:
      case modelicaParser::T__47:
      case modelicaParser::T__86:
      case modelicaParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(510);
        element_modification_or_replaceable();
        break;
      }

      case modelicaParser::T__29: {
        enterOuterAlt(_localctx, 2);
        setState(511);
        element_redeclaration();
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

//----------------- Element_modification_or_replaceableContext ------------------------------------------------------------------

modelicaParser::Element_modification_or_replaceableContext::Element_modification_or_replaceableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Element_modificationContext* modelicaParser::Element_modification_or_replaceableContext::element_modification() {
  return getRuleContext<modelicaParser::Element_modificationContext>(0);
}

modelicaParser::Element_replaceableContext* modelicaParser::Element_modification_or_replaceableContext::element_replaceable() {
  return getRuleContext<modelicaParser::Element_replaceableContext>(0);
}


size_t modelicaParser::Element_modification_or_replaceableContext::getRuleIndex() const {
  return modelicaParser::RuleElement_modification_or_replaceable;
}

void modelicaParser::Element_modification_or_replaceableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_modification_or_replaceable(this);
}

void modelicaParser::Element_modification_or_replaceableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_modification_or_replaceable(this);
}


antlrcpp::Any modelicaParser::Element_modification_or_replaceableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitElement_modification_or_replaceable(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Element_modification_or_replaceableContext* modelicaParser::element_modification_or_replaceable() {
  Element_modification_or_replaceableContext *_localctx = _tracker.createInstance<Element_modification_or_replaceableContext>(_ctx, getState());
  enterRule(_localctx, 66, modelicaParser::RuleElement_modification_or_replaceable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(515);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__47) {
      setState(514);
      match(modelicaParser::T__47);
    }
    setState(518);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__0) {
      setState(517);
      match(modelicaParser::T__0);
    }
    setState(522);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::T__86:
      case modelicaParser::IDENT: {
        setState(520);
        element_modification();
        break;
      }

      case modelicaParser::T__32: {
        setState(521);
        element_replaceable();
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

//----------------- Element_modificationContext ------------------------------------------------------------------

modelicaParser::Element_modificationContext::Element_modificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::NameContext* modelicaParser::Element_modificationContext::name() {
  return getRuleContext<modelicaParser::NameContext>(0);
}

modelicaParser::ModificationContext* modelicaParser::Element_modificationContext::modification() {
  return getRuleContext<modelicaParser::ModificationContext>(0);
}

modelicaParser::String_commentContext* modelicaParser::Element_modificationContext::string_comment() {
  return getRuleContext<modelicaParser::String_commentContext>(0);
}


size_t modelicaParser::Element_modificationContext::getRuleIndex() const {
  return modelicaParser::RuleElement_modification;
}

void modelicaParser::Element_modificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_modification(this);
}

void modelicaParser::Element_modificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_modification(this);
}


antlrcpp::Any modelicaParser::Element_modificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitElement_modification(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Element_modificationContext* modelicaParser::element_modification() {
  Element_modificationContext *_localctx = _tracker.createInstance<Element_modificationContext>(_ctx, getState());
  enterRule(_localctx, 68, modelicaParser::RuleElement_modification);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(524);
    name();
    setState(526);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__19)
      | (1ULL << modelicaParser::T__21)
      | (1ULL << modelicaParser::T__46))) != 0)) {
      setState(525);
      modification();
    }
    setState(529);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::STRING) {
      setState(528);
      string_comment();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_redeclarationContext ------------------------------------------------------------------

modelicaParser::Element_redeclarationContext::Element_redeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Element_replaceableContext* modelicaParser::Element_redeclarationContext::element_replaceable() {
  return getRuleContext<modelicaParser::Element_replaceableContext>(0);
}

modelicaParser::Short_class_definitionContext* modelicaParser::Element_redeclarationContext::short_class_definition() {
  return getRuleContext<modelicaParser::Short_class_definitionContext>(0);
}

modelicaParser::Component_clause1Context* modelicaParser::Element_redeclarationContext::component_clause1() {
  return getRuleContext<modelicaParser::Component_clause1Context>(0);
}


size_t modelicaParser::Element_redeclarationContext::getRuleIndex() const {
  return modelicaParser::RuleElement_redeclaration;
}

void modelicaParser::Element_redeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_redeclaration(this);
}

void modelicaParser::Element_redeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_redeclaration(this);
}


antlrcpp::Any modelicaParser::Element_redeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitElement_redeclaration(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Element_redeclarationContext* modelicaParser::element_redeclaration() {
  Element_redeclarationContext *_localctx = _tracker.createInstance<Element_redeclarationContext>(_ctx, getState());
  enterRule(_localctx, 70, modelicaParser::RuleElement_redeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(531);
    match(modelicaParser::T__29);
    setState(533);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__47) {
      setState(532);
      match(modelicaParser::T__47);
    }
    setState(536);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__0) {
      setState(535);
      match(modelicaParser::T__0);
    }
    setState(543);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::T__4:
      case modelicaParser::T__5:
      case modelicaParser::T__6:
      case modelicaParser::T__7:
      case modelicaParser::T__8:
      case modelicaParser::T__9:
      case modelicaParser::T__10:
      case modelicaParser::T__11:
      case modelicaParser::T__12:
      case modelicaParser::T__13:
      case modelicaParser::T__14:
      case modelicaParser::T__15:
      case modelicaParser::T__16:
      case modelicaParser::T__38:
      case modelicaParser::T__39:
      case modelicaParser::T__40:
      case modelicaParser::T__41:
      case modelicaParser::T__42:
      case modelicaParser::T__43:
      case modelicaParser::T__44:
      case modelicaParser::T__86:
      case modelicaParser::IDENT: {
        setState(540);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case modelicaParser::T__4:
          case modelicaParser::T__5:
          case modelicaParser::T__6:
          case modelicaParser::T__7:
          case modelicaParser::T__8:
          case modelicaParser::T__9:
          case modelicaParser::T__10:
          case modelicaParser::T__11:
          case modelicaParser::T__12:
          case modelicaParser::T__13:
          case modelicaParser::T__14:
          case modelicaParser::T__15:
          case modelicaParser::T__16: {
            setState(538);
            short_class_definition();
            break;
          }

          case modelicaParser::T__38:
          case modelicaParser::T__39:
          case modelicaParser::T__40:
          case modelicaParser::T__41:
          case modelicaParser::T__42:
          case modelicaParser::T__43:
          case modelicaParser::T__44:
          case modelicaParser::T__86:
          case modelicaParser::IDENT: {
            setState(539);
            component_clause1();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case modelicaParser::T__32: {
        setState(542);
        element_replaceable();
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

//----------------- Element_replaceableContext ------------------------------------------------------------------

modelicaParser::Element_replaceableContext::Element_replaceableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Short_class_definitionContext* modelicaParser::Element_replaceableContext::short_class_definition() {
  return getRuleContext<modelicaParser::Short_class_definitionContext>(0);
}

modelicaParser::Component_clause1Context* modelicaParser::Element_replaceableContext::component_clause1() {
  return getRuleContext<modelicaParser::Component_clause1Context>(0);
}

modelicaParser::Constraining_clauseContext* modelicaParser::Element_replaceableContext::constraining_clause() {
  return getRuleContext<modelicaParser::Constraining_clauseContext>(0);
}


size_t modelicaParser::Element_replaceableContext::getRuleIndex() const {
  return modelicaParser::RuleElement_replaceable;
}

void modelicaParser::Element_replaceableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_replaceable(this);
}

void modelicaParser::Element_replaceableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_replaceable(this);
}


antlrcpp::Any modelicaParser::Element_replaceableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitElement_replaceable(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Element_replaceableContext* modelicaParser::element_replaceable() {
  Element_replaceableContext *_localctx = _tracker.createInstance<Element_replaceableContext>(_ctx, getState());
  enterRule(_localctx, 72, modelicaParser::RuleElement_replaceable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(545);
    match(modelicaParser::T__32);
    setState(548);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::T__4:
      case modelicaParser::T__5:
      case modelicaParser::T__6:
      case modelicaParser::T__7:
      case modelicaParser::T__8:
      case modelicaParser::T__9:
      case modelicaParser::T__10:
      case modelicaParser::T__11:
      case modelicaParser::T__12:
      case modelicaParser::T__13:
      case modelicaParser::T__14:
      case modelicaParser::T__15:
      case modelicaParser::T__16: {
        setState(546);
        short_class_definition();
        break;
      }

      case modelicaParser::T__38:
      case modelicaParser::T__39:
      case modelicaParser::T__40:
      case modelicaParser::T__41:
      case modelicaParser::T__42:
      case modelicaParser::T__43:
      case modelicaParser::T__44:
      case modelicaParser::T__86:
      case modelicaParser::IDENT: {
        setState(547);
        component_clause1();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(551);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__37) {
      setState(550);
      constraining_clause();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_clause1Context ------------------------------------------------------------------

modelicaParser::Component_clause1Context::Component_clause1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Type_specifierContext* modelicaParser::Component_clause1Context::type_specifier() {
  return getRuleContext<modelicaParser::Type_specifierContext>(0);
}

modelicaParser::Component_declaration1Context* modelicaParser::Component_clause1Context::component_declaration1() {
  return getRuleContext<modelicaParser::Component_declaration1Context>(0);
}

modelicaParser::Type_prefix_connectorContext* modelicaParser::Component_clause1Context::type_prefix_connector() {
  return getRuleContext<modelicaParser::Type_prefix_connectorContext>(0);
}

modelicaParser::Type_prefix_variabilityContext* modelicaParser::Component_clause1Context::type_prefix_variability() {
  return getRuleContext<modelicaParser::Type_prefix_variabilityContext>(0);
}

modelicaParser::Type_prefix_ioContext* modelicaParser::Component_clause1Context::type_prefix_io() {
  return getRuleContext<modelicaParser::Type_prefix_ioContext>(0);
}


size_t modelicaParser::Component_clause1Context::getRuleIndex() const {
  return modelicaParser::RuleComponent_clause1;
}

void modelicaParser::Component_clause1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_clause1(this);
}

void modelicaParser::Component_clause1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_clause1(this);
}


antlrcpp::Any modelicaParser::Component_clause1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitComponent_clause1(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Component_clause1Context* modelicaParser::component_clause1() {
  Component_clause1Context *_localctx = _tracker.createInstance<Component_clause1Context>(_ctx, getState());
  enterRule(_localctx, 74, modelicaParser::RuleComponent_clause1);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(554);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__38

    || _la == modelicaParser::T__39) {
      setState(553);
      type_prefix_connector();
    }
    setState(557);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__40)
      | (1ULL << modelicaParser::T__41)
      | (1ULL << modelicaParser::T__42))) != 0)) {
      setState(556);
      type_prefix_variability();
    }
    setState(560);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__43

    || _la == modelicaParser::T__44) {
      setState(559);
      type_prefix_io();
    }
    setState(562);
    type_specifier();
    setState(563);
    component_declaration1();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_declaration1Context ------------------------------------------------------------------

modelicaParser::Component_declaration1Context::Component_declaration1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::DeclarationContext* modelicaParser::Component_declaration1Context::declaration() {
  return getRuleContext<modelicaParser::DeclarationContext>(0);
}

modelicaParser::CommentContext* modelicaParser::Component_declaration1Context::comment() {
  return getRuleContext<modelicaParser::CommentContext>(0);
}


size_t modelicaParser::Component_declaration1Context::getRuleIndex() const {
  return modelicaParser::RuleComponent_declaration1;
}

void modelicaParser::Component_declaration1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_declaration1(this);
}

void modelicaParser::Component_declaration1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_declaration1(this);
}


antlrcpp::Any modelicaParser::Component_declaration1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitComponent_declaration1(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Component_declaration1Context* modelicaParser::component_declaration1() {
  Component_declaration1Context *_localctx = _tracker.createInstance<Component_declaration1Context>(_ctx, getState());
  enterRule(_localctx, 76, modelicaParser::RuleComponent_declaration1);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(565);
    declaration();
    setState(566);
    comment();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Short_class_definitionContext ------------------------------------------------------------------

modelicaParser::Short_class_definitionContext::Short_class_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Class_prefixesContext* modelicaParser::Short_class_definitionContext::class_prefixes() {
  return getRuleContext<modelicaParser::Class_prefixesContext>(0);
}

modelicaParser::Short_class_specifierContext* modelicaParser::Short_class_definitionContext::short_class_specifier() {
  return getRuleContext<modelicaParser::Short_class_specifierContext>(0);
}


size_t modelicaParser::Short_class_definitionContext::getRuleIndex() const {
  return modelicaParser::RuleShort_class_definition;
}

void modelicaParser::Short_class_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShort_class_definition(this);
}

void modelicaParser::Short_class_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShort_class_definition(this);
}


antlrcpp::Any modelicaParser::Short_class_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitShort_class_definition(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Short_class_definitionContext* modelicaParser::short_class_definition() {
  Short_class_definitionContext *_localctx = _tracker.createInstance<Short_class_definitionContext>(_ctx, getState());
  enterRule(_localctx, 78, modelicaParser::RuleShort_class_definition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(568);
    class_prefixes();
    setState(569);
    short_class_specifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Equation_sectionContext ------------------------------------------------------------------

modelicaParser::Equation_sectionContext::Equation_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::EquationContext *> modelicaParser::Equation_sectionContext::equation() {
  return getRuleContexts<modelicaParser::EquationContext>();
}

modelicaParser::EquationContext* modelicaParser::Equation_sectionContext::equation(size_t i) {
  return getRuleContext<modelicaParser::EquationContext>(i);
}


size_t modelicaParser::Equation_sectionContext::getRuleIndex() const {
  return modelicaParser::RuleEquation_section;
}

void modelicaParser::Equation_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEquation_section(this);
}

void modelicaParser::Equation_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEquation_section(this);
}


antlrcpp::Any modelicaParser::Equation_sectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitEquation_section(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Equation_sectionContext* modelicaParser::equation_section() {
  Equation_sectionContext *_localctx = _tracker.createInstance<Equation_sectionContext>(_ctx, getState());
  enterRule(_localctx, 80, modelicaParser::RuleEquation_section);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(572);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__48) {
      setState(571);
      match(modelicaParser::T__48);
    }
    setState(574);
    match(modelicaParser::T__49);
    setState(578);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(575);
        equation(); 
      }
      setState(580);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Algorithm_sectionContext ------------------------------------------------------------------

modelicaParser::Algorithm_sectionContext::Algorithm_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::StatementContext *> modelicaParser::Algorithm_sectionContext::statement() {
  return getRuleContexts<modelicaParser::StatementContext>();
}

modelicaParser::StatementContext* modelicaParser::Algorithm_sectionContext::statement(size_t i) {
  return getRuleContext<modelicaParser::StatementContext>(i);
}


size_t modelicaParser::Algorithm_sectionContext::getRuleIndex() const {
  return modelicaParser::RuleAlgorithm_section;
}

void modelicaParser::Algorithm_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlgorithm_section(this);
}

void modelicaParser::Algorithm_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlgorithm_section(this);
}


antlrcpp::Any modelicaParser::Algorithm_sectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitAlgorithm_section(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Algorithm_sectionContext* modelicaParser::algorithm_section() {
  Algorithm_sectionContext *_localctx = _tracker.createInstance<Algorithm_sectionContext>(_ctx, getState());
  enterRule(_localctx, 82, modelicaParser::RuleAlgorithm_section);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(582);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__48) {
      setState(581);
      match(modelicaParser::T__48);
    }
    setState(584);
    match(modelicaParser::T__50);
    setState(590);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__21)
      | (1ULL << modelicaParser::T__45)
      | (1ULL << modelicaParser::T__51)
      | (1ULL << modelicaParser::T__52)
      | (1ULL << modelicaParser::T__56)
      | (1ULL << modelicaParser::T__59)
      | (1ULL << modelicaParser::T__60))) != 0) || _la == modelicaParser::T__86

    || _la == modelicaParser::IDENT) {
      setState(585);
      statement();
      setState(586);
      match(modelicaParser::T__1);
      setState(592);
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

//----------------- EquationContext ------------------------------------------------------------------

modelicaParser::EquationContext::EquationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Simple_expressionContext* modelicaParser::EquationContext::simple_expression() {
  return getRuleContext<modelicaParser::Simple_expressionContext>(0);
}

modelicaParser::ExpressionContext* modelicaParser::EquationContext::expression() {
  return getRuleContext<modelicaParser::ExpressionContext>(0);
}

modelicaParser::If_equationContext* modelicaParser::EquationContext::if_equation() {
  return getRuleContext<modelicaParser::If_equationContext>(0);
}

modelicaParser::For_equationContext* modelicaParser::EquationContext::for_equation() {
  return getRuleContext<modelicaParser::For_equationContext>(0);
}

modelicaParser::Connect_clauseContext* modelicaParser::EquationContext::connect_clause() {
  return getRuleContext<modelicaParser::Connect_clauseContext>(0);
}

modelicaParser::When_equationContext* modelicaParser::EquationContext::when_equation() {
  return getRuleContext<modelicaParser::When_equationContext>(0);
}

modelicaParser::NameContext* modelicaParser::EquationContext::name() {
  return getRuleContext<modelicaParser::NameContext>(0);
}

modelicaParser::Function_call_argsContext* modelicaParser::EquationContext::function_call_args() {
  return getRuleContext<modelicaParser::Function_call_argsContext>(0);
}

modelicaParser::CommentContext* modelicaParser::EquationContext::comment() {
  return getRuleContext<modelicaParser::CommentContext>(0);
}


size_t modelicaParser::EquationContext::getRuleIndex() const {
  return modelicaParser::RuleEquation;
}

void modelicaParser::EquationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEquation(this);
}

void modelicaParser::EquationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEquation(this);
}


antlrcpp::Any modelicaParser::EquationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitEquation(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::EquationContext* modelicaParser::equation() {
  EquationContext *_localctx = _tracker.createInstance<EquationContext>(_ctx, getState());
  enterRule(_localctx, 84, modelicaParser::RuleEquation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(604);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
    case 1: {
      setState(593);
      simple_expression();
      setState(594);
      match(modelicaParser::T__19);
      setState(595);
      expression();
      break;
    }

    case 2: {
      setState(597);
      if_equation();
      break;
    }

    case 3: {
      setState(598);
      for_equation();
      break;
    }

    case 4: {
      setState(599);
      connect_clause();
      break;
    }

    case 5: {
      setState(600);
      when_equation();
      break;
    }

    case 6: {
      setState(601);
      name();
      setState(602);
      function_call_args();
      break;
    }

    }
    setState(607);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::STRING) {
      setState(606);
      comment();
    }
    setState(609);
    match(modelicaParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

modelicaParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Component_referenceContext* modelicaParser::StatementContext::component_reference() {
  return getRuleContext<modelicaParser::Component_referenceContext>(0);
}

modelicaParser::Output_expression_listContext* modelicaParser::StatementContext::output_expression_list() {
  return getRuleContext<modelicaParser::Output_expression_listContext>(0);
}

modelicaParser::Function_call_argsContext* modelicaParser::StatementContext::function_call_args() {
  return getRuleContext<modelicaParser::Function_call_argsContext>(0);
}

modelicaParser::If_statementContext* modelicaParser::StatementContext::if_statement() {
  return getRuleContext<modelicaParser::If_statementContext>(0);
}

modelicaParser::For_statementContext* modelicaParser::StatementContext::for_statement() {
  return getRuleContext<modelicaParser::For_statementContext>(0);
}

modelicaParser::While_statementContext* modelicaParser::StatementContext::while_statement() {
  return getRuleContext<modelicaParser::While_statementContext>(0);
}

modelicaParser::When_statementContext* modelicaParser::StatementContext::when_statement() {
  return getRuleContext<modelicaParser::When_statementContext>(0);
}

modelicaParser::CommentContext* modelicaParser::StatementContext::comment() {
  return getRuleContext<modelicaParser::CommentContext>(0);
}

modelicaParser::ExpressionContext* modelicaParser::StatementContext::expression() {
  return getRuleContext<modelicaParser::ExpressionContext>(0);
}


size_t modelicaParser::StatementContext::getRuleIndex() const {
  return modelicaParser::RuleStatement;
}

void modelicaParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void modelicaParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any modelicaParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::StatementContext* modelicaParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 86, modelicaParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(630);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::T__86:
      case modelicaParser::IDENT: {
        setState(611);
        component_reference();
        setState(615);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case modelicaParser::T__46: {
            setState(612);
            match(modelicaParser::T__46);
            setState(613);
            expression();
            break;
          }

          case modelicaParser::T__21: {
            setState(614);
            function_call_args();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case modelicaParser::T__21: {
        setState(617);
        match(modelicaParser::T__21);
        setState(618);
        output_expression_list();
        setState(619);
        match(modelicaParser::T__23);
        setState(620);
        match(modelicaParser::T__46);
        setState(621);
        component_reference();
        setState(622);
        function_call_args();
        break;
      }

      case modelicaParser::T__51: {
        setState(624);
        match(modelicaParser::T__51);
        break;
      }

      case modelicaParser::T__52: {
        setState(625);
        match(modelicaParser::T__52);
        break;
      }

      case modelicaParser::T__45: {
        setState(626);
        if_statement();
        break;
      }

      case modelicaParser::T__56: {
        setState(627);
        for_statement();
        break;
      }

      case modelicaParser::T__59: {
        setState(628);
        while_statement();
        break;
      }

      case modelicaParser::T__60: {
        setState(629);
        when_statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(633);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::STRING) {
      setState(632);
      comment();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_equationContext ------------------------------------------------------------------

modelicaParser::If_equationContext::If_equationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::ExpressionContext *> modelicaParser::If_equationContext::expression() {
  return getRuleContexts<modelicaParser::ExpressionContext>();
}

modelicaParser::ExpressionContext* modelicaParser::If_equationContext::expression(size_t i) {
  return getRuleContext<modelicaParser::ExpressionContext>(i);
}

std::vector<modelicaParser::EquationContext *> modelicaParser::If_equationContext::equation() {
  return getRuleContexts<modelicaParser::EquationContext>();
}

modelicaParser::EquationContext* modelicaParser::If_equationContext::equation(size_t i) {
  return getRuleContext<modelicaParser::EquationContext>(i);
}


size_t modelicaParser::If_equationContext::getRuleIndex() const {
  return modelicaParser::RuleIf_equation;
}

void modelicaParser::If_equationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_equation(this);
}

void modelicaParser::If_equationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_equation(this);
}


antlrcpp::Any modelicaParser::If_equationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitIf_equation(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::If_equationContext* modelicaParser::if_equation() {
  If_equationContext *_localctx = _tracker.createInstance<If_equationContext>(_ctx, getState());
  enterRule(_localctx, 88, modelicaParser::RuleIf_equation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(635);
    match(modelicaParser::T__45);
    setState(636);
    expression();
    setState(637);
    match(modelicaParser::T__53);
    setState(643);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(638);
        equation();
        setState(639);
        match(modelicaParser::T__1); 
      }
      setState(645);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
    }
    setState(659);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__54) {
      setState(646);
      match(modelicaParser::T__54);
      setState(647);
      expression();
      setState(648);
      match(modelicaParser::T__53);
      setState(654);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(649);
          equation();
          setState(650);
          match(modelicaParser::T__1); 
        }
        setState(656);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      }
      setState(661);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(671);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__55) {
      setState(662);
      match(modelicaParser::T__55);
      setState(668);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(663);
          equation();
          setState(664);
          match(modelicaParser::T__1); 
        }
        setState(670);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      }
    }
    setState(673);
    match(modelicaParser::T__17);
    setState(674);
    match(modelicaParser::T__45);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

modelicaParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::ExpressionContext *> modelicaParser::If_statementContext::expression() {
  return getRuleContexts<modelicaParser::ExpressionContext>();
}

modelicaParser::ExpressionContext* modelicaParser::If_statementContext::expression(size_t i) {
  return getRuleContext<modelicaParser::ExpressionContext>(i);
}

std::vector<modelicaParser::StatementContext *> modelicaParser::If_statementContext::statement() {
  return getRuleContexts<modelicaParser::StatementContext>();
}

modelicaParser::StatementContext* modelicaParser::If_statementContext::statement(size_t i) {
  return getRuleContext<modelicaParser::StatementContext>(i);
}


size_t modelicaParser::If_statementContext::getRuleIndex() const {
  return modelicaParser::RuleIf_statement;
}

void modelicaParser::If_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_statement(this);
}

void modelicaParser::If_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_statement(this);
}


antlrcpp::Any modelicaParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::If_statementContext* modelicaParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 90, modelicaParser::RuleIf_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(676);
    match(modelicaParser::T__45);
    setState(677);
    expression();
    setState(678);
    match(modelicaParser::T__53);
    setState(684);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__21)
      | (1ULL << modelicaParser::T__45)
      | (1ULL << modelicaParser::T__51)
      | (1ULL << modelicaParser::T__52)
      | (1ULL << modelicaParser::T__56)
      | (1ULL << modelicaParser::T__59)
      | (1ULL << modelicaParser::T__60))) != 0) || _la == modelicaParser::T__86

    || _la == modelicaParser::IDENT) {
      setState(679);
      statement();
      setState(680);
      match(modelicaParser::T__1);
      setState(686);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(700);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__54) {
      setState(687);
      match(modelicaParser::T__54);
      setState(688);
      expression();
      setState(689);
      match(modelicaParser::T__53);
      setState(695);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << modelicaParser::T__21)
        | (1ULL << modelicaParser::T__45)
        | (1ULL << modelicaParser::T__51)
        | (1ULL << modelicaParser::T__52)
        | (1ULL << modelicaParser::T__56)
        | (1ULL << modelicaParser::T__59)
        | (1ULL << modelicaParser::T__60))) != 0) || _la == modelicaParser::T__86

      || _la == modelicaParser::IDENT) {
        setState(690);
        statement();
        setState(691);
        match(modelicaParser::T__1);
        setState(697);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(702);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(712);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__55) {
      setState(703);
      match(modelicaParser::T__55);
      setState(709);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << modelicaParser::T__21)
        | (1ULL << modelicaParser::T__45)
        | (1ULL << modelicaParser::T__51)
        | (1ULL << modelicaParser::T__52)
        | (1ULL << modelicaParser::T__56)
        | (1ULL << modelicaParser::T__59)
        | (1ULL << modelicaParser::T__60))) != 0) || _la == modelicaParser::T__86

      || _la == modelicaParser::IDENT) {
        setState(704);
        statement();
        setState(705);
        match(modelicaParser::T__1);
        setState(711);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(714);
    match(modelicaParser::T__17);
    setState(715);
    match(modelicaParser::T__45);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_equationContext ------------------------------------------------------------------

modelicaParser::For_equationContext::For_equationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::For_indicesContext* modelicaParser::For_equationContext::for_indices() {
  return getRuleContext<modelicaParser::For_indicesContext>(0);
}

std::vector<modelicaParser::EquationContext *> modelicaParser::For_equationContext::equation() {
  return getRuleContexts<modelicaParser::EquationContext>();
}

modelicaParser::EquationContext* modelicaParser::For_equationContext::equation(size_t i) {
  return getRuleContext<modelicaParser::EquationContext>(i);
}


size_t modelicaParser::For_equationContext::getRuleIndex() const {
  return modelicaParser::RuleFor_equation;
}

void modelicaParser::For_equationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_equation(this);
}

void modelicaParser::For_equationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_equation(this);
}


antlrcpp::Any modelicaParser::For_equationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitFor_equation(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::For_equationContext* modelicaParser::for_equation() {
  For_equationContext *_localctx = _tracker.createInstance<For_equationContext>(_ctx, getState());
  enterRule(_localctx, 92, modelicaParser::RuleFor_equation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(717);
    match(modelicaParser::T__56);
    setState(718);
    for_indices();
    setState(719);
    match(modelicaParser::T__57);
    setState(725);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(720);
        equation();
        setState(721);
        match(modelicaParser::T__1); 
      }
      setState(727);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
    }
    setState(728);
    match(modelicaParser::T__17);
    setState(729);
    match(modelicaParser::T__56);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_statementContext ------------------------------------------------------------------

modelicaParser::For_statementContext::For_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::For_indicesContext* modelicaParser::For_statementContext::for_indices() {
  return getRuleContext<modelicaParser::For_indicesContext>(0);
}

std::vector<modelicaParser::StatementContext *> modelicaParser::For_statementContext::statement() {
  return getRuleContexts<modelicaParser::StatementContext>();
}

modelicaParser::StatementContext* modelicaParser::For_statementContext::statement(size_t i) {
  return getRuleContext<modelicaParser::StatementContext>(i);
}


size_t modelicaParser::For_statementContext::getRuleIndex() const {
  return modelicaParser::RuleFor_statement;
}

void modelicaParser::For_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_statement(this);
}

void modelicaParser::For_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_statement(this);
}


antlrcpp::Any modelicaParser::For_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitFor_statement(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::For_statementContext* modelicaParser::for_statement() {
  For_statementContext *_localctx = _tracker.createInstance<For_statementContext>(_ctx, getState());
  enterRule(_localctx, 94, modelicaParser::RuleFor_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(731);
    match(modelicaParser::T__56);
    setState(732);
    for_indices();
    setState(733);
    match(modelicaParser::T__57);
    setState(739);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__21)
      | (1ULL << modelicaParser::T__45)
      | (1ULL << modelicaParser::T__51)
      | (1ULL << modelicaParser::T__52)
      | (1ULL << modelicaParser::T__56)
      | (1ULL << modelicaParser::T__59)
      | (1ULL << modelicaParser::T__60))) != 0) || _la == modelicaParser::T__86

    || _la == modelicaParser::IDENT) {
      setState(734);
      statement();
      setState(735);
      match(modelicaParser::T__1);
      setState(741);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(742);
    match(modelicaParser::T__17);
    setState(743);
    match(modelicaParser::T__56);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_indicesContext ------------------------------------------------------------------

modelicaParser::For_indicesContext::For_indicesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::For_indexContext *> modelicaParser::For_indicesContext::for_index() {
  return getRuleContexts<modelicaParser::For_indexContext>();
}

modelicaParser::For_indexContext* modelicaParser::For_indicesContext::for_index(size_t i) {
  return getRuleContext<modelicaParser::For_indexContext>(i);
}


size_t modelicaParser::For_indicesContext::getRuleIndex() const {
  return modelicaParser::RuleFor_indices;
}

void modelicaParser::For_indicesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_indices(this);
}

void modelicaParser::For_indicesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_indices(this);
}


antlrcpp::Any modelicaParser::For_indicesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitFor_indices(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::For_indicesContext* modelicaParser::for_indices() {
  For_indicesContext *_localctx = _tracker.createInstance<For_indicesContext>(_ctx, getState());
  enterRule(_localctx, 96, modelicaParser::RuleFor_indices);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(745);
    for_index();
    setState(750);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__25) {
      setState(746);
      match(modelicaParser::T__25);
      setState(747);
      for_index();
      setState(752);
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

//----------------- For_indexContext ------------------------------------------------------------------

modelicaParser::For_indexContext::For_indexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* modelicaParser::For_indexContext::IDENT() {
  return getToken(modelicaParser::IDENT, 0);
}

modelicaParser::ExpressionContext* modelicaParser::For_indexContext::expression() {
  return getRuleContext<modelicaParser::ExpressionContext>(0);
}


size_t modelicaParser::For_indexContext::getRuleIndex() const {
  return modelicaParser::RuleFor_index;
}

void modelicaParser::For_indexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_index(this);
}

void modelicaParser::For_indexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_index(this);
}


antlrcpp::Any modelicaParser::For_indexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitFor_index(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::For_indexContext* modelicaParser::for_index() {
  For_indexContext *_localctx = _tracker.createInstance<For_indexContext>(_ctx, getState());
  enterRule(_localctx, 98, modelicaParser::RuleFor_index);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(753);
    match(modelicaParser::IDENT);
    setState(756);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__58) {
      setState(754);
      match(modelicaParser::T__58);
      setState(755);
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

//----------------- While_statementContext ------------------------------------------------------------------

modelicaParser::While_statementContext::While_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::ExpressionContext* modelicaParser::While_statementContext::expression() {
  return getRuleContext<modelicaParser::ExpressionContext>(0);
}

std::vector<modelicaParser::StatementContext *> modelicaParser::While_statementContext::statement() {
  return getRuleContexts<modelicaParser::StatementContext>();
}

modelicaParser::StatementContext* modelicaParser::While_statementContext::statement(size_t i) {
  return getRuleContext<modelicaParser::StatementContext>(i);
}


size_t modelicaParser::While_statementContext::getRuleIndex() const {
  return modelicaParser::RuleWhile_statement;
}

void modelicaParser::While_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_statement(this);
}

void modelicaParser::While_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_statement(this);
}


antlrcpp::Any modelicaParser::While_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitWhile_statement(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::While_statementContext* modelicaParser::while_statement() {
  While_statementContext *_localctx = _tracker.createInstance<While_statementContext>(_ctx, getState());
  enterRule(_localctx, 100, modelicaParser::RuleWhile_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(758);
    match(modelicaParser::T__59);
    setState(759);
    expression();
    setState(760);
    match(modelicaParser::T__57);
    setState(766);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__21)
      | (1ULL << modelicaParser::T__45)
      | (1ULL << modelicaParser::T__51)
      | (1ULL << modelicaParser::T__52)
      | (1ULL << modelicaParser::T__56)
      | (1ULL << modelicaParser::T__59)
      | (1ULL << modelicaParser::T__60))) != 0) || _la == modelicaParser::T__86

    || _la == modelicaParser::IDENT) {
      setState(761);
      statement();
      setState(762);
      match(modelicaParser::T__1);
      setState(768);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(769);
    match(modelicaParser::T__17);
    setState(770);
    match(modelicaParser::T__59);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- When_equationContext ------------------------------------------------------------------

modelicaParser::When_equationContext::When_equationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::ExpressionContext *> modelicaParser::When_equationContext::expression() {
  return getRuleContexts<modelicaParser::ExpressionContext>();
}

modelicaParser::ExpressionContext* modelicaParser::When_equationContext::expression(size_t i) {
  return getRuleContext<modelicaParser::ExpressionContext>(i);
}

std::vector<modelicaParser::EquationContext *> modelicaParser::When_equationContext::equation() {
  return getRuleContexts<modelicaParser::EquationContext>();
}

modelicaParser::EquationContext* modelicaParser::When_equationContext::equation(size_t i) {
  return getRuleContext<modelicaParser::EquationContext>(i);
}


size_t modelicaParser::When_equationContext::getRuleIndex() const {
  return modelicaParser::RuleWhen_equation;
}

void modelicaParser::When_equationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhen_equation(this);
}

void modelicaParser::When_equationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhen_equation(this);
}


antlrcpp::Any modelicaParser::When_equationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitWhen_equation(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::When_equationContext* modelicaParser::when_equation() {
  When_equationContext *_localctx = _tracker.createInstance<When_equationContext>(_ctx, getState());
  enterRule(_localctx, 102, modelicaParser::RuleWhen_equation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(772);
    match(modelicaParser::T__60);
    setState(773);
    expression();
    setState(774);
    match(modelicaParser::T__53);
    setState(780);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(775);
        equation();
        setState(776);
        match(modelicaParser::T__1); 
      }
      setState(782);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
    }
    setState(796);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__61) {
      setState(783);
      match(modelicaParser::T__61);
      setState(784);
      expression();
      setState(785);
      match(modelicaParser::T__53);
      setState(791);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(786);
          equation();
          setState(787);
          match(modelicaParser::T__1); 
        }
        setState(793);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx);
      }
      setState(798);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(799);
    match(modelicaParser::T__17);
    setState(800);
    match(modelicaParser::T__60);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- When_statementContext ------------------------------------------------------------------

modelicaParser::When_statementContext::When_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::ExpressionContext *> modelicaParser::When_statementContext::expression() {
  return getRuleContexts<modelicaParser::ExpressionContext>();
}

modelicaParser::ExpressionContext* modelicaParser::When_statementContext::expression(size_t i) {
  return getRuleContext<modelicaParser::ExpressionContext>(i);
}

std::vector<modelicaParser::StatementContext *> modelicaParser::When_statementContext::statement() {
  return getRuleContexts<modelicaParser::StatementContext>();
}

modelicaParser::StatementContext* modelicaParser::When_statementContext::statement(size_t i) {
  return getRuleContext<modelicaParser::StatementContext>(i);
}


size_t modelicaParser::When_statementContext::getRuleIndex() const {
  return modelicaParser::RuleWhen_statement;
}

void modelicaParser::When_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhen_statement(this);
}

void modelicaParser::When_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhen_statement(this);
}


antlrcpp::Any modelicaParser::When_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitWhen_statement(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::When_statementContext* modelicaParser::when_statement() {
  When_statementContext *_localctx = _tracker.createInstance<When_statementContext>(_ctx, getState());
  enterRule(_localctx, 104, modelicaParser::RuleWhen_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(802);
    match(modelicaParser::T__60);
    setState(803);
    expression();
    setState(804);
    match(modelicaParser::T__53);
    setState(810);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__21)
      | (1ULL << modelicaParser::T__45)
      | (1ULL << modelicaParser::T__51)
      | (1ULL << modelicaParser::T__52)
      | (1ULL << modelicaParser::T__56)
      | (1ULL << modelicaParser::T__59)
      | (1ULL << modelicaParser::T__60))) != 0) || _la == modelicaParser::T__86

    || _la == modelicaParser::IDENT) {
      setState(805);
      statement();
      setState(806);
      match(modelicaParser::T__1);
      setState(812);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(826);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__61) {
      setState(813);
      match(modelicaParser::T__61);
      setState(814);
      expression();
      setState(815);
      match(modelicaParser::T__53);
      setState(821);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << modelicaParser::T__21)
        | (1ULL << modelicaParser::T__45)
        | (1ULL << modelicaParser::T__51)
        | (1ULL << modelicaParser::T__52)
        | (1ULL << modelicaParser::T__56)
        | (1ULL << modelicaParser::T__59)
        | (1ULL << modelicaParser::T__60))) != 0) || _la == modelicaParser::T__86

      || _la == modelicaParser::IDENT) {
        setState(816);
        statement();
        setState(817);
        match(modelicaParser::T__1);
        setState(823);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(828);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(829);
    match(modelicaParser::T__17);
    setState(830);
    match(modelicaParser::T__60);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Connect_clauseContext ------------------------------------------------------------------

modelicaParser::Connect_clauseContext::Connect_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::Component_referenceContext *> modelicaParser::Connect_clauseContext::component_reference() {
  return getRuleContexts<modelicaParser::Component_referenceContext>();
}

modelicaParser::Component_referenceContext* modelicaParser::Connect_clauseContext::component_reference(size_t i) {
  return getRuleContext<modelicaParser::Component_referenceContext>(i);
}


size_t modelicaParser::Connect_clauseContext::getRuleIndex() const {
  return modelicaParser::RuleConnect_clause;
}

void modelicaParser::Connect_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConnect_clause(this);
}

void modelicaParser::Connect_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConnect_clause(this);
}


antlrcpp::Any modelicaParser::Connect_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitConnect_clause(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Connect_clauseContext* modelicaParser::connect_clause() {
  Connect_clauseContext *_localctx = _tracker.createInstance<Connect_clauseContext>(_ctx, getState());
  enterRule(_localctx, 106, modelicaParser::RuleConnect_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(832);
    match(modelicaParser::T__62);
    setState(833);
    match(modelicaParser::T__21);
    setState(834);
    component_reference();
    setState(835);
    match(modelicaParser::T__25);
    setState(836);
    component_reference();
    setState(837);
    match(modelicaParser::T__23);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

modelicaParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Simple_expressionContext* modelicaParser::ExpressionContext::simple_expression() {
  return getRuleContext<modelicaParser::Simple_expressionContext>(0);
}

std::vector<modelicaParser::ExpressionContext *> modelicaParser::ExpressionContext::expression() {
  return getRuleContexts<modelicaParser::ExpressionContext>();
}

modelicaParser::ExpressionContext* modelicaParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<modelicaParser::ExpressionContext>(i);
}


size_t modelicaParser::ExpressionContext::getRuleIndex() const {
  return modelicaParser::RuleExpression;
}

void modelicaParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void modelicaParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any modelicaParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::ExpressionContext* modelicaParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 108, modelicaParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(857);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::T__17:
      case modelicaParser::T__21:
      case modelicaParser::T__24:
      case modelicaParser::T__48:
      case modelicaParser::T__65:
      case modelicaParser::T__72:
      case modelicaParser::T__73:
      case modelicaParser::T__74:
      case modelicaParser::T__75:
      case modelicaParser::T__81:
      case modelicaParser::T__82:
      case modelicaParser::T__83:
      case modelicaParser::T__85:
      case modelicaParser::T__86:
      case modelicaParser::IDENT:
      case modelicaParser::STRING:
      case modelicaParser::UNSIGNED_NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(839);
        simple_expression();
        break;
      }

      case modelicaParser::T__45: {
        enterOuterAlt(_localctx, 2);
        setState(840);
        match(modelicaParser::T__45);
        setState(841);
        expression();
        setState(842);
        match(modelicaParser::T__53);
        setState(843);
        expression();
        setState(851);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == modelicaParser::T__54) {
          setState(844);
          match(modelicaParser::T__54);
          setState(845);
          expression();
          setState(846);
          match(modelicaParser::T__53);
          setState(847);
          expression();
          setState(853);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(854);
        match(modelicaParser::T__55);
        setState(855);
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

//----------------- Simple_expressionContext ------------------------------------------------------------------

modelicaParser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::Logical_expressionContext *> modelicaParser::Simple_expressionContext::logical_expression() {
  return getRuleContexts<modelicaParser::Logical_expressionContext>();
}

modelicaParser::Logical_expressionContext* modelicaParser::Simple_expressionContext::logical_expression(size_t i) {
  return getRuleContext<modelicaParser::Logical_expressionContext>(i);
}


size_t modelicaParser::Simple_expressionContext::getRuleIndex() const {
  return modelicaParser::RuleSimple_expression;
}

void modelicaParser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void modelicaParser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


antlrcpp::Any modelicaParser::Simple_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitSimple_expression(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Simple_expressionContext* modelicaParser::simple_expression() {
  Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, getState());
  enterRule(_localctx, 110, modelicaParser::RuleSimple_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(859);
    logical_expression();
    setState(866);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__22) {
      setState(860);
      match(modelicaParser::T__22);
      setState(861);
      logical_expression();
      setState(864);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::T__22) {
        setState(862);
        match(modelicaParser::T__22);
        setState(863);
        logical_expression();
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

//----------------- Logical_expressionContext ------------------------------------------------------------------

modelicaParser::Logical_expressionContext::Logical_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::Logical_termContext *> modelicaParser::Logical_expressionContext::logical_term() {
  return getRuleContexts<modelicaParser::Logical_termContext>();
}

modelicaParser::Logical_termContext* modelicaParser::Logical_expressionContext::logical_term(size_t i) {
  return getRuleContext<modelicaParser::Logical_termContext>(i);
}


size_t modelicaParser::Logical_expressionContext::getRuleIndex() const {
  return modelicaParser::RuleLogical_expression;
}

void modelicaParser::Logical_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_expression(this);
}

void modelicaParser::Logical_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_expression(this);
}


antlrcpp::Any modelicaParser::Logical_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitLogical_expression(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Logical_expressionContext* modelicaParser::logical_expression() {
  Logical_expressionContext *_localctx = _tracker.createInstance<Logical_expressionContext>(_ctx, getState());
  enterRule(_localctx, 112, modelicaParser::RuleLogical_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(868);
    logical_term();
    setState(873);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__63) {
      setState(869);
      match(modelicaParser::T__63);
      setState(870);
      logical_term();
      setState(875);
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

//----------------- Logical_termContext ------------------------------------------------------------------

modelicaParser::Logical_termContext::Logical_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::Logical_factorContext *> modelicaParser::Logical_termContext::logical_factor() {
  return getRuleContexts<modelicaParser::Logical_factorContext>();
}

modelicaParser::Logical_factorContext* modelicaParser::Logical_termContext::logical_factor(size_t i) {
  return getRuleContext<modelicaParser::Logical_factorContext>(i);
}


size_t modelicaParser::Logical_termContext::getRuleIndex() const {
  return modelicaParser::RuleLogical_term;
}

void modelicaParser::Logical_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_term(this);
}

void modelicaParser::Logical_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_term(this);
}


antlrcpp::Any modelicaParser::Logical_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitLogical_term(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Logical_termContext* modelicaParser::logical_term() {
  Logical_termContext *_localctx = _tracker.createInstance<Logical_termContext>(_ctx, getState());
  enterRule(_localctx, 114, modelicaParser::RuleLogical_term);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(876);
    logical_factor();
    setState(881);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__64) {
      setState(877);
      match(modelicaParser::T__64);
      setState(878);
      logical_factor();
      setState(883);
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

//----------------- Logical_factorContext ------------------------------------------------------------------

modelicaParser::Logical_factorContext::Logical_factorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::RelationContext* modelicaParser::Logical_factorContext::relation() {
  return getRuleContext<modelicaParser::RelationContext>(0);
}


size_t modelicaParser::Logical_factorContext::getRuleIndex() const {
  return modelicaParser::RuleLogical_factor;
}

void modelicaParser::Logical_factorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_factor(this);
}

void modelicaParser::Logical_factorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_factor(this);
}


antlrcpp::Any modelicaParser::Logical_factorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitLogical_factor(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Logical_factorContext* modelicaParser::logical_factor() {
  Logical_factorContext *_localctx = _tracker.createInstance<Logical_factorContext>(_ctx, getState());
  enterRule(_localctx, 116, modelicaParser::RuleLogical_factor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(885);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__65) {
      setState(884);
      match(modelicaParser::T__65);
    }
    setState(887);
    relation();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationContext ------------------------------------------------------------------

modelicaParser::RelationContext::RelationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::Arithmetic_expressionContext *> modelicaParser::RelationContext::arithmetic_expression() {
  return getRuleContexts<modelicaParser::Arithmetic_expressionContext>();
}

modelicaParser::Arithmetic_expressionContext* modelicaParser::RelationContext::arithmetic_expression(size_t i) {
  return getRuleContext<modelicaParser::Arithmetic_expressionContext>(i);
}

modelicaParser::Rel_opContext* modelicaParser::RelationContext::rel_op() {
  return getRuleContext<modelicaParser::Rel_opContext>(0);
}


size_t modelicaParser::RelationContext::getRuleIndex() const {
  return modelicaParser::RuleRelation;
}

void modelicaParser::RelationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelation(this);
}

void modelicaParser::RelationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelation(this);
}


antlrcpp::Any modelicaParser::RelationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitRelation(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::RelationContext* modelicaParser::relation() {
  RelationContext *_localctx = _tracker.createInstance<RelationContext>(_ctx, getState());
  enterRule(_localctx, 118, modelicaParser::RuleRelation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(889);
    arithmetic_expression();
    setState(893);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (modelicaParser::T__66 - 67))
      | (1ULL << (modelicaParser::T__67 - 67))
      | (1ULL << (modelicaParser::T__68 - 67))
      | (1ULL << (modelicaParser::T__69 - 67))
      | (1ULL << (modelicaParser::T__70 - 67))
      | (1ULL << (modelicaParser::T__71 - 67)))) != 0)) {
      setState(890);
      rel_op();
      setState(891);
      arithmetic_expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_opContext ------------------------------------------------------------------

modelicaParser::Rel_opContext::Rel_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t modelicaParser::Rel_opContext::getRuleIndex() const {
  return modelicaParser::RuleRel_op;
}

void modelicaParser::Rel_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_op(this);
}

void modelicaParser::Rel_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_op(this);
}


antlrcpp::Any modelicaParser::Rel_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitRel_op(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Rel_opContext* modelicaParser::rel_op() {
  Rel_opContext *_localctx = _tracker.createInstance<Rel_opContext>(_ctx, getState());
  enterRule(_localctx, 120, modelicaParser::RuleRel_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(895);
    _la = _input->LA(1);
    if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (modelicaParser::T__66 - 67))
      | (1ULL << (modelicaParser::T__67 - 67))
      | (1ULL << (modelicaParser::T__68 - 67))
      | (1ULL << (modelicaParser::T__69 - 67))
      | (1ULL << (modelicaParser::T__70 - 67))
      | (1ULL << (modelicaParser::T__71 - 67)))) != 0))) {
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

//----------------- Arithmetic_expressionContext ------------------------------------------------------------------

modelicaParser::Arithmetic_expressionContext::Arithmetic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::TermContext *> modelicaParser::Arithmetic_expressionContext::term() {
  return getRuleContexts<modelicaParser::TermContext>();
}

modelicaParser::TermContext* modelicaParser::Arithmetic_expressionContext::term(size_t i) {
  return getRuleContext<modelicaParser::TermContext>(i);
}

std::vector<modelicaParser::Add_opContext *> modelicaParser::Arithmetic_expressionContext::add_op() {
  return getRuleContexts<modelicaParser::Add_opContext>();
}

modelicaParser::Add_opContext* modelicaParser::Arithmetic_expressionContext::add_op(size_t i) {
  return getRuleContext<modelicaParser::Add_opContext>(i);
}


size_t modelicaParser::Arithmetic_expressionContext::getRuleIndex() const {
  return modelicaParser::RuleArithmetic_expression;
}

void modelicaParser::Arithmetic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic_expression(this);
}

void modelicaParser::Arithmetic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic_expression(this);
}


antlrcpp::Any modelicaParser::Arithmetic_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitArithmetic_expression(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Arithmetic_expressionContext* modelicaParser::arithmetic_expression() {
  Arithmetic_expressionContext *_localctx = _tracker.createInstance<Arithmetic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 122, modelicaParser::RuleArithmetic_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(898);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 73) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 73)) & ((1ULL << (modelicaParser::T__72 - 73))
      | (1ULL << (modelicaParser::T__73 - 73))
      | (1ULL << (modelicaParser::T__74 - 73))
      | (1ULL << (modelicaParser::T__75 - 73)))) != 0)) {
      setState(897);
      add_op();
    }
    setState(900);
    term();
    setState(906);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 73) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 73)) & ((1ULL << (modelicaParser::T__72 - 73))
      | (1ULL << (modelicaParser::T__73 - 73))
      | (1ULL << (modelicaParser::T__74 - 73))
      | (1ULL << (modelicaParser::T__75 - 73)))) != 0)) {
      setState(901);
      add_op();
      setState(902);
      term();
      setState(908);
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

//----------------- Add_opContext ------------------------------------------------------------------

modelicaParser::Add_opContext::Add_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t modelicaParser::Add_opContext::getRuleIndex() const {
  return modelicaParser::RuleAdd_op;
}

void modelicaParser::Add_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd_op(this);
}

void modelicaParser::Add_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd_op(this);
}


antlrcpp::Any modelicaParser::Add_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitAdd_op(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Add_opContext* modelicaParser::add_op() {
  Add_opContext *_localctx = _tracker.createInstance<Add_opContext>(_ctx, getState());
  enterRule(_localctx, 124, modelicaParser::RuleAdd_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(909);
    _la = _input->LA(1);
    if (!(((((_la - 73) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 73)) & ((1ULL << (modelicaParser::T__72 - 73))
      | (1ULL << (modelicaParser::T__73 - 73))
      | (1ULL << (modelicaParser::T__74 - 73))
      | (1ULL << (modelicaParser::T__75 - 73)))) != 0))) {
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

//----------------- TermContext ------------------------------------------------------------------

modelicaParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::FactorContext *> modelicaParser::TermContext::factor() {
  return getRuleContexts<modelicaParser::FactorContext>();
}

modelicaParser::FactorContext* modelicaParser::TermContext::factor(size_t i) {
  return getRuleContext<modelicaParser::FactorContext>(i);
}

std::vector<modelicaParser::Mul_opContext *> modelicaParser::TermContext::mul_op() {
  return getRuleContexts<modelicaParser::Mul_opContext>();
}

modelicaParser::Mul_opContext* modelicaParser::TermContext::mul_op(size_t i) {
  return getRuleContext<modelicaParser::Mul_opContext>(i);
}


size_t modelicaParser::TermContext::getRuleIndex() const {
  return modelicaParser::RuleTerm;
}

void modelicaParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void modelicaParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


antlrcpp::Any modelicaParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::TermContext* modelicaParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 126, modelicaParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(911);
    factor();
    setState(917);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 35) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 35)) & ((1ULL << (modelicaParser::T__34 - 35))
      | (1ULL << (modelicaParser::T__76 - 35))
      | (1ULL << (modelicaParser::T__77 - 35))
      | (1ULL << (modelicaParser::T__78 - 35)))) != 0)) {
      setState(912);
      mul_op();
      setState(913);
      factor();
      setState(919);
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

//----------------- Mul_opContext ------------------------------------------------------------------

modelicaParser::Mul_opContext::Mul_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t modelicaParser::Mul_opContext::getRuleIndex() const {
  return modelicaParser::RuleMul_op;
}

void modelicaParser::Mul_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMul_op(this);
}

void modelicaParser::Mul_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMul_op(this);
}


antlrcpp::Any modelicaParser::Mul_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitMul_op(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Mul_opContext* modelicaParser::mul_op() {
  Mul_opContext *_localctx = _tracker.createInstance<Mul_opContext>(_ctx, getState());
  enterRule(_localctx, 128, modelicaParser::RuleMul_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(920);
    _la = _input->LA(1);
    if (!(((((_la - 35) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 35)) & ((1ULL << (modelicaParser::T__34 - 35))
      | (1ULL << (modelicaParser::T__76 - 35))
      | (1ULL << (modelicaParser::T__77 - 35))
      | (1ULL << (modelicaParser::T__78 - 35)))) != 0))) {
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

//----------------- FactorContext ------------------------------------------------------------------

modelicaParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::PrimaryContext *> modelicaParser::FactorContext::primary() {
  return getRuleContexts<modelicaParser::PrimaryContext>();
}

modelicaParser::PrimaryContext* modelicaParser::FactorContext::primary(size_t i) {
  return getRuleContext<modelicaParser::PrimaryContext>(i);
}


size_t modelicaParser::FactorContext::getRuleIndex() const {
  return modelicaParser::RuleFactor;
}

void modelicaParser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void modelicaParser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}


antlrcpp::Any modelicaParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::FactorContext* modelicaParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 130, modelicaParser::RuleFactor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(922);
    primary();
    setState(925);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__79

    || _la == modelicaParser::T__80) {
      setState(923);
      _la = _input->LA(1);
      if (!(_la == modelicaParser::T__79

      || _la == modelicaParser::T__80)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(924);
      primary();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

modelicaParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* modelicaParser::PrimaryContext::UNSIGNED_NUMBER() {
  return getToken(modelicaParser::UNSIGNED_NUMBER, 0);
}

tree::TerminalNode* modelicaParser::PrimaryContext::STRING() {
  return getToken(modelicaParser::STRING, 0);
}

modelicaParser::Function_call_argsContext* modelicaParser::PrimaryContext::function_call_args() {
  return getRuleContext<modelicaParser::Function_call_argsContext>(0);
}

modelicaParser::NameContext* modelicaParser::PrimaryContext::name() {
  return getRuleContext<modelicaParser::NameContext>(0);
}

modelicaParser::Component_referenceContext* modelicaParser::PrimaryContext::component_reference() {
  return getRuleContext<modelicaParser::Component_referenceContext>(0);
}

modelicaParser::Output_expression_listContext* modelicaParser::PrimaryContext::output_expression_list() {
  return getRuleContext<modelicaParser::Output_expression_listContext>(0);
}

std::vector<modelicaParser::Expression_listContext *> modelicaParser::PrimaryContext::expression_list() {
  return getRuleContexts<modelicaParser::Expression_listContext>();
}

modelicaParser::Expression_listContext* modelicaParser::PrimaryContext::expression_list(size_t i) {
  return getRuleContext<modelicaParser::Expression_listContext>(i);
}

modelicaParser::Function_argumentsContext* modelicaParser::PrimaryContext::function_arguments() {
  return getRuleContext<modelicaParser::Function_argumentsContext>(0);
}


size_t modelicaParser::PrimaryContext::getRuleIndex() const {
  return modelicaParser::RulePrimary;
}

void modelicaParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void modelicaParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


antlrcpp::Any modelicaParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::PrimaryContext* modelicaParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 132, modelicaParser::RulePrimary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(958);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(927);
      match(modelicaParser::UNSIGNED_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(928);
      match(modelicaParser::STRING);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(929);
      match(modelicaParser::T__81);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(930);
      match(modelicaParser::T__82);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(934);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case modelicaParser::T__86:
        case modelicaParser::IDENT: {
          setState(931);
          name();
          break;
        }

        case modelicaParser::T__24: {
          setState(932);
          match(modelicaParser::T__24);
          break;
        }

        case modelicaParser::T__48: {
          setState(933);
          match(modelicaParser::T__48);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(936);
      function_call_args();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(937);
      component_reference();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(938);
      match(modelicaParser::T__21);
      setState(939);
      output_expression_list();
      setState(940);
      match(modelicaParser::T__23);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(942);
      match(modelicaParser::T__83);
      setState(943);
      expression_list();
      setState(948);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == modelicaParser::T__1) {
        setState(944);
        match(modelicaParser::T__1);
        setState(945);
        expression_list();
        setState(950);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(951);
      match(modelicaParser::T__84);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(953);
      match(modelicaParser::T__85);
      setState(954);
      function_arguments();
      setState(955);
      match(modelicaParser::T__36);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(957);
      match(modelicaParser::T__17);
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

//----------------- NameContext ------------------------------------------------------------------

modelicaParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> modelicaParser::NameContext::IDENT() {
  return getTokens(modelicaParser::IDENT);
}

tree::TerminalNode* modelicaParser::NameContext::IDENT(size_t i) {
  return getToken(modelicaParser::IDENT, i);
}


size_t modelicaParser::NameContext::getRuleIndex() const {
  return modelicaParser::RuleName;
}

void modelicaParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void modelicaParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}


antlrcpp::Any modelicaParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::NameContext* modelicaParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 134, modelicaParser::RuleName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(961);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__86) {
      setState(960);
      match(modelicaParser::T__86);
    }
    setState(963);
    match(modelicaParser::IDENT);
    setState(968);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__86) {
      setState(964);
      match(modelicaParser::T__86);
      setState(965);
      match(modelicaParser::IDENT);
      setState(970);
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

//----------------- Component_referenceContext ------------------------------------------------------------------

modelicaParser::Component_referenceContext::Component_referenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> modelicaParser::Component_referenceContext::IDENT() {
  return getTokens(modelicaParser::IDENT);
}

tree::TerminalNode* modelicaParser::Component_referenceContext::IDENT(size_t i) {
  return getToken(modelicaParser::IDENT, i);
}

std::vector<modelicaParser::Array_subscriptsContext *> modelicaParser::Component_referenceContext::array_subscripts() {
  return getRuleContexts<modelicaParser::Array_subscriptsContext>();
}

modelicaParser::Array_subscriptsContext* modelicaParser::Component_referenceContext::array_subscripts(size_t i) {
  return getRuleContext<modelicaParser::Array_subscriptsContext>(i);
}


size_t modelicaParser::Component_referenceContext::getRuleIndex() const {
  return modelicaParser::RuleComponent_reference;
}

void modelicaParser::Component_referenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_reference(this);
}

void modelicaParser::Component_referenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_reference(this);
}


antlrcpp::Any modelicaParser::Component_referenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitComponent_reference(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Component_referenceContext* modelicaParser::component_reference() {
  Component_referenceContext *_localctx = _tracker.createInstance<Component_referenceContext>(_ctx, getState());
  enterRule(_localctx, 136, modelicaParser::RuleComponent_reference);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(972);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__86) {
      setState(971);
      match(modelicaParser::T__86);
    }
    setState(974);
    match(modelicaParser::IDENT);
    setState(976);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__83) {
      setState(975);
      array_subscripts();
    }
    setState(985);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__86) {
      setState(978);
      match(modelicaParser::T__86);
      setState(979);
      match(modelicaParser::IDENT);
      setState(981);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == modelicaParser::T__83) {
        setState(980);
        array_subscripts();
      }
      setState(987);
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

//----------------- Function_call_argsContext ------------------------------------------------------------------

modelicaParser::Function_call_argsContext::Function_call_argsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Function_argumentsContext* modelicaParser::Function_call_argsContext::function_arguments() {
  return getRuleContext<modelicaParser::Function_argumentsContext>(0);
}


size_t modelicaParser::Function_call_argsContext::getRuleIndex() const {
  return modelicaParser::RuleFunction_call_args;
}

void modelicaParser::Function_call_argsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_call_args(this);
}

void modelicaParser::Function_call_argsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_call_args(this);
}


antlrcpp::Any modelicaParser::Function_call_argsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitFunction_call_args(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Function_call_argsContext* modelicaParser::function_call_args() {
  Function_call_argsContext *_localctx = _tracker.createInstance<Function_call_argsContext>(_ctx, getState());
  enterRule(_localctx, 138, modelicaParser::RuleFunction_call_args);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(988);
    match(modelicaParser::T__21);
    setState(990);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__16)
      | (1ULL << modelicaParser::T__17)
      | (1ULL << modelicaParser::T__21)
      | (1ULL << modelicaParser::T__24)
      | (1ULL << modelicaParser::T__45)
      | (1ULL << modelicaParser::T__48))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (modelicaParser::T__65 - 66))
      | (1ULL << (modelicaParser::T__72 - 66))
      | (1ULL << (modelicaParser::T__73 - 66))
      | (1ULL << (modelicaParser::T__74 - 66))
      | (1ULL << (modelicaParser::T__75 - 66))
      | (1ULL << (modelicaParser::T__81 - 66))
      | (1ULL << (modelicaParser::T__82 - 66))
      | (1ULL << (modelicaParser::T__83 - 66))
      | (1ULL << (modelicaParser::T__85 - 66))
      | (1ULL << (modelicaParser::T__86 - 66))
      | (1ULL << (modelicaParser::IDENT - 66))
      | (1ULL << (modelicaParser::STRING - 66))
      | (1ULL << (modelicaParser::UNSIGNED_NUMBER - 66)))) != 0)) {
      setState(989);
      function_arguments();
    }
    setState(992);
    match(modelicaParser::T__23);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_argumentsContext ------------------------------------------------------------------

modelicaParser::Function_argumentsContext::Function_argumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Function_argumentContext* modelicaParser::Function_argumentsContext::function_argument() {
  return getRuleContext<modelicaParser::Function_argumentContext>(0);
}

modelicaParser::Function_argumentsContext* modelicaParser::Function_argumentsContext::function_arguments() {
  return getRuleContext<modelicaParser::Function_argumentsContext>(0);
}

modelicaParser::For_indicesContext* modelicaParser::Function_argumentsContext::for_indices() {
  return getRuleContext<modelicaParser::For_indicesContext>(0);
}

modelicaParser::Named_argumentsContext* modelicaParser::Function_argumentsContext::named_arguments() {
  return getRuleContext<modelicaParser::Named_argumentsContext>(0);
}


size_t modelicaParser::Function_argumentsContext::getRuleIndex() const {
  return modelicaParser::RuleFunction_arguments;
}

void modelicaParser::Function_argumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_arguments(this);
}

void modelicaParser::Function_argumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_arguments(this);
}


antlrcpp::Any modelicaParser::Function_argumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitFunction_arguments(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Function_argumentsContext* modelicaParser::function_arguments() {
  Function_argumentsContext *_localctx = _tracker.createInstance<Function_argumentsContext>(_ctx, getState());
  enterRule(_localctx, 140, modelicaParser::RuleFunction_arguments);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1002);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 136, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(994);
      function_argument();
      setState(999);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case modelicaParser::T__25: {
          setState(995);
          match(modelicaParser::T__25);
          setState(996);
          function_arguments();
          break;
        }

        case modelicaParser::T__56: {
          setState(997);
          match(modelicaParser::T__56);
          setState(998);
          for_indices();
          break;
        }

        case modelicaParser::T__23:
        case modelicaParser::T__36: {
          break;
        }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1001);
      named_arguments();
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

//----------------- Named_argumentsContext ------------------------------------------------------------------

modelicaParser::Named_argumentsContext::Named_argumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Named_argumentContext* modelicaParser::Named_argumentsContext::named_argument() {
  return getRuleContext<modelicaParser::Named_argumentContext>(0);
}

modelicaParser::Named_argumentsContext* modelicaParser::Named_argumentsContext::named_arguments() {
  return getRuleContext<modelicaParser::Named_argumentsContext>(0);
}


size_t modelicaParser::Named_argumentsContext::getRuleIndex() const {
  return modelicaParser::RuleNamed_arguments;
}

void modelicaParser::Named_argumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamed_arguments(this);
}

void modelicaParser::Named_argumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamed_arguments(this);
}


antlrcpp::Any modelicaParser::Named_argumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitNamed_arguments(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Named_argumentsContext* modelicaParser::named_arguments() {
  Named_argumentsContext *_localctx = _tracker.createInstance<Named_argumentsContext>(_ctx, getState());
  enterRule(_localctx, 142, modelicaParser::RuleNamed_arguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1004);
    named_argument();
    setState(1007);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__25) {
      setState(1005);
      match(modelicaParser::T__25);
      setState(1006);
      named_arguments();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Named_argumentContext ------------------------------------------------------------------

modelicaParser::Named_argumentContext::Named_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* modelicaParser::Named_argumentContext::IDENT() {
  return getToken(modelicaParser::IDENT, 0);
}

modelicaParser::Function_argumentContext* modelicaParser::Named_argumentContext::function_argument() {
  return getRuleContext<modelicaParser::Function_argumentContext>(0);
}


size_t modelicaParser::Named_argumentContext::getRuleIndex() const {
  return modelicaParser::RuleNamed_argument;
}

void modelicaParser::Named_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamed_argument(this);
}

void modelicaParser::Named_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamed_argument(this);
}


antlrcpp::Any modelicaParser::Named_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitNamed_argument(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Named_argumentContext* modelicaParser::named_argument() {
  Named_argumentContext *_localctx = _tracker.createInstance<Named_argumentContext>(_ctx, getState());
  enterRule(_localctx, 144, modelicaParser::RuleNamed_argument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1009);
    match(modelicaParser::IDENT);
    setState(1010);
    match(modelicaParser::T__19);
    setState(1011);
    function_argument();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_argumentContext ------------------------------------------------------------------

modelicaParser::Function_argumentContext::Function_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::NameContext* modelicaParser::Function_argumentContext::name() {
  return getRuleContext<modelicaParser::NameContext>(0);
}

modelicaParser::Named_argumentsContext* modelicaParser::Function_argumentContext::named_arguments() {
  return getRuleContext<modelicaParser::Named_argumentsContext>(0);
}

modelicaParser::ExpressionContext* modelicaParser::Function_argumentContext::expression() {
  return getRuleContext<modelicaParser::ExpressionContext>(0);
}


size_t modelicaParser::Function_argumentContext::getRuleIndex() const {
  return modelicaParser::RuleFunction_argument;
}

void modelicaParser::Function_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_argument(this);
}

void modelicaParser::Function_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_argument(this);
}


antlrcpp::Any modelicaParser::Function_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitFunction_argument(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Function_argumentContext* modelicaParser::function_argument() {
  Function_argumentContext *_localctx = _tracker.createInstance<Function_argumentContext>(_ctx, getState());
  enterRule(_localctx, 146, modelicaParser::RuleFunction_argument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1022);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::T__16: {
        enterOuterAlt(_localctx, 1);
        setState(1013);
        match(modelicaParser::T__16);
        setState(1014);
        name();
        setState(1015);
        match(modelicaParser::T__21);
        setState(1017);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == modelicaParser::IDENT) {
          setState(1016);
          named_arguments();
        }
        setState(1019);
        match(modelicaParser::T__23);
        break;
      }

      case modelicaParser::T__17:
      case modelicaParser::T__21:
      case modelicaParser::T__24:
      case modelicaParser::T__45:
      case modelicaParser::T__48:
      case modelicaParser::T__65:
      case modelicaParser::T__72:
      case modelicaParser::T__73:
      case modelicaParser::T__74:
      case modelicaParser::T__75:
      case modelicaParser::T__81:
      case modelicaParser::T__82:
      case modelicaParser::T__83:
      case modelicaParser::T__85:
      case modelicaParser::T__86:
      case modelicaParser::IDENT:
      case modelicaParser::STRING:
      case modelicaParser::UNSIGNED_NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(1021);
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

//----------------- Output_expression_listContext ------------------------------------------------------------------

modelicaParser::Output_expression_listContext::Output_expression_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::ExpressionContext *> modelicaParser::Output_expression_listContext::expression() {
  return getRuleContexts<modelicaParser::ExpressionContext>();
}

modelicaParser::ExpressionContext* modelicaParser::Output_expression_listContext::expression(size_t i) {
  return getRuleContext<modelicaParser::ExpressionContext>(i);
}


size_t modelicaParser::Output_expression_listContext::getRuleIndex() const {
  return modelicaParser::RuleOutput_expression_list;
}

void modelicaParser::Output_expression_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOutput_expression_list(this);
}

void modelicaParser::Output_expression_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOutput_expression_list(this);
}


antlrcpp::Any modelicaParser::Output_expression_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitOutput_expression_list(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Output_expression_listContext* modelicaParser::output_expression_list() {
  Output_expression_listContext *_localctx = _tracker.createInstance<Output_expression_listContext>(_ctx, getState());
  enterRule(_localctx, 148, modelicaParser::RuleOutput_expression_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1025);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << modelicaParser::T__17)
      | (1ULL << modelicaParser::T__21)
      | (1ULL << modelicaParser::T__24)
      | (1ULL << modelicaParser::T__45)
      | (1ULL << modelicaParser::T__48))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (modelicaParser::T__65 - 66))
      | (1ULL << (modelicaParser::T__72 - 66))
      | (1ULL << (modelicaParser::T__73 - 66))
      | (1ULL << (modelicaParser::T__74 - 66))
      | (1ULL << (modelicaParser::T__75 - 66))
      | (1ULL << (modelicaParser::T__81 - 66))
      | (1ULL << (modelicaParser::T__82 - 66))
      | (1ULL << (modelicaParser::T__83 - 66))
      | (1ULL << (modelicaParser::T__85 - 66))
      | (1ULL << (modelicaParser::T__86 - 66))
      | (1ULL << (modelicaParser::IDENT - 66))
      | (1ULL << (modelicaParser::STRING - 66))
      | (1ULL << (modelicaParser::UNSIGNED_NUMBER - 66)))) != 0)) {
      setState(1024);
      expression();
    }
    setState(1033);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__25) {
      setState(1027);
      match(modelicaParser::T__25);
      setState(1029);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << modelicaParser::T__17)
        | (1ULL << modelicaParser::T__21)
        | (1ULL << modelicaParser::T__24)
        | (1ULL << modelicaParser::T__45)
        | (1ULL << modelicaParser::T__48))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 66)) & ((1ULL << (modelicaParser::T__65 - 66))
        | (1ULL << (modelicaParser::T__72 - 66))
        | (1ULL << (modelicaParser::T__73 - 66))
        | (1ULL << (modelicaParser::T__74 - 66))
        | (1ULL << (modelicaParser::T__75 - 66))
        | (1ULL << (modelicaParser::T__81 - 66))
        | (1ULL << (modelicaParser::T__82 - 66))
        | (1ULL << (modelicaParser::T__83 - 66))
        | (1ULL << (modelicaParser::T__85 - 66))
        | (1ULL << (modelicaParser::T__86 - 66))
        | (1ULL << (modelicaParser::IDENT - 66))
        | (1ULL << (modelicaParser::STRING - 66))
        | (1ULL << (modelicaParser::UNSIGNED_NUMBER - 66)))) != 0)) {
        setState(1028);
        expression();
      }
      setState(1035);
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

//----------------- Expression_listContext ------------------------------------------------------------------

modelicaParser::Expression_listContext::Expression_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::ExpressionContext *> modelicaParser::Expression_listContext::expression() {
  return getRuleContexts<modelicaParser::ExpressionContext>();
}

modelicaParser::ExpressionContext* modelicaParser::Expression_listContext::expression(size_t i) {
  return getRuleContext<modelicaParser::ExpressionContext>(i);
}


size_t modelicaParser::Expression_listContext::getRuleIndex() const {
  return modelicaParser::RuleExpression_list;
}

void modelicaParser::Expression_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_list(this);
}

void modelicaParser::Expression_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_list(this);
}


antlrcpp::Any modelicaParser::Expression_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitExpression_list(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Expression_listContext* modelicaParser::expression_list() {
  Expression_listContext *_localctx = _tracker.createInstance<Expression_listContext>(_ctx, getState());
  enterRule(_localctx, 150, modelicaParser::RuleExpression_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1036);
    expression();
    setState(1041);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__25) {
      setState(1037);
      match(modelicaParser::T__25);
      setState(1038);
      expression();
      setState(1043);
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

//----------------- Array_subscriptsContext ------------------------------------------------------------------

modelicaParser::Array_subscriptsContext::Array_subscriptsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::SubscriptContext *> modelicaParser::Array_subscriptsContext::subscript() {
  return getRuleContexts<modelicaParser::SubscriptContext>();
}

modelicaParser::SubscriptContext* modelicaParser::Array_subscriptsContext::subscript(size_t i) {
  return getRuleContext<modelicaParser::SubscriptContext>(i);
}


size_t modelicaParser::Array_subscriptsContext::getRuleIndex() const {
  return modelicaParser::RuleArray_subscripts;
}

void modelicaParser::Array_subscriptsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_subscripts(this);
}

void modelicaParser::Array_subscriptsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_subscripts(this);
}


antlrcpp::Any modelicaParser::Array_subscriptsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitArray_subscripts(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Array_subscriptsContext* modelicaParser::array_subscripts() {
  Array_subscriptsContext *_localctx = _tracker.createInstance<Array_subscriptsContext>(_ctx, getState());
  enterRule(_localctx, 152, modelicaParser::RuleArray_subscripts);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1044);
    match(modelicaParser::T__83);
    setState(1045);
    subscript();
    setState(1050);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__25) {
      setState(1046);
      match(modelicaParser::T__25);
      setState(1047);
      subscript();
      setState(1052);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1053);
    match(modelicaParser::T__84);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubscriptContext ------------------------------------------------------------------

modelicaParser::SubscriptContext::SubscriptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::ExpressionContext* modelicaParser::SubscriptContext::expression() {
  return getRuleContext<modelicaParser::ExpressionContext>(0);
}


size_t modelicaParser::SubscriptContext::getRuleIndex() const {
  return modelicaParser::RuleSubscript;
}

void modelicaParser::SubscriptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscript(this);
}

void modelicaParser::SubscriptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscript(this);
}


antlrcpp::Any modelicaParser::SubscriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitSubscript(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::SubscriptContext* modelicaParser::subscript() {
  SubscriptContext *_localctx = _tracker.createInstance<SubscriptContext>(_ctx, getState());
  enterRule(_localctx, 154, modelicaParser::RuleSubscript);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1057);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::T__22: {
        enterOuterAlt(_localctx, 1);
        setState(1055);
        match(modelicaParser::T__22);
        break;
      }

      case modelicaParser::T__17:
      case modelicaParser::T__21:
      case modelicaParser::T__24:
      case modelicaParser::T__45:
      case modelicaParser::T__48:
      case modelicaParser::T__65:
      case modelicaParser::T__72:
      case modelicaParser::T__73:
      case modelicaParser::T__74:
      case modelicaParser::T__75:
      case modelicaParser::T__81:
      case modelicaParser::T__82:
      case modelicaParser::T__83:
      case modelicaParser::T__85:
      case modelicaParser::T__86:
      case modelicaParser::IDENT:
      case modelicaParser::STRING:
      case modelicaParser::UNSIGNED_NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(1056);
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

//----------------- CommentContext ------------------------------------------------------------------

modelicaParser::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::String_commentContext* modelicaParser::CommentContext::string_comment() {
  return getRuleContext<modelicaParser::String_commentContext>(0);
}

modelicaParser::AnnotationContext* modelicaParser::CommentContext::annotation() {
  return getRuleContext<modelicaParser::AnnotationContext>(0);
}


size_t modelicaParser::CommentContext::getRuleIndex() const {
  return modelicaParser::RuleComment;
}

void modelicaParser::CommentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComment(this);
}

void modelicaParser::CommentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComment(this);
}


antlrcpp::Any modelicaParser::CommentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitComment(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::CommentContext* modelicaParser::comment() {
  CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
  enterRule(_localctx, 156, modelicaParser::RuleComment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1059);
    string_comment();
    setState(1061);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == modelicaParser::T__87) {
      setState(1060);
      annotation();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- String_commentContext ------------------------------------------------------------------

modelicaParser::String_commentContext::String_commentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> modelicaParser::String_commentContext::STRING() {
  return getTokens(modelicaParser::STRING);
}

tree::TerminalNode* modelicaParser::String_commentContext::STRING(size_t i) {
  return getToken(modelicaParser::STRING, i);
}


size_t modelicaParser::String_commentContext::getRuleIndex() const {
  return modelicaParser::RuleString_comment;
}

void modelicaParser::String_commentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString_comment(this);
}

void modelicaParser::String_commentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString_comment(this);
}


antlrcpp::Any modelicaParser::String_commentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitString_comment(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::String_commentContext* modelicaParser::string_comment() {
  String_commentContext *_localctx = _tracker.createInstance<String_commentContext>(_ctx, getState());
  enterRule(_localctx, 158, modelicaParser::RuleString_comment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1063);
    match(modelicaParser::STRING);
    setState(1068);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__72) {
      setState(1064);
      match(modelicaParser::T__72);
      setState(1065);
      match(modelicaParser::STRING);
      setState(1070);
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

//----------------- Model_annotationContext ------------------------------------------------------------------

modelicaParser::Model_annotationContext::Model_annotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::AnnotationContext* modelicaParser::Model_annotationContext::annotation() {
  return getRuleContext<modelicaParser::AnnotationContext>(0);
}


size_t modelicaParser::Model_annotationContext::getRuleIndex() const {
  return modelicaParser::RuleModel_annotation;
}

void modelicaParser::Model_annotationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModel_annotation(this);
}

void modelicaParser::Model_annotationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModel_annotation(this);
}


antlrcpp::Any modelicaParser::Model_annotationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitModel_annotation(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::Model_annotationContext* modelicaParser::model_annotation() {
  Model_annotationContext *_localctx = _tracker.createInstance<Model_annotationContext>(_ctx, getState());
  enterRule(_localctx, 160, modelicaParser::RuleModel_annotation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1071);
    annotation();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationContext ------------------------------------------------------------------

modelicaParser::AnnotationContext::AnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

modelicaParser::Class_modificationContext* modelicaParser::AnnotationContext::class_modification() {
  return getRuleContext<modelicaParser::Class_modificationContext>(0);
}


size_t modelicaParser::AnnotationContext::getRuleIndex() const {
  return modelicaParser::RuleAnnotation;
}

void modelicaParser::AnnotationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotation(this);
}

void modelicaParser::AnnotationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotation(this);
}


antlrcpp::Any modelicaParser::AnnotationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<modelicaVisitor*>(visitor))
    return parserVisitor->visitAnnotation(this);
  else
    return visitor->visitChildren(this);
}

modelicaParser::AnnotationContext* modelicaParser::annotation() {
  AnnotationContext *_localctx = _tracker.createInstance<AnnotationContext>(_ctx, getState());
  enterRule(_localctx, 162, modelicaParser::RuleAnnotation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1073);
    match(modelicaParser::T__87);
    setState(1074);
    class_modification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> modelicaParser::_decisionToDFA;
atn::PredictionContextCache modelicaParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN modelicaParser::_atn;
std::vector<uint16_t> modelicaParser::_serializedATN;

std::vector<std::string> modelicaParser::_ruleNames = {
  "stored_definition", "within_statement", "class_definition", "class_specifier", 
  "class_prefixes", "long_class_specifier", "short_class_specifier", "der_class_specifier", 
  "base_prefix", "enum_list", "enumeration_literal", "composition", "language_specification", 
  "external_function_call", "element_list", "element", "import_clause", 
  "import_list", "extends_clause", "constraining_clause", "component_clause", 
  "type_prefix_connector", "type_prefix_variability", "type_prefix_io", 
  "type_specifier", "component_list", "component_declaration", "condition_attribute", 
  "declaration", "modification", "class_modification", "argument_list", 
  "argument", "element_modification_or_replaceable", "element_modification", 
  "element_redeclaration", "element_replaceable", "component_clause1", "component_declaration1", 
  "short_class_definition", "equation_section", "algorithm_section", "equation", 
  "statement", "if_equation", "if_statement", "for_equation", "for_statement", 
  "for_indices", "for_index", "while_statement", "when_equation", "when_statement", 
  "connect_clause", "expression", "simple_expression", "logical_expression", 
  "logical_term", "logical_factor", "relation", "rel_op", "arithmetic_expression", 
  "add_op", "term", "mul_op", "factor", "primary", "name", "component_reference", 
  "function_call_args", "function_arguments", "named_arguments", "named_argument", 
  "function_argument", "output_expression_list", "expression_list", "array_subscripts", 
  "subscript", "comment", "string_comment", "model_annotation", "annotation"
};

std::vector<std::string> modelicaParser::_literalNames = {
  "", "'final'", "';'", "'within'", "'encapsulated'", "'partial'", "'class'", 
  "'model'", "'operator'", "'record'", "'block'", "'expandable'", "'connector'", 
  "'type'", "'package'", "'pure'", "'impure'", "'function'", "'end'", "'extends'", 
  "'='", "'enumeration'", "'('", "':'", "')'", "'der'", "','", "'public'", 
  "'protected'", "'external'", "'redeclare'", "'inner'", "'outer'", "'replaceable'", 
  "'import'", "'.*'", "'.{'", "'}'", "'constrainedby'", "'flow'", "'stream'", 
  "'discrete'", "'parameter'", "'constant'", "'input'", "'output'", "'if'", 
  "':='", "'each'", "'initial'", "'equation'", "'algorithm'", "'break'", 
  "'return'", "'then'", "'elseif'", "'else'", "'for'", "'loop'", "'in'", 
  "'while'", "'when'", "'elsewhen'", "'connect'", "'or'", "'and'", "'not'", 
  "'<'", "'<='", "'>'", "'>='", "'=='", "'<>'", "'+'", "'-'", "'.+'", "'.-'", 
  "'*'", "'/'", "'./'", "'^'", "'.^'", "'false'", "'true'", "'['", "']'", 
  "'{'", "'.'", "'annotation'"
};

std::vector<std::string> modelicaParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "IDENT", 
  "STRING", "UNSIGNED_NUMBER", "WS", "COMMENT", "LINE_COMMENT"
};

dfa::Vocabulary modelicaParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> modelicaParser::_tokenNames;

modelicaParser::Initializer::Initializer() {
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
    0x3, 0x60, 0x437, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x3, 0x2, 0x7, 0x2, 0xa8, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0xab, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0xae, 0xa, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0xb3, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xb6, 0xb, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0xba, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x4, 0x5, 0x4, 0xbf, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xc7, 0xa, 0x5, 0x3, 0x6, 0x5, 0x6, 
    0xca, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xcf, 0xa, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xd4, 0xa, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xda, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 
    0xdd, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xe1, 0xa, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0xe5, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xee, 0xa, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0xf1, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 
    0x7, 0xf7, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0xfe, 0xa, 0x8, 0x3, 0x8, 0x5, 0x8, 0x101, 0xa, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0x104, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x10b, 0xa, 0x8, 0x3, 0x8, 0x5, 0x8, 0x10e, 0xa, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x112, 0xa, 0x8, 0x5, 0x8, 0x114, 
    0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x11f, 0xa, 0x9, 0xc, 0x9, 0xe, 
    0x9, 0x122, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x126, 0xa, 0x9, 
    0x3, 0xa, 0x5, 0xa, 0x129, 0xa, 0xa, 0x3, 0xa, 0x5, 0xa, 0x12c, 0xa, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0x12f, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0x134, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x137, 0xb, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0x13b, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x144, 0xa, 0xd, 0xc, 
    0xd, 0xe, 0xd, 0x147, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x14b, 
    0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 0x14e, 0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 0x151, 
    0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 0x154, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x5, 0xd, 0x159, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x5, 0xf, 0x160, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0x165, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x7, 0x10, 0x16a, 
    0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x16d, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0x172, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 0x175, 
    0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 0x178, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x17b, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x17f, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x184, 0xa, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x189, 0xa, 0x11, 0x5, 0x11, 0x18b, 
    0xa, 0x11, 0x5, 0x11, 0x18d, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 
    0x19e, 0xa, 0x12, 0x3, 0x12, 0x5, 0x12, 0x1a1, 0xa, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x1a6, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 
    0x1a9, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x1ae, 
    0xa, 0x14, 0x3, 0x14, 0x5, 0x14, 0x1b1, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x5, 0x15, 0x1b6, 0xa, 0x15, 0x3, 0x16, 0x5, 0x16, 0x1b9, 
    0xa, 0x16, 0x3, 0x16, 0x5, 0x16, 0x1bc, 0xa, 0x16, 0x3, 0x16, 0x5, 0x16, 
    0x1bf, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x1c3, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x7, 0x1b, 0x1d2, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x1d5, 0xb, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1d9, 0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 
    0x1dc, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x5, 0x1e, 0x1e3, 0xa, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1e6, 0xa, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1eb, 0xa, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1f1, 0xa, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x5, 0x20, 0x1f5, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x1fc, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 
    0x1ff, 0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x203, 0xa, 0x22, 
    0x3, 0x23, 0x5, 0x23, 0x206, 0xa, 0x23, 0x3, 0x23, 0x5, 0x23, 0x209, 
    0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x20d, 0xa, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x211, 0xa, 0x24, 0x3, 0x24, 0x5, 0x24, 0x214, 
    0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x218, 0xa, 0x25, 0x3, 0x25, 
    0x5, 0x25, 0x21b, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x21f, 
    0xa, 0x25, 0x3, 0x25, 0x5, 0x25, 0x222, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x5, 0x26, 0x227, 0xa, 0x26, 0x3, 0x26, 0x5, 0x26, 0x22a, 
    0xa, 0x26, 0x3, 0x27, 0x5, 0x27, 0x22d, 0xa, 0x27, 0x3, 0x27, 0x5, 0x27, 
    0x230, 0xa, 0x27, 0x3, 0x27, 0x5, 0x27, 0x233, 0xa, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x3, 0x2a, 0x5, 0x2a, 0x23f, 0xa, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x7, 0x2a, 0x243, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x246, 
    0xb, 0x2a, 0x3, 0x2b, 0x5, 0x2b, 0x249, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x24f, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 
    0x252, 0xb, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 
    0x2c, 0x25f, 0xa, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x262, 0xa, 0x2c, 0x3, 
    0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
    0x26a, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x279, 0xa, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
    0x27c, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x7, 0x2e, 0x284, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x287, 
    0xb, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x7, 0x2e, 0x28f, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x292, 0xb, 
    0x2e, 0x7, 0x2e, 0x294, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x297, 0xb, 
    0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x29d, 
    0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x2a0, 0xb, 0x2e, 0x5, 0x2e, 0x2a2, 
    0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x2ad, 0xa, 0x2f, 
    0xc, 0x2f, 0xe, 0x2f, 0x2b0, 0xb, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x2b8, 0xa, 0x2f, 0xc, 0x2f, 
    0xe, 0x2f, 0x2bb, 0xb, 0x2f, 0x7, 0x2f, 0x2bd, 0xa, 0x2f, 0xc, 0x2f, 
    0xe, 0x2f, 0x2c0, 0xb, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x7, 0x2f, 0x2c6, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x2c9, 0xb, 0x2f, 
    0x5, 0x2f, 0x2cb, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 0x2d6, 
    0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x2d9, 0xb, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x7, 0x31, 0x2e4, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x2e7, 0xb, 
    0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x7, 0x32, 0x2ef, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 0x2f2, 0xb, 0x32, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x2f7, 0xa, 0x33, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 0x2ff, 
    0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x302, 0xb, 0x34, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 
    0x35, 0x7, 0x35, 0x30d, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x310, 0xb, 
    0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x7, 0x35, 0x318, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x31b, 0xb, 0x35, 
    0x7, 0x35, 0x31d, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x320, 0xb, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 
    0x36, 0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 0x32b, 0xa, 0x36, 0xc, 0x36, 
    0xe, 0x36, 0x32e, 0xb, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 0x336, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 
    0x339, 0xb, 0x36, 0x7, 0x36, 0x33b, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 
    0x33e, 0xb, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 
    0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x354, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 
    0x357, 0xb, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x35c, 
    0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 
    0x39, 0x363, 0xa, 0x39, 0x5, 0x39, 0x365, 0xa, 0x39, 0x3, 0x3a, 0x3, 
    0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x36a, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 
    0x36d, 0xb, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x372, 
    0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 0x375, 0xb, 0x3b, 0x3, 0x3c, 0x5, 0x3c, 
    0x378, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x5, 0x3d, 0x380, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 
    0x5, 0x3f, 0x385, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x7, 0x3f, 0x38b, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x38e, 0xb, 0x3f, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 
    0x41, 0x396, 0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x399, 0xb, 0x41, 0x3, 
    0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x3a0, 
    0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 
    0x44, 0x3, 0x44, 0x5, 0x44, 0x3a9, 0xa, 0x44, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 
    0x44, 0x3, 0x44, 0x7, 0x44, 0x3b5, 0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 
    0x3b8, 0xb, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x3c1, 0xa, 0x44, 0x3, 0x45, 0x5, 0x45, 
    0x3c4, 0xa, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 0x45, 0x3c9, 
    0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x3cc, 0xb, 0x45, 0x3, 0x46, 0x5, 0x46, 
    0x3cf, 0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x3d3, 0xa, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x3d8, 0xa, 0x46, 0x7, 0x46, 
    0x3da, 0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x3dd, 0xb, 0x46, 0x3, 0x47, 
    0x3, 0x47, 0x5, 0x47, 0x3e1, 0xa, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x3ea, 0xa, 0x48, 
    0x3, 0x48, 0x5, 0x48, 0x3ed, 0xa, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
    0x5, 0x49, 0x3f2, 0xa, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 
    0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x3fc, 0xa, 0x4b, 
    0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x401, 0xa, 0x4b, 0x3, 0x4c, 
    0x5, 0x4c, 0x404, 0xa, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 0x408, 
    0xa, 0x4c, 0x7, 0x4c, 0x40a, 0xa, 0x4c, 0xc, 0x4c, 0xe, 0x4c, 0x40d, 
    0xb, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x7, 0x4d, 0x412, 0xa, 0x4d, 
    0xc, 0x4d, 0xe, 0x4d, 0x415, 0xb, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x7, 0x4e, 0x41b, 0xa, 0x4e, 0xc, 0x4e, 0xe, 0x4e, 0x41e, 
    0xb, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x424, 
    0xa, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x428, 0xa, 0x50, 0x3, 0x51, 
    0x3, 0x51, 0x3, 0x51, 0x7, 0x51, 0x42d, 0xa, 0x51, 0xc, 0x51, 0xe, 0x51, 
    0x430, 0xb, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x2, 0x2, 0x54, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
    0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
    0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 
    0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 
    0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 
    0xa2, 0xa4, 0x2, 0xa, 0x3, 0x2, 0x11, 0x12, 0x3, 0x2, 0x29, 0x2a, 0x3, 
    0x2, 0x2b, 0x2d, 0x3, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x45, 0x4a, 0x3, 0x2, 
    0x4b, 0x4e, 0x4, 0x2, 0x25, 0x25, 0x4f, 0x51, 0x3, 0x2, 0x52, 0x53, 
    0x2, 0x49a, 0x2, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x4, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0xbe, 0x3, 0x2, 0x2, 0x2, 0x8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0xc9, 0x3, 0x2, 0x2, 0x2, 0xc, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xe, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x115, 0x3, 0x2, 0x2, 0x2, 0x12, 0x128, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x130, 0x3, 0x2, 0x2, 0x2, 0x16, 0x138, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x15a, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x16b, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x22, 0x190, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x1a2, 0x3, 0x2, 0x2, 0x2, 0x26, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x28, 0x1b2, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x1c6, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1ca, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x34, 0x1ce, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x38, 0x1dd, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x1f2, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x42, 0x202, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x205, 0x3, 0x2, 0x2, 0x2, 0x46, 0x20e, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x215, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x223, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x237, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x52, 0x23e, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x248, 0x3, 0x2, 0x2, 0x2, 0x56, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x278, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x2a6, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x60, 0x2dd, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x64, 0x2f3, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x68, 0x306, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x324, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x342, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x70, 0x35d, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x366, 0x3, 0x2, 0x2, 0x2, 0x74, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x76, 0x377, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x381, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x384, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x38f, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x391, 0x3, 0x2, 0x2, 0x2, 0x82, 0x39a, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x39c, 0x3, 0x2, 0x2, 0x2, 0x86, 0x3c0, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x3de, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x90, 0x3ee, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0x94, 0x400, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x403, 0x3, 0x2, 0x2, 0x2, 0x98, 0x40e, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x416, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x423, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0x425, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x429, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0x431, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x433, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0xa8, 0x5, 0x4, 0x3, 0x2, 0xa7, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xab, 
    0x3, 0x2, 0x2, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 
    0x2, 0x2, 0x2, 0xaa, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0xac, 0xae, 0x7, 0x3, 0x2, 0x2, 0xad, 0xac, 0x3, 0x2, 0x2, 
    0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xaf, 0xb0, 0x5, 0x6, 0x4, 0x2, 0xb0, 0xb1, 0x7, 0x4, 0x2, 0x2, 0xb1, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb6, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0x3, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0xb9, 0x7, 0x5, 0x2, 0x2, 0xb8, 0xba, 0x5, 0x88, 0x45, 
    0x2, 0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 
    0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x4, 0x2, 0x2, 0xbc, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbf, 0x7, 0x6, 0x2, 0x2, 0xbe, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc1, 0x5, 0xa, 0x6, 0x2, 0xc1, 0xc2, 0x5, 0x8, 
    0x5, 0x2, 0xc2, 0x7, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc7, 0x5, 0xc, 0x7, 
    0x2, 0xc4, 0xc7, 0x5, 0xe, 0x8, 0x2, 0xc5, 0xc7, 0x5, 0x10, 0x9, 0x2, 
    0xc6, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0x9, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xca, 
    0x7, 0x7, 0x2, 0x2, 0xc9, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xe1, 0x7, 0x8, 
    0x2, 0x2, 0xcc, 0xe1, 0x7, 0x9, 0x2, 0x2, 0xcd, 0xcf, 0x7, 0xa, 0x2, 
    0x2, 0xce, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xe1, 0x7, 0xb, 0x2, 0x2, 0xd1, 
    0xe1, 0x7, 0xc, 0x2, 0x2, 0xd2, 0xd4, 0x7, 0xd, 0x2, 0x2, 0xd3, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xe1, 0x7, 0xe, 0x2, 0x2, 0xd6, 0xe1, 0x7, 0xf, 
    0x2, 0x2, 0xd7, 0xe1, 0x7, 0x10, 0x2, 0x2, 0xd8, 0xda, 0x9, 0x2, 0x2, 
    0x2, 0xd9, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 0x2, 0x2, 
    0xda, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdd, 0x7, 0xa, 0x2, 0x2, 0xdc, 
    0xdb, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0xe1, 0x7, 0x13, 0x2, 0x2, 0xdf, 0xe1, 0x7, 
    0xa, 0x2, 0x2, 0xe0, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xcc, 0x3, 0x2, 
    0x2, 0x2, 0xe0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xd1, 0x3, 0x2, 0x2, 
    0x2, 0xe0, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xd6, 0x3, 0x2, 0x2, 0x2, 
    0xe0, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xb, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe4, 
    0x7, 0x5b, 0x2, 0x2, 0xe3, 0xe5, 0x5, 0xa0, 0x51, 0x2, 0xe4, 0xe3, 0x3, 
    0x2, 0x2, 0x2, 0xe4, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xe7, 0x5, 0x18, 0xd, 0x2, 0xe7, 0xe8, 0x7, 0x14, 0x2, 
    0x2, 0xe8, 0xe9, 0x7, 0x5b, 0x2, 0x2, 0xe9, 0xf7, 0x3, 0x2, 0x2, 0x2, 
    0xea, 0xeb, 0x7, 0x15, 0x2, 0x2, 0xeb, 0xed, 0x7, 0x5b, 0x2, 0x2, 0xec, 
    0xee, 0x5, 0x3e, 0x20, 0x2, 0xed, 0xec, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 
    0x3, 0x2, 0x2, 0x2, 0xee, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf1, 0x5, 
    0xa0, 0x51, 0x2, 0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x18, 0xd, 
    0x2, 0xf3, 0xf4, 0x7, 0x14, 0x2, 0x2, 0xf4, 0xf5, 0x7, 0x5b, 0x2, 0x2, 
    0xf5, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xf6, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xd, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 
    0x7, 0x5b, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x16, 0x2, 0x2, 0xfa, 0xfb, 0x5, 
    0x12, 0xa, 0x2, 0xfb, 0xfd, 0x5, 0x88, 0x45, 0x2, 0xfc, 0xfe, 0x5, 0x9a, 
    0x4e, 0x2, 0xfd, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 0x2, 
    0x2, 0xfe, 0x100, 0x3, 0x2, 0x2, 0x2, 0xff, 0x101, 0x5, 0x3e, 0x20, 
    0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x3, 0x2, 0x2, 0x2, 
    0x101, 0x103, 0x3, 0x2, 0x2, 0x2, 0x102, 0x104, 0x5, 0x9e, 0x50, 0x2, 
    0x103, 0x102, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 
    0x104, 0x114, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x5b, 0x2, 0x2, 
    0x106, 0x107, 0x7, 0x16, 0x2, 0x2, 0x107, 0x108, 0x7, 0x17, 0x2, 0x2, 
    0x108, 0x10d, 0x7, 0x18, 0x2, 0x2, 0x109, 0x10b, 0x5, 0x14, 0xb, 0x2, 
    0x10a, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 
    0x10b, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10e, 0x7, 0x19, 0x2, 0x2, 
    0x10d, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10c, 0x3, 0x2, 0x2, 0x2, 
    0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x111, 0x7, 0x1a, 0x2, 0x2, 
    0x110, 0x112, 0x5, 0x9e, 0x50, 0x2, 0x111, 0x110, 0x3, 0x2, 0x2, 0x2, 
    0x111, 0x112, 0x3, 0x2, 0x2, 0x2, 0x112, 0x114, 0x3, 0x2, 0x2, 0x2, 
    0x113, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x113, 0x105, 0x3, 0x2, 0x2, 0x2, 0x114, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x7, 0x5b, 0x2, 0x2, 0x116, 0x117, 
    0x7, 0x16, 0x2, 0x2, 0x117, 0x118, 0x7, 0x1b, 0x2, 0x2, 0x118, 0x119, 
    0x7, 0x18, 0x2, 0x2, 0x119, 0x11a, 0x5, 0x88, 0x45, 0x2, 0x11a, 0x11b, 
    0x7, 0x1c, 0x2, 0x2, 0x11b, 0x120, 0x7, 0x5b, 0x2, 0x2, 0x11c, 0x11d, 
    0x7, 0x1c, 0x2, 0x2, 0x11d, 0x11f, 0x7, 0x5b, 0x2, 0x2, 0x11e, 0x11c, 
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x122, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11e, 
    0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 0x2, 0x2, 0x121, 0x123, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 0x123, 0x125, 
    0x7, 0x1a, 0x2, 0x2, 0x124, 0x126, 0x5, 0x9e, 0x50, 0x2, 0x125, 0x124, 
    0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 0x126, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x127, 0x129, 0x5, 0x2c, 0x17, 0x2, 0x128, 0x127, 0x3, 
    0x2, 0x2, 0x2, 0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12b, 0x3, 
    0x2, 0x2, 0x2, 0x12a, 0x12c, 0x5, 0x2e, 0x18, 0x2, 0x12b, 0x12a, 0x3, 
    0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12e, 0x3, 
    0x2, 0x2, 0x2, 0x12d, 0x12f, 0x5, 0x30, 0x19, 0x2, 0x12e, 0x12d, 0x3, 
    0x2, 0x2, 0x2, 0x12e, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x130, 0x135, 0x5, 0x16, 0xc, 0x2, 0x131, 0x132, 0x7, 0x1c, 
    0x2, 0x2, 0x132, 0x134, 0x5, 0x16, 0xc, 0x2, 0x133, 0x131, 0x3, 0x2, 
    0x2, 0x2, 0x134, 0x137, 0x3, 0x2, 0x2, 0x2, 0x135, 0x133, 0x3, 0x2, 
    0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13a, 0x7, 0x5b, 0x2, 
    0x2, 0x139, 0x13b, 0x5, 0x9e, 0x50, 0x2, 0x13a, 0x139, 0x3, 0x2, 0x2, 
    0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x145, 0x5, 0x1e, 0x10, 0x2, 0x13d, 0x13e, 0x7, 0x1d, 0x2, 0x2, 
    0x13e, 0x144, 0x5, 0x1e, 0x10, 0x2, 0x13f, 0x140, 0x7, 0x1e, 0x2, 0x2, 
    0x140, 0x144, 0x5, 0x1e, 0x10, 0x2, 0x141, 0x144, 0x5, 0x52, 0x2a, 0x2, 
    0x142, 0x144, 0x5, 0x54, 0x2b, 0x2, 0x143, 0x13d, 0x3, 0x2, 0x2, 0x2, 
    0x143, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 
    0x143, 0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x147, 0x3, 0x2, 0x2, 0x2, 
    0x145, 0x143, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x3, 0x2, 0x2, 0x2, 
    0x146, 0x153, 0x3, 0x2, 0x2, 0x2, 0x147, 0x145, 0x3, 0x2, 0x2, 0x2, 
    0x148, 0x14a, 0x7, 0x1f, 0x2, 0x2, 0x149, 0x14b, 0x5, 0x1a, 0xe, 0x2, 
    0x14a, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 
    0x14b, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14e, 0x5, 0x1c, 0xf, 0x2, 
    0x14d, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 0x2, 0x2, 
    0x14e, 0x150, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x151, 0x5, 0xa4, 0x53, 0x2, 
    0x150, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 0x3, 0x2, 0x2, 0x2, 
    0x151, 0x152, 0x3, 0x2, 0x2, 0x2, 0x152, 0x154, 0x7, 0x4, 0x2, 0x2, 
    0x153, 0x148, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 
    0x154, 0x158, 0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0x5, 0xa2, 0x52, 0x2, 
    0x156, 0x157, 0x7, 0x4, 0x2, 0x2, 0x157, 0x159, 0x3, 0x2, 0x2, 0x2, 
    0x158, 0x155, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x3, 0x2, 0x2, 0x2, 
    0x159, 0x19, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 0x7, 0x5c, 0x2, 0x2, 
    0x15b, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 0x5, 0x8a, 0x46, 0x2, 
    0x15d, 0x15e, 0x7, 0x16, 0x2, 0x2, 0x15e, 0x160, 0x3, 0x2, 0x2, 0x2, 
    0x15f, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x3, 0x2, 0x2, 0x2, 
    0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x7, 0x5b, 0x2, 0x2, 
    0x162, 0x164, 0x7, 0x18, 0x2, 0x2, 0x163, 0x165, 0x5, 0x98, 0x4d, 0x2, 
    0x164, 0x163, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 0x2, 0x2, 
    0x165, 0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x7, 0x1a, 0x2, 0x2, 
    0x167, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x168, 0x16a, 0x5, 0x20, 0x11, 0x2, 
    0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16d, 0x3, 0x2, 0x2, 0x2, 
    0x16b, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x3, 0x2, 0x2, 0x2, 
    0x16c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16e, 
    0x18d, 0x5, 0x22, 0x12, 0x2, 0x16f, 0x18d, 0x5, 0x26, 0x14, 0x2, 0x170, 
    0x172, 0x7, 0x20, 0x2, 0x2, 0x171, 0x170, 0x3, 0x2, 0x2, 0x2, 0x171, 
    0x172, 0x3, 0x2, 0x2, 0x2, 0x172, 0x174, 0x3, 0x2, 0x2, 0x2, 0x173, 
    0x175, 0x7, 0x3, 0x2, 0x2, 0x174, 0x173, 0x3, 0x2, 0x2, 0x2, 0x174, 
    0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x177, 0x3, 0x2, 0x2, 0x2, 0x176, 
    0x178, 0x7, 0x21, 0x2, 0x2, 0x177, 0x176, 0x3, 0x2, 0x2, 0x2, 0x177, 
    0x178, 0x3, 0x2, 0x2, 0x2, 0x178, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x179, 
    0x17b, 0x7, 0x22, 0x2, 0x2, 0x17a, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17a, 
    0x17b, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x17c, 
    0x17f, 0x5, 0x6, 0x4, 0x2, 0x17d, 0x17f, 0x5, 0x2a, 0x16, 0x2, 0x17e, 
    0x17c, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17f, 
    0x18b, 0x3, 0x2, 0x2, 0x2, 0x180, 0x183, 0x7, 0x23, 0x2, 0x2, 0x181, 
    0x184, 0x5, 0x6, 0x4, 0x2, 0x182, 0x184, 0x5, 0x2a, 0x16, 0x2, 0x183, 
    0x181, 0x3, 0x2, 0x2, 0x2, 0x183, 0x182, 0x3, 0x2, 0x2, 0x2, 0x184, 
    0x188, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x5, 0x28, 0x15, 0x2, 0x186, 
    0x187, 0x5, 0x9e, 0x50, 0x2, 0x187, 0x189, 0x3, 0x2, 0x2, 0x2, 0x188, 
    0x185, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 0x2, 0x189, 
    0x18b, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x18a, 
    0x180, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18c, 
    0x16e, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x18c, 
    0x171, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18e, 
    0x18f, 0x7, 0x4, 0x2, 0x2, 0x18f, 0x21, 0x3, 0x2, 0x2, 0x2, 0x190, 0x19d, 
    0x7, 0x24, 0x2, 0x2, 0x191, 0x192, 0x7, 0x5b, 0x2, 0x2, 0x192, 0x193, 
    0x7, 0x16, 0x2, 0x2, 0x193, 0x19e, 0x5, 0x88, 0x45, 0x2, 0x194, 0x195, 
    0x5, 0x88, 0x45, 0x2, 0x195, 0x196, 0x7, 0x25, 0x2, 0x2, 0x196, 0x19e, 
    0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x5, 0x88, 0x45, 0x2, 0x198, 0x199, 
    0x7, 0x26, 0x2, 0x2, 0x199, 0x19a, 0x5, 0x24, 0x13, 0x2, 0x19a, 0x19b, 
    0x7, 0x27, 0x2, 0x2, 0x19b, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19e, 
    0x5, 0x88, 0x45, 0x2, 0x19d, 0x191, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x194, 
    0x3, 0x2, 0x2, 0x2, 0x19d, 0x197, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19c, 
    0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a1, 
    0x5, 0x9e, 0x50, 0x2, 0x1a0, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 
    0x3, 0x2, 0x2, 0x2, 0x1a1, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a7, 0x7, 
    0x5b, 0x2, 0x2, 0x1a3, 0x1a4, 0x7, 0x1c, 0x2, 0x2, 0x1a4, 0x1a6, 0x7, 
    0x5b, 0x2, 0x2, 0x1a5, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a9, 0x3, 
    0x2, 0x2, 0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 
    0x2, 0x2, 0x2, 0x1a8, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 0x2, 
    0x2, 0x2, 0x1aa, 0x1ab, 0x7, 0x15, 0x2, 0x2, 0x1ab, 0x1ad, 0x5, 0x88, 
    0x45, 0x2, 0x1ac, 0x1ae, 0x5, 0x3e, 0x20, 0x2, 0x1ad, 0x1ac, 0x3, 0x2, 
    0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b0, 0x3, 0x2, 
    0x2, 0x2, 0x1af, 0x1b1, 0x5, 0xa4, 0x53, 0x2, 0x1b0, 0x1af, 0x3, 0x2, 
    0x2, 0x2, 0x1b0, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x1b2, 0x1b3, 0x7, 0x28, 0x2, 0x2, 0x1b3, 0x1b5, 0x5, 0x88, 0x45, 
    0x2, 0x1b4, 0x1b6, 0x5, 0x3e, 0x20, 0x2, 0x1b5, 0x1b4, 0x3, 0x2, 0x2, 
    0x2, 0x1b5, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x1b7, 0x1b9, 0x5, 0x2c, 0x17, 0x2, 0x1b8, 0x1b7, 0x3, 0x2, 0x2, 0x2, 
    0x1b8, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1bb, 0x3, 0x2, 0x2, 0x2, 
    0x1ba, 0x1bc, 0x5, 0x2e, 0x18, 0x2, 0x1bb, 0x1ba, 0x3, 0x2, 0x2, 0x2, 
    0x1bb, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1be, 0x3, 0x2, 0x2, 0x2, 
    0x1bd, 0x1bf, 0x5, 0x30, 0x19, 0x2, 0x1be, 0x1bd, 0x3, 0x2, 0x2, 0x2, 
    0x1be, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x3, 0x2, 0x2, 0x2, 
    0x1c0, 0x1c2, 0x5, 0x32, 0x1a, 0x2, 0x1c1, 0x1c3, 0x5, 0x9a, 0x4e, 0x2, 
    0x1c2, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x3, 0x2, 0x2, 0x2, 
    0x1c3, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x5, 0x34, 0x1b, 0x2, 
    0x1c5, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x9, 0x3, 0x2, 0x2, 0x1c7, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x9, 0x4, 0x2, 0x2, 0x1c9, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cb, 0x9, 0x5, 0x2, 0x2, 0x1cb, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x5, 0x88, 0x45, 0x2, 0x1cd, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x1ce, 0x1d3, 0x5, 0x36, 0x1c, 0x2, 0x1cf, 0x1d0, 0x7, 
    0x1c, 0x2, 0x2, 0x1d0, 0x1d2, 0x5, 0x36, 0x1c, 0x2, 0x1d1, 0x1cf, 0x3, 
    0x2, 0x2, 0x2, 0x1d2, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d1, 0x3, 
    0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x1d5, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d8, 0x5, 0x3a, 
    0x1e, 0x2, 0x1d7, 0x1d9, 0x5, 0x38, 0x1d, 0x2, 0x1d8, 0x1d7, 0x3, 0x2, 
    0x2, 0x2, 0x1d8, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1db, 0x3, 0x2, 
    0x2, 0x2, 0x1da, 0x1dc, 0x5, 0x9e, 0x50, 0x2, 0x1db, 0x1da, 0x3, 0x2, 
    0x2, 0x2, 0x1db, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x1dd, 0x1de, 0x7, 0x30, 0x2, 0x2, 0x1de, 0x1df, 0x5, 0x6e, 0x38, 
    0x2, 0x1df, 0x39, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e2, 0x7, 0x5b, 0x2, 
    0x2, 0x1e1, 0x1e3, 0x5, 0x9a, 0x4e, 0x2, 0x1e2, 0x1e1, 0x3, 0x2, 0x2, 
    0x2, 0x1e2, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e5, 0x3, 0x2, 0x2, 
    0x2, 0x1e4, 0x1e6, 0x5, 0x3c, 0x1f, 0x2, 0x1e5, 0x1e4, 0x3, 0x2, 0x2, 
    0x2, 0x1e5, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x1e7, 0x1ea, 0x5, 0x3e, 0x20, 0x2, 0x1e8, 0x1e9, 0x7, 0x16, 0x2, 0x2, 
    0x1e9, 0x1eb, 0x5, 0x6e, 0x38, 0x2, 0x1ea, 0x1e8, 0x3, 0x2, 0x2, 0x2, 
    0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1f1, 0x3, 0x2, 0x2, 0x2, 
    0x1ec, 0x1ed, 0x7, 0x16, 0x2, 0x2, 0x1ed, 0x1f1, 0x5, 0x6e, 0x38, 0x2, 
    0x1ee, 0x1ef, 0x7, 0x31, 0x2, 0x2, 0x1ef, 0x1f1, 0x5, 0x6e, 0x38, 0x2, 
    0x1f0, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ec, 0x3, 0x2, 0x2, 0x2, 
    0x1f0, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1f2, 
    0x1f4, 0x7, 0x18, 0x2, 0x2, 0x1f3, 0x1f5, 0x5, 0x40, 0x21, 0x2, 0x1f4, 
    0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 
    0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x7, 0x1a, 0x2, 0x2, 0x1f7, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1fd, 0x5, 0x42, 0x22, 0x2, 0x1f9, 
    0x1fa, 0x7, 0x1c, 0x2, 0x2, 0x1fa, 0x1fc, 0x5, 0x42, 0x22, 0x2, 0x1fb, 
    0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1fd, 
    0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1fe, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x200, 0x203, 
    0x5, 0x44, 0x23, 0x2, 0x201, 0x203, 0x5, 0x48, 0x25, 0x2, 0x202, 0x200, 
    0x3, 0x2, 0x2, 0x2, 0x202, 0x201, 0x3, 0x2, 0x2, 0x2, 0x203, 0x43, 0x3, 
    0x2, 0x2, 0x2, 0x204, 0x206, 0x7, 0x32, 0x2, 0x2, 0x205, 0x204, 0x3, 
    0x2, 0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 0x208, 0x3, 
    0x2, 0x2, 0x2, 0x207, 0x209, 0x7, 0x3, 0x2, 0x2, 0x208, 0x207, 0x3, 
    0x2, 0x2, 0x2, 0x208, 0x209, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20c, 0x3, 
    0x2, 0x2, 0x2, 0x20a, 0x20d, 0x5, 0x46, 0x24, 0x2, 0x20b, 0x20d, 0x5, 
    0x4a, 0x26, 0x2, 0x20c, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20b, 0x3, 
    0x2, 0x2, 0x2, 0x20d, 0x45, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x210, 0x5, 0x88, 
    0x45, 0x2, 0x20f, 0x211, 0x5, 0x3c, 0x1f, 0x2, 0x210, 0x20f, 0x3, 0x2, 
    0x2, 0x2, 0x210, 0x211, 0x3, 0x2, 0x2, 0x2, 0x211, 0x213, 0x3, 0x2, 
    0x2, 0x2, 0x212, 0x214, 0x5, 0xa0, 0x51, 0x2, 0x213, 0x212, 0x3, 0x2, 
    0x2, 0x2, 0x213, 0x214, 0x3, 0x2, 0x2, 0x2, 0x214, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x215, 0x217, 0x7, 0x20, 0x2, 0x2, 0x216, 0x218, 0x7, 0x32, 0x2, 
    0x2, 0x217, 0x216, 0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 0x3, 0x2, 0x2, 
    0x2, 0x218, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21b, 0x7, 0x3, 0x2, 
    0x2, 0x21a, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21b, 0x3, 0x2, 0x2, 
    0x2, 0x21b, 0x221, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21f, 0x5, 0x50, 0x29, 
    0x2, 0x21d, 0x21f, 0x5, 0x4c, 0x27, 0x2, 0x21e, 0x21c, 0x3, 0x2, 0x2, 
    0x2, 0x21e, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x222, 0x3, 0x2, 0x2, 
    0x2, 0x220, 0x222, 0x5, 0x4a, 0x26, 0x2, 0x221, 0x21e, 0x3, 0x2, 0x2, 
    0x2, 0x221, 0x220, 0x3, 0x2, 0x2, 0x2, 0x222, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x226, 0x7, 0x23, 0x2, 0x2, 0x224, 0x227, 0x5, 0x50, 0x29, 0x2, 
    0x225, 0x227, 0x5, 0x4c, 0x27, 0x2, 0x226, 0x224, 0x3, 0x2, 0x2, 0x2, 
    0x226, 0x225, 0x3, 0x2, 0x2, 0x2, 0x227, 0x229, 0x3, 0x2, 0x2, 0x2, 
    0x228, 0x22a, 0x5, 0x28, 0x15, 0x2, 0x229, 0x228, 0x3, 0x2, 0x2, 0x2, 
    0x229, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x22b, 
    0x22d, 0x5, 0x2c, 0x17, 0x2, 0x22c, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22c, 
    0x22d, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x22e, 
    0x230, 0x5, 0x2e, 0x18, 0x2, 0x22f, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x22f, 
    0x230, 0x3, 0x2, 0x2, 0x2, 0x230, 0x232, 0x3, 0x2, 0x2, 0x2, 0x231, 
    0x233, 0x5, 0x30, 0x19, 0x2, 0x232, 0x231, 0x3, 0x2, 0x2, 0x2, 0x232, 
    0x233, 0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x3, 0x2, 0x2, 0x2, 0x234, 
    0x235, 0x5, 0x32, 0x1a, 0x2, 0x235, 0x236, 0x5, 0x4e, 0x28, 0x2, 0x236, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x5, 0x3a, 0x1e, 0x2, 0x238, 
    0x239, 0x5, 0x9e, 0x50, 0x2, 0x239, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x23a, 
    0x23b, 0x5, 0xa, 0x6, 0x2, 0x23b, 0x23c, 0x5, 0xe, 0x8, 0x2, 0x23c, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x23f, 0x7, 0x33, 0x2, 0x2, 0x23e, 
    0x23d, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x23f, 
    0x240, 0x3, 0x2, 0x2, 0x2, 0x240, 0x244, 0x7, 0x34, 0x2, 0x2, 0x241, 
    0x243, 0x5, 0x56, 0x2c, 0x2, 0x242, 0x241, 0x3, 0x2, 0x2, 0x2, 0x243, 
    0x246, 0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 0x244, 
    0x245, 0x3, 0x2, 0x2, 0x2, 0x245, 0x53, 0x3, 0x2, 0x2, 0x2, 0x246, 0x244, 
    0x3, 0x2, 0x2, 0x2, 0x247, 0x249, 0x7, 0x33, 0x2, 0x2, 0x248, 0x247, 
    0x3, 0x2, 0x2, 0x2, 0x248, 0x249, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24a, 
    0x3, 0x2, 0x2, 0x2, 0x24a, 0x250, 0x7, 0x35, 0x2, 0x2, 0x24b, 0x24c, 
    0x5, 0x58, 0x2d, 0x2, 0x24c, 0x24d, 0x7, 0x4, 0x2, 0x2, 0x24d, 0x24f, 
    0x3, 0x2, 0x2, 0x2, 0x24e, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x252, 
    0x3, 0x2, 0x2, 0x2, 0x250, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x250, 0x251, 
    0x3, 0x2, 0x2, 0x2, 0x251, 0x55, 0x3, 0x2, 0x2, 0x2, 0x252, 0x250, 0x3, 
    0x2, 0x2, 0x2, 0x253, 0x254, 0x5, 0x70, 0x39, 0x2, 0x254, 0x255, 0x7, 
    0x16, 0x2, 0x2, 0x255, 0x256, 0x5, 0x6e, 0x38, 0x2, 0x256, 0x25f, 0x3, 
    0x2, 0x2, 0x2, 0x257, 0x25f, 0x5, 0x5a, 0x2e, 0x2, 0x258, 0x25f, 0x5, 
    0x5e, 0x30, 0x2, 0x259, 0x25f, 0x5, 0x6c, 0x37, 0x2, 0x25a, 0x25f, 0x5, 
    0x68, 0x35, 0x2, 0x25b, 0x25c, 0x5, 0x88, 0x45, 0x2, 0x25c, 0x25d, 0x5, 
    0x8c, 0x47, 0x2, 0x25d, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x253, 0x3, 
    0x2, 0x2, 0x2, 0x25e, 0x257, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x258, 0x3, 
    0x2, 0x2, 0x2, 0x25e, 0x259, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25a, 0x3, 
    0x2, 0x2, 0x2, 0x25e, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x261, 0x3, 
    0x2, 0x2, 0x2, 0x260, 0x262, 0x5, 0x9e, 0x50, 0x2, 0x261, 0x260, 0x3, 
    0x2, 0x2, 0x2, 0x261, 0x262, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x3, 
    0x2, 0x2, 0x2, 0x263, 0x264, 0x7, 0x4, 0x2, 0x2, 0x264, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x265, 0x269, 0x5, 0x8a, 0x46, 0x2, 0x266, 0x267, 0x7, 0x31, 
    0x2, 0x2, 0x267, 0x26a, 0x5, 0x6e, 0x38, 0x2, 0x268, 0x26a, 0x5, 0x8c, 
    0x47, 0x2, 0x269, 0x266, 0x3, 0x2, 0x2, 0x2, 0x269, 0x268, 0x3, 0x2, 
    0x2, 0x2, 0x26a, 0x279, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 0x7, 0x18, 
    0x2, 0x2, 0x26c, 0x26d, 0x5, 0x96, 0x4c, 0x2, 0x26d, 0x26e, 0x7, 0x1a, 
    0x2, 0x2, 0x26e, 0x26f, 0x7, 0x31, 0x2, 0x2, 0x26f, 0x270, 0x5, 0x8a, 
    0x46, 0x2, 0x270, 0x271, 0x5, 0x8c, 0x47, 0x2, 0x271, 0x279, 0x3, 0x2, 
    0x2, 0x2, 0x272, 0x279, 0x7, 0x36, 0x2, 0x2, 0x273, 0x279, 0x7, 0x37, 
    0x2, 0x2, 0x274, 0x279, 0x5, 0x5c, 0x2f, 0x2, 0x275, 0x279, 0x5, 0x60, 
    0x31, 0x2, 0x276, 0x279, 0x5, 0x66, 0x34, 0x2, 0x277, 0x279, 0x5, 0x6a, 
    0x36, 0x2, 0x278, 0x265, 0x3, 0x2, 0x2, 0x2, 0x278, 0x26b, 0x3, 0x2, 
    0x2, 0x2, 0x278, 0x272, 0x3, 0x2, 0x2, 0x2, 0x278, 0x273, 0x3, 0x2, 
    0x2, 0x2, 0x278, 0x274, 0x3, 0x2, 0x2, 0x2, 0x278, 0x275, 0x3, 0x2, 
    0x2, 0x2, 0x278, 0x276, 0x3, 0x2, 0x2, 0x2, 0x278, 0x277, 0x3, 0x2, 
    0x2, 0x2, 0x279, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x27c, 0x5, 0x9e, 
    0x50, 0x2, 0x27b, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x27c, 0x3, 0x2, 
    0x2, 0x2, 0x27c, 0x59, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27e, 0x7, 0x30, 
    0x2, 0x2, 0x27e, 0x27f, 0x5, 0x6e, 0x38, 0x2, 0x27f, 0x285, 0x7, 0x38, 
    0x2, 0x2, 0x280, 0x281, 0x5, 0x56, 0x2c, 0x2, 0x281, 0x282, 0x7, 0x4, 
    0x2, 0x2, 0x282, 0x284, 0x3, 0x2, 0x2, 0x2, 0x283, 0x280, 0x3, 0x2, 
    0x2, 0x2, 0x284, 0x287, 0x3, 0x2, 0x2, 0x2, 0x285, 0x283, 0x3, 0x2, 
    0x2, 0x2, 0x285, 0x286, 0x3, 0x2, 0x2, 0x2, 0x286, 0x295, 0x3, 0x2, 
    0x2, 0x2, 0x287, 0x285, 0x3, 0x2, 0x2, 0x2, 0x288, 0x289, 0x7, 0x39, 
    0x2, 0x2, 0x289, 0x28a, 0x5, 0x6e, 0x38, 0x2, 0x28a, 0x290, 0x7, 0x38, 
    0x2, 0x2, 0x28b, 0x28c, 0x5, 0x56, 0x2c, 0x2, 0x28c, 0x28d, 0x7, 0x4, 
    0x2, 0x2, 0x28d, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28b, 0x3, 0x2, 
    0x2, 0x2, 0x28f, 0x292, 0x3, 0x2, 0x2, 0x2, 0x290, 0x28e, 0x3, 0x2, 
    0x2, 0x2, 0x290, 0x291, 0x3, 0x2, 0x2, 0x2, 0x291, 0x294, 0x3, 0x2, 
    0x2, 0x2, 0x292, 0x290, 0x3, 0x2, 0x2, 0x2, 0x293, 0x288, 0x3, 0x2, 
    0x2, 0x2, 0x294, 0x297, 0x3, 0x2, 0x2, 0x2, 0x295, 0x293, 0x3, 0x2, 
    0x2, 0x2, 0x295, 0x296, 0x3, 0x2, 0x2, 0x2, 0x296, 0x2a1, 0x3, 0x2, 
    0x2, 0x2, 0x297, 0x295, 0x3, 0x2, 0x2, 0x2, 0x298, 0x29e, 0x7, 0x3a, 
    0x2, 0x2, 0x299, 0x29a, 0x5, 0x56, 0x2c, 0x2, 0x29a, 0x29b, 0x7, 0x4, 
    0x2, 0x2, 0x29b, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x299, 0x3, 0x2, 
    0x2, 0x2, 0x29d, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29c, 0x3, 0x2, 
    0x2, 0x2, 0x29e, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a2, 0x3, 0x2, 
    0x2, 0x2, 0x2a0, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x298, 0x3, 0x2, 
    0x2, 0x2, 0x2a1, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a3, 0x3, 0x2, 
    0x2, 0x2, 0x2a3, 0x2a4, 0x7, 0x14, 0x2, 0x2, 0x2a4, 0x2a5, 0x7, 0x30, 
    0x2, 0x2, 0x2a5, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a7, 0x7, 0x30, 
    0x2, 0x2, 0x2a7, 0x2a8, 0x5, 0x6e, 0x38, 0x2, 0x2a8, 0x2ae, 0x7, 0x38, 
    0x2, 0x2, 0x2a9, 0x2aa, 0x5, 0x58, 0x2d, 0x2, 0x2aa, 0x2ab, 0x7, 0x4, 
    0x2, 0x2, 0x2ab, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2a9, 0x3, 0x2, 
    0x2, 0x2, 0x2ad, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2ac, 0x3, 0x2, 
    0x2, 0x2, 0x2ae, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2be, 0x3, 0x2, 
    0x2, 0x2, 0x2b0, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 0x7, 0x39, 
    0x2, 0x2, 0x2b2, 0x2b3, 0x5, 0x6e, 0x38, 0x2, 0x2b3, 0x2b9, 0x7, 0x38, 
    0x2, 0x2, 0x2b4, 0x2b5, 0x5, 0x58, 0x2d, 0x2, 0x2b5, 0x2b6, 0x7, 0x4, 
    0x2, 0x2, 0x2b6, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b4, 0x3, 0x2, 
    0x2, 0x2, 0x2b8, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2b7, 0x3, 0x2, 
    0x2, 0x2, 0x2b9, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bd, 0x3, 0x2, 
    0x2, 0x2, 0x2bb, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2b1, 0x3, 0x2, 
    0x2, 0x2, 0x2bd, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bc, 0x3, 0x2, 
    0x2, 0x2, 0x2be, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2ca, 0x3, 0x2, 
    0x2, 0x2, 0x2c0, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c7, 0x7, 0x3a, 
    0x2, 0x2, 0x2c2, 0x2c3, 0x5, 0x58, 0x2d, 0x2, 0x2c3, 0x2c4, 0x7, 0x4, 
    0x2, 0x2, 0x2c4, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c2, 0x3, 0x2, 
    0x2, 0x2, 0x2c6, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c5, 0x3, 0x2, 
    0x2, 0x2, 0x2c7, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2cb, 0x3, 0x2, 
    0x2, 0x2, 0x2c9, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2c1, 0x3, 0x2, 
    0x2, 0x2, 0x2ca, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2cc, 0x3, 0x2, 
    0x2, 0x2, 0x2cc, 0x2cd, 0x7, 0x14, 0x2, 0x2, 0x2cd, 0x2ce, 0x7, 0x30, 
    0x2, 0x2, 0x2ce, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d0, 0x7, 0x3b, 
    0x2, 0x2, 0x2d0, 0x2d1, 0x5, 0x62, 0x32, 0x2, 0x2d1, 0x2d7, 0x7, 0x3c, 
    0x2, 0x2, 0x2d2, 0x2d3, 0x5, 0x56, 0x2c, 0x2, 0x2d3, 0x2d4, 0x7, 0x4, 
    0x2, 0x2, 0x2d4, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d2, 0x3, 0x2, 
    0x2, 0x2, 0x2d6, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d5, 0x3, 0x2, 
    0x2, 0x2, 0x2d7, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2da, 0x3, 0x2, 
    0x2, 0x2, 0x2d9, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 0x7, 0x14, 
    0x2, 0x2, 0x2db, 0x2dc, 0x7, 0x3b, 0x2, 0x2, 0x2dc, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x2dd, 0x2de, 0x7, 0x3b, 0x2, 0x2, 0x2de, 0x2df, 0x5, 0x62, 
    0x32, 0x2, 0x2df, 0x2e5, 0x7, 0x3c, 0x2, 0x2, 0x2e0, 0x2e1, 0x5, 0x58, 
    0x2d, 0x2, 0x2e1, 0x2e2, 0x7, 0x4, 0x2, 0x2, 0x2e2, 0x2e4, 0x3, 0x2, 
    0x2, 0x2, 0x2e3, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e7, 0x3, 0x2, 
    0x2, 0x2, 0x2e5, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e6, 0x3, 0x2, 
    0x2, 0x2, 0x2e6, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e5, 0x3, 0x2, 
    0x2, 0x2, 0x2e8, 0x2e9, 0x7, 0x14, 0x2, 0x2, 0x2e9, 0x2ea, 0x7, 0x3b, 
    0x2, 0x2, 0x2ea, 0x61, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2f0, 0x5, 0x64, 
    0x33, 0x2, 0x2ec, 0x2ed, 0x7, 0x1c, 0x2, 0x2, 0x2ed, 0x2ef, 0x5, 0x64, 
    0x33, 0x2, 0x2ee, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f2, 0x3, 0x2, 
    0x2, 0x2, 0x2f0, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f1, 0x3, 0x2, 
    0x2, 0x2, 0x2f1, 0x63, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f0, 0x3, 0x2, 0x2, 
    0x2, 0x2f3, 0x2f6, 0x7, 0x5b, 0x2, 0x2, 0x2f4, 0x2f5, 0x7, 0x3d, 0x2, 
    0x2, 0x2f5, 0x2f7, 0x5, 0x6e, 0x38, 0x2, 0x2f6, 0x2f4, 0x3, 0x2, 0x2, 
    0x2, 0x2f6, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x2f8, 0x2f9, 0x7, 0x3e, 0x2, 0x2, 0x2f9, 0x2fa, 0x5, 0x6e, 0x38, 0x2, 
    0x2fa, 0x300, 0x7, 0x3c, 0x2, 0x2, 0x2fb, 0x2fc, 0x5, 0x58, 0x2d, 0x2, 
    0x2fc, 0x2fd, 0x7, 0x4, 0x2, 0x2, 0x2fd, 0x2ff, 0x3, 0x2, 0x2, 0x2, 
    0x2fe, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x302, 0x3, 0x2, 0x2, 0x2, 
    0x300, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x300, 0x301, 0x3, 0x2, 0x2, 0x2, 
    0x301, 0x303, 0x3, 0x2, 0x2, 0x2, 0x302, 0x300, 0x3, 0x2, 0x2, 0x2, 
    0x303, 0x304, 0x7, 0x14, 0x2, 0x2, 0x304, 0x305, 0x7, 0x3e, 0x2, 0x2, 
    0x305, 0x67, 0x3, 0x2, 0x2, 0x2, 0x306, 0x307, 0x7, 0x3f, 0x2, 0x2, 
    0x307, 0x308, 0x5, 0x6e, 0x38, 0x2, 0x308, 0x30e, 0x7, 0x38, 0x2, 0x2, 
    0x309, 0x30a, 0x5, 0x56, 0x2c, 0x2, 0x30a, 0x30b, 0x7, 0x4, 0x2, 0x2, 
    0x30b, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x309, 0x3, 0x2, 0x2, 0x2, 
    0x30d, 0x310, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x30c, 0x3, 0x2, 0x2, 0x2, 
    0x30e, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x30f, 0x31e, 0x3, 0x2, 0x2, 0x2, 
    0x310, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x311, 0x312, 0x7, 0x40, 0x2, 0x2, 
    0x312, 0x313, 0x5, 0x6e, 0x38, 0x2, 0x313, 0x319, 0x7, 0x38, 0x2, 0x2, 
    0x314, 0x315, 0x5, 0x56, 0x2c, 0x2, 0x315, 0x316, 0x7, 0x4, 0x2, 0x2, 
    0x316, 0x318, 0x3, 0x2, 0x2, 0x2, 0x317, 0x314, 0x3, 0x2, 0x2, 0x2, 
    0x318, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x319, 0x317, 0x3, 0x2, 0x2, 0x2, 
    0x319, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x31d, 0x3, 0x2, 0x2, 0x2, 
    0x31b, 0x319, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x311, 0x3, 0x2, 0x2, 0x2, 
    0x31d, 0x320, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x31c, 0x3, 0x2, 0x2, 0x2, 
    0x31e, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x321, 0x3, 0x2, 0x2, 0x2, 
    0x320, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x321, 0x322, 0x7, 0x14, 0x2, 0x2, 
    0x322, 0x323, 0x7, 0x3f, 0x2, 0x2, 0x323, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x324, 0x325, 0x7, 0x3f, 0x2, 0x2, 0x325, 0x326, 0x5, 0x6e, 0x38, 0x2, 
    0x326, 0x32c, 0x7, 0x38, 0x2, 0x2, 0x327, 0x328, 0x5, 0x58, 0x2d, 0x2, 
    0x328, 0x329, 0x7, 0x4, 0x2, 0x2, 0x329, 0x32b, 0x3, 0x2, 0x2, 0x2, 
    0x32a, 0x327, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x32e, 0x3, 0x2, 0x2, 0x2, 
    0x32c, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x32d, 0x3, 0x2, 0x2, 0x2, 
    0x32d, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x32c, 0x3, 0x2, 0x2, 0x2, 
    0x32f, 0x330, 0x7, 0x40, 0x2, 0x2, 0x330, 0x331, 0x5, 0x6e, 0x38, 0x2, 
    0x331, 0x337, 0x7, 0x38, 0x2, 0x2, 0x332, 0x333, 0x5, 0x58, 0x2d, 0x2, 
    0x333, 0x334, 0x7, 0x4, 0x2, 0x2, 0x334, 0x336, 0x3, 0x2, 0x2, 0x2, 
    0x335, 0x332, 0x3, 0x2, 0x2, 0x2, 0x336, 0x339, 0x3, 0x2, 0x2, 0x2, 
    0x337, 0x335, 0x3, 0x2, 0x2, 0x2, 0x337, 0x338, 0x3, 0x2, 0x2, 0x2, 
    0x338, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x339, 0x337, 0x3, 0x2, 0x2, 0x2, 
    0x33a, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x33e, 0x3, 0x2, 0x2, 0x2, 
    0x33c, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33d, 0x3, 0x2, 0x2, 0x2, 
    0x33d, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33c, 0x3, 0x2, 0x2, 0x2, 
    0x33f, 0x340, 0x7, 0x14, 0x2, 0x2, 0x340, 0x341, 0x7, 0x3f, 0x2, 0x2, 
    0x341, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x342, 0x343, 0x7, 0x41, 0x2, 0x2, 
    0x343, 0x344, 0x7, 0x18, 0x2, 0x2, 0x344, 0x345, 0x5, 0x8a, 0x46, 0x2, 
    0x345, 0x346, 0x7, 0x1c, 0x2, 0x2, 0x346, 0x347, 0x5, 0x8a, 0x46, 0x2, 
    0x347, 0x348, 0x7, 0x1a, 0x2, 0x2, 0x348, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x349, 0x35c, 0x5, 0x70, 0x39, 0x2, 0x34a, 0x34b, 0x7, 0x30, 0x2, 0x2, 
    0x34b, 0x34c, 0x5, 0x6e, 0x38, 0x2, 0x34c, 0x34d, 0x7, 0x38, 0x2, 0x2, 
    0x34d, 0x355, 0x5, 0x6e, 0x38, 0x2, 0x34e, 0x34f, 0x7, 0x39, 0x2, 0x2, 
    0x34f, 0x350, 0x5, 0x6e, 0x38, 0x2, 0x350, 0x351, 0x7, 0x38, 0x2, 0x2, 
    0x351, 0x352, 0x5, 0x6e, 0x38, 0x2, 0x352, 0x354, 0x3, 0x2, 0x2, 0x2, 
    0x353, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x354, 0x357, 0x3, 0x2, 0x2, 0x2, 
    0x355, 0x353, 0x3, 0x2, 0x2, 0x2, 0x355, 0x356, 0x3, 0x2, 0x2, 0x2, 
    0x356, 0x358, 0x3, 0x2, 0x2, 0x2, 0x357, 0x355, 0x3, 0x2, 0x2, 0x2, 
    0x358, 0x359, 0x7, 0x3a, 0x2, 0x2, 0x359, 0x35a, 0x5, 0x6e, 0x38, 0x2, 
    0x35a, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x349, 0x3, 0x2, 0x2, 0x2, 
    0x35b, 0x34a, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x35d, 
    0x364, 0x5, 0x72, 0x3a, 0x2, 0x35e, 0x35f, 0x7, 0x19, 0x2, 0x2, 0x35f, 
    0x362, 0x5, 0x72, 0x3a, 0x2, 0x360, 0x361, 0x7, 0x19, 0x2, 0x2, 0x361, 
    0x363, 0x5, 0x72, 0x3a, 0x2, 0x362, 0x360, 0x3, 0x2, 0x2, 0x2, 0x362, 
    0x363, 0x3, 0x2, 0x2, 0x2, 0x363, 0x365, 0x3, 0x2, 0x2, 0x2, 0x364, 
    0x35e, 0x3, 0x2, 0x2, 0x2, 0x364, 0x365, 0x3, 0x2, 0x2, 0x2, 0x365, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x366, 0x36b, 0x5, 0x74, 0x3b, 0x2, 0x367, 
    0x368, 0x7, 0x42, 0x2, 0x2, 0x368, 0x36a, 0x5, 0x74, 0x3b, 0x2, 0x369, 
    0x367, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x36b, 
    0x369, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x36c, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x373, 
    0x5, 0x76, 0x3c, 0x2, 0x36f, 0x370, 0x7, 0x43, 0x2, 0x2, 0x370, 0x372, 
    0x5, 0x76, 0x3c, 0x2, 0x371, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x372, 0x375, 
    0x3, 0x2, 0x2, 0x2, 0x373, 0x371, 0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 
    0x3, 0x2, 0x2, 0x2, 0x374, 0x75, 0x3, 0x2, 0x2, 0x2, 0x375, 0x373, 0x3, 
    0x2, 0x2, 0x2, 0x376, 0x378, 0x7, 0x44, 0x2, 0x2, 0x377, 0x376, 0x3, 
    0x2, 0x2, 0x2, 0x377, 0x378, 0x3, 0x2, 0x2, 0x2, 0x378, 0x379, 0x3, 
    0x2, 0x2, 0x2, 0x379, 0x37a, 0x5, 0x78, 0x3d, 0x2, 0x37a, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x37b, 0x37f, 0x5, 0x7c, 0x3f, 0x2, 0x37c, 0x37d, 0x5, 
    0x7a, 0x3e, 0x2, 0x37d, 0x37e, 0x5, 0x7c, 0x3f, 0x2, 0x37e, 0x380, 0x3, 
    0x2, 0x2, 0x2, 0x37f, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x380, 0x3, 
    0x2, 0x2, 0x2, 0x380, 0x79, 0x3, 0x2, 0x2, 0x2, 0x381, 0x382, 0x9, 0x6, 
    0x2, 0x2, 0x382, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x383, 0x385, 0x5, 0x7e, 
    0x40, 0x2, 0x384, 0x383, 0x3, 0x2, 0x2, 0x2, 0x384, 0x385, 0x3, 0x2, 
    0x2, 0x2, 0x385, 0x386, 0x3, 0x2, 0x2, 0x2, 0x386, 0x38c, 0x5, 0x80, 
    0x41, 0x2, 0x387, 0x388, 0x5, 0x7e, 0x40, 0x2, 0x388, 0x389, 0x5, 0x80, 
    0x41, 0x2, 0x389, 0x38b, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x387, 0x3, 0x2, 
    0x2, 0x2, 0x38b, 0x38e, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x38a, 0x3, 0x2, 
    0x2, 0x2, 0x38c, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x38e, 0x38c, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x390, 0x9, 0x7, 0x2, 
    0x2, 0x390, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x391, 0x397, 0x5, 0x84, 0x43, 
    0x2, 0x392, 0x393, 0x5, 0x82, 0x42, 0x2, 0x393, 0x394, 0x5, 0x84, 0x43, 
    0x2, 0x394, 0x396, 0x3, 0x2, 0x2, 0x2, 0x395, 0x392, 0x3, 0x2, 0x2, 
    0x2, 0x396, 0x399, 0x3, 0x2, 0x2, 0x2, 0x397, 0x395, 0x3, 0x2, 0x2, 
    0x2, 0x397, 0x398, 0x3, 0x2, 0x2, 0x2, 0x398, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x399, 0x397, 0x3, 0x2, 0x2, 0x2, 0x39a, 0x39b, 0x9, 0x8, 0x2, 0x2, 
    0x39b, 0x83, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x39f, 0x5, 0x86, 0x44, 0x2, 
    0x39d, 0x39e, 0x9, 0x9, 0x2, 0x2, 0x39e, 0x3a0, 0x5, 0x86, 0x44, 0x2, 
    0x39f, 0x39d, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a0, 0x3, 0x2, 0x2, 0x2, 
    0x3a0, 0x85, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3c1, 0x7, 0x5d, 0x2, 0x2, 
    0x3a2, 0x3c1, 0x7, 0x5c, 0x2, 0x2, 0x3a3, 0x3c1, 0x7, 0x54, 0x2, 0x2, 
    0x3a4, 0x3c1, 0x7, 0x55, 0x2, 0x2, 0x3a5, 0x3a9, 0x5, 0x88, 0x45, 0x2, 
    0x3a6, 0x3a9, 0x7, 0x1b, 0x2, 0x2, 0x3a7, 0x3a9, 0x7, 0x33, 0x2, 0x2, 
    0x3a8, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3a6, 0x3, 0x2, 0x2, 0x2, 
    0x3a8, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3aa, 0x3, 0x2, 0x2, 0x2, 
    0x3aa, 0x3c1, 0x5, 0x8c, 0x47, 0x2, 0x3ab, 0x3c1, 0x5, 0x8a, 0x46, 0x2, 
    0x3ac, 0x3ad, 0x7, 0x18, 0x2, 0x2, 0x3ad, 0x3ae, 0x5, 0x96, 0x4c, 0x2, 
    0x3ae, 0x3af, 0x7, 0x1a, 0x2, 0x2, 0x3af, 0x3c1, 0x3, 0x2, 0x2, 0x2, 
    0x3b0, 0x3b1, 0x7, 0x56, 0x2, 0x2, 0x3b1, 0x3b6, 0x5, 0x98, 0x4d, 0x2, 
    0x3b2, 0x3b3, 0x7, 0x4, 0x2, 0x2, 0x3b3, 0x3b5, 0x5, 0x98, 0x4d, 0x2, 
    0x3b4, 0x3b2, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b8, 0x3, 0x2, 0x2, 0x2, 
    0x3b6, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b6, 0x3b7, 0x3, 0x2, 0x2, 0x2, 
    0x3b7, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b6, 0x3, 0x2, 0x2, 0x2, 
    0x3b9, 0x3ba, 0x7, 0x57, 0x2, 0x2, 0x3ba, 0x3c1, 0x3, 0x2, 0x2, 0x2, 
    0x3bb, 0x3bc, 0x7, 0x58, 0x2, 0x2, 0x3bc, 0x3bd, 0x5, 0x8e, 0x48, 0x2, 
    0x3bd, 0x3be, 0x7, 0x27, 0x2, 0x2, 0x3be, 0x3c1, 0x3, 0x2, 0x2, 0x2, 
    0x3bf, 0x3c1, 0x7, 0x14, 0x2, 0x2, 0x3c0, 0x3a1, 0x3, 0x2, 0x2, 0x2, 
    0x3c0, 0x3a2, 0x3, 0x2, 0x2, 0x2, 0x3c0, 0x3a3, 0x3, 0x2, 0x2, 0x2, 
    0x3c0, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3c0, 0x3a8, 0x3, 0x2, 0x2, 0x2, 
    0x3c0, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3c0, 0x3ac, 0x3, 0x2, 0x2, 0x2, 
    0x3c0, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3c0, 0x3bb, 0x3, 0x2, 0x2, 0x2, 
    0x3c0, 0x3bf, 0x3, 0x2, 0x2, 0x2, 0x3c1, 0x87, 0x3, 0x2, 0x2, 0x2, 0x3c2, 
    0x3c4, 0x7, 0x59, 0x2, 0x2, 0x3c3, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c3, 
    0x3c4, 0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3c5, 0x3, 0x2, 0x2, 0x2, 0x3c5, 
    0x3ca, 0x7, 0x5b, 0x2, 0x2, 0x3c6, 0x3c7, 0x7, 0x59, 0x2, 0x2, 0x3c7, 
    0x3c9, 0x7, 0x5b, 0x2, 0x2, 0x3c8, 0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3c9, 
    0x3cc, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3ca, 
    0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3cb, 0x89, 0x3, 0x2, 0x2, 0x2, 0x3cc, 0x3ca, 
    0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3cf, 0x7, 0x59, 0x2, 0x2, 0x3ce, 0x3cd, 
    0x3, 0x2, 0x2, 0x2, 0x3ce, 0x3cf, 0x3, 0x2, 0x2, 0x2, 0x3cf, 0x3d0, 
    0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3d2, 0x7, 0x5b, 0x2, 0x2, 0x3d1, 0x3d3, 
    0x5, 0x9a, 0x4e, 0x2, 0x3d2, 0x3d1, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3d3, 
    0x3, 0x2, 0x2, 0x2, 0x3d3, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3d4, 0x3d5, 
    0x7, 0x59, 0x2, 0x2, 0x3d5, 0x3d7, 0x7, 0x5b, 0x2, 0x2, 0x3d6, 0x3d8, 
    0x5, 0x9a, 0x4e, 0x2, 0x3d7, 0x3d6, 0x3, 0x2, 0x2, 0x2, 0x3d7, 0x3d8, 
    0x3, 0x2, 0x2, 0x2, 0x3d8, 0x3da, 0x3, 0x2, 0x2, 0x2, 0x3d9, 0x3d4, 
    0x3, 0x2, 0x2, 0x2, 0x3da, 0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3d9, 
    0x3, 0x2, 0x2, 0x2, 0x3db, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3dc, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x3dd, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3de, 0x3e0, 0x7, 
    0x18, 0x2, 0x2, 0x3df, 0x3e1, 0x5, 0x8e, 0x48, 0x2, 0x3e0, 0x3df, 0x3, 
    0x2, 0x2, 0x2, 0x3e0, 0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3e1, 0x3e2, 0x3, 
    0x2, 0x2, 0x2, 0x3e2, 0x3e3, 0x7, 0x1a, 0x2, 0x2, 0x3e3, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x3e4, 0x3e9, 0x5, 0x94, 0x4b, 0x2, 0x3e5, 0x3e6, 0x7, 
    0x1c, 0x2, 0x2, 0x3e6, 0x3ea, 0x5, 0x8e, 0x48, 0x2, 0x3e7, 0x3e8, 0x7, 
    0x3b, 0x2, 0x2, 0x3e8, 0x3ea, 0x5, 0x62, 0x32, 0x2, 0x3e9, 0x3e5, 0x3, 
    0x2, 0x2, 0x2, 0x3e9, 0x3e7, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3ea, 0x3, 
    0x2, 0x2, 0x2, 0x3ea, 0x3ed, 0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3ed, 0x5, 
    0x90, 0x49, 0x2, 0x3ec, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3eb, 0x3, 
    0x2, 0x2, 0x2, 0x3ed, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3f1, 0x5, 0x92, 
    0x4a, 0x2, 0x3ef, 0x3f0, 0x7, 0x1c, 0x2, 0x2, 0x3f0, 0x3f2, 0x5, 0x90, 
    0x49, 0x2, 0x3f1, 0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3f2, 0x3, 0x2, 
    0x2, 0x2, 0x3f2, 0x91, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f4, 0x7, 0x5b, 
    0x2, 0x2, 0x3f4, 0x3f5, 0x7, 0x16, 0x2, 0x2, 0x3f5, 0x3f6, 0x5, 0x94, 
    0x4b, 0x2, 0x3f6, 0x93, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f8, 0x7, 0x13, 
    0x2, 0x2, 0x3f8, 0x3f9, 0x5, 0x88, 0x45, 0x2, 0x3f9, 0x3fb, 0x7, 0x18, 
    0x2, 0x2, 0x3fa, 0x3fc, 0x5, 0x90, 0x49, 0x2, 0x3fb, 0x3fa, 0x3, 0x2, 
    0x2, 0x2, 0x3fb, 0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3fd, 0x3, 0x2, 
    0x2, 0x2, 0x3fd, 0x3fe, 0x7, 0x1a, 0x2, 0x2, 0x3fe, 0x401, 0x3, 0x2, 
    0x2, 0x2, 0x3ff, 0x401, 0x5, 0x6e, 0x38, 0x2, 0x400, 0x3f7, 0x3, 0x2, 
    0x2, 0x2, 0x400, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0x401, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x402, 0x404, 0x5, 0x6e, 0x38, 0x2, 0x403, 0x402, 0x3, 0x2, 0x2, 
    0x2, 0x403, 0x404, 0x3, 0x2, 0x2, 0x2, 0x404, 0x40b, 0x3, 0x2, 0x2, 
    0x2, 0x405, 0x407, 0x7, 0x1c, 0x2, 0x2, 0x406, 0x408, 0x5, 0x6e, 0x38, 
    0x2, 0x407, 0x406, 0x3, 0x2, 0x2, 0x2, 0x407, 0x408, 0x3, 0x2, 0x2, 
    0x2, 0x408, 0x40a, 0x3, 0x2, 0x2, 0x2, 0x409, 0x405, 0x3, 0x2, 0x2, 
    0x2, 0x40a, 0x40d, 0x3, 0x2, 0x2, 0x2, 0x40b, 0x409, 0x3, 0x2, 0x2, 
    0x2, 0x40b, 0x40c, 0x3, 0x2, 0x2, 0x2, 0x40c, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x40d, 0x40b, 0x3, 0x2, 0x2, 0x2, 0x40e, 0x413, 0x5, 0x6e, 0x38, 0x2, 
    0x40f, 0x410, 0x7, 0x1c, 0x2, 0x2, 0x410, 0x412, 0x5, 0x6e, 0x38, 0x2, 
    0x411, 0x40f, 0x3, 0x2, 0x2, 0x2, 0x412, 0x415, 0x3, 0x2, 0x2, 0x2, 
    0x413, 0x411, 0x3, 0x2, 0x2, 0x2, 0x413, 0x414, 0x3, 0x2, 0x2, 0x2, 
    0x414, 0x99, 0x3, 0x2, 0x2, 0x2, 0x415, 0x413, 0x3, 0x2, 0x2, 0x2, 0x416, 
    0x417, 0x7, 0x56, 0x2, 0x2, 0x417, 0x41c, 0x5, 0x9c, 0x4f, 0x2, 0x418, 
    0x419, 0x7, 0x1c, 0x2, 0x2, 0x419, 0x41b, 0x5, 0x9c, 0x4f, 0x2, 0x41a, 
    0x418, 0x3, 0x2, 0x2, 0x2, 0x41b, 0x41e, 0x3, 0x2, 0x2, 0x2, 0x41c, 
    0x41a, 0x3, 0x2, 0x2, 0x2, 0x41c, 0x41d, 0x3, 0x2, 0x2, 0x2, 0x41d, 
    0x41f, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x41c, 0x3, 0x2, 0x2, 0x2, 0x41f, 
    0x420, 0x7, 0x57, 0x2, 0x2, 0x420, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x421, 
    0x424, 0x7, 0x19, 0x2, 0x2, 0x422, 0x424, 0x5, 0x6e, 0x38, 0x2, 0x423, 
    0x421, 0x3, 0x2, 0x2, 0x2, 0x423, 0x422, 0x3, 0x2, 0x2, 0x2, 0x424, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0x425, 0x427, 0x5, 0xa0, 0x51, 0x2, 0x426, 
    0x428, 0x5, 0xa4, 0x53, 0x2, 0x427, 0x426, 0x3, 0x2, 0x2, 0x2, 0x427, 
    0x428, 0x3, 0x2, 0x2, 0x2, 0x428, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x429, 0x42e, 
    0x7, 0x5c, 0x2, 0x2, 0x42a, 0x42b, 0x7, 0x4b, 0x2, 0x2, 0x42b, 0x42d, 
    0x7, 0x5c, 0x2, 0x2, 0x42c, 0x42a, 0x3, 0x2, 0x2, 0x2, 0x42d, 0x430, 
    0x3, 0x2, 0x2, 0x2, 0x42e, 0x42c, 0x3, 0x2, 0x2, 0x2, 0x42e, 0x42f, 
    0x3, 0x2, 0x2, 0x2, 0x42f, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x430, 0x42e, 0x3, 
    0x2, 0x2, 0x2, 0x431, 0x432, 0x5, 0xa4, 0x53, 0x2, 0x432, 0xa3, 0x3, 
    0x2, 0x2, 0x2, 0x433, 0x434, 0x7, 0x5a, 0x2, 0x2, 0x434, 0x435, 0x5, 
    0x3e, 0x20, 0x2, 0x435, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x96, 0xa9, 0xad, 
    0xb4, 0xb9, 0xbe, 0xc6, 0xc9, 0xce, 0xd3, 0xd9, 0xdc, 0xe0, 0xe4, 0xed, 
    0xf0, 0xf6, 0xfd, 0x100, 0x103, 0x10a, 0x10d, 0x111, 0x113, 0x120, 0x125, 
    0x128, 0x12b, 0x12e, 0x135, 0x13a, 0x143, 0x145, 0x14a, 0x14d, 0x150, 
    0x153, 0x158, 0x15f, 0x164, 0x16b, 0x171, 0x174, 0x177, 0x17a, 0x17e, 
    0x183, 0x188, 0x18a, 0x18c, 0x19d, 0x1a0, 0x1a7, 0x1ad, 0x1b0, 0x1b5, 
    0x1b8, 0x1bb, 0x1be, 0x1c2, 0x1d3, 0x1d8, 0x1db, 0x1e2, 0x1e5, 0x1ea, 
    0x1f0, 0x1f4, 0x1fd, 0x202, 0x205, 0x208, 0x20c, 0x210, 0x213, 0x217, 
    0x21a, 0x21e, 0x221, 0x226, 0x229, 0x22c, 0x22f, 0x232, 0x23e, 0x244, 
    0x248, 0x250, 0x25e, 0x261, 0x269, 0x278, 0x27b, 0x285, 0x290, 0x295, 
    0x29e, 0x2a1, 0x2ae, 0x2b9, 0x2be, 0x2c7, 0x2ca, 0x2d7, 0x2e5, 0x2f0, 
    0x2f6, 0x300, 0x30e, 0x319, 0x31e, 0x32c, 0x337, 0x33c, 0x355, 0x35b, 
    0x362, 0x364, 0x36b, 0x373, 0x377, 0x37f, 0x384, 0x38c, 0x397, 0x39f, 
    0x3a8, 0x3b6, 0x3c0, 0x3c3, 0x3ca, 0x3ce, 0x3d2, 0x3d7, 0x3db, 0x3e0, 
    0x3e9, 0x3ec, 0x3f1, 0x3fb, 0x400, 0x403, 0x407, 0x40b, 0x413, 0x41c, 
    0x423, 0x427, 0x42e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

modelicaParser::Initializer modelicaParser::_init;
