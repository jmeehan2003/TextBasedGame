/*********************************************
 * Program Name: outlaw
 * Author: Daniel Yopp
 * Date: 6/6/18
 * Description: Townsquare class declarations. Townsquare class is a child class from space class.  
 * ******************************************/
#ifndef TOWNSQUARE_HPP
#define TOWNSQUARE_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class TownSquare : public Space
{
	public:
		TownSquare();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
