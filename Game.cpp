/* 
 * File:   Game.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:34
 */

#include "Game.h"
#include "BoxMenu.h"
#include "Inventory.h"
#include "DevMenu.h"
#include "BookcaseMenu.h"
#include <sstream>

std::string Game::convertInt(int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

Game::Game() {
	this->windowWidth = SIZE_WINDOW_WIDTH_NORMAL;
	this->windowHeight = SIZE_WINDOW_HEIGHT_NORMAL;
	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth,windowHeight),"DevGame");

	this->player = new Player();
	this->player->setPosition(windowWidth/2,windowHeight/2);

	this->room = new Room();
	this->currentMenu = 0;
	this->currentActionMenu = 0;
	buttonDelay.restart();
	
	sf::Font* font = new sf::Font();
	this->moneyText = new sf::Text();

	if(!font->loadFromFile(FONT_STANDARD)){
		    std::cout<<"FAILED: loading font in Game"<<std::endl;
	}else{
		this->moneyText->setFont(*font);
		this->moneyText->setColor(sf::Color::Black);
		this->moneyText->setCharacterSize(FONT_SIZE_NORMAL);
	}
}

Game::Game(const Game& orig) {
}

Game::~Game() {
    delete window;
    delete player;
	delete room;
	delete currentMenu;
	delete currentQuest;
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
		    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && buttonDelay.getElapsedTime().asSeconds() > 0.25){
		    //	Inventory* inv = this->player->getInventory();
		            if(this->currentMenu != 0 && this->currentMenu->getId() == MENU_INVENTORY){
		                    currentMenu->close();
		                    currentMenu = 0;
		                    buttonDelay.restart();
		            }
		            else{
							setCurrentMenu((Menu*)this->player->getInventory());
		                    buttonDelay.restart();
		            }
		    }
		    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
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
						   
							   if(obj->getMenu() != 0){
									obj->openMenu();
							   }

							   currentMenu = obj->getMenu();
							   buttonDelay.restart();							
						}
					}
			}else if(buttonDelay.getElapsedTime().asSeconds() > 0.25f){     // Button actions
				executeAction(xArgument,yArgument);
				if(currentMenu != 0 && currentMenu->getId() == MENU_DEV){
					executeQuestAction(xArgument,yArgument);
				}
				else if(currentMenu != 0 && currentMenu->getId() == MENU_BUY){
					executeBuyAction(xArgument,yArgument);
				}
			}
		 }
		 else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
		    int xArgument = sf::Mouse::getPosition(*window).x;
		    int yArgument = sf::Mouse::getPosition(*window).y;

		 	if(currentMenu != 0 && buttonDelay.getElapsedTime().asSeconds() > 0.25f){     // Button actions
				int size = currentMenu->getButtons().size();
				Menu* tmpMenu = currentMenu;

				for(int i=0; i < size; i++){
					Button* obj = currentMenu->getButtons()[i];
					if(obj->getActionMenu() != 0){
						if(obj->getXPosition()					  < xArgument &&
						   obj->getYPosition()					  < yArgument &&
						   obj->getXPosition() + obj->getWidth()  > xArgument &&
						   obj->getYPosition() + obj->getHeight() > yArgument){
							   obj->openActionMenu(this);
							   lastMousePositionX = xArgument;
							   lastMousePositionY = yArgument;

						}
					}
				}
			}else{
				this->currentActionMenu = 0;
			}
	 	}
	}//end while
	if(window->isOpen()){
		window->clear();
		this->draw();
		window->display();
	}
    }
}

