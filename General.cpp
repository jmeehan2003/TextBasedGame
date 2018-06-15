/*************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp 
 * Date: 6/6/18 
 * Description: General Class member functions are the functions called when the user directs the player to the general store in the town. This class is a child class of space class
 * **********************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "General.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;

/************************************
 * 	General
 * Description: Constructor sets up the possible tips the Shopkeeper may give depending on what the randomly selected hideout is. It also prepares the gift that will be offered. 
 * ********************************/
General::General()
{
	name = "General Store";

	Tip1 = "Shopkeeper: One of Jimmy Fasthand's crew came in here looking for lamp oil. It was weird sheriff because who needs oil during a full moon. He was also covered in mud like he had been living underground." ;

	Tip2 = "Shopkeeper: One of Jimmy Fasthand's crew came in here looking for a raincoat. There has been some nasty rain from by the Old Graveyard all the way to the Mountain Pass.";

	Tip3 = "Shopkeeper: We just got a shipment through the mountain pass and didn't have any problems. I would doubt there are any bandits up there.";
 
	giftStruct.locationGift = Rifle;
	giftStruct.giftName = "Repeater Rifle";
	giftStruct.giftValue = 12;
}

/**********************************************
 *	giveTip
 * Description: General class takes as a parameter, the current hidding place of Jimmy Fasthands. Based on the hiding place, the function determines which of the tips are acceptable and from that and it randomly generates which tip it will return.  
 * ********************************************/
std::string General::giveTip(hideout outlawHide)
{
	if(outlawHide == Hidden_Cave || outlawHide == Abandoned_Mine)
	   {
		if(rand()%2==0)
		{
			return Tip1;
		}
		else
		{
			return Tip3;
		}
	   }
	else
	   {
		return Tip2;
	   }	
}

/*************************************************
 *	specialAction 
 * description: The general class does not have a special action.
 * **********************************************/
int General::specialAction()
{
	return 0;
}	

/*****************************************************
 *	offerGift
 * Description: This prompt is used to determine if the user wants the special gift set up in the constructor. It returns 1 for yes and 2 for no. If the user selects yes, a parent class function, getGift(), is used to access the General class' inherited data members and add the special gift to the custom container.
 * **************************************************/
int General::offerGift()
{
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "The Shopkeeper would like to offer you a brand new repeater rifle? Would you like to accept?" << std::endl;
	 std::cout << "1. Yes" << std::endl;
	 std::cout << "2. No" << std::endl;	 
	 getline(std::cin, menuInputSTR);
	 if ( menuInputSTR == "1" || menuInputSTR == "2")
	    {
		inputVerification = true;
		menuInput = stoi(menuInputSTR);
	    }
	 else
	    {
		std::cout << "INVALID USER INPUT! Please enter integer 1 or 2" << std::endl;
	    }
	} 
   //end input verification
	return menuInput;
}	


