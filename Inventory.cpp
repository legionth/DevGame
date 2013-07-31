/* 
 * File:   Inventory.cpp
 * Author: niels
 * 
 * Created on 10. April 2013, 11:14
 */

#include "Inventory.h"

Inventory::Inventory():Menu("menu_inventory.png",MENU_INVENTORY) {
    setCurrentSite(0);
	this->setFrameSize(SIZE_WINDOW_WIDTH_NORMAL,SIZE_WINDOW_HEIGHT_NORMAL);
	int y = 0;
	int x = 1;
	for(int i = 1; i <= 64; i++){
		ItemHoldButton* holder = new ItemHoldButton();
		holder->setPosition(SIZE_HOLDER_BUTTON_WIDTH_NORMAL*x,
			                SIZE_HOLDER_BUTTON_HEIGHT_NORMAL*y);
		
		if(i != 0 && i%8 == 0){
			y++;
			x = 0;
		}

		this->addItemButton(holder);
		x++;
	}
}

Inventory::Inventory(const Inventory& orig) {
}

Inventory::~Inventory() {
}

void Inventory::addItem(Item* item){
	int i = 0;
	
	while(i < holderButtons.size() && holderButtons[i]->getItem() != 0){
		i++;
	}

	this->holderButtons[i]->setItem(item);
}

Item* Inventory::getItem(int pos){
	return this->holderButtons[pos]->getItem();
}

bool Inventory::hasItem(int id,int count=1){
    int it = 0;
    bool ret = false;
    
	for(int i = 0; i <= this->holderButtons.size();i++){
		if(this->holderButtons[i]->getItem()->getId() == id){
            it++;
        }
    }
    
    if(it == count){
        ret = true;
    }
    
    return ret;
}

int Inventory::getCurrentSite(){
    return this->currentSite;
}

void Inventory::setCurrentSite(int i){
    this->currentSite = i;
}

void Inventory::nextSite(){
    this->currentSite++;
}
void Inventory::previousSite(){
    this->currentSite--;
}

void Inventory::draw(sf::RenderWindow* window){
	Menu::draw(window);

	for(int i = 0; i < this->holderButtons.size(); i++){
		window->draw(*holderButtons[i]->getSprite());
	}
}

void Inventory::addItemButton(ItemHoldButton* button){
	this->holderButtons.push_back(button);
}