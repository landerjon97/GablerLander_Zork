/*
Aurthor: John Gabler, Jonathan Lander
Project: Text Based Adventure
Date: 5/3/17
*/
#include "stdafx.h"
#include "item.h"
#include <iostream>
using namespace std;

Item::Item() 
{

}
//just holds the flashlight and key. Everything else is boolean based which 
//we found to be the best solution
//if we had much more time and much more code we would for sure base everything around item class
//however, we only have a few items and it make more logical sense this way.
void Item::flashLight() 
{
	//just for the tutorial room otherwise the cout will be somewhere else
	if (flashlightUp == true) {
		cout << "You picked up the flashlight and can see the contents of the room.\n" <<
			"There is a desk against one wall with a trashcan next to it.\n"
			<< "There is a door to the east.\n";
	}
}
void Item::key() 
{
	if (keyUp == true && flashlightUp == true) 
	{
		cout << "You picked up a key. \n";
	}
	else 
	{
		cout << "You can't see anything. \n";
	}
}
