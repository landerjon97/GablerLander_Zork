#include "stdafx.h"
#include "player.h"
#include "room.h"
#include <vector>



void Player::player()
{

}
void Player::setVector(vector<Room> room) {
	rooms = room;
}
void Player::player(string pUserInput)
{ 
	
	string userInput = pUserInput;
	if (userInput == "h" || userInput == "help" || userInput == "instructions")
	{
		instructions();
	}
	else if (userInput == "n" || userInput == "north" || userInput == "move north" || userInput == "move n")
	{
		north(rooms[0].testDoor('n'));
	}
	else if (userInput == "s" || userInput == "south" || userInput == "move south" || userInput == "move s")
	{
		south(rooms[0].testDoor('s'));
	}
	else if (userInput == "e" || userInput == "east" || userInput == "move east" || userInput == "move e")
	{
		east(rooms[0].testDoor('e'));
	}
	else if (userInput == "w" || userInput == "west" || userInput == "move west" || userInput == "move w")
	{
		west(rooms[0].testDoor('w'));
	}
	else {
		cout << "Please type 'help' if you are unsure what to do.\n";
	}

}

void Player::north(bool moveNorth)
{
	if (moveNorth == true)
	{
		if (currentroom == 1)
		{
			currentroom = 4;
		}
		else
		{
			currentroom = 3;
		}
		cout << "You opened north side door and pass through.\n";
		rooms[currentroom].displayDescription;
	}
	else
	{
		cout << "You can't move to the North." << endl;
	}
}
void Player::south(bool moveSouth)
{
	if (moveSouth == true)
	{
		if (currentroom == 3)
		{
			currentroom = 2;
		}
		else
		{
			currentroom = 1;
		}
		cout << "You opened south side door and pass through.\n";
		rooms[currentroom].displayDescription;
	}
	else
	{
		cout << "You can't move to the South." << endl;
	}
}
void Player::west(bool moveWest)
{
	if (moveWest == true)
	{
		if (currentroom == 2)
		{
			currentroom--;
		}
		else
		{
			currentroom++;
		}
		cout << "You opened west side door and pass through.\n";
		rooms[currentroom].displayDescription;
	}
	else
	{
		cout << "You can't move to the West." << endl;
	}
}
void Player::east(bool moveEast)
{
	if (moveEast == true)
	{
		if (currentroom == 1)
		{
			currentroom++;
		}
		else
		{
			currentroom--;
		}
		cout << "You opened east side door and pass through.\n" << endl;
		rooms[currentroom].displayDescription;
	}
	else
	{
		cout << "You can't move to the East." << endl;
	}
}
bool Player::takeItem(int rooms, bool items, int itemInventory)
{
	if (items == true)
	{
		items = false;
		return items;
	}
	else
	{
		cout << "You can't pick that up." << endl;
	}
}

void Player::useItem(int rooms, int itemInventory)
{
	// 
}

void Player::instructions()
{
	cout << "To move you will use the keys n, s, e, w to move a specific compass direction." << endl
		 << "The other actions you will be able to execute are take, inspect, use, and combine." << endl
		 << "For example you can say 'take keys' to pick up keys." << endl;
}