#ifndef ITEM_H
#define ITEM_H
class Item {
private:
public:
	bool flashlightUp = false;
	bool keyUp = false;
	bool takeKey = false;
	bool takeRedKey = false;
	bool takeYellowKey = false;
	bool yellowKey = false;
	bool redKey = false;

	Item();
	void chest();
	void flashLight();
	void note1();
	void note2();
	void note3();
	void note4();
	void bed();
	void box();
	void briefcase();
	void doll();
	void crowbar();
	void printer();
	void cabinet();
	void finaldoor();
	void key();


};

#endif // !1
