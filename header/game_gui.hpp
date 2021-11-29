#include "SFML/Graphics.hpp"
//#include "game.hpp"

class GameGui
{
private:
    /* data */
    sf::Sprite board[8][8];

public:
    GameGui(sf::RenderWindow &window);
    ~GameGui(){}
    void Run(sf::RenderWindow &window);
};
