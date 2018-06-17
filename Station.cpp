/*************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp 
 * Date: 6/6/18 
 * Description: Station Class member functions are the functions called when the user directs the player to the train station in the town. This class is a child class of space class
 * **********************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Station.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;

/************************************
 * 	Station
 * Description: Constructor sets up the possible tips the train station may give depending on what the randomly selected hideout is. It also prepares the gift that will be offered. 
 * ********************************/
Station::Station()
{
	name = "Train Station";

	Tip1 = "Conductor: We haven't had any with bandits attacking up by the abandoned mine. It is a nice change of pace. ";
	Tip2 = "Conductor: We haven't had any with bandits attacking up by the mountain pass. It is a nice change of pace. ";
	Tip3 = "Conductor: Sorry sheriff, I don't have anything to report. ";
 
	giftStruct.locationGift = Map;
	giftStruct.giftName = "Map";
	giftStruct.giftValue = 5;
}

/**********************************************
 *	giveTip
 * Description: Station class takes as a parameter, the current hidding place of Jimmy Fasthands. Based on the hiding place, the function determines which of the tips are acceptable and from that and it randomly generates which tip it will return.  
 * ********************************************/
std::string Station::giveTip(hideout outlawHide)
{
	if(outlawHide != Abandoned_Mine)
	   {
		if(rand()%3 != 0)
		   {
			return Tip1;
		   }
		else
		   {
			return Tip3;
		   }
	   }
	else if(outlawHide != Mountain_Pass)
	   {
		if(rand()%5 != 0)
		   {
			return Tip2;
		   }
		else
		   {
			return Tip3;
		   }
	   }
	else
	   {
		return Tip3;
	   }
}

/*************************************************
 *	specialAction 
 * description: The station class special action does not exist. 
 * **********************************************/
int Station::specialAction()
{
	{return 0;} 	
}	

/*****************************************************
 *	Barber::offerGift
 * Description: This prompt is used to determine if the user wants the special gift set up in the constructor. It returns 1 for yes and 2 for no. If the user selects yes, a parent class function, getGift(), is used to access the Station class' inherited data members and add the special gift to the custom container.
 * **************************************************/
int Station::offerGift()
{
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "The Conductor would like to offer you a map to help find your way around in the wild country. Would you like to accept it?" << std::endl;
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


