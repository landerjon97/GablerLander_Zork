#include "stdafx.h"
#include "room.h"
#include <iostream>
#include <string>
using namespace std;
Room::Room() {

}
void Room::items() {

}
void Room::description(string pDescrip) {
	info = pDescrip;


}
void Room::displayDescription() {
	cout << info << endl;
}

void Room::doors(bool n, bool e, bool s, bool w) {
	north = n;
	east = e;
	south = s;
	west = w;
}

bool Room::testDoor(char pDirection) {
	if (pDirection == 'n') {
		if (north == true) {
			return true;
		}
		else {
			return false;
		}
	}
	if (pDirection == 'e') {
		if (east == true) {
			return true;
		}
		else {
			return false;
		}
	}
	if (pDirection == 's') {
		if (south == true) {
			return true;
		}
		else {
			return false;
		}
	}
	if (pDirection == 'w') {
		if (west == true) {
			return true;
		}
		else {
			return false;
		}
	}
}
