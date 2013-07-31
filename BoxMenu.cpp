#include "BoxMenu.h"


BoxMenu::BoxMenu(std::string file):Menu(file,MENU_BOX)
{
	SellButton* sellButton = new SellButton();
	CloseButton* closeButton = new CloseButton(this,0);

	closeButton->setPosition(SIZE_WINDOW_WIDTH_NORMAL  - SIZE_BUTTON_WIDTH_NORMAL*2,
		                     SIZE_WINDOW_HEIGHT_NORMAL - SIZE_BUTTON_HEIGHT_NORMAL);

	sellButton->setPosition(SIZE_WINDOW_WIDTH_NORMAL - SIZE_BUTTON_WIDTH_NORMAL,
		                    SIZE_WINDOW_HEIGHT_NORMAL - SIZE_BUTTON_HEIGHT_NORMAL);
	this->addButton(sellButton);
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

		this->addItemButton(holder);
		x++;
	}
	std::cout<<"itemHolder:"<<this->itemButtons.size()<<std::endl;
}


BoxMenu::~BoxMenu(void)
{
}


void BoxMenu::sell(Game* game){
	int money = 0;

	for(int i = 0; i < itemButtons.size(); i++){
		money = itemButtons[i]->getItem()->getSellPrice();
	}

	game->getPlayer()->setMoney(game->getPlayer()->getMoney() + money);
}

std::vector<ItemHoldButton*> BoxMenu::getItemButtons(){
	return this->itemButtons;
}

void BoxMenu::addItemButton(ItemHoldButton* button){
	this->itemButtons.push_back(button);
}

void BoxMenu::draw(sf::RenderWindow* window){
	Menu::draw(window);

	for(int i = 0; i < itemButtons.size();i++){
		window->draw(*itemButtons[i]->getSprite());
	}
}