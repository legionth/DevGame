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
    Item(const Item& orig);
    virtual ~Item();
    int getId();
    void setId(int i);
private:
    int id;
};

#endif	/* ITEM_H */

