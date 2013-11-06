#include "ItemHoldButton_Select.h"
#include "BookcaseMenu.h"
#include "Game.h"

ItemHoldButtonSelect::ItemHoldButtonSelect(void){
	this->selected = false;
}

ItemHoldButtonSelect::~ItemHoldButtonSelect(void){

}

void ItemHoldButtonSelect::action(Game* game){
	this->select();
	// A little bit dirty...
}

bool ItemHoldButtonSelect::isSelected(){
	return this->selected;
}

void ItemHoldButtonSelect::select(){
	this->selected = !selected;
}
