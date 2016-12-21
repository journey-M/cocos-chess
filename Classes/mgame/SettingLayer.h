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
	//��ʼ�������еĲ˵�
	void initSettingMenus();

	//������Ч
	Label* labelSoundEffect;
	void toggleSoundEffect();
	//���ر�������
	Label* labelBgSound;
	void toggleBgSound();
	//���ع��
	Label* labelAds;
	void toggleADS();
};


#endif // !__SETTING_LAYER_H__