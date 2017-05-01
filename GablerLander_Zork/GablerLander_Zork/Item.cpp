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
			"There is a desk against one wall with a trashcan next to it. On another wall you see a chalkboard with some writing on it.\n"
			<< "There is a door to the east.";
	}
}

void Item::key() 
{
	if (keyUp == true && flashlightUp == true) {
		cout << "You picked up a key. \n";
	}
	else {
		cout << "You can't see anything. \n";
	}
}
void Item::chest() 
{

}
void Item::note1()
{

}
void Item::note2()
{

}
void Item::note3()
{

}
void Item::note4()
{

}
void Item::bed()
{

}
void Item::box()
{

}
void Item::briefcase()
{

}
void Item::doll()
{

}
void Item::printer()
{

}
void Item::cabinet()
{

}
void Item::finaldoor()
{

}