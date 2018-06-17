/********************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp
 * Date: 6/7/18
 * Description: A pure virtual class that is parent to all the classes of locations around town
 * ******************************************************/

#include <string>
#include "Space.hpp"

//returns name data member
std::string Space::getName()
{
	return name;
}

//returns gift struct
item Space::giveGift()
{
	return giftStruct;	
}

/*****************************************************
 *	set pointer functions
 * Description: sets pointers for the neighboring objects
 * **************************************************/
void Space::setTop(Space* input)
{
	Top = input;
}

void Space::setBottom(Space* input)
{
	Bottom = input;
}

void Space::setLeft(Space* input)
{
	Left = input;
}

void Space::setRight(Space* input)
{	
	Right = input;
}

/********************************************
 *	get Pointers functions
 * Descriptions: these functions return pointers of the location next to the current location. 
 ********************************************/
Space* Space::getTop()
{
	return Top;
}

Space* Space::getBottom()
{
	return Bottom;
}

Space* Space::getLeft()	
{
	return Left;
}

Space* Space::getRight()
{
	return Right;
} 
