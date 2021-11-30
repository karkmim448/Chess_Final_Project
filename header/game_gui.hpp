#include "SFML/Graphics.hpp"
#include "game.hpp"

class GameGui
{
private:
    /* data */
    sf::Sprite board[8][8];

public:
    GameGui(sf::RenderWindow &window, Game &game);
    ~GameGui(){}
    void Run(sf::RenderWindow &window, Game &game);
    void drawBoard(sf::RenderWindow &window, sf::Texture &lightSquareTexture, sf::Texture &darkSquareTexture);
    void drawPieces(sf::RenderWindow &window, Game &game, std::vector<sf::Sprite> spriteVector1);

};
