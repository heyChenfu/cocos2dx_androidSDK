//revMessage接受数据是没问题的不过要使用JniBack要保证setCallBack已经执行了
//还有一点，android onCreate执行要早于 cocos init。所以在onCreate发送消息到cocos，cocos init设置监听，也来不及。

#include "ToolJni.h"
//我将这里的nullptr修改为NULL
static ToolJni *xx_tooljni = NULL;

ToolJni* ToolJni::init(){
	if (xx_tooljni == NULL){
        xx_tooljni = new ToolJni();
    }
    return xx_tooljni;
}

void ToolJni::revMessage(const char* message,int x_tag){
	jniback->revBack(message,x_tag);
}
//被extern "C"修饰的变量和函数是按照C语言方式编译和连接的
extern "C"
{
	#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
		void Java_com_xiaohu_tool_jni_ToolJni_sendJniMessage(JNIEnv*  env, jobject thiz, jstring info,jint a){
			const char *temp = env->GetStringUTFChars(info, NULL);
			ToolJni::init()->revMessage(temp,a);
		}
	#endif
}

void ToolJni::sendMessage(const char* data,int x_tag){
	#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
		JniMethodInfo minfo;
		if (JniHelper::getStaticMethodInfo(minfo,"com/xiaohu/tool/jni/ToolJni", "revMessage", "(Ljava/lang/String;I)V")){
	//	if (JniHelper::getStaticMethodInfo(minfo,"com/xiaohu/tool/jni/ToolJni", "revMessage", "(Ljava/lang/String;)V")){
			jstring jdata = minfo.env->NewStringUTF(data);
			minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID,jdata,x_tag);
		}
	#endif
}

//void ToolJni::setCallBack(JniBack *j){
//	jniback = j;
//}