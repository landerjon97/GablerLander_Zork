#include "stdafx.h"
#include "item.h"
#include <iostream>
using namespace std;
Item::Item() 
{

}

void Item::flashLight() 
{
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
