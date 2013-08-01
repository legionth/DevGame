#include "BuyMenu.h"

BuyMenu::BuyMenu(Menu* prevMenu):Menu("menu_buy.png",MENU_BUY)
{
	int y = 0;
	int x = 1;
	for(int i = 1; i <= 2; i++){
		ItemHoldButton* holder = new ItemHoldButton();
		holder->setPosition(SIZE_HOLDER_BUTTON_WIDTH_NORMAL,
			                SIZE_HOLDER_BUTTON_HEIGHT_NORMAL*i);
		
		Item* item = new Item(i-1);
		item->setPosition(SIZE_HOLDER_BUTTON_WIDTH_NORMAL + SIZE_HOLDER_BUTTON_WIDTH_NORMAL/4,
			              SIZE_HOLDER_BUTTON_HEIGHT_NORMAL*i + SIZE_HOLDER_BUTTON_HEIGHT_NORMAL/4);
		
		holder->setItem(item);

		this->itemHolderButtons.push_back(holder);
	}

	CloseButton* closeButton = new CloseButton(this,prevMenu);

	closeButton->setPosition(SIZE_WINDOW_WIDTH_NORMAL  - SIZE_BUTTON_WIDTH_NORMAL*2,
		                     SIZE_WINDOW_HEIGHT_NORMAL - SIZE_BUTTON_HEIGHT_NORMAL);

	this->addButton(closeButton);
}


BuyMenu::~BuyMenu(void)
{
	itemHolderButtons.clear();
}

void BuyMenu::draw(sf::RenderWindow* window){
	Menu::draw(window);
	for(int i = 0; i < itemHolderButtons.size(); i++){
		window->draw(*itemHolderButtons[i]->getSprite());
		window->draw(*itemHolderButtons[i]->getItem()->getSprite());
	}
}
