/*
Aurthor: John Gabler, Jonathan Lander
Project: Text Based Adventure
Date: 5/3/17
*/

/*
************************************************
NOTE: MUST BE RAN ON VISUAL STUDIO 2017 NOT 2015
************************************************
*/
//included libraries
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
	//using a timing variable called tLeft
	int tLeft = 480;
	//way to get user input
	string userinput;
	//contructing player class
	Player player;
	//introduction
	cout << "Tutorial Room" << endl;
	string descrip1 = "You wake up in a mostly dark room. You don't know how you got here. All you can see is a flashlight on the floor shining against the wall.";
	//creating rooms with a vector
	//NOTE: Not 2d but we simulate the 2d while playing. (technically its is a 3x2)
	vector<Room> room(6);
	//will be describing these in their classes
	room[0].description(descrip1);
	room[0].displayDescription();
	room[0].doors(false, false, false, false);
	room[1].doors(true, true, false, false);
	room[2].doors(true, false, false, true);
	room[3].doors(false, false, true, true);
	room[4].doors(false, true, true, false);
	room[5].doors(false, false, false, false);
	//set game over to false before it enters the loop 
	player.gameover = false;
	//passing the vector into the player.cpp
	player.setVector(room);
	//starting in the first room
	player.currentRoom = 0;
	//creating the clock to test to see if user runs out of time
	clock_t c1;
	//setting clock to zero
	c1 = 0;
	//the main game loop
	while (player.gameover == false)
	{
		///start the timer
		c1 = clock();
		//if time left - clock is greater than or equal to 150 seconds and so on.
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
			//break automatically closes the loop
			break;
		}
		//getline read the entire line. this is the only way to get two word inputs.
		getline(cin, userinput);
		//passing user input into the player class where most of the work is done.
		player.player(userinput);
	}
}


int main()
{
	//this is the start screen. User must type start before actually playing the game. 
	//firgured this is smarter to do than just having it all in one method.
	string start;
	cout << "***********************************************************************************" << endl
		<< "Welcome to our game. In this game you will use"
		<< " text to navigate through different rooms with the goal to escape." << endl
		<< "You will use the keys n, s, e, w to move a certain compass direction." << endl
		<< "The other actions you will be able to execute are take, inspect, open, and look around to see description of room." << endl
		<< "You also only have a set amount of time. You better hurry." << endl
	    << "***********************************************************************************" << endl;
	cout << "Type start to begin." << endl;
	//stupid proofing the start screen.
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