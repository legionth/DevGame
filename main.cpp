/* 
 * File:   main.cpp
 * Author: niels
 *
 * Created on 8. April 2013, 14:28
 */

//#include <cstdlib>
#include "Game.h"
using namespace std;

/*
 * 
 */
int main() {
    Game* game = new Game();
    game->run();
    delete game;
	return 0;
}

