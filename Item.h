/* 
 * File:   Item.h
 * Author: niels
 *
 * Created on 8. April 2013, 14:35
 */

#include "DrawAble.h"
#ifndef ITEM_H
#define	ITEM_H

class Item : public DrawAble{
public:
    Item();
	Item(int id);
	Item(int id,std::string toolTip);
    Item(const Item& orig);
    virtual ~Item();
    int getId();
    void setId(int i);
	sf::Text getToolTip();
	void setToolTip(std::string toolTip);
private:
    int id;
	sf::Text toolTip;
};

#endif	/* ITEM_H */

