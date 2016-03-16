package com.xiaohu.tool.jni;

import android.util.Log;

//ToolJni.sendJniMessage("test");
//implements JniBack
//ToolJni.setListen(this);

public class ToolJni {
	
	private static JniBack jniBack = null;

	public static native void sendJniMessage(String str,int tag);
	
	public static void revMessage(final String str,int x_tag){
		if(jniBack != null){
			jniBack.JniRevMessage(str,x_tag);
		}
	}
	
	public static void setListen(JniBack j){
		jniBack = j;
	}
}
