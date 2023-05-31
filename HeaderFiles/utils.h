#ifndef _LLVM_EMITTER_UTILS_
#define _LLVM_EMITTER_UTILS_

#include <llvm-c/Core.h>

#include "IEcoVisitor1.h"


static LLVMValueRef _createAllocaAtEntry(LLVMValueRef fn, LLVMTypeRef type, char_t* name) {
    LLVMValueRef result = 0;
    LLVMBuilderRef builder = LLVMCreateBuilder();

    LLVMPositionBuilderAtEnd(builder, LLVMGetEntryBasicBlock(fn));
    LLVMBuildAlloca(builder, type, name);

    LLVMDisposeBuilder(builder);
    return result;
}

LLVMTypeRef _primitiveType2LLVM(LLVMContextRef ctx, int16_t tag) {
    switch (tag) {
    case ECO_TOOLCHAIN_AST1_TYPE_VOID: return LLVMVoidTypeInContext(ctx);
    case ECO_TOOLCHAIN_AST1_TYPE_CHAR: return LLVMInt8TypeInContext(ctx);
    case ECO_TOOLCHAIN_AST1_TYPE_SHORT: return LLVMInt16TypeInContext(ctx);
    case ECO_TOOLCHAIN_AST1_TYPE_INT: return LLVMInt32TypeInContext(ctx);
    case ECO_TOOLCHAIN_AST1_TYPE_LONG: return LLVMInt64TypeInContext(ctx);
    case ECO_TOOLCHAIN_AST1_TYPE_LONG_LONG: return LLVMInt128TypeInContext(ctx);
    case ECO_TOOLCHAIN_AST1_TYPE_FLOAT: return LLVMFloatTypeInContext(ctx);
    case ECO_TOOLCHAIN_AST1_TYPE_DOUBLE: return LLVMDoubleTypeInContext(ctx);
    case ECO_TOOLCHAIN_AST1_TYPE_LONG_DOUBLE: return LLVMFP128TypeInContext(ctx);
    default: return 0; // unreachable
    }
}

static bool_t _isFloatingPointTy(LLVMTypeRef type) {
    LLVMTypeKind t = LLVMGetTypeKind(type);
    return (t == LLVMHalfTypeKind) || (t == LLVMBFloatTypeKind) ||
        (t == LLVMFloatTypeKind) || (t == LLVMDoubleTypeKind) ||
        (t == LLVMX86_FP80TypeKind) || (t == LLVMFP128TypeKind) || (t == LLVMPPC_FP128TypeKind);
}

static bool_t _isIntegerTy(LLVMTypeRef type) {
    LLVMTypeKind t = LLVMGetTypeKind(type);
    return (t == LLVMIntegerTypeKind);
}

static uint32_t parseInteger(char_t* str) {
    uint32_t i = 0, res = 0;
    while (str[i] && (str[i] >= '0' && str[i] <= '9')) {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res;
}

int16_t emit(struct CEcoToolchainEmitterLLVMIR1Visitor* visitor, void* obj, void** out) {
    int16_t result = 0;
    result = visitor->m_pVTblIVisitor->Accept((IEcoVisitor1*)visitor, obj);

    if (out != 0) {
        *out = visitor->m_pRetVal;
    }

    visitor->m_pRetVal = 0;
    return result;
}

#endif // _LLVM_EMITTER_UTILS_
