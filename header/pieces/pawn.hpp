#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include "../../header/pieces/specialmove.hpp"

class pawn : public specialmove{

public:
    pawn(std::pair<int, int> pos=std::make_pair(0,0));

    bool _hasMoved;

    bool getColor();
    std::string getIcon();
    void setColor(bool);
    void setIcon(std::string);
    bool moveCheck(std::pair<int, int> endingSquare);
    void getPossibleMoves();
};

#endif
