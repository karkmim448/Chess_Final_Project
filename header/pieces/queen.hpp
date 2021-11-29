#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "../../header/pieces/piece.hpp"

class queen : public piece{
    public:
        queen();
	    queen(bool color, std::string icon, Game* game);

        ~queen();
        
        void updatePossibleMoves(std::pair<int, int> position);
};

#endif
