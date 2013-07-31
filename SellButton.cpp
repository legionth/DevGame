#include "SellButton.h"
#include "BoxMenu.h"

SellButton::SellButton(void)
{
	this->createSprite("button_sell.png");
	this->setFrameSize(SIZE_BUTTON_WIDTH_NORMAL,SIZE_BUTTON_HEIGHT_NORMAL);
}


SellButton::~SellButton(void)
{
}

void SellButton::action(Game* game){
	Player* pl = game->getPlayer();
	Box* box = game->getBox();
	int money = 0;
	
	//std::cout<<box->getBoxMenu()->getItemButtons()<<std::endl;

	for(int i = 0; i < box->getBoxMenu()->getItemButtons().size(); i++){
		if(box->getBoxMenu()->getItemButtons()[i] != 0 && box->getBoxMenu()->getItemButtons()[i]->getItem() != 0){
			money += box->getBoxMenu()->getItemButtons()[i]->getItem()->getSellPrice();
			box->getBoxMenu()->getItemButtons()[i]->clearItem();
		}
	}
	pl->setMoney(pl->getMoney() + money);
	
}
