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
	bool takeBlueKey = false;
	bool yellowKey = false;
	bool redKey = false;
	bool blueKey = false;
	bool boltcutters = false;
	bool takeBoltcutters = false;
	bool inspectBox = false;

	Item();
	void flashLight();
	void key();
};

#endif // !1
