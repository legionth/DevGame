#pragma once
#include "Menu.h"
#include "ItemHoldButton_Select.h"

class BookcaseMenu : public Menu
{
public:
	BookcaseMenu(std::string file);
	~BookcaseMenu(void);
	void addItem(Item* item);
	void draw(sf::RenderWindow* window);
	void setCurrentDescription(std::string desc);
	sf::Text getCurrentDescription();
	std::vector<ItemHoldButtonSelect*> getItemHoldButtons();
private:
	std::vector<ItemHoldButtonSelect*> itemButtons;
	sf::Text currentDescription;
};

