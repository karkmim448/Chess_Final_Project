#include "SFML/Graphics.hpp"

#include "game.hpp"
#include <chrono>
#include <thread>

class GameGui
{
private:
    /* data */
    sf::Sprite board[8][8];

public:
    GameGui(sf::RenderWindow &window, std::string fileName);
    ~GameGui(){}
    
    void Run(sf::RenderWindow &window, std::string fileName);
    void drawBoard(sf::RenderWindow &window, sf::Texture &lightSquareTexture, sf::Texture &darkSquareTexture);
    void drawPieces(sf::RenderWindow &window, Game &game, std::vector<sf::Sprite> spriteVector1);
    std::pair<int, int> movePiece(sf::RenderWindow &window, Game &game, std::pair<int, int> piecePair);
    void gameOver(std::string winner, sf::RenderWindow &window);
};
