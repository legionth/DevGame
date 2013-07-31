/* 
 * File:   Inventory.h
 * Author: niels
 *
 * Created on 10. April 2013, 11:14
 */

#pragma once
#include "Menu.h"
#include "Item.h"
#include "Consts.h"
#include "ItemHoldButton.h"
#ifndef INVENTORY_H
#define	INVENTORY_H

class Inventory : public Menu{
public:
    Inventory();
    Inventory(const Inventory& orig);
    virtual ~Inventory();
    void addItem(Item* item);
    Item* getItem(int pos);
    bool hasItem(int id,int count);
    void setCurrentSite(int i);
    int getCurrentSite();
    void nextSite();
    void previousSite();
	void draw(sf::RenderWindow* window);
	void addItemButton(ItemHoldButton* button);
private:
	std::vector<ItemHoldButton*> holderButtons;
    
    // currently displayed site
    int currentSite;
    // maxItems per  site
};

#endif	/* INVENTORY_H */

