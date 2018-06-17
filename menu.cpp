/***********************************************
 * Program Name: outlaw
 * Author: Daniel Yopp
 * Date: 6/7/18
 * Description: Menu prompts and input verifications for outlaw
 * ********************************************/
#include <iostream>
#include <string>
#include "menu.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

/*************************************************
 *	welcome
 * description: welcome statement that explains game
 * **********************************************/
void welcome()
{	cout << endl << endl; 	
	cout << "Welcome to the town of Gold Creek in the Wild West! \n";
	cout << "You are the new sheriff in town and you couldn't have come a moment too soon! \n\n";
	cout << "While stopping in at Town Hall to check in with the Mayor you learn that, just this morning, the dangerous outlaw Jimmy Fasthands came through town, kidnapped the mayor's daughter, and headed out to hide in the country. He demanded a ransom payment by sun-down so there isn't much time. You must gather clues from the different shops around town as to where Jimmy Fasthands might be hiding. The possible places are:" << endl;
	cout << "\nThe Indian Graveyard - A rainy secluded graveyard few ever visit. ";
	cout <<	"\nThe Mountain Pass - A hard to travel pass that has unpredictable weather.";
	cout << "\nThe Hidden Cave - A deep cave with no light that few venture into.";
	cout << "\nThe Abandoned Mine - An old mine, deep underground, that has been forgotten." << endl;

	cout << "\nThe locals also may have some supplies that can help you successfully rescue the Mayor's Daughter but you will only be able to carry 3 supplies in your saddlebags so choose wisely what you take."; 

	cout << "\n\nTime is limited because you must travel to one of the remote locations to find Jimmy Fasthands before sundown. You will only have time to visit 6 of the 12 areas in town to gather clues and supplies. You will be starting at the mayor's office in town hall and can only travel in one block increments around town. Good Luck!\n\n" << endl;
}	
/************************************************
 *	help
 * description: help function is a more descriptive explanation if user requests it from menu
 * *********************************************/
void help()
{
cout << "Game Objectives:\n";
cout <<	"To win the game, the player(Sheriff) must complete two tasks:\n";
cout << "Failing to complete either of these objectives will result in a loss.\n\n"; 

cout << "Objective 1:\n"; 
cout << "The Sheriff must gather clues from the towns people about where the outlaw Jimmy Fasthands is hiding.\n"; 
cout << "This is done by traveling around the town and associating with the towns people. \n\n"; 
cout << "The possible hiding spots are:\n"; 
cout << "1. The Indian Graveyard\n";
cout << "2. The Mountain Pass\n";
cout << "3. The Hidden Cave\n";
cout << "4. The Abandoned Mine.\n\n"; 

cout << "The sheriff can gather clues from around town by traveling to different locations on the map and gathering clues from the towns people. To travel, the player should consult the map to see the current location, and select an option in the menu between 1 and 4 depending on the direction the user wants to move.  The player can also review all of the clues they have recieved by selecting option 7 on the menu.\n\n"; 

cout << "Once the player is out of time/visits, they will be asked to select a hideout to ride to and check for Jimmy Fasthands. The player needs to select the appropriate hideout based on the clues received or the player will lose.\n\n"; 


cout << "Objective 2:\n";
cout << "The Sheriff must also gather items from around town that will be valuable when going to confront Jimmy Fasthands. At any one time, the Sheriff can only carry three items. If the sheriff has three items and is offered another item, the sheriff can choose to reject the offer or discard a current item and accept the offer. The sheriff can receive offers by traveling around town and associating with towns people.\n\n"; 


cout << "Possible Items that can be gathered are:\nMap			+5\nRepeater Rifle		+12\nKnife			+4\nRevolver		+9\nPosse			+10\nGood Luck Charm		+1\nBandage			+2\nMustache Trim kit	+0\nOld Bandit Cloak 	+6\n\n";	

cout << "Each item has an associated value and by the end of the game, that total value of all items the sheriff currently has, must be greater than or equal to 16 to be able to defeat Jimmy Fasthands and win the game.\n"; 

}
/******************************
 *	menuSelect1
 * Description: Allows user to select if they would like to play the game
 ****************************/
int menuSelect1()
{
   //string input verification. will only accept 1 or 2
   bool inputVerification = false;
   string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 cout << "Please select an option:" << endl;
	 cout << "1. Play Game" << endl;
	 cout << "2. Exit" << endl;
	 getline(cin, menuInputSTR);
	 if ( menuInputSTR == "1" || menuInputSTR == "2")
	    {
		inputVerification = true;
		menuInput = stoi(menuInputSTR);
	    }
	 else
	    {
		cout << "INVALID USER INPUT! Please enter 1 or 2." << endl;
	    }
	} 
   //end input verification
return menuInput;
}

/******************************
 *	menuSelect2
 * Description: Allows user to select if they would like to play the game again
 ****************************/
int menuSelect2()
{
   //string input verification. will only accept 1 or 2
   bool inputVerification = false;
   string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 cout << "Please select an option:" << endl;
	 cout << "1. Play Again" << endl;
	 cout << "2. Exit" << endl;
	 getline(cin, menuInputSTR);
	 if ( menuInputSTR == "1" || menuInputSTR == "2")
	    {
		inputVerification = true;
		menuInput = stoi(menuInputSTR);
	    }
	 else
	    {
		cout << "INVALID USER INPUT! Please enter 1 or 2." << endl;
	    }
	} 
   //end input verification
return menuInput;
}

/********************************************
 *	playerMenu
 * Description: main game menu
 * *****************************************/
int playerMenu()
{
   //string input verification. will only accept 1,2,3,4
   bool inputVerification = false;
   string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 cout << "Please select an option:"  << endl;
	 cout << "1. Move North" << endl;
	 cout << "2. Move South" << endl;
	 cout << "3. Move East" << endl;  
	 cout << "4. Move West" << endl;
	 cout << "5. Print Map with Location" << endl;
	 cout << "6. View Current Inventory" << endl;
	 cout << "7. Print All Clues Recieved" << endl;
	 cout << "8. Help" << endl;  
	 getline(cin, menuInputSTR);
	 if ( menuInputSTR == "1" || menuInputSTR == "2" || menuInputSTR == "3" || menuInputSTR =="4" ||  menuInputSTR == "5" || menuInputSTR == "6" || menuInputSTR == "7" || menuInputSTR == "8")
	    {
		inputVerification = true;
		menuInput = stoi(menuInputSTR);
	    }
	 else
	    {
		cout << "INVALID USER INPUT! Please enter 1, 2, 3, 4, or 5." << endl;
	    }
	} 
   //end input verification
return menuInput;
}

/************************************************
 *	menuhideout
 * Description: menu to select which hideout to look for the outlaw
 * *********************************************/
hideout menuHideout()
{
   //string input verification. will only accept 1,2,3,4
   bool inputVerification = false;
   string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 cout << "Please select where you will ride to look for Jimmy Fasthands:"  << endl;
	 cout << "1. Indian Graveyard" << endl;
	 cout << "2. Mountain Pass" << endl;
	 cout << "3. Hidden Cave" << endl;  
	 cout << "4. Abandoned Mine" << endl;
	 getline(cin, menuInputSTR);
	 if ( menuInputSTR == "1" || menuInputSTR == "2" || menuInputSTR == "3" || menuInputSTR =="4")
	    {
		inputVerification = true;
		menuInput = stoi(menuInputSTR);
	    }
	 else
	    {
		cout << "INVALID USER INPUT! Please enter 1, 2, 3, or 4." << endl;
	    }
	} 
   //end input verification
	hideout answer = static_cast<hideout>(menuInput-1); 



return answer;
}