void Game::draw(){
    room->draw(window);
    player->draw(window);
	int countRoomObjects = room->getRoomObjects().size();
	
	if(currentMenu != 0){                         //Dran denken #includen der *.h Dateien
		if(currentMenu->getId() == MENU_BOX){
			BoxMenu* r = reinterpret_cast<BoxMenu*>(currentMenu);
			r->draw(window);
		}
		else if(currentMenu->getId() == MENU_INVENTORY){
			Inventory* r = reinterpret_cast<Inventory*>(currentMenu);
			r->draw(window);
		}
		else if(currentMenu->getId() == MENU_BUY){
			BuyMenu* r = reinterpret_cast<BuyMenu*>(currentMenu);
			r->draw(window);
		}
		else if(currentMenu->getId() == MENU_DEV){
			DevMenu* r = reinterpret_cast<DevMenu*>(currentMenu);
			r->draw(window);
		}
		else if(currentMenu->getId() == MENU_BOOKCASE){
			BookcaseMenu* r = reinterpret_cast<BookcaseMenu*>(currentMenu);
			r->draw(window);
		}
		else{
			currentMenu->draw(window);
		}
	}

	this->getMoneyText()->setPosition(20,20);
	this->getMoneyText()->setString(convertInt(player->getMoney()) + " $");

	window->draw(*this->getMoneyText());

	if(currentActionMenu != 0){
		this->currentActionMenu->draw(window,lastMousePositionX,lastMousePositionY);
	}
}

void Game::init(){
	Computer *computer = new Computer();
	Box *box = new Box();
	Bookcase* bookcase = new Bookcase();

	computer->setPosition(this->windowWidth/2 - computer->getWidth()/2,0);
	bookcase->setPosition(this->windowWidth/2 - bookcase->getWidth()/2 + 256 + 8,0);
	box->setPosition(this->windowWidth - box->getWidth(),this->windowHeight/2);

	room->addRoomObject(computer);
	room->addRoomObject(box);
	room->addRoomObject(bookcase);

	this->box = box;
	this->currentBookCase = bookcase;
}

void Game::setCurrentMenu(Menu* menu){
	this->currentMenu = menu;
}

Player* Game::getPlayer(){
	return this->player;
}

Box* Game::getBox(){
	return this->box;
}

void Game::setCurrentActiontMenu(ActionMenu* menu){
	this->currentActionMenu = menu;
}

void Game::setCurrentQuest(Quest* quest){
	this->currentQuest = quest;
}

Quest* Game::getCurrentQuest(){
	return this->currentQuest;
}

Menu* Game::getCurrentMenu(){
	return this->currentMenu;
}


void Game::executeAction(int xArgument, int yArgument){
		int size = currentMenu->getButtons().size();
		Menu* tmpMenu = currentMenu;
		std::cout<<"size="<<size<<std::endl;
		for(int i=0; i < size; i++){
			Button* obj = currentMenu->getButtons()[i];			// @TODO das isnd nur buttons

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

void Game::executeQuestAction(int xArgument, int yArgument){
		int size = reinterpret_cast<DevMenu*>(currentMenu)->getQuests().size();
		DevMenu* tmpMenu = reinterpret_cast<DevMenu*>(currentMenu);
		
		std::cout<<"size="<<size<<std::endl;
		for(int i=0; i < size; i++){
			Quest* obj = reinterpret_cast<DevMenu*>(currentMenu)->getQuests()[i];			// @TODO das isnd nur buttons

			if(obj->getXPosition()					  < xArgument &&
				obj->getYPosition()					  < yArgument &&
				obj->getXPosition() + obj->getWidth()  > xArgument &&
				obj->getYPosition() + obj->getHeight() > yArgument){
					obj->action(this);
					buttonDelay.restart();

					if(currentMenu == 0 || tmpMenu != reinterpret_cast<DevMenu*>(currentMenu)){
						break;
					}
			}
		}
}

void Game::executeBuyAction(int xArgument, int yArgument){
		int size = reinterpret_cast<BuyMenu*>(currentMenu)->getBuyButtons().size();
		BuyMenu* tmpMenu = reinterpret_cast<BuyMenu*>(currentMenu);
		std::cout<<"size="<<size<<std::endl;
		for(int i=0; i < size; i++){
			BuyButton* obj = reinterpret_cast<BuyMenu*>(currentMenu)->getBuyButtons()[i];			// @TODO das isnd nur buttons

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

Bookcase* Game::getCurrentBookcase(){
	return this->currentBookCase;
}

sf::Text* Game::getMoneyText(){
	return this->moneyText;
}