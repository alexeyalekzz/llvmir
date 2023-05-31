/*
 * <��������� ��������>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </��������� ��������>
 *
 * <������>
 *   CEcoToolchainEmitterLLVMIR1Visitor
 * </������>
 *
 * <��������>
 *   ������ �������� ��� ��������� ���������� ����������� CEcoToolchainEmitterLLVMIR1Visitor
 * </��������>
 *
 * <�����>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </�����>
 *
 */

#include "CEcoToolchainEmitterLLVMIR1Visitor.h"
#include "IEcoInterfaceBus1.h"
#include "IdEcoMap1.h"
#include "IdEcoList1.h"

// for debug
#include "IdEcoLog1.h"
#include "IEcoLog1FileAffiliate.h"

#include "utils.h"
#include <llvm-c/Analysis.h>


 /*
  *
  * <������>
  *   ������� QueryInterface
  * </������>
  *
  * <��������>
  *   ������� QueryInterface ��� ���������� IEcoVisitor1
  * </��������>
  *
  */
int16_t ECOCALLMETHOD CEcoToolchainEmitterLLVMIR1Visitor_QueryInterface(/* in */ struct IEcoVisitor1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    int16_t result = -1;

    /* �������� ���������� */
    if (me == 0 || ppv == 0) {
        return result;
    }

    /* �������� � ��������� ������������ ���������� */
    if (IsEqualUGUID(riid, &IID_IEcoVisitor1)) {
        *ppv = &pCMe->m_pVTblIVisitor;
        pCMe->m_pVTblIVisitor->AddRef((IEcoVisitor1*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIVisitor;
        pCMe->m_pVTblIVisitor->AddRef((IEcoVisitor1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <������>
 *   ������� AddRef
 * </������>
 *
 * <��������>
 *   ������� AddRef ��� ���������� IEcoVisitor1
 * </��������>
 *
 */
uint32_t ECOCALLMETHOD CEcoToolchainEmitterLLVMIR1Visitor_AddRef(/* in */ struct IEcoVisitor1* me) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;

    /* �������� ��������� */
    if (me == 0) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <������>
 *   ������� Release
 * </������>
 *
 * <��������>
 *   ������� Release ��� ���������� IEcoVisitor1
 * </��������>
 *
 */
uint32_t ECOCALLMETHOD CEcoToolchainEmitterLLVMIR1Visitor_Release(/* in */ struct IEcoVisitor1* me) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;

    /* �������� ��������� */
    if (me == 0) {
        return -1;
    }

    /* ���������� �������� ������ �� ��������� */
    --pCMe->m_cRef;

    /* � ������ ��������� ��������, ������������ ������ ���������� */
    if (pCMe->m_cRef == 0) {
        deleteCEcoToolchainEmitterLLVMIR1Visitor((IEcoVisitor1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <������>
 *   ������� Accept
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t ECOCALLMETHOD CEcoToolchainEmitterLLVMIR1Visitor_Accept(/* in */ struct IEcoVisitor1* me, /* in */ IEcoUnknown* pIUnk) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pIUnk == 0) {
        return -1;
    }

    result = pIUnk->pVTbl->QueryInterface(pIUnk, &IID_IEcoToolchainAST1SyntaxObject, (void**)&pISyntaxObject);

    if (result == 0 && pISyntaxObject != 0) {
        if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1ArrayType)) {
            pCMe->EmitArrayType((IEcoVisitor1*)pCMe, (IEcoToolchainAST1ArrayType*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1BinaryExpression)) {
            pCMe->EmitBinaryExpression((IEcoVisitor1*)pCMe, (IEcoToolchainAST1BinaryExpression*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1BlockDeclarations)) {
            pCMe->EmitBlockDeclarations((IEcoVisitor1*)pCMe, (IEcoToolchainAST1BlockDeclarations*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1BlockExpressions)) {
            pCMe->EmitBlockExpressions((IEcoVisitor1*)pCMe, (IEcoToolchainAST1BlockExpressions*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1BlockStatements)) {
            pCMe->EmitBlockStatements((IEcoVisitor1*)pCMe, (IEcoToolchainAST1BlockStatements*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1BlockTranslationUnitObjects)) {
            pCMe->EmitBlockTranslationUnitObject((IEcoVisitor1*)pCMe, (IEcoToolchainAST1BlockTranslationUnitObjects*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1BlockTypes)) {
            pCMe->EmitBlockTypes((IEcoVisitor1*)pCMe, (IEcoToolchainAST1BlockTypes*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1BreakStatement)) {
            pCMe->EmitBreakStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1BreakStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1CaseStatement)) {
            pCMe->EmitCaseStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1CaseStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1CastExpression)) {
            pCMe->EmitCastExpression((IEcoVisitor1*)pCMe, (IEcoToolchainAST1CastExpression*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1CharacterLiteral)) {
            pCMe->EmitCharacterLiteral((IEcoVisitor1*)pCMe, (IEcoToolchainAST1CharacterLiteral*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1CompoundStatement)) {
            pCMe->EmitCompoundStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1CompoundStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1ConditionalExpression)) {
            pCMe->EmitConditionalExpression((IEcoVisitor1*)pCMe, (IEcoToolchainAST1ConditionalExpression*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1ContinueStatement)) {
            pCMe->EmitContinueStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1ContinueStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1Declaration)) {
            pCMe->EmitDeclaration((IEcoVisitor1*)pCMe, (IEcoToolchainAST1Declaration*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1DefaultStatement)) {
            pCMe->EmitDefaultStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1DefaultStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1DoWhileStatement)) {
            pCMe->EmitDoWhileStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1DoWhileStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1EnumDeclaration)) {
            pCMe->EmitEnumDeclaration((IEcoVisitor1*)pCMe, (IEcoToolchainAST1EnumDeclaration*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1EnumType)) {
            pCMe->EmitEnumType((IEcoVisitor1*)pCMe, (IEcoToolchainAST1EnumType*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1Expression)) {
            pCMe->EmitExpression((IEcoVisitor1*)pCMe, (IEcoToolchainAST1Expression*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1ExpressionableDeclaration)) {
            pCMe->EmitExpressionableDeclaration((IEcoVisitor1*)pCMe, (IEcoToolchainAST1ExpressionableDeclaration*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1FloatLiteral)) {
            pCMe->EmitFloatLiteral((IEcoVisitor1*)pCMe, (IEcoToolchainAST1FloatLiteral*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1ForStatement)) {
            pCMe->EmitForStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1ForStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1FunctionCall)) {
            pCMe->EmitFunctionCall((IEcoVisitor1*)pCMe, (IEcoToolchainAST1FunctionCall*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1FunctionDeclaration)) {
            pCMe->EmitFunctionDeclaration((IEcoVisitor1*)pCMe, (IEcoToolchainAST1FunctionDeclaration*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1FunctionDefinition)) {
            pCMe->EmitFunctionDefinition((IEcoVisitor1*)pCMe, (IEcoToolchainAST1FunctionDefinition*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1FunctionType)) {
            pCMe->EmitFunctionType((IEcoVisitor1*)pCMe, (IEcoToolchainAST1FunctionType*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1GlobalScope)) {
            pCMe->EmitGlobalScope((IEcoVisitor1*)pCMe, (IEcoToolchainAST1GlobalScope*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1GoToStatement)) {
            pCMe->EmitGoToStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1GoToStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1IfStatement)) {
            pCMe->EmitIfStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1IfStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1IntegerLiteral)) {
            pCMe->EmitIntegerLiteral((IEcoVisitor1*)pCMe, (IEcoToolchainAST1IntegerLiteral*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1LabelStatement)) {
            pCMe->EmitLabelStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1LabelStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1Literal)) {
            pCMe->EmitLiteral((IEcoVisitor1*)pCMe, (IEcoToolchainAST1Literal*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1MemberSelection)) {
            pCMe->EmitMemberSelection((IEcoVisitor1*)pCMe, (IEcoToolchainAST1MemberSelection*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1NullExpression)) {
            pCMe->EmitNullExpression((IEcoVisitor1*)pCMe, (IEcoToolchainAST1NullExpression*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1NumberType)) {
            pCMe->EmitNumberType((IEcoVisitor1*)pCMe, (IEcoToolchainAST1NumberType*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1PointerType)) {
            pCMe->EmitPointerType((IEcoVisitor1*)pCMe, (IEcoToolchainAST1PointerType*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1ReturnStatement)) {
            pCMe->EmitReturnStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1ReturnStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1Scope)) {
            pCMe->EmitScope((IEcoVisitor1*)pCMe, (IEcoToolchainAST1Scope*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1SingleStatement)) {
            pCMe->EmitSingleStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1SingleStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1SizeofExpression)) {
            pCMe->EmitSizeofExpression((IEcoVisitor1*)pCMe, (IEcoToolchainAST1SizeofExpression*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1SizeofType)) {
            pCMe->EmitSizeofType((IEcoVisitor1*)pCMe, (IEcoToolchainAST1SizeofType*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1Statement)) {
            pCMe->EmitStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1Statement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1StringLiteral)) {
            pCMe->EmitStringLiteral((IEcoVisitor1*)pCMe, (IEcoToolchainAST1StringLiteral*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1StructOrUnionDeclaration)) {
            pCMe->EmitStructOrUnionDeclaration((IEcoVisitor1*)pCMe, (IEcoToolchainAST1StructOrUnionDeclaration*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1StructOrUnionType)) {
            pCMe->EmitStructOrUnionType((IEcoVisitor1*)pCMe, (IEcoToolchainAST1StructOrUnionType*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1SwitchStatement)) {
            pCMe->EmitSwitchStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1SwitchStatement*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1SyntaxObject)) {
            pCMe->EmitSyntaxObject((IEcoVisitor1*)pCMe, (IEcoToolchainAST1SyntaxObject*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1TranslationUnit)) {
            pCMe->EmitTranslationUnit((IEcoVisitor1*)pCMe, (IEcoToolchainAST1TranslationUnit*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1TranslationUnitObject)) {
            pCMe->EmitTranslationUnitObject((IEcoVisitor1*)pCMe, (IEcoToolchainAST1TranslationUnitObject*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1TypedefDeclaration)) {
            pCMe->EmitTypedefDeclaration((IEcoVisitor1*)pCMe, (IEcoToolchainAST1TypedefDeclaration*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1TypedefType)) {
            pCMe->EmitTypedefType((IEcoVisitor1*)pCMe, (IEcoToolchainAST1TypedefType*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1UnaryExpression)) {
            pCMe->EmitUnaryExpression((IEcoVisitor1*)pCMe, (IEcoToolchainAST1UnaryExpression*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1VariableDeclaration)) {
            pCMe->EmitVariableDeclaration((IEcoVisitor1*)pCMe, (IEcoToolchainAST1VariableDeclaration*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1VariableDefinition)) {
            pCMe->EmitVariableDefinition((IEcoVisitor1*)pCMe, (IEcoToolchainAST1VariableDefinition*)pISyntaxObject);
        }
        else if (IsEqualUGUID(pISyntaxObject->pVTbl->get_Id(pISyntaxObject), &IID_IEcoToolchainAST1WhileStatement)) {
            pCMe->EmitWhileStatement((IEcoVisitor1*)pCMe, (IEcoToolchainAST1WhileStatement*)pISyntaxObject);
        }
        else {
            result = -1;
        }

        pISyntaxObject->pVTbl->Release(pISyntaxObject);
    }
    else {
        result = -1;
    }

    return result;
}

LLVMModuleRef CEcoToolchainEmitterLLVMIR1Visitor_get_Module(/* in */ struct IEcoVisitor1* me) {
    if (me != 0) {
        return ((CEcoToolchainEmitterLLVMIR1Visitor*)me)->m_pLLVMModule;
    }

    return 0;
}

/*
 *
 * <������>
 *   ������� EmitTranslationUnit
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitTranslationUnit(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1TranslationUnit* pITransUnit) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1BlockTranslationUnitObjects* pIBlockTranslationUnitObjects = 0;
    IEcoToolchainAST1StructOrUnionDeclaration* pStructDecl = 0;
    IEcoToolchainAST1FunctionDeclaration* pFunDecl = 0;
    IEcoToolchainAST1Declaration* pDecl = 0;
    IEcoList1* pDeclsList = 0;
    IEcoToolchainAST1GlobalScope* pIGlobalScope = 0;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;
    uint32_t i = 0;

    /* �������� ���������� */
    if (me == 0 || pITransUnit == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitTranslationUnit() called\n");

    // TODO use source file name
    pCMe->m_pLLVMModule = LLVMModuleCreateWithNameInContext("__module", pCMe->m_pContext);

    pIGlobalScope = pITransUnit->pVTbl->get_Scope(pITransUnit);

    // Handle function declarations
    pDeclsList = pIGlobalScope->pVTbl->get_Declarations(pIGlobalScope);
    for (i = 0; i < pDeclsList->pVTbl->Count(pDeclsList); ++i) {
        pDecl = pDeclsList->pVTbl->Item(pDeclsList, i);
        
        result = pDecl->pVTbl->QueryInterface(pDecl, &IID_IEcoToolchainAST1FunctionDeclaration, &pFunDecl);
        if (result != 0 || pFunDecl == 0) {
            continue;
        }

        result = emit(pCMe, pFunDecl, 0);
        if (result != 0) {
            return -1;
        }
    }

    // Handle struct declarations
    pDeclsList = pIGlobalScope->pVTbl->get_StructOrUnionDeclarations(pIGlobalScope);
    for (i = 0; i < pDeclsList->pVTbl->Count(pDeclsList); ++i) {
        pStructDecl = pDeclsList->pVTbl->Item(pDeclsList, i);
        result = emit(pCMe, pStructDecl, 0);
        if (result != 0) {
            return -1;
        }
    }

    pIBlockTranslationUnitObjects = pITransUnit->pVTbl->getObjects(pITransUnit);
    result = pIBlockTranslationUnitObjects->pVTbl->QueryInterface(pIBlockTranslationUnitObjects, &IID_IEcoVisitor1Element, (void **)&pIElement);
    if (result == 0 && pIElement != 0) {
        pIElement->pVTbl->Visit(pIElement, me);
        pIElement->pVTbl->Release(pIElement);
    }
    return result;
}

/*
 *
 * <������>
 *   ������� EmitBlockTranslationUnitObject
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitBlockTranslationUnitObject(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BlockTranslationUnitObjects* pIBlockTranslationUnitObjects) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1TranslationUnitObject* pITranslationUnitObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;
    int32_t index = 0;

    /* �������� ���������� */
    if (me == 0 || pIBlockTranslationUnitObjects == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitBlockTranslationUnitObject() called\n");

    pITranslationUnitObject = pIBlockTranslationUnitObjects->pVTbl->get_Object(pIBlockTranslationUnitObjects, index);
    while (pITranslationUnitObject != 0) {
        result = pITranslationUnitObject->pVTbl->QueryInterface(pITranslationUnitObject, &IID_IEcoVisitor1Element, (void **)&pIElement);
        if (result == 0 && pIElement != 0) {
            pIElement->pVTbl->Visit(pIElement, me);
            pIElement->pVTbl->Release(pIElement);
        }

       index++;
       pITranslationUnitObject = pIBlockTranslationUnitObjects->pVTbl->get_Object(pIBlockTranslationUnitObjects, index);
    }

    return result;
}

/*
 *
 * <������>
 *   ������� EmitFunctionType
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitFunctionType(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1FunctionType* pIFunctionType) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pIFunctionType == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitFunctionType() called\n");

    return result;
}

/*
 *
 * <������>
 *   ������� EmitEmitFunctionDefinition
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitFunctionDefinition(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1FunctionDefinition* pIFunDef) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1FunctionDeclaration* pIFunDecl = 0;
    IEcoToolchainAST1CompoundStatement* pIBody = 0;
    IEcoToolchainAST1Declaration* pParamDecl = 0;
    IEcoToolchainAST1BlockDeclarations* pParameters = 0;
    bool_t isVarArg = 0;
    int16_t result = 0;
    uint32_t i = 0;
    uint32_t count = 0;
    char_t* ident = 0;

    LLVMBasicBlockRef entryBlock = 0;
    LLVMValueRef fun = 0;
    LLVMValueRef arg = 0;
    LLVMValueRef argAlloca = 0;
    LLVMValueRef paramValues[10] = { 0 }; // TODO make it dynamic
    LLVMTypeRef type = 0;

    ScopedValue* paramVal = 0;

    /* �������� ���������� */
    if (me == 0 || pIFunDef == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->InfoFormat(pCMe->m_log,
        "[LLVM Visitor] EmitFunctionDefinition() called\n"
        "               Object: <%s>\n", pIFunDef->pVTbl->get_NameObject(pIFunDef)
    );

    // TODO check if function already exists

    pIFunDecl = pIFunDef->pVTbl->get_Declaration(pIFunDef);
    pIBody = pIFunDef->pVTbl->get_Body(pIFunDef);

    if (pIFunDecl == 0 || pIBody == 0) {
        return -1;
    }

    // Emit declaration
    result = emit(pCMe, pIFunDecl, &fun);
    if (result != 0) {
        return result;
    }

    pCMe->ScopeNext(me);

    // Create an entry block and attach it to a function
    entryBlock = LLVMAppendBasicBlockInContext(pCMe->m_pContext, fun, "entry");
    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, entryBlock);

    // Handle args
    pParameters = pIFunDecl->pVTbl->get_Params(pIFunDecl);
    LLVMGetParams(fun, paramValues);

    count = LLVMCountParams(fun);
    for (i = 0; i < count; ++i) {
        pParamDecl = pParameters->pVTbl->get_Declaration(pParameters, i);

        result = emit(pCMe, pParamDecl, &paramVal);
        if (result != 0) {
            return -1;
        }

        LLVMBuildStore(pCMe->m_pBuilder, paramValues[i], paramVal->pAlloca);
    }

    // Emit body
    result = emit(pCMe, pIBody, 0);

    // For debug. TODO remove later
    result = LLVMVerifyFunction(fun, LLVMPrintMessageAction);

    pCMe->ScopePrev(me);

    return result;
}

/*
 *
 * <������>
 *   ������� EmitCompoundStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitCompoundStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1CompoundStatement* pICompoundStatement) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoVisitor1Element* pIElement = 0;
    IEcoToolchainAST1BlockStatements* pIBlockStatements = 0;
    IEcoToolchainAST1BlockDeclarations *pIBlockDeclarations = 0;
    int16_t result = 0;
    uint32_t index = 0;

    /* �������� ���������� */
    if (me == 0 || pICompoundStatement == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->InfoFormat(pCMe->m_log,
        "[LLVM Visitor] EmitCompoundStatement() called\n"
        "               Object: <%s>\n", pICompoundStatement->pVTbl->get_NameObject(pICompoundStatement)
    );

    pIBlockDeclarations = pICompoundStatement->pVTbl->get_BlockDeclarations(pICompoundStatement);
    if (pIBlockDeclarations != 0) {
        result = pIBlockDeclarations->pVTbl->QueryInterface(pIBlockDeclarations, &IID_IEcoVisitor1Element, (void**)&pIElement);
        if (result == 0 && pIElement != 0) {
            pIElement->pVTbl->Visit(pIElement, me);
            pIElement->pVTbl->Release(pIElement);
        }
    }

    pIBlockStatements = pICompoundStatement->pVTbl->get_BlockStatements(pICompoundStatement);
    if (pIBlockStatements != 0) {
        result = pIBlockStatements->pVTbl->QueryInterface(pIBlockStatements, &IID_IEcoVisitor1Element, (void**)&pIElement);
        if (result == 0 && pIElement != 0) {
            pIElement->pVTbl->Visit(pIElement, me);
            pIElement->pVTbl->Release(pIElement);
        }
    }

    return result;
}

/*
 *
 * <������>
 *   ������� EmitBlockStatements
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitBlockStatements(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BlockStatements* pIBlockStatements) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoVisitor1Element* pIElement = 0;
    IEcoToolchainAST1Statement* pIStatement = 0;
    int16_t result = 0;
    uint32_t index = 0;

    /* �������� ���������� */
    if (me == 0 || pIBlockStatements == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitBlockStatements() called\n");

    pIStatement = pIBlockStatements->pVTbl->get_Statement(pIBlockStatements, index);
    while (pIStatement != 0) {
        result = pIStatement->pVTbl->QueryInterface(pIStatement, &IID_IEcoVisitor1Element, (void**)&pIElement);
        if (result == 0 && pIElement != 0) {
            pIElement->pVTbl->Visit(pIElement, me);
            pIElement->pVTbl->Release(pIElement);
        }

        index++;
        pIStatement = pIBlockStatements->pVTbl->get_Statement(pIBlockStatements, index);
    }

    return result;
}

/*
 *
 * <������>
 *   ������� EmitStringLiteral
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitStringLiteral(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1StringLiteral* pIStringLiteral) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    int16_t result = 0;

    LLVMValueRef val = 0;

    /* �������� ���������� */
    if (me == 0 || pIStringLiteral == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitStringLiteral() called\n");

    val = LLVMBuildGlobalStringPtr(pCMe->m_pBuilder, pIStringLiteral->pVTbl->get_Value(pIStringLiteral), "");
    pCMe->m_pRetVal = pCMe->CreateUnnamedValue(
        me, 
        val,
        LLVMTypeOf(val),
        0
    );

    return result;
}

/*
 *
 * <������>
 *   ������� EmitBinaryExpression
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitBinaryExpression(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BinaryExpression* pIBinExpr) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1Expression *pLeftExpr = 0, *pRightExpr = 0;
    int16_t result = 0;
    bool_t isFp = 0;
    int32_t op;
    ScopedValue *lhsVal = 0, *rhsVal = 0;

    LLVMTypeRef leftType = 0, rightType = 0;
    LLVMValueRef l = 0, r = 0, tempVal = 0;
    LLVMValueRef indices[1];

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitBinaryExpression() called\n");

    /* �������� ���������� */
    if (me == 0 || pIBinExpr == 0) {
        return -1;
    }

    pLeftExpr = pIBinExpr->pVTbl->get_LeftOperand(pIBinExpr);
    pRightExpr = pIBinExpr->pVTbl->get_RightOperand(pIBinExpr);

    if (pLeftExpr == 0 || pRightExpr == 0) {
        return -1;
    }

    result = emit(pCMe, pLeftExpr, &lhsVal);
    if (result != 0) {
        return -1;
    }

    result = emit(pCMe, pRightExpr, &rhsVal);
    if (result != 0) {
        return -1;
    }

    op = pIBinExpr->pVTbl->get_Operator(pIBinExpr);

    l = lhsVal->pVal;
    r = rhsVal->pVal;

    /* If this is a LHS value, we should load first */
    if ((op != ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_ASSIGN) &&
        (op != ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_COMMA) && 
        (op != ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_INDEX) &&
        (lhsVal->pAlloca != 0)) 
    {
        l = LLVMBuildLoad2(pCMe->m_pBuilder, lhsVal->pType, lhsVal->pAlloca, "");
    }
    if (rhsVal->pAlloca != 0) {
        r = LLVMBuildLoad2(pCMe->m_pBuilder, rhsVal->pType, rhsVal->pAlloca, "");
    }

    isFp = (l && _isFloatingPointTy(LLVMTypeOf(l))) || (r && _isFloatingPointTy(LLVMTypeOf(r)));
    switch (op) {
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_ADD:
        tempVal = isFp ? LLVMBuildFAdd(pCMe->m_pBuilder, l, r, "")
                       : LLVMBuildAdd(pCMe->m_pBuilder, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_SUBTRACT:
        tempVal = isFp ? LLVMBuildFSub(pCMe->m_pBuilder, l, r, "")
                       : LLVMBuildSub(pCMe->m_pBuilder, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_MULTIPLY:
        tempVal = isFp ? LLVMBuildFMul(pCMe->m_pBuilder, l, r, "")
                       : LLVMBuildMul(pCMe->m_pBuilder, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_DIVIDE:
        tempVal = isFp ? LLVMBuildFDiv(pCMe->m_pBuilder, l, r, "")
                       : LLVMBuildSDiv(pCMe->m_pBuilder, l, r, "");    // todo there's also LLVMUDiv
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_MODULUS:
        tempVal = isFp ? LLVMBuildFRem(pCMe->m_pBuilder, l, r, "")
                       : LLVMBuildSRem(pCMe->m_pBuilder, l, r, "");    // todo there's also LLVMURem
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_AND:
        tempVal = LLVMBuildAnd(pCMe->m_pBuilder, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_OR:
        tempVal = LLVMBuildOr(pCMe->m_pBuilder, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_EQUAL:
        tempVal = isFp ? LLVMBuildFCmp(pCMe->m_pBuilder, LLVMRealOEQ, l, r, "")
                       : LLVMBuildICmp(pCMe->m_pBuilder, LLVMIntEQ, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_NOT_EQUAL:
        tempVal = isFp ? LLVMBuildFCmp(pCMe->m_pBuilder, LLVMRealONE, l, r, "")
                       : LLVMBuildICmp(pCMe->m_pBuilder, LLVMIntNE, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_GREATER:
        tempVal = isFp ? LLVMBuildFCmp(pCMe->m_pBuilder, LLVMRealOGT, l, r, "")
                       : LLVMBuildICmp(pCMe->m_pBuilder, LLVMIntSGT, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_NOT_GREATE:
        tempVal = isFp ? LLVMBuildFCmp(pCMe->m_pBuilder, LLVMRealOLE, l, r, "")
                       : LLVMBuildICmp(pCMe->m_pBuilder, LLVMIntSLE, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_LESS:
        tempVal = isFp ? LLVMBuildFCmp(pCMe->m_pBuilder, LLVMRealOLT, l, r, "")
                       : LLVMBuildICmp(pCMe->m_pBuilder, LLVMIntSLT, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_NOT_LESS:
        tempVal = isFp ? LLVMBuildFCmp(pCMe->m_pBuilder, LLVMRealOGE, l, r, "")
                       : LLVMBuildICmp(pCMe->m_pBuilder, LLVMIntSGE, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_BIT_AND:
        tempVal = LLVMBuildAnd(pCMe->m_pBuilder, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_BIT_OR:
        tempVal = LLVMBuildOr(pCMe->m_pBuilder, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_BIT_XOR:
        tempVal = LLVMBuildXor(pCMe->m_pBuilder, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_BIT_LEFT_SHIFT:
        tempVal = LLVMBuildShl(pCMe->m_pBuilder, l, r, "");
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_BIT_RIGHT_SHIFT:
        tempVal = LLVMBuildAShr(pCMe->m_pBuilder, l, r, ""); // todo or lshr?
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_ASSIGN:
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, r, lhsVal->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_COMMA:
        tempVal = r;
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_ADD_ASSIGN:
        tempVal = isFp ? LLVMBuildFAdd(pCMe->m_pBuilder, l, r, "")
                       : LLVMBuildAdd(pCMe->m_pBuilder, l, r, "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, lhsVal->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_SUB_ASSIGN:
        tempVal = isFp ? LLVMBuildFSub(pCMe->m_pBuilder, l, r, "")
                       : LLVMBuildSub(pCMe->m_pBuilder, l, r, "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, lhsVal->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_MULT_ASSIGN:
        tempVal = isFp ? LLVMBuildFMul(pCMe->m_pBuilder, l, r, "")
                       : LLVMBuildMul(pCMe->m_pBuilder, l, r, "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, lhsVal->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_DIV_ASSIGN:
        tempVal = isFp ? LLVMBuildFDiv(pCMe->m_pBuilder, l, r, "")
                       : LLVMBuildSDiv(pCMe->m_pBuilder, l, r, "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, lhsVal->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_MOD_ASSIGN:
        tempVal = isFp ? LLVMBuildFRem(pCMe->m_pBuilder, l, r, "")
                       : LLVMBuildSRem(pCMe->m_pBuilder, l, r, "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, lhsVal->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_AND_ASSIGN:
        tempVal = LLVMBuildAnd(pCMe->m_pBuilder, l, r, "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, lhsVal->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_OR_ASSIGN:
        tempVal = LLVMBuildOr(pCMe->m_pBuilder, l, r, "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, lhsVal->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_XOR_ASSIGN:
        tempVal = LLVMBuildXor(pCMe->m_pBuilder, l, r, "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, lhsVal->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_LEFT_SHIFT_ASSIGN:
        tempVal = LLVMBuildShl(pCMe->m_pBuilder, l, r, "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, lhsVal->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_RIGHT_SHIFT_ASSIGN:
        tempVal = LLVMBuildAShr(pCMe->m_pBuilder, l, r, "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, lhsVal->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_BINARY_OPERATOR_INDEX:
        indices[0] = r;
        tempVal = LLVMBuildInBoundsGEP2(pCMe->m_pBuilder, lhsVal->pType, lhsVal->pAlloca, indices, 1, "");
        pCMe->m_pRetVal = pCMe->CreateUnnamedValue(me, 0, LLVMTypeOf(tempVal), tempVal);
        return result;
    default:
        tempVal = 0;
        break;
    }

    if (tempVal == 0) {
        return -1;
    }

    pCMe->m_pRetVal = pCMe->CreateUnnamedValue(me, tempVal, LLVMTypeOf(tempVal), 0);
    return result;
}

/*
 *
 * <������>
 *   ������� EmitMemberSelection
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitMemberSelection(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1MemberSelection* pIMemberSelection) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1Expression* pSourceExpr = 0;
    IEcoToolchainAST1VariableDefinition* pInternalExpr = 0;

    ScopedValue* pSourceVal = 0, * pInternalVal = 0;
    StructFieldInfo* fieldInfo = 0;
    int16_t result = 0;
    char_t* structName = 0;
    char_t* fieldName = 0;

    LLVMValueRef ptr = 0, val = 0;

    /* �������� ���������� */
    if (me == 0 || pIMemberSelection == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitMemberSelection() called\n");

    pSourceExpr = pIMemberSelection->pVTbl->get_SourceExpression(pIMemberSelection);
    result = emit(pCMe, pSourceExpr, &pSourceVal);
    if (result != 0) {
        return -1;
    }

    pInternalExpr = pIMemberSelection->pVTbl->get_InternalExpression(pIMemberSelection);

    structName = LLVMGetStructName(pSourceVal->pType);
    fieldName = pInternalExpr->pVTbl->get_IdentifierName(pInternalExpr);

    fieldInfo = pCMe->GetStructFieldInfo(me, structName, fieldName);

    ptr = LLVMBuildStructGEP2(pCMe->m_pBuilder, pSourceVal->pType, pSourceVal->pAlloca, fieldInfo->idx, "");
    val = LLVMBuildLoad2(pCMe->m_pBuilder, fieldInfo->type, ptr, "");

    pCMe->m_pRetVal = pCMe->CreateUnnamedValue(
        me,
        val,
        fieldInfo->type,
        ptr
    );

    return result;
}

/*
 *
 * <������>
 *   ������� EmitUnaryExpression
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitUnaryExpression(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1UnaryExpression* pIUnaryExpr) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    int16_t op = 0;
    int16_t result = 0;

    ScopedValue* val = 0, *ret = 0;;
    LLVMValueRef tempVal = 0, v = 0;

    /* �������� ���������� */
    if (me == 0 || pIUnaryExpr == 0) {
        return -1;
    }

    // Emit operand
    result = emit(pCMe, pIUnaryExpr->pVTbl->get_Operand(pIUnaryExpr), &val);
    if (result != 0) {
        return -1;
    }

    v = val->pVal;
    if (val->pAlloca != 0) {
        v = LLVMBuildLoad2(pCMe->m_pBuilder, val->pType, val->pAlloca, "");
    }

    op = pIUnaryExpr->pVTbl->get_Operator(pIUnaryExpr);
    switch (op)
    {
    case ECO_TOOLCHAIN_AST1_UNARY_OPERATOR_POINTER:
        tempVal = LLVMBuildLoad2(pCMe->m_pBuilder, val->pType, v, "");
        ret = pCMe->CreateUnnamedValue(me, tempVal, LLVMPointerTypeInContext(pCMe->m_pContext, 0), 0);
        break;
    case ECO_TOOLCHAIN_AST1_UNARY_OPERATOR_REFERENCE:
        ret = pCMe->CreateUnnamedValue(me, val->pAlloca, LLVMPointerTypeInContext(pCMe->m_pContext, 0), 0);
        break;
    case ECO_TOOLCHAIN_AST1_UNARY_OPERATOR_NEGATIVE:
        tempVal = LLVMBuildNeg(pCMe->m_pBuilder, v, "");
        ret = pCMe->CreateUnnamedValue(me, tempVal, val->pType, 0);
        break;
    case ECO_TOOLCHAIN_AST1_UNARY_OPERATOR_NOT:
    case ECO_TOOLCHAIN_AST1_UNARY_OPERATOR_BIT_NOT:
        tempVal = LLVMBuildNot(pCMe->m_pBuilder, v, "");
        ret = pCMe->CreateUnnamedValue(me, tempVal, val->pType, 0);
        break;
    case ECO_TOOLCHAIN_AST1_UNARY_OPERATOR_POSTFIX_INC:
    case ECO_TOOLCHAIN_AST1_UNARY_OPERATOR_PREFIX_INC:
        tempVal = LLVMBuildAdd(pCMe->m_pBuilder, v, LLVMConstInt(val->pType, 1, 0), "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, val->pAlloca);
        ret = pCMe->CreateUnnamedValue(me, tempVal, val->pType, val->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_UNARY_OPERATOR_POSTFIX_DEC:
    case ECO_TOOLCHAIN_AST1_UNARY_OPERATOR_PREFIX_DEC:
        tempVal = LLVMBuildSub(pCMe->m_pBuilder, v, LLVMConstInt(val->pType, 1, 0), "");
        tempVal = LLVMBuildStore(pCMe->m_pBuilder, tempVal, val->pAlloca);
        ret = pCMe->CreateUnnamedValue(me, tempVal, val->pType, val->pAlloca);
        break;
    case ECO_TOOLCHAIN_AST1_UNARY_OPERATOR_POSITIVE:
        ret = val;
        break;
    default:
        break;
    }

    if (ret == 0) {
        return -1;
    }

    pCMe->m_pRetVal = ret;
    return result;
}

/*
 *
 * <������>
 *   ������� EmitIntegerLiteral
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitIntegerLiteral(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1IntegerLiteral* pIIntegerLiteral) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1Type* pType = 0;
    IEcoToolchainAST1NumberType* pNumType = 0;
    char_t* valStr = 0;
    int16_t result = 0;

    LLVMTypeRef literalType = 0;

    /* �������� ���������� */
    if (me == 0 || pIIntegerLiteral == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitIntegerLiteral() called\n");

    pType = pIIntegerLiteral->pVTbl->get_Type(pIIntegerLiteral);
    result = pType->pVTbl->QueryInterface(pType, &IID_IEcoToolchainAST1NumberType, &pNumType);
    if (result != 0 || pNumType == 0) {
        pCMe->m_pRetVal = 0;
        return result;
    }

    result = emit(pCMe, pNumType, &literalType);
    if (result != 0) {
        return result;
    }

    valStr = pIIntegerLiteral->pVTbl->get_Value(pIIntegerLiteral);
    
    pCMe->m_pRetVal = pCMe->CreateUnnamedValue(
        me,
        LLVMConstIntOfString(literalType, valStr, 10),
        literalType,
        0
    );

    return result;
}

/*
 *
 * <������>
 *   ������� EmitFloatLiteral
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitFloatLiteral(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1FloatLiteral* pIFloatLiteral) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1Type* pType = 0;
    IEcoToolchainAST1NumberType* pNumType = 0;
    char_t* valStr = 0;
    int16_t result = 0;

    LLVMTypeRef literalType = 0;

    /* �������� ���������� */
    if (me == 0 || pIFloatLiteral == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitEmitFloatLiteral() called\n");

    pType = pIFloatLiteral->pVTbl->get_Type(pIFloatLiteral);
    result = pType->pVTbl->QueryInterface(pType, &IID_IEcoToolchainAST1NumberType, &pNumType);
    if (result != 0 || pNumType == 0) {
        pCMe->m_pRetVal = 0;
        return result;
    }

    result = emit(pCMe, pNumType, &literalType);
    if (result != 0) {
        return result;
    }

    valStr = pIFloatLiteral->pVTbl->get_Value(pIFloatLiteral);

    pCMe->m_pRetVal = pCMe->CreateUnnamedValue(
        me,
        LLVMConstRealOfString(literalType, valStr),
        literalType,
        0
    );

    return result;
}

/*
 *
 * <������>
 *   ������� EmitNumberType
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitNumberType(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1NumberType* pINumTy) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    int16_t result = 0;
    int16_t typeTag;

    LLVMTypeRef type = 0;

    /* �������� ���������� */
    if (me == 0 || pINumTy == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->InfoFormat(pCMe->m_log, 
        "[LLVM Visitor] EmitNumberType() called\n"
        "               Object: <%s>\n", pINumTy->pVTbl->get_NameObject(pINumTy)
    );

    typeTag = pINumTy->pVTbl->get_IntegralType(pINumTy);
    type = _primitiveType2LLVM(pCMe->m_pContext, typeTag);

    pCMe->m_pRetVal = type;
    return result;
}

/*
 *
 * <������>
 *   ������� EmitStructOrUnionType
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitStructOrUnionType(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1StructOrUnionType* pIStructOrUnionType) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    int16_t result = 0;
    LLVMTypeRef type = 0;

    /* �������� ���������� */
    if (me == 0 || pIStructOrUnionType == 0) {
        return -1;
    }

    type = LLVMGetTypeByName2(pCMe->m_pContext, pIStructOrUnionType->pVTbl->get_TypeName(pIStructOrUnionType));
    if (type == 0) {
        return -1;
    }

    pCMe->m_pRetVal = type;
    return result;
}

/*
 *
 * <������>
 *   ������� EmitArrayType
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitArrayType(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1ArrayType* pIArrayType) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1Type* pIntegralType = 0;
    IEcoToolchainAST1Expression* pCountExpr = 0;
    IEcoToolchainAST1IntegerLiteral* pIntLiteral = 0;
    int16_t result = 0;
    uint32_t elementCount = 0;
    char_t* elementCountStr = 0;

    LLVMTypeRef elementType = 0;

    /* �������� ���������� */
    if (me == 0 || pIArrayType == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitArrayType() called\n");

    pIntegralType = pIArrayType->pVTbl->get_IntegralType(pIArrayType);
    result = emit(pCMe, pIntegralType, &elementType);
    if (result != 0) {
        return -1;
    }

    pCountExpr = pIArrayType->pVTbl->get_CountExpression(pIArrayType);
    
    // Assume that it should be always integer literal
    result = pCountExpr->pVTbl->QueryInterface(pCountExpr, &IID_IEcoToolchainAST1IntegerLiteral, &pIntLiteral);
    if (result != 0 || pIntLiteral == 0) {
        return -1;
    }

    elementCountStr = pIntLiteral->pVTbl->get_Value(pIntLiteral);
    elementCount = parseInteger(elementCountStr);

    pCMe->m_pRetVal = LLVMArrayType(elementType, elementCount);
    return result;
}

/*
 *
 * <������>
 *   ������� EmitPointerType
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitPointerType(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1PointerType* pIPtrType) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pIPtrType == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->InfoFormat(pCMe->m_log, 
        "[LLVM Visitor] EmitPointerType() called\n"
        "               Object: <%s>\n", pIPtrType->pVTbl->get_NameObject(pIPtrType)
    );

    pCMe->m_pRetVal = LLVMPointerTypeInContext(pCMe->m_pContext, 0);
    return result;
}

/*
 *
 * <������>
 *   ������� EmitVariableDeclaration
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitVariableDeclaration(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1VariableDeclaration* pIVarDecl) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    IEcoToolchainAST1Type* pIType = 0;
    IEcoToolchainAST1Expression* pIInit = 0;
    IEcoToolchainAST1StructOrUnionType* pStructType = 0;
    IEcoToolchainAST1StructOrUnionDeclaration* pStructDecl = 0;

    char_t* name = 0;
    int16_t result = 0;
    ScopedValue *initVal = 0;

    LLVMValueRef allocaVal = 0, funVal = 0;
    LLVMTypeRef type = 0;
    LLVMBuilderRef tempBuilder = 0;

    /* �������� ���������� */
    if (me == 0 || pIVarDecl == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitVariableDeclaration() called\n");

    // todo how to detect that it is a global variable?

    // Getting type
    pIType = pIVarDecl->pVTbl->get_Type(pIVarDecl);
    result = emit(pCMe, pIType, &type);
    if (result != 0) {
        return result;
    }

    // Check, if this is a struct declaration
    result = pIType->pVTbl->QueryInterface(pIType, &IID_IEcoToolchainAST1StructOrUnionType, &pStructType);
    if ((result == 0) && (pStructType != 0) &&
        (LLVMGetInsertBlock(pCMe->m_pBuilder) == 0))
    {  
        // This is struct declaration at the global scope, just ignore it
        return 0;
    }

    name = pIVarDecl->pVTbl->get_IdentifierName(pIVarDecl);

    // Will generate alloca instruction for variable at the function entry
    //
    // %<name> = alloca <type>
    tempBuilder = LLVMCreateBuilder();
    funVal = LLVMGetBasicBlockParent(LLVMGetInsertBlock(pCMe->m_pBuilder));
    LLVMPositionBuilderAtEnd(tempBuilder, LLVMGetEntryBasicBlock(funVal));
    allocaVal = LLVMBuildAlloca(tempBuilder, type, name);
    LLVMDisposeBuilder(tempBuilder);

    // Emit initializer
    pIInit = pIVarDecl->pVTbl->get_Initializator(pIVarDecl);
    result = emit(pCMe, pIInit, &initVal);

    // Stores initializer value, if there any
    // 
    // store <type> <initVal>, <name>
    if (result == 0 && pIInit != 0) {
        LLVMBuildStore(pCMe->m_pBuilder, initVal->pVal, allocaVal);
    }
    
    pCMe->m_pRetVal = pCMe->CreateNamedValue(
        me,
        name,
        initVal ? initVal->pVal : 0,
        type, 
        allocaVal
    );
    return result;
}

/*
 *
 * <������>
 *   ������� EmitStructOrUnionDeclaration
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitStructOrUnionDeclaration(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1StructOrUnionDeclaration* pIStructOrUnionDecl) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1BlockDeclarations* pFields = 0;
    IEcoToolchainAST1VariableDeclaration* pFieldDecl = 0;

    char_t* structName = 0;
    int16_t result = 0;
    uint32_t i = 0, fieldCount = 0;

    LLVMValueRef fieldVals[10] = { 0 };
    LLVMTypeRef fieldTypes[10] = { 0 };
    LLVMTypeRef structType = 0, fieldType = 0;

    /* �������� ���������� */
    if (me == 0 || pIStructOrUnionDecl == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitStructOrUnionDeclaration() called\n");

    structName = pIStructOrUnionDecl->pVTbl->get_IdentifierName(pIStructOrUnionDecl);
    pFields = pIStructOrUnionDecl->pVTbl->get_Params(pIStructOrUnionDecl);

    pCMe->AddStruct(me, structName);

    fieldCount = pFields->pVTbl->get_Count(pFields);
    for (; i < fieldCount; ++i) {
        pFieldDecl = (IEcoToolchainAST1VariableDeclaration*)pFields->pVTbl->get_Declaration(pFields, i);

        result = emit(pCMe, pFieldDecl->pVTbl->get_Type(pFieldDecl), &fieldType);
        if (result != 0) {
            return -1;
        }

        fieldTypes[i] = fieldType;
        
        pCMe->SetStructFieldInfo(me, structName, pFieldDecl->pVTbl->get_IdentifierName(pFieldDecl), i, fieldType);
    }

    structType = LLVMStructCreateNamed(pCMe->m_pContext, structName);
    LLVMStructSetBody(structType, fieldTypes, fieldCount, 0);

    return result;
}

/*
 *
 * <������>
 *   ������� EmitVariableDefinition
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitVariableDefinition(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1VariableDefinition* pIVarDef) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;

    ScopedValue* sVal = 0;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pIVarDef == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitVariableDefinition() called\n");

    sVal = pCMe->ScopeGetNamed(me, pIVarDef->pVTbl->get_IdentifierName(pIVarDef));
    if (sVal == 0) {
        return -1;
    }

    pCMe->m_pRetVal = sVal;
    return result;
}

/*
 *
 * <������>
 *   ������� EmitCastExpression
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitCastExpression(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1CastExpression* pICastExpression) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pICastExpression == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitCastExpression() called\n");

    return result;
}

/*
 *
 * <������>
 *   ������� EmitConditionalExpression
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitConditionalExpression(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1ConditionalExpression* pICondExpr) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1Expression* pTestExpr = 0, * pTrueExpr = 0, * pFalseExpr = 0;

    ScopedValue* testVal = 0, * trueVal = 0, * falseVal = 0;
    int16_t result = 0;

    LLVMValueRef v1 = 0, v2 = 0, v3 = 0, res = 0;

    /* �������� ���������� */
    if (me == 0 || pICondExpr == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitConditionalExpression() called\n");

    pTestExpr = pICondExpr->pVTbl->get_TestOperand(pICondExpr);
    pTrueExpr = pICondExpr->pVTbl->get_TrueOperand(pICondExpr);
    pFalseExpr = pICondExpr->pVTbl->get_FalseOperand(pICondExpr);

    if (pTestExpr == 0 || pTrueExpr == 0 || pFalseExpr == 0) {
        return -1;
    }

    result = emit(pCMe, pTestExpr, &testVal);
    result += emit(pCMe, pTrueExpr, &trueVal);
    result += emit(pCMe, pFalseExpr, &falseVal);
    if (result != 0) {
        return -1;
    }

    v1 = testVal->pVal;
    v2 = trueVal->pVal;
    v3 = falseVal->pVal;
    if (testVal->pAlloca != 0) {
        v1 = LLVMBuildLoad2(pCMe->m_pBuilder, testVal->pType, testVal->pAlloca, "");
    }
    if (trueVal->pAlloca != 0) {
        v2 = LLVMBuildLoad2(pCMe->m_pBuilder, trueVal->pType, trueVal->pAlloca, "");
    }
    if (falseVal->pAlloca != 0) {
        v3 = LLVMBuildLoad2(pCMe->m_pBuilder, falseVal->pType, falseVal->pAlloca, "");
    }

    /* Need to compare with 0 explicitly if value is not boolean */
    if (LLVMGetIntTypeWidth(LLVMTypeOf(v1)) != 1) {
        v1 = LLVMBuildICmp(pCMe->m_pBuilder, LLVMIntNE, v1, LLVMConstInt(testVal->pType, 0, 0), "");
    }

    res = LLVMBuildSelect(pCMe->m_pBuilder, v1, v2, v3, "");
    pCMe->m_pRetVal = pCMe->CreateUnnamedValue(
        me,
        res,
        LLVMTypeOf(res),
        0
    );
    return result;
}

/*
 *
 * <������>
 *   ������� EmitSizeofType
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitSizeofType(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1SizeofType* pISizeofType) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pISizeofType == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitSizeofType() called\n");

    return result;
}

/*
 *
 * <������>
 *   ������� EmitSizeofVarDef
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitSizeofExpression(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1SizeofExpression* pISizeofExpression) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pISizeofExpression == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitSizeofExpression() called\n");

    return result;
}

/*
 *
 * <������>
 *   ������� EmitNullExpression
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitNullExpression(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1NullExpression* pINullExpression) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pINullExpression == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitNullExpression() called\n");

    return result;
}

/*
 *
 * <������>
 *   ������� EmitBlockExpressions
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitBlockExpressions(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BlockExpressions* pIBlockExpressions) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    IEcoToolchainAST1Expression* pIExpression = 0;
    int16_t result = 0;
    uint32_t index = 0;

    /* �������� ���������� */
    if (me == 0 || pIBlockExpressions == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitBlockExpressions() called\n");

    pIExpression = pIBlockExpressions->pVTbl->get_Expression(pIBlockExpressions, index);
    if (pIExpression != 0) {
        result = pIExpression->pVTbl->QueryInterface(pIExpression, &IID_IEcoVisitor1Element, (void**)&pIElement);
        if (result == 0 && pIElement != 0) {
            pIElement->pVTbl->Visit(pIElement, me);
            pIElement->pVTbl->Release(pIElement);
        }

        index++;
        pIExpression = pIBlockExpressions->pVTbl->get_Expression(pIBlockExpressions, index);
    }

    return result;
}

/*
 *
 * <������>
 *   ������� EmitBreakStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitBreakStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BreakStatement* pIBreakStatement) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pIBreakStatement == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitBreakStatement() called\n");

    return result;
}

/*
 *
 * <������>
 *   ������� EmitDefaultStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitDefaultStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1DefaultStatement* pIDefaultStatement) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pIDefaultStatement == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitDefaultStatement() called\n");

    return result;
}

/*
 *
 * <������>
 *   ������� EmitContinueStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitContinueStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1ContinueStatement* pIContinueStatement) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pIContinueStatement == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitContinueStatement() called\n");

    return result;
}

/*
 *
 * <������>
 *   ������� EmitReturnStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitReturnStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1ReturnStatement* pIRetStmt) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1Expression* pIExpr = 0;
    int16_t result = 0;

    ScopedValue* retVal = 0;

    /* �������� ���������� */
    if (me == 0 || pIRetStmt == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitReturnStatement() called\n");

    pIExpr = pIRetStmt->pVTbl->get_Expression(pIRetStmt);
    result = emit(pCMe, pIExpr, &retVal);
    if (result != 0) {
        return result;
    }

    if (retVal->pAlloca != 0) {
        LLVMBuildRet(pCMe->m_pBuilder, LLVMBuildLoad2(pCMe->m_pBuilder, retVal->pType, retVal->pAlloca, ""));
    }
    else {
        LLVMBuildRet(pCMe->m_pBuilder, retVal->pVal);
    }

    pCMe->m_pRetVal = 0; 
    return result;
}

/*
 *
 * <������>
 *   ������� EmitGoToStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitGoToStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1GoToStatement* pIGoToStatement) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    
    int16_t result = 0;
    char_t* labelName = 0;

    /* �������� ���������� */
    if (me == 0 || pIGoToStatement == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitGoToStatement() called\n");

    labelName = pIGoToStatement->pVTbl->get_LabelName(pIGoToStatement);
    LLVMBuildBr(pCMe->m_pBuilder, LLVMCreateBasicBlockInContext(pCMe->m_pContext, labelName));

    return result;
}

/*
 *
 * <������>
 *   ������� EmitIfStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitIfStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1IfStatement* pIIfStmt) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    int16_t result = 0;
    bool_t isInt = 0;

    IEcoToolchainAST1Expression* condExpr = 0;
    IEcoToolchainAST1Statement* thenStmt = 0, *elseStmt = 0;

    LLVMValueRef funVal = 0, elseVal = 0;
    LLVMBasicBlockRef thenBlock = 0, elseBlock = 0, outBlock = 0;
    ScopedValue *condVal = 0, *thenVal = 0;

    /* �������� ���������� */
    if (me == 0 || pIIfStmt == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitIfStatement() called\n");

    condExpr = pIIfStmt->pVTbl->get_TestExpression(pIIfStmt);
    thenStmt = pIIfStmt->pVTbl->get_TrueStatement(pIIfStmt);
    elseStmt = pIIfStmt->pVTbl->get_FalseStatement(pIIfStmt);

    result = emit(pCMe, condExpr, &condVal);
    if (result != 0) {
        return -1;
    }

    // TODO only when condVal->pType != i1
    // Need to compare with 0 explicitly to get i1 type
    //isInt = _isIntegerTy(LLVMTypeOf(condVal->pVal));
    //if (isInt) {
    //    condVal->pVal = LLVMBuildICmp(pCMe->m_pBuilder, LLVMIntEQ, condVal->pVal, LLVMConstInt(condVal->pType, 0, 0), "");
    //}
    //else {
    //    condVal->pVal = LLVMBuildFCmp(pCMe->m_pBuilder, LLVMRealOEQ, condVal->pVal, LLVMConstReal(condVal->pType, 0.0), "");
    //}

    // Get function ref to insert blocks
    funVal = LLVMGetBasicBlockParent(LLVMGetInsertBlock(pCMe->m_pBuilder));

    thenBlock = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");
    if (thenBlock == 0) {
        return -1;
    }

    if (elseStmt != 0) {
        elseBlock = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");
    }

    outBlock = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");

    if (elseStmt == 0) {
        elseBlock = outBlock;
    }

    // br i1 %cond, label %then, label %else
    LLVMBuildCondBr(pCMe->m_pBuilder, condVal->pVal, thenBlock, elseBlock);

    // if {
    // ...
    // }
    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, thenBlock);
    result = emit(pCMe, thenStmt, &thenVal);
    LLVMBuildBr(pCMe->m_pBuilder, outBlock);

    // else {
    // ...
    // }
    if (elseStmt) {
        LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, elseBlock);
        result = emit(pCMe, elseStmt, &elseVal);
        LLVMBuildBr(pCMe->m_pBuilder, outBlock);
    }

    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, outBlock);

    return result;
}

/*
 *
 * <������>
 *   ������� EmitForStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitForStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1ForStatement* pIForStmt) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    IEcoToolchainAST1Expression *pInitExpr = 0, *pTestExpr = 0, *pIterExpr = 0;
    IEcoToolchainAST1Statement* pLoopBody = 0;
    int16_t result = 0;

    LLVMValueRef funVal = 0;
    LLVMBasicBlockRef loopStartBlk = 0, loopEndBlk = 0, loopBodyBlk = 0, currentBlk = 0;
    ScopedValue* testVal = 0;

    /* �������� ���������� */
    if (me == 0 || pIForStmt == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitForStatement() called\n");

    pLoopBody = pIForStmt->pVTbl->get_InternalStatement(pIForStmt);
    pInitExpr = pIForStmt->pVTbl->get_InitExpression(pIForStmt);
    pTestExpr = pIForStmt->pVTbl->get_TestExpression(pIForStmt);
    pIterExpr = pIForStmt->pVTbl->get_IterExpression(pIForStmt);

    // Get function ref to insert blocks
    currentBlk = LLVMGetInsertBlock(pCMe->m_pBuilder);
    funVal = LLVMGetBasicBlockParent(currentBlk);

    // Generate initial
    if (pInitExpr) {

        pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] Generating initial expr\n");

        result = emit(pCMe, pInitExpr, 0);
        if (result != 0) {
            return -1;
        }
    }

    // Generate labels
    loopStartBlk = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");
    loopBodyBlk = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");
    loopEndBlk = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");

    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, loopStartBlk);

    // Generate loop exit condition (if there any)
    if (pTestExpr) {

        pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] Generating loop exit condition\n");

        result = emit(pCMe, pTestExpr, &testVal);
        if (result != 0) {
            return -1;
        }

        // TODO only if testVal->pType != i1
        // Need to compare with 0 explicitly to get i1 type
        //if (_isIntegerTy(LLVMTypeOf(testVal))) {
        //    testVal = LLVMBuildICmp(pCMe->m_pBuilder, LLVMIntEQ, testVal, LLVMConstInt(LLVMTypeOf(testVal), 0, 0), "");
        //}
        //else {
        //    testVal = LLVMBuildFCmp(pCMe->m_pBuilder, LLVMRealOEQ, testVal, LLVMConstReal(LLVMTypeOf(testVal), 0.0), "");
        //}

        LLVMBuildCondBr(pCMe->m_pBuilder, testVal->pVal, loopBodyBlk, loopEndBlk);
    }

    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, loopBodyBlk);

    // Generate loop body
    if (pLoopBody) {

        pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] Generating loop body\n");

        result = emit(pCMe, pLoopBody, 0);
        if (result != 0) {
            return -1;
        }
    }

    // Generate iter
    if (pIterExpr) {

        pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] Generating iter expr\n");

        result = emit(pCMe, pIterExpr, 0);
        if (result != 0) {
            return -1;
        }
    }

    LLVMBuildBr(pCMe->m_pBuilder, loopStartBlk);

    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, currentBlk);
    LLVMBuildBr(pCMe->m_pBuilder, loopStartBlk);

    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, loopEndBlk);

    return result;
}

/*
 *
 * <������>
 *   ������� EmitWhileStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitWhileStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1WhileStatement* pIWhileStmt) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1Expression* pTestExpr = 0;
    IEcoToolchainAST1Statement* pBody = 0;
    int16_t result = 0;

    LLVMBasicBlockRef loopStartBlk = 0, loopEndBlk = 0, loopBodyBlk = 0, currentBlk = 0;
    LLVMValueRef funVal = 0;
    ScopedValue* testVal = 0;

    /* �������� ���������� */
    if (me == 0 || pIWhileStmt == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitWhileStatement() called\n");

    pTestExpr = pIWhileStmt->pVTbl->get_TestExpression(pIWhileStmt);
    pBody = pIWhileStmt->pVTbl->get_InternalStatement(pIWhileStmt);

    if (pTestExpr == 0) {
        return -1;
    }

    /* Get function ref to insert blocks */
    currentBlk = LLVMGetInsertBlock(pCMe->m_pBuilder);
    funVal = LLVMGetBasicBlockParent(currentBlk);

    /* Generate labels */
    loopStartBlk = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");
    loopBodyBlk = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");
    loopEndBlk = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");

    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, currentBlk);
    LLVMBuildBr(pCMe->m_pBuilder, loopStartBlk);
    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, loopStartBlk);

    /* Generate loop condition */
    result = emit(pCMe, pTestExpr, &testVal);
    if (result != 0) {
        return -1;
    }

    LLVMBuildCondBr(pCMe->m_pBuilder, testVal->pVal, loopBodyBlk, loopEndBlk);
    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, loopBodyBlk);

    /* Generate body */
    if (pBody != 0) {
        result = emit(pCMe, pBody, 0);
        if (result != 0) {
            return -1;
        }
    }

    LLVMBuildBr(pCMe->m_pBuilder, loopStartBlk);
    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, loopEndBlk);

    return result;
}

/*
 *
 * <������>
 *   ������� EmitDoWhileStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitDoWhileStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1DoWhileStatement* pIDoWhileStmt) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1Expression* pTestExpr = 0;
    IEcoToolchainAST1Statement* pBody = 0;
    int16_t result = 0;

    LLVMBasicBlockRef loopCondBlk = 0, loopEndBlk = 0, loopBodyBlk = 0, currentBlk = 0;
    LLVMValueRef funVal = 0;
    ScopedValue* testVal = 0;

    /* �������� ���������� */
    if (me == 0 || pIDoWhileStmt == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitDoWhileStatement() called\n");

    pTestExpr = pIDoWhileStmt->pVTbl->get_TestExpression(pIDoWhileStmt);
    pBody = pIDoWhileStmt->pVTbl->get_InternalStatement(pIDoWhileStmt);

    if (pTestExpr == 0) {
        return -1;
    }

    /* Get function ref to insert blocks */
    currentBlk = LLVMGetInsertBlock(pCMe->m_pBuilder);
    funVal = LLVMGetBasicBlockParent(currentBlk);

    /* Generate labels */
    loopBodyBlk = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");
    loopCondBlk = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");
    loopEndBlk = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, "");

    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, currentBlk);
    LLVMBuildBr(pCMe->m_pBuilder, loopBodyBlk);
    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, loopBodyBlk);

    /* Generate body */
    if (pBody != 0) {
        result = emit(pCMe, pBody, 0);
        if (result != 0) {
            return -1;
        }
    }

    LLVMBuildBr(pCMe->m_pBuilder, loopCondBlk);
    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, loopCondBlk);

    /* Generate loop condition */
    result = emit(pCMe, pTestExpr, &testVal);
    if (result != 0) {
        return -1;
    }

    LLVMBuildCondBr(pCMe->m_pBuilder, testVal->pVal, loopBodyBlk, loopEndBlk);
    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, loopEndBlk);

    return result;
}

/*
 *
 * <������>
 *   ������� EmitSwitchStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitSwitchStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1SwitchStatement* pISwitchStatement) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pISwitchStatement == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitSwitchStatement() called\n");

    return result;
}

/*
 *
 * <������>
 *   ������� EmitCaseStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitCaseStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1CaseStatement* pICaseStatement) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1SyntaxObject* pISyntaxObject = 0;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pICaseStatement == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitCaseStatement() called\n");

    return result;
}

/*
 *
 * <������>
 *   ������� EmitLabelStatement
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitLabelStatement(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1LabelStatement* pILabelStatement) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1Statement* internalStmt = 0;

    int16_t result = 0;
    char_t* labelName = 0;

    LLVMBasicBlockRef bb = 0, curBlk = 0;
    LLVMValueRef funVal = 0;

    /* �������� ���������� */
    if (me == 0 || pILabelStatement == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitLabelStatement() called\n");

    labelName = pILabelStatement->pVTbl->get_LabelName(pILabelStatement);
    
    curBlk = LLVMGetInsertBlock(pCMe->m_pBuilder);
    funVal = LLVMGetBasicBlockParent(curBlk);

    bb = LLVMAppendBasicBlockInContext(pCMe->m_pContext, funVal, labelName);

    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, curBlk);
    LLVMBuildBr(pCMe->m_pBuilder, bb);

    LLVMPositionBuilderAtEnd(pCMe->m_pBuilder, bb);
    internalStmt = pILabelStatement->pVTbl->get_InternalStatement(pILabelStatement);
    result = emit(pCMe, internalStmt, 0);
    if (result != 0) {
        return -1;
    }

    return result;
}

/*
 *
 * <������>
 *   ������� EmitBlockTypes
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitBlockTypes(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BlockTypes* pIBlockTypes) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    int16_t result = 0;

    /* �������� ���������� */
    if (me == 0 || pIBlockTypes == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitBlockTypes() called\n");

    return result;
}

/*
 *
 * <������>
 *   ������� EmitFunctionDeclaration
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitFunctionDeclaration(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1FunctionDeclaration* pIFunDecl) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1FunctionType* pIFunType = 0;
    IEcoToolchainAST1BlockDeclarations* pArgs = 0;
    IEcoToolchainAST1Declaration* pArg = 0;
    IEcoToolchainAST1VariableDeclaration* pVarDecl = 0;
    int16_t result = 0;
    char_t* name = 0;
    uint32_t index = 0;

    bool_t isVarArg = 0;
    uint32_t paramCount = 0;
    LLVMTypeRef ty = 0;
    LLVMTypeRef argTy = 0;
    LLVMTypeRef returnType = 0;
    LLVMTypeRef paramTypes[10]; // TODO make it dynamic
    LLVMValueRef funVal = 0;

    /* �������� ���������� */
    if (me == 0 || pIFunDecl == 0) {
        return -1;
    }


    pCMe->m_log->pVTbl->InfoFormat(pCMe->m_log, 
        "[LLVM Visitor] EmitFunctionDeclaration() called\n"
        "               Object: <%s>\n", pIFunDecl->pVTbl->get_NameObject(pIFunDecl)
    );

    name = pIFunDecl->pVTbl->get_IdentifierName(pIFunDecl);

    // First, check if this declaration already exists in module
    funVal = LLVMGetNamedFunction(pCMe->m_pLLVMModule, name);
    if (funVal != 0) {
        pCMe->m_pRetVal = funVal;
        return 0;
    }

    pIFunType = pIFunDecl->pVTbl->get_Type(pIFunDecl);
    
    // Iterate over parameters and store it in paramTypes[]
    pArgs = pIFunType->pVTbl->get_Params(pIFunType);
    paramCount = pArgs->pVTbl->get_Count(pArgs);
    for (; index < paramCount; ++index) {
        pArg = pArgs->pVTbl->get_Declaration(pArgs, index);
        pVarDecl = (IEcoToolchainAST1VariableDeclaration*)pArg;
        
        result = emit(pCMe, pVarDecl->pVTbl->get_Type(pVarDecl), &argTy);
        if (result != 0) {
            return result;
        }

        paramTypes[index] = argTy;
    }

    // Emit return type
    result = emit(pCMe, pIFunType->pVTbl->get_ReturnType(pIFunType), &returnType);
    if (result != 0) {
        return result;
    }

    isVarArg = pIFunType->pVTbl->isVariadic(pIFunType);

    // Add function to module
    ty = LLVMFunctionType(returnType, paramTypes, paramCount, isVarArg);
    pCMe->m_pRetVal = LLVMAddFunction(pCMe->m_pLLVMModule, name, ty);

    return result;
}


/*
 *
 * <������>
 *   ������� EmitFunctionCall
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitFunctionCall(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1FunctionCall* pIFunCall) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoToolchainAST1BlockExpressions* pIFuncParams = 0;
    IEcoToolchainAST1Expression* pIExpr = 0;
    IEcoToolchainAST1VariableDefinition* pIVarDef = 0;
    int16_t result = 0;
    uint32_t count = 0;
    uint32_t index = 0;
    char_t* name = 0;

    LLVMTypeRef functionType = 0;
    ScopedValue* argValue = 0;
    LLVMValueRef function = 0;
    LLVMValueRef argValues[10] = { 0 }; // TODO make it dynamic

    /* �������� ���������� */
    if (me == 0 || pIFunCall == 0) {
        return -1;
    }

    pIVarDef = (IEcoToolchainAST1VariableDefinition*)pIFunCall->pVTbl->get_FunctionExpression(pIFunCall);
    name = pIVarDef->pVTbl->get_IdentifierName(pIVarDef);

    pCMe->m_log->pVTbl->InfoFormat(pCMe->m_log,
        "[LLVM Visitor] EmitFunctionCall() called\n"
        "               Object: <%s>\n"
        "               Calee: %s\n",
        pIFunCall->pVTbl->get_NameObject(pIFunCall), name
    );

    // Find function in current module by name
    function = LLVMGetNamedFunction(pCMe->m_pLLVMModule, name);
    if (function == 0) {
        return -1;
    }

    // Iterate over arguments and store emitted values into argValues[]
    pIFuncParams = pIFunCall->pVTbl->get_Arguments(pIFunCall);
    count = pIFuncParams->pVTbl->get_Count(pIFuncParams);
    for (; index < count; ++index) {
        pIExpr = pIFuncParams->pVTbl->get_Expression(pIFuncParams, index);

        result = emit(pCMe, pIExpr, &argValue);
        if (result != 0) {
            return result;
        }

        if (argValue->pAlloca != 0) {
            argValues[index] = LLVMBuildLoad2(pCMe->m_pBuilder, argValue->pType, argValue->pAlloca, "");
        }
        else {
            argValues[index] = argValue->pVal;
        }
    }

    // Functions always globals, so we can call LLVMGlobalGetValueType()
    functionType = LLVMGlobalGetValueType(function);

    pCMe->m_pRetVal = pCMe->CreateUnnamedValue(
        me,
        LLVMBuildCall2(pCMe->m_pBuilder, functionType, function, argValues, count, ""),
        functionType,
        0
    );

    return result;
}

/*
 *
 * <������>
 *   ������� EmitBlockDeclarations
 * </������>
 *
 * <��������>
 *   �������
 * </��������>
 *
 */
int16_t CEcoToolchainEmitterLLVMIR1Visitor_EmitBlockDeclarations(/* in */ struct IEcoVisitor1* me, /* in */ IEcoToolchainAST1BlockDeclarations* pIBlockDeclarations) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoVisitor1Element* pIElement = 0;
    IEcoToolchainAST1Declaration* pIDeclaration = 0;
    int16_t result = 0;
    uint32_t index = 0;

    /* �������� ���������� */
    if (me == 0 || pIBlockDeclarations == 0) {
        return -1;
    }

    pCMe->m_log->pVTbl->Info(pCMe->m_log, "[LLVM Visitor] EmitBlockDeclarations() called\n");

    pIDeclaration = pIBlockDeclarations->pVTbl->get_Declaration(pIBlockDeclarations, index);
    while (pIDeclaration != 0) {
        result = pIDeclaration->pVTbl->QueryInterface(pIDeclaration, &IID_IEcoVisitor1Element, (void**)&pIElement);
        if (result == 0 && pIElement != 0) {
            pIElement->pVTbl->Visit(pIElement, me);
            pIElement->pVTbl->Release(pIElement);
        }

        index++;
        pIDeclaration = pIBlockDeclarations->pVTbl->get_Declaration(pIBlockDeclarations, index);
    }


    return result;
}

ScopedValue* CEcoToolchainEmitterLLVMIR1Visitor_CreateUnnamedValue(struct IEcoVisitor1* me, LLVMValueRef val, LLVMTypeRef type, LLVMValueRef allocaVal) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    ScopedValue* sVal = 0;

    if (me == 0) {
        return 0;
    }

    sVal = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, sizeof(ScopedValue));
    sVal->pVal = val;
    sVal->pType = type;
    sVal->pAlloca = allocaVal;

    pCMe->ScopeAddUnnamed(me, sVal);

    return sVal;
}

ScopedValue* CEcoToolchainEmitterLLVMIR1Visitor_CreateNamedValue(struct IEcoVisitor1* me, char_t* name, LLVMValueRef val, LLVMTypeRef type, LLVMValueRef allocaVal) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    ScopedValue* sVal = 0;

    if (me == 0 || name == 0 || allocaVal == 0 || type == 0) {
        return 0;
    }

    sVal = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, sizeof(ScopedValue));
    sVal->pVal = val;
    sVal->pType = type;
    sVal->pAlloca = allocaVal;

    pCMe->ScopeAddNamed(me, name, sVal);

    return sVal;
}

void CEcoToolchainEmitterLLVMIR1Visitor_ScopeNext(struct IEcoVisitor1* me) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoInterfaceBus1* pIBus = 0;
    Scope* newScope = 0;
    IEcoMap1* namedVals = 0;
    IEcoList1* unnamedVals = 0;

    /* Get interface bus */
    pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);

    /* Query named values map and list of unnamed values */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMap1, 0, &IID_IEcoMap1, (void**)&namedVals);
    namedVals->pVTbl->InitByType(namedVals, ECO_COMPARATOR_1_STRING_TYPE, ECO_COMPARATOR_1_POINTER_TYPE);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&unnamedVals);

    /* Allocate and initialize new scope */
    newScope = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, sizeof(Scope));
    newScope->namedVals = namedVals;
    newScope->unnamedVals = unnamedVals;

    /* Add new scope to list of scopes */
    pCMe->m_scopesList->pVTbl->Add(pCMe->m_scopesList, newScope);
    pCMe->m_scopeNumber++;

    pIBus->pVTbl->Release(pIBus);
}

void CEcoToolchainEmitterLLVMIR1Visitor_ScopePrev(struct IEcoVisitor1* me) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoMap1Iterator* namedValsIt = 0;
    Scope* scope = 0;
    ScopedValue* val = 0;
    uint32_t unnamedCnt = 0, i = 0;

    scope = pCMe->m_scopesList->pVTbl->Item(pCMe->m_scopesList, pCMe->m_scopeNumber - 1);
    
    /* Iterate over named values and deallocate them */
    if (!scope->namedVals->pVTbl->IsEmpty(scope->namedVals)) {
        namedValsIt = scope->namedVals->pVTbl->Get_IterBegin(scope->namedVals);
        while (namedValsIt->pVTbl->HasNext(namedValsIt)) {
            val = namedValsIt->pVTbl->Get_Value(namedValsIt);
            pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, val);

            namedValsIt->pVTbl->GoToNext(namedValsIt);
        }
    }

    /* Iterate over unnamed values and deallocate them */
    unnamedCnt = scope->unnamedVals->pVTbl->Count(scope->unnamedVals);
    if (unnamedCnt != 0) {
        for (i = 0; i < unnamedCnt; ++i) {
            val = scope->unnamedVals->pVTbl->Item(scope->unnamedVals, i);
            pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, val);
        }
    }

    /* Release components */
    scope->namedVals->pVTbl->Release(scope->namedVals);
    scope->unnamedVals->pVTbl->Release(scope->unnamedVals);

    /* Remove scope from list */
    pCMe->m_scopesList->pVTbl->RemoveAt(pCMe->m_scopesList, pCMe->m_scopeNumber - 1);
    pCMe->m_scopeNumber--;
    
    /* Deallocate scope */
    pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, scope);
}

void CEcoToolchainEmitterLLVMIR1Visitor_ScopeAddNamed(struct IEcoVisitor1* me, char_t* name, ScopedValue* val) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    Scope* scope = 0;

    scope = pCMe->m_scopesList->pVTbl->Item(pCMe->m_scopesList, pCMe->m_scopeNumber - 1);
    scope->namedVals->pVTbl->Set(scope->namedVals, name, val);
}

void CEcoToolchainEmitterLLVMIR1Visitor_ScopeAddUnnamed(struct IEcoVisitor1* me, ScopedValue* val) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    Scope* scope = 0;

    scope = pCMe->m_scopesList->pVTbl->Item(pCMe->m_scopesList, pCMe->m_scopeNumber - 1);
    scope->unnamedVals->pVTbl->Add(scope->unnamedVals, val);
}

ScopedValue* CEcoToolchainEmitterLLVMIR1Visitor_ScopeGetNamed(struct IEcoVisitor1* me, char_t* name) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    Scope* scope = 0;

    scope = pCMe->m_scopesList->pVTbl->Item(pCMe->m_scopesList, pCMe->m_scopeNumber - 1);
    return scope->namedVals->pVTbl->Get(scope->namedVals, name);
}

void CEcoToolchainEmitterLLVMIR1Visitor_AddStruct(/* in */ struct IEcoVisitor1* me, /* in */ char_t* structName) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMap1* pMap = 0;

    /* Create new map of fields for struct */
    pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMap1, 0, &IID_IEcoMap1, (void**)&pMap);
    pMap->pVTbl->InitByType(pMap, ECO_COMPARATOR_1_STRING_TYPE, ECO_COMPARATOR_1_POINTER_TYPE);

    /* Insert to map */
    pCMe->m_structsFieldsMap->pVTbl->Set(pCMe->m_structsFieldsMap, structName, pMap);
}

void CEcoToolchainEmitterLLVMIR1Visitor_SetStructFieldInfo(struct IEcoVisitor1* me, char_t* structName, char_t* fieldName, uint32_t fieldIdx, LLVMTypeRef fieldType) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoMap1* pMap = 0;
    StructFieldInfo* info = 0;

    pMap = pCMe->m_structsFieldsMap->pVTbl->Get(pCMe->m_structsFieldsMap, structName);

    info = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, sizeof(StructFieldInfo));
    info->idx = fieldIdx;
    info->type = fieldType;
    pMap->pVTbl->Set(pMap, fieldName, info);
}

StructFieldInfo* CEcoToolchainEmitterLLVMIR1Visitor_GetStructFieldInfo(struct IEcoVisitor1* me, char_t* structName, char_t* fieldName) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)me;
    IEcoMap1* pMap = 0;

    pMap = pCMe->m_structsFieldsMap->pVTbl->Get(pCMe->m_structsFieldsMap, structName);
    return pMap->pVTbl->Get(pMap, fieldName);
}

static void drainStructFieldsMap(IEcoMap1* map, IEcoMemoryAllocator1* pIMem) {
    IEcoMap1Iterator* it = 0, *innerIt = 0;
    IEcoMap1* pInnerMap = 0;
    StructFieldInfo* fieldInfo = 0;

    /* Iter over structs */
    if (!map->pVTbl->IsEmpty(map)) {
        it = map->pVTbl->Get_IterBegin(map);
        while (it->pVTbl->HasNext(it)) {
            pInnerMap = it->pVTbl->Get_Value(it);

            /* Iter over fields */
            if (!pInnerMap->pVTbl->IsEmpty(pInnerMap)) {
                innerIt = pInnerMap->pVTbl->Get_IterBegin(pInnerMap);
                while (innerIt->pVTbl->HasNext(innerIt)) {
                    fieldInfo = innerIt->pVTbl->Get_Value(innerIt);
                    pIMem->pVTbl->Free(pIMem, fieldInfo);
                    innerIt->pVTbl->GoToNext(innerIt);
                }
            }

            pInnerMap->pVTbl->Release(pInnerMap);

            it->pVTbl->GoToNext(it);
        }
    }
}

/* Create Virtual Table */
IEcoVisitor1VTbl g_xC5CCED1755D74106A5F315694AC2C99FVTbl = {
    CEcoToolchainEmitterLLVMIR1Visitor_QueryInterface,
    CEcoToolchainEmitterLLVMIR1Visitor_AddRef,
    CEcoToolchainEmitterLLVMIR1Visitor_Release,
    CEcoToolchainEmitterLLVMIR1Visitor_Accept
};

/*
 *
 * <������>
 *   ������� Create
 * </������>
 *
 * <��������>
 *   ������� �������� ����������
 * </��������>
 *
 */
int16_t createCEcoToolchainEmitterLLVMIR1Visitor(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoVisitor1** ppIVisitor) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = 0;
    IEcoLog1FileAffiliate* pIFileAffiliate = 0;

    /* �������� ���������� */
    if (ppIVisitor == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* ��������� ���������� ���������� ���������� */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void**)&pISys);

    /* �������� */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* ��������� ���������� ��� ������ � ������������ ����� */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);

    /* ��������� ���������� �������������� ������ */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**)&pIMem);

    /* �������� */
    if (result != 0 && pIMem == 0) {
        /* ������������ ���������� ���������� � ������ ������ */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* ��������� ������ ��� ������ ���������� */
    pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoToolchainEmitterLLVMIR1Visitor));

    /* ���������� ��������� �� ��������� ��� ������ � ������� */
    pCMe->m_pIMem = pIMem;

    pCMe->m_pISys = pISys;

    /* ��������� �������� ������ �� ��������� */
    pCMe->m_cRef = 1;

    /* �������� ������� ������� ���������� IEcoToolchainEmitterLLVMIR1 */
    pCMe->m_pVTblIVisitor = &g_xC5CCED1755D74106A5F315694AC2C99FVTbl;

    /* ������������� ������ */
    pCMe->EmitBinaryExpression = CEcoToolchainEmitterLLVMIR1Visitor_EmitBinaryExpression;
    pCMe->EmitMemberSelection = CEcoToolchainEmitterLLVMIR1Visitor_EmitMemberSelection;
    pCMe->EmitUnaryExpression = CEcoToolchainEmitterLLVMIR1Visitor_EmitUnaryExpression;
    pCMe->EmitIntegerLiteral = CEcoToolchainEmitterLLVMIR1Visitor_EmitIntegerLiteral;
    pCMe->EmitFloatLiteral = CEcoToolchainEmitterLLVMIR1Visitor_EmitFloatLiteral;
    pCMe->EmitStringLiteral = CEcoToolchainEmitterLLVMIR1Visitor_EmitStringLiteral;
    pCMe->EmitNumberType = CEcoToolchainEmitterLLVMIR1Visitor_EmitNumberType;
    pCMe->EmitStructOrUnionType = CEcoToolchainEmitterLLVMIR1Visitor_EmitStructOrUnionType;
    pCMe->EmitArrayType = CEcoToolchainEmitterLLVMIR1Visitor_EmitArrayType;
    pCMe->EmitPointerType = CEcoToolchainEmitterLLVMIR1Visitor_EmitPointerType;
    pCMe->EmitVariableDeclaration = CEcoToolchainEmitterLLVMIR1Visitor_EmitVariableDeclaration;
    pCMe->EmitStructOrUnionDeclaration = CEcoToolchainEmitterLLVMIR1Visitor_EmitStructOrUnionDeclaration;
    pCMe->EmitVariableDefinition = CEcoToolchainEmitterLLVMIR1Visitor_EmitVariableDefinition;
    pCMe->EmitCastExpression = CEcoToolchainEmitterLLVMIR1Visitor_EmitCastExpression;
    pCMe->EmitConditionalExpression = CEcoToolchainEmitterLLVMIR1Visitor_EmitConditionalExpression;
    pCMe->EmitSizeofType = CEcoToolchainEmitterLLVMIR1Visitor_EmitSizeofType;
    pCMe->EmitSizeofExpression = CEcoToolchainEmitterLLVMIR1Visitor_EmitSizeofExpression;
    pCMe->EmitNullExpression = CEcoToolchainEmitterLLVMIR1Visitor_EmitNullExpression;
    pCMe->EmitBlockExpressions = CEcoToolchainEmitterLLVMIR1Visitor_EmitBlockExpressions;
    pCMe->EmitBreakStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitBreakStatement;
    pCMe->EmitDefaultStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitDefaultStatement;
    pCMe->EmitCompoundStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitCompoundStatement;
    pCMe->EmitContinueStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitContinueStatement;
    pCMe->EmitReturnStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitReturnStatement;
    pCMe->EmitGoToStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitGoToStatement;
    pCMe->EmitIfStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitIfStatement;
    pCMe->EmitForStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitForStatement;
    pCMe->EmitWhileStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitWhileStatement;
    pCMe->EmitDoWhileStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitDoWhileStatement;
    pCMe->EmitSwitchStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitSwitchStatement;
    pCMe->EmitTranslationUnit = CEcoToolchainEmitterLLVMIR1Visitor_EmitTranslationUnit;
    pCMe->EmitBlockTranslationUnitObject = CEcoToolchainEmitterLLVMIR1Visitor_EmitBlockTranslationUnitObject;
    pCMe->EmitCaseStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitCaseStatement;
    pCMe->EmitLabelStatement = CEcoToolchainEmitterLLVMIR1Visitor_EmitLabelStatement;
    pCMe->EmitBlockStatements = CEcoToolchainEmitterLLVMIR1Visitor_EmitBlockStatements;
    pCMe->EmitFunctionType = CEcoToolchainEmitterLLVMIR1Visitor_EmitFunctionType;
    pCMe->EmitBlockTypes = CEcoToolchainEmitterLLVMIR1Visitor_EmitBlockTypes;
    pCMe->EmitFunctionDeclaration = CEcoToolchainEmitterLLVMIR1Visitor_EmitFunctionDeclaration;
    pCMe->EmitFunctionDefinition = CEcoToolchainEmitterLLVMIR1Visitor_EmitFunctionDefinition;
    pCMe->EmitFunctionCall = CEcoToolchainEmitterLLVMIR1Visitor_EmitFunctionCall;
    pCMe->EmitBlockDeclarations = CEcoToolchainEmitterLLVMIR1Visitor_EmitBlockDeclarations;
    
    /* Scope-related */
    pCMe->CreateNamedValue = CEcoToolchainEmitterLLVMIR1Visitor_CreateNamedValue;
    pCMe->CreateUnnamedValue = CEcoToolchainEmitterLLVMIR1Visitor_CreateUnnamedValue;
    pCMe->ScopeNext = CEcoToolchainEmitterLLVMIR1Visitor_ScopeNext;
    pCMe->ScopePrev = CEcoToolchainEmitterLLVMIR1Visitor_ScopePrev;
    pCMe->ScopeAddNamed = CEcoToolchainEmitterLLVMIR1Visitor_ScopeAddNamed;
    pCMe->ScopeAddUnnamed = CEcoToolchainEmitterLLVMIR1Visitor_ScopeAddUnnamed;
    pCMe->ScopeGetNamed = CEcoToolchainEmitterLLVMIR1Visitor_ScopeGetNamed;
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoList1, 0, &IID_IEcoList1, (void**)&pCMe->m_scopesList);

    /* LLVM-related */
    pCMe->m_pContext = LLVMContextCreate();
    pCMe->m_pBuilder = LLVMCreateBuilderInContext(pCMe->m_pContext);

    /* Struct-related */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMap1, 0, &IID_IEcoMap1, (void**)&pCMe->m_structsFieldsMap);
    pCMe->m_structsFieldsMap->pVTbl->InitByType(pCMe->m_structsFieldsMap, ECO_COMPARATOR_1_STRING_TYPE, ECO_COMPARATOR_1_POINTER_TYPE);
    pCMe->AddStruct = CEcoToolchainEmitterLLVMIR1Visitor_AddStruct;
    pCMe->SetStructFieldInfo = CEcoToolchainEmitterLLVMIR1Visitor_SetStructFieldInfo;
    pCMe->GetStructFieldInfo = CEcoToolchainEmitterLLVMIR1Visitor_GetStructFieldInfo;

    /* Log, for debug */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1, (void**)&pCMe->m_log);
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1FileAffiliate, (void**)&pIFileAffiliate);
    pCMe->m_log->pVTbl->AddAffiliate(pCMe->m_log, (IEcoLog1Affiliate*)pIFileAffiliate);
    pIFileAffiliate->pVTbl->Release(pIFileAffiliate);

    pCMe->get_Module = CEcoToolchainEmitterLLVMIR1Visitor_get_Module;

    /* ������� ��������� �� ��������� */
    *ppIVisitor = (IEcoVisitor1*)pCMe;

    /* ������������ */
    pIBus->pVTbl->Release(pIBus);

    return result;
}

