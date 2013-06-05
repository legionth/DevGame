/* 
 * File:   Game.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:34
 */

#include "Game.h"

Game::Game() {
	this->windowWidth = SIZE_WINDOW_WIDTH_NORMAL;
    this->windowHeight = SIZE_WINDOW_HEIGHT_NORMAL;
    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth,windowHeight),"DevGame");
    
    this->player = new Player();
    this->player->setPosition(windowWidth/2,windowHeight/2);
    
    this->room = new Room();
	this->currentMenu = 0;
	buttonDelay.restart();

}

Game::Game(const Game& orig) {
}

Game::~Game() {
    delete window;
    delete player;
}

void Game::run(){
    init();
	while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
				return;
            }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				event.mouseButton.x;
				event.mouseButton.y;
                int xArgument = sf::Mouse::getPosition(*window).x;
                int yArgument = sf::Mouse::getPosition(*window).y;
				
				if(currentMenu == 0 && buttonDelay.getElapsedTime().asSeconds() > 0.25){
					player->getSprite()->setPosition(xArgument,yArgument);
			
					int countRoomObjects = room->getRoomObjects().size();
					for(int i = 0; i < countRoomObjects; i++){
						RoomObject* obj = room->getRoomObjects()[i];

						if(obj->getXPosition()					  < xArgument &&
						   obj->getYPosition()					  < yArgument &&
						   obj->getXPosition() + obj->getWidth()  > xArgument &&
						   obj->getYPosition() + obj->getHeight() > yArgument){

							   obj->openMenu();
							   currentMenu = obj->getMenu();
							   buttonDelay.restart();							
						}
					}
				}else if(buttonDelay.getElapsedTime().asSeconds() > 0.25f){     // Button actions
					int size = currentMenu->getButtons().size();
					Menu* tmpMenu = currentMenu;
					for(int i=0; i < size; i++){
						Button* obj = currentMenu->getButtons()[i];

						if(obj->getXPosition()					  < xArgument &&
						   obj->getYPosition()					  < yArgument &&
						   obj->getXPosition() + obj->getWidth()  > xArgument &&
						   obj->getYPosition() + obj->getHeight() > yArgument){
							   obj->action(this);
							   buttonDelay.restart();
							   if(currentMenu == 0 || tmpMenu != currentMenu){
									break;
							   }
						}
					}

				}
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
	int countRoomObjects = room->getRoomObjects().size();
	
		if(currentMenu){
			currentMenu->draw(window);
		}
}

void Game::init(){
	Computer *computer = new Computer();
	computer->setPosition(this->windowWidth/2 - computer->getWidth()/2,0);
	room->addRoomObject(computer);
}

void Game::setCurrentMenu(Menu* menu){
	this->currentMenu = menu;
}

Player* Game::getPlayer(){
	return this->player;
}
