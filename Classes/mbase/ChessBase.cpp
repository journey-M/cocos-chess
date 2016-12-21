#include "ChessBase.h"



ChessBase::ChessBase()
{
}


void ChessBase::setRole(int role)
{
	mRole = role;

	if (mRole == REDCHESS) 
	{
		chessSprite = Sprite::create("chess_red.png");
	}
	else 
	{
		chessSprite = Sprite::create("chess_black.png");
	}
	chessSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
}

void ChessBase::setChessPostion(int chessSpace, Vec2 chessOrigin) {
	float x = chessSpace*chessPostion.column;
	float y = chessSpace*chessPostion.row;
	chessSprite->setPosition(chessOrigin.x + x, chessOrigin.y +y);
}

void ChessBase::setSelected(bool b)
{
	isSelected = b;

	if (b) 
	{
		chessSprite->setScale(SCALE_P);
	}
	else
	{
		chessSprite->setScale(SCALE_N);
	}
}

bool ChessBase::canGoPos(ChessPostion* postion, int (*p)[5])
{
	//判断位置的绝对值
	int dx = postion->column - this->chessPostion.column;
	int dy = postion->row - this->chessPostion.row;

	//判断上下
	if (postion->column == this->chessPostion.column ) 
	{
		//向上
		if (postion->row > chessPostion.row)
		{
			for (int i= chessPostion.row+1; i<= postion->row; i++)
			{
				if (p[postion->column][i] != NONECHESS) 
				{
					return false;
				}
			}
			return true;
		}
		//向下
		else if (postion->row < chessPostion.row)
		{
			for (int i = chessPostion.row -1; i >= postion->row; i--)
			{
				if (p[postion->column][i] != NONECHESS)
				{
					return false;
				}
			}
			return true;
		}

	}
	//判断左右
	else if (postion->row == this->chessPostion.row)
	{
		//向左
		if (postion->column < chessPostion.column)
		{
			for (int i = chessPostion.column-1; i >= postion->column; i--)
			{
				if (p[i][postion->row] != NONECHESS)
				{
					return false;
				}
			}
			return true;
		}
		//向右
		else if (postion->column > chessPostion.column)
		{
			for (int i = chessPostion.column +1; i <= postion->column; i++)
			{
				if (p[i][postion->row] != NONECHESS)
				{
					return false;
				}
			}
			return true;
		}
	}

	//向左上
	else if (_ABS(dx) == _ABS(dy))
	{
		int tempDx = _ABS(dx);

		if (canLT() && chessPostion.column>postion->column && chessPostion.row<postion->row)
		{
			for (int i = 1; i <= tempDx; i++)
			{
				if (p[chessPostion.column - i][chessPostion.row + i] != NONECHESS)
				{
					return false;
				}
			}
			return true;
		}
		else if (canTR() && chessPostion.column<postion->column && chessPostion.row<postion->row)
		{
			for (int i = 1; i <= tempDx; i++)
			{
				if (p[chessPostion.column + i][chessPostion.row + i] != NONECHESS)
				{
					return false;
				}
			}
			return true;
		}
		else if (canRB() && chessPostion.column<postion->column && chessPostion.row>postion->row)
		{
			for (int i = 1; i <= tempDx; i++)
			{
				if (p[chessPostion.column +i][chessPostion.row -i] != NONECHESS)
				{
					return false;
				}
			}
			return true;
		}
		else if (canBL() && chessPostion.column>postion->column && chessPostion.row>postion->row)
		{
			for (int i = 1; i <= tempDx; i++)
			{
				if (p[chessPostion.column - i][chessPostion.row - i] != NONECHESS)
				{
					return false;
				}
			}
			return true;
		}
	}
	return false;

}

bool ChessBase::canLeft()
{
	if (this->chessPostion.column>0)
	{
		return true;
	}
	return false;
}
bool ChessBase::canRight()
{
	if (this->chessPostion.column<4)
	{
		return true;
	}
	return false;
}
bool ChessBase::canTop()
{
	if (this->chessPostion.row<4)
	{
		return true;
	}
	return false;
}
bool ChessBase::canBottom()
{
	if (this->chessPostion.row>0)
	{
		return true;
	}
	return false;
}

