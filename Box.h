#pragma once
#include "roomobject.h"

class BoxMenu;
class Box :
	public RoomObject
{
public:
	Box(void);
	~Box(void);
	BoxMenu* getBoxMenu();
	void setBoxMenu(BoxMenu* menu);
private:
	BoxMenu* boxMenu;
};

