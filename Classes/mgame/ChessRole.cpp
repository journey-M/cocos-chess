#include "ChessRole.h"



ChessRole::ChessRole(std::string name,int sex, int roleType, std::string headUrl)
{
	this->name = name;
	this->sex = sex;
	this->roleType = roleType;
	this->headUrl = headUrl;

}


ChessRole::~ChessRole()
{
}
