#ifndef __KING_HPP__
#define __KING_HPP__

#include "piece.hpp"

class king : public piece{
    public:
        void updatePossibleMoves(std::pair<int, int> position);
};

#endif

