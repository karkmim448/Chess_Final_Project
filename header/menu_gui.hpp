#include "SFML/Graphics.hpp"
#include "menu.hpp"

class MenuGui
{
private:
    /* data */
    sf::Sprite board[8][8];
    
public:
    
    MenuGui(sf::RenderWindow &window);
    ~MenuGui(){}
    void Run(sf::RenderWindow &window);
    
};

