#include "stdafx.h"
#include "player.h"
#include "room.h"
#include "item.h"
#include <vector>



void Player::player()
{

}
void Player::setVector(vector<Room> room) {
	rooms = room;
	Item items;
}
void Player::player(string pUserInput)
{
	string userInput = pUserInput;
	if (userInput == "h" || userInput == "help" || userInput == "instructions")
	{
		instructions();
	}
	else if (currentRoom == 0 && item.keyUp == true && (userInput == "e" || userInput == "east" || userInput == "move east" || userInput == "move e")) {
		cout << "The key that you used on the door breaks but you continue into the next room.\n";
		item.keyUp = false;
		east(rooms[currentRoom].testDoor('e'));
	}
	else if (userInput == "n" || userInput == "north" || userInput == "move north" || userInput == "move n")
	{
		north(rooms[currentRoom].testDoor('n'));
	}
	else if (userInput == "s" || userInput == "south" || userInput == "move south" || userInput == "move s")
	{
		south(rooms[currentRoom].testDoor('s'));
	}
	else if (userInput == "e" || userInput == "east" || userInput == "move east" || userInput == "move e")
	{
		east(rooms[currentRoom].testDoor('e'));
	}
	else if (userInput == "w" || userInput == "west" || userInput == "move west" || userInput == "move w")
	{
		west(rooms[currentRoom].testDoor('w'));
	}
	else if (currentRoom == 0 && userInput == "take flashlight") {
		item.flashlightUp = true;
		item.flashLight();
	}
	else if (currentRoom == 0 && userInput == "inspect trash" && item.flashlightUp == true) {
		cout << "The trash is empty.\n There's nothing to take.\n";
	}
	else if (currentRoom == 0 && userInput == "inspect desk" && item.flashlightUp == true) {
		cout << "You found a key in the top left draw.\n Maybe this key could be used on the eastern door.\n";
		item.takeKey = true;
	}
	else if (currentRoom == 0 && userInput == "take key" && item.flashlightUp == true && item.takeKey == true) {
		rooms[0].doors(false, true, false, false);
		item.keyUp = true;
		item.key();
	}


	
	else if (userInput == "look around") {
		if (currentRoom == 0 && item.flashlightUp == true) {
			rooms[0].description("The room is almost entirely empty, but you see a small desk against one of the walls as well as a trash can next to it.\n");
			rooms[currentRoom].displayDescription();
		}
		else if (currentRoom == 1) {
			rooms[1].description("stuff.\n")
		}
		else {
			rooms[currentRoom].displayDescription();
		}
	}
	else {
		cout << "Please type 'help' if you are unsure what to do.\n";
	}

}

void Player::north(bool moveNorth)
{
	if (moveNorth == true)
	{
		if (currentRoom == 1)
		{
			currentRoom = 4;
		}
		else
		{
			currentRoom = 3;
		}
		cout << "You opened north side door and pass through.\n";
		rooms[currentRoom].displayDescription();
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
		if (currentRoom == 3)
		{
			currentRoom = 2;
		}
		else
		{
			currentRoom = 1;
		}
		cout << "You opened south side door and pass through.\n";
		rooms[currentRoom].displayDescription();
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
		if (currentRoom == 2)
		{
			currentRoom--;
		}
		else
		{
			currentRoom++;
		}
		cout << "You opened west side door and pass through.\n";
		rooms[currentRoom].displayDescription();
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
		if (currentRoom == 1 || currentRoom == 0)
		{
			currentRoom++;
		}
		else
		{
			currentRoom--;
		}
		cout << "You opened east side door and pass through.\n" << endl;
		rooms[currentRoom].displayDescription();
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