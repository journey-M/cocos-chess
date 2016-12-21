#ifndef __SETTING_LAYER_H__
#define __SETTING_LAYER_H__

#include "cocos2d.h"
#include "SettingLayer.h"
USING_NS_CC;

class SettingLayer:public cocos2d::Layer
{
public:

	virtual bool init();
	
	bool onMTouchBegan(Touch* touch, Event* event);
  
	void onDialogClose();

	CREATE_FUNC(SettingLayer);

private:

	Configuration* configur;

	EventListenerTouchOneByOne* listner;
	int fontSize = 45;
	const float RATEPARENT = 0.62f;
	float EXPECT_DIA_WIDTH =  0;
	float EXPECT_DIA_HEIGHT =  0;
	//初始化设置中的菜单
	void initSettingMenus();

	//开关音效
	Label* labelSoundEffect;
	void toggleSoundEffect();
	//开关背景音乐
	Label* labelBgSound;
	void toggleBgSound();
	//开关广告
	Label* labelAds;
	void toggleADS();
};


#endif // !__SETTING_LAYER_H__