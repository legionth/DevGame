#pragma once
#include "Menu.h"
#include "Button.h"
class Game;
class Action : public Button
{
public:
	Action(void);
	Action(Menu* menu);
	~Action(void);
	void action(Game* game);
	void draw(sf::RenderWindow* window);
	void setName(std::string name);
private:
	Menu* menu;
	sf::Text *name;
};

