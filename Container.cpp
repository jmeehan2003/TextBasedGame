/*********************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp
 * Date: 6/6/18
 * Description: Container class menu functions are used to add and access item structs in array data member. Item struct is declared in space.hpp. 
 * ******************************************************/
#include <iostream>
#include <string>
#include "Container.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*********************************************************
 *	Container Constructor
 * Description: Constructor sets each of the three positions to the empty placeholder struct. 
 * ******************************************************/
Container::Container()
{
	placeHolder.locationGift = Empty;
	placeHolder.giftName = "EMPTY";
	placeHolder.giftValue = 0;

	saddleBags[0] = placeHolder;
	saddleBags[1] = placeHolder;
	saddleBags[2] = placeHolder;
}

/*******************************************************
 *	printItems
 * Description: This function prints the current names in each struct for the three slots
 * ****************************************************/
void Container::printItems()
{
//	cout << "Items in Sheriff's Saddlebags: " << endl;
	cout << "1: " << saddleBags[0].giftName << endl;
	cout << "2: " << saddleBags[1].giftName << endl;
	cout << "3: " << saddleBags[2].giftName << endl; 
}

/*******************************************************
 *	printItemsAndVals
 * Description: This function prints both the string name and the int value of each struct in the array.
 * ****************************************************/
int Container::printItemsAndVals()
{
	
	cout << "1: " << saddleBags[0].giftName << endl;
	cout << "   Value of: " << saddleBags[0].giftValue << endl;
	cout << "2: " << saddleBags[1].giftName << endl;
	cout << "   Value of: " << saddleBags[1].giftValue << endl;
	cout << "3: " << saddleBags[2].giftName << endl; 
	cout << "   Value of: " << saddleBags[2].giftValue << endl;

	return (saddleBags[0].giftValue + saddleBags[1].giftValue + saddleBags[2].giftValue);
}

/******************************************************
 *	promptChange
 * Description: input verification prompt that asks user which item to discard to make room for a new item.
 * ***************************************************/
int Container::promptChange()
{
  //string input verification. will only accept 1,2,3,4 
   bool inputVerification = false;
   string menuInputSTR;
   int menuInput;
   while(!inputVerification)
	{
	 cout << "Which item would you like to discard?" << endl;
	 printItems();
	 cout << "4: Do Not Accept New Item" << endl;

	 getline(cin, menuInputSTR);
	 if ( menuInputSTR == "1" || menuInputSTR == "2" || menuInputSTR == "3" || menuInputSTR == "4")
	    {
		inputVerification = true;
		menuInput = stoi(menuInputSTR);
	    }
	 else
	    {
		cout << "INVALID USER INPUT! Please enter an integer between 1-4" << endl;
	    }
	} 
   //end input verification
   return menuInput;
}

/******************************************************
 *	addItems
 * Description: This function adds a new item input in the parameter into the next avalible emtpy slot. If none of the 3 slots are empty then the function calls promptChange() to determine which item the user would like to remove.
 * ***************************************************/
void Container::addItem(item input)
{
	if(saddleBags[0].giftName == "EMPTY")
	{
		saddleBags[0] = input;
	}

	else if(saddleBags[1].giftName == "EMPTY")
	{
		saddleBags[1] = input;
	}

	else if(saddleBags[2].giftName == "EMPTY")
	{
		saddleBags[2] = input;
	}

	else
	{
		int numDump = promptChange();
		
		if(numDump == 1)
		{
			saddleBags[0] = input;
		}

		else if(numDump == 2)
		{
			saddleBags[1] = input;
		}

		else if(numDump == 3)
		{
			saddleBags[2] = input;
		}
	}
}

/************************************************
 * 	totalItemValue
 * Description: Function adds each structs int value to determine the total value of all products.
 * *********************************************/
int Container::totalItemValue()
{
	int totalValue = 0;
	totalValue = (saddleBags[0].giftValue);  
	totalValue += (saddleBags[1].giftValue);  
	totalValue += (saddleBags[2].giftValue);  
	return totalValue;
}

 
