#include </SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "/pieces/piece.hpp"

class Square{
  private:
    piece* _piece;
    bool _color;
  public:
    bool getCurrentColor();
    bool getPieceColor();
    virtual void replacePiece(int newX, int newY)=0;
    void checkPiece();    //checks if piece taken is king->gameover

}

