/*********************************************
 * Program Name: outlaw
 * Description: Barber class declarations. Saloon class is a child class from space class and repersents the functions for the saloon in town.  
 * ******************************************/
#ifndef SALOON_HPP
#define SALOON_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class Saloon : public Space
{
	private:
		bool hadDrink;
	public:
		Saloon();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
