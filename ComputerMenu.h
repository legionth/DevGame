#pragma once
#include "menu.h"
class ComputerMenu :
	public Menu
{
public:
	ComputerMenu(void);
	ComputerMenu(std::string file);
	~ComputerMenu(void);
	void actionBuy(Player* player);
	void actionDev(Player* player);
};

