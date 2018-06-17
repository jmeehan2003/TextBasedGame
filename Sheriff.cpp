/******************************************************************
 * Program Name: outlaw
 * Author:Daniel Yopp
 * Date: 6/7/18
 * Description: Sheriff class member functions
 * ***************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include "Sheriff.hpp"
#include "Space.hpp"
#include "Container.hpp"

//Space Class- derived classes
#include "Barber.hpp"
#include "Butcher.hpp"
#include "Church.hpp"
#include "CityHall.hpp"
#include "Doctor.hpp"
#include "General.hpp"
#include "Hotel.hpp"
#include "Office.hpp"
#include "Saloon.hpp"
#include "Station.hpp"
#include "Theater.hpp"
#include "TownSquare.hpp"


/*******************************************************************8
 *	Sheriff
 * Description: Sheriff constructor first creates a random location that is the hideout among other member class variables. It then creates a town map, of space objects, randomly except for town hall and townsquare. It then goes on to setup the pointers for each of the objects so that the pointers can be used to move arund the map
 * *****************************************************************/

Sheriff::Sheriff()
{
	//randomly create hideout
	FasthandHideout = static_cast<hideout>(rand()%4);
	//set timeSteps
	timeSteps = 6;
	//set hits string empty
	accumulatedHints = "";	

	//Randomly assign spaces to 3x4 town except cityhall and townsquare
	//bool array is used to determine when a space is full(true)
	bool buildArray[3][4];
	for (int count = 0; count < 3; count++)
		{
		for (int count2 = 0; count2 < 4; count2++)
			{
				buildArray[count][count2] = false;
			}
		}

	//Assign Townhall and Townsquare directly
	townMap[1][0] = new CityHall;
	buildArray[1][0] = true;	
	locationX = 1;
	locationY = 0;

	
	townMap[1][2] = new TownSquare;
	buildArray[1][2] = true;	

	//Assign other buildings randomly
	bool placed;
	int randX, randY;

	//Barber Placement	
	placed = false;
	while(!placed)
	{
		randX = rand()%3;
		randY = rand()%4;
		

		if(buildArray[randX][randY] == false)
		   {
			townMap[randX][randY] = new Barber;
			buildArray[randX][randY] = true;
			placed = true;
		   }
	}

	//Butcher Placement	
	placed = false;
	while(!placed)
	{
		randX = rand()%3;
		randY = rand()%4;
		

		if(buildArray[randX][randY] == false)
		   {
			townMap[randX][randY] = new Butcher;
			buildArray[randX][randY] = true;
			placed = true;
		   }
	}

	//Church Placement	
	placed = false;
	while(!placed)
	{
		randX = rand()%3;
		randY = rand()%4;
		

		if(buildArray[randX][randY] == false)
		   {
			townMap[randX][randY] = new Church;
			buildArray[randX][randY] = true;
			placed = true;
		   }
	}

	//Doctor Placement	
	placed = false;
	while(!placed)
	{
		randX = rand()%3;
		randY = rand()%4;
		

		if(buildArray[randX][randY] == false)
		   {
			townMap[randX][randY] = new Doctor;
			buildArray[randX][randY] = true;
			placed = true;
		   }
	}

	//General Store Placement	
	placed = false;
	while(!placed)
	{
		randX = rand()%3;
		randY = rand()%4;
		

		if(buildArray[randX][randY] == false)
		   {
			townMap[randX][randY] = new General;
			buildArray[randX][randY] = true;
			placed = true;
		   }
	}
	//Hotel Placement	
	placed = false;
	while(!placed)
	{
		randX = rand()%3;
		randY = rand()%4;
		

		if(buildArray[randX][randY] == false)
		   {
			townMap[randX][randY] = new Hotel;
			buildArray[randX][randY] = true;
			placed = true;
		   }
	}
	//Sheriff Office Placement
	placed = false;
	while(!placed)
	{
		randX = rand()%3;
		randY = rand()%4;
		

		if(buildArray[randX][randY] == false)
		   {
			townMap[randX][randY] = new Office;
			buildArray[randX][randY] = true;
			placed = true;
		   }
	}
	//Saloon Placement
	placed = false;
	while(!placed)
	{
		randX = rand()%3;
		randY = rand()%4;
		

		if(buildArray[randX][randY] == false)
		   {
			townMap[randX][randY] = new Saloon;
			buildArray[randX][randY] = true;
			placed = true;
		   }
	}


	//Train Station Placement
	placed = false;
	while(!placed)
	{
		randX = rand()%3;
		randY = rand()%4;
		

		if(buildArray[randX][randY] == false)
		   {
			townMap[randX][randY] = new Station;
			buildArray[randX][randY] = true;
			placed = true;
		   }
	}
	//Theater Placement
	placed = false;
	while(!placed)
	{
		randX = rand()%3;
		randY = rand()%4;
		

		if(buildArray[randX][randY] == false)
		   {
			townMap[randX][randY] = new Theater;
			buildArray[randX][randY] = true;
			placed = true;
		   }
	}	


	//Pointer setup for Space objects
	for(int count=0; count < 4; count++)
	   {
   		townMap[0][count]->setLeft(nullptr);
		townMap[1][count]->setLeft(townMap[0][count]);
		townMap[2][count]->setLeft(townMap[1][count]);
	   }
	for(int count=0; count < 4; count++)
	   {
		townMap[2][count]->setRight(nullptr);
		townMap[1][count]->setRight(townMap[2][count]);
		townMap[0][count]->setRight(townMap[1][count]);
	   }
	for(int count=0; count < 3; count++)
	   {
		townMap[count][0]->setTop(nullptr);
		townMap[count][1]->setTop(townMap[count][0]);
		townMap[count][2]->setTop(townMap[count][1]);
		townMap[count][3]->setTop(townMap[count][2]);
	   }
	for(int count=0; count < 3; count++)
	   {
		townMap[count][3]->setBottom(nullptr);
		townMap[count][2]->setBottom(townMap[count][3]);
		townMap[count][1]->setBottom(townMap[count][2]);
		townMap[count][0]->setBottom(townMap[count][1]); 
	   }
}

