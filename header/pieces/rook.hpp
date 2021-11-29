#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include <utility>
#include <string>

#include "piece.hpp"

class rook : public piece{
    public:
        void updatePossibleMoves(std::pair<int, int> position);
};

#endif
