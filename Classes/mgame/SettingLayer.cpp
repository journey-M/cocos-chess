#include "SettingLayer.h"
#include "Constants.h"


bool SettingLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//获取大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	configur = Configuration::sharedConfiguration();

	EXPECT_DIA_WIDTH = visibleSize.width* RATEPARENT;
	EXPECT_DIA_HEIGHT = EXPECT_DIA_WIDTH;

	//设置拦截背景触摸的事件
	setTouchEnabled(true);
	listner = EventListenerTouchOneByOne::create();
	listner->onTouchBegan = CC_CALLBACK_2(SettingLayer::onMTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listner, this);
	listner->setSwallowTouches(true);

	//设置背景半透明的黑色
	auto colorbg = LayerColor::create(Color4B(0x32,0x32,0x32, 0x66));
	addChild(colorbg, -20);

	//设置背景的cg
	auto spriteCbg = Sprite::create("HelloWorld.png");
	spriteCbg->setAnchorPoint(Vec2(0.5f, 0.5f));
	Size size = spriteCbg->getContentSize();

	float wdx = EXPECT_DIA_WIDTH / size.width;
	float hdx = EXPECT_DIA_HEIGHT / size.height;

	spriteCbg->setScale(wdx, hdx);
	spriteCbg->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
	addChild(spriteCbg, 5);
	initSettingMenus();

	return true;
}

void SettingLayer::initSettingMenus()
{
	MenuItemImage* close = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_0(SettingLayer::onDialogClose, this));
	close->setPosition(Vec2(EXPECT_DIA_WIDTH / 2, EXPECT_DIA_HEIGHT / 2));
	auto user = UserDefault::sharedUserDefault();
	//音乐特效
	std::string strSoundEffect;
	if (user->getBoolForKey(KEY_SOUND_EFFECT))
	{
		strSoundEffect = configur->getValue("soundEffct_close").asString();
	}
	else
	{
		strSoundEffect = configur->getValue("soundEffct").asString();
	}
	labelSoundEffect = Label::createWithSystemFont(strSoundEffect, "arial", fontSize);
	//北京音乐
	std::string strBgSound;
	if (user->getBoolForKey(KEY_SOUND_EFFECT))
	{
		strBgSound = configur->getValue("bgMusic_close").asString();
	}
	else
	{
		strBgSound = configur->getValue("bgMusic").asString();
	}
	labelBgSound = Label::createWithSystemFont(strBgSound, "arial", fontSize);
	//广告ads
	std::string strAds;
	if (user->getBoolForKey(KEY_SOUND_EFFECT))
	{
		strAds = configur->getValue("closeAds_close").asString();
	}
	else
	{
		strAds = configur->getValue("closeAds").asString();
	}
	labelAds = Label::createWithSystemFont(strAds, "arial", fontSize);
	auto menuISoundEffct = MenuItemLabel::create(labelSoundEffect, CC_CALLBACK_0(SettingLayer::toggleSoundEffect, this));
	auto menuIBgSound = MenuItemLabel::create(labelBgSound, CC_CALLBACK_0(SettingLayer::toggleBgSound, this));
	auto menuIAds = MenuItemLabel::create(labelAds, CC_CALLBACK_0(SettingLayer::toggleADS, this));
	menuISoundEffct->setPosition(Vec2(0.0f, EXPECT_DIA_HEIGHT/3));
	menuIBgSound->setPosition(Vec2(0.0f, 0.0f));
	menuIAds->setPosition(Vec2(0.0f, -EXPECT_DIA_HEIGHT/3));
	auto menu = Menu::create(close, menuISoundEffct, menuIBgSound, menuIAds, NULL);
	addChild(menu, 6);
}

bool SettingLayer::onMTouchBegan(Touch* touch, Event* event)
{
	return true;
}

void SettingLayer::onDialogClose() 
{
	_eventDispatcher->removeEventListener(listner);
	CCLOG("on dialog close");
	auto scene = getScene();
	scene->removeChild(this);
	

}

void SettingLayer::toggleSoundEffect()
{
	auto user = UserDefault::sharedUserDefault();
	auto b = user->getBoolForKey(KEY_SOUND_EFFECT, false);

	if (b) 
	{
		labelSoundEffect->setString(configur->getValue("soundEffct_close").asString());
		user->setBoolForKey(KEY_SOUND_EFFECT, false);
	}
	else 
	{
		labelSoundEffect->setString(configur->getValue("soundEffct").asString());
		user->setBoolForKey(KEY_SOUND_EFFECT, true);
	}
}
void SettingLayer::toggleBgSound()
{
	auto user = UserDefault::sharedUserDefault();
	auto b = user->getBoolForKey(KEY_BG_SOUND, false);

	if (b)
	{
		labelBgSound->setString(configur->getValue("bgMusic_close").asString());
		user->setBoolForKey(KEY_BG_SOUND, false);
	}
	else
	{
		labelBgSound->setString(configur->getValue("bgMusic").asString());
		user->setBoolForKey(KEY_BG_SOUND, true);
	}
}
void SettingLayer::toggleADS()
{
	auto user = UserDefault::sharedUserDefault();
	auto b = user->getBoolForKey(KEY_ADS, false);

	if (b)
	{
		labelAds->setString(configur->getValue("closeAds_close").asString());
		user->setBoolForKey(KEY_ADS, false);
	}
	else
	{
		labelAds->setString(configur->getValue("closeAds").asString());
		user->setBoolForKey(KEY_ADS, true);
	}

}