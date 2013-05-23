#include "Menu.h"
#pragma once

class DevMenu:public Menu
{
public:
	DevMenu(std::string file,Menu* prevMenu);
	~DevMenu(void);
};

