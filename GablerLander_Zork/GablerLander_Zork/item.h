#ifndef ITEM_H
#define ITEM_H
class Item {
private:
public:
	bool flashlightUp = false;
	bool keyUp = false;
	bool takeKey = false;
	bool chestLock = true;
	Item();
	void chest();
	void flashLight();
	void note();
	void key();
};

#endif // !1
