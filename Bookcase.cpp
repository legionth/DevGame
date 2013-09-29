#include "Bookcase.h"


Bookcase::Bookcase(void)
{
	this->setId(BOOKCASE);
	this->createSprite("bookcase.png");
	setFrameSize(256,256);
	setBookcaseMenu(new BookcaseMenu("menu_bookcase.png"));
}


Bookcase::~Bookcase(void)
{
	delete this->menu;
}


BookcaseMenu* Bookcase::getBookcaseMenu(){
	return this->menu;
}

void Bookcase::setBookcaseMenu(BookcaseMenu* menu){
	this->menu = menu;
	setMenu(menu);
}
