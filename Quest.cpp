#include "Quest.h"


Quest::Quest(int id,Item* item,std::map<int,int> need, std::map<int,int> exp, int money,int x ,int y)
{
	this->need = need;
	this->exp = exp;
	this->questName = new sf::Text();
	this->description = new sf::Text();
	this->item = item;
	this->id = id;
	this->completed = false;
	this->money = money;
	this->createSprite("button_quest.png");
	this->setFrameSize(SIZE_QUEST_BUTTON_WIDTH_NORMAL,SIZE_QUEST_BUTTON_HEIGHT_NORMAL);
    this->setPosition(x,y);

	this->need[MATH_ID]			= 0;
	this->need[ALGORITHM_ID]	= 0;
	this->need[PROGRAMMING_ID]  = 0;
	this->need[DESIGN_ID]		= 0;
	this->need[DATABASES_ID]	= 0;
	this->need[ELECTRONICS_ID]	= 0;
        
	//this->description->setColor(sf::Color::Red);
	//this->description->setFont(*font);
	//this->description->setCharacterSize(16);
	this->questName = getNameText();
    this->questName->setColor(sf::Color::Green);
    this->questName->setPosition(this->getXPosition()+8,this->getYPosition());
    this->questName->setCharacterSize(FONT_SIZE_NORMAL);
                
    this->description = getDescText();
    this->description->setColor(sf::Color::Black);
    this->description->setPosition(this->getXPosition()+8,this->getYPosition()+FONT_SIZE_NORMAL*2);
    this->description->setCharacterSize(FONT_SIZE_SMALL);
}


Quest::~Quest(void)
{
}

void Quest::action(Game* game){
	std::cout<<"Quest selected"<<std::endl;
   if(isAvaible(game) && isVisible()){
	   game->setCurrentQuest(this);
   }
}

void Quest::hide(){
	this->visible = false;
}

void Quest::show(){
	this->visible = true;
}

void Quest::setVisible(bool visible){
	this->visible = visible;
}
	 
bool Quest::isAvaible(Game* game){
	Player* player = game->getPlayer();
	bool ret = false;
	
	if(	this->need[MATH_ID] <= player->getMath()				&&
		this->need[ALGORITHM_ID] <= player->getAlgortihm()		&&
		this->need[PROGRAMMING_ID] <= player->getProgramming()	&&
		this->need[DESIGN_ID] <= player->getDesign()			&&
		this->need[DATABASES_ID] <= player->getDatabases()		&&
		this->need[ELECTRONICS_ID] <= player->getElectronics()){
			ret = true;
	}

	return ret;
}
	 
Item* Quest::getItem(){
	return this->item;
}

bool Quest::isVisible(){
	return this->visible;
}

void Quest::setDescription(std::string description){
	this->description->setString(description);
}

sf::Text* Quest::getQuestDescription(){
	return this->description;
}

bool Quest::isComplete(){
	return this->completed;
}


int Quest::getMoney(){
	return this->money;
}

void Quest::draw(sf::RenderWindow* window){
    Button::draw(window);
    window->draw(*this->description);
    window->draw(*this->questName);
}

sf::Text* Quest::getNameText(){
    sf::Text* text = new sf::Text(); 
    switch(this->id){
        case QUEST_HELLO_WORLD:
            text->setString("Hello World");
            break;
        case QUEST_CALCULATOR:
            text->setString("Calculator");
            break;
        default:
            text->setString("NOT FOUND");
            break;
    }
    return text;
}

sf::Text* Quest::getDescText(){
    sf::Text* text = new sf::Text(); 
    switch(this->id){
        case QUEST_HELLO_WORLD:
            text->setString("Write your first program.(Why should I greet this cruel World...?)");
            break;
        case QUEST_CALCULATOR:
            text->setString("Write your first simple calculator. You love arithmetic operations!");
            break;
        default:
            text->setString("NOT FOUND");
            break;
    } 
    sf::Font *font = new sf::Font();

    if(!font->loadFromFile(FONT_STANDARD)){
        std::cout<<"Font couldn't be loaded"<<std::endl;
    }else{
    	text->setFont(*font);
    }

    return text;
}

void Quest::setPosition(int x, int y){
    Button::setPosition(x,y);
    this->questName->setPosition(this->getXPosition()+8,this->getYPosition());
    this->description->setPosition(this->getXPosition()+8,this->getYPosition()+FONT_SIZE_NORMAL*2);
    
}
