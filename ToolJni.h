
#ifndef __TOOLJNI_H__
#define __TOOLJNI_H__

#include "cocos2d.h"
#include "JniBack.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)  
#include <jni.h>  
#include "platform/android/jni/JniHelper.h"  
#include <android/log.h>  
#endif

USING_NS_CC;

enum JNI_X_TAG{
	JNI_MAINMENU,              //�������˵�����
	JNI_START_SELECTMENU,      //������ͨģʽ����ѡ�����
	JNI_CHALLENGE_SELECTMENU,  //������սģʽ����ѡ�����
	JNI_GAME_BEGAIN,           //��Ϸ��ʼ
	JNI_GAME_PAUSE,            //��Ϸ��ͣ
	JNI_GAME_RESUME,           //��Ϸ����
	JNI_GAME_OVER,             //��Ϸ����
	JNI_EXIT,                  //�˳���Ϸ
	JNI_CLASSIC,               //����ģʽ
};

class ToolJni : public CCObject{
public:
	static ToolJni* init();

	void revMessage(const char* message,int x_tag);

	void sendMessage(const char* data,int x_tag);

	void setCallBack(JniBack *j);

private:
	JniBack *jniback;
};

#endif