#include "Box.h"

Box::Box(void)
{
	setId(3);
	createSprite("box.png");
	setFrameSize(64,64);
	setMenu(0);
}


Box::~Box(void)
{
}
