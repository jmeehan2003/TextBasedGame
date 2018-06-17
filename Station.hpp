/*********************************************
 * Program Name: outlaw
 * Description: Station class declarations. Train Station class is a child class from space class and repersents the functions for the train station in town.  
 * ******************************************/
#ifndef STATION_HPP
#define STATION_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class Station : public Space
{
	public:
		Station();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
