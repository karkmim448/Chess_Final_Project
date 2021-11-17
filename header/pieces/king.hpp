#ifndef __KING_HPP__
#define __KING_HPP__

#include "../../header/pieces/specialmove.hpp"

class king : public specialmove{

        public:
                bool castleCheck();

                bool _hasMoved;
		bool _inCheck;	
		
                void move(startingSquare, endingSquare);
                void movecheck(startingSquare);
                void capture(startingSquare);
};

#endif

