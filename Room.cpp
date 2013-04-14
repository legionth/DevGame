/* 
 * File:   Room.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:35
 */

#include <vector>

#include "Room.h"

Room::Room() {
    this->createSprite("room.png");
}

Room::Room(const Room& orig) {
}

Room::~Room() {
    for(int i = 0; i < roomObjects.size(); i++){
        delete roomObjects[i];
    }
}

void Room::addRoomObject(RoomObject* roomObject) {
    this->roomObjects.push_back(roomObject);
}

std::vector<RoomObject*> Room::getRoomObjects() const {
    return roomObjects;
}

void Room::draw(sf::RenderWindow* window){
    DrawAble::draw(window);
    for(int i = 0; i < roomObjects.size(); i++){
        roomObjects[i]->draw(window);
    }
}
