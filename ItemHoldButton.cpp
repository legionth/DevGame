#include "ItemHoldButton.h"
#include "Game.h"
#include "PopUpMenu.h"

ItemHoldButton::ItemHoldButton(void)
{
	this->item = 0;
	this->popUpMenu = 0;
	this->createSprite("button_holder.png");
	setFrameSize(SIZE_HOLDER_BUTTON_WIDTH_NORMAL,SIZE_HOLDER_BUTTON_HEIGHT_NORMAL);
}


ItemHoldButton::~ItemHoldButton(void)
{
	delete this->item;
	delete this->popUpMenu;
}


bool ItemHoldButton::isFull(){
	if(this->item != 0){
		return true;
	}else{
		return false;
	}
}

void ItemHoldButton::setItem(Item* item){
	this->item = item;
}

Item* ItemHoldButton::getItem(){
	return this->item;
}

void ItemHoldButton::clearItem(){
	delete this->item;
	this->item = 0;
}

void ItemHoldButton::action(Game* game){

}