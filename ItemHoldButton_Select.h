#pragma once
#include "ItemHoldButton.h"

/**
* Special ItemHoldButton to select from a menu
* special action behavior
**/
class ItemHoldButtonSelect : public ItemHoldButton
{
public:
	ItemHoldButton(void);
	~ItemHoldButton(void);
	void action(Game* game);
	bool isSelected();
	void select();
private:
	bool selected;
};

