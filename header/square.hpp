#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include "pieces/piece.hpp"

class Square{
  private:
    /* 
      -True = light, False = dark
      -Used by gui to determine square color, static after construction, never should be changed 
    */
    bool _color;

    /*
      -Used by gui, when a piece is selected, highlights the squares that the user can move that piece to
      -Also used by game to determine if a move is valid, if the square is highlighted, the move is valid
      -Should default to zero, having it set to one should be temporary
      -Should be set to one only when a piece is selected but has not moved yet
    */
    bool _highlighted;
    
    /* 
      -Strategy pattern, used for movement
      -Used by Game to determine valid squares for a piece to move to
      -Should be changed when a piece moves or a pawn promotes
    */
    piece* _piece;
  public:
    //Constructors
    Square();
    Square(bool color);
    Square(bool color, piece* piece);

    //Destructor
    ~Square();

    //Basic Accessors
    bool getColor();
    bool getHighlight();
    piece* getPiece();
    
    //Basic Mutators
    void setColor(bool color);//should never be used
    void setHighlight(bool highlight);
    void setPiece(piece* piece);
};

#endif //__SQUARE_HPP__//