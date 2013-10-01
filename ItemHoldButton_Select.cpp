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
	if(game->getCurrentMenu()->getId() == MENU_BOOKCASE){
			BookcaseMenu* r = reinterpret_cast<BookcaseMenu*>(game->getCurrentMenu());
			std::vector<ItemHoldButtonSelect*> buttons = r->getItemHoldButtons();		// receive all buttons to switch selected buttons

			for(int i = 0; buttons.size() > i; i++){
				if(buttons[i] != this && buttons[i]->isSelected()){
					buttons[i]->select();
					return;
				}
			}
	}
}

bool ItemHoldButtonSelect::isSelected(){
	return this->selected;
}

void ItemHoldButtonSelect::select(){
	this->selected = !selected;
}
