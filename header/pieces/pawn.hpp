#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include "../../src/pieces/specialmove.hpp"

class pawn : Public specialmove{

public:
	bool _hasMoved;

	void move(startingSquare, endingSquare);
	void movecheck(startingSquare);
	void capture(startingSquare);
	bool enPassantCheck();
	void promote();
};

#endif
