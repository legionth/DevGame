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
#include "MenuButton.h"
//#include "Button.h"


class CloseButton;
class MenuButton;
class Menu : public DrawAble{
public:
    Menu();
	Menu(std::string file,int id);
    Menu(const Menu& orig);
    virtual ~Menu();
    void open();
    void close();
	void actionClose();
	bool isOpen();

	void addButton(Button* button);
	std::vector<Button*> getButtons();
	void draw(sf::RenderWindow* window);
	void arrangeButtons();
	int getId();
	void setId(int id);
private:
    bool isopen;
	int id;
	std::vector<Button*> buttons;
};

#endif	/* MENU_H */

