#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include "piece.hpp"

class bishop : public piece{
    public:
        bishop();
	    bishop(bool color, std::string icon, Game* game);

        ~bishop();
        
        void updatePossibleMoves(std::pair<int, int> position);
};

#endif
