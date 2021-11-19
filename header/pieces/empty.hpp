#ifndef __EMPTY_HPP__
#define __EMPTY_HPP__

#include "../../header/pieces/piece.hpp"

class empty : public piece{
public:
    empty(std::pair<int, int> pos=std::make_pair(0,0));

    bool getColor();
    std::string getIcon();
    void setColor(bool);
    void setIcon(std::string);
    bool moveCheck(std::pair<int, int> endingSquare);
    void getPossibleMoves();
};

#endif
