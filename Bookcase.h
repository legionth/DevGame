#pragma once
#include "RoomObject.h"
#include "ItemHoldButton.h"
#include "Item.h"
#include "BookcaseMenu.h"

class Bookcase: public RoomObject
{
public:
	Bookcase(void);
	~Bookcase(void);
	BookcaseMenu* getBookcaseMenu();
	void setBookcaseMenu(BookcaseMenu* menu);
private:
	BookcaseMenu* menu;
};

