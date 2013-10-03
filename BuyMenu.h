#pragma once
#include "Menu.h"
#include "BuyButton.h"

class BuyMenu : public Menu
{
public:
	BuyMenu(Menu* prevMenu);
	~BuyMenu(void);

	void draw(sf::RenderWindow* window);
	std::vector<BuyButton*> getBuyButtons();
private:
	std::vector<BuyButton*> itemHolderButtons;
	std::vector<sf::Text*> text;
	std::vector<sf::Text*> price;

	sf::Text* getText(int id);
};

