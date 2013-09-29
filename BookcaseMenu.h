#pragma once
#include "Menu.h"
#include "ItemHoldButton.h"

class BookcaseMenu : public Menu
{
public:
	BookcaseMenu(std::string file);
	~BookcaseMenu(void);
	void addItem(Item* item);
	void draw(sf::RenderWindow* window);
private:
	std::vector<ItemHoldButton*> itemButtons;
};

