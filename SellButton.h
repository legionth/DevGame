#pragma once

#include "Button.h"
#include "Item.h"
#include "Player.h"
#include "Game.h"

class SellButton : public Button 
{
public:
	SellButton(void);
	~SellButton(void);
	void action(Game* game);
private:

};

