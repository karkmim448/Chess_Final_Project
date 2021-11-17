#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include "../../header/pieces/specialmove.hpp"

class rook : public specialmove{
	
	public:
		bool castleCheck();

		bool _hasMoved;
		
		void move(startingSquare, endingSquare);
		void movecheck(startingSquare);
		void capture(startingSquare);
};

#endif
