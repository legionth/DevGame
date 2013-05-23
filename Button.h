#include "DrawAble.h"
#pragma once

class Game;
class Button: public DrawAble{
public:
	Button(void);
	~Button(void);

	virtual void action(Game* game) = 0;
	void setLabel(sf::String label);
private:
	sf::String label;
};

