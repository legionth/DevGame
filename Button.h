#include "DrawAble.h"
#pragma once
class Button: public DrawAble{
public:
	Button(void);
	~Button(void);

	virtual void action() = 0;
	void setLabel(sf::String label);
private:
	sf::String label;
};

