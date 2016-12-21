#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__


#include "cocos2d.h"
#include "mgame\BoardState.h"
#include "RoleLayer.h"

class MGame :public cocos2d::Layer
{
public:

	BoardState boarderStae;

	static cocos2d::Scene* createScence();
	virtual bool init();

	bool onMTouchBegin(Touch* touch, Event *event);
	void onMTouchMoved(Touch* touch, Event *event);
	void onMTouchEnded(Touch *touch, Event *event);
	void onMTouchCanceled(Touch* touch, Event *event);
	//回掉的函数
	void moveCallBack();
	void dismissCallBack();
	void onRoleChanged();
	CREATE_FUNC(MGame);

private:

	
	//设置Role对象
	RoleLayer* roleLayer;

	//是执行过移动事件
	bool hasMovedChess = false;
	//是否执行过消失的动画
	bool hasRunDissMissMethd = false;
	//是否执行过更换角色的动画
	int hasRoleChanged = 0;
	vector<ChessPostion> eatedPoints;
	vector<ChessPostion> lastEatedPoints;
	void initSingleTouchEvent();
	void initChessBoard();
	void eateChess();
	void beginMove(ChessPostion* postion);
};

#endif