#include "Computer.h"


Computer::Computer(void)
{
	setId(ROOM_IDS::COMPUTER);
	createSprite("computer.png");
	setFrameSize(256,256);
	setMenu(new Menu("menu_computer.png"));
}


Computer::~Computer(void)
{
}
