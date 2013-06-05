#include "CloseButton.h"
#include "Menu.h"
#include "Game.h"

CloseButton::CloseButton(Menu* menu,Menu* prevMenu)
{
	this->menu = menu;
	this->prevMenu = prevMenu;
	createSprite("button_close.png");
	setFrameSize(SIZE_BUTTON_WIDTH_NORMAL,SIZE_BUTTON_HEIGHT_NORMAL);
}

CloseButton::CloseButton()
{
	createSprite("button_close.png");
	setFrameSize(SIZE_BUTTON_WIDTH_NORMAL,SIZE_BUTTON_HEIGHT_NORMAL);
}

void CloseButton::setMenu(Menu* menu){
	this->menu = menu;
}

void CloseButton::setPrevMenu(Menu* menu){
	this->prevMenu = menu;
}

CloseButton::~CloseButton(void)
{
	//delete menu;
}

void CloseButton::action(Game* game){
	menu->close();
	if(prevMenu != 0){
		prevMenu->open();
	}
	game->setCurrentMenu(prevMenu);
}