/******************************************************************
 *	Sheriff
 * Description: delete all town map objects
 * ***************************************************************/
Sheriff::~Sheriff()
{

	for (int count = 0; count < 3; count++)
		{
		 for (int count2 = 0; count2 < 4; count2++)
			{
			 delete townMap[count][count2];
			}
		}

}

/*******************************************************************
 *	printMap
 * Description: Prints map objects and current location of sheriff
 * ****************************************************************/
void Sheriff::printMap()
{
	//sets all sheriff slots in map blank
	std::string sheriffLoc[3][4];
	for (int count = 0; count < 3; count++)
		{
		 for (int count2 = 0; count2 < 4; count2++)
			{
			 sheriffLoc[count][count2] = "             ";
			}
		}
	//sets the occupied sheriff slot to read sheriff
	sheriffLoc[locationX][locationY] = "  (Sheriff)  ";

   std::cout << std::endl;	
   printTime();
   std::cout << "*************************NORTH*************************" << std::endl;
   std::cout << "*\"" << townMap[0][0]->getName() << "\" || \"" << townMap[1][0]->getName() << "\" || \"" << townMap[2][0]->getName() << "\"*" << std::endl;
   std::cout << "*\"" << sheriffLoc[0][0] << "\" || \"" << sheriffLoc[1][0] << "\" || \"" << sheriffLoc[2][0] << "\"*" << std::endl;
   std::cout << "*-----------------------------------------------------*" << std::endl;
   std::cout << "*-----------------------------------------------------*" << std::endl;
   std::cout << "*\"" << townMap[0][1]->getName() << "\" || \"" << townMap[1][1]->getName() << "\" || \"" << townMap[2][1]->getName() << "\"*" << std::endl;
   std::cout << "W\"" << sheriffLoc[0][1] << "\" || \"" << sheriffLoc[1][1] << "\" || \"" << sheriffLoc[2][1] << "\"E" <<     std::endl;
   std::cout << "E-----------------------------------------------------A" << std::endl;
   std::cout << "S-----------------------------------------------------S" << std::endl;
   std::cout << "T\"" << townMap[0][2]->getName() << "\" || \"" << townMap[1][2]->getName() << "\" || \"" << townMap[2][2]->getName() << "\"T" << std::endl;
   std::cout << "*\"" << sheriffLoc[0][2] << "\" || \"" << sheriffLoc[1][2] << "\" || \"" << sheriffLoc[2][2] << "\"*" <<     std::endl;
   std::cout << "*-----------------------------------------------------*" << std::endl;
   std::cout << "*-----------------------------------------------------*" << std::endl;
   
   std::cout << "*\"" << townMap[0][3]->getName() << "\" || \"" << townMap[1][3]->getName() << "\" || \"" << townMap[2][3]->getName() << "\"*" << std::endl;
   std::cout << "*\"" << sheriffLoc[0][3] << "\" || \"" << sheriffLoc[1][3] << "\" || \"" << sheriffLoc[2][3] << "\"*" <<     std::endl;
   std::cout << "*-----------------------------------------------------*" << std::endl;
   std::cout << "*************************SOUTH*************************" << std::endl << std::endl << std::endl;
}

/*************************************************************
 *	getStringHint
 * Description: calls the space class function to get hint for the sheriff's current location
 * **********************************************************/
