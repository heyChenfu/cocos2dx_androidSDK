LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

#traverse all the directory and subdirectory
define walk
  $(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk, $(e)))
endef
#traverse Classes Directory
ALLFILES = $(call walk, $(LOCAL_PATH)/../../Classes)
FILE_LIST := hellocpp/main.cpp
FILE_LIST += $(filter %.cpp, $(ALLFILES))
FILE_INCLUDES := $(shell find $(LOCAL_PATH)/../../Classes -type d)
#source file will be compiled
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
