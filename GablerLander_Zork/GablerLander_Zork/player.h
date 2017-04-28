#ifndef PLAYER_H
#define PLAYER_H
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Player
{
public:
	void player();
	void player(string pUserInput);
private:
	void north(int* rooms, bool moveNorth);
	void south(int* rooms, bool moveSouth);
	void west(int* rooms, bool moveWest);
	void east(int* rooms, bool moveEast);
	bool takeItem(int* rooms, bool itemAvailable, int* itemInventory);
	void useItem(int* rooms, int* itemInventory);
	void instructions();
};
#endif