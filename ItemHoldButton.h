#pragma once
#include "PopUpMenu.h"
#include "Item.h"

class Game;
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

