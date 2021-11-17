#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "../../header/pieces/piece.hpp"

class queen : public piece{

        public:
                void move(startingSquare, endingSquare);
                void movecheck(startingSquare);
                void capture(startingSquare);
};

#endif
