#include "Computer.h"


Computer::Computer(void)
{
	setId(1);
	createSprite("computer.png");
	setFrameSize(256,256);
	setMenu(new ComputerMenu("menu_computer.png"));
}


Computer::~Computer(void)
{
}
