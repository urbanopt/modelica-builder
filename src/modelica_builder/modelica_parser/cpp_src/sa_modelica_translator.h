/*
 * This file was auto-generated by speedy-antlr-tool v1.0.0
 *  https://github.com/amykyta3/speedy-antlr-tool
 */

#pragma once

#include "modelicaBaseVisitor.h"
#include "speedy_antlr.h"

class SA_modelicaTranslator : public modelicaBaseVisitor {
    speedy_antlr::Translator *translator;

    // Cached context classes
    PyObject *Stored_definitionContext_cls = NULL;
    PyObject *Within_statementContext_cls = NULL;
    PyObject *Class_definitionContext_cls = NULL;
    PyObject *Class_specifierContext_cls = NULL;
    PyObject *Class_prefixesContext_cls = NULL;
    PyObject *Long_class_specifierContext_cls = NULL;
    PyObject *Short_class_specifierContext_cls = NULL;
    PyObject *Der_class_specifierContext_cls = NULL;
    PyObject *Base_prefixContext_cls = NULL;
    PyObject *Enum_listContext_cls = NULL;
    PyObject *Enumeration_literalContext_cls = NULL;
    PyObject *CompositionContext_cls = NULL;
    PyObject *Language_specificationContext_cls = NULL;
    PyObject *External_function_callContext_cls = NULL;
    PyObject *Element_listContext_cls = NULL;
    PyObject *ElementContext_cls = NULL;
    PyObject *Import_clauseContext_cls = NULL;
    PyObject *Import_listContext_cls = NULL;
    PyObject *Extends_clauseContext_cls = NULL;
    PyObject *Constraining_clauseContext_cls = NULL;
    PyObject *Component_clauseContext_cls = NULL;
    PyObject *Type_prefix_connectorContext_cls = NULL;
    PyObject *Type_prefix_variabilityContext_cls = NULL;
    PyObject *Type_prefix_ioContext_cls = NULL;
    PyObject *Type_specifierContext_cls = NULL;
    PyObject *Component_listContext_cls = NULL;
    PyObject *Component_declarationContext_cls = NULL;
    PyObject *Condition_attributeContext_cls = NULL;
    PyObject *DeclarationContext_cls = NULL;
    PyObject *ModificationContext_cls = NULL;
    PyObject *Class_modificationContext_cls = NULL;
    PyObject *Argument_listContext_cls = NULL;
    PyObject *ArgumentContext_cls = NULL;
    PyObject *Element_modification_or_replaceableContext_cls = NULL;
    PyObject *Element_modificationContext_cls = NULL;
    PyObject *Element_redeclarationContext_cls = NULL;
    PyObject *Element_replaceableContext_cls = NULL;
    PyObject *Component_clause1Context_cls = NULL;
    PyObject *Component_declaration1Context_cls = NULL;
    PyObject *Short_class_definitionContext_cls = NULL;
    PyObject *Equation_sectionContext_cls = NULL;
    PyObject *Algorithm_sectionContext_cls = NULL;
    PyObject *EquationContext_cls = NULL;
    PyObject *StatementContext_cls = NULL;
    PyObject *If_equationContext_cls = NULL;
    PyObject *If_statementContext_cls = NULL;
    PyObject *For_equationContext_cls = NULL;
    PyObject *For_statementContext_cls = NULL;
    PyObject *For_indicesContext_cls = NULL;
    PyObject *For_indexContext_cls = NULL;
    PyObject *While_statementContext_cls = NULL;
    PyObject *When_equationContext_cls = NULL;
    PyObject *When_statementContext_cls = NULL;
    PyObject *Connect_clauseContext_cls = NULL;
    PyObject *ExpressionContext_cls = NULL;
    PyObject *Simple_expressionContext_cls = NULL;
    PyObject *Logical_expressionContext_cls = NULL;
    PyObject *Logical_termContext_cls = NULL;
    PyObject *Logical_factorContext_cls = NULL;
    PyObject *RelationContext_cls = NULL;
    PyObject *Rel_opContext_cls = NULL;
    PyObject *Arithmetic_expressionContext_cls = NULL;
    PyObject *Add_opContext_cls = NULL;
    PyObject *TermContext_cls = NULL;
    PyObject *Mul_opContext_cls = NULL;
    PyObject *FactorContext_cls = NULL;
    PyObject *PrimaryContext_cls = NULL;
    PyObject *NameContext_cls = NULL;
    PyObject *Component_referenceContext_cls = NULL;
    PyObject *Function_call_argsContext_cls = NULL;
    PyObject *Function_argumentsContext_cls = NULL;
    PyObject *Named_argumentsContext_cls = NULL;
    PyObject *Named_argumentContext_cls = NULL;
    PyObject *Function_argumentContext_cls = NULL;
    PyObject *Output_expression_listContext_cls = NULL;
    PyObject *Expression_listContext_cls = NULL;
    PyObject *Array_subscriptsContext_cls = NULL;
    PyObject *SubscriptContext_cls = NULL;
    PyObject *CommentContext_cls = NULL;
    PyObject *String_commentContext_cls = NULL;
    PyObject *Model_annotationContext_cls = NULL;
    PyObject *AnnotationContext_cls = NULL;

