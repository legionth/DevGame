#pragma once
#include "ItemHoldButton.h"

/**
*	Aktion fuer das BuyMenu
**/
class BuyButton : public ItemHoldButton
{
public:
	BuyButton(void);
	~BuyButton(void);
	void action(Game* game);
	bool isSold();
private:
	bool sold;

};

