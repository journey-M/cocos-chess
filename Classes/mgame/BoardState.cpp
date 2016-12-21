#include "BoardState.h"
#include "mbase\ChessBase.h"
#include "Constants.h"

BoardState::BoardState() 
{

	
}

void BoardState::initBoardState(int chessSpace, Vec2 chessOrigin)
{
	this->selectedChess = NULL;
	this->curentRole = REDCHESS;
	this->chessSpace = chessSpace;
	this->chessOrigin = chessOrigin;

	Vec2 first = Vec2(chessOrigin.x - chessSpace / 2, chessOrigin.y - chessSpace / 2);
	Vec2 second = Vec2(chessOrigin.x+ chessSpace*4 + chessSpace / 2, chessOrigin.y+ chessSpace * 4 +chessSpace / 2);

	effecArea[0] = first;
	effecArea[1] = second;


	for (int m=0; m < 5 ;m++)
	{
		for (int n =0; n<5; n++)
		{
			postionState[m][n] = NONECHESS;
		}
	}

	for (int i = 0; i<5; i++)
	{
		ChessBase redchess;
		redchess.setRole(REDCHESS);
		redchess.chessPostion.row = 0;
		redchess.chessPostion.column = i;
		//设置棋盘状态
		postionState[i][0] = REDCHESS;

		ChessBase blackChess;
		blackChess.setRole(BLACKCHESS);
		blackChess.chessPostion.row = 4;
		blackChess.chessPostion.column = i;
		//设置棋盘状态
		postionState[i][4] = BLACKCHESS;
		redCheesVector.push_back(redchess);
		blackChessVector.push_back(blackChess);
	}
}


ChessPostion* BoardState::convert2Postion(Touch *touch)
{
	if (!isInEfectiveAera(touch))
	{
		return NULL;
	}
	Vec2  vecTouch = touch->getLocation()- chessOrigin ;
	int x = round(vecTouch.x/chessSpace);
	int y = round(vecTouch.y/chessSpace);
	ChessPostion* chessPostion = new ChessPostion();
	chessPostion->column = x;
	chessPostion->row = y;
	return chessPostion;
}

bool BoardState::isInEfectiveAera(Touch *touch)
{
	Vec2 vTouc = touch->getLocation();
	if ((vTouc.x <= effecArea[1].x&& vTouc.x >= effecArea[0].x) && (vTouc.y <= effecArea[1].y&& vTouc.y >= effecArea[0].y))
	{
		return true;
	}
	CCLOG("this is not in effective area!!");
	return false;
}

//返回是否消耗掉选择的事件
bool BoardState::setChessSelected(ChessPostion* chessPostion) 
{

	if (curentRole == REDCHESS) 
	{
		for (auto it = redCheesVector.begin(); it!= redCheesVector.end(); it++) 
		{
			auto b = it->chessPostion.equals(chessPostion);
			if (b) 
			{
				if (selectedChess != NULL)
				{
					selectedChess->setSelected(false);
				}
				it->setSelected(true);
				selectedChess =&(*it);

				return true;
			}
		}
	}
	else if (curentRole == BLACKCHESS)
	{
		for (auto it = blackChessVector.begin(); it != blackChessVector.end(); it++)
		{
			auto b = it->chessPostion.equals(chessPostion);
			if (b)
			{
				if (selectedChess != NULL)
				{
					selectedChess->setSelected(false);
				}
				it->setSelected(true);
				selectedChess = &(*it);
				return true;
			}
		}
	}
	return false;
}

ChessBase * BoardState::findChessByPosition(ChessPostion* chessPos)
{
	for (auto it = redCheesVector.begin(); it!=redCheesVector.end(); it++)
	{
		if (it->chessPostion.equals(chessPos))
		{
			return &(*it);
		}
	}

	for (auto it = blackChessVector.begin(); it != blackChessVector.end(); it++) 
	{
		if (it->chessPostion.equals(chessPos))
		{
			return &(*it);
		}
	}
	return NULL;
}

ChessBase * BoardState::findChessByPosition(int column, int row)
{
	ChessPostion* chPos = new ChessPostion(column, row);
	return findChessByPosition(chPos);
}


