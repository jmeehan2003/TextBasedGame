/*********************************************
 * Program Name: outlaw
 * Author: Daniel Yopp
 * Date: 6/6/18
 * Description: Barber class declarations. Barber class is a child class from space class and repersents the functions for the barbershop in town.  
 * ******************************************/

#ifndef BARBER_HPP
#define BARBER_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class Barber : public Space
{
	public:
		Barber();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
