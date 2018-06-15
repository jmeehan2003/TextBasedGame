/*************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp 
 * Date: 6/6/18 
 * Description: CityHall Class member functions are the functions called when the user directs the player to the townhall in the town. This class is a child class of space class
 * **********************************************/

#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "CityHall.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;

/************************************
 * 	CityHall Construtor
 * Description: City hall does not give any tips or any gifts. The constructor just sets these variables up with placeholders 
 * ********************************/
CityHall::CityHall()
{
	name = "  Town Hall  ";

	Tip1 = "";
	Tip2 = "";
	Tip3 = "";


 
	giftStruct.locationGift = Revolver;
	giftStruct.giftName = "Colt Revolver";
	giftStruct.giftValue = 9;

}


/**********************************************
 *	giveTip
 * Description: CityHall class takes as a parameter, the current hiding place of Jimmy Fasthands. IT does not return a tip (Tip1 is an emptry string) .  
 * ********************************************/
std::string CityHall::giveTip(hideout outlawHide)
{
return Tip1;
}


/*************************************************
 *	specialAction 
 * description: The cityhall class doesn't have a special action. 
 * **********************************************/
int CityHall::specialAction()
{
return 0; 	
}	

/*****************************************************
 *	Barber::offerGift
 * Description: Cityhall does not offer a gift. It returns 2 which is read as Noto gift.
 * **************************************************/
int CityHall::offerGift()
{
return 2;
}


