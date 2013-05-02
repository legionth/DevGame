/* 
 * File:   Menu.h
 * Author: niels
 *
 * Created on 8. April 2013, 14:35
 */

#include "DrawAble.h"
#include "Player.h"
#include "Consts.h"

#ifndef MENU_H
#define	MENU_H
#pragma once
#include "CloseButton.h"
//#include "Button.h"


class CloseButton;
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

	void addButton(Button* button);
	std::vector<Button*> getButtons();
private:
    bool isopen;

	std::vector<Button*> buttons;
};

#endif	/* MENU_H */

