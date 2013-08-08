/* 
 * File:   Consts.h
 * Author: niels
 *
 * Created on 11. April 2013, 08:06
 */

#pragma once
#include <string>
#ifndef CONSTS_H
#define	CONSTS_H


const int MAX_ITEMS_INVENTORY = 10;

enum ROOM_IDS{ 
	COMPUTER  = 1,
	BOOKSHELF = 2,
	BOX       = 3
};

/*
* Frame sizes
*/

const int SIZE_WINDOW_WIDTH_NORMAL = 1024;
const int SIZE_WINDOW_HEIGHT_NORMAL = 768;

const int SIZE_BUTTON_WIDTH_NORMAL = 256;
const int SIZE_BUTTON_HEIGHT_NORMAL = 256;

const int SIZE_QUEST_BUTTON_WIDTH_NORMAL = 768;
const int SIZE_QUEST_BUTTON_HEIGHT_NORMAL = 256;

enum ATTR_IDS{
	MATH_ID			= 0,
	ALGORITHM_ID		= 1,
	PROGRAMMING_ID		= 2,
	DESIGN_ID		= 3,
	DATABASES_ID		= 4,
	ELECTRONICS_ID		= 5
};

enum QUEST_IDS{
	QUEST_HELLO_WORLD,
	QUEST_CALCULATOR

};

#endif

