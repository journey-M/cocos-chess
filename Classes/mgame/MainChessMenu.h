#ifndef __MAIN_CHESS_MENU_H__
#define __MAIN_CHESS_MENU_H__

#include "cocos2d.h"
#include "MGame.h"
#include "SettingLayer.h"

class MainChessMenu :public cocos2d::Layer
{
public:

	SettingLayer* settingLayer = nullptr;

	virtual bool init();
	static cocos2d::Scene* createScence();

	void onSingleSelect();
	void onHelpSelect();
	void onSettingSelct();

	CREATE_FUNC(MainChessMenu);

private:

};


#endif // !__MAIN_MENU_H__