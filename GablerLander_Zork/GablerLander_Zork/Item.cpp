#include "stdafx.h"
#include "item.h"
#include <iostream>
using namespace std;
Item::Item() {

}

void Item::flashLight() {
	if (flashlightUp == true) {
		cout << "You picked up the flashlight and can see the contents of the room.\n";
	}
}

void Item::key() {

}

void Item::note()
{

}