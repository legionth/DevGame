/* 
 * File:   Menu.h
 * Author: niels
 *
 * Created on 8. April 2013, 14:35
 */

#include "DrawAble.h"
#include "Player.h"

#ifndef MENU_H
#define	MENU_H

class Menu : public DrawAble{
public:
    Menu();
	Menu(std::string file);
    Menu(const Menu& orig);
    virtual ~Menu();
    void open();
    void close();
	void actionClose();
	bool isOpen();
private:
    bool isopen;
};

#endif	/* MENU_H */

