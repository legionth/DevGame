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

#include "Player.h"
#include "Room.h"
#include "Computer.h"
#include "Consts.h"

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
private:
    sf::RenderWindow* window;
    Player* player;
    Room* room;
    int windowWidth;
    int windowHeight;
};

#endif	/* GAME_H */

