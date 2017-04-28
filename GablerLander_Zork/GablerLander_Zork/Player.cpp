#include "stdafx.h"
#include "player.h"



void Player::player()
{

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

void Player::north(int* rooms, bool moveNorth)
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
void Player::south(int* rooms, bool moveSouth)
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
void Player::west(int* rooms, bool moveWest)
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
void Player::east(int* rooms, bool moveEast)
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
	cout << "To move you will use the keys n, s, e, w to move a specific compass direction." << endl
		 << "The other actions you will be able to execute are take, inspect, use, and combine." << endl
		 << "For example you can say 'take keys' to pick up keys." << endl;
}
*/