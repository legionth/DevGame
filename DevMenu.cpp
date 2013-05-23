#include "DevMenu.h"


DevMenu::DevMenu(std::string file,Menu* prevMenu):Menu(file)
{
	this->addButton(new CloseButton(this,prevMenu));
}


DevMenu::~DevMenu(void)
{
}
