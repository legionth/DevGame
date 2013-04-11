/* 
 * File:   Room.h
 * Author: niels
 *
 * Created on 8. April 2013, 14:35
 */
#include "RoomObject.h"
#ifndef ROOM_H
#define	ROOM_H

class Room {
public:
    Room();
    Room(const Room& orig);
    virtual ~Room();
    void addRoomObject(RoomObject* roomObject);
    std::vector<RoomObject*> getRoomObjects() const;
    
    void draw(sf::RenderWindow* window);
private:
    std::vector<RoomObject*> roomObjects;
};

#endif	/* ROOM_H */

