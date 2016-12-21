#include "MGame.h"

USING_NS_CC;


Scene* MGame::createScence() {
	auto scence = Scene::create();
	//���ñ�������ɫ
	auto colorLayer = LayerColor::create(Color4B(0x66, 0x66, 0x33, 0xff));
	scence->addChild(colorLayer, -20);

	auto layer = MGame::create();
	scence->addChild(layer);


	return scence;
}


bool MGame::init() {

	if (!Layer::init()) {
		return false;
	}
	//��ӱ�����
	roleLayer = RoleLayer::create();
	this->addChild(roleLayer, -5);

	//��ȡ��Ļ�Ĵ�С�ͻ���ԭ��
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 originSize = Director::getInstance()->getVisibleOrigin();
	originSize = Vec2(0.0f,40.0f);
	//���Ʊ�������
	auto spritebg = Sprite::create("bg.png");
	spritebg->setPosition(originSize.x + visibleSize.width/2, originSize.y + visibleSize.height/2);
	this->addChild(spritebg);
	//�õ�����֮��ļ��
	Size bgSize = spritebg->getContentSize();
	int WIDTH = (int)(bgSize.width / 4);
	//�õ����̵�ԭ������
	Vec2 bgPostion = spritebg->getPosition();
	Vec2 bgOrigin = Vec2(bgPostion.x- WIDTH*2, bgPostion.y-WIDTH*2);

	//��ʼ�����̵�״̬
	boarderStae.initBoardState(WIDTH, bgOrigin);
	initChessBoard();
	initSingleTouchEvent();
	roleLayer->setRoles( new ChessRole("����",0, ROLE_COPUTER, ""),
		new ChessRole("��", 1, ROLE_ME, ""), WIDTH,bgOrigin);

	return true;
}

void MGame::initChessBoard() 
{
	for (auto it = boarderStae.redCheesVector.begin(); it != boarderStae.redCheesVector.end(); ++it)
	{
		it->setChessPostion(boarderStae.chessSpace, boarderStae.chessOrigin);
		this->addChild(it->chessSprite);
	}

	for (auto it = boarderStae.blackChessVector.begin(); it != boarderStae.blackChessVector.end(); ++it)
	{
		it->setChessPostion(boarderStae.chessSpace, boarderStae.chessOrigin);
		this->addChild(it->chessSprite);
	}

}

void MGame::initSingleTouchEvent() 
{
	auto listnerTouch = EventListenerTouchOneByOne::create();
	listnerTouch->setSwallowTouches(true);
	listnerTouch->onTouchBegan = CC_CALLBACK_2(MGame::onMTouchBegin, this);
	listnerTouch->onTouchMoved = CC_CALLBACK_2(MGame::onMTouchMoved, this);
	listnerTouch->onTouchEnded = CC_CALLBACK_2(MGame::onMTouchEnded, this);
	listnerTouch->onTouchCancelled = CC_CALLBACK_2(MGame::onMTouchCanceled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listnerTouch, this);

}

bool MGame::onMTouchBegin(Touch* touch, Event *event)
{

	auto aVct = boarderStae.convert2Postion(touch);

	if (aVct == NULL)
	{
		return true;
	}
	//����ѡ������ӣ������¼�
	if (hasMovedChess == true ||boarderStae.setChessSelected(aVct) || hasRunDissMissMethd == true)
		return false;

	beginMove(aVct);

	return false;
}
void MGame::beginMove(ChessPostion* postion)
{
	if (boarderStae.selectedChess != NULL)
	{
		auto b = boarderStae.selectedChess->canGoPos(postion, boarderStae.postionState);
		//�Ƿ����ƶ���ĳ��λ��
		if (b)
		{
			auto callback = CCCallFunc::create(this, callfunc_selector(MGame::moveCallBack));
			hasMovedChess = true;
			boarderStae.selectedChess->moveTo(postion, boarderStae.postionState, boarderStae.chessSpace, callback);
			vector<ChessPostion> vtemp = boarderStae.getEatPoints(boarderStae.selectedChess);
			//������б��Ե��ĵ�
			eatedPoints.insert(eatedPoints.end(), vtemp.begin(), vtemp.end());
		}
	}

}

void MGame::eateChess()
{

	hasRoleChanged = false;
	hasRunDissMissMethd = false;
	hasMovedChess = false;
	//�г��ӵ�����ͳԵ���û�оͲ������ִ����
	for (auto it = eatedPoints.begin(); it!= eatedPoints.end() ; it++) 
	{	 
		ChessBase* chess = boarderStae.findChessByPosition(it->column, it->row);
		auto callback = CCCallFunc::create(this, callfunc_selector(MGame::dismissCallBack));
		chess->chessDissMiss(boarderStae.postionState, callback);
	}

	//û���ӳԵ�������£��ж��Ƿ���ʤ����
	if(boarderStae.redCheesVector.size()==10)
	{
		CCLOG("������ʤ��");
	}
	else if (boarderStae.blackChessVector.size() == 10) 
	{
		CCLOG("����ʤ��");
	}

}


void MGame::moveCallBack()
{
	boarderStae.selectedChess = NULL;
	boarderStae.curentRole = -boarderStae.curentRole;
	//����
	eateChess();
}
void MGame::dismissCallBack()
{
	if (hasRunDissMissMethd) {
		return;
	}
	hasRunDissMissMethd = true;
	for (auto it = eatedPoints.begin(); it != eatedPoints.end(); it++)
	{
		ChessBase* chess = boarderStae.findChessByPosition(it->column, it->row);
		auto call = CallFunc::create(this, callfunc_selector( MGame::onRoleChanged) );
	    (*chess).chessChangeRole(boarderStae.postionState , call);
		hasRoleChanged = eatedPoints.size();

		if (chess->mRole == BLACKCHESS) 
		{
			for (auto it = boarderStae.redCheesVector.begin(); it!= boarderStae.redCheesVector.end(); it++)
			{
				if (&(*it) == &(*chess)) {
					boarderStae.blackChessVector.push_back(*chess);
					boarderStae.redCheesVector.erase(it);	
					break;
				}
			}
		}
		else {
			for (auto it = boarderStae.blackChessVector.begin(); it != boarderStae.blackChessVector.end(); it++)
			{
				if (&(*it) == &(*chess)) {
					boarderStae.redCheesVector.push_back(*chess);
					boarderStae.blackChessVector.erase(it);					
					break;
				}
			}
		}		
	}
}

void MGame::onRoleChanged()
{
	hasRoleChanged--;
	if (hasRoleChanged>0)
	{
		return;
	}

	lastEatedPoints = eatedPoints;
	eatedPoints.clear();
	for (auto it = lastEatedPoints.begin(); it != lastEatedPoints.end(); it++) 
	{
		auto chess = boarderStae.findChessByPosition(&(*it));
		vector<ChessPostion> vtemp = boarderStae.getEatPoints(chess);
		//����µı��Ե��ĵ�
		eatedPoints.insert(eatedPoints.end(), vtemp.begin(), vtemp.end());
	}

	eateChess();
}


void MGame::onMTouchMoved(Touch* touch, Event *event)
{
}

void MGame::onMTouchEnded(Touch* touch, Event *event)
{
}

void MGame::onMTouchCanceled(Touch* touch, Event *event)
{
}