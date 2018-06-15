/*************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp 
 * Date: 6/6/18 
 * Description: Church Class member functions are the functions called when the user directs the player to the church in the town. This class is a child class of space class
 * **********************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Church.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;

/************************************
 * 	Barber
 * Description: Constructor sets the only possible tip the church will give. 
 * ********************************/
Church::Church()
{
	name = "    Church   ";

	Tip1 = "Priest: Sorry Sheriff, I dont't know anything about Fasthands. You should talk to the actor at the theater though. He used to be a member of the Jimmy Fasthand's gang. Make sure you are nice to him because he can be touchy about his past.";
	Tip2 = " ";
	Tip3 = " ";
 
//	giftStruct.locationGift = ;
//	giftStruct.giftName = "";
//	giftStruct.giftValue = ;
}

/**********************************************
 *	giveTip
 * Description: Church class takes as a parameter, the current hidding place of Jimmy Fasthands. Regardless of the hideout, the church returns a tip to check with the actor at the theater.  
 * ********************************************/
std::string Church::giveTip(hideout outlawHide)
{
	return Tip1;
}

/*************************************************
 *	specialAction 
 * description: The church has no special action
 * **********************************************/
int Church::specialAction()
{
return 0;
}	

/************************************************
 * offerGift
 * description: the church does not offer a gift
 * *********************************************/
int Church::offerGift()
{
return 2;
}	


