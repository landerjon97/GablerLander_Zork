// GablerLander_Zork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "room.h"
#include "item.h"
#include "player.h"

using namespace std;


int main()
{
	cout<< "***********************************************************************************" << endl << "Welcome to GAMENAME. In this game you will use"
		<< " text to navigate through the level." << endl << "To move you will use the keys N, S, E, W to move a certain compass direction." << endl
		<< "The other actions you will be able to execute are take, inspect, use, and combine." << endl
	    << "***********************************************************************************" << endl;
	cout << "Type start to begin." << endl;
	getchar();


    return 0;
}

/*
Tutorial Room
-- You wake up in a mostly dark room. You don't know how you got here. All you can see 
       is a flashlight on the floor shining against the wall.
-- User picks up flashlight (take flashlight)
-- You scan the room with the flashlight and find yourself in a room with two doors.
-- The room is almost entirely empty, but you see a small desk against one of the walls as well as a trash can next to it.
-- On another wall there is a chalkboard with faint writing on it. (inspect chalkboard)
-- The chalkboard gives a more detailed description on how to execute commands
-- When entering a room, a detailed description will appear on the screen, to redisplay updated description simply state (inspect room)
-- To pick up an item (take item)
-- To use item (use item to unlock door)
-- Some items will need to be combined to be useful (combine key and rope)
-- Nothing in the trashcan, the desk contains a ring of keys containing a blue, yellow, and red key. (inspect desk) (take keys)
-- Blue key opens door to the east. (use blue key to unlock door)
-- Door is unlocked and user exits room
*/