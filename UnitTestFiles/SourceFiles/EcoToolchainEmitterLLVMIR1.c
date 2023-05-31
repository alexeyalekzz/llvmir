/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoToolchainEmitterLLVMIR1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoToolchainEmitterLLVMIR1.h"
#include "IdEcoString1.h"
#include "IdEcoToolchainAST1.h"
#include "IdEcoTree1.h"
#include "IdEcoDictionary1.h"
#include "IdEcoMap1.h"
#include "IdEcoSet1.h"
#include "IdEcoVisitor1.h"
#include "IdEcoComparator1.h"

#include "IdEcoLog1.h"
#include "IEcoLog1FileAffiliate.h"
#include "IdEcoList1.h"

FILE* _iob;
FILE* __cdecl __iob_func(void) { return _iob; }


bool_t ECOCALLMETHOD FillFactorialAST(IEcoToolchainAST1* pIAST, IEcoInterfaceBus1* pIBus);

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t ECOCALLMETHOD EcoMain(IEcoUnknown* pIUnk) {
    FILE iob[] = { *stdin, *stdout, *stderr };
    _iob = iob;

    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoToolchainEmitterLLVMIR1* pIEcoToolchainEmitterLLVMIR1 = 0;
    IEcoToolchainAST1* pIAST = 0;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoToolchainEmitterLLVMIR1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_C5CCED1755D74106A5F315694AC2C99F);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoToolchainAST1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_2FE0BD508F5743BDA9F52414233542A8);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoString1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_84CC0A7DBABD44EEBE749C9A8312D37E);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoList1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_53884AFC93C448ECAA929C8D3A562281);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы со словарем */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoDictionary1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_2912A7C7E0B84B4D9BFE9500EF4667D3);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с деревом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoTree1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_82F73722057E47F3A2931ED27087694D);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с журналом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLog1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_97322B6765B74342BBCE38798A0B40B5);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с ассоциированным масивом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoMap1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_0D7907DBE1C14B9E9B9FD9E8D9E251DF);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoSet1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_7750135D34D7461897B912F7CC615F72);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoVisitor1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_4E7C20FEFAF341069B5C42497B462BBE);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoComparator1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_C7ED3BA4B6EB4385BBDB3C6AC5C7A394);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса для работы с AST*/
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoToolchainAST1, 0, &IID_IEcoToolchainAST1, (void**)&pIAST);
    if (result != 0 || pIAST == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoToolchainEmitterLLVMIR1, 0, &IID_IEcoToolchainEmitterLLVMIR1, (void**) &pIEcoToolchainEmitterLLVMIR1);
    if (result != 0 || pIEcoToolchainEmitterLLVMIR1 == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    FillFactorialAST(pIAST, pIBus);

    pISyntaxObject = (IEcoToolchainAST1SyntaxObject*)pIAST->pVTbl->get_TranslationUnit(pIAST);
    if (pISyntaxObject == 0) {
        goto Release;
    }

    result = pIEcoToolchainEmitterLLVMIR1->pVTbl->EmitCode(pIEcoToolchainEmitterLLVMIR1, pISyntaxObject);
    if (result != 0) {
        goto Release;
    }

    result = pIEcoToolchainEmitterLLVMIR1->pVTbl->WriteIRFile(pIEcoToolchainEmitterLLVMIR1, "out.ll");
    result = pIEcoToolchainEmitterLLVMIR1->pVTbl->WriteObjectFile(pIEcoToolchainEmitterLLVMIR1, "out.obj", OptLevelDefault);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoToolchainEmitterLLVMIR1 != 0) {
        pIEcoToolchainEmitterLLVMIR1->pVTbl->Release(pIEcoToolchainEmitterLLVMIR1);
    }

    if (pIAST != 0) {
        pIAST->pVTbl->Release(pIAST);
    }

    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}


