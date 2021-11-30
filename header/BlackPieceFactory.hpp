#ifndef __BLACK_PIECE_FACTORY_HPP__
#define __BLACK_PIECE_FACTORY_HPP__

#include <string>
#include "PieceFactory.hpp"
#include "game.hpp"


class BlackPieceFactory: public PieceFactory{
public:

	BlackPieceFactory();

	piece* DrawPawn(Game* g);
	piece* DrawRook(Game* g);
	piece* DrawKing(Game* g);
	piece*  DrawKnight(Game* g);
	piece* DrawBishop(Game* g);
	piece* DrawQueen(Game* g);


};




#endif
