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
    
}

void RoomObject::closeMenu(){

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