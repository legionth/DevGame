/* 
 * File:   Menu.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:35
 */

#include "Menu.h"

Menu::Menu() {
	this->isopen = false;
	//addButton(new CloseButton(this,0));
}

Menu::Menu(std::string file, int id) {
	this->isopen = false;
	createSprite(file);
	this->setFrameSize(SIZE_WINDOW_WIDTH_NORMAL,SIZE_WINDOW_HEIGHT_NORMAL);
//	addButton(new CloseButton(this));
	this->id = id;
}

Menu::Menu(const Menu& orig) {
	this->isopen = false;
}

Menu::~Menu() {
	buttons.clear();
}

void Menu::open(){
	this->isopen = true;
}

void Menu::close(){
	this->isopen = false;
}

void Menu::actionClose(){
	this->isopen = false;
}

bool Menu::isOpen(){
	return this->isopen;
}


void Menu::addButton(Button* button){
	buttons.push_back(button);
}

std::vector<Button*> Menu::getButtons(){
	return buttons;
}

void Menu::draw(sf::RenderWindow* window){
	DrawAble::draw(window);
	std::cout<<"Menu::draw"<<std::endl;
	for(int i = 0; i < this->getButtons().size();i++){
		Button* button = this->getButtons()[i];
		button->draw(window);
	}

}


void Menu::arrangeButtons(){
	for(int i = 0; i < this->buttons.size(); i++){
		this->buttons[i]->setPosition(SIZE_WINDOW_WIDTH_NORMAL/2 - this->buttons[i]->getFrameWidth()/2,this->buttons[i]->getFrameHeight()*i +8);
	}
}

void Menu::setId(int id){
	this->id = id;
}

int Menu::getId(){
	return this->id;
}

