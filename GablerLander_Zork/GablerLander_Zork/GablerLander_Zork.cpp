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
	int tLeft = 10;
	string userinput;
	Player player;
	cout << "Tutorial Room" << endl;
	string descrip1 = "You wake up in a mostly dark room. You don't know how you got here. All you can see is a flashlight on the floor shining against the wall.";
	vector<Room> room(6);
	room[0].description(descrip1);
	room[0].displayDescription();
	room[0].doors(false, false, false, false);
	room[1].doors(true, true, false, false);
	room[2].doors(true, false, false, true);
	room[3].doors(false, false, true, true);
	room[4].doors(false, true, true, false);
	room[5].doors(false, false, false, false);
	
	player.gameover = false;
	player.setVector(room);
	player.currentRoom = 0;
	    //initializing a clock type
	
	  //end point of clock

	clock_t c1;
	c1 = 0;

	while (player.gameover == false)
	{
		c1 = clock();
		if (tLeft - (c1 / (int)CLOCKS_PER_SEC) >= 150) {
			cout << "You smell a faint smell of smoke. " <<  endl;
		}
		else if (tLeft - (c1 / (int)CLOCKS_PER_SEC) < 150 && tLeft - (c1 / (int)CLOCKS_PER_SEC) >= 100) {
			cout << "The room is getting hotter. The building is on fire. estimated time till building burns down: " << tLeft - (c1 / (int)CLOCKS_PER_SEC) << " seconds" << endl;
		}
		else if (tLeft - (c1 / (int)CLOCKS_PER_SEC)  < 100 && tLeft - (c1 / (int)CLOCKS_PER_SEC) >= 60) {
			cout << "The heat is starting to become overwhelming. estimated time till building burns down: " << tLeft - (c1 / (int)CLOCKS_PER_SEC) << " seconds" << endl;
		}
		else if (tLeft - (c1 / (int)CLOCKS_PER_SEC)  < 60 && tLeft - (c1 / (int)CLOCKS_PER_SEC) >= 10) {
			cout << "The building is starting to splinter. You need to hurry. estimated time till building burns down: " << tLeft - (c1 / (int)CLOCKS_PER_SEC) << " seconds" << endl;
		}
		else if (tLeft - (c1 / (int)CLOCKS_PER_SEC)  < 10 && tLeft - (c1 / (int)CLOCKS_PER_SEC) >= 1) {
			cout << "You're vision is fading to black. estimated time till building burns down: " << tLeft - (c1 / (int)CLOCKS_PER_SEC) << " seconds" << endl;
		}
		else if (tLeft - (c1 / (int)CLOCKS_PER_SEC)  < 1) {
			cout << "You died\n";
			player.gameover = true;
			break;
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
		<< "The other actions you will be able to execute are take, inspect, open, and look around to see description of room." << endl
	    << "***********************************************************************************" << endl;
	cout << "Type start to begin." << endl;
	while (start != "start" || start != "exit") {
		
		try {
			getline(cin, start);
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