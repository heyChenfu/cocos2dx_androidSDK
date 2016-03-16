//revMessage����������û����Ĳ���Ҫʹ��JniBackҪ��֤setCallBack�Ѿ�ִ����
//����һ�㣬android onCreateִ��Ҫ���� cocos init��������onCreate������Ϣ��cocos��cocos init���ü�����Ҳ��������

#include "ToolJni.h"
//�ҽ������nullptr�޸�ΪNULL
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
//��extern "C"���εı����ͺ����ǰ���C���Է�ʽ��������ӵ�
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