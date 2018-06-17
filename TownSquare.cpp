/*************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp 
 * Date: 6/6/18 
 * Description: Townsquare Class member functions are the functions called when the user directs the player to the townsquare in the town. This class is a child class of space class
 * **********************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "TownSquare.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;

/************************************
 * 	Townsquare
 * Description: Constructor sets tips and gift to empty.  
 * ********************************/
TownSquare::TownSquare()
{
	name = " Town Square ";

	Tip1 = "TownSquare: There is no one in the Town Square";
	Tip2 = "";
	Tip3 = "";


 
	giftStruct.locationGift = Revolver;
	giftStruct.giftName = "Colt Revolver";
	giftStruct.giftValue = 9;

}


/**********************************************
 *	giveTip
 * Description: Townsquare class takes as a parameter, but returns tip one saying that no one is in the square
 * ********************************************/
std::string TownSquare::giveTip(hideout outlawHide)
{
return Tip1;
}


/*************************************************
 *	specialAction 
 * description: The townsquare does not have a special action 
 * **********************************************/
int TownSquare::specialAction()
{
return 0; 	
}	

/*****************************************************
 *	Barber::offerGift
 * Description: the town square does not offer a gift.
 * **************************************************/
int TownSquare::offerGift()
{
return 2;
}


