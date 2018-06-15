/*************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp 
 * Date: 6/6/18 
 * Description: Hotel Class member functions are the functions called when the user directs the player to the hotel in the town. This class is a child class of space class
 * **********************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Hotel.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;

/************************************
 * 	Barber
 * Description: Constructor sets up the possible tips the hotel may give depending on what the randomly selected hideout is. It also prepares the gift that will be offered. 
 * ********************************/
Hotel::Hotel()
{
	name = "    Hotel    ";

	Tip1 = "Hotel Clerk: I saw one of Fasthand's crew came in here soaked like he had been camping out in the rain. Its been raining a lot through the pass and by the graveyard.";
	Tip2 = "Hotel Clerk: I saw one of Fasthand's crew came in covered in mud like he just crawled out of a hole in the ground.";
	Tip3 = "Hotel Clerk: I don't know sheriff. They haven't been here";

 
 
	giftStruct.locationGift = Charm;
	giftStruct.giftName = "Good Luck Charm";
	giftStruct.giftValue = 1;
}

/**********************************************
 *	giveTip
 * Description: Hotel class takes as a parameter, the current hidding place of Jimmy Fasthands. Based on the hiding place, the function determines which of the tips are acceptable and from that and it randomly generates which tip it will return.  
 * ********************************************/
std::string Hotel::giveTip(hideout outlawHide)
{
	if(outlawHide != Abandoned_Mine && outlawHide != Hidden_Cave)
	   {
		if(rand()%3!=0)
		{
			return Tip1;
		}
		else
		{
			return Tip3; // not helpful tip
		}
	   } 	

	else
	   {
		if(rand()%3!=0)
		{
			return Tip2;
		}
		else
		{
			return Tip3; // not helpful tip
		}
		
	   }	

}

/*************************************************
 *	specialAction 
 * description: The hotel class does not have a special action.
 * **********************************************/
int Hotel::specialAction()
{
	   return 0;
}	

/*****************************************************
 *	Hotel::offerGift
 * Description: This prompt is used to determine if the user wants the special gift set up in the constructor. It returns 1 for yes and 2 for no. If the user selects yes, a parent class function, getGift(), is used to access the Barber class' inherited data members and add the special gift to the custom container.
 * **************************************************/
int Hotel::offerGift()
{
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "The hotel clerk would like to offer you a good luck charm. Would you like to accept it?" << std::endl;
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


