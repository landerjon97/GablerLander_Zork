#ifndef PLAYER_H
#define PLAYER_H
#include "stdafx.h"
#include "room.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Player
{
public:
	void player();
	void player(string pUserInput);
	void setVector(vector<Room> room);
private:
	void north(bool moveNorth);
	void south(bool moveSouth);
	void west(bool moveWest);
	void east(bool moveEast);
	bool takeItem(int rooms, bool itemAvailable, int itemInventory);
	void useItem(int rooms, int itemInventory);
	void instructions();
	vector<Room> rooms;
	char direction;
};
#endif