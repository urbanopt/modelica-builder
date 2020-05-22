/*
 * This file was auto-generated by speedy-antlr-tool v1.0.0
 *  https://github.com/amykyta3/speedy-antlr-tool
 */

#include "sa_modelica_translator.h"


SA_modelicaTranslator::SA_modelicaTranslator(speedy_antlr::Translator *translator) {
    this->translator = translator;
}

SA_modelicaTranslator::~SA_modelicaTranslator() {
    Py_XDECREF(Stored_definitionContext_cls);
    Py_XDECREF(Within_statementContext_cls);
    Py_XDECREF(Class_definitionContext_cls);
    Py_XDECREF(Class_specifierContext_cls);
    Py_XDECREF(Class_prefixesContext_cls);
    Py_XDECREF(Long_class_specifierContext_cls);
    Py_XDECREF(Short_class_specifierContext_cls);
    Py_XDECREF(Der_class_specifierContext_cls);
    Py_XDECREF(Base_prefixContext_cls);
    Py_XDECREF(Enum_listContext_cls);
    Py_XDECREF(Enumeration_literalContext_cls);
    Py_XDECREF(CompositionContext_cls);
    Py_XDECREF(Language_specificationContext_cls);
    Py_XDECREF(External_function_callContext_cls);
    Py_XDECREF(Element_listContext_cls);
    Py_XDECREF(ElementContext_cls);
    Py_XDECREF(Import_clauseContext_cls);
    Py_XDECREF(Import_listContext_cls);
    Py_XDECREF(Extends_clauseContext_cls);
    Py_XDECREF(Constraining_clauseContext_cls);
    Py_XDECREF(Component_clauseContext_cls);
    Py_XDECREF(Type_prefix_connectorContext_cls);
    Py_XDECREF(Type_prefix_variabilityContext_cls);
    Py_XDECREF(Type_prefix_ioContext_cls);
    Py_XDECREF(Type_specifierContext_cls);
    Py_XDECREF(Component_listContext_cls);
    Py_XDECREF(Component_declarationContext_cls);
    Py_XDECREF(Condition_attributeContext_cls);
    Py_XDECREF(DeclarationContext_cls);
    Py_XDECREF(ModificationContext_cls);
    Py_XDECREF(Class_modificationContext_cls);
    Py_XDECREF(Argument_listContext_cls);
    Py_XDECREF(ArgumentContext_cls);
    Py_XDECREF(Element_modification_or_replaceableContext_cls);
    Py_XDECREF(Element_modificationContext_cls);
    Py_XDECREF(Element_redeclarationContext_cls);
    Py_XDECREF(Element_replaceableContext_cls);
    Py_XDECREF(Component_clause1Context_cls);
    Py_XDECREF(Component_declaration1Context_cls);
    Py_XDECREF(Short_class_definitionContext_cls);
    Py_XDECREF(Equation_sectionContext_cls);
    Py_XDECREF(Algorithm_sectionContext_cls);
    Py_XDECREF(EquationContext_cls);
    Py_XDECREF(StatementContext_cls);
    Py_XDECREF(If_equationContext_cls);
    Py_XDECREF(If_statementContext_cls);
    Py_XDECREF(For_equationContext_cls);
    Py_XDECREF(For_statementContext_cls);
    Py_XDECREF(For_indicesContext_cls);
    Py_XDECREF(For_indexContext_cls);
    Py_XDECREF(While_statementContext_cls);
    Py_XDECREF(When_equationContext_cls);
    Py_XDECREF(When_statementContext_cls);
    Py_XDECREF(Connect_clauseContext_cls);
    Py_XDECREF(ExpressionContext_cls);
    Py_XDECREF(Simple_expressionContext_cls);
    Py_XDECREF(Logical_expressionContext_cls);
    Py_XDECREF(Logical_termContext_cls);
    Py_XDECREF(Logical_factorContext_cls);
    Py_XDECREF(RelationContext_cls);
    Py_XDECREF(Rel_opContext_cls);
    Py_XDECREF(Arithmetic_expressionContext_cls);
    Py_XDECREF(Add_opContext_cls);
    Py_XDECREF(TermContext_cls);
    Py_XDECREF(Mul_opContext_cls);
    Py_XDECREF(FactorContext_cls);
    Py_XDECREF(PrimaryContext_cls);
    Py_XDECREF(NameContext_cls);
    Py_XDECREF(Component_referenceContext_cls);
    Py_XDECREF(Function_call_argsContext_cls);
    Py_XDECREF(Function_argumentsContext_cls);
    Py_XDECREF(Named_argumentsContext_cls);
    Py_XDECREF(Named_argumentContext_cls);
    Py_XDECREF(Function_argumentContext_cls);
    Py_XDECREF(Output_expression_listContext_cls);
    Py_XDECREF(Expression_listContext_cls);
    Py_XDECREF(Array_subscriptsContext_cls);
    Py_XDECREF(SubscriptContext_cls);
    Py_XDECREF(CommentContext_cls);
    Py_XDECREF(String_commentContext_cls);
    Py_XDECREF(Model_annotationContext_cls);
    Py_XDECREF(AnnotationContext_cls);
}


