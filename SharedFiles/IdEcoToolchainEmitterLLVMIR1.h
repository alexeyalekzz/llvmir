/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoToolchainEmitterLLVMIR1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoToolchainEmitterLLVMIR1
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

#ifndef __ID_ECOTOOLCHAINEMITTERLLVMIR1_H__
#define __ID_ECOTOOLCHAINEMITTERLLVMIR1_H__

#include "IEcoBase1.h"
#include "IEcoToolchainEmitterLLVMIR1.h"

/* EcoToolchainEmitterLLVMIR1 CID = {C5CCED17-55D7-4106-A5F3-15694AC2C99F} */
#ifndef __CID_EcoToolchainEmitterLLVMIR1
static const UGUID CID_EcoToolchainEmitterLLVMIR1 = {0x01, 0x10, 0xC5, 0xCC, 0xED, 0x17, 0x55, 0xD7, 0x41, 0x06, 0xA5, 0xF3, 0x15, 0x69, 0x4A, 0xC2, 0xC9, 0x9F};
#endif /* __CID_EcoToolchainEmitterLLVMIR1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_C5CCED1755D74106A5F315694AC2C99F;
#endif

#endif /* __ID_ECOTOOLCHAINEMITTERLLVMIR1_H__ */
