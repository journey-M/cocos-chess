#pragma once
#ifndef __BOAED_STATE_H__
#define __BOAED_STATE_H__

#include <vector>
#include <math.h>
#include "cocos2d.h"
#include "mbase/ChessPostion.h"
#include "mbase/ChessBase.h"
#include "mbase/ChessPostion.h"


using std::vector;

class BoardState 
{
public:

	BoardState();
	~BoardState();
	//当前下棋的棋子
	int curentRole;
	//当前选中棋子
	ChessBase* selectedChess;
	//棋盘的默认存储数据结构	int[column][row]
	int postionState[5][5];
	//每两个棋子之间的距离
	int chessSpace = 0;
	//棋盘绘制的起点
	Vec2 chessOrigin;
	vector<ChessBase> redCheesVector;
	vector<ChessBase> blackChessVector;

	//初始化棋盘的状态
	void initBoardState(int chessSpace, Vec2 chessOrigin);
	bool setChessSelected(ChessPostion* chessPostion);
	ChessPostion* convert2Postion(Touch *touch);
	ChessBase * findChessByPosition(ChessPostion* chessPos);
	ChessBase * findChessByPosition(int column, int row);
	//获取将要吃掉的棋子
	vector<ChessPostion> getEatPoints(ChessBase *chess);



private:
	Vec2 effecArea[2];
	bool isInEfectiveAera(Touch *touch);
	bool hasPostion(vector<ChessPostion> vector, ChessPostion *postion);



};

#endif