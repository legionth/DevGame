#pragma once
#include "menu.h"
#include "DevMenu.h"
#include "BuyMenu.h"


class ComputerMenu :
	public Menu
{
public:
	ComputerMenu(void);
	ComputerMenu(std::string file);
	~ComputerMenu(void);
	void actionBuy();
	void actionDev();
private:
	BuyMenu* buyMenu;
	DevMenu* devMenu;
};

