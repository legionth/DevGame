/* 
 * File:   RoomObject.h
 * Author: niels
 *
 * Created on 8. April 2013, 14:35
 */

#include "DrawAble.h"
#include "Menu.h"
#ifndef ROOMOBJECT_H
#define	ROOMOBJECT_H

class RoomObject : public DrawAble{
public:
    RoomObject();
    RoomObject(const RoomObject& orig);
    virtual ~RoomObject();
    void use();
    void openMenu();
    void closeMenu();
private:
    Menu* menu;
};

#endif	/* ROOMOBJECT_H */

