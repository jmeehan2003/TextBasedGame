/*************************************************
 * Program Name: outlaw
 * Author: James Meehan
 * Description: Saloon Class member functions are the functions called when the user directs the player to the saloon in the town. This class is a child class of space class
 * **********************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Saloon.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;

/************************************
 * 	Saloon
 * Description: Constructor sets up the possible tips the saloon may give depending on what the randomly selected hideout is. It also prepares the gift that will be offered. 
 * ********************************/
Saloon::Saloon()
{
	name = "   Saloon    ";
	hadDrink = false;


	Tip1 = "Bartender: Sorry Sheriff, business has been slow and traffic through the saloon has been way down. I don't have any help to offer.";
	Tip2 = " ";
	Tip3 = " ";
 
	giftStruct.locationGift = Posse;
	giftStruct.giftName = "Posse";
	giftStruct.giftValue = 10;
}

/**********************************************
 *	giveTip
 * Description: Saloon class takes as a parameter, the current hidding place of Jimmy Fasthands. IT will return an empty string with no tip.  
 * ********************************************/
std::string Saloon::giveTip(hideout outlawHide)
{
	return Tip1;
}

/*************************************************
 *	specialAction 
 * description: The Saloon class special action is to offer a drink to the sheriff. If accepted, this will add 2 to time for sheriff. The return amount from special action is added to time. 
 * **********************************************/
int Saloon::specialAction()
{
 if(!hadDrink)
 {	
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "Would you like a quick drink on the house sheriff? " << std::endl;
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
	 std::cout << "The drink has given you stamina! (Plus 2 to time)" << std::endl;
	 hadDrink = true;
	 return 2;
	}
   else
	{return 0;} 	
	
 }
 else
 {return 0;}
}	

/*****************************************************
 *	Saloon::offerGift
 * Description: This prompt is used to determine if the user wants the special gift set up in the constructor. It returns 1 for yes and 2 for no. If the user selects yes, a parent class function, getGift(), is used to access the Saloon class' inherited data members and add the special gift to the custom container.
 * **************************************************/
int Saloon::offerGift()
{
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "The Bartender would like to offer to round up a Posse for you once you head after Jimmy Fasthands. Would you like to accept it?" << std::endl;
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


