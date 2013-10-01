#include "DrawAble.h"
#pragma once

class Game;
class ActionMenu;
class Button: public DrawAble{
public:
	Button(void);
	~Button(void);

	virtual void action(Game* game) = 0;
	void setLabel(sf::String label);
	void setActionMenu(ActionMenu* menu);
	ActionMenu* getActionMenu();
	void openActionMenu(Game* game);
	bool isBuyButton();
	void setIsBuyButton(bool b);
private:
	sf::String label;
	ActionMenu* actionMenu;
	bool buyButton;
};

