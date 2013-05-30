#include "MenuButton.h"
#include "Menu.h"
#include "Game.h"

MenuButton::MenuButton(Menu* menu,Menu* prevMenu,std::string spriteFile)
{
	this->menu = menu;
	this->prevMenu = prevMenu;
	createSprite(spriteFile);
	setFrameSize(SIZE_BUTTON_WIDTH_NORMAL,SIZE_BUTTON_HEIGHT_NORMAL);
}

MenuButton::MenuButton(){
	createSprite("button_close.png");
	setFrameSize(SIZE_BUTTON_WIDTH_NORMAL,SIZE_BUTTON_HEIGHT_NORMAL);
}

MenuButton::~MenuButton(void)
{
	delete menu;
}

void MenuButton::action(Game* game){
	menu->open();
	prevMenu->close();
	game->setCurrentMenu(menu);

}
