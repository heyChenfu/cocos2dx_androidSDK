
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
	JNI_MAINMENU,              //进入主菜单界面
	JNI_START_SELECTMENU,      //进入普通模式人物选择界面
	JNI_CHALLENGE_SELECTMENU,  //进入挑战模式人物选择界面
	JNI_GAME_BEGAIN,           //游戏开始
	JNI_GAME_PAUSE,            //游戏暂停
	JNI_GAME_RESUME,           //游戏继续
	JNI_GAME_OVER,             //游戏结束
	JNI_EXIT,                  //退出游戏
	JNI_CLASSIC,               //天梯模式
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