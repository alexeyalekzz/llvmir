/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoToolchainEmitterLLVMIR1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoToolchainEmitterLLVMIR1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECOTOOLCHAINEMITTERLLVMIR1_H__
#define __I_ECOTOOLCHAINEMITTERLLVMIR1_H__

#include "IEcoBase1.h"
#include "IEcoToolchainAST1.h"

/* IEcoToolchainEmitterLLVMIR1 IID = {432C15A4-BF5E-4663-9F7C-99EC2ACB5D20} */
#ifndef __IID_IEcoToolchainEmitterLLVMIR1
static const UGUID IID_IEcoToolchainEmitterLLVMIR1 = {0x01, 0x10, 0x43, 0x2C, 0x15, 0xA4, 0xBF, 0x5E, 0x46, 0x63, 0x9F, 0x7C, 0x99, 0xEC, 0x2A, 0xCB, 0x5D, 0x20};
#endif /* __IID_IEcoToolchainEmitterLLVMIR1 */

typedef enum EmitterLLVMIROptLevel {
    OptLevelNone = 0,
    OptLevelLess,
    OptLevelDefault,
    OptLevelBest
} EmitterLLVMIROptLevel;

typedef struct IEcoToolchainEmitterLLVMIR1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ struct IEcoToolchainEmitterLLVMIR1* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ struct IEcoToolchainEmitterLLVMIR1* me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ struct IEcoToolchainEmitterLLVMIR1* me);

    /* IEcoToolchainEmitterLLVMIR1 */
    int16_t (ECOCALLMETHOD *EmitCode)(/* in */ struct IEcoToolchainEmitterLLVMIR1* me, /* in */ struct IEcoToolchainAST1SyntaxObject* pISyntaxObj);

    int16_t (ECOCALLMETHOD* WriteObjectFile)(/* in */ struct IEcoToolchainEmitterLLVMIR1* me, 
                                             /* in */ char_t* filename, EmitterLLVMIROptLevel opt);

    int16_t (ECOCALLMETHOD* WriteAssemblyFile)(/* in */ struct IEcoToolchainEmitterLLVMIR1* me,
                                               /* in */ char_t* filename, EmitterLLVMIROptLevel opt);

    int16_t (ECOCALLMETHOD* WriteIRFile)(/* in */ struct IEcoToolchainEmitterLLVMIR1* me, /* in */ char_t* filename);

} IEcoToolchainEmitterLLVMIR1VTbl, *IEcoToolchainEmitterLLVMIR1VTblPtr;

interface IEcoToolchainEmitterLLVMIR1 {
    struct IEcoToolchainEmitterLLVMIR1VTbl *pVTbl;
} IEcoToolchainEmitterLLVMIR1;


#endif /* __I_ECOTOOLCHAINEMITTERLLVMIR1_H__ */
