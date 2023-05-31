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
 *   Данный исходный код описывает реализацию интерфейсов CEcoToolchainEmitterLLVMIR1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoToolchainEmitterLLVMIR1.h"
#include "CEcoToolchainEmitterLLVMIR1Visitor.h"


/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoToolchainEmitterLLVMIR1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoToolchainEmitterLLVMIR1_QueryInterface(/* in */ struct IEcoToolchainEmitterLLVMIR1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoToolchainEmitterLLVMIR1* pCMe = (CEcoToolchainEmitterLLVMIR1*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoToolchainEmitterLLVMIR1) ) {
        *ppv = &pCMe->m_pVTblIEcoToolchainEmitterLLVMIR1;
        pCMe->m_pVTblIEcoToolchainEmitterLLVMIR1->AddRef((IEcoToolchainEmitterLLVMIR1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoToolchainEmitterLLVMIR1;
        pCMe->m_pVTblIEcoToolchainEmitterLLVMIR1->AddRef((IEcoToolchainEmitterLLVMIR1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoToolchainEmitterLLVMIR1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoToolchainEmitterLLVMIR1_AddRef(/* in */ struct IEcoToolchainEmitterLLVMIR1* me) {
    CEcoToolchainEmitterLLVMIR1* pCMe = (CEcoToolchainEmitterLLVMIR1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoToolchainEmitterLLVMIR1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoToolchainEmitterLLVMIR1_Release(/* in */ struct IEcoToolchainEmitterLLVMIR1* me) {
    CEcoToolchainEmitterLLVMIR1* pCMe = (CEcoToolchainEmitterLLVMIR1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoToolchainEmitterLLVMIR1((IEcoToolchainEmitterLLVMIR1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция EmitCode
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoToolchainEmitterLLVMIR1_EmitCode(/* in */ struct IEcoToolchainEmitterLLVMIR1* me, /* in */ struct IEcoToolchainAST1SyntaxObject* pISyntaxObj) {
    CEcoToolchainEmitterLLVMIR1* pCMe = (CEcoToolchainEmitterLLVMIR1*)me;
    IEcoVisitor1Element* pIElement = 0;
    int16_t result = 0;

    /* Проверка указателей */
    if (me == 0 || pISyntaxObj == 0) {
        return -1;
    }

    /* Проверка визитора */
    if (pCMe->m_pIVisitor == 0) {
        result = createCEcoToolchainEmitterLLVMIR1Visitor((IEcoUnknown*)pCMe->m_pISys, 0, &pCMe->m_pIVisitor);
        if (result == -1 || pCMe->m_pIVisitor == 0) {
            return -1;
        }
    }

    /* Проверка работы элемента визитора */
    result = pISyntaxObj->pVTbl->QueryInterface(pISyntaxObj, &IID_IEcoVisitor1Element, (void**)&pIElement);
    if (result == 0 && pIElement != 0) {
       /* Посещение визитором объекта (элемента) */
       pIElement->pVTbl->Visit(pIElement, pCMe->m_pIVisitor);
       pIElement->pVTbl->Release(pIElement);
    } else {
       return -1;
    }

    return 0;
}


/*
 *
 * <сводка>
 *   Функция WriteObjectFile
 * </сводка>
 *
 * <описание>
 *   Dumps current module to object file
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoToolchainEmitterLLVMIR1_WriteObjectFile(struct IEcoToolchainEmitterLLVMIR1* me, char_t* filename, EmitterLLVMIROptLevel opt) {
    CEcoToolchainEmitterLLVMIR1* pCMe = (CEcoToolchainEmitterLLVMIR1*)me;

    char_t* triple = 0;
    char_t* error = 0;
    char_t* host_cpu = 0;
    char_t* features = 0;
    int16_t result = 0;

    LLVMTargetRef target;
    LLVMModuleRef mod = 0;
    LLVMTargetMachineRef targetMachine = 0;

    /* Проверка указателей */
    if (me == 0 || filename == 0) {
        return -1;
    }

    triple = LLVMGetDefaultTargetTriple();

    LLVMGetTargetFromTriple(triple, &target, &error);
    host_cpu = LLVMGetHostCPUName();
    features = LLVMGetHostCPUFeatures();

    targetMachine = LLVMCreateTargetMachine(
        target,
        triple,
        host_cpu,
        features,
        (LLVMCodeGenOptLevel)opt,
        LLVMRelocDefault,
        LLVMCodeModelDefault
    );

    mod = ((CEcoToolchainEmitterLLVMIR1Visitor*)(pCMe->m_pIVisitor))->get_Module(pCMe->m_pIVisitor);
    result = LLVMTargetMachineEmitToFile(targetMachine, mod, filename, LLVMObjectFile, &error); // TODO handle error

    if (error) {
        LLVMDisposeMessage(error);
    }
    LLVMDisposeMessage(triple);
    LLVMDisposeMessage(host_cpu);
    LLVMDisposeMessage(features);
    LLVMDisposeTargetMachine(targetMachine);
    return result;
}

/*
 *
 * <сводка>
 *   Функция WriteAssemblyFile
 * </сводка>
 *
 * <описание>
 *   Dumps current module to assembly file
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoToolchainEmitterLLVMIR1_WriteAssemblyFile(struct IEcoToolchainEmitterLLVMIR1* me, char_t* filename, EmitterLLVMIROptLevel opt) {
    CEcoToolchainEmitterLLVMIR1* pCMe = (CEcoToolchainEmitterLLVMIR1*)me;

    char_t* triple = 0;
    char_t* error = 0;
    char_t* host_cpu = 0;
    char_t* features = 0;
    int16_t result = 0;

    LLVMTargetRef target;
    LLVMModuleRef mod = 0;
    LLVMTargetMachineRef targetMachine = 0;

    /* Проверка указателей */
    if (me == 0 || filename == 0) {
        return -1;
    }

    triple = LLVMGetDefaultTargetTriple();

    LLVMGetTargetFromTriple(triple, &target, &error);
    host_cpu = LLVMGetHostCPUName();
    features = LLVMGetHostCPUFeatures();

    targetMachine = LLVMCreateTargetMachine(
        target,
        triple,
        host_cpu,
        features,
        (LLVMCodeGenOptLevel)opt,
        LLVMRelocDefault,
        LLVMCodeModelDefault
    );

    mod = ((CEcoToolchainEmitterLLVMIR1Visitor*)(pCMe->m_pIVisitor))->get_Module(pCMe->m_pIVisitor);
    result = LLVMTargetMachineEmitToFile(targetMachine, mod, filename, LLVMAssemblyFile, &error); // TODO handle error

    if (error) {
        LLVMDisposeMessage(error);
    }
    LLVMDisposeMessage(triple);
    LLVMDisposeMessage(host_cpu);
    LLVMDisposeMessage(features);
    LLVMDisposeTargetMachine(targetMachine);
    return result;
}

/*
 *
 * <сводка>
 *   Функция WriteIRFile
 * </сводка>
 *
 * <описание>
 *   Dumps current module to file in LLVM IR format
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoToolchainEmitterLLVMIR1_WriteIRFile(/* in */ struct IEcoToolchainEmitterLLVMIR1* me, /* in */ char_t* filename) {
    CEcoToolchainEmitterLLVMIR1* pCMe = (CEcoToolchainEmitterLLVMIR1*)me;
    int16_t result = 0;

    LLVMModuleRef mod = 0;
    char_t* error;

    /* Проверка указателей */
    if (me == 0 || filename == 0) {
        return -1;
    }

    mod = ((CEcoToolchainEmitterLLVMIR1Visitor*)(pCMe->m_pIVisitor))->get_Module(pCMe->m_pIVisitor);
    result = LLVMPrintModuleToFile(mod, filename, &error); // TODO handle error

    return result;
}


/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoToolchainEmitterLLVMIR1(/*in*/ struct IEcoToolchainEmitterLLVMIR1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoToolchainEmitterLLVMIR1* pCMe = (CEcoToolchainEmitterLLVMIR1*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
    return result;
}

/* Create Virtual Table IEcoToolchainEmitterLLVMIR1 */
IEcoToolchainEmitterLLVMIR1VTbl g_x432C15A4BF5E46639F7C99EC2ACB5D20VTbl = {
    CEcoToolchainEmitterLLVMIR1_QueryInterface,
    CEcoToolchainEmitterLLVMIR1_AddRef,
    CEcoToolchainEmitterLLVMIR1_Release,
    CEcoToolchainEmitterLLVMIR1_EmitCode,
    CEcoToolchainEmitterLLVMIR1_WriteObjectFile,
    CEcoToolchainEmitterLLVMIR1_WriteAssemblyFile,
    CEcoToolchainEmitterLLVMIR1_WriteIRFile
};




/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoToolchainEmitterLLVMIR1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoToolchainEmitterLLVMIR1** ppIEcoToolchainEmitterLLVMIR1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoToolchainEmitterLLVMIR1* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoToolchainEmitterLLVMIR1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoToolchainEmitterLLVMIR1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoToolchainEmitterLLVMIR1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoToolchainEmitterLLVMIR1 */
    pCMe->m_pVTblIEcoToolchainEmitterLLVMIR1 = &g_x432C15A4BF5E46639F7C99EC2ACB5D20VTbl;

    /* Возврат указателя на интерфейс */
    *ppIEcoToolchainEmitterLLVMIR1 = (IEcoToolchainEmitterLLVMIR1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoToolchainEmitterLLVMIR1(/* in */ IEcoToolchainEmitterLLVMIR1* pIEcoToolchainEmitterLLVMIR1) {
    CEcoToolchainEmitterLLVMIR1* pCMe = (CEcoToolchainEmitterLLVMIR1*)pIEcoToolchainEmitterLLVMIR1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoToolchainEmitterLLVMIR1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        if (pCMe->m_pIVisitor != 0) {
            pCMe->m_pIVisitor->pVTbl->Release(pCMe->m_pIVisitor);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
