#pragma once
#include "Button.h"
#include "Game.h"
#include "Item.h"

class Quest
{
public:
	Quest(sf::String questName,Item* item,std::map<int,int> need, std::map<int,int> exp);
	~Quest(void);

	void action(Game* game);
	void hide();
	void show();
	void setVisible(bool visible);

	bool isAvaible(Game* game);

	Item* getItem();
private:
	bool visible;
	Item* item;
	sf::String questName;

	std::map<int,int> need;
	std::map<int,int> exp;
};

