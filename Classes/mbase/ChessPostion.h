#pragma once
#ifndef __CHESS_POSTION__
#define __CHESS_POSTION__


class ChessPostion
{
public:

	ChessPostion ();
	ChessPostion(int coloumn, int row);
	~ChessPostion();

	int row;
	int column;

	bool equals(ChessPostion *npostion);
	bool equals(int x, int y);

private:
	//�ж��Ƿ������������
	//int isSpecialPos();

};


#endif 
