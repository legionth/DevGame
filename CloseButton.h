#include "Button.h"
#pragma once

class Menu;
class CloseButton : public Button
{
public:
	void action();
	CloseButton(Menu* menu);
	CloseButton();
	~CloseButton(void);
private:
	Menu* menu;
};

