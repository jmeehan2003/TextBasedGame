/*********************************************
 * Program Name: outlaw
 * Description: General class declarations. General class is a child class from space class and repersents the functions for the general store in town.  
 * ******************************************/
#ifndef GENERAL_HPP
#define GENERAL_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class General : public Space
{
	public:
		General();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
