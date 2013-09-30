#include "BuyMenu.h"
#include <sstream>

std::string convertInt(int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

BuyMenu::BuyMenu(Menu* prevMenu):Menu("menu_buy.png",MENU_BUY)
{
	int y = 0;
	int x = 1;

	for(int i = 1; i <= 2; i++){
		ItemHoldButton* holder = new ItemHoldButton();
		holder->setPosition(SIZE_HOLDER_BUTTON_WIDTH_NORMAL,
			                SIZE_HOLDER_BUTTON_HEIGHT_NORMAL*i);
		
		Item* item = new Item(i-1);			// i-1 because of enums, a little bit dirty but nobody will see it... ever!
		item->setPosition(SIZE_HOLDER_BUTTON_WIDTH_NORMAL + SIZE_HOLDER_BUTTON_WIDTH_NORMAL/4,
			              SIZE_HOLDER_BUTTON_HEIGHT_NORMAL*i + SIZE_HOLDER_BUTTON_HEIGHT_NORMAL/4);
		
		holder->setItem(item);

		this->itemHolderButtons.push_back(holder);
		sf::Text* t = this->getText(i-1);
		sf::Font* font = new sf::Font();
        sf::Text* p = new sf::Text();
        p->setString("Price: " + convertInt(item->getBuyPrice()));      //Must be done like that
                
        if(!font->loadFromFile(FONT_STANDARD)){
            std::cout<<"FAILED: loading font in BuyMenu"<<std::endl;
        }else{
            p->setFont(*font); 
            t->setFont(*font);
        }
                
                //Bug Default-Font doesn't exist in SFML2
                
		t->setCharacterSize(FONT_SIZE_NORMAL);
		p->setCharacterSize(FONT_SIZE_NORMAL);
		p->setStyle(sf::Text::Bold);

		t->setPosition(SIZE_HOLDER_BUTTON_WIDTH_NORMAL*2 + FONT_SIZE_NORMAL,
			                SIZE_HOLDER_BUTTON_HEIGHT_NORMAL*i);

		p->setPosition(SIZE_HOLDER_BUTTON_WIDTH_NORMAL*2 + FONT_SIZE_NORMAL,
			                SIZE_HOLDER_BUTTON_HEIGHT_NORMAL*i + FONT_SIZE_NORMAL + 8);

		price.push_back(p);
		text.push_back(t);
	}

	CloseButton* closeButton = new CloseButton(this,prevMenu);

	closeButton->setPosition(SIZE_WINDOW_WIDTH_NORMAL  - SIZE_BUTTON_WIDTH_NORMAL*2,
		                     SIZE_WINDOW_HEIGHT_NORMAL - SIZE_BUTTON_HEIGHT_NORMAL);

	this->addButton(closeButton);
}


BuyMenu::~BuyMenu(void)
{
	itemHolderButtons.clear();
	text.clear();
}

void BuyMenu::draw(sf::RenderWindow* window){
	Menu::draw(window);

	for(int i = 0; i < itemHolderButtons.size(); i++){
		window->draw(*itemHolderButtons[i]->getSprite());
		window->draw(*itemHolderButtons[i]->getItem()->getSprite());
		window->draw(*text[i]);
		window->draw(*price[i]);
	}
}

sf::Text* BuyMenu::getText(int id){
	sf::Text* text = new sf::Text();
	switch(id){
		case ITEM_BOOK_HELLO_WORLD:
			text->setString("My First Program");
			break;
		case ITEM_BOOK_CALCULATOR:
			text->setString("Simple...");
			break;
		default:
			text->setString("Forget to write something, blame the programmer");
			break;
	}

	return text;
}