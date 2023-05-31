#ifndef __C_ECO_TOOLCHAIN_EMITTER_LLVMIR_VISITOR_H__
#define __C_ECO_TOOLCHAIN_EMITTER_LLVMIR_VISITOR_H__

#include "IEcoVisitor1.h"
#include "IEcoSystem1.h"
#include "IEcoToolchainAST1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoMap1.h"
#include "IEcoLog1.h"

#include "llvm-c/Core.h"

/* Struct that used as the result of emit for most functions */
typedef struct ScopedValue {
    /* Type of the value stored */
    LLVMTypeRef pType;

    /* Actual value. Can be nullptr for uninitialized variables */
    LLVMValueRef pVal;

    /* Pointer to value. Will be nullptr for RHS values. */
    LLVMValueRef pAlloca;
} ScopedValue;


/* Struct to manage ScopedValues lifetimes */
typedef struct Scope {
    /* map<char_t*, ScopedValue*> */
    IEcoMap1* namedVals;

    /* list<ScopedValue*> */
    IEcoList1* unnamedVals;
} Scope;

typedef struct StructFieldInfo {
    uint32_t idx;
    LLVMTypeRef type;
} StructFieldInfo;

typedef struct CEcoToolchainEmitterLLVMIR1Visitor {

    IEcoVisitor1VTbl* m_pVTblIVisitor;

    int16_t (*EmitArrayType)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1ArrayType* pIArrayType);
    int16_t (*EmitBinaryExpression)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BinaryExpression* pIBinaryExpression);
    int16_t (*EmitBlockDeclarations)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BlockDeclarations* pIBlockDeclarations);
    int16_t (*EmitBlockExpressions)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BlockExpressions* pIBlockExpressions);
    int16_t (*EmitBlockStatements)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BlockStatements* pIBlockStatements);
    int16_t (*EmitBlockTranslationUnitObject)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BlockTranslationUnitObjects* pIBlockTranslationUnitObjects);
    int16_t (*EmitBlockTypes)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BlockTypes* pIBlockTypes);
    int16_t (*EmitBreakStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BreakStatement* pIBreakStatement);
    int16_t (*EmitCaseStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1CaseStatement* pICaseStatement);
    int16_t (*EmitCastExpression)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1CastExpression* pICastExpression);
    int16_t (*EmitCharacterLiteral)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1CharacterLiteral* pICharacterLiteral);
    int16_t (*EmitCompoundStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1CompoundStatement* pICompoundStatement);
    int16_t (*EmitConditionalExpression)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1ConditionalExpression* pIConditionalExpression);
    int16_t (*EmitContinueStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1ContinueStatement* pIContinueStatement);
    int16_t (*EmitDeclaration)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1Declaration* pIDeclaration);
    int16_t (*EmitDefaultStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1DefaultStatement* pIDefaultStatement);
    int16_t (*EmitDoWhileStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1DoWhileStatement* pIDoWhileStatement);
    int16_t (*EmitEnumDeclaration)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1EnumDeclaration* pIEnumDeclaration);
    int16_t (*EmitEnumType)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1EnumType* pIEnumType);
    int16_t (*EmitExpression)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1Expression* pIExpression);
    int16_t (*EmitExpressionableDeclaration)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1ExpressionableDeclaration* pIExpressionableDeclaration);
    int16_t (*EmitFloatLiteral)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1FloatLiteral* pIFloatLiteral);
    int16_t (*EmitForStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1ForStatement* pIForStatement);
    int16_t (*EmitFunctionCall)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1FunctionCall* pIFunctionCall);
    int16_t (*EmitFunctionDeclaration)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1FunctionDeclaration* pIFunctionDeclaration);
    int16_t (*EmitFunctionDefinition)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1FunctionDefinition* pIFunctionDefinition);
    int16_t (*EmitFunctionType)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1FunctionType* pIFunctionType);
    int16_t (*EmitGlobalScope)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1GlobalScope* pIGlobalScope);
    int16_t (*EmitGoToStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1GoToStatement* pIGoToStatement);
    int16_t (*EmitIfStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1IfStatement* pIIfStatement);
    int16_t (*EmitIntegerLiteral)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1IntegerLiteral* pIIntegerLiteral);
    int16_t (*EmitLabelStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1LabelStatement* pILabelStatement);
    int16_t (*EmitLiteral)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1Literal* pILiteral);
    int16_t (*EmitMemberSelection)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1MemberSelection* pIMemberSelection);
    int16_t (*EmitNullExpression)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1NullExpression* pINullExpression);
    int16_t (*EmitNumberType)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1NumberType* pINumberTypev);
    int16_t (*EmitPointerType)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1PointerType* pIPointerType);
    int16_t (*EmitReturnStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1ReturnStatement* pIReturnStatement);
    int16_t (*EmitScope)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1Scope* pIScope);
    int16_t (*EmitSingleStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1SingleStatement* pISingleStatement);
    int16_t (*EmitSizeofExpression)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1SizeofExpression* pISizeofExpression);
    int16_t (*EmitSizeofType)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1SizeofType* pISizeofType);
    int16_t (*EmitStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1Statement* pIStatement);
    int16_t (*EmitStringLiteral)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1StringLiteral* pIStringLiteral);
    int16_t (*EmitStructOrUnionDeclaration)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1StructOrUnionDeclaration* pIStructOrUnionDeclaration);
    int16_t (*EmitStructOrUnionType)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1StructOrUnionType* pIStructOrUnionType);
    int16_t (*EmitSwitchStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1SwitchStatement* pISwitchStatement);
    int16_t (*EmitSyntaxObject)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1SyntaxObject* pISyntaxObject);
    int16_t (*EmitTranslationUnit)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1TranslationUnit* pITranslationUnit);
    int16_t (*EmitTranslationUnitObject)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1TranslationUnitObject* pITranslationUnitObject);
    int16_t (*EmitTypedefDeclaration)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1TypedefDeclaration* pITypedefDeclaration);
    int16_t (*EmitTypedefType)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1TypedefType* pITypedefType);
    int16_t (*EmitUnaryExpression)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1UnaryExpression* pIUnaryExpression);
    int16_t (*EmitVariableDeclaration)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1VariableDeclaration* pIVariableDeclaration);
    int16_t (*EmitVariableDefinition)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1VariableDefinition* pIVariableDefinition);
    int16_t (*EmitWhileStatement)(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1WhileStatement* pIWhileStatement);

    LLVMModuleRef (*get_Module)(/* in */ struct IEcoVisitor1* me);


    /* Scope-related function group
     * 
     * Each scope contains map of named values(map<char_t*, ScopedValue*>)
     *      and list of unnamed values.
     * 
     * When we enter new scope (e.g. function) ScopeNext() called 
     *      and all ScopedValues created via CreateNamedValue()/CreateUnnamedValue() will get into this scope
     * 
     * When scope ends, ScopePrev() called and all ScopedValues are freed automatically
     */

    /* 
     * Creates new unnamed scoped value.
     * In some cases allocaVal can be non null, but in most cases this function is used to create RHS values, so often allocaVal == 0
     */
    ScopedValue* (*CreateUnnamedValue)(/* in */ struct IEcoVisitor1* me, /* in */ LLVMValueRef val,
                                       /* in */ LLVMTypeRef type, /* in */ LLVMValueRef allocaVal);

    /*
     * Creates new named scoped value.
     */
    ScopedValue* (*CreateNamedValue)(/* in */ struct IEcoVisitor1* me, 
                                     /* in */ char_t* name, /* in */ LLVMValueRef val,
                                     /* in */ LLVMTypeRef type, /* in */ LLVMValueRef allocaVal);

    void (*ScopeNext)(/* in */ struct IEcoVisitor1* me);
    void (*ScopePrev)(/* in */ struct IEcoVisitor1* me);
    void (*ScopeAddNamed)(/* in */ struct IEcoVisitor1* me, /* in */ char_t* name, /* in */ ScopedValue* val);
    void (*ScopeAddUnnamed)(/* in */ struct IEcoVisitor1* me, /* in */ ScopedValue* val);
    ScopedValue* (*ScopeGetNamed)(/* in */ struct IEcoVisitor1* me, /* in */ char_t* name);


    /* Group of functions related to structs.
     * Need to map field identifiers to indexes
     */
    void (*AddStruct)(/* in */ struct IEcoVisitor1* me, /* in */ char_t* structName);
    void (*SetStructFieldInfo)(/* in */ struct IEcoVisitor1* me, 
                               /* in */ char_t* structName, /* in */ char_t* fieldName,
                               /* in */ uint32_t fieldIdx, /* in */ LLVMTypeRef fieldType);
    StructFieldInfo* (*GetStructFieldInfo)(/* in */ struct IEcoVisitor1* me, /* in */ char_t* structName, /* in */ char_t* fieldName);

    /* List of scopes, each scope contains named and unnamed values associated with that scope */
    IEcoList1* m_scopesList;
    uint32_t m_scopeNumber;

    /* LLVM-related */
    LLVMModuleRef m_pLLVMModule;
    LLVMBuilderRef m_pBuilder;
    LLVMContextRef m_pContext;

    /* ������� ������ */
    uint32_t m_cRef;

    /* ��������� ��� ������ � ������� */
    IEcoSystem1* m_pISys;
    IEcoMemoryAllocator1* m_pIMem;
    void* m_pRetVal;

    /* For debug */
    IEcoLog1* m_log;

    /* To handle struct field names */
    IEcoMap1* m_structsFieldsMap;

} CEcoToolchainEmitterLLVMIR1Visitor, * CEcoToolchainEmitterLLVMIR1VisitorPtr;

/* �������� ���������� */
int16_t createCEcoToolchainEmitterLLVMIR1Visitor(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoVisitor1** ppIVisitor);
/* �������� */
void deleteCEcoToolchainEmitterLLVMIR1Visitor(/* in */ IEcoVisitor1* pIVisitor);

#endif /* __C_ECO_TOOLCHAIN_EMITTER_LLVMIR_VISITOR_H__ */
