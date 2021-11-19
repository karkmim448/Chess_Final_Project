#ifndef __GAME_HPP__
#define __GAME_HPP__

//#include </SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "square.hpp"
#include <fstream>
#include "PieceFactory.hpp"

class Game{
  protected:
    PieceFactory *factory;
    Square **board[8][8];
  public:
    Game();
    Square** getBoard();
    void DrawBoard(std::string fileName);

};

#endif
