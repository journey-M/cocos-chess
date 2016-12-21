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
	//��ǰ���������
	int curentRole;
	//��ǰѡ������
	ChessBase* selectedChess;
	//���̵�Ĭ�ϴ洢���ݽṹ	int[column][row]
	int postionState[5][5];
	//ÿ��������֮��ľ���
	int chessSpace = 0;
	//���̻��Ƶ����
	Vec2 chessOrigin;
	vector<ChessBase> redCheesVector;
	vector<ChessBase> blackChessVector;

	//��ʼ�����̵�״̬
	void initBoardState(int chessSpace, Vec2 chessOrigin);
	bool setChessSelected(ChessPostion* chessPostion);
	ChessPostion* convert2Postion(Touch *touch);
	ChessBase * findChessByPosition(ChessPostion* chessPos);
	ChessBase * findChessByPosition(int column, int row);
	//��ȡ��Ҫ�Ե�������
	vector<ChessPostion> getEatPoints(ChessBase *chess);



private:
	Vec2 effecArea[2];
	bool isInEfectiveAera(Touch *touch);
	bool hasPostion(vector<ChessPostion> vector, ChessPostion *postion);



};

#endif