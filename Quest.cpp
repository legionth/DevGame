#include "Quest.h"


Quest::Quest(int id,std::string questName,Item* item,std::map<int,int> need, std::map<int,int> exp, int money)
{
	this->need = need;
	this->exp = exp;
	this->questName.setString(questName);
	this->item = item;
	this->id = id;
	this->completed = false;
	this->money = money;
	this->createSprite("button_quest.png");
	this->setFrameSize(SIZE_QUEST_BUTTON_WIDTH_NORMAL,SIZE_QUEST_BUTTON_HEIGHT_NORMAL);

	this->need[MATH_ID]			= 0;
	this->need[ALGORITHM_ID]	= 0;
	this->need[PROGRAMMING_ID]  = 0;
	this->need[DESIGN_ID]		= 0;
	this->need[DATABASES_ID]	= 0;
	this->need[ELECTRONICS_ID]	= 0;
}


Quest::~Quest(void)
{
}

void Quest::action(Game* game){
//	if(isAvaible(game) && isVisible()){

	//}
}

void Quest::hide(){
	this->visible = false;
}

void Quest::show(){
	this->visible = true;
}

void Quest::setVisible(bool visible){
	this->visible = visible;
}
	 
bool Quest::isAvaible(Game* game){
	Player* player = game->getPlayer();
	bool ret = false;
	if(	this->need[MATH_ID] == player->getMath()				&&
		this->need[ALGORITHM_ID] == player->getAlgortihm()		&&
		this->need[PROGRAMMING_ID] == player->getProgramming()	&&
		this->need[DESIGN_ID] == player->getDesign()			&&
		this->need[DATABASES_ID] == player->getDatabases()		&&
		this->need[ELECTRONICS_ID] == player->getElectronics()){
			ret = true;
	}
	return ret;
}
	 
Item* Quest::getItem(){
	return this->item;
}

bool Quest::isVisible(){
	return this->visible;
}

void Quest::setDescription(std::string description){
	this->description.setString(description);
}

sf::Text Quest::getQuestDescription(){
	return this->description;
}

bool Quest::isComplete(){
	return this->completed;
}


int Quest::getMoney(){
	return this->money;
}

void Quest::draw(sf::RenderWindow* window){
	DrawAble::draw(window);
	window->draw(this->description);
	window->draw(this->questName);
}
