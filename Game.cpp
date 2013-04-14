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
				event.mouseButton.x;
				event.mouseButton.y;
                float xArgument = sf::Mouse::getPosition().x;
                float yArgument = sf::Mouse::getPosition().y;

                yArgument = event.mouseButton.y - player->getSprite()->getPosition().y;
                xArgument = event.mouseButton.x - player->getSprite()->getPosition().x;
                

                // std::cout<< event.mouseButton.y<<std::endl;
				player->getSprite()->setPosition(xArgument,yArgument);

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

