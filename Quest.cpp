#include "Quest.h"


Quest::Quest(int id,sf::String questName,Item* item,std::map<int,int> need, std::map<int,int> exp, int money)
{
	this->need = need;
	this->exp = exp;
	this->questName = questName;
	this->item = item;
	this->id = id;
	this->completed = false;
	this->money = money;
}


Quest::~Quest(void)
{
}

void Quest::action(Game* game){
	if(isAvaible(game) && isVisible()){

	}
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

void Quest::setDescription(sf::String description){
	this->description = description;
}

sf::String Quest::getQuestDescription(){
	return this->description;
}

bool Quest::isComplete(){
	return this->completed;
}


int Quest::getMoney(){
	return this->money;
}