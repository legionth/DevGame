/* 
 * File:   DrawAble.h
 * Author: niels
 *
 * Created on 8. April 2013, 14:35
 */

#include <iostream>

#ifdef _WIN32
	#include <SFML\Graphics.hpp>
#else
	#include <SFML/Graphics.hpp>
#endif

#ifndef DRAWABLE_H
#define	DRAWABLE_H

class DrawAble {
public:
    DrawAble();
    DrawAble(const DrawAble& orig);
    virtual ~DrawAble();
    //Simple Drawings
    void draw(sf::RenderWindow* window);
    
    void createSprite(std::string file);
    sf::Sprite* getSprite();

    void setCurrentFrame(int i);
    void setAnimationFrames(int start, int stop);
    int getCurrentFrame();
    void setPosition(int x,int y);
    
    void setXPosition(int x);
    void setYPosition(int y);
    int getXPosition();
    int getYPosition();
    //Animation Settings

    bool isPlaying();
    void playAnimation(int start, int stop);
    void stopAnimation();
    void updateAnimation();
    
    void setStartFrame(int i);
    void setStopFrame(int i);
    int getStartFrame();
    int getStopFrame();
    
    void setFrameSize(int width, int height);
    int getFrameHeight();
    int getFrameWidth();
    
    sf::IntRect getFrameRect(int frame);
    void setFrameRect(int frame);
    
    int getFPS();
    void setFPS(int i);
private:
    sf::Sprite* sprite;
    int xPos;
    int yPos;
    // Animation Attributes
    int currentFrame;
    int startFrame;
    int stopFrame;
    
    bool playing;
    
    int width;
    int height;
    sf::Clock clock;
    int fps;
};

#endif	/* DRAWABLE_H */

