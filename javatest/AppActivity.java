/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import org.cocos2dx.lib.Cocos2dxActivity;
import com.xiaohu.tool.jni.JniBack;
import com.xiaohu.tool.jni.ToolJni;
import android.util.Log;

public class AppActivity extends Cocos2dxActivity implements JniBack {
	private final int JNI_MAINMENU = 0;              //进入主菜单界面
	private final int JNI_START_SELECTMENU = 1;      //进入普通模式人物选择界面
	private final int JNI_CHALLENGE_SELECTMENU = 2;  //进入挑战模式人物选择界面
	private final int JNI_TRAININGSCENE = 3;         //进入训练界面
	private final int JNI_GAME_BEGAIN = 4;           //游戏开始
	private final int JNI_GAME_PAUSE = 5;            //游戏暂停
	private final int JNI_GAME_RESUME = 6;           //游戏继续
	private final int JNI_GAME_OVER = 7;             //游戏结束
	private final int JNI_EXIT = 8;                  //退出游戏
	private final int JNI_CLASSIC = 9;               //天梯模式
	
	public AppActivity(){
		ToolJni.setListen(this);
	}
	
	@Override
	public void JniRevMessage(String str, int x_tag) {
		// TODO Auto-generated method stub
		switch(x_tag){
		case JNI_MAINMENU:
			Log.d("chenfu", str+" tag: "+x_tag);
			break;
		case JNI_START_SELECTMENU:
			Log.d("chenfu", str+" tag: "+x_tag);
			break;
		case JNI_CHALLENGE_SELECTMENU:
			Log.d("chenfu", str+" tag: "+x_tag);
			break;
		case JNI_TRAININGSCENE:
			Log.d("chenfu", str+" tag: "+x_tag);
			break;
		case JNI_GAME_BEGAIN:
			Log.d("chenfu", str+" tag: "+x_tag);
			break;
		case JNI_GAME_PAUSE:
			Log.d("chenfu", str+" tag: "+x_tag);
			break;
		case JNI_GAME_RESUME:
			Log.d("chenfu", str+" tag: "+x_tag);
			break;
		case JNI_GAME_OVER:
			Log.d("chenfu", str+" tag: "+x_tag);
			break;
		case JNI_EXIT:
			Log.d("chenfu", str+" tag: "+x_tag);
			break;
		case JNI_CLASSIC:
			Log.d("chenfu", str+" tag: "+x_tag);
			break;
		}
	}
}
