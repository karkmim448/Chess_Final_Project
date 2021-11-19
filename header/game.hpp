#ifndef __GAME_HPP__
#define __GAME_HPP__

//#include </SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "square.hpp"
#include <fstream>
#include "PieceFactory.hpp"

class Game : Square {
  protected:
    PieceFactory *factory;
    Square **board[8][8];
  public:
    Game();
    void DrawBoard(std::string fileName);

};

#endif
