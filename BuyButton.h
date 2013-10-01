#pragma once
#include "Button.h"

/**
*	Aktion fuer das BuyMenu
**/
class BuyButton : public Button
{
public:
	BuyButton(void);
	~BuyButton(void);
	void action(Game* game);
	bool isSold();
private:
	bool sold;

};

