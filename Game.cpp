/* 
 * File:   Game.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:34
 */

#include "Game.h"

Game::Game() {
    this->windowWidth = 1024;
    this->windowHeight = 768;
    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth,windowHeight),"DevGame");
    
    this->player = new Player();
    this->player->setPosition(windowWidth/2,windowHeight/2);
    
    this->room = new Room();
}

Game::Game(const Game& orig) {
}

Game::~Game() {
    delete window;
    delete player;
}

void Game::run(){
    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                int xArgument = 0;
                int yArgument = 0;

                yArgument = sf::Mouse::getPosition().y - player->getSprite()->getPosition().y;
                xArgument = sf::Mouse::getPosition().x - player->getSprite()->getPosition().x;
                

                // std::cout<< event.mouseButton.y<<std::endl;
                player->move(xArgument,yArgument);

               // std::cout<< sf::Mouse::getPosition().x<<std::endl;
                //std::cout<< sf::Mouse::getPosition().y<<std::endl;
            }
        }
        window->clear();
        this->draw();
        window->display();
    }
}

void Game::draw(){
    room->draw(window);
    player->draw(window);
}

