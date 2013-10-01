ItemHoldButtonSelect::ItemHoldButton(void){
	this->selected = false;
}

ItemHoldButtonSelect::~ItemHoldButton(void){

}

void ItemHoldButtonSelect::action(Game* game){
	this->select();
	// A little bit dirty...
	switch(game->getCurrentMenu()->getId()){
		case MENU_BOOKCASE:
			BookcaseMenu* r = reinterpret_cast<BookcaseMenu*>(currentMenu);
			std::vector<ItemHoldButtonSelect*> buttons = r->getItemHoldButtons();		// receive all buttons to switch selected buttons

			for(int i = 0; buttons.size() > i; i++){
				if(buttons[i] != this && buttons[i]->isSelected()){
					buttons[i].select();
					return;
				}
			}

			break;
		default:
			break;
	}
}

bool ItemHoldButtonSelect::isSelected(){
	return this->selected;
}

void ItemHoldButtonSelect::select(){
	this->selected = !selected;
}
