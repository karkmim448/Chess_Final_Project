#ifndef __PIECE_FACTORY_HPP__
#define __PIECE_FACTORY_HPP__

#include <string>
#include "pieces/piece.hpp"

class PieceFactory{
public:

	virtual piece* DrawPawn(std::pair<int, int>, Game*) = 0;
	virtual piece* DrawRook(std::pair<int, int>, Game*) = 0;
	virtual piece* DrawKing(std::pair<int, int>, Game*) = 0;
	virtual piece* DrawKnight(std::pair<int, int>, Game*) = 0;
	virtual piece* DrawBishop(std::pair<int, int>, Game*) = 0;
	virtual piece* DrawQueen(std::pair<int, int>, Game*) = 0;


};

#endif
