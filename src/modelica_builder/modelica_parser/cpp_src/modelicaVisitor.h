
// Generated from /var/antlrResult/modelica.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "modelicaParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by modelicaParser.
 */
class  modelicaVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by modelicaParser.
   */
    virtual antlrcpp::Any visitStored_definition(modelicaParser::Stored_definitionContext *context) = 0;

    virtual antlrcpp::Any visitWithin_statement(modelicaParser::Within_statementContext *context) = 0;

    virtual antlrcpp::Any visitClass_definition(modelicaParser::Class_definitionContext *context) = 0;

    virtual antlrcpp::Any visitClass_specifier(modelicaParser::Class_specifierContext *context) = 0;

    virtual antlrcpp::Any visitClass_prefixes(modelicaParser::Class_prefixesContext *context) = 0;

    virtual antlrcpp::Any visitLong_class_specifier(modelicaParser::Long_class_specifierContext *context) = 0;

    virtual antlrcpp::Any visitShort_class_specifier(modelicaParser::Short_class_specifierContext *context) = 0;

    virtual antlrcpp::Any visitDer_class_specifier(modelicaParser::Der_class_specifierContext *context) = 0;

    virtual antlrcpp::Any visitBase_prefix(modelicaParser::Base_prefixContext *context) = 0;

    virtual antlrcpp::Any visitEnum_list(modelicaParser::Enum_listContext *context) = 0;

    virtual antlrcpp::Any visitEnumeration_literal(modelicaParser::Enumeration_literalContext *context) = 0;

    virtual antlrcpp::Any visitComposition(modelicaParser::CompositionContext *context) = 0;

    virtual antlrcpp::Any visitLanguage_specification(modelicaParser::Language_specificationContext *context) = 0;

    virtual antlrcpp::Any visitExternal_function_call(modelicaParser::External_function_callContext *context) = 0;

    virtual antlrcpp::Any visitElement_list(modelicaParser::Element_listContext *context) = 0;

    virtual antlrcpp::Any visitElement(modelicaParser::ElementContext *context) = 0;

    virtual antlrcpp::Any visitImport_clause(modelicaParser::Import_clauseContext *context) = 0;

    virtual antlrcpp::Any visitImport_list(modelicaParser::Import_listContext *context) = 0;

    virtual antlrcpp::Any visitExtends_clause(modelicaParser::Extends_clauseContext *context) = 0;

    virtual antlrcpp::Any visitConstraining_clause(modelicaParser::Constraining_clauseContext *context) = 0;

    virtual antlrcpp::Any visitComponent_clause(modelicaParser::Component_clauseContext *context) = 0;

    virtual antlrcpp::Any visitType_prefix_connector(modelicaParser::Type_prefix_connectorContext *context) = 0;

    virtual antlrcpp::Any visitType_prefix_variability(modelicaParser::Type_prefix_variabilityContext *context) = 0;

    virtual antlrcpp::Any visitType_prefix_io(modelicaParser::Type_prefix_ioContext *context) = 0;

    virtual antlrcpp::Any visitType_specifier(modelicaParser::Type_specifierContext *context) = 0;

    virtual antlrcpp::Any visitComponent_list(modelicaParser::Component_listContext *context) = 0;

    virtual antlrcpp::Any visitComponent_declaration(modelicaParser::Component_declarationContext *context) = 0;

    virtual antlrcpp::Any visitCondition_attribute(modelicaParser::Condition_attributeContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(modelicaParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitModification(modelicaParser::ModificationContext *context) = 0;

    virtual antlrcpp::Any visitClass_modification(modelicaParser::Class_modificationContext *context) = 0;

    virtual antlrcpp::Any visitArgument_list(modelicaParser::Argument_listContext *context) = 0;

    virtual antlrcpp::Any visitArgument(modelicaParser::ArgumentContext *context) = 0;

    virtual antlrcpp::Any visitElement_modification_or_replaceable(modelicaParser::Element_modification_or_replaceableContext *context) = 0;

    virtual antlrcpp::Any visitElement_modification(modelicaParser::Element_modificationContext *context) = 0;

    virtual antlrcpp::Any visitElement_redeclaration(modelicaParser::Element_redeclarationContext *context) = 0;

    virtual antlrcpp::Any visitElement_replaceable(modelicaParser::Element_replaceableContext *context) = 0;

    virtual antlrcpp::Any visitComponent_clause1(modelicaParser::Component_clause1Context *context) = 0;

    virtual antlrcpp::Any visitComponent_declaration1(modelicaParser::Component_declaration1Context *context) = 0;

    virtual antlrcpp::Any visitShort_class_definition(modelicaParser::Short_class_definitionContext *context) = 0;

    virtual antlrcpp::Any visitEquation_section(modelicaParser::Equation_sectionContext *context) = 0;

    virtual antlrcpp::Any visitAlgorithm_section(modelicaParser::Algorithm_sectionContext *context) = 0;

    virtual antlrcpp::Any visitEquation(modelicaParser::EquationContext *context) = 0;

    virtual antlrcpp::Any visitStatement(modelicaParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitIf_equation(modelicaParser::If_equationContext *context) = 0;

    virtual antlrcpp::Any visitIf_statement(modelicaParser::If_statementContext *context) = 0;

    virtual antlrcpp::Any visitFor_equation(modelicaParser::For_equationContext *context) = 0;

    virtual antlrcpp::Any visitFor_statement(modelicaParser::For_statementContext *context) = 0;

    virtual antlrcpp::Any visitFor_indices(modelicaParser::For_indicesContext *context) = 0;

    virtual antlrcpp::Any visitFor_index(modelicaParser::For_indexContext *context) = 0;

    virtual antlrcpp::Any visitWhile_statement(modelicaParser::While_statementContext *context) = 0;

    virtual antlrcpp::Any visitWhen_equation(modelicaParser::When_equationContext *context) = 0;

    virtual antlrcpp::Any visitWhen_statement(modelicaParser::When_statementContext *context) = 0;

    virtual antlrcpp::Any visitConnect_clause(modelicaParser::Connect_clauseContext *context) = 0;

    virtual antlrcpp::Any visitExpression(modelicaParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSimple_expression(modelicaParser::Simple_expressionContext *context) = 0;

    virtual antlrcpp::Any visitLogical_expression(modelicaParser::Logical_expressionContext *context) = 0;

    virtual antlrcpp::Any visitLogical_term(modelicaParser::Logical_termContext *context) = 0;

    virtual antlrcpp::Any visitLogical_factor(modelicaParser::Logical_factorContext *context) = 0;

    virtual antlrcpp::Any visitRelation(modelicaParser::RelationContext *context) = 0;

    virtual antlrcpp::Any visitRel_op(modelicaParser::Rel_opContext *context) = 0;

    virtual antlrcpp::Any visitArithmetic_expression(modelicaParser::Arithmetic_expressionContext *context) = 0;

    virtual antlrcpp::Any visitAdd_op(modelicaParser::Add_opContext *context) = 0;

    virtual antlrcpp::Any visitTerm(modelicaParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitMul_op(modelicaParser::Mul_opContext *context) = 0;

    virtual antlrcpp::Any visitFactor(modelicaParser::FactorContext *context) = 0;

    virtual antlrcpp::Any visitPrimary(modelicaParser::PrimaryContext *context) = 0;

    virtual antlrcpp::Any visitName(modelicaParser::NameContext *context) = 0;

    virtual antlrcpp::Any visitComponent_reference(modelicaParser::Component_referenceContext *context) = 0;

    virtual antlrcpp::Any visitFunction_call_args(modelicaParser::Function_call_argsContext *context) = 0;

    virtual antlrcpp::Any visitFunction_arguments(modelicaParser::Function_argumentsContext *context) = 0;

    virtual antlrcpp::Any visitNamed_arguments(modelicaParser::Named_argumentsContext *context) = 0;

    virtual antlrcpp::Any visitNamed_argument(modelicaParser::Named_argumentContext *context) = 0;

    virtual antlrcpp::Any visitFunction_argument(modelicaParser::Function_argumentContext *context) = 0;

    virtual antlrcpp::Any visitOutput_expression_list(modelicaParser::Output_expression_listContext *context) = 0;

    virtual antlrcpp::Any visitExpression_list(modelicaParser::Expression_listContext *context) = 0;

    virtual antlrcpp::Any visitArray_subscripts(modelicaParser::Array_subscriptsContext *context) = 0;

    virtual antlrcpp::Any visitSubscript(modelicaParser::SubscriptContext *context) = 0;

    virtual antlrcpp::Any visitComment(modelicaParser::CommentContext *context) = 0;

    virtual antlrcpp::Any visitString_comment(modelicaParser::String_commentContext *context) = 0;

    virtual antlrcpp::Any visitModel_annotation(modelicaParser::Model_annotationContext *context) = 0;

    virtual antlrcpp::Any visitAnnotation(modelicaParser::AnnotationContext *context) = 0;


};

