#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "../../header/pieces/piece.hpp"

class knight : public piece{

        public:
                void move(startingSquare, endingSquare);
                void movecheck(startingSquare);
                void capture(startingSquare);
};

#endif

