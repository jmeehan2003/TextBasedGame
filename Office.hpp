/*********************************************
 * Program Name: outlaw
 * Description: Office class declarations. Office class is a child class from space class and repersents the functions for the barbershop in town.  
 * ******************************************/
#ifndef OFFICE_HPP
#define OFFICE_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class Office : public Space
{
	private:
		bool hasEaten;

	public:
		Office();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
