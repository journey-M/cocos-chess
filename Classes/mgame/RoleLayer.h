#ifndef __ROLELAYER_H__
#define __ROLELAYER_H__

#include "cocos2d.h"
#include "mgame\ChessRole.h"
#include "mgame\SettingLayer.h"

class RoleLayer :public cocos2d::Layer
{
public:

	virtual bool init();

	void setRoles(ChessRole * roleEnemy, ChessRole *roleMe, int chessSpace, cocos2d::Vec2 chessOrigin);
	cocos2d::Texture2D* getTextur(int roleType);
	CREATE_FUNC(RoleLayer);

private:

	void onCloseClick();
	void onSettingCLick();

};


#endif // !__ROLELAYER_H__
