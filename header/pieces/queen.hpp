#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "piece.hpp"

class queen : public piece{
public:
    queen(std::pair<int, int> pos, std::string s, Game* g);

    bool getColor();
    std::string getIcon();
    void setColor(bool);
    void setIcon(std::string);
    bool moveCheck(std::pair<int, int> endingSquare);
    void getPossibleMoves(std::pair<int, int> startingSquare);
};

#endif
