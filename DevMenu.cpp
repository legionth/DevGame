#include "DevMenu.h"
#include "Quest.h"

DevMenu::DevMenu(std::string file,Menu* prevMenu):Menu(file,MENU_DEV)
{
	std::map<int,int> need;
	need[MATH_ID] = 0;
	need[ALGORITHM_ID] = 0;
	need[PROGRAMMING_ID] = 0;
	need[DESIGN_ID] = 0;
	need[DATABASES_ID] = 0;
	need[ELECTRONICS_ID] = 0;

	std::map<int,int> exp;
	exp[MATH_ID] = 0;
	exp[ALGORITHM_ID] = 0;
	exp[PROGRAMMING_ID] = 1;
	exp[DESIGN_ID] = 0;
	exp[DATABASES_ID] = 0;
	exp[ELECTRONICS_ID] = 0;
	
	std::string description = "Hello World Programm!";
	Quest *quest = new Quest(QUEST_HELLO_WORLD,"HelloWorld",0,need,exp,0);
	
	quest->setDescription(description);
	this->addButton(quest);

	this->addButton(new CloseButton(this,prevMenu));
	arrangeButtons();
}


DevMenu::~DevMenu(void)
{
}
