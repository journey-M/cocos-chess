#include "ChessPostion.h"

ChessPostion::ChessPostion() 
{

}

ChessPostion::ChessPostion(int coloumn, int row)
{
	this->column = coloumn;
	this->row = row;
}

bool ChessPostion::equals(ChessPostion* nPostion)
{
	if ((nPostion->column == this->column) && (nPostion->row == this->row))
	{
		return true;
	}
	return false;
}

bool ChessPostion::equals(int x, int y) 
{
	if ((x == this->column) && (y == this->row))
	{
		return true;
	}
	return false;
}


ChessPostion::~ChessPostion()
{

}