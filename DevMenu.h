#pragma once
#include "Menu.h"
//#include "Quest.h"
class Quest;
class DevMenu : public Menu
{
public:
	DevMenu(std::string file,Menu* prevMenu);
	~DevMenu(void);
	void addQuest(Quest* quest);

	void draw(sf::RenderWindow* window);
private:
	std::vector<Quest*> quests;
};

