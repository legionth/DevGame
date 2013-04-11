/* 
 * File:   Menu.h
 * Author: niels
 *
 * Created on 8. April 2013, 14:35
 */

#include "DrawAble.h"
#ifndef MENU_H
#define	MENU_H

class Menu : public DrawAble{
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
    void open();
    void close();
    bool isOpen();
private:
    bool isopen;
};

#endif	/* MENU_H */

