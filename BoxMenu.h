#pragma once
#include <vector>
#include "Menu.h"
#include "ItemHoldButton.h"
#include "SellButton.h"
#include "CloseButton.h"

class BoxMenu : public Menu
{
public:
	BoxMenu(std::string file);
	~BoxMenu(void);
	void sell(Game* game);
	std::vector<ItemHoldButton*> getItemButtons();
private:
	std::vector<ItemHoldButton*> itemButtons;
};

