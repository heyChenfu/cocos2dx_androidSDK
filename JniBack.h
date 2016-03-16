#ifndef __JNIBACK_H__
#define __JNIBACK_H__

#include "cocos2d.h"

USING_NS_CC;

class JniBack {
public:
	virtual void revBack(const char* message,int x_tag){};
};
#endif