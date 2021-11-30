#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include "piece.hpp"

class bishop : public piece{
public:
    bishop(std::pair<int, int> pos, std::string s, Game* g);

    bool getColor();
    std::string getIcon();
    void setColor(bool);
    void setIcon(std::string);
    bool moveCheck(std::pair<int, int> endingSquare);
    void getPossibleMoves(std::pair<int, int> startingSquare);	
};

#endif
