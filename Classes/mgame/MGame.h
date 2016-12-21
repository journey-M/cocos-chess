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
	//�ص��ĺ���
	void moveCallBack();
	void dismissCallBack();
	void onRoleChanged();
	CREATE_FUNC(MGame);

private:

	
	//����Role����
	RoleLayer* roleLayer;

	//��ִ�й��ƶ��¼�
	bool hasMovedChess = false;
	//�Ƿ�ִ�й���ʧ�Ķ���
	bool hasRunDissMissMethd = false;
	//�Ƿ�ִ�й�������ɫ�Ķ���
	int hasRoleChanged = 0;
	vector<ChessPostion> eatedPoints;
	vector<ChessPostion> lastEatedPoints;
	void initSingleTouchEvent();
	void initChessBoard();
	void eateChess();
	void beginMove(ChessPostion* postion);
};

#endif