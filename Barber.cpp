/*************************************************
 * Program Name: outlaw
 * Author: James Meehan
 * Description: Barber Class member functions are the functions called when the user directs the player to the barbershop in the town. This class is a child class of space class
 * **********************************************/

#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Barber.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;

/************************************
 * 	Barber
 * Description: Constructor sets up the possible tips the barber may give depending on what the randomly selected hideout is. It also prepares the gift that will be offered. 
 * ********************************/
Barber::Barber()
{
	name = "   Barber    ";

	Tip1 = "Barber: Word on the street is that Jimmy Fasthands isn't at the hidden cave.";
	Tip2 = "Barber: Word on the street is that Jimmy Fasthands isn't at the abandoned mine because of talk.";
	Tip3 = "Barber: Sorry Sheriff, I haven't heard anything.";
	
	giftStruct.locationGift = Mustache;
	giftStruct.giftName = "Mustache Trim Kit";
	giftStruct.giftValue = 0;

}

/**********************************************
 *	giveTip
 * Description: Barber class takes as a parameter, the current hidding place of Jimmy Fasthands. Based on the hiding place, the function determines which of the tips are acceptable and from that and it randomly generates which tip it will return.  
 * ********************************************/
std::string Barber::giveTip(hideout outlawHide)
{
	if (outlawHide == Indian_Graveyard || outlawHide == Abandoned_Mine)
	{
		//66% chance of providing useful tip
		if(rand()%3 != 0)
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
		if(rand()%3 != 0)
		{
			return Tip2;
		}
		else
		{
			return Tip3;
		}
	}
}


/*************************************************
 *	specialAction 
 * description: The barber class special action is to offer to provide the haircut to the sheriff. While some other classes have a useful special action, this one is actually a detriment to the sheriff in that it costs him time. The return amount from special action is deducted from time. 
 * **********************************************/
int Barber::specialAction()
{
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "Would you like to take the time for a harcut? (This will take away 1 increment of time) " << std::endl;
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
   if (menuInput == 1)
	{
	 std::cout << "Barber: Well Sheriff, I hope you like your new haircut. I'm suprised you are so confident in finding the mayors daughter!(minue 1 time)" << std::endl;    
	 return -1;
	
	}
   else
	{return 0;} 	
	
}	

/*****************************************************
 *	Barber::offerGift
 * Description: This prompt is used to determine if the user wants the special gift set up in the constructor. It returns 1 for yes and 2 for no. If the user selects yes, a parent class function, getGift(), is used to access the Barber class' inherited data members and add the special gift to the custom container.
 * **************************************************/
int Barber::offerGift()
{
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "The Barber would like to offer you a mustache trimming kit. Would you like to accept it?" << std::endl;
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


