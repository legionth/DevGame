#pragma once
#include "Button.h"
#include "Game.h"
#include "Item.h"

/**
* Quest Button returns Items and +/- Attrbiutes. Should be used to improve player skills and/or add a
* Item to Inventory
* Should work for all Menu's	@TODO test this :P
*/
class Quest : public Button
{
public:
	Quest(int id,Item* item,std::map<int,int> need, std::map<int,int> exp,int money=0,int x=0,int y=0);
	~Quest(void);

	void action(Game* game);
	void hide();
	void show();
	void setVisible(bool visible);
    	void setPosition(int x, int y);

	bool isAvaible(Game* game);
	bool isVisible();
	bool isComplete();

	void complete();
	Item* getItem();

	void setDescription(std::string description);
	sf::Text* getQuestDescription();

	int getId();
	int getMoney();
    	void draw(sf::RenderWindow* window);
	sf::Sprite* getGameDisplaySprite();
	std::map<int,int> getExperience();
	// CurrentQuest Functions	
	bool isCompleted();
	void startQuest();
	void stopQuest();
	void restartQuest();

	int getMaxTime();
private:
	int id;
        bool visible;								        // If this quest is shown in Menu
	Item* item;
	sf::Text *questName;
	sf::Text *description;
	sf::Clock clock;
	int maxTime; 									// Max Time in Second that is needed to complete the Quest

	std::map<int,int> need;								// Need Attributes by Player
	std::map<int,int> exp;								// Experience reward for completed this quest
	bool completed;										// Completed Quest
	int money;
    	sf::Text* getNameText();
    	sf::Text* getDescText();
	sf::Sprite* gameDisplaySprite;							// gameDisplaySprite is for drawing the current Quest in Game class
	std::string getDisplaySpriteImgText();						// filter img for display sprite
	void changeSprite(std::string file);
};

