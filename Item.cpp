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
	this->sellPrice = 0;
	this->buyPrice = 0;
	this->sellAble = true;
	this->unique = false;

	switch(id){								
		case ITEM_BOOK_HELLO_WORLD:
			this->createSprite("book_hello_world.png");
			this->unique = true;
			this->book = true;
			break;
		case ITEM_BOOK_CALCULATOR:
			this->createSprite("book_calculator.png");
			this->unique = true;
			this->book = true;
			break;
	}

	this->setFrameSize(SIZE_ITEM_WIDTH_NORMAL,SIZE_ITEM_HEIGHT_NORMAL);

	this->description = this->generateDescription();
}

Item::Item(int id,std::string toolTip){
	this->id = id;
	this->toolTip.setString(toolTip);
	this->sellPrice = 0;
	this->buyPrice = 0;
	this->sellAble = true;
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



int Item::getSellPrice(){
	return this->sellPrice;
}

void Item::setSellPrice(int i){
	this->sellPrice = i;
}

int Item::getBuyPrice(){
	return this->buyPrice;
}
	
void Item::setBuyPrice(int i){
	this->buyPrice = i;
}

bool Item::isSellAble(){
	return this->sellAble;
}

void Item::setSellAble(bool b){
	this->sellAble = b;
}

bool Item::isUnique(){
	return this->unique;
}

bool Item::isBook(){
	return this->book;
}

sf::Text* Item::generateDescription(){
	sf::Text* text = new sf::Text();
	switch(this->id){
		case ITEM_BOOK_HELLO_WORLD:
			text->setString("Syntax.Logic.Fun.");
			break;
		case ITEM_BOOK_HELLO_WORLD:
			text->setString("+-/*");
			break;
		default:
			text->setString("Lol! whut?");
			break;
	}   
	sf::Font *font = new sf::Font();

	if(!font->loadFromFile(FONT_STANDARD)){
		std::cout<<"Font couldn't be loaded"<<std::endl;
	}else{
		text->setFont(*font);
	}

	return text;
}

sf::Text* Item::getDescText(){
	return this->description;
}