//先判断是否有吃两个的情况
vector<ChessPostion> BoardState::getEatPoints(ChessBase *chess)
{
	vector<ChessPostion> tempVect ;
	//判断左右
	if (chess->canLeft() && chess->canRight())
	{
		if (postionState[chess->chessPostion.column-1][chess->chessPostion.row] == -(chess->mRole)&&
			postionState[chess->chessPostion.column+1][chess->chessPostion.row] == -(chess->mRole))
		{
			ChessPostion* leftP = new ChessPostion(chess->chessPostion.column - 1, chess->chessPostion.row);
			ChessPostion* rightP = new ChessPostion(chess->chessPostion.column + 1, chess->chessPostion.row);
			tempVect.push_back(*leftP);
			tempVect.push_back(*rightP);
			chess->effectVector.push_back(EFFICT_Left);
			chess->effectVector.push_back(EFFICT_Right);

		}
	}
	//判断上下
	if (chess->canTop() && chess->canBottom())
	{
		if (postionState[chess->chessPostion.column ][chess->chessPostion.row -1] == -(chess->mRole) &&
			postionState[chess->chessPostion.column ][chess->chessPostion.row +1] == -(chess->mRole))
		{
			ChessPostion* topP = new ChessPostion(chess->chessPostion.column, chess->chessPostion.row + 1);
			ChessPostion* bottomP = new ChessPostion(chess->chessPostion.column, chess->chessPostion.row - 1);
			tempVect.push_back(*topP);
			tempVect.push_back(*bottomP);
			chess->effectVector.push_back(EFFICT_Top);
			chess->effectVector.push_back(EFFICT_Bottom);
		}
	}

	//判断LT--RB
	if (chess->canLT() && chess->canRB())
	{
		if (postionState[chess->chessPostion.column - 1][chess->chessPostion.row + 1] == -(chess->mRole) &&
			postionState[chess->chessPostion.column +1][chess->chessPostion.row - 1] == -(chess->mRole))
		{
			ChessPostion* topLT = new ChessPostion(chess->chessPostion.column - 1, chess->chessPostion.row + 1);
			ChessPostion* bottomRB = new ChessPostion(chess->chessPostion.column + 1, chess->chessPostion.row - 1);
			tempVect.push_back(*topLT);
			tempVect.push_back(*bottomRB);
			chess->effectVector.push_back(EFFICT_LT);
			chess->effectVector.push_back(EFFICT_RB);

		}
	}

	//判断TR--BL
	if (chess->canLT() && chess->canRB())
	{
		if (postionState[chess->chessPostion.column + 1][chess->chessPostion.row + 1] == -(chess->mRole) &&
			postionState[chess->chessPostion.column - 1][chess->chessPostion.row - 1] == -(chess->mRole))
		{
			ChessPostion* topRT = new ChessPostion(chess->chessPostion.column + 1, chess->chessPostion.row + 1);
			ChessPostion* bottolB = new ChessPostion(chess->chessPostion.column - 1, chess->chessPostion.row - 1);
			tempVect.push_back(*topRT);
			tempVect.push_back(*bottolB);
			chess->effectVector.push_back(EFFICT_TR);
			chess->effectVector.push_back(EFFICT_BL);
		}
	}

	//单个吃子的情况分析
	//左侧的情况
	if (chess->canLeft() && chess->chessPostion.column-2>=0  
		&& postionState[chess->chessPostion.column-1][chess->chessPostion.row] == -(chess->mRole)
		&& postionState[chess->chessPostion.column - 2][chess->chessPostion.row] == (chess->mRole))
	{
		ChessPostion * eatedPos = new ChessPostion(chess->chessPostion.column - 1,chess->chessPostion.row);
		ChessPostion * effectPos = new ChessPostion(chess->chessPostion.column - 2, chess->chessPostion.row);
		if (!hasPostion(tempVect, eatedPos)) 
		{
			tempVect.push_back(*eatedPos);
			findChessByPosition(effectPos)->effectVector.push_back(EFFICT_Right);
		}

	}

	//右侧的情况
	if (chess->canRight() && chess->chessPostion.column + 2 <= 4
		&& postionState[chess->chessPostion.column + 1][chess->chessPostion.row] == -(chess->mRole)
		&& postionState[chess->chessPostion.column + 2][chess->chessPostion.row] == (chess->mRole))
	{
		ChessPostion * eatedPos = new ChessPostion(chess->chessPostion.column + 1, chess->chessPostion.row);
		ChessPostion * effectPos = new ChessPostion(chess->chessPostion.column + 2, chess->chessPostion.row);
		if (!hasPostion(tempVect, eatedPos))
		{
			tempVect.push_back(*eatedPos);
			findChessByPosition(effectPos)->effectVector.push_back(EFFICT_Left);
		}
	}
	//上侧的情况
	if (chess->canTop() && chess->chessPostion.row + 2 <= 4
		&& postionState[chess->chessPostion.column ][chess->chessPostion.row + 1] == -(chess->mRole)
		&& postionState[chess->chessPostion.column ][chess->chessPostion.row + 2] == (chess->mRole))
	{
		ChessPostion * eatedPos = new ChessPostion(chess->chessPostion.column, chess->chessPostion.row+1);
		ChessPostion * effectPos = new ChessPostion(chess->chessPostion.column, chess->chessPostion.row+2);
		if (!hasPostion(tempVect, eatedPos))
		{
			findChessByPosition(effectPos)->effectVector.push_back(EFFICT_Bottom);
			tempVect.push_back(*eatedPos);
		}
	}
	//下侧的情况
	if (chess->canTop() && chess->chessPostion.row - 2 >= 0
		&& postionState[chess->chessPostion.column][chess->chessPostion.row - 1] == -(chess->mRole)
		&& postionState[chess->chessPostion.column][chess->chessPostion.row - 2] == (chess->mRole))
	{
		ChessPostion * eatedPos = new ChessPostion(chess->chessPostion.column, chess->chessPostion.row - 1);
		ChessPostion * effectPos = new ChessPostion(chess->chessPostion.column, chess->chessPostion.row - 2);
		if (!hasPostion(tempVect, eatedPos))
		{
			findChessByPosition(effectPos)->effectVector.push_back(EFFICT_Top);
			tempVect.push_back(*eatedPos);
		}
	}

	//左上侧的情况
	if (chess->canLT() && chess->chessPostion.row + 2 <= 4 && chess->chessPostion.column - 2 >= 0
		&& postionState[chess->chessPostion.column-1][chess->chessPostion.row + 1] == -(chess->mRole)
		&& postionState[chess->chessPostion.column-2][chess->chessPostion.row + 2] == (chess->mRole))
	{
		ChessPostion * eatedPos = new ChessPostion(chess->chessPostion.column-1, chess->chessPostion.row + 1);
		ChessPostion * effectPos = new ChessPostion(chess->chessPostion.column-2, chess->chessPostion.row + 2);
		if (!hasPostion(tempVect, eatedPos))
		{
			findChessByPosition(effectPos)->effectVector.push_back(EFFICT_RB);
			tempVect.push_back(*eatedPos);
		}
	}

	//右上侧的情况
	if (chess->canTR() && chess->chessPostion.row + 2 <= 4 && chess->chessPostion.column + 2 <= 4
		&& postionState[chess->chessPostion.column + 1][chess->chessPostion.row + 1] == -(chess->mRole)
		&& postionState[chess->chessPostion.column + 2][chess->chessPostion.row + 2] == (chess->mRole))
	{
		ChessPostion * eatedPos = new ChessPostion(chess->chessPostion.column + 1, chess->chessPostion.row + 1);
		ChessPostion * effectPos = new ChessPostion(chess->chessPostion.column + 2, chess->chessPostion.row + 2);
		if (!hasPostion(tempVect, eatedPos))
		{
			findChessByPosition(effectPos)->effectVector.push_back(EFFICT_BL);
			tempVect.push_back(*eatedPos);
		}
	}
	//右下侧的情况
	if (chess->canRB() && chess->chessPostion.row - 2 >= 0 && chess->chessPostion.column + 2 <= 4
		&& postionState[chess->chessPostion.column + 1][chess->chessPostion.row - 1] == -(chess->mRole)
		&& postionState[chess->chessPostion.column + 2][chess->chessPostion.row - 2] == (chess->mRole))
	{
		ChessPostion * eatedPos = new ChessPostion(chess->chessPostion.column + 1, chess->chessPostion.row - 1);
		ChessPostion * effectPos = new ChessPostion(chess->chessPostion.column + 2, chess->chessPostion.row - 2);
		if (!hasPostion(tempVect, eatedPos))
		{
			findChessByPosition(effectPos)->effectVector.push_back(EFFICT_LT);
			tempVect.push_back(*eatedPos);
		}
	}
	//左下侧的情况
	if (chess->canBL() && chess->chessPostion.row - 2 >= 0 && chess->chessPostion.column - 2 >= 0
		&& postionState[chess->chessPostion.column - 1][chess->chessPostion.row - 1] == -(chess->mRole)
		&& postionState[chess->chessPostion.column - 2][chess->chessPostion.row - 2] == (chess->mRole))
	{
		ChessPostion * eatedPos = new ChessPostion(chess->chessPostion.column- 1, chess->chessPostion.row - 1);
		ChessPostion * effectPos = new ChessPostion(chess->chessPostion.column - 2, chess->chessPostion.row - 2);
		if (!hasPostion(tempVect, eatedPos))
		{
			findChessByPosition(effectPos)->effectVector.push_back(EFFICT_TR);
			tempVect.push_back(*eatedPos);
		}
	}

	return tempVect;
}

bool BoardState::hasPostion(vector<ChessPostion> vectorTmp, ChessPostion *postion)
{
	for (auto it = vectorTmp.begin(); it != vectorTmp.end(); it++)
	{
		if ((*it).equals(postion))
		{
			return true;
		}
	}
	return false;
}



BoardState::~BoardState() 
{
}


