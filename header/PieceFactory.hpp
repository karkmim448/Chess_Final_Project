#ifndef __PIECE_FACTORY_HPP__
#define __PIECE_FACTORY_HPP__

#include <string>
#include "pieces/piece.hpp"

class PieceFactory{
public:
	PieceFactory();
	
	virtual piece* DrawPawn(Game*) = 0;
	virtual piece* DrawRook(Game*) = 0;
	virtual piece* DrawKing(Game*) = 0;
	virtual piece* DrawKnight(Game*) = 0;
	virtual piece* DrawBishop(Game*) = 0;
	virtual piece* DrawQueen(Game*) = 0;


};

#endif
