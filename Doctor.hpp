/*********************************************
 * Program Name: outlaw
 * Author: Daniel Yopp
 * Date: 6/6/18
 * Description: Doctor class declarations. Doctor class is a child class from space class and repersents the functions for the barbershop in town.  
 * ******************************************/
#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include <string>
#include "Space.hpp"
#include "Sheriff.hpp"

class Doctor : public Space
{
	public:
		Doctor();
		std::string giveTip(hideout);
		int specialAction();
		int offerGift();

};
#endif
