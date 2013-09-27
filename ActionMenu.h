/* 
 * File:   ActionMenu.h
 * Author: niels
 *
 * Created on 10. April 2013, 09:09
 */

#ifndef ACTIONMENU_H
#define	ACTIONMENU_H
#include "Drawable.h"
#include "Action.h"
class ActionMenu : public DrawAble{
public:
    ActionMenu();
    ActionMenu(const ActionMenu& orig);
    virtual ~ActionMenu();
	bool isShown();
	void showMenu(bool b);
	void draw(sf::RenderWindow* window);
private:
	bool shown;
	//std::map<std::string,Action*> actions;
	std::vector<Action*> actions;

};

#endif	/* ACTIONMENU_H */

