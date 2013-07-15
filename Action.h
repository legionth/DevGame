#pragma once
#include "Menu.h"
#include "Game.h"
class Action
{
public:
	Action(void);
	Action(Menu* menu);
	~Action(void);
	void execute(Game* game);
private:
	Menu* menu;
	sf::String name;
};

