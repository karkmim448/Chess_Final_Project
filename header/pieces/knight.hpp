#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "piece.hpp"

class knight : public piece{
    public:
        void updatePossibleMoves(std::pair<int, int> position);
};

#endif

