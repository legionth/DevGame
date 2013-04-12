/* 
 * File:   Game.h
 * Author: niels
 *
 * Created on 8. April 2013, 14:34
 */

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Room.h"
#ifndef GAME_H
#define	GAME_H

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    void run();
    void draw();
private:
    sf::RenderWindow* window;
    Player* player;
    Room* room;
    int windowWidth;
    int windowHeight;
};

#endif	/* GAME_H */

