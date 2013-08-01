#pragma once
#include "Menu.h"
#include "ItemHoldButton.h"
class BuyMenu : public Menu
{
public:
	BuyMenu(Menu* prevMenu);
	~BuyMenu(void);

	void draw(sf::RenderWindow* window);
private:
	std::vector<ItemHoldButton*> itemHolderButtons;
};