bool ChessBase::canLT() 
{
	if (this->chessPostion.equals(1,3)|| this->chessPostion.equals(2, 2)|| this->chessPostion.equals(3, 1)|| this->chessPostion.equals(4, 0)|| 
		this->chessPostion.equals(1, 1)||this->chessPostion.equals(2, 0)||
		this->chessPostion.equals(3, 3)|| this->chessPostion.equals(4, 2))
	{
		return true;
	}
	return false;
}
bool ChessBase::canTR() 
{
	if (this->chessPostion.equals(0, 2) || this->chessPostion.equals(1, 3) || this->chessPostion.equals(0, 0) || this->chessPostion.equals(1, 1) ||
		this->chessPostion.equals(2, 2) || this->chessPostion.equals(3, 3) ||
		this->chessPostion.equals(2, 0) || this->chessPostion.equals(3, 1))
	{
		return true;
	}
	return false;
}
bool ChessBase::canRB() 
{
	if (this->chessPostion.equals(0, 2) || this->chessPostion.equals(1, 1) || this->chessPostion.equals(0, 4) || this->chessPostion.equals(1, 3) ||
		this->chessPostion.equals(2, 2) || this->chessPostion.equals(3, 1) ||
		this->chessPostion.equals(3, 3) || this->chessPostion.equals(2, 4))
	{
		return true;
	}
	return false;
}
bool ChessBase::canBL() 
{
	if (this->chessPostion.equals(1, 3) || this->chessPostion.equals(2, 4) || this->chessPostion.equals(4, 4) || this->chessPostion.equals(3, 3) ||
		this->chessPostion.equals(2, 2) || this->chessPostion.equals(1, 1) ||
		this->chessPostion.equals(3, 1) || this->chessPostion.equals(4, 2))
	{
		return true;
	}
	return false;
}

//执行动画 设置新的位置  
void ChessBase::moveTo(ChessPostion* postion, int(*p)[5], int chessSpace, CallFunc* callFunc)
{
	//取消放大的状态
	this->setSelected(false);

	p[this->chessPostion.column][this->chessPostion.row] = NONECHESS;
	p[postion->column][postion->row] = this->mRole;
	float mvX = (postion->column - this->chessPostion.column)* chessSpace;
	float mvY = (postion->row - this->chessPostion.row)* chessSpace;	
	
	auto action = Sequence::create(MoveBy::create(1.0, Point(mvX, mvY)), callFunc,NULL);
	this->chessSprite->runAction(action);
	//开始执行动画后 更新自身的位置坐标
	CCLOG("role:%d    moveTo:(%d,%d)->(%d,%d)", mRole,this->chessPostion.column, this->chessPostion.row,
		postion->column, postion->row);

	this->updateChessPosition(postion);



}

//设置精灵消失并回掉
void ChessBase::chessDissMiss(int(*p)[5], CallFunc* callFunc)
{
	auto action = Sequence::create(FadeOut::create(1.0f ), callFunc, NULL);
	this->chessSprite->runAction(action);

}

void ChessBase::chessChangeRole(int(*p)[5],CallFunc* callFunc)
{
	this->mRole = -(this->mRole);
	//跟新二位数组
	p[this->chessPostion.column][this->chessPostion.row] = mRole;
	//更新精灵的图片
	Texture2D *texture = NULL;
	if (mRole == BLACKCHESS) 
	{
		texture = TextureCache::sharedTextureCache()->addImage("chess_black.png");
	}
	else if (mRole == REDCHESS) 
	{
		texture  = TextureCache::sharedTextureCache()->addImage("chess_red.png");
	}
	this->chessSprite->setTexture(texture);

	auto action = Sequence::create( FadeIn::create(1.0f) , callFunc ,NULL);
	this->chessSprite->runAction(action);
	CCLOG("this role changed (%d, %d)-> %d", this->chessPostion.column, this->chessPostion.row, this->mRole);

}

void ChessBase::updateChessPosition(ChessPostion* postion)
{
	this->chessPostion.column = postion->column;
	this->chessPostion.row = postion->row;

}


ChessBase::~ChessBase()
{
}
