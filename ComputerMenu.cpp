#include "ComputerMenu.h"


ComputerMenu::ComputerMenu(void)
{
	this->devMenu = new DevMenu("menu_computer.png",this);
	this->addButton(new CloseButton(this,0));
}

ComputerMenu::ComputerMenu(std::string file):Menu(file,MENU_COMPUTER)
{
	this->devMenu = new DevMenu("menu_computer.png",this);
	this->buyMenu = new BuyMenu(this);
	this->addButton(new MenuButton(this->devMenu,this,"button_dev_menu.png"));
	this->addButton(new MenuButton(this->buyMenu,this,"button_buy_menu.png"));
	this->addButton(new CloseButton(this,0));

	arrangeButtons();
}


ComputerMenu::~ComputerMenu(void)
{
}

void ComputerMenu::actionBuy(){

}

void ComputerMenu::actionDev(){

}