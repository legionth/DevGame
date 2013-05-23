/* 
 * File:   RoomObject.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:35
 */

#include "RoomObject.h"

RoomObject::RoomObject() {
}

RoomObject::RoomObject(const RoomObject& orig) {
}

RoomObject::~RoomObject() {
}

void RoomObject::use(){

}

void RoomObject::openMenu(){
	this->menu->open();
}

void RoomObject::closeMenu(){
	this->menu->close();
}

void RoomObject::setMenu(Menu* menu){
	this->menu = menu;
}

int RoomObject::getId(){
	return this->id;
}

void RoomObject::setId(int i){
	this->id = i;
}

bool RoomObject::isMenuOpen(){
	return this->menu->isOpen();
}

void RoomObject::drawMenu(sf::RenderWindow* window){
	this->menu->draw(window);
	for(int i = 0; i < menu->getButtons().size();i++){
		Button* button = menu->getButtons()[i];
		button->draw(window);
	}
}

Menu* RoomObject::getMenu(){
	return this->menu;
}