bool_t ECOCALLMETHOD FillFactorialAST(IEcoToolchainAST1* pIAST, IEcoInterfaceBus1* pIBus) {
    IEcoToolchainAST1StringLiteral* pIStringLiteral = 0;
    IEcoToolchainAST1BlockExpressions* pIFuncParams = 0;
    IEcoToolchainAST1FunctionCall* pIFunctionCall = 0;
    IEcoToolchainAST1IntegerLiteral* pIZeroLiteral = 0;
    IEcoToolchainAST1ReturnStatement* pIReturn = 0;
    IEcoToolchainAST1NumberType* pIReturnType = 0;
    IEcoToolchainAST1FunctionType* pIFunctionType = 0;
    IEcoToolchainAST1BlockDeclarations* pIDeclarations = 0;
    IEcoToolchainAST1BlockTranslationUnitObjects* pIObjects = 0;
    IEcoToolchainAST1BlockStatements* pIStatements = 0;
    IEcoToolchainAST1CompoundStatement* pIBody = 0;
    IEcoToolchainAST1BlockDeclarations* pIFuncParamDecs = 0;
    IEcoToolchainAST1FunctionDeclaration* pIFuncDeclaration = 0;
    IEcoToolchainAST1GlobalScope* pIGlobalScope = 0;
    IEcoToolchainAST1NumberType* pICharType = 0;
    IEcoToolchainAST1PointerType* pIPointerType = 0;
    IEcoToolchainAST1BlockTypes* pIParamsTypes = 0;
    IEcoToolchainAST1NullExpression* pINullExp = 0;
    IEcoToolchainAST1VariableDeclaration* pIDecl = 0;
    IEcoToolchainAST1FunctionDeclaration* pIPrintfDec = 0;
    IEcoToolchainAST1TranslationUnit* pITranslationUnit = 0;
    IEcoToolchainAST1VariableDefinition* pIPrintfDef = 0;
    IEcoToolchainAST1Scope* pIPrintfDecScope = 0; 
    IEcoToolchainAST1FunctionDefinition* pIFuncDefinition = 0;
    IEcoToolchainAST1IntegerLiteral* pZeroLiteral = 0;
    IEcoToolchainAST1IntegerLiteral* pTenLiteral = 0;
    IEcoToolchainAST1Scope* pIMainDecScope = 0;
    IEcoToolchainAST1IfStatement* pIfStmt = 0;
    IEcoToolchainAST1BinaryExpression* pResAssignOne = 0;
    IEcoToolchainAST1BinaryExpression* pResAssignNMullCall = 0;
    IEcoToolchainAST1Scope* pIMainDefScope = 0;
    IEcoToolchainAST1NumberType* pNumType = 0;
    IEcoToolchainAST1VariableDeclaration* pVarIDecl = 0;
    IEcoToolchainAST1VariableDefinition* pVarIDef = 0;
    IEcoToolchainAST1VariableDeclaration* pVarResDecl = 0;
    IEcoToolchainAST1VariableDefinition* pVarResDef = 0;
    IEcoToolchainAST1VariableDefinition* pNDef = 0;
    IEcoToolchainAST1FunctionDefinition* pFactorialDef = 0;
    IEcoToolchainAST1BinaryExpression* pCondBinop = 0;
    IEcoToolchainAST1BinaryExpression* pIterExpr = 0;
    IEcoToolchainAST1BinaryExpression* pNLessTwo = 0;
    IEcoToolchainAST1ForStatement* pForStmt = 0;
    IEcoToolchainAST1CompoundStatement* pTrueStmts = 0;
    IEcoToolchainAST1CompoundStatement* pFalseStmts = 0;
    IEcoToolchainAST1CompoundStatement* pForBodyCompoundStmt = 0;
    IEcoToolchainAST1CompoundStatement* pFactorialBody = 0;
    IEcoToolchainAST1Scope* pForScope = 0;
    IEcoToolchainAST1Scope* pIScope = 0;
    IEcoToolchainAST1BinaryExpression* pResAssignCall = 0;
    IEcoToolchainAST1BinaryExpression* pBinexprNMulCall = 0;
    IEcoToolchainAST1BinaryExpression* pNSubOneBinexpr = 0;
    IEcoToolchainAST1FunctionCall* pFactorialCall = 0;
    IEcoToolchainAST1FunctionDeclaration* pFactorialDecl = 0;
    IEcoToolchainAST1NumberType* pIIntType = 0;
    IEcoToolchainAST1Scope* pIFactorialDecScope = 0;
    IEcoToolchainAST1Scope* pIFactorialDefScope = 0;
    IEcoToolchainAST1IntegerLiteral* pTwoLiteral = 0;
    IEcoToolchainAST1IntegerLiteral* pOneLiteral = 0;
    IEcoToolchainAST1FunctionCall* pFactortialCall1 = 0;
    IEcoToolchainAST1BlockExpressions* pFactortialCall1Args = 0;
    IEcoToolchainAST1BlockExpressions* pArgsBlockExprs = 0;
    IEcoToolchainAST1BlockStatements* pBlockStmts = 0;
    IEcoToolchainAST1VariableDefinition* pFactorialVarDef = 0;
    IEcoToolchainAST1BlockStatements* pForBodyBlkStmts = 0;
    IEcoToolchainAST1VariableDeclaration* pResultVarDecl = 0;
    IEcoToolchainAST1VariableDefinition* pResVarDef = 0;
    IEcoToolchainAST1ReturnStatement* pFactorialReturnStmt = 0;
    IEcoList1* pIFuncParamsList = 0;
    IEcoList1* pITypeList = 0;
    IEcoList1* pIDecList = 0;
    IEcoList1* pIStmtsList = 0;
    IEcoList1* pIForBodyStmtsList = 0;
    IEcoList1* argsExprsList = 0;
    IEcoList1* pExprList = 0;
    IEcoList1* pMainDeclsList = 0;
    IEcoList1* pFactorialDeclsList = 0;
    int16_t result = 0;


    /* Пример:
    * int printf(char*, ...);
    * 
    * int factorial(int n) {
    *   int result = 0;
    *   if (n < 2) {
    *       result = 1;
    *   } else {
    *       result = n * factorial(n - 1);
    *   }
    *   return result;
    * }
    * 
    * int main() {
    *   int i = 0;
    *   int res;
    *   for (; i < 10; ++i) {
    *       res = factorial(i);
    *       printf("%d\n", res);
    *   }
    *   return 0;
    * }
    */

    /* Global scope */
    pIAST->pVTbl->new_GlobalScope(pIAST, 0, &pIGlobalScope);

    /* int printf(const char* format, ...);*/
    pIAST->pVTbl->new_NumberType(pIAST, 0, ECO_TOOLCHAIN_AST1_TYPE_INT, 32, 0, 1, 0, &pIReturnType);         // int
    pIAST->pVTbl->new_NumberType(pIAST, 0, ECO_TOOLCHAIN_AST1_TYPE_CHAR, 8, 0, 0, 0, &pICharType);           // char
    pIAST->pVTbl->new_PointerType(pIAST, 0, (IEcoToolchainAST1Type*)pICharType, 1, &pIPointerType);          // char*
    pIAST->pVTbl->new_VariableDeclaration(pIAST, 0, (IEcoToolchainAST1Type*)pIPointerType, "s", 0, &pIDecl); // char* s
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIDecList);
    pIDecList->pVTbl->Add(pIDecList, pIDecl);
    pIAST->pVTbl->new_BlockDeclarations(pIAST, 0, pIDecList, &pIDeclarations);
    pIAST->pVTbl->new_Scope(pIAST, 0, (IEcoToolchainAST1Scope*)pIGlobalScope, &pIPrintfDecScope);
    pIPrintfDecScope->pVTbl->RegistDeclaration(pIPrintfDecScope, (IEcoToolchainAST1Declaration*)pIDecl);
    pIAST->pVTbl->new_FunctionType(pIAST, 0, (IEcoToolchainAST1Type*)pIReturnType, pIDeclarations, pIPrintfDecScope, 1, &pIFunctionType);
    pIAST->pVTbl->new_FunctionDeclaration(pIAST, 0, pIFunctionType, "printf", &pIPrintfDec);

    /* int factorial(int n); */
    pIAST->pVTbl->new_NumberType(pIAST, 0, ECO_TOOLCHAIN_AST1_TYPE_INT, 32, 0, 1, 0, &pIReturnType);        // int

    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIDecList);
    pIAST->pVTbl->new_NumberType(pIAST, 0, ECO_TOOLCHAIN_AST1_TYPE_INT, 32, 0, 1, 0, &pIIntType);           // int
    pIAST->pVTbl->new_VariableDeclaration(pIAST, 0, (IEcoToolchainAST1Type*)pIIntType, "n", 0, &pIDecl);    // int n
    pIDecList->pVTbl->Add(pIDecList, pIDecl);

    pIAST->pVTbl->new_BlockDeclarations(pIAST, 0, pIDecList, &pIDeclarations);
    pIAST->pVTbl->new_Scope(pIAST, 0, (IEcoToolchainAST1Scope*)pIGlobalScope, &pIFactorialDecScope);
    pIAST->pVTbl->new_Scope(pIAST, 0, pIFactorialDecScope, &pIFactorialDefScope);
    pIFactorialDecScope->pVTbl->RegistDeclaration(pIFactorialDecScope, pIDecl);

    pIAST->pVTbl->new_FunctionType(pIAST, 0, pIReturnType, pIDeclarations, pIFactorialDecScope, 0, &pIFunctionType); // int(int)
    pIAST->pVTbl->new_FunctionDeclaration(pIAST, 0, pIFunctionType, "factorial", &pFactorialDecl);                   // int factorial(int n);

    /* int result = 0; */
    pIAST->pVTbl->new_NumberType(pIAST, 0, ECO_TOOLCHAIN_AST1_TYPE_INT, 32, 0, 1, 0, &pNumType);
    pIAST->pVTbl->new_IntegerLiteral(pIAST, 0, "0", &pZeroLiteral);
    pIAST->pVTbl->new_VariableDeclaration(pIAST, 0, pNumType, "result", pZeroLiteral, &pResultVarDecl);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pFactorialDeclsList);
    pFactorialDeclsList->pVTbl->Add(pFactorialDeclsList, pResultVarDecl);
    pIFactorialDefScope->pVTbl->RegistDeclaration(pIFactorialDefScope, pResultVarDecl);

    /* n < 2 */
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pIDecl, &pNDef);
    pIAST->pVTbl->new_IntegerLiteral(pIAST, 0, "2", &pTwoLiteral);
    pIAST->pVTbl->new_BinaryExpression(pIAST, 0, ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_LESS, pNDef, pTwoLiteral, &pNLessTwo);

    /* result = 1; */
    pIAST->pVTbl->new_IntegerLiteral(pIAST, 0, "1", &pOneLiteral);
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pResultVarDecl, &pResVarDef);
    pIAST->pVTbl->new_BinaryExpression(pIAST, 0, ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_ASSIGN, pResVarDef, pOneLiteral, &pResAssignOne);

    /* result = n * factorial(n - 1); */
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pIDecl, &pNDef);
    pIAST->pVTbl->new_IntegerLiteral(pIAST, 0, "1", &pOneLiteral);
    pIAST->pVTbl->new_BinaryExpression(pIAST, 0, ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_SUBTRACT, pNDef, pOneLiteral, &pNSubOneBinexpr);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&argsExprsList);
    argsExprsList->pVTbl->Add(argsExprsList, pNSubOneBinexpr);

    pIAST->pVTbl->new_BlockExpressions(pIAST, 0, argsExprsList, &pFactortialCall1Args);
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pFactorialDecl, &pFactorialVarDef);
    pIAST->pVTbl->new_FunctionCall(pIAST, 0, pFactorialVarDef, pFactortialCall1Args, &pFactortialCall1);
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pIDecl, &pNDef);
    pIAST->pVTbl->new_BinaryExpression(pIAST, 0, ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_MULTIPLY, pNDef, pFactortialCall1, &pBinexprNMulCall);
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pResultVarDecl, &pResVarDef);
    pIAST->pVTbl->new_BinaryExpression(pIAST, 0, ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_ASSIGN, pResVarDef, pBinexprNMulCall, &pResAssignNMullCall);

    /* if (n < 2) {...} else {...} */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIStmtsList);
    pIStmtsList->pVTbl->Add(pIStmtsList, pResAssignOne);
    pIAST->pVTbl->new_BlockStatements(pIAST, 0, pIStmtsList, &pBlockStmts);
    pIAST->pVTbl->new_Scope(pIAST, 0, pIFactorialDefScope, &pIScope);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIDecList);
    pIAST->pVTbl->new_BlockDeclarations(pIAST, 0, pIDecList, &pIDeclarations);
    pIAST->pVTbl->new_CompoundStatement(pIAST, 0, pIDeclarations, pBlockStmts, pIScope, &pTrueStmts);

    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIStmtsList);
    pIStmtsList->pVTbl->Add(pIStmtsList, pResAssignNMullCall);
    pIAST->pVTbl->new_BlockStatements(pIAST, 0, pIStmtsList, &pBlockStmts);
    pIAST->pVTbl->new_Scope(pIAST, 0, pIFactorialDefScope, &pIScope);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIDecList);
    pIAST->pVTbl->new_BlockDeclarations(pIAST, 0, pIDecList, &pIDeclarations);
    pIAST->pVTbl->new_CompoundStatement(pIAST, 0, pIDeclarations, pBlockStmts, pIScope, &pFalseStmts);

    pIAST->pVTbl->new_IfStatement(pIAST, 0, pNLessTwo, pTrueStmts, pFalseStmts, &pIfStmt);

    /* return result; */
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pResultVarDecl, &pResVarDef);
    pIAST->pVTbl->new_ReturnStatement(pIAST, 0, pResVarDef, &pFactorialReturnStmt);

    /* factorial(...) {...} */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIStmtsList);
    pIStmtsList->pVTbl->Add(pIStmtsList, pIfStmt);
    pIStmtsList->pVTbl->Add(pIStmtsList, pFactorialReturnStmt);
    pIAST->pVTbl->new_BlockStatements(pIAST, 0, pIStmtsList, &pBlockStmts);
    pIAST->pVTbl->new_BlockDeclarations(pIAST, 0, pFactorialDeclsList, &pIDeclarations);
    pIAST->pVTbl->new_CompoundStatement(pIAST, 0, pIDeclarations, pBlockStmts, pIFactorialDefScope, &pFactorialBody);
    pIAST->pVTbl->new_FunctionDefinition(pIAST, 0, pFactorialDecl, pFactorialBody, &pFactorialDef);
    pIGlobalScope->pVTbl->RegistFunctionDefinition(pIGlobalScope, pFactorialDef);

    /* int main() */
    pIAST->pVTbl->new_NumberType(pIAST, 0, ECO_TOOLCHAIN_AST1_TYPE_INT, 32, 0, 1, 0, &pIReturnType);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIDecList);
    pIAST->pVTbl->new_BlockDeclarations(pIAST, 0, pIDecList, &pIDeclarations);
    pIAST->pVTbl->new_Scope(pIAST, 0, (IEcoToolchainAST1Scope*)pIGlobalScope, &pIMainDecScope);
    pIAST->pVTbl->new_Scope(pIAST, 0, pIMainDecScope, &pIMainDefScope);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIStmtsList);

    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pMainDeclsList);

    /* int i = 0; */
    pIAST->pVTbl->new_NumberType(pIAST, 0, ECO_TOOLCHAIN_AST1_TYPE_INT, 32, 0, 1, 0, &pNumType);
    pIAST->pVTbl->new_IntegerLiteral(pIAST, 0, "0", &pZeroLiteral);
    pIAST->pVTbl->new_VariableDeclaration(pIAST, 0, pNumType, "i", pZeroLiteral, &pVarIDecl);
    pMainDeclsList->pVTbl->Add(pMainDeclsList, pVarIDecl);

    /* int res; */
    pIAST->pVTbl->new_NumberType(pIAST, 0, ECO_TOOLCHAIN_AST1_TYPE_INT, 32, 0, 1, 0, &pNumType);
    pIAST->pVTbl->new_VariableDeclaration(pIAST, 0, pNumType, "res", 0, &pVarResDecl);
    pMainDeclsList->pVTbl->Add(pMainDeclsList, pVarResDecl);

    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIForBodyStmtsList);

    /* res = factorial(i); */
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pVarResDecl, &pVarResDef);
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pVarIDecl, &pVarIDef);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pExprList);
    pExprList->pVTbl->Add(pExprList, pVarIDef);
    pIAST->pVTbl->new_BlockExpressions(pIAST, 0, pExprList, &pArgsBlockExprs);
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pFactorialDecl, &pFactorialVarDef);
    pIAST->pVTbl->new_FunctionCall(pIAST, 0, pFactorialVarDef, pArgsBlockExprs, &pFactorialCall);
    pIAST->pVTbl->new_BinaryExpression(pIAST, 0, ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_ASSIGN, pVarResDef, pFactorialCall, &pResAssignCall);
    pIForBodyStmtsList->pVTbl->Add(pIForBodyStmtsList, pResAssignCall);

    // printf("%d\n", res);
    pIAST->pVTbl->new_StringLiteral(pIAST, 0, "%d\\n", &pIStringLiteral);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIFuncParamsList);
    pIFuncParamsList->pVTbl->Add(pIFuncParamsList, pIStringLiteral);
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pVarResDecl, &pVarResDef);
    pIFuncParamsList->pVTbl->Add(pIFuncParamsList, pVarResDef);

    pIAST->pVTbl->new_BlockExpressions(pIAST, 0, pIFuncParamsList, &pIFuncParams);
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, (IEcoToolchainAST1ExpressionableDeclaration*)pIPrintfDec, &pIPrintfDef);
    pIAST->pVTbl->new_FunctionCall(pIAST, 0, (IEcoToolchainAST1Expression*)pIPrintfDef, pIFuncParams, &pIFunctionCall);
    pIForBodyStmtsList->pVTbl->Add(pIForBodyStmtsList, pIFunctionCall);

    /* for (...) {...} */
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pVarIDecl, &pVarIDef);
    pIAST->pVTbl->new_IntegerLiteral(pIAST, 0, "10", &pTenLiteral);
    pIAST->pVTbl->new_BinaryExpression(pIAST, 0, ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_LESS, pVarIDef, pTenLiteral, &pCondBinop);
    pIAST->pVTbl->new_VariableDefinition(pIAST, 0, pVarIDecl, &pVarIDef);
    pIAST->pVTbl->new_UnaryExpression(pIAST, 0, ECO_TOOLCHAIN_AST1_UNARY_OPERATOR_POSTFIX_INC, pVarIDef, &pIterExpr);
    pIAST->pVTbl->new_Scope(pIAST, 0, pIMainDefScope, &pForScope);
    pIAST->pVTbl->new_BlockStatements(pIAST, 0, pIForBodyStmtsList, &pForBodyBlkStmts);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIDecList);
    pIAST->pVTbl->new_BlockDeclarations(pIAST, 0, pIDecList, &pIDeclarations);
    pIAST->pVTbl->new_CompoundStatement(pIAST, 0, pIDeclarations, pForBodyBlkStmts, pForScope, &pForBodyCompoundStmt);
    pIAST->pVTbl->new_ForStatement(pIAST, 0, 0, pCondBinop, pIterExpr, pForBodyCompoundStmt, &pForStmt);
    pIStmtsList->pVTbl->Add(pIStmtsList, pForStmt);

    // return 0;
    pIAST->pVTbl->new_IntegerLiteral(pIAST, 0, "0", &pIZeroLiteral);
    pIAST->pVTbl->new_ReturnStatement(pIAST, 0, (IEcoToolchainAST1Expression*)pIZeroLiteral, &pIReturn);
    pIStmtsList->pVTbl->Add(pIStmtsList, pIReturn);

    /* int main() { ... } */
    pIAST->pVTbl->new_BlockStatements(pIAST, 0, pIStmtsList, &pIStatements);
    pIAST->pVTbl->new_BlockDeclarations(pIAST, 0, pMainDeclsList, &pIDeclarations);
    pIMainDefScope->pVTbl->RegistDeclaration(pIMainDefScope, pVarResDecl);
    pIMainDefScope->pVTbl->RegistDeclaration(pIMainDefScope, pVarIDecl);
    pIAST->pVTbl->new_CompoundStatement(pIAST, 0, pIDeclarations, pIStatements, pIMainDefScope, &pIBody);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIDecList);
    pIAST->pVTbl->new_BlockDeclarations(pIAST, 0, pIDecList, &pIFuncParamDecs);
    pIAST->pVTbl->new_FunctionType(pIAST, 0, (IEcoToolchainAST1Type*)pIReturnType, pIFuncParamDecs, pIMainDecScope, 0, &pIFunctionType);
    pIAST->pVTbl->new_FunctionDeclaration(pIAST, 0, pIFunctionType, "main", &pIFuncDeclaration);

    pIAST->pVTbl->new_FunctionDefinition(pIAST, 0, pIFuncDeclaration, pIBody, &pIFuncDefinition);
    pIGlobalScope->pVTbl->RegistFunctionDefinition(pIGlobalScope, pIFuncDefinition);

    /* Transaction Unit */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pIDecList);
    pIDecList->pVTbl->Add(pIDecList, pIPrintfDec);
    pIDecList->pVTbl->Add(pIDecList, pFactorialDef);
    pIDecList->pVTbl->Add(pIDecList, pIFuncDefinition);
    pIGlobalScope->pVTbl->RegistDeclaration(pIGlobalScope, (IEcoToolchainAST1Declaration*)pIPrintfDec);
    pIGlobalScope->pVTbl->RegistDeclaration(pIGlobalScope, (IEcoToolchainAST1Declaration*)pIFuncDeclaration);
    pIGlobalScope->pVTbl->RegistDeclaration(pIGlobalScope, (IEcoToolchainAST1Declaration*)pFactorialDecl);
    pIAST->pVTbl->new_BlockTranslationUnitObjects(pIAST, 0, pIDecList, &pIObjects);
    pIAST->pVTbl->new_TranslationUnit(pIAST, 0, pIGlobalScope, pIObjects, &pITranslationUnit);
    return 1;
}
