#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include "piece.hpp"

class pawn: public piece{
    public:
        pawn();
	    pawn(bool color, std::string icon, Game* game);

        ~pawn();
        
        void updatePossibleMoves(std::pair<int, int> position);
        void promote(std::pair<int, int> position);
};

#endif
