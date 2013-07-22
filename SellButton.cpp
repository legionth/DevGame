#include "SellButton.h"
#include "BoxMenu.h"

SellButton::SellButton(void)
{
}


SellButton::~SellButton(void)
{
}

void SellButton::action(Game* game){
	Player* pl = game->getPlayer();
	Box* box = game->getBox();
	int money = 0;

	for(int i = 0; i < box->getBoxMenu()->getItemButtons().size(); i++){
		money += box->getBoxMenu()->getItemButtons()[i]->getItem()->getSellPrice();
	}
	
	pl->setMoney(pl->getMoney() + money);
	
}