    public:
    SA_modelicaTranslator(speedy_antlr::Translator *translator);
    ~SA_modelicaTranslator();
    antlrcpp::Any visitStored_definition(modelicaParser::Stored_definitionContext *ctx);

    antlrcpp::Any visitWithin_statement(modelicaParser::Within_statementContext *ctx);

    antlrcpp::Any visitClass_definition(modelicaParser::Class_definitionContext *ctx);

    antlrcpp::Any visitClass_specifier(modelicaParser::Class_specifierContext *ctx);

    antlrcpp::Any visitClass_prefixes(modelicaParser::Class_prefixesContext *ctx);

    antlrcpp::Any visitLong_class_specifier(modelicaParser::Long_class_specifierContext *ctx);

    antlrcpp::Any visitShort_class_specifier(modelicaParser::Short_class_specifierContext *ctx);

    antlrcpp::Any visitDer_class_specifier(modelicaParser::Der_class_specifierContext *ctx);

    antlrcpp::Any visitBase_prefix(modelicaParser::Base_prefixContext *ctx);

    antlrcpp::Any visitEnum_list(modelicaParser::Enum_listContext *ctx);

    antlrcpp::Any visitEnumeration_literal(modelicaParser::Enumeration_literalContext *ctx);

    antlrcpp::Any visitComposition(modelicaParser::CompositionContext *ctx);

    antlrcpp::Any visitLanguage_specification(modelicaParser::Language_specificationContext *ctx);

    antlrcpp::Any visitExternal_function_call(modelicaParser::External_function_callContext *ctx);

    antlrcpp::Any visitElement_list(modelicaParser::Element_listContext *ctx);

    antlrcpp::Any visitElement(modelicaParser::ElementContext *ctx);

    antlrcpp::Any visitImport_clause(modelicaParser::Import_clauseContext *ctx);

    antlrcpp::Any visitImport_list(modelicaParser::Import_listContext *ctx);

    antlrcpp::Any visitExtends_clause(modelicaParser::Extends_clauseContext *ctx);

    antlrcpp::Any visitConstraining_clause(modelicaParser::Constraining_clauseContext *ctx);

    antlrcpp::Any visitComponent_clause(modelicaParser::Component_clauseContext *ctx);

    antlrcpp::Any visitType_prefix_connector(modelicaParser::Type_prefix_connectorContext *ctx);

    antlrcpp::Any visitType_prefix_variability(modelicaParser::Type_prefix_variabilityContext *ctx);

    antlrcpp::Any visitType_prefix_io(modelicaParser::Type_prefix_ioContext *ctx);

    antlrcpp::Any visitType_specifier(modelicaParser::Type_specifierContext *ctx);

    antlrcpp::Any visitComponent_list(modelicaParser::Component_listContext *ctx);

    antlrcpp::Any visitComponent_declaration(modelicaParser::Component_declarationContext *ctx);

    antlrcpp::Any visitCondition_attribute(modelicaParser::Condition_attributeContext *ctx);

    antlrcpp::Any visitDeclaration(modelicaParser::DeclarationContext *ctx);

    antlrcpp::Any visitModification(modelicaParser::ModificationContext *ctx);

    antlrcpp::Any visitClass_modification(modelicaParser::Class_modificationContext *ctx);

    antlrcpp::Any visitArgument_list(modelicaParser::Argument_listContext *ctx);

    antlrcpp::Any visitArgument(modelicaParser::ArgumentContext *ctx);

    antlrcpp::Any visitElement_modification_or_replaceable(modelicaParser::Element_modification_or_replaceableContext *ctx);

    antlrcpp::Any visitElement_modification(modelicaParser::Element_modificationContext *ctx);

    antlrcpp::Any visitElement_redeclaration(modelicaParser::Element_redeclarationContext *ctx);

