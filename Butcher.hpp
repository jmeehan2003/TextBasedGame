/*********************************************
 * Program Name: outlaw
 * Author Daniel Yopp
 * Date: 6/6/18
 * Description: Butcher class declarations. Butcher class is a child class from space class and repersents the functions for the butchershop in town.  
 * ******************************************/

#ifndef BUTCHER_HPP
#define BUTCHER_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class Butcher : public Space
{
	public:
		Butcher();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
