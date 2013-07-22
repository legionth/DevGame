#include "Action.h"
#include "Game.h"


Action::Action(void)
{
	this->menu = 0;
}


Action::~Action(void)
{
}

void Action::execute(Game* game){
	if(this->menu != 0){
		this->menu->open();
		game->setCurrentMenu(this->menu);
	}

}

void Action::setName(sf::String name){
	this->name = name;
}
