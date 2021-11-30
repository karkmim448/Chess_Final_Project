#ifndef __KING_HPP__
#define __KING_HPP__

#include "piece.hpp"

class king : public piece{

public:
        bool castleCheck();

        bool _inCheck;	

    king(std::pair<int, int> pos, std::string s, Game* g);

    bool getColor();
    std::string getIcon();
    void setColor(bool);
    void setIcon(std::string);
    bool moveCheck(std::pair<int, int> endingSquare);
    void getPossibleMoves(std::pair<int, int> startingSquare);
};

#endif

