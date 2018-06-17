/*************************************************
 * Program Name: outlaw
 * Author: James Meehan
 * Description: Theater Class member functions are the functions called when the user directs the player to the barbershop in the town. This class is a child class of space class
 * **********************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Theater.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;
using std::cout;
using std::endl;

/************************************
 * 	Theater
 * Description: Constructor sets up the possible tips the actor may give depending on what the randomly selected hideout is. It also prepares the gift that will be offered. 
 * ********************************/
Theater::Theater()
{
	name = "   Theater   ";

	Tip1 = "Actor: I don't know nothin'! I only help people who buy tickets to the show!";
	Tip2 = "Actor: Lets keep this off the record. I don't want the towns folk to know I used to run with Jimmy Fasthands. He likes to hide out at ";
	Tip3 = "";

  	

	giftStruct.locationGift = Cloak;
	giftStruct.giftName = "Old Bandit Cloak";
	giftStruct.giftValue = 6;
}

/**********************************************
 *	giveTip
 * Description: Theater class takes as a parameter, the current hidding place of Jimmy Fasthands. Based on the hiding place, the function determines which of the tips are acceptable and from that and it randomly generates which tip it will return.  
 * ********************************************/
std::string Theater::giveTip(hideout outlawHide)
{

	tempHideout = outlawHide;
	return Tip1;
}

/*************************************************
 *	specialAction 
 * description: The theater class special action is to offer a ticket to the show that costs one unti of time. If the user agrees to see the show, the actor tells exactly where Jimmy Fasthands is hiding. 
 * **********************************************/
int Theater::specialAction()
{
   bool inputVerification = false;
   string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 cout << "************************" << endl;	
	 cout << "Would you like to purchase a ticket to watch the show? (Lose 1 time unit) " << endl;
	 cout << "1. Yes" << endl;
	 cout << "2. No" << endl;
	 getline(std::cin, menuInputSTR);
	 if ( menuInputSTR == "1" || menuInputSTR == "2" )
	    {
		inputVerification = true;
		menuInput = stoi(menuInputSTR);
	    }
	 else
	    {
		cout << "INVALID USER INPUT! Please enter an integer between 1-9" << endl;
	    }
	} 
   //end input verification
   
   if (menuInput == 1)
	{
	string temp;
	if(tempHideout == Abandoned_Mine)
	   {
		std::cout << Tip2 << "abandoned mine."<< std::endl;
	   }
	else if(tempHideout == Mountain_Pass)
	   {
		std::cout << Tip2 << "mountain pass." << std::endl;
	   }
	else if(tempHideout == Hidden_Cave)
	   {
		std::cout << Tip2 << "hidden cave." << std::endl;
	   }
	else
	   {
		std::cout << Tip2 << "indian graveyard." << std::endl;
	   }	
	return -1;
	}   
   else
	{
	   return 0;
	}
	 	
}	

/*****************************************************
 *	Theater::offerGift
 * Description: This prompt is used to determine if the user wants the special gift set up in the constructor. It returns 1 for yes and 2 for no. If the user selects yes, a parent class function, getGift(), is used to access the theater class' inherited data members and add the special gift to the custom container.
 * **************************************************/
int Theater::offerGift()
{
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "The actor would like to offer you an old bandit cloak. Would you like to accept it?" << std::endl;
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


