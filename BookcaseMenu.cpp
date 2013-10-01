#include "BookcaseMenu.h"


BookcaseMenu::BookcaseMenu(std::string file):Menu(file,MENU_BOOKCASE)
{
	CloseButton* closeButton = new CloseButton(this,0);

	closeButton->setPosition(SIZE_WINDOW_WIDTH_NORMAL  - SIZE_BUTTON_WIDTH_NORMAL*2,
		                     SIZE_WINDOW_HEIGHT_NORMAL - SIZE_BUTTON_HEIGHT_NORMAL);

	this->addButton(closeButton);

	int y = 0;
	int x = 1;
	for(int i = 1; i <= 64; i++){
		ItemHoldButton* holder = new ItemHoldButton();
		holder->setPosition(SIZE_HOLDER_BUTTON_WIDTH_NORMAL*x,
			                SIZE_HOLDER_BUTTON_HEIGHT_NORMAL*y);
		
		if(i != 0 && i%8 == 0){
			y++;
			x = 0;
		}

		this->itemButtons.push_back(holder);
		//this->addItemButton(holder);
		x++;
	}
}


BookcaseMenu::~BookcaseMenu(void){
	itemButtons.clear();
}

void BookcaseMenu::addItem(Item* item){
	for(int i=0; i < itemButtons.size();i++){
		if(itemButtons[i]->getItem() == 0){
			itemButtons[i]->setItem(item);
			return;
		}
	}
}

void BookcaseMenu::draw(sf::RenderWindow* window){
	Menu::draw(window);

	for(int i = 0; i < itemButtons.size();i++){
		window->draw(*itemButtons[i]->getSprite());

		if(itemButtons[i]->getItem() != 0){
			window->draw(*itemButtons[i]->getItem()->getSprite());
		}
	}

	window->draw(currentDescription);
}


void BookcaseMenu::setCurrentDescription(std::string desc){
	this->currentDescription.setString(desc);
}

sf::Text BookcaseMenu::getCurrentDescription(){
	return this->currentDescription;
}
