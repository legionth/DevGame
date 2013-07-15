#include "Box.h"


Box::Box(void)
{
	setId(ROOM_IDS::BOX);
	createSprite("box.png");
	setFrameSize(64,64);
	setMenu(0);
}


Box::~Box(void)
{
}
