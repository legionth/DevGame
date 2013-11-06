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
	COMPUTER = 1,
	BOOKCASE = 2,
	BOX = 3
};

/*
* Frame sizes
*/

const int SIZE_WINDOW_WIDTH_NORMAL			= 1024;
const int SIZE_WINDOW_HEIGHT_NORMAL			= 768;

const int SIZE_BUTTON_WIDTH_NORMAL			= 256;
const int SIZE_BUTTON_HEIGHT_NORMAL			= 256;

const int SIZE_QUEST_BUTTON_WIDTH_NORMAL		= 768;
const int SIZE_QUEST_BUTTON_HEIGHT_NORMAL		= 256;

const int SIZE_HOLDER_BUTTON_WIDTH_NORMAL		= 64;
const int SIZE_HOLDER_BUTTON_HEIGHT_NORMAL		= 64;

const int SIZE_ITEM_WIDTH_NORMAL			= 32;
const int SIZE_ITEM_HEIGHT_NORMAL			= 32;

const int SIZE_ACTION_MENU_HEIGHT_NORMAL		= 32;
const int SIZE_ACTION_MENU_WIDTH_NORMAL			= 256;

const int FONT_SIZE_VERY_SMALL				= 8;
const int FONT_SIZE_SMALL				= 12;
const int FONT_SIZE_NORMAL				= 16;

const int SIZE_CURRENT_QUEST_WIDTH_NORMAL		= 128;
const int SIZE_CURRENT_QUEST_HEIGHT_NORMAL		= 256;

enum ATTR_IDS{
	MATH_ID				= 0,
	ALGORITHM_ID		= 1,
	PROGRAMMING_ID		= 2,
	DESIGN_ID			= 3,
	DATABASES_ID		= 4,
	ELECTRONICS_ID		= 5
};

enum QUEST_IDS{
	QUEST_HELLO_WORLD = 0,
	QUEST_CALCULATOR = 1

};

enum MENU_IDS{
	MENU_COMPUTER,
	MENU_DEV,
	MENU_BUY,
	MENU_BOX,
	MENU_INVENTORY,
	MENU_BOOKCASE
};

enum ITEM_IDS{
	ITEM_BOOK_HELLO_WORLD,
	ITEM_BOOK_CALCULATOR,
	ITEM_HELLO_WORLD,
	ITEM_CALCULATOR
};


const std::string FONT_STANDARD = "DIGITALDREAM.TTF";//"arial.ttf";

#endif

