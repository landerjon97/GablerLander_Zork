// GablerLander_Zork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "room.h"
#include "item.h"
#include "player.h"
#include <vector>
#include "time.h"
#include <string>

using namespace std;

void gameStart() {
	int tLeft = 240;
	string userinput;
	Player player;
	bool gameover = false;
	cout << "Tutorial Room" << endl;
	string descrip1 = "You wake up in a mostly dark room. You don't know how you got here. All you can see is a flashlight on the floor shining against the wall. You can smell the faint scent of smoke.";
	vector<Room> room(6);
	room[0].description(descrip1);
	room[0].displayDescription();
	room[0].doors(false, false, false, false);
	room[1].doors(true, true, false, false);
	room[2].doors(true, false, false, true);
	room[3].doors(false, false, true, true);
	room[4].doors(false, true, true, false);
	room[5].doors(false, false, false, false);
	room[1].description("room 1");
	room[2].description("room 2");
	room[3].description("room 3");
	room[4].description("room 4");
	room[5].description("room 5");

	player.setVector(room);
	player.currentRoom = 0;
	clock_t c1;     //initializing a clock type

	  //end point of clock



	while (gameover == false)
	{
		c1 = clock();
		tLeft -= c1 / (int)CLOCKS_PER_SEC;
		if (tLeft >= 150) {
			cout << "You smell a faint smell of smoke." << tLeft << " seconds" << endl;
		}
		else if (tLeft < 150 && tLeft >= 100) {
			cout<< "The room is getting hotter. The building is on fire. estimated time till building burns down: " << tLeft << " seconds" << endl;
		}
		
		getline(cin, userinput);
		player.player(userinput);
		
	}
}


int main()
{
	string start;
	cout<< "***********************************************************************************" << endl 
		<< "Welcome to our game. In this game you will use"
		<< " text to navigate through different rooms with the goal to escape." << endl 
		<< "You will use the keys n, s, e, w to move a certain compass direction." << endl
		<< "The other actions you will be able to execute are take, inspect, use, and look around." << endl
	    << "***********************************************************************************" << endl;
	cout << "Type start to begin." << endl;
	while (start != "start" || start != "exit") {
		
		try {
			cin >> start;
			if (start == "start") {
				gameStart();
			}
			else if (start == "exit") {
				return 0;
			}
			else if (start == "help") {
				cout << "Your current options are: \n exit: to leave game. \n start: to begin game.\n";
			}
			else {
				cout << "Please type 'start' to begin or 'exit' to leave." << endl;
			}
		}
		catch (exception ex) {
			cout << "Something went wrong." << endl;
		}
	}
	getchar();
    return 0;
}