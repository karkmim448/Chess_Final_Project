//#include </SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "pieces/piece.hpp"

class Square{
  private:
    bool _color;
  public:
    piece* piece;
    piece* getPiece();
    bool getCurrentColor();
    bool getPieceColor();
    void replacePiece(int newX, int newY);
    void checkPiece();    //checks if piece taken is king->gameover

};

