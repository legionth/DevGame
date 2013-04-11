/* 
 * File:   Game.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:34
 */

#include "Game.h"

Game::Game() {
    this->window = new sf::RenderWindow(sf::VideoMode(1024,1024),"DevGame");
    this->player = new Player();
}

Game::Game(const Game& orig) {
}

Game::~Game() {
    delete window;
}

void Game::run(){
    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
            }
        }
        
        this->draw();
    }
}

void Game::draw(){
    //player->draw(window);
}

