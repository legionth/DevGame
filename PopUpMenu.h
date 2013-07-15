#pragma once
#include <vector>
#include "Menu.h"
#include "Action.h"
class PopUpMenu : public Menu
{
public:
	PopUpMenu(void);
	~PopUpMenu(void);
	void getActions();
private:
	std::vector<Action*> actions;
};

