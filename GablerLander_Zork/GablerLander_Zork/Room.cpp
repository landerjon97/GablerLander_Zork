/*
Aurthor: John Gabler, Jonathan Lander
Project: Text Based Adventure
Date: 5/3/17
*/
#include "stdafx.h"
#include "room.h"
#include <iostream>
#include <string>
using namespace std;
Room::Room() 
{
}
void Room::items()
{
}
//assigns a description
void Room::description(string pDescrip)
{
	info = pDescrip;
}
//displays description
void Room::displayDescription() 
{
	cout << info << endl;
}
/*
HOW WE MADE EACH ROOM:
each room techincally had 4 doors. we can turn them on or off with boolean values.
*/
void Room::doors(bool n, bool e, bool s, bool w) 
{
	north = n;
	east = e;
	south = s;
	west = w;
}
//tests to see if the door is labeled true or false if false you cant go that way.
bool Room::testDoor(char pDirection) 
{
	if (pDirection == 'n') 
	{
		if (north == true) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	if (pDirection == 'e')
	{
		if (east == true) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	if (pDirection == 's') 
	{
		if (south == true) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	if (pDirection == 'w') 
	{
		if (west == true) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
}
