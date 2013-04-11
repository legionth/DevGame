/* 
 * File:   Inventory.cpp
 * Author: niels
 * 
 * Created on 10. April 2013, 11:14
 */

#include "Inventory.h"

Inventory::Inventory() {
    setCurrentSite(0);
}

Inventory::Inventory(const Inventory& orig) {
}

Inventory::~Inventory() {
}

void Inventory::addItem(Item* item){
    this->items.push_back(item);
}

Item* Inventory::getItem(int pos){
    return this->items[pos];
}

bool Inventory::hasItem(int id,int count=1){
    int it = 0;
    bool ret = false;
    
    for(int i = 0; i <= this->items.size();i++){
        if(this->items[i]->getId() == id){
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