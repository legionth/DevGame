#include "CloseButton.h"
#include "Menu.h"

CloseButton::CloseButton(Menu* menu)
{
	this->menu = menu;
	createSprite("button_close.png");
	setFrameSize(SIZE_BUTTON_WIDTH_NORMAL,SIZE_BUTTON_HEIGHT_NORMAL);
}

CloseButton::CloseButton()
{
	createSprite("button_close.png");
	setFrameSize(SIZE_BUTTON_WIDTH_NORMAL,SIZE_BUTTON_HEIGHT_NORMAL);
}



CloseButton::~CloseButton(void)
{
	delete menu;
}

void CloseButton::action(){
	menu->close();
}
