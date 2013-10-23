/* 
 * File:   Item.h
 * Author: niels
 *
 * Created on 8. April 2013, 14:35
 */

#include "DrawAble.h"
#include "Consts.h"
#ifndef ITEM_H
#define	ITEM_H

class Item : public DrawAble{
public:
    Item();
	Item(int id);
	Item(int id,std::string toolTip);
	Item(const Item& orig);
    	virtual ~Item();
    	int getId();
	void setId(int i);
	sf::Text getToolTip();
	void setToolTip(std::string toolTip);

	int getSellPrice();
	void setSellPrice(int i);
	int getBuyPrice();
	void setBuyPrice(int i);
	bool isSellAble();
	void setSellAble(bool b);

	bool isUnique();
	bool isBook();
	sf::Text* getDescText();
private:
	int id;
	sf::Text toolTip;
	int sellPrice;
	int buyPrice;
	bool sellAble;
	bool unique;
	bool book;
	
	sf::Text* description;
	sf::Text* generateDescription();
};

#endif	/* ITEM_H */

