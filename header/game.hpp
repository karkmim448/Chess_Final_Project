#include </SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "square.hpp"
#include <fstream>

class Game : Square {
  protected:
    Square *board[8][8];
  public:
    void DrawBoard(string fileName);
}

