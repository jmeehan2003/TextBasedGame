/*********************************************
 * Program Name: outlaw
 * Description: Church class declarations. Church class is a child class from space class and repersents the functions for the church in town.  
 * ******************************************/

#ifndef CHURCH_HPP
#define CHURCH_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class Church : public Space
{
	public:
		Church();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
