/****************************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp
 * Date: 6/7/18
 * Description: Space class is a pure virtual parent class for lacations in the town
 * *************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

//enum declarations
enum hideout {Indian_Graveyard, Mountain_Pass, Hidden_Cave, Abandoned_Mine}; 

enum gift {Map, Rifle, Revolver, Posse, Charm, Bandage, Mustache, Cloak, Knife, Empty};


//struct declaration
struct item
{
	gift locationGift;
	std::string giftName;
	int giftValue;
};

//class declaration
class Space
{
	protected:	
		
		Space* Top;
		Space* Left;
		Space* Right;
		Space* Bottom;
		std::string Tip1;
		std::string Tip2;
		std::string Tip3;
		item giftStruct;
		std::string name; 

	public:
		virtual std::string giveTip(hideout) = 0;
		virtual int specialAction() = 0; 		
		virtual int offerGift()=0;
		item giveGift();
		std::string getName();
		void setTop(Space*);
		void setBottom(Space*);
		void setRight(Space*);
		void setLeft(Space*);
		Space* getTop();
		Space* getBottom();
		Space* getLeft();
		Space* getRight();	
};

#endif
