#include "Button.h"
#include "ActionMenu.h"
#include "Game.h"

Button::Button(void)
{
	this->actionMenu = 0;
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
	this->actionMenu->action(game);
}
