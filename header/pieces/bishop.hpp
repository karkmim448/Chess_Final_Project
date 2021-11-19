#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include "../../header/pieces/piece.hpp"

class bishop : public piece{

    bishop(std::pair<int, int> pos=std::make_pair(0,0));

    bool getColor();
    std::string getIcon();
    void setColor(bool);
    void setIcon(std::string);
    bool moveCheck(std::pair<int, int> endingSquare);
    void getPossibleMoves();	
};

#endif
