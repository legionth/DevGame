/* 
 * File:   Player.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:34
 */

#include "Player.h"

Player::Player() {
    setAlgorithm(0);
    setMath(0);
    setDesign(0);
    setProgramming(0);
    
    createSprite("player.png");
    setFrameSize(256,256);
    playAnimation(0,4);
	this->money = 0;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

int Player::getMath(){
    return this->math;
}

int Player::getAlgortihm(){
    return this->algorithm;
}

int Player::getProgramming(){
    return this->programming;
}

int Player::getDesign(){
    return this->design;
}

int Player::getDatabases(){
    return this->databases;
}

void Player::setMath(int i){
    this->math = i;
}

void Player::setAlgorithm(int i){
    this->algorithm = i;
}

void Player::setDesign(int i){
    this->design = i;
}

void Player::setDatabases(int i){
    this->databases = i;
}

void Player::setElectronics(int electronics) {
    this->electronics = electronics;
}

int Player::getElectronics() const {
    return electronics;
}

void Player::setProgramming(int i){
    this->programming = i;
}

void Player::move(int x, int y){
    getSprite()->move(x,y);
}

int Player::getMoney(){
	return this->money;
}

void Player::setMoney(int i){
	this->money = i;
}