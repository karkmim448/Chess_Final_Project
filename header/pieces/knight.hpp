#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "piece.hpp"

class knight : public piece{
    public:
        knight();
	    knight(bool color, std::string icon, Game* game);

        ~knight();
        
        void updatePossibleMoves(std::pair<int, int> position);
};

#endif

