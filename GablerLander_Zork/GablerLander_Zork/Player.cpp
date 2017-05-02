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
		if (currentRoom == 4)
		{
			cout << "This door requires a passcode. Enter it now." << endl;
			string userinput2;
			cin >> userinput2;
			if (userinput2 == "8265")
			{
				cout << "You enter the correct passcode and the door unlocks. You pass through the door and find yourself outside. Game over.\n";
			}
			else {
				cout << "You entered the wrong passcode.\n";
			}
		}
		west(rooms[currentRoom].testDoor('w'));
	}
	else if (currentRoom == 0 && userInput == "take flashlight") {
		item.flashlightUp = true;
		item.flashLight();
	}
	else if (currentRoom == 0 && (userInput == "inspect trash" || userInput == "inspect trash") && item.flashlightUp == true) {
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

	else if (currentRoom == 1 && userInput == "inspect bed") {
		cout << "The bed looks messy. You find a box underneath the bed it. The outline of the keyhole is red.\n";
	}
	else if (currentRoom == 1 && userInput == "open box") {
		if (item.redKey == true) {
			cout << "You open the box with the red key and contains a note.\n The note reads: 'Digit: 1 Number: 8";
		}
		else {
			cout << "You cannot open the box it requires a key.\n";
		}
	}
	else if (currentRoom == 1 && userInput == "inspect closet") {
		cout << "You find a bunch of clothes in the closet. Nothing worth taking.\n";
	}
	else if (currentRoom == 2 && userInput == "inspect oven") {
		cout << "The oven contains nothing.\n";
	}
	else if (currentRoom == 2 && userInput == "inspect sink") {
		cout << "The sink is filled with uncleaned dishes. Nothing worth taking.\n";
	}
	else if (currentRoom == 2 && userInput == "inspect fridge") {
		cout << "You find a bunch of yummy desserts and roasted chicken.\n Now is probably not a good time to eat.\n";
	}
	else if (currentRoom == 2 && userInput == "inspect cabinet") {
		cout << "The cabinet contains lots of spicies. You see a red key on one of the shelves.\n";
		item.takeRedKey = true;
	}
	else if (currentRoom == 2 && item.takeRedKey == true && userInput == "take key" || userInput == "take red key") {
		cout << "You take the red key from the cabinet\n";
		item.redKey = true;
	}
	else if (currentRoom == 2 && userInput == "inspect table") {
		cout << "The table has huge scratch marks saying: 'Digit: 4 Number: 5'\n";
	}
	else if (currentRoom == 2 && userInput == "inspect sink") {
		cout << "The sink is filled with uncleaned dishes. Nothing worth taking.\n";
	}
	else if (currentRoom == 3 && userInput == "inspect couch")
	{
		cout << "You inspect the couch and find a blue key under a cushion. You take the key.\n";
		item.blueKey = true;
	}
	else if (currentRoom == 3 && userInput == "inspect cage")
	{
		if (item.boltcutters == true)
		{
			cout << "You use the boltcutter to cut the chain and open the cage. There is a box on the ground.\n";
			item.inspectBox = true;
		}
		else
		{
			cout << "The cage is chained shut. Try finding something to open it.\n";
		}
	}
	else if (currentRoom == 3 && userInput == "open box")
	{
		if (item.inspectBox == true)
		{
			cout << "You open the box and find a notecard. The notecard reads 'Digit: 2 Number: 2'\n";
		}
		else
		{
			cout << "You can't open the box because it is locked in the cage.\n";
		}
	}
	else if (currentRoom == 4 && userInput == "inspect cabinet")
	{
		if (item.blueKey == true)
		{
			cout << "You use the blue key to unlock the cabinet. You find boltcutters and take them.\n";
			item.boltcutters = true;
		}
		else
		{
			cout << "You try to open the cabinet and it is locked. The lock has a blue outline.\n";
		}
	}
	else if (currentRoom == 4 && userInput == "inspect printer")
	{
		cout << "You inspect the printer and find a note scrawled on the inside. It reads 'Digit: 3 Number: 6'.\n";
	}
	else if (userInput == "look around") {
		if (currentRoom == 0 && item.flashlightUp == true) {
			rooms[0].description("The room is almost entirely empty, but you see a small desk against one of the walls as well as a trash can next to it.\n");
			rooms[currentRoom].displayDescription();
		}
		else if (currentRoom == 1) {
			rooms[1].description("This room seems to be a bed room. There's a closet on the south side and a bed in the middle.\n Three doors one on east end and one on north side. The west door locked behind you.\n");
			rooms[1].displayDescription();
		}
		else if (currentRoom == 2) {
			rooms[2].description("This room looks like a kichen. There is an oven, a sink, a cabinet, a table, and a fridge.\n There are two doors, north and west\n");
			rooms[2].displayDescription();
		}
		else if (currentRoom == 3) {
			rooms[3].description("You enter a room with a couch against one wall. There is also a cage that appears to be chained shut. There is a box inside the cage. There are doors to the south and west.");
			rooms[3].displayDescription();
		}
		else if (currentRoom == 4) {
			rooms[4].description("You enter a room with a large cabinet against a wall.  There is a printer laying next to the cabinet. There are doors to the east, south, and west.");
			rooms[4].displayDescription();
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
		<< "The other actions you will be able to execute are take, inspect, open." << endl
		<< "For example you can say 'take flashlight' to pick up the flashlight." << endl;
}