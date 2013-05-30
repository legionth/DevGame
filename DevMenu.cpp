#include "DevMenu.h"


DevMenu::DevMenu(std::string file,Menu* prevMenu):Menu(file)
{
	this->addButton(new CloseButton(this,prevMenu));
	arrangeButtons();
}


DevMenu::~DevMenu(void)
{
}
