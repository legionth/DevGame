/* 
 * File:   Menu.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:35
 */

#include "Menu.h"

Menu::Menu() {
	this->isopen = false;
}

Menu::Menu(std::string file) {
	this->isopen = false;
	createSprite(file);
}

Menu::Menu(const Menu& orig) {
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