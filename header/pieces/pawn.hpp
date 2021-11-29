#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include "piece.hpp"

class pawn: public piece{
    public:
        void updatePossibleMoves(std::pair<int, int> position);
        void promote(std::pair<int, int> position);
};

#endif
