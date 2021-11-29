#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include "../../header/pieces/piece.hpp"

class bishop : public piece{
    public:
        void updatePossibleMoves(std::pair<int, int> position);
};

#endif
