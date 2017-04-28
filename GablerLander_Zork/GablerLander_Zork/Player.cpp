#include "stdafx.h"
#include "player.h"

void Player::userAction()
{

}
void Player::userAction(string pUserInput)
{
	string userInput = pUserInput;
	if (userInput == "h" || userInput == "help" || userInput == "instructions")
	{
		instructions();
	}
	else if (userInput == "n" || userInput == "north" || userInput == "move north" || userInput == "move n")
	{
		north(/* Will be passing in room array, and a bool of whether they can move north */);
	}
	else if (userInput == "s" || userInput == "south" || userInput == "move south" || userInput == "move s")
	{
		south(/* Will be passing in room array, and a bool of whether they can move south */);
	}
	else if (userInput == "e" || userInput == "east" || userInput == "move east" || userInput == "move e")
	{
		east(/* Will be passing in room array, and a bool of whether they can move east */);
	}
	else if (userInput == "w" || userInput == "west" || userInput == "move west" || userInput == "move w")
	{
		west(/* Will be passing in room array, and a bool of whether they can move west */);
	}

}

void Player::north(int* roomsArray, bool moveNorth)
{
	if (moveNorth == true)
	{
		// Move to vector position of i-1
	}
	else
	{
		cout << "You can't move to the North." << endl;
	}
}
void Player::south(int* roomsArray, bool moveSouth)
{
	if (moveSouth == true)
	{
		//Move to vector position of i+1
	}
	else
	{
		cout << "You can't move to the South." << endl;
	}
}
void Player::west(int* roomsArray, bool moveWest)
{
	if (moveWest == true)
	{
		//Move to vector position j-1
	}
	else
	{
		cout << "You can't move to the West." << endl;
	}
}
void Player::east(int* roomsArray, bool moveEast)
{
	if (moveEast == true)
	{
		//Move to vector position j+1
	}
	else
	{
		cout << "You can't move to the East." << endl;
	}
}
bool Player::takeItem(int* rooms, bool items, int* itemInventory)
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

void Player::useItem(int* rooms, int* itemInventory)
{
	// 
}

void Player::instructions()
{
	// Display instructions
}