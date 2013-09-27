#include "Action.h"
#include "Game.h"


Action::Action(void)
{
	this->menu = 0;
	this->name = new sf::Text();
	this->setFrameSize(SIZE_ACTION_MENU_WIDTH_NORMAL,SIZE_ACTION_MENU_HEIGHT_NORMAL);
	this->createSprite("button_action_menu_notselect.png");
}


Action::~Action(void)
{
}

void Action::action(Game* game){
	if(this->menu != 0){
		this->menu->open();
		game->setCurrentMenu(this->menu);
	}

}

void Action::setName(std::string name){
	this->name->setString(name);
}

void Action::draw(sf::RenderWindow* window){
	//Button::draw(game);
	window->draw(*this->getSprite());
	window->draw(*this->name);
}
