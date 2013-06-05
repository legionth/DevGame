#pragma once
#include "Button.h"
#include "Game.h"
#include "Item.h"

/**
* Quest Button returns Items and +/- Attrbiutes. Should be used to improve player skills and/or add a
* Item to Inventory
* Shoul work for all Menu's	@TODO test this :P
*/
class Quest : public Button
{
public:
	Quest(int id,std::string questName,Item* item,std::map<int,int> need, std::map<int,int> exp,int money=0);
	~Quest(void);

	void action(Game* game);
	void hide();
	void show();
	void setVisible(bool visible);

	bool isAvaible(Game* game);
	bool isVisible();
	bool isComplete();

	void complete();
	Item* getItem();

	void setDescription(std::string description);
	sf::Text getQuestDescription();

	int getId();

	int getMoney();
	void draw(sf::RenderWindow* window);
private:
	int id;
	bool visible;										// If this quest is shown in Menu
	Item* item;
	sf::Text questName;
	sf::Text description;

	std::map<int,int> need;								// Need Attributes by Player
	std::map<int,int> exp;								// Experience reward for completed this quest
	bool completed;										// Completed Quest
	int money;
};

