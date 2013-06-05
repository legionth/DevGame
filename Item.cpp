/* 
 * File:   Item.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:35
 */

#include "Item.h"

Item::Item() {
}

Item::Item(const Item& orig) {
}

Item::Item(int id){
	this->id = id;
}

Item::Item(int id,std::string toolTip){
	this->id = id;
	this->toolTip.setString(toolTip);
}


Item::~Item() {
}

int Item::getId(){
    return this->id;
}

void Item::setId(int i){
    this->id = i;
}

sf::Text Item::getToolTip(){
	return this->toolTip;
}

void Item::setToolTip(std::string toolTip){
	this->toolTip.setString(toolTip);
}

