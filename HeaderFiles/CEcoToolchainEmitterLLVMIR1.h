/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoToolchainEmitterLLVMIR1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoToolchainEmitterLLVMIR1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOTOOLCHAINEMITTERLLVMIR1_H__
#define __C_ECOTOOLCHAINEMITTERLLVMIR1_H__

#include "IEcoToolchainEmitterLLVMIR1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoVisitor1.h"

#include <llvm-c/Target.h>
#include <llvm-c/TargetMachine.h>


typedef struct CEcoToolchainEmitterLLVMIR1 {

    /* Таблица функций интерфейса IEcoToolchainEmitterLLVMIR1 */
    IEcoToolchainEmitterLLVMIR1VTbl* m_pVTblIEcoToolchainEmitterLLVMIR1;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Визитор */
    IEcoVisitor1* m_pIVisitor;

} CEcoToolchainEmitterLLVMIR1, *CEcoToolchainEmitterLLVMIR1Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoToolchainEmitterLLVMIR1(/*in*/ struct IEcoToolchainEmitterLLVMIR1* me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoToolchainEmitterLLVMIR1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoToolchainEmitterLLVMIR1** ppIEcoToolchainEmitterLLVMIR1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoToolchainEmitterLLVMIR1(/* in */ IEcoToolchainEmitterLLVMIR1* pIEcoToolchainEmitterLLVMIR1);

#endif /* __C_ECOTOOLCHAINEMITTERLLVMIR1_H__ */
