/************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp
 * Date: 6/7/18
 * Description: Sheriff class is the main class of the outlaw program. It contains multiple other class bjects as members and is set up to have its functions called from main.
 * *********************************************/
#ifndef SHERIFF_HPP
#define SHERIFF_HPP

#include <string>
#include "Space.hpp"
#include "Container.hpp"

class Sheriff
{	
	private:
		hideout FasthandHideout;
		int locationX;
		int locationY;
		std::string accumulatedHints;
		int timeSteps;
		Space *townMap[3][4];		
		Container gifts;

	public:
		Sheriff();
		~Sheriff();
		void printMap();
		std::string getStringHint();
		void addClueString(std::string);
		void moveSheriff(int);
		std::string printClueString(); 
		void changeTime(int);
	 	void printTime();
		int returnTime();
		void modifyX(int x);
		void modifyY(int y); 		
		void printInventory();
		int finalInventoryTally();
		hideout returnHideout(); 
};
#endif
