/*********************************************
 * Program Name: outlaw
 * Author: Daniel Yopp
 * Date: 6/6/18
 * Description: Hotel class declarations. Hotel class is a child class from space class and repersents the functions for the barbershop in town.  
 * ******************************************/
#ifndef HOTEL_HPP
#define HOTEL_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class Hotel : public Space
{
	public:
		Hotel();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
