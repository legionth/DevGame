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
	
	Quest *quest = new Quest(QUEST_HELLO_WORLD,0,need,exp,0,0,0);
	this->addQuest(quest);
        
	need[MATH_ID] = 0;
	need[ALGORITHM_ID] = 0;
	need[PROGRAMMING_ID] = 1;
	need[DESIGN_ID] = 0;
	need[DATABASES_ID] = 0;
	need[ELECTRONICS_ID] = 0;

	exp[MATH_ID] = 1;
	exp[ALGORITHM_ID] = 0;
	exp[PROGRAMMING_ID] = 1;
	exp[DESIGN_ID] = 0;
	exp[DATABASES_ID] = 0;
	exp[ELECTRONICS_ID] = 0;
        
        quest = new Quest(QUEST_CALCULATOR,0,need,exp,0,0,0);
	this->addQuest(quest);

	CloseButton* closeButton = new CloseButton(this,prevMenu);
	closeButton->setPosition(SIZE_WINDOW_WIDTH_NORMAL - SIZE_BUTTON_WIDTH_NORMAL, 
							 SIZE_WINDOW_HEIGHT_NORMAL- SIZE_BUTTON_HEIGHT_NORMAL);
	
	this->addButton(closeButton);

	
}


DevMenu::~DevMenu(void)
{
	this->quests.clear();
}

void DevMenu::addQuest(Quest* quest){
	if(quests.size() != 0){
		quest->setPosition(quests[quests.size()-1]->getXPosition(),
			               quests[quests.size()-1]->getYPosition()+SIZE_QUEST_BUTTON_HEIGHT_NORMAL);
	}else{
		quest->setPosition(128,0);
	}

	this->quests.push_back(quest);
}

void DevMenu::draw(sf::RenderWindow* window){
	Menu::draw(window);

	for(int i = 0; i < quests.size(); i++){
            window->draw(*quests[i]->getSprite());
            quests[i]->draw(window);
	}
}
