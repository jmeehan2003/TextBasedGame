/*************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp 
 * Date: 6/6/18 
 * Description: Office Class member functions are the functions called when the user directs the player to the sheriff office in the town. This class is a child class of space class
 * **********************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Office.hpp"
#include "Space.hpp"
#include "Sheriff.hpp"

using std::string;

/************************************
 * 	Office
 * Description: Constructor sets tips equal to nothing because the user will not recieve a tip at this location. It also sets the bool member, only in sheriff class equal t false. This bool is used in the special action. It also prepares the gift that will be offered. 
 * ********************************/
Office::Office()
{
	name = "SheriffOffice";

	bool hasEaten = false; 

	Tip1 = "";
	Tip2 = "";
	Tip3 = "";


 
	giftStruct.locationGift = Revolver;
	giftStruct.giftName = "Colt Revolver";
	giftStruct.giftValue = 9;

}


/**********************************************
 *	giveTip
 * Description: Office class takes as a parameter, the current hidding place of Jimmy Fasthands. It will return an empty string as a tip.  
 * ********************************************/
std::string Office::giveTip(hideout outlawHide)
{
	return Tip1;
}

/*************************************************
 *	specialAction 
 * description: The Office class special action is to offer a meal to sheriff. If user accepts a meal, bool haseaten becomes true and then 3 is return to add 3 to time. Otherwise 0 is returned. If bool haseaten is true, then this option is not avalible to the user.
 * **********************************************/
int Office::specialAction()
{
 if(!hasEaten)
 {		
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "Would you like to eat a meal? (No extra time cost required to eat) " << std::endl;
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
	 std::cout << "You have increased your stamina by eating and should be able to move faster(add 3 to time )" << std::endl;    
	 hasEaten = true;
	 return 3;
	
	}
   else
	{return 0;} 	

 }//end if(!hasEaten)

 else
 {return 0;}
}	

/*****************************************************
 *	offerGift
 * Description: This prompt is used to determine if the user wants the special gift set up in the constructor. It returns 1 for yes and 2 for no. If the user selects yes, a parent class function, getGift(), is used to access the Office class' inherited data members and add the special gift to the custom container.
 * **************************************************/
int Office::offerGift()
{
  //string input verification. will only accept 1 or 2 
   bool inputVerification = false;
   std::string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 std::cout << "************************" << std::endl;	
	 std::cout << "Would you like to take your revolver?" << std::endl;
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


