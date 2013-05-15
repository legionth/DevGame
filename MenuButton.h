#include "Button.h"

#pragma once;


class Menu;
class Game;
class MenuButton: public Button{
public:
	MenuButton(Menu* menu,Menu* prevMenu,std::string spriteFile);
	MenuButton();
	~MenuButton(void);
	void action(Game* game);
private:
	Menu* menu;
	Menu* prevMenu;
};