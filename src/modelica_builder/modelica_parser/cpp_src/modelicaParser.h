
// Generated from /var/antlrResult/modelica.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  modelicaParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, T__45 = 46, T__46 = 47, T__47 = 48, T__48 = 49, T__49 = 50, 
    T__50 = 51, T__51 = 52, T__52 = 53, T__53 = 54, T__54 = 55, T__55 = 56, 
    T__56 = 57, T__57 = 58, T__58 = 59, T__59 = 60, T__60 = 61, T__61 = 62, 
    T__62 = 63, T__63 = 64, T__64 = 65, T__65 = 66, T__66 = 67, T__67 = 68, 
    T__68 = 69, T__69 = 70, T__70 = 71, T__71 = 72, T__72 = 73, T__73 = 74, 
    T__74 = 75, T__75 = 76, T__76 = 77, T__77 = 78, T__78 = 79, T__79 = 80, 
    T__80 = 81, T__81 = 82, T__82 = 83, T__83 = 84, T__84 = 85, T__85 = 86, 
    T__86 = 87, T__87 = 88, IDENT = 89, STRING = 90, UNSIGNED_NUMBER = 91, 
    WS = 92, COMMENT = 93, LINE_COMMENT = 94
  };

  enum {
    RuleStored_definition = 0, RuleWithin_statement = 1, RuleClass_definition = 2, 
    RuleClass_specifier = 3, RuleClass_prefixes = 4, RuleLong_class_specifier = 5, 
    RuleShort_class_specifier = 6, RuleDer_class_specifier = 7, RuleBase_prefix = 8, 
    RuleEnum_list = 9, RuleEnumeration_literal = 10, RuleComposition = 11, 
    RuleLanguage_specification = 12, RuleExternal_function_call = 13, RuleElement_list = 14, 
    RuleElement = 15, RuleImport_clause = 16, RuleImport_list = 17, RuleExtends_clause = 18, 
    RuleConstraining_clause = 19, RuleComponent_clause = 20, RuleType_prefix_connector = 21, 
    RuleType_prefix_variability = 22, RuleType_prefix_io = 23, RuleType_specifier = 24, 
    RuleComponent_list = 25, RuleComponent_declaration = 26, RuleCondition_attribute = 27, 
    RuleDeclaration = 28, RuleModification = 29, RuleClass_modification = 30, 
    RuleArgument_list = 31, RuleArgument = 32, RuleElement_modification_or_replaceable = 33, 
    RuleElement_modification = 34, RuleElement_redeclaration = 35, RuleElement_replaceable = 36, 
    RuleComponent_clause1 = 37, RuleComponent_declaration1 = 38, RuleShort_class_definition = 39, 
    RuleEquation_section = 40, RuleAlgorithm_section = 41, RuleEquation = 42, 
    RuleStatement = 43, RuleIf_equation = 44, RuleIf_statement = 45, RuleFor_equation = 46, 
    RuleFor_statement = 47, RuleFor_indices = 48, RuleFor_index = 49, RuleWhile_statement = 50, 
    RuleWhen_equation = 51, RuleWhen_statement = 52, RuleConnect_clause = 53, 
    RuleExpression = 54, RuleSimple_expression = 55, RuleLogical_expression = 56, 
    RuleLogical_term = 57, RuleLogical_factor = 58, RuleRelation = 59, RuleRel_op = 60, 
    RuleArithmetic_expression = 61, RuleAdd_op = 62, RuleTerm = 63, RuleMul_op = 64, 
    RuleFactor = 65, RulePrimary = 66, RuleName = 67, RuleComponent_reference = 68, 
    RuleFunction_call_args = 69, RuleFunction_arguments = 70, RuleNamed_arguments = 71, 
    RuleNamed_argument = 72, RuleFunction_argument = 73, RuleOutput_expression_list = 74, 
    RuleExpression_list = 75, RuleArray_subscripts = 76, RuleSubscript = 77, 
    RuleComment = 78, RuleString_comment = 79, RuleModel_annotation = 80, 
    RuleAnnotation = 81
  };

  modelicaParser(antlr4::TokenStream *input);
  ~modelicaParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Stored_definitionContext;
  class Within_statementContext;
  class Class_definitionContext;
  class Class_specifierContext;
  class Class_prefixesContext;
  class Long_class_specifierContext;
  class Short_class_specifierContext;
  class Der_class_specifierContext;
  class Base_prefixContext;
  class Enum_listContext;
  class Enumeration_literalContext;
  class CompositionContext;
  class Language_specificationContext;
  class External_function_callContext;
  class Element_listContext;
  class ElementContext;
  class Import_clauseContext;
  class Import_listContext;
  class Extends_clauseContext;
  class Constraining_clauseContext;
  class Component_clauseContext;
  class Type_prefix_connectorContext;
  class Type_prefix_variabilityContext;
  class Type_prefix_ioContext;
  class Type_specifierContext;
  class Component_listContext;
  class Component_declarationContext;
  class Condition_attributeContext;
  class DeclarationContext;
  class ModificationContext;
  class Class_modificationContext;
  class Argument_listContext;
  class ArgumentContext;
  class Element_modification_or_replaceableContext;
  class Element_modificationContext;
  class Element_redeclarationContext;
  class Element_replaceableContext;
  class Component_clause1Context;
  class Component_declaration1Context;
  class Short_class_definitionContext;
  class Equation_sectionContext;
  class Algorithm_sectionContext;
  class EquationContext;
  class StatementContext;
  class If_equationContext;
  class If_statementContext;
  class For_equationContext;
  class For_statementContext;
  class For_indicesContext;
  class For_indexContext;
  class While_statementContext;
  class When_equationContext;
  class When_statementContext;
  class Connect_clauseContext;
  class ExpressionContext;
  class Simple_expressionContext;
  class Logical_expressionContext;
  class Logical_termContext;
  class Logical_factorContext;
  class RelationContext;
  class Rel_opContext;
  class Arithmetic_expressionContext;
  class Add_opContext;
  class TermContext;
  class Mul_opContext;
  class FactorContext;
  class PrimaryContext;
  class NameContext;
  class Component_referenceContext;
  class Function_call_argsContext;
  class Function_argumentsContext;
  class Named_argumentsContext;
  class Named_argumentContext;
  class Function_argumentContext;
  class Output_expression_listContext;
  class Expression_listContext;
  class Array_subscriptsContext;
  class SubscriptContext;
  class CommentContext;
  class String_commentContext;
  class Model_annotationContext;
  class AnnotationContext; 

  class  Stored_definitionContext : public antlr4::ParserRuleContext {
  public:
    Stored_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Within_statementContext *> within_statement();
    Within_statementContext* within_statement(size_t i);
    std::vector<Class_definitionContext *> class_definition();
    Class_definitionContext* class_definition(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Stored_definitionContext* stored_definition();

  class  Within_statementContext : public antlr4::ParserRuleContext {
  public:
    Within_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Within_statementContext* within_statement();

  class  Class_definitionContext : public antlr4::ParserRuleContext {
  public:
    Class_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_prefixesContext *class_prefixes();
    Class_specifierContext *class_specifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_definitionContext* class_definition();

  class  Class_specifierContext : public antlr4::ParserRuleContext {
  public:
    Class_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Long_class_specifierContext *long_class_specifier();
    Short_class_specifierContext *short_class_specifier();
    Der_class_specifierContext *der_class_specifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_specifierContext* class_specifier();

  class  Class_prefixesContext : public antlr4::ParserRuleContext {
  public:
    Class_prefixesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_prefixesContext* class_prefixes();

  class  Long_class_specifierContext : public antlr4::ParserRuleContext {
  public:
    Long_class_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENT();
    antlr4::tree::TerminalNode* IDENT(size_t i);
    CompositionContext *composition();
    String_commentContext *string_comment();
    Class_modificationContext *class_modification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Long_class_specifierContext* long_class_specifier();

  class  Short_class_specifierContext : public antlr4::ParserRuleContext {
  public:
    Short_class_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    Base_prefixContext *base_prefix();
    NameContext *name();
    Array_subscriptsContext *array_subscripts();
    Class_modificationContext *class_modification();
    CommentContext *comment();
    Enum_listContext *enum_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Short_class_specifierContext* short_class_specifier();

  class  Der_class_specifierContext : public antlr4::ParserRuleContext {
  public:
    Der_class_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENT();
    antlr4::tree::TerminalNode* IDENT(size_t i);
    NameContext *name();
    CommentContext *comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Der_class_specifierContext* der_class_specifier();

  class  Base_prefixContext : public antlr4::ParserRuleContext {
  public:
    Base_prefixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_prefix_connectorContext *type_prefix_connector();
    Type_prefix_variabilityContext *type_prefix_variability();
    Type_prefix_ioContext *type_prefix_io();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Base_prefixContext* base_prefix();

  class  Enum_listContext : public antlr4::ParserRuleContext {
  public:
    Enum_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Enumeration_literalContext *> enumeration_literal();
    Enumeration_literalContext* enumeration_literal(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_listContext* enum_list();

  class  Enumeration_literalContext : public antlr4::ParserRuleContext {
  public:
    Enumeration_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    CommentContext *comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enumeration_literalContext* enumeration_literal();

  class  CompositionContext : public antlr4::ParserRuleContext {
  public:
    CompositionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Element_listContext *> element_list();
    Element_listContext* element_list(size_t i);
    std::vector<Equation_sectionContext *> equation_section();
    Equation_sectionContext* equation_section(size_t i);
    std::vector<Algorithm_sectionContext *> algorithm_section();
    Algorithm_sectionContext* algorithm_section(size_t i);
    Model_annotationContext *model_annotation();
    Language_specificationContext *language_specification();
    External_function_callContext *external_function_call();
    AnnotationContext *annotation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompositionContext* composition();

  class  Language_specificationContext : public antlr4::ParserRuleContext {
  public:
    Language_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Language_specificationContext* language_specification();

  class  External_function_callContext : public antlr4::ParserRuleContext {
  public:
    External_function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    Component_referenceContext *component_reference();
    Expression_listContext *expression_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  External_function_callContext* external_function_call();

  class  Element_listContext : public antlr4::ParserRuleContext {
  public:
    Element_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ElementContext *> element();
    ElementContext* element(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Element_listContext* element_list();

  class  ElementContext : public antlr4::ParserRuleContext {
  public:
    ElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Import_clauseContext *import_clause();
    Extends_clauseContext *extends_clause();
    Class_definitionContext *class_definition();
    Component_clauseContext *component_clause();
    Constraining_clauseContext *constraining_clause();
    CommentContext *comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementContext* element();

  class  Import_clauseContext : public antlr4::ParserRuleContext {
  public:
    Import_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    NameContext *name();
    Import_listContext *import_list();
    CommentContext *comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_clauseContext* import_clause();

  class  Import_listContext : public antlr4::ParserRuleContext {
  public:
    Import_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENT();
    antlr4::tree::TerminalNode* IDENT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_listContext* import_list();

  class  Extends_clauseContext : public antlr4::ParserRuleContext {
  public:
    Extends_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    Class_modificationContext *class_modification();
    AnnotationContext *annotation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extends_clauseContext* extends_clause();

  class  Constraining_clauseContext : public antlr4::ParserRuleContext {
  public:
    Constraining_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    Class_modificationContext *class_modification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constraining_clauseContext* constraining_clause();

  class  Component_clauseContext : public antlr4::ParserRuleContext {
  public:
    Component_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Component_listContext *component_list();
    Type_prefix_connectorContext *type_prefix_connector();
    Type_prefix_variabilityContext *type_prefix_variability();
    Type_prefix_ioContext *type_prefix_io();
    Array_subscriptsContext *array_subscripts();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_clauseContext* component_clause();

  class  Type_prefix_connectorContext : public antlr4::ParserRuleContext {
  public:
    Type_prefix_connectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_prefix_connectorContext* type_prefix_connector();

  class  Type_prefix_variabilityContext : public antlr4::ParserRuleContext {
  public:
    Type_prefix_variabilityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_prefix_variabilityContext* type_prefix_variability();

  class  Type_prefix_ioContext : public antlr4::ParserRuleContext {
  public:
    Type_prefix_ioContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_prefix_ioContext* type_prefix_io();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_specifierContext* type_specifier();

  class  Component_listContext : public antlr4::ParserRuleContext {
  public:
    Component_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Component_declarationContext *> component_declaration();
    Component_declarationContext* component_declaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_listContext* component_list();

  class  Component_declarationContext : public antlr4::ParserRuleContext {
  public:
    Component_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    Condition_attributeContext *condition_attribute();
    CommentContext *comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_declarationContext* component_declaration();

  class  Condition_attributeContext : public antlr4::ParserRuleContext {
  public:
    Condition_attributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Condition_attributeContext* condition_attribute();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    Array_subscriptsContext *array_subscripts();
    ModificationContext *modification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  ModificationContext : public antlr4::ParserRuleContext {
  public:
    ModificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_modificationContext *class_modification();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModificationContext* modification();

  class  Class_modificationContext : public antlr4::ParserRuleContext {
  public:
    Class_modificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Argument_listContext *argument_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_modificationContext* class_modification();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgumentContext *> argument();
    ArgumentContext* argument(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Argument_listContext* argument_list();

  class  ArgumentContext : public antlr4::ParserRuleContext {
  public:
    ArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Element_modification_or_replaceableContext *element_modification_or_replaceable();
    Element_redeclarationContext *element_redeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentContext* argument();

  class  Element_modification_or_replaceableContext : public antlr4::ParserRuleContext {
  public:
    Element_modification_or_replaceableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Element_modificationContext *element_modification();
    Element_replaceableContext *element_replaceable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Element_modification_or_replaceableContext* element_modification_or_replaceable();

  class  Element_modificationContext : public antlr4::ParserRuleContext {
  public:
    Element_modificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    ModificationContext *modification();
    String_commentContext *string_comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Element_modificationContext* element_modification();

  class  Element_redeclarationContext : public antlr4::ParserRuleContext {
  public:
    Element_redeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Element_replaceableContext *element_replaceable();
    Short_class_definitionContext *short_class_definition();
    Component_clause1Context *component_clause1();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Element_redeclarationContext* element_redeclaration();

  class  Element_replaceableContext : public antlr4::ParserRuleContext {
  public:
    Element_replaceableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Short_class_definitionContext *short_class_definition();
    Component_clause1Context *component_clause1();
    Constraining_clauseContext *constraining_clause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Element_replaceableContext* element_replaceable();

  class  Component_clause1Context : public antlr4::ParserRuleContext {
  public:
    Component_clause1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Component_declaration1Context *component_declaration1();
    Type_prefix_connectorContext *type_prefix_connector();
    Type_prefix_variabilityContext *type_prefix_variability();
    Type_prefix_ioContext *type_prefix_io();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_clause1Context* component_clause1();

  class  Component_declaration1Context : public antlr4::ParserRuleContext {
  public:
    Component_declaration1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    CommentContext *comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_declaration1Context* component_declaration1();

  class  Short_class_definitionContext : public antlr4::ParserRuleContext {
  public:
    Short_class_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_prefixesContext *class_prefixes();
    Short_class_specifierContext *short_class_specifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Short_class_definitionContext* short_class_definition();

  class  Equation_sectionContext : public antlr4::ParserRuleContext {
  public:
    Equation_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EquationContext *> equation();
    EquationContext* equation(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Equation_sectionContext* equation_section();

  class  Algorithm_sectionContext : public antlr4::ParserRuleContext {
  public:
    Algorithm_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Algorithm_sectionContext* algorithm_section();

  class  EquationContext : public antlr4::ParserRuleContext {
  public:
    EquationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_expressionContext *simple_expression();
    ExpressionContext *expression();
    If_equationContext *if_equation();
    For_equationContext *for_equation();
    Connect_clauseContext *connect_clause();
    When_equationContext *when_equation();
    NameContext *name();
    Function_call_argsContext *function_call_args();
    CommentContext *comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EquationContext* equation();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Component_referenceContext *component_reference();
    Output_expression_listContext *output_expression_list();
    Function_call_argsContext *function_call_args();
    If_statementContext *if_statement();
    For_statementContext *for_statement();
    While_statementContext *while_statement();
    When_statementContext *when_statement();
    CommentContext *comment();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  If_equationContext : public antlr4::ParserRuleContext {
  public:
    If_equationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<EquationContext *> equation();
    EquationContext* equation(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_equationContext* if_equation();

  class  If_statementContext : public antlr4::ParserRuleContext {
  public:
    If_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_statementContext* if_statement();

  class  For_equationContext : public antlr4::ParserRuleContext {
  public:
    For_equationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    For_indicesContext *for_indices();
    std::vector<EquationContext *> equation();
    EquationContext* equation(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_equationContext* for_equation();

  class  For_statementContext : public antlr4::ParserRuleContext {
  public:
    For_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    For_indicesContext *for_indices();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_statementContext* for_statement();

  class  For_indicesContext : public antlr4::ParserRuleContext {
  public:
    For_indicesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<For_indexContext *> for_index();
    For_indexContext* for_index(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_indicesContext* for_indices();

  class  For_indexContext : public antlr4::ParserRuleContext {
  public:
    For_indexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_indexContext* for_index();

  class  While_statementContext : public antlr4::ParserRuleContext {
  public:
    While_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_statementContext* while_statement();

  class  When_equationContext : public antlr4::ParserRuleContext {
  public:
    When_equationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<EquationContext *> equation();
    EquationContext* equation(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  When_equationContext* when_equation();

  class  When_statementContext : public antlr4::ParserRuleContext {
  public:
    When_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  When_statementContext* when_statement();

  class  Connect_clauseContext : public antlr4::ParserRuleContext {
  public:
    Connect_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Component_referenceContext *> component_reference();
    Component_referenceContext* component_reference(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Connect_clauseContext* connect_clause();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_expressionContext *simple_expression();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Logical_expressionContext *> logical_expression();
    Logical_expressionContext* logical_expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_expressionContext* simple_expression();

  class  Logical_expressionContext : public antlr4::ParserRuleContext {
  public:
    Logical_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Logical_termContext *> logical_term();
    Logical_termContext* logical_term(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logical_expressionContext* logical_expression();

  class  Logical_termContext : public antlr4::ParserRuleContext {
  public:
    Logical_termContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Logical_factorContext *> logical_factor();
    Logical_factorContext* logical_factor(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logical_termContext* logical_term();

  class  Logical_factorContext : public antlr4::ParserRuleContext {
  public:
    Logical_factorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelationContext *relation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logical_factorContext* logical_factor();

  class  RelationContext : public antlr4::ParserRuleContext {
  public:
    RelationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Arithmetic_expressionContext *> arithmetic_expression();
    Arithmetic_expressionContext* arithmetic_expression(size_t i);
    Rel_opContext *rel_op();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationContext* relation();

  class  Rel_opContext : public antlr4::ParserRuleContext {
  public:
    Rel_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rel_opContext* rel_op();

  class  Arithmetic_expressionContext : public antlr4::ParserRuleContext {
  public:
    Arithmetic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    std::vector<Add_opContext *> add_op();
    Add_opContext* add_op(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arithmetic_expressionContext* arithmetic_expression();

  class  Add_opContext : public antlr4::ParserRuleContext {
  public:
    Add_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Add_opContext* add_op();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    std::vector<Mul_opContext *> mul_op();
    Mul_opContext* mul_op(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();

  class  Mul_opContext : public antlr4::ParserRuleContext {
  public:
    Mul_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mul_opContext* mul_op();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PrimaryContext *> primary();
    PrimaryContext* primary(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FactorContext* factor();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNSIGNED_NUMBER();
    antlr4::tree::TerminalNode *STRING();
    Function_call_argsContext *function_call_args();
    NameContext *name();
    Component_referenceContext *component_reference();
    Output_expression_listContext *output_expression_list();
    std::vector<Expression_listContext *> expression_list();
    Expression_listContext* expression_list(size_t i);
    Function_argumentsContext *function_arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryContext* primary();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENT();
    antlr4::tree::TerminalNode* IDENT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameContext* name();

  class  Component_referenceContext : public antlr4::ParserRuleContext {
  public:
    Component_referenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENT();
    antlr4::tree::TerminalNode* IDENT(size_t i);
    std::vector<Array_subscriptsContext *> array_subscripts();
    Array_subscriptsContext* array_subscripts(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_referenceContext* component_reference();

  class  Function_call_argsContext : public antlr4::ParserRuleContext {
  public:
    Function_call_argsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_argumentsContext *function_arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_call_argsContext* function_call_args();

  class  Function_argumentsContext : public antlr4::ParserRuleContext {
  public:
    Function_argumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_argumentContext *function_argument();
    Function_argumentsContext *function_arguments();
    For_indicesContext *for_indices();
    Named_argumentsContext *named_arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_argumentsContext* function_arguments();

  class  Named_argumentsContext : public antlr4::ParserRuleContext {
  public:
    Named_argumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Named_argumentContext *named_argument();
    Named_argumentsContext *named_arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_argumentsContext* named_arguments();

  class  Named_argumentContext : public antlr4::ParserRuleContext {
  public:
    Named_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    Function_argumentContext *function_argument();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_argumentContext* named_argument();

  class  Function_argumentContext : public antlr4::ParserRuleContext {
  public:
    Function_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    Named_argumentsContext *named_arguments();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_argumentContext* function_argument();

  class  Output_expression_listContext : public antlr4::ParserRuleContext {
  public:
    Output_expression_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Output_expression_listContext* output_expression_list();

  class  Expression_listContext : public antlr4::ParserRuleContext {
  public:
    Expression_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_listContext* expression_list();

  class  Array_subscriptsContext : public antlr4::ParserRuleContext {
  public:
    Array_subscriptsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SubscriptContext *> subscript();
    SubscriptContext* subscript(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_subscriptsContext* array_subscripts();

  class  SubscriptContext : public antlr4::ParserRuleContext {
  public:
    SubscriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubscriptContext* subscript();

  class  CommentContext : public antlr4::ParserRuleContext {
  public:
    CommentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    String_commentContext *string_comment();
    AnnotationContext *annotation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommentContext* comment();

  class  String_commentContext : public antlr4::ParserRuleContext {
  public:
    String_commentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> STRING();
    antlr4::tree::TerminalNode* STRING(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  String_commentContext* string_comment();

  class  Model_annotationContext : public antlr4::ParserRuleContext {
  public:
    Model_annotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnnotationContext *annotation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Model_annotationContext* model_annotation();

  class  AnnotationContext : public antlr4::ParserRuleContext {
  public:
    AnnotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_modificationContext *class_modification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationContext* annotation();


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

