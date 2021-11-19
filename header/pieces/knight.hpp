#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "../../header/pieces/piece.hpp"

class knight : public piece{

    knight(std::pair<int, int> pos=std::make_pair(0,0));
    bool getColor();
    std::string getIcon();
    void setColor(bool);
    void setIcon(std::string);
    bool moveCheck(std::pair<int, int> endingSquare);
    void getPossibleMoves();
};

#endif

