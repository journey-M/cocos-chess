#pragma once
#ifndef __CHESSBASE_H__
#define __CHESSBASE_H__

#include <vector>
#include "cocos2d.h"
#include "mbase\ChessPostion.h"
#include "mgame\Constants.h"
//#include "mgame\BoardState.h"

#define _ABS(x) ((x)>0 ? (x): -(x))
#define SCALE_P 1.3f
#define SCALE_N 1.0f



USING_NS_CC;

class ChessBase
{
public:
	ChessBase();
	~ChessBase();
	int mRole;
	Sprite* chessSprite;
	ChessPostion chessPostion;

	std::vector<int> effectVector;

	void setRole(int role);
	void setChessPostion(int chessSpace, Vec2 chessOrigin);
	void setSelected(bool b);
	bool canGoPos(ChessPostion* postion, int(*p)[5]);

	bool canLeft();
	bool canRight();
	bool canTop();
	bool canBottom();

	bool canLT();
	bool canTR();
	bool canRB();
	bool canBL();

	void moveTo(ChessPostion* postion, int(*p)[5], int chessSpace, CallFunc* callFunc);
	void updateChessPosition(ChessPostion* postion);
	void chessDissMiss(int(*p)[5], CallFunc* callFunc);
	void chessChangeRole(int(*p)[5], CallFunc* callFunc);


private:

	bool isSelected = false;

};

#endif // !__CHESSBASE_H__