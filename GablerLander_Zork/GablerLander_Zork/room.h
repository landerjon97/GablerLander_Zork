#ifndef ROOM_H
#define ROOM_H
#include <string>

using namespace std;
class Room {
private:
	string info;
	bool north;
	bool east;
	bool south;
	bool west;
public:
	Room();
	void items();
	void description(string pDescrip);
	void displayDescription();
	void doors(bool n, bool e, bool s, bool w);
	bool testDoor(char pDirection);
	int roomNumber;


};


#endif

