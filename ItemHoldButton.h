#pragma once
#include "Item.h"
#include "Button.h"

class Game;
class PopUpMenu;
class ItemHoldButton : public Button
{
public:
	ItemHoldButton(void);
	~ItemHoldButton(void);
	void openPopUpMenu();
	bool isFull();
	void setItem(Item* item);
	Item* getItem();
	void clearItem();
	void action(Game* game);
private:
	PopUpMenu* popUpMenu;
	Item* item;
};

