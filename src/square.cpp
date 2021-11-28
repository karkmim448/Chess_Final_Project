
#include "../header/square.hpp"

Square::Square(): _color(0), _highlighted(0), _piece(0) {}

Square::Square(bool color): _color(color), _highlighted(0), _piece(nullptr){}

Square::Square(bool color, piece* piece): _color(color), _highlighted(0), _piece(piece) {}

Square::~Square(){
    delete this->_piece;
}

bool Square::getColor(){
    return this->_color;
}

bool Square::getHighlight(){
    return this->_highlighted;
}

piece* Square::getPiece(){
    return this->_piece;
}

void Square::setColor(bool color){
    this->_color = color;
}

void Square::setHighlight(bool highlight){
    this->_highlighted = highlight;
}

void Square::setPiece(piece* toBeSet){
    this->_piece = toBeSet;
}