std::string Sheriff::getStringHint()
{
	std::string tempSTR = townMap[locationX][locationY]->giveTip(FasthandHideout);
	return tempSTR;
}

/************************************************************
 *	changeTime
 * Description: changes the timesteps remaining in looking for clues
 * **********************************************************/ 
void Sheriff::changeTime(int input)
{
	timeSteps = timeSteps + input;
}

/************************************************************
 *	addCLueString
 * Description: Adds a string to the data member that holds all string hint recieved
 * **********************************************************/
void Sheriff::addClueString(std::string input)
{
	if(accumulatedHints == "")
		{ accumulatedHints = input + "\n";}
	else
		{accumulatedHints += ("\n" + input + "\n");} 
}

/************************************************************
 *	moveSheriff
 * Description: takes menu input and moves the sheriff the appropriate direction based on input
 * *********************************************************/
void Sheriff::moveSheriff(int x)
{
	if((townMap[(locationX)][(locationY)]->getTop()==nullptr) && x==1)
	   {
		std::cout << "Invalid Move!(off board)" << std::endl;
	   }
	else if((townMap[(locationX)][(locationY)]->getBottom()==nullptr) && x==2)
	   {
		std::cout << "Invalid Move!(off board)" << std::endl;
	   }
	else if((townMap[(locationX)][(locationY)]->getRight()==nullptr) && x==3)
	   {
		std::cout << "Invalid Move!(off board)" << std::endl;
	   }
	else if((townMap[(locationX)][(locationY)]->getLeft()==nullptr) && x==4)
	   {
		std::cout << "Invalid Move!(off board)" << std::endl;
	   }
	else
	   {	
		if((townMap[(locationX)][(locationY)]->getTop()!=nullptr) && x==1)
	   	   {
			std::cout << "Move North" << std::endl;
			locationY -= 1;
	   	   } 
		else if((townMap[(locationX)][(locationY)]->getBottom()!=nullptr) && x==2)
		   {
			std::cout << "Move South" << std::endl;
			locationY += 1;
		   }
		else if((townMap[(locationX)][(locationY)]->getRight()!=nullptr) && x==3)
		   {
			std::cout << "Move East" << std::endl;
			locationX += 1;
		   }
		else if((townMap[(locationX)][(locationY)]->getLeft()!=nullptr) && x==4)
		   {
			std::cout << "Move West" << std::endl;
			locationX -= 1;
		   }
		
		//decreases timesteps
		timeSteps--;

		//get hint
		std::string currentSTR;
		currentSTR = getStringHint();

		//print location and hint
		std::cout << "Sheriff enters: " << townMap[locationX][locationY]->getName() << std::endl;	
		std::cout << currentSTR << std::endl;
		//call special action and alter timesteps if needed
		int SpecialActionResult = townMap[locationX][locationY]->specialAction();
		timeSteps += SpecialActionResult;
		//offer/accept gift
		int giftAccept = townMap[locationX][locationY]->offerGift();
		if(giftAccept == 1)
		   {
			gifts.addItem(townMap[locationX][locationY]->giveGift());
		   }			


		if(timeSteps > 0 )
		{
		printMap(); 
		}
		//add string to accumulated strings
		addClueString(currentSTR);
	   }	


} 
/******************************************************888
 *	printClueString
 * Description: prints all clues recieved
 * *****************************************************/
std::string Sheriff::printClueString()
{
	std::cout << accumulatedHints;
	return accumulatedHints;
}

/*******************************************************
 *	printTime
 * Description: prints current timeSteps remaining
 * ****************************************************/
void Sheriff::printTime()
{
	std::cout << "You have time left for " << timeSteps << " visits/moves around town" << std::endl;
}

/******************************************************
 *	returnTime
 * Description: returns timesteps
 * ***************************************************/
int Sheriff::returnTime()
{
	return timeSteps;
}
 
/******************************************************
 *	modifyX
 * Description: changes locationX data member
 * ***************************************************/
void Sheriff::modifyX(int x)
{
	locationX = x;
}

/******************************************************
 *	modifyY
 * Decription: changes locationY data member
 * ****************************************************/
void Sheriff::modifyY(int y)
{
	locationY = y;
 
}

/******************************************************
 *	printInventory
 * Description: prints current items in Container data member
 * ***************************************************/
void Sheriff::printInventory()
{
	std::cout << "Current Items in the Sheriff's saddlebags: " << std::endl;
	gifts.printItems();  

}

/*****************************************************
 *	finalInventoryTally
 * Description: prints items and values currently in container
 ****************************************************/
int Sheriff::finalInventoryTally()
{
		int temp = gifts.printItemsAndVals();
		return temp;
}


/****************************************************
 *	returnHideout
 * Description: returns current hideout location
 * *************************************************/
hideout Sheriff::returnHideout()
{
	return FasthandHideout;
}
		 
