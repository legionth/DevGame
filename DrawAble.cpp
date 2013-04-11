/* 
 * File:   DrawAble.cpp
 * Author: niels
 * 
 * Created on 8. April 2013, 14:35
 */

#include "DrawAble.h"

DrawAble::DrawAble() {
}

DrawAble::DrawAble(const DrawAble& orig) {
}

DrawAble::~DrawAble() {
}

void DrawAble::draw(sf::RenderWindow* window){
    window->draw(*sprite);
}

void DrawAble::createSprite(std::string file){
    sf::Texture img;
    if(img.loadFromFile(file)){
        std::cout<<"File:"<<file<<"not found!"<<std::endl;
        return;
    }
    this->sprite = new sf::Sprite(img);
}

sf::Sprite* DrawAble::getSprite(){
    return this->sprite;
}

void DrawAble::setCurrentFrame(int i){
    this->currentFrame = i;
}

void DrawAble::setAnimationFrames(int start, int stop){
    this->startFrame = start;
    this->stopFrame = stop;
}

int DrawAble::getCurrentFrame(){
    this->currentFrame;
}

bool DrawAble::isPlaying(){
    return this->playing;
}

void DrawAble::playAnimation(int start, int stop){
    this->playing = true;
    setCurrentFrame(start);
    setAnimationFrames(start,stop);
}

void DrawAble::stopAnimation(){
    this->playing = false;
}

void DrawAble::setStartFrame(int i){
    this->startFrame = i;
}

void DrawAble::setStopFrame(int i){
    this->stopFrame = i;
}

int DrawAble::getStartFrame(){
    return this->startFrame;
}

int DrawAble::getStopFrame(){
    return this->stopFrame;
}
/**
 *      Update the Animation per Rect
 */
void DrawAble::updateAnimation(){
    if(isPlaying()){
        int frameCount = getStopFrame() - getStartFrame();
        float timePosition = (clock.getElapsedTime().asSeconds() * fps);
                
        setCurrentFrame(getStartFrame() + (int)timePosition % frameCount);
        getSprite()->setTextureRect(getFrameRect(this->getCurrentFrame()));
        
        if(getCurrentFrame() == getStopFrame()){
            stopAnimation();
        }
        //std::cout<<"updateAnimation"<<getFrameWidth()<<"bla"<<getFrameHeight()<<std::endl;
    }
    else{
        setFrameRect(getCurrentFrame());
    }
}

void DrawAble::setFrameRect(int frame){
    setCurrentFrame(frame);
    getSprite()->setTextureRect(getFrameRect(frame));
}
/**
 * Cut an frame of the Texture by height and width of the Texture
 * @param frame
 * @return cutted FrameRect from Texture 
 */
sf::IntRect DrawAble::getFrameRect(int frame){
    unsigned int width = (getSprite()->getTexture()->getSize().x / getFrameWidth());
    unsigned int height = (getSprite()->getTexture()->getSize().y / getFrameHeight());

    int tileX = frame % width;
    int tileY = frame / width;
    
    sf::IntRect rect(tileX*getFrameWidth(),
        tileY*getFrameHeight(),
                     getFrameWidth(),
                     getFrameHeight()); // describes now the length and heigth not the end point see SFML docu
    
    return rect;
}

void DrawAble::setFrameSize(int width, int height){
    this->height = height;
    this->width = width;
}

int DrawAble::getFrameHeight(){
    return this->height;
}

int DrawAble::getFrameWidth(){
    return this->width;
}

int DrawAble::getFPS(){
    return this->fps;
}

void DrawAble::setFPS(int i){
    this->fps = i;
}

void DrawAble::setXPosition(int x){
    this->xPos = x;
}

void DrawAble::setYPosition(int y){
    this->yPos = y;
}

int DrawAble::getXPosition(){
    return this->xPos;
}

int DrawAble::getYPosition(){
    return this->yPos;
}

void DrawAble::setPosition(int x, int y){
    this->xPos = x;
    this->yPos = y;
}