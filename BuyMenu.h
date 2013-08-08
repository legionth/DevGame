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
	std::vector<sf::Text*> text;
	std::vector<sf::Text*> price;

	sf::Text* getText(int id);
};

