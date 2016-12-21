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
	//�ж�λ�õľ���ֵ
	int dx = postion->column - this->chessPostion.column;
	int dy = postion->row - this->chessPostion.row;

	//�ж�����
	if (postion->column == this->chessPostion.column ) 
	{
		//����
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
		//����
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
	//�ж�����
	else if (postion->row == this->chessPostion.row)
	{
		//����
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
		//����
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

	//������
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

//ִ�ж��� �����µ�λ��  
void ChessBase::moveTo(ChessPostion* postion, int(*p)[5], int chessSpace, CallFunc* callFunc)
{
	//ȡ���Ŵ��״̬
	this->setSelected(false);

	p[this->chessPostion.column][this->chessPostion.row] = NONECHESS;
	p[postion->column][postion->row] = this->mRole;
	float mvX = (postion->column - this->chessPostion.column)* chessSpace;
	float mvY = (postion->row - this->chessPostion.row)* chessSpace;	
	
	auto action = Sequence::create(MoveBy::create(1.0, Point(mvX, mvY)), callFunc,NULL);
	this->chessSprite->runAction(action);
	//��ʼִ�ж����� ���������λ������
	CCLOG("role:%d    moveTo:(%d,%d)->(%d,%d)", mRole,this->chessPostion.column, this->chessPostion.row,
		postion->column, postion->row);

	this->updateChessPosition(postion);



}

//���þ�����ʧ���ص�
void ChessBase::chessDissMiss(int(*p)[5], CallFunc* callFunc)
{
	auto action = Sequence::create(FadeOut::create(1.0f ), callFunc, NULL);
	this->chessSprite->runAction(action);

}

void ChessBase::chessChangeRole(int(*p)[5],CallFunc* callFunc)
{
	this->mRole = -(this->mRole);
	//���¶�λ����
	p[this->chessPostion.column][this->chessPostion.row] = mRole;
	//���¾����ͼƬ
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
