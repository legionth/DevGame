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

Item::~Item() {
}

int Item::getId(){
    return this->id;
}

void Item::setId(int i){
    this->id = i;
}

