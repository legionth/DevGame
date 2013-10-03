#include "BuyButton.h"
#include "Game.h"

BuyButton::BuyButton(void)
{
	this->sold = false;
	setIsBuyButton(true);
}


BuyButton::~BuyButton(void)
{
}

void BuyButton::action(Game* game){
	std::cout<<"Action buybutton"<<std::endl;
	if(!this->sold){
		Player* player = game->getPlayer();
		Item* item = this->getItem();

		if(item->getBuyPrice() <= player->getMoney()){
			player->setMoney(player->getMoney() - item->getBuyPrice());
			
			if(item->isUnique()){
				sold = true;
			}
			
			if(item->isBook()){
				game->getCurrentBookcase()->getBookcaseMenu()->addItem(item);
			}
		}
	}
}

bool BuyButton::isSold(){
	return this->sold;
}
