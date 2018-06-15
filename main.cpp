/******************************************************8
 * Program Name: outlaw
 * Author: James Meehan
 * Description: Contains the main function for the outlaw program. 
 * ****************************************************/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "menu.hpp"
#include "Sheriff.hpp"
#include "Space.hpp"

int main()
{
   //seed random number generator	
   unsigned seed;
   seed = time(0);
   srand(seed);

   //bool for end game menus
   bool endgame = false;

   welcome();

   //play game menu	
   if (2 == menuSelect1())
   {endgame = true;}
	
   //repeat game loop
   while(!endgame)
   {

	Sheriff gameplay;
	gameplay.printMap();

	//loop to move player around town until out of time
	while(gameplay.returnTime() > 0)
	{ 
	   int answer = playerMenu();

	   if(answer >= 1 && answer <=4)
	   {
		gameplay.moveSheriff(answer);
	   }

	   if(answer == 5)
	   {
		gameplay.printMap();
	   }
	
	   if(answer == 6)
	   {
		gameplay.printInventory();
	   }
	
	   if(answer == 7)
	   {
		gameplay.printClueString();	
	   }

	   if(answer == 8)
	   {
		help();
	   }	   
	
	   std::string tempSTR = gameplay.getStringHint();
	
	}	  

	//Once time is up, prompt for user to select hideout
	std::cout << "You have run out of time to look for clues!\n";
	std::cout << "You must now select a location to ride to and look for Jimmy Fasthands.\n";
	std::cout << "You recieved the following clues from the towns people:\n\n";

	//Prints all clues recieved 
	gameplay.printClueString();	
	std::cout << std::endl;
	hideout hideoutGuess = menuHideout();
	//if hideout correct, calculate value of items
	if(hideoutGuess == gameplay.returnHideout())
	  {
		std::cout << "You found Jimmy FastHands and his gang!" << std::endl;	
	  	std::cout << "Hopefully you brought enough supplies to successfully rescue the mayor's daughter." << std::endl;
		std::cout << "You brought the following: " << std::endl;
		int totalItemValue = gameplay.finalInventoryTally();		
		if (totalItemValue > 15)
		{
		   std::cout << "With these items, you were able to rescue the mayor's daughter!\nCONGRATULATIONS! YOU WIN!" << std::endl;
		}
		else 
		{
		   std::cout << "You were not able to rescue the mayor's daughter with these items.\nNext time try to bring more valuable items. GAME OVER!" << std::endl; 
		}

	
	  }
	//if hideout incorrect, game over
	else
	  {
		std::cout << "Unfortunately, Jimmy Fasthands is not hidding out at this location." << std::endl;
		std::cout << "He was at the ";
		if(Indian_Graveyard == gameplay.returnHideout())
		{
			std::cout << "Indian Graveyard." << std::endl;
		}

		else if(Mountain_Pass == gameplay.returnHideout())
		{
			std::cout << "Mountain Pass." << std::endl;
		} 
		else if(Hidden_Cave == gameplay.returnHideout())
		{
			std::cout << "Hidden Cave." << std::endl;
		} 
		else 
		{
			std::cout << "Abandoned Mine." << std::endl;
		} 
		std::cout <<  "GAME OVER!" << std::endl;
				

	  }   

	//end game menu
	if(2 == menuSelect2())
	{endgame = true;}		
   }// end of endgame loop
return 0;
}

	
