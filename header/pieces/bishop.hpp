#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include "../../header/pieces/piece.hpp"

class bishop : public piece{

        public:
                void move(startingSquare, endingSquare);
                void movecheck(startingSquare);
                void capture(startingSquare);
};

#endif
