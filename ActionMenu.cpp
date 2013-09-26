/* 
 * File:   ActionMenu.cpp
 * Author: niels
 * 
 * Created on 10. April 2013, 09:09
 */

#include "ActionMenu.h"

ActionMenu::ActionMenu() {
}

ActionMenu::ActionMenu(const ActionMenu& orig) {
}

ActionMenu::~ActionMenu() {
}

bool ActionMenu::isShown(){
	return this->shown;
}

void ActionMenu::showMenu(bool b){
	this->shown = b;
}

void ActionMenu::action(Game* game){

}
