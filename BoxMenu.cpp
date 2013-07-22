#include "BoxMenu.h"


BoxMenu::BoxMenu(std::string file):Menu(file)
{
	SellButton* sellButton = new SellButton();
	CloseButton* closeButton = new CloseButton();

	this->addButton(sellButton);
	this->addButton(closeButton);

	for(int i = 0; i < 16; i++){
		ItemHoldButton* holder = new ItemHoldButton();
		holder->setPosition(SIZE_HOLDER_BUTTON_WIDTH_NORMAL*i,SIZE_HOLDER_BUTTON_HEIGHT_NORMAL*i);
		this->addButton(holder);
	}
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