
/**************************************************
 * Program Name: outlaw
 * Author: Daniel Yopp
 * Date: 6/6/18
 * Description: Container class includes a way to store up to three "item" structs. These structs are used to determine what items the sheriff is currently carrying. The functions are used to access and modify these items. 
 * **********************************************/
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "Space.hpp" //where item struct is declared

class Container
{
	private:
	//item is struct declared in Space.hpp
	item saddleBags[3];
	item placeHolder;	


	public:
	Container();
	void printItems();
	int printItemsAndVals();  
	int promptChange();
	void addItem(item);
	int totalItemValue();
};

#endif
