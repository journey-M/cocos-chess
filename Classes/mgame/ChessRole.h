#pragma once
#ifndef __ROLE_CHESS_H__
#define __ROLE_CHESS_H__

#include <string>
#include "mgame\Constants.h"

class ChessRole
{
public:
	//ChessRole();
	ChessRole::ChessRole(std::string name, int sex, int roleType, std::string headUrl);

	~ChessRole();

	std::string name;
	int sex;
	std::string headUrl;
	int roleType;
};

#endif // !1
