#pragma once
#include "Menu.h"
class Game;
class Action
{
public:
	Action(void);
	Action(Menu* menu);
	~Action(void);
	void execute(Game* game);
	void setName(sf::String name);
private:
	Menu* menu;
	sf::String name;
};

