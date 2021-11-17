#ifndef __EMPTY_HPP__
#define __EMPTY_HPP__

#include "../../header/pieces/piece.hpp"

class empty : public piece{

        public:
                void move(startingSquare, endingSquare);
                void movecheck(startingSquare);
                void capture(startingSquare);
};

#endif
