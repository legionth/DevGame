#include "ComputerMenu.h"


ComputerMenu::ComputerMenu(void)
{
	this->devMenu = new DevMenu("menu_computer.png",this);
	this->addButton(new CloseButton(this,0));
}

ComputerMenu::ComputerMenu(std::string file):Menu(file)
{
	this->devMenu = new DevMenu("menu_computer.png",this);
	this->addButton(new CloseButton(this,0));
}


ComputerMenu::~ComputerMenu(void)
{
}

void ComputerMenu::actionBuy(){

}

void ComputerMenu::actionDev(){

}