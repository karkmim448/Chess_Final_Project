#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "game_gui.hpp"

#define MAX_NUMBER_OF_ITEMS 3       //play load quit

class MenuState: public State{
    public:
        MenuState(GameDataRef data);
        void init();

        void MoveUp();
	    void MoveDown();
	    int GetPressedItem() { return selectedItemIndex; }

        void handleInput() = 0;
        void update(float dt) = 0;
        void Draw(float) = 0;

    private:
        GameDataRef _data;
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
};


#endif
