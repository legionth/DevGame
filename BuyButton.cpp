#include "BuyButton.h"


BuyButton::BuyButton(void)
{
	this->sold = false;
}


BuyButton::~BuyButton(void)
{
}

void BuyButton::action(Game* game){
	if(!this->sold){
		Player* player = game->getPlayer();
		Item* item = this->getItem();

		if(item->getBuyPrice() <= player->getMoney()){
			player->setMoney(player->getMoney() - item->getBuyPrice());
			if(item->isUnique()){
				sold = true;
			}
		}
	}
}

bool BuyButton::isSold(){
	return this->sold;
}
