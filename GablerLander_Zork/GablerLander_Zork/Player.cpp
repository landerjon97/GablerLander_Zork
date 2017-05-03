/*
Aurthor: John Gabler, Jonathan Lander
Project: Text Based Adventure
Date: 5/3/17
*/

/*
NOTE: much of code repeates in certain way. I'm keeping commenting
to a realistic level.
*/
#include "stdafx.h"
#include "player.h"
#include "room.h"
#include "item.h"
#include <vector>



void Player::player()
{

}
//grabs vector from the startgame method also constructs items
void Player::setVector(vector<Room> room) {
	rooms = room;
	Item items;
}
//this method is where the game takes place.
//may not be the best method to use but it made sense and we went with it.
void Player::player(string pUserInput)
{
	string userInput = pUserInput;
	//if the user inputs this then display instructions only commenting the special stuff.
	if (userInput == "h" || userInput == "help" || userInput == "instructions")
	{
		instructions();
	}
	//we had to test a lot of things for the tutorial room.
	else if (currentRoom == 0 && item.keyUp == true && (userInput == "e" || userInput == "east" || userInput == "move east" || userInput == "move e")) 
	{
		//user has to have key in order to break out
		cout << "The key that you used on the door breaks but you continue into the next room.\n";
		item.keyUp = false;
		east(rooms[currentRoom].testDoor('e'));
	}
	//must make sure user has key before leaving tutor room
	else if (currentRoom == 0 && item.keyUp == false && (userInput == "e" || userInput == "east" || userInput == "move east" || userInput == "move e")) 
	{
		cout << "This door requires a key to open.\n";
	}
	//these are the directions the user can go. and then it passes it into different methods.
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
		//requires user to enter a key inorder to get out.
		if (currentRoom == 4)
		{
			cout << "This door requires a passcode. Enter it now." << endl;
			string userinput2;
			cin >> userinput2;
			if (userinput2 == "8265")
			{
				cout << "You enter the correct passcode and the door unlocks. You pass through the door and find yourself outside. Game over.\n";
				gameover = true;
			}
			else 
			{
				cout << "You entered the wrong passcode.\n";
				west(rooms[currentRoom].testDoor('w'));
			}
		}
		else {
			west(rooms[currentRoom].testDoor('w'));
		}
		
	}
	//taking of flashlight
	else if (currentRoom == 0 && userInput == "take flashlight") 
	{
		item.flashlightUp = true;
		item.flashLight();
	}
	//fundamental way of inspecting things.
	else if (currentRoom == 0 && (userInput == "inspect trash" || userInput == "inspect trashcan") && item.flashlightUp == true) 
	{
		cout << "The trash is empty.\n There's nothing to take.\n";
	}
	else if (currentRoom == 0 && userInput == "inspect desk" && item.flashlightUp == true) 
	{
		cout << "You found a key in the top left drawer.\n Maybe this key could be used on the eastern door.\n";
		item.takeKey = true;
	}
	//taking things.
	else if (currentRoom == 0 && userInput == "take key" && item.flashlightUp == true && item.takeKey == true) 
	{
		rooms[0].doors(false, true, false, false);
		item.keyUp = true;
		item.key();
	}
	else if (currentRoom == 1 && userInput == "inspect bed") 
	{
		cout << "The bed looks messy. You find a box underneath the bed it. The outline of the keyhole is red.\n";
	}
	//opening things.
	else if (currentRoom == 1 && userInput == "open box") 
	{
		//have to have key inorder to do that...
		if (item.redKey == true) 
		{
			cout << "You open the box with the red key and contains a note.\n The note reads: 'Digit: 1 Number: 8.\n";
		}
		else 
		{
			cout << "You cannot open the box it requires a key.\n";
		}
	}
	else if (currentRoom == 1 && userInput == "inspect closet") 
	{
		cout << "You find a bunch of clothes in the closet. Nothing worth taking.\n";
	}
	else if (currentRoom == 2 && userInput == "inspect oven") 
	{
		cout << "The oven contains nothing.\n";
	}
	else if (currentRoom == 2 && userInput == "inspect sink") 
	{
		cout << "The sink is filled with uncleaned dishes. Nothing worth taking.\n";
	}
	else if (currentRoom == 2 && userInput == "inspect fridge") 
	{
		cout << "You find a bunch of yummy desserts and roasted chicken.\n Now is probably not a good time to eat.\n";
	}
	else if (currentRoom == 2 && userInput == "inspect cabinet") 
	{
		cout << "The cabinet contains lots of spicies. You see a red key on one of the shelves.\n";
		item.takeRedKey = true;
	}
	else if (currentRoom == 2 && item.takeRedKey == true && userInput == "take key" || userInput == "take red key") 
	{
		cout << "You take the red key from the cabinet.\n";
		item.redKey = true;
	}
	else if (currentRoom == 2 && userInput == "inspect table") 
	{
		cout << "The table has huge scratch marks saying: 'Digit: 4 Number: 5'.\n";
	}
	else if (currentRoom == 2 && userInput == "inspect sink") 
	{
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
			cout << "You open the box and find a notecard. The notecard reads 'Digit: 2 Number: 2'.\n";
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

	//look around just displays strings of the rooms.
	//this is also where we assigned descriptions to everything.
	else if (userInput == "look around") 
	{
		if (currentRoom == 0 && item.flashlightUp == true) 
		{
			rooms[0].description("The room is almost entirely empty, but you see a small desk against one of the walls as well as a trash can next to it.\n");
			rooms[currentRoom].displayDescription();
		}
		else if (currentRoom == 1)
		{
			rooms[1].description("This room seems to be a bed room. There's a closet on the south side and a bed in the middle.\n Three doors one on east end and one on north side. The west door locked behind you.\n");
			rooms[1].displayDescription();
		}
		else if (currentRoom == 2) 
		{
			rooms[2].description("This room looks like a kichen. There is an oven, a sink, a cabinet, a table, and a fridge.\n There are two doors, north and west.\n");
			rooms[2].displayDescription();
		}
		else if (currentRoom == 3) 
		{
			rooms[3].description("You enter a room with a couch against one wall. There is also a cage that appears to be chained shut. There is a box inside the cage. \n There are doors to the south and west.");
			rooms[3].displayDescription();
		}
		else if (currentRoom == 4) 
		{
			rooms[4].description("You enter a room with a large cabinet against a wall.  There is a printer laying next to the cabinet. \n There are doors to the east, south, and west.");
			rooms[4].displayDescription();
		}
		else 
		{
			//somehow you mess the input up then it will do this
			rooms[currentRoom].displayDescription();
		}
	}
	else 
	{
		//if all fails just display help 
		cout << "Please type 'help' if you are unsure what to do.\n";
	}

}

/*
HOW WE WORKED LOCATION:
since this isnt a 2d array we decided to have an int value
that that changes based on room.
it moves around much like a for loop would with i and j
we also notified the user if he or she actually is able to move to the next
room.
*/

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
//just instruction method thats only used once but it works.
void Player::instructions()
{
	cout << "To move you will use the keys n, s, e, w to move a specific compass direction." << endl
		<< "The other actions you will be able to execute are take, inspect, open, and look around to get desciption of the room." << endl
		<< "For example you can say 'take flashlight' to pick up the flashlight." << endl;
}