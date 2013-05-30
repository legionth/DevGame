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

const enum ROOM_IDS{ 
	COMPUTER = 1,
	BOOKSHELF = 2
};

/*
* Frame sizes
*/

const int SIZE_WINDOW_WIDTH_NORMAL = 1024;
const int SIZE_WINDOW_HEIGHT_NORMAL = 768;

const int SIZE_BUTTON_WIDTH_NORMAL = 256;
const int SIZE_BUTTON_HEIGHT_NORMAL = 256;

const enum ATTR_IDS{
	MATH_ID			= 0,
	ALGORITHM_ID	= 1,
	PROGRAMMING		= 2,
	DESIGN			= 3,
	DATABASES		= 4,
	ELECTRONICS		= 5
};

#endif