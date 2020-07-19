LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := test.cpp

LOCAL_MODULE:= libtestneon

LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)
