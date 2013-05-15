#include "Button.h"
#pragma once

class Menu;
class Game;
class CloseButton : public Button
{
public:
	void action(Game* game);
	CloseButton(Menu* menu,Menu* prevMenu);
	CloseButton();
	void setMenu(Menu* menu);
	void setPrevMenu(Menu* menu);
	~CloseButton(void);
private:
	Menu* menu;
	Menu* prevMenu;
};

