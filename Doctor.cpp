/*************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp 
 * Date: 6/6/18 
 * Description: Doctor Class member functions are the functions called when the user directs the player to the doctor in the town. This class is a child class of space class
 * **********************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Doctor.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;

/************************************
 * 	Doctor
 * Description: Constructor sets up the possible tips the doctor may give depending on what the randomly selected hideout is. It also prepares the gift that will be offered. 
 * ********************************/
Doctor::Doctor()
{
	name = "    Doctor   ";

	Tip1 = "Doctor: I just attended the burial of Chief BearClaw up at the Old Indian Graveyard. I didn't see anything unusual up there.";
	Tip2 = "Doctor: Sorry sheriff, I don't have any information to help.  ";
	Tip3 = " ";
 
	giftStruct.locationGift = Bandage;
	giftStruct.giftName = "Bandage";
	giftStruct.giftValue = 2;
}

/**********************************************
 *	giveTip
 * Description: Doctor class takes as a parameter, the current hidding place of Jimmy Fasthands. Based on the hiding place, the function determines which of the tips are acceptable and from that and it randomly generates which tip it will retur.  
 * ********************************************/
std::string Doctor::giveTip(hideout outlawHide)
{
	if(outlawHide != Indian_Graveyard)
	   {
		if(rand()%4 != 0)
		   {
			return Tip1; //75% chance of god tip.
		   }
		else
		   {
			return Tip2;
		   }
	   }
	else
	   {
		return Tip2;
	   }
}

/*************************************************
 *	specialAction 
 * description: The doctor class special action is to offer to provide the checkup to the sheriff. While some other classes have a useful special action, this one is actually a detriment to the sheriff in that it costs him time. The return amount from special action is deducted from time. 
 * **********************************************/
int Doctor::specialAction()
{
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "Would you like a quick check up? (Lose 1 time unit)  " << std::endl;
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
	 std::cout << "You probably should be looking for clues!(-1 time)" << std::endl;
	 return -1;}
   else
	{return 0;} 	
	
}	

/*****************************************************
 *	Barber::offerGift
 * Description: This prompt is used to determine if the user wants the special gift set up in the constructor. It returns 1 for yes and 2 for no. If the user selects yes, a parent class function, getGift(), is used to access the Doctor class' inherited data members and add the special gift to the custom container.
 * **************************************************/
int Doctor::offerGift()
{
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "The Doctor would like to offer you a bandage. Would you like to accept it?" << std::endl;
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


