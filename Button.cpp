#include "Button.h"
#include "ActionMenu.h"
#include "Game.h"

Button::Button(void)
{
	this->actionMenu = 0;
	this->buyButton = false;
}


Button::~Button(void)
{
}
void Button::setActionMenu(ActionMenu* menu){
	this->actionMenu = menu;
}

ActionMenu* Button::getActionMenu(){
	return this->actionMenu;
}
void Button::openActionMenu(Game* game){
	game->setCurrentActiontMenu(getActionMenu());
	//this->actionMenu->action(game);
}

bool Button::isBuyButton(){
	return this->buyButton;
}

void Button::setIsBuyButton(bool b){
	this->buyButton = b;
}