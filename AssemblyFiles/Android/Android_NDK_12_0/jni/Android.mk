LOCAL_PATH:= $(call my-dir)

#
# Eco.Toolchain.EmitterLLVMIR1
#
include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../../../Eco.Core1/SharedFiles
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../Eco.InterfaceBus1/SharedFiles
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../Eco.MemoryManager1/SharedFiles
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../HeaderFiles
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../SharedFiles
TARGET_PLATFORM := android-9
TARGET_OUT := $(LOCAL_PATH)/../../../../BuildFiles/Android/$(TARGET_ARCH_ABI)/$(CONFIGURATION)
LOCAL_SRC_FILES := ../../../../SourceFiles/CEcoToolchainEmitterLLVMIR1.c \
../../../../SourceFiles/CEcoToolchainEmitterLLVMIR1Factory.c

ifeq ($(TARGET_LINK),0)

LOCAL_MODULE := libC5CCED1755D74106A5F315694AC2C99F
LOCAL_CFLAGS := -std=c99 -DECO_LIB -DECO_ANDROID -DUGUID_UTILITY -D__ANDROID__

include $(BUILD_STATIC_LIBRARY)

else

LOCAL_MODULE := C5CCED1755D74106A5F315694AC2C99F
LOCAL_CFLAGS := -std=c99 -DECO_DLL -DECO_ANDROID -DUGUID_UTILITY -D__ANDROID__

include $(BUILD_SHARED_LIBRARY)

endif