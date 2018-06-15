/*********************************************
 * Program Name: outlaw
 * Description: CityHall class declarations. cityhall is a child class from space class and repersents the functions for the townhall in town.  
 * ******************************************/
#ifndef CITYHALL_HPP
#define CITYHALL_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class CityHall : public Space
{
	public:
		CityHall();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
