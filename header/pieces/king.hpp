#ifndef __KING_HPP__
#define __KING_HPP__

#include "../../header/pieces/specialmove.hpp"

class king : public specialmove{

public:
        bool castleCheck();

        bool _hasMoved;
        bool _inCheck;	

        king(std::pair<int, int> pos=std::make_pair(0,0));
    bool getColor();
    std::string getIcon();
    void setColor(bool);
    void setIcon(std::string);
    bool moveCheck(std::pair<int, int> endingSquare);
    void getPossibleMoves();
};

#endif

