#include "RoleLayer.h"
#include "mgame\Constants.h"

USING_NS_CC;

bool RoleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	

	//添加关闭和设置的按钮
	MenuItemImage* close = MenuItemImage::create("icons/setting_norm.png", "icons/setting_press.png", CC_CALLBACK_0(RoleLayer::onCloseClick, this));
	close->setPosition(Vec2(visibleSize.width / 2 - 120 , visibleSize.height / 2 - 60 ));

	MenuItemImage* setting = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_0(RoleLayer::onSettingCLick, this));
	setting->setPosition(Vec2(visibleSize.width/2- 60, visibleSize.height/2- 60));

	auto menu = Menu::create(close, setting, NULL);
	this->addChild(menu, 100);

	return true;

}

void RoleLayer::setRoles(ChessRole * roleEnemy, ChessRole *roleMe, int chessSpace, cocos2d::Vec2 chessOrigin)
{

	auto texture_enemy = this->getTextur(roleEnemy->roleType);
	auto texture_me = this->getTextur(roleMe->roleType);

	auto sprite_me = Sprite::createWithTexture(texture_me);
	auto sprite_enemy = Sprite::createWithTexture(texture_enemy);
	sprite_me->setAnchorPoint(Vec2(0.5f,0.5f));
	sprite_enemy->setAnchorPoint(Vec2(0.5f, 0.5f));

	sprite_enemy->setPosition(Vec2(chessOrigin.x+ chessSpace*2, chessOrigin.y+ chessSpace*4+30 + chessSpace/2));
	sprite_me-> setPosition(Vec2(chessOrigin.x + chessSpace * 2, chessOrigin.y-chessSpace*2/3));

	this->addChild(sprite_me);
	this->addChild(sprite_enemy);

}

cocos2d::Texture2D* RoleLayer::getTextur(int roleType)
{
	Texture2D* texture;
	switch (roleType)
	{
	case ROLE_COPUTER:
		texture = TextureCache::sharedTextureCache()->addImage("icons/role_computer.png");
		break;
	case ROLE_FRIENDS:
		texture = TextureCache::sharedTextureCache()->addImage("icons/role_friends.png");
		break;
	case ROLE_ME:
		texture = TextureCache::sharedTextureCache()->addImage("icons/role_me.png");
		break;
	case ROLE_WEB_PERSION:
		texture = TextureCache::sharedTextureCache()->addImage("icons/role_web_persion.png");
		break;
	default:
		texture = TextureCache::sharedTextureCache()->addImage("icons/role_friends.png");
		break;
	}
	return texture;
}

void RoleLayer::onCloseClick()
{

}
void RoleLayer::onSettingCLick()
{

}

