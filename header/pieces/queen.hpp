#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "../../header/pieces/piece.hpp"

class queen : public piece{
public:
    queen(std::pair<int, int> pos=std::make_pair(0,0));

    bool getColor();
    std::string getIcon();
    void setColor(bool);
    void setIcon(std::string);
    bool moveCheck(std::pair<int, int> endingSquare);
    void getPossibleMoves();
};

#endif