antlrcpp::Any SA_modelicaTranslator::visitStored_definition(modelicaParser::Stored_definitionContext *ctx){
    if(!Stored_definitionContext_cls) Stored_definitionContext_cls = PyObject_GetAttrString(translator->parser_cls, "Stored_definitionContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Stored_definitionContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitWithin_statement(modelicaParser::Within_statementContext *ctx){
    if(!Within_statementContext_cls) Within_statementContext_cls = PyObject_GetAttrString(translator->parser_cls, "Within_statementContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Within_statementContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitClass_definition(modelicaParser::Class_definitionContext *ctx){
    if(!Class_definitionContext_cls) Class_definitionContext_cls = PyObject_GetAttrString(translator->parser_cls, "Class_definitionContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Class_definitionContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitClass_specifier(modelicaParser::Class_specifierContext *ctx){
    if(!Class_specifierContext_cls) Class_specifierContext_cls = PyObject_GetAttrString(translator->parser_cls, "Class_specifierContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Class_specifierContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitClass_prefixes(modelicaParser::Class_prefixesContext *ctx){
    if(!Class_prefixesContext_cls) Class_prefixesContext_cls = PyObject_GetAttrString(translator->parser_cls, "Class_prefixesContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Class_prefixesContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitLong_class_specifier(modelicaParser::Long_class_specifierContext *ctx){
    if(!Long_class_specifierContext_cls) Long_class_specifierContext_cls = PyObject_GetAttrString(translator->parser_cls, "Long_class_specifierContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Long_class_specifierContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitShort_class_specifier(modelicaParser::Short_class_specifierContext *ctx){
    if(!Short_class_specifierContext_cls) Short_class_specifierContext_cls = PyObject_GetAttrString(translator->parser_cls, "Short_class_specifierContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Short_class_specifierContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitDer_class_specifier(modelicaParser::Der_class_specifierContext *ctx){
    if(!Der_class_specifierContext_cls) Der_class_specifierContext_cls = PyObject_GetAttrString(translator->parser_cls, "Der_class_specifierContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Der_class_specifierContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitBase_prefix(modelicaParser::Base_prefixContext *ctx){
    if(!Base_prefixContext_cls) Base_prefixContext_cls = PyObject_GetAttrString(translator->parser_cls, "Base_prefixContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Base_prefixContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitEnum_list(modelicaParser::Enum_listContext *ctx){
    if(!Enum_listContext_cls) Enum_listContext_cls = PyObject_GetAttrString(translator->parser_cls, "Enum_listContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Enum_listContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitEnumeration_literal(modelicaParser::Enumeration_literalContext *ctx){
    if(!Enumeration_literalContext_cls) Enumeration_literalContext_cls = PyObject_GetAttrString(translator->parser_cls, "Enumeration_literalContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Enumeration_literalContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitComposition(modelicaParser::CompositionContext *ctx){
    if(!CompositionContext_cls) CompositionContext_cls = PyObject_GetAttrString(translator->parser_cls, "CompositionContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, CompositionContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitLanguage_specification(modelicaParser::Language_specificationContext *ctx){
    if(!Language_specificationContext_cls) Language_specificationContext_cls = PyObject_GetAttrString(translator->parser_cls, "Language_specificationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Language_specificationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitExternal_function_call(modelicaParser::External_function_callContext *ctx){
    if(!External_function_callContext_cls) External_function_callContext_cls = PyObject_GetAttrString(translator->parser_cls, "External_function_callContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, External_function_callContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitElement_list(modelicaParser::Element_listContext *ctx){
    if(!Element_listContext_cls) Element_listContext_cls = PyObject_GetAttrString(translator->parser_cls, "Element_listContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Element_listContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitElement(modelicaParser::ElementContext *ctx){
    if(!ElementContext_cls) ElementContext_cls = PyObject_GetAttrString(translator->parser_cls, "ElementContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, ElementContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitImport_clause(modelicaParser::Import_clauseContext *ctx){
    if(!Import_clauseContext_cls) Import_clauseContext_cls = PyObject_GetAttrString(translator->parser_cls, "Import_clauseContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Import_clauseContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitImport_list(modelicaParser::Import_listContext *ctx){
    if(!Import_listContext_cls) Import_listContext_cls = PyObject_GetAttrString(translator->parser_cls, "Import_listContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Import_listContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitExtends_clause(modelicaParser::Extends_clauseContext *ctx){
    if(!Extends_clauseContext_cls) Extends_clauseContext_cls = PyObject_GetAttrString(translator->parser_cls, "Extends_clauseContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Extends_clauseContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitConstraining_clause(modelicaParser::Constraining_clauseContext *ctx){
    if(!Constraining_clauseContext_cls) Constraining_clauseContext_cls = PyObject_GetAttrString(translator->parser_cls, "Constraining_clauseContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Constraining_clauseContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitComponent_clause(modelicaParser::Component_clauseContext *ctx){
    if(!Component_clauseContext_cls) Component_clauseContext_cls = PyObject_GetAttrString(translator->parser_cls, "Component_clauseContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Component_clauseContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitType_prefix_connector(modelicaParser::Type_prefix_connectorContext *ctx){
    if(!Type_prefix_connectorContext_cls) Type_prefix_connectorContext_cls = PyObject_GetAttrString(translator->parser_cls, "Type_prefix_connectorContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Type_prefix_connectorContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitType_prefix_variability(modelicaParser::Type_prefix_variabilityContext *ctx){
    if(!Type_prefix_variabilityContext_cls) Type_prefix_variabilityContext_cls = PyObject_GetAttrString(translator->parser_cls, "Type_prefix_variabilityContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Type_prefix_variabilityContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitType_prefix_io(modelicaParser::Type_prefix_ioContext *ctx){
    if(!Type_prefix_ioContext_cls) Type_prefix_ioContext_cls = PyObject_GetAttrString(translator->parser_cls, "Type_prefix_ioContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Type_prefix_ioContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitType_specifier(modelicaParser::Type_specifierContext *ctx){
    if(!Type_specifierContext_cls) Type_specifierContext_cls = PyObject_GetAttrString(translator->parser_cls, "Type_specifierContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Type_specifierContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitComponent_list(modelicaParser::Component_listContext *ctx){
    if(!Component_listContext_cls) Component_listContext_cls = PyObject_GetAttrString(translator->parser_cls, "Component_listContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Component_listContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitComponent_declaration(modelicaParser::Component_declarationContext *ctx){
    if(!Component_declarationContext_cls) Component_declarationContext_cls = PyObject_GetAttrString(translator->parser_cls, "Component_declarationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Component_declarationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitCondition_attribute(modelicaParser::Condition_attributeContext *ctx){
    if(!Condition_attributeContext_cls) Condition_attributeContext_cls = PyObject_GetAttrString(translator->parser_cls, "Condition_attributeContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Condition_attributeContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitDeclaration(modelicaParser::DeclarationContext *ctx){
    if(!DeclarationContext_cls) DeclarationContext_cls = PyObject_GetAttrString(translator->parser_cls, "DeclarationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, DeclarationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitModification(modelicaParser::ModificationContext *ctx){
    if(!ModificationContext_cls) ModificationContext_cls = PyObject_GetAttrString(translator->parser_cls, "ModificationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, ModificationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitClass_modification(modelicaParser::Class_modificationContext *ctx){
    if(!Class_modificationContext_cls) Class_modificationContext_cls = PyObject_GetAttrString(translator->parser_cls, "Class_modificationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Class_modificationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitArgument_list(modelicaParser::Argument_listContext *ctx){
    if(!Argument_listContext_cls) Argument_listContext_cls = PyObject_GetAttrString(translator->parser_cls, "Argument_listContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Argument_listContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitArgument(modelicaParser::ArgumentContext *ctx){
    if(!ArgumentContext_cls) ArgumentContext_cls = PyObject_GetAttrString(translator->parser_cls, "ArgumentContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, ArgumentContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitElement_modification_or_replaceable(modelicaParser::Element_modification_or_replaceableContext *ctx){
    if(!Element_modification_or_replaceableContext_cls) Element_modification_or_replaceableContext_cls = PyObject_GetAttrString(translator->parser_cls, "Element_modification_or_replaceableContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Element_modification_or_replaceableContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitElement_modification(modelicaParser::Element_modificationContext *ctx){
    if(!Element_modificationContext_cls) Element_modificationContext_cls = PyObject_GetAttrString(translator->parser_cls, "Element_modificationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Element_modificationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitElement_redeclaration(modelicaParser::Element_redeclarationContext *ctx){
    if(!Element_redeclarationContext_cls) Element_redeclarationContext_cls = PyObject_GetAttrString(translator->parser_cls, "Element_redeclarationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Element_redeclarationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitElement_replaceable(modelicaParser::Element_replaceableContext *ctx){
    if(!Element_replaceableContext_cls) Element_replaceableContext_cls = PyObject_GetAttrString(translator->parser_cls, "Element_replaceableContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Element_replaceableContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitComponent_clause1(modelicaParser::Component_clause1Context *ctx){
    if(!Component_clause1Context_cls) Component_clause1Context_cls = PyObject_GetAttrString(translator->parser_cls, "Component_clause1Context");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Component_clause1Context_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitComponent_declaration1(modelicaParser::Component_declaration1Context *ctx){
    if(!Component_declaration1Context_cls) Component_declaration1Context_cls = PyObject_GetAttrString(translator->parser_cls, "Component_declaration1Context");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Component_declaration1Context_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitShort_class_definition(modelicaParser::Short_class_definitionContext *ctx){
    if(!Short_class_definitionContext_cls) Short_class_definitionContext_cls = PyObject_GetAttrString(translator->parser_cls, "Short_class_definitionContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Short_class_definitionContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitEquation_section(modelicaParser::Equation_sectionContext *ctx){
    if(!Equation_sectionContext_cls) Equation_sectionContext_cls = PyObject_GetAttrString(translator->parser_cls, "Equation_sectionContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Equation_sectionContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitAlgorithm_section(modelicaParser::Algorithm_sectionContext *ctx){
    if(!Algorithm_sectionContext_cls) Algorithm_sectionContext_cls = PyObject_GetAttrString(translator->parser_cls, "Algorithm_sectionContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Algorithm_sectionContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitEquation(modelicaParser::EquationContext *ctx){
    if(!EquationContext_cls) EquationContext_cls = PyObject_GetAttrString(translator->parser_cls, "EquationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, EquationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitStatement(modelicaParser::StatementContext *ctx){
    if(!StatementContext_cls) StatementContext_cls = PyObject_GetAttrString(translator->parser_cls, "StatementContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, StatementContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitIf_equation(modelicaParser::If_equationContext *ctx){
    if(!If_equationContext_cls) If_equationContext_cls = PyObject_GetAttrString(translator->parser_cls, "If_equationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, If_equationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitIf_statement(modelicaParser::If_statementContext *ctx){
    if(!If_statementContext_cls) If_statementContext_cls = PyObject_GetAttrString(translator->parser_cls, "If_statementContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, If_statementContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitFor_equation(modelicaParser::For_equationContext *ctx){
    if(!For_equationContext_cls) For_equationContext_cls = PyObject_GetAttrString(translator->parser_cls, "For_equationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, For_equationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitFor_statement(modelicaParser::For_statementContext *ctx){
    if(!For_statementContext_cls) For_statementContext_cls = PyObject_GetAttrString(translator->parser_cls, "For_statementContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, For_statementContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitFor_indices(modelicaParser::For_indicesContext *ctx){
    if(!For_indicesContext_cls) For_indicesContext_cls = PyObject_GetAttrString(translator->parser_cls, "For_indicesContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, For_indicesContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitFor_index(modelicaParser::For_indexContext *ctx){
    if(!For_indexContext_cls) For_indexContext_cls = PyObject_GetAttrString(translator->parser_cls, "For_indexContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, For_indexContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitWhile_statement(modelicaParser::While_statementContext *ctx){
    if(!While_statementContext_cls) While_statementContext_cls = PyObject_GetAttrString(translator->parser_cls, "While_statementContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, While_statementContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitWhen_equation(modelicaParser::When_equationContext *ctx){
    if(!When_equationContext_cls) When_equationContext_cls = PyObject_GetAttrString(translator->parser_cls, "When_equationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, When_equationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitWhen_statement(modelicaParser::When_statementContext *ctx){
    if(!When_statementContext_cls) When_statementContext_cls = PyObject_GetAttrString(translator->parser_cls, "When_statementContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, When_statementContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitConnect_clause(modelicaParser::Connect_clauseContext *ctx){
    if(!Connect_clauseContext_cls) Connect_clauseContext_cls = PyObject_GetAttrString(translator->parser_cls, "Connect_clauseContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Connect_clauseContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitExpression(modelicaParser::ExpressionContext *ctx){
    if(!ExpressionContext_cls) ExpressionContext_cls = PyObject_GetAttrString(translator->parser_cls, "ExpressionContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, ExpressionContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitSimple_expression(modelicaParser::Simple_expressionContext *ctx){
    if(!Simple_expressionContext_cls) Simple_expressionContext_cls = PyObject_GetAttrString(translator->parser_cls, "Simple_expressionContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Simple_expressionContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitLogical_expression(modelicaParser::Logical_expressionContext *ctx){
    if(!Logical_expressionContext_cls) Logical_expressionContext_cls = PyObject_GetAttrString(translator->parser_cls, "Logical_expressionContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Logical_expressionContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitLogical_term(modelicaParser::Logical_termContext *ctx){
    if(!Logical_termContext_cls) Logical_termContext_cls = PyObject_GetAttrString(translator->parser_cls, "Logical_termContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Logical_termContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitLogical_factor(modelicaParser::Logical_factorContext *ctx){
    if(!Logical_factorContext_cls) Logical_factorContext_cls = PyObject_GetAttrString(translator->parser_cls, "Logical_factorContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Logical_factorContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitRelation(modelicaParser::RelationContext *ctx){
    if(!RelationContext_cls) RelationContext_cls = PyObject_GetAttrString(translator->parser_cls, "RelationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, RelationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitRel_op(modelicaParser::Rel_opContext *ctx){
    if(!Rel_opContext_cls) Rel_opContext_cls = PyObject_GetAttrString(translator->parser_cls, "Rel_opContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Rel_opContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitArithmetic_expression(modelicaParser::Arithmetic_expressionContext *ctx){
    if(!Arithmetic_expressionContext_cls) Arithmetic_expressionContext_cls = PyObject_GetAttrString(translator->parser_cls, "Arithmetic_expressionContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Arithmetic_expressionContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitAdd_op(modelicaParser::Add_opContext *ctx){
    if(!Add_opContext_cls) Add_opContext_cls = PyObject_GetAttrString(translator->parser_cls, "Add_opContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Add_opContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitTerm(modelicaParser::TermContext *ctx){
    if(!TermContext_cls) TermContext_cls = PyObject_GetAttrString(translator->parser_cls, "TermContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, TermContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitMul_op(modelicaParser::Mul_opContext *ctx){
    if(!Mul_opContext_cls) Mul_opContext_cls = PyObject_GetAttrString(translator->parser_cls, "Mul_opContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Mul_opContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitFactor(modelicaParser::FactorContext *ctx){
    if(!FactorContext_cls) FactorContext_cls = PyObject_GetAttrString(translator->parser_cls, "FactorContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, FactorContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitPrimary(modelicaParser::PrimaryContext *ctx){
    if(!PrimaryContext_cls) PrimaryContext_cls = PyObject_GetAttrString(translator->parser_cls, "PrimaryContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, PrimaryContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitName(modelicaParser::NameContext *ctx){
    if(!NameContext_cls) NameContext_cls = PyObject_GetAttrString(translator->parser_cls, "NameContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, NameContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitComponent_reference(modelicaParser::Component_referenceContext *ctx){
    if(!Component_referenceContext_cls) Component_referenceContext_cls = PyObject_GetAttrString(translator->parser_cls, "Component_referenceContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Component_referenceContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitFunction_call_args(modelicaParser::Function_call_argsContext *ctx){
    if(!Function_call_argsContext_cls) Function_call_argsContext_cls = PyObject_GetAttrString(translator->parser_cls, "Function_call_argsContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Function_call_argsContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitFunction_arguments(modelicaParser::Function_argumentsContext *ctx){
    if(!Function_argumentsContext_cls) Function_argumentsContext_cls = PyObject_GetAttrString(translator->parser_cls, "Function_argumentsContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Function_argumentsContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitNamed_arguments(modelicaParser::Named_argumentsContext *ctx){
    if(!Named_argumentsContext_cls) Named_argumentsContext_cls = PyObject_GetAttrString(translator->parser_cls, "Named_argumentsContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Named_argumentsContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitNamed_argument(modelicaParser::Named_argumentContext *ctx){
    if(!Named_argumentContext_cls) Named_argumentContext_cls = PyObject_GetAttrString(translator->parser_cls, "Named_argumentContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Named_argumentContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitFunction_argument(modelicaParser::Function_argumentContext *ctx){
    if(!Function_argumentContext_cls) Function_argumentContext_cls = PyObject_GetAttrString(translator->parser_cls, "Function_argumentContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Function_argumentContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitOutput_expression_list(modelicaParser::Output_expression_listContext *ctx){
    if(!Output_expression_listContext_cls) Output_expression_listContext_cls = PyObject_GetAttrString(translator->parser_cls, "Output_expression_listContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Output_expression_listContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitExpression_list(modelicaParser::Expression_listContext *ctx){
    if(!Expression_listContext_cls) Expression_listContext_cls = PyObject_GetAttrString(translator->parser_cls, "Expression_listContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Expression_listContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitArray_subscripts(modelicaParser::Array_subscriptsContext *ctx){
    if(!Array_subscriptsContext_cls) Array_subscriptsContext_cls = PyObject_GetAttrString(translator->parser_cls, "Array_subscriptsContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Array_subscriptsContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitSubscript(modelicaParser::SubscriptContext *ctx){
    if(!SubscriptContext_cls) SubscriptContext_cls = PyObject_GetAttrString(translator->parser_cls, "SubscriptContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, SubscriptContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitComment(modelicaParser::CommentContext *ctx){
    if(!CommentContext_cls) CommentContext_cls = PyObject_GetAttrString(translator->parser_cls, "CommentContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, CommentContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitString_comment(modelicaParser::String_commentContext *ctx){
    if(!String_commentContext_cls) String_commentContext_cls = PyObject_GetAttrString(translator->parser_cls, "String_commentContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, String_commentContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitModel_annotation(modelicaParser::Model_annotationContext *ctx){
    if(!Model_annotationContext_cls) Model_annotationContext_cls = PyObject_GetAttrString(translator->parser_cls, "Model_annotationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, Model_annotationContext_cls);
    return py_ctx;
}

antlrcpp::Any SA_modelicaTranslator::visitAnnotation(modelicaParser::AnnotationContext *ctx){
    if(!AnnotationContext_cls) AnnotationContext_cls = PyObject_GetAttrString(translator->parser_cls, "AnnotationContext");
    PyObject *py_ctx = translator->convert_ctx(this, ctx, AnnotationContext_cls);
    return py_ctx;
}
