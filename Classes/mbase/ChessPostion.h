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
	//判断是否是特殊的类型
	//int isSpecialPos();

};


#endif 
