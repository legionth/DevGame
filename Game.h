/* 
 * File:   Game.h
 * Author: niels
 *
 * Created on 8. April 2013, 14:34
 */
#ifdef _WIN32
	#include "SFML\Graphics.hpp"
#else
	#include "SFML/Graphics.hpp"
#endif

#pragma once
#include "Player.h"
#include "Room.h"
#include "Computer.h"
#include "Box.h"
#include "Consts.h"
#include "ActionMenu.h"
#include "Quest.h"

#ifndef GAME_H
#define	GAME_H

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    void run();
   	void draw();
	void init();
	void setCurrentMenu(Menu* menu);
	void setCurrentActiontMenu(ActionMenu* menu);
	void setCurrentQuest(Quest* quest);
	Quest* getCurrentQuest();
	Box* getBox();

	Player* getPlayer();
private:
	sf::RenderWindow* window;
	Player* player;
	Room* room;
	int windowWidth;
    int windowHeight;
	Menu* currentMenu;
	ActionMenu* currentActionMenu;
	sf::Clock buttonDelay;
	Box* box;
	Quest* currentQuest;
};

#endif	/* GAME_H */

