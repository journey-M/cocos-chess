#include "MainChessMenu.h"

USING_NS_CC;

Scene* MainChessMenu::createScence()
{
	auto scene = Scene::create();
	auto menuLayer = MainChessMenu::create();

	auto layerColor = LayerColor::create(Color4B(0xff,0x0f,0x4f,0xff));
	scene->addChild(layerColor);



	scene->addChild(menuLayer);
	return scene;
}

bool MainChessMenu::init() 
{
	if (!Layer::init())
	{
		return false;
	}

	//获取屏幕的大小和绘制原点
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 originSize = Director::getInstance()->getVisibleOrigin();
	const int FONTSIZE = 52;
	const int MENU_SPACE = 42;
	MenuItemFont::setFontSize(FONTSIZE);

	Configuration::sharedConfiguration()->loadConfigFile("values/Strings.plist");

	Configuration *config = Configuration::sharedConfiguration();
	auto singleStr = config->getValue("menuSingle");
	auto helpStr = config->getValue("menuHelp");
	auto setStr = config->getValue("menuSetting");

	auto menuhelp = MenuItemFont::create(helpStr.asString(), CC_CALLBACK_0(MainChessMenu::onHelpSelect, this));
	auto menuStandAlone = MenuItemFont::create(singleStr.asString(), CC_CALLBACK_0 (MainChessMenu::onSingleSelect, this));
	auto menuSetting = MenuItemFont::create(setStr.asString(), CC_CALLBACK_0(MainChessMenu::onSettingSelct, this));

	int singleMenuHeight = (menuStandAlone->getContentSize()).height;
	menuhelp->setPosition(Vec2(0.0f, -singleMenuHeight / 2 - MENU_SPACE));
	menuStandAlone->setPosition(Vec2(0.0f, singleMenuHeight / 2 + MENU_SPACE));
	menuSetting->setPosition(Vec2(0.0f, 0.0f));


	auto menu = Menu::create(menuhelp, menuSetting, menuStandAlone, NULL);
	this->addChild(menu, 5);

	return true;



}


void MainChessMenu::onSingleSelect()
{
	Director* derector = Director::getInstance();

	derector->replaceScene(MGame::createScence());
}
void MainChessMenu::onSettingSelct()
{
	settingLayer = SettingLayer::create();
	auto scene = getScene();
	scene->addChild(settingLayer, 25);
}
void MainChessMenu::onHelpSelect()
{
	CCLOG("onhelp");
}