/*
 *
 * <������>
 *   ������� Delete
 * </������>
 *
 * <��������>
 *   ������� ������������ ����������
 * </��������>
 *
 */
void deleteCEcoToolchainEmitterLLVMIR1Visitor(/* in */ IEcoVisitor1* pIVisitor) {
    CEcoToolchainEmitterLLVMIR1Visitor* pCMe = (CEcoToolchainEmitterLLVMIR1Visitor*)pIVisitor;
    
    if (pCMe->m_pLLVMModule) {
        LLVMDisposeModule(pCMe->m_pLLVMModule);
    }
    if (pCMe->m_pBuilder) {
        LLVMDisposeBuilder(pCMe->m_pBuilder);
    }
    if (pCMe->m_pContext) {
        LLVMContextDispose(pCMe->m_pContext);
    }
    if (pCMe->m_scopesList) {
        pCMe->m_scopesList->pVTbl->Release(pCMe->m_scopesList);
    }
    if (pCMe->m_log != 0) {
        pCMe->m_log->pVTbl->Release(pCMe->m_log);
    }
    if (pCMe->m_structsFieldsMap != 0) {
        drainStructFieldsMap(pCMe->m_structsFieldsMap, pCMe->m_pIMem);
        pCMe->m_structsFieldsMap->pVTbl->Release(pCMe->m_structsFieldsMap);
    }
    pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, pCMe);
    pCMe->m_pIMem->pVTbl->Release(pCMe->m_pIMem);
}
