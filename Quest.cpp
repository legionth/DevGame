#include "Quest.h"


Quest::Quest(sf::String questName,Item* item,std::map<int,int> need, std::map<int,int> exp)
{
	this->need = need;
	this->exp = exp;
	this->questName = questName;
	this->item = item;
}


Quest::~Quest(void)
{
}

void Quest::action(Game* game){

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


	return ret;
}
	 
Item* Quest::getItem(){
	return this->item;
}