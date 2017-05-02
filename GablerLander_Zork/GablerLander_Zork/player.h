#ifndef PLAYER_H
#define PLAYER_H
#include "stdafx.h"
#include "room.h"
#include "item.h"
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
	int currentRoom;
private:
	void north(bool moveNorth);
	void south(bool moveSouth);
	void west(bool moveWest);
	void east(bool moveEast);
	void instructions();
	Item item;
	vector<Room> rooms;
};
#endif