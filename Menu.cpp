/* 
 * File:   Menu.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:35
 */

#include "Menu.h"

Menu::Menu() {
	this->isopen = false;
	addButton(new CloseButton(this));
}

Menu::Menu(std::string file) {
	this->isopen = false;
	createSprite(file);
	this->setFrameSize(SIZE_WINDOW_WIDTH_NORMAL,SIZE_WINDOW_HEIGHT_NORMAL);
	addButton(new CloseButton(this));
}

Menu::Menu(const Menu& orig) {
	this->isopen = false;
}

Menu::~Menu() {
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