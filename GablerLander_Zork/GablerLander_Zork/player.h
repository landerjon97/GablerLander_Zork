/*
Aurthor: John Gabler, Jonathan Lander
Project: Text Based Adventure
Date: 5/3/17
*/
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
	//much of this is explained in player.cpp
public:
	//does nothing
	void player();
	//where games played
	void player(string pUserInput);
	//sets vector
	void setVector(vector<Room> room);
	//used to move around without 2d vector
	int currentRoom;
	//way of ending the game.
	bool gameover = false;

private:
	//directions.
	void north(bool moveNorth);
	void south(bool moveSouth);
	void west(bool moveWest);
	void east(bool moveEast);
	void instructions();
	//construct the Item class here and vector room
	Item item;
	vector<Room> rooms;
};
#endif