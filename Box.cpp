#include "Box.h"
#include "BoxMenu.h"


Box::Box(void)
{
	setId(ROOM_IDS::BOX);
	createSprite("box.png");
	setFrameSize(64,64);
	setMenu(new BoxMenu("menu_box.png"));
}


Box::~Box(void)
{
	delete this->boxMenu;
}


BoxMenu* Box::getBoxMenu(){
	return this->boxMenu;
}
	
void Box::setBoxMenu(BoxMenu* menu){
	this->boxMenu = menu;
}