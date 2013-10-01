/* 
 * File:   Player.h
 * Author: niels
 *
 * Created on 8. April 2013, 14:34
 */

#ifndef PLAYER_H
#define	PLAYER_H
#pragma once 
#include "DrawAble.h"
#include "Room.h"
#include <SFML/Graphics.hpp>

class Inventory;
class Player : public DrawAble{
public:
	Player();
	Player(const Player& orig);
	virtual ~Player();

	int getMath();
	int getAlgortihm();
	int getProgramming();
	int getDesign();
	int getDatabases();
	int getElectronics() const;

	void setMath(int i);
	void setAlgorithm(int i);
	void setProgramming(int i);
	void setDesign(int i);
	void setDatabases(int i);
	void setElectronics(int electronics);

	void move(int x, int y);
	int getMoney();
	void setMoney(int i);
	Inventory* getInventory();
	void setInventory(Inventory* inventory);
private:
	int math;
	int algorithm;
	int programming;
	int design;
	int databases;
	int electronics;

	int money;
	Inventory* inventory;    
};

#endif	/* PLAYER_H */

