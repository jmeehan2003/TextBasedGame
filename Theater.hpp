/*********************************************
 * Program Name: outlaw
 * Description: Theater class declarations. Theater class is a child class from space class and repersents the functions for the barbershop in town.  
 * ******************************************/
#ifndef THEATER_HPP
#define THEATER_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class Theater : public Space
{
	private:
		hideout tempHideout;

	public:
		Theater();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
