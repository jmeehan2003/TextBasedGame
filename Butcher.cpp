/*************************************************
 * Program Name: outlaw
 * Author: James Meehan
 * Description: Butcher Class member functions are the functions called when the user directs the player to the butchershop in the town. This class is a child class of space class
 * **********************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Butcher.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;
/************************************
 * 	Butcher
 * Description: Constructor sets up the possible tips the butcher may give depending on what the randomly selected hideout is. It also prepares the gift that will be offered. 
 * ********************************/
Butcher::Butcher()
{
	name = "   Butcher   ";

	Tip1 = "Butcher: I was hunting for elk in the mountain pass. I didn't see anything peculiar up there.";

	Tip2 = "Butcher: I was hunting for deer by the hidden cave. I didn't notice anything peculiar over there.";
	Tip3 = "Butcher: Sorry Sheriff, my wife has been sick so I haven't been around much.";


 
	giftStruct.locationGift = Knife;
	giftStruct.giftName = "Butcher Knife";
	giftStruct.giftValue = 4;
}


/**********************************************
 *	giveTip
 * Description: Butcher class takes as a parameter, the current hidding place of Jimmy Fasthands. Based on the hiding place, the function determines which of the tips are acceptable and from that and it randomly generates which tip it will retur.  
 * ********************************************/
std::string Butcher::giveTip(hideout outlawHide)
{
	if(outlawHide == Abandoned_Mine || outlawHide == Hidden_Cave)
	   {
		   //66% chance of good tip
		if(rand()%3!=0)
		{
			return Tip1; //helpful
		}
		else
		{
			return Tip3; //not helpful
		}
	   } 	

	else
	   {
		if(rand()%3!=0)
		{
			return Tip2; //helpful
		}
		else
		{
			return Tip3; //not helpful
		}
		
	   }	

}
/**************************************************
 *	specialAction 
 * Description: the butcher does not have a special action
 * ************************************************/

int Butcher::specialAction()
{
	   return 0;
}	

/*****************************************************
 *	Butcher::offerGift
 * Description: This prompt is used to determine if the user wants the special gift set up in the constructor. It returns 1 for yes and 2 for no. If the user selects yes, a parent class function, getGift(), is used to access the Butcher class' inherited data members and add the special gift to the custom container.
 * **************************************************/
int Butcher::offerGift()
{
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "The Butcher would like to offer you a butcher knife for protection. Would you like to accept it?" << std::endl;
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