    antlrcpp::Any visitElement_replaceable(modelicaParser::Element_replaceableContext *ctx);

    antlrcpp::Any visitComponent_clause1(modelicaParser::Component_clause1Context *ctx);

    antlrcpp::Any visitComponent_declaration1(modelicaParser::Component_declaration1Context *ctx);

    antlrcpp::Any visitShort_class_definition(modelicaParser::Short_class_definitionContext *ctx);

    antlrcpp::Any visitEquation_section(modelicaParser::Equation_sectionContext *ctx);

    antlrcpp::Any visitAlgorithm_section(modelicaParser::Algorithm_sectionContext *ctx);

    antlrcpp::Any visitEquation(modelicaParser::EquationContext *ctx);

    antlrcpp::Any visitStatement(modelicaParser::StatementContext *ctx);

    antlrcpp::Any visitIf_equation(modelicaParser::If_equationContext *ctx);

    antlrcpp::Any visitIf_statement(modelicaParser::If_statementContext *ctx);

    antlrcpp::Any visitFor_equation(modelicaParser::For_equationContext *ctx);

    antlrcpp::Any visitFor_statement(modelicaParser::For_statementContext *ctx);

    antlrcpp::Any visitFor_indices(modelicaParser::For_indicesContext *ctx);

    antlrcpp::Any visitFor_index(modelicaParser::For_indexContext *ctx);

    antlrcpp::Any visitWhile_statement(modelicaParser::While_statementContext *ctx);

    antlrcpp::Any visitWhen_equation(modelicaParser::When_equationContext *ctx);

    antlrcpp::Any visitWhen_statement(modelicaParser::When_statementContext *ctx);

    antlrcpp::Any visitConnect_clause(modelicaParser::Connect_clauseContext *ctx);

    antlrcpp::Any visitExpression(modelicaParser::ExpressionContext *ctx);

    antlrcpp::Any visitSimple_expression(modelicaParser::Simple_expressionContext *ctx);

    antlrcpp::Any visitLogical_expression(modelicaParser::Logical_expressionContext *ctx);

    antlrcpp::Any visitLogical_term(modelicaParser::Logical_termContext *ctx);

    antlrcpp::Any visitLogical_factor(modelicaParser::Logical_factorContext *ctx);

    antlrcpp::Any visitRelation(modelicaParser::RelationContext *ctx);

    antlrcpp::Any visitRel_op(modelicaParser::Rel_opContext *ctx);

    antlrcpp::Any visitArithmetic_expression(modelicaParser::Arithmetic_expressionContext *ctx);

    antlrcpp::Any visitAdd_op(modelicaParser::Add_opContext *ctx);

    antlrcpp::Any visitTerm(modelicaParser::TermContext *ctx);

    antlrcpp::Any visitMul_op(modelicaParser::Mul_opContext *ctx);

    antlrcpp::Any visitFactor(modelicaParser::FactorContext *ctx);

    antlrcpp::Any visitPrimary(modelicaParser::PrimaryContext *ctx);

    antlrcpp::Any visitName(modelicaParser::NameContext *ctx);

    antlrcpp::Any visitComponent_reference(modelicaParser::Component_referenceContext *ctx);

    antlrcpp::Any visitFunction_call_args(modelicaParser::Function_call_argsContext *ctx);

    antlrcpp::Any visitFunction_arguments(modelicaParser::Function_argumentsContext *ctx);

    antlrcpp::Any visitNamed_arguments(modelicaParser::Named_argumentsContext *ctx);

    antlrcpp::Any visitNamed_argument(modelicaParser::Named_argumentContext *ctx);

    antlrcpp::Any visitFunction_argument(modelicaParser::Function_argumentContext *ctx);

    antlrcpp::Any visitOutput_expression_list(modelicaParser::Output_expression_listContext *ctx);

    antlrcpp::Any visitExpression_list(modelicaParser::Expression_listContext *ctx);

    antlrcpp::Any visitArray_subscripts(modelicaParser::Array_subscriptsContext *ctx);

    antlrcpp::Any visitSubscript(modelicaParser::SubscriptContext *ctx);

    antlrcpp::Any visitComment(modelicaParser::CommentContext *ctx);

    antlrcpp::Any visitString_comment(modelicaParser::String_commentContext *ctx);

    antlrcpp::Any visitModel_annotation(modelicaParser::Model_annotationContext *ctx);

    antlrcpp::Any visitAnnotation(modelicaParser::AnnotationContext *ctx);

};