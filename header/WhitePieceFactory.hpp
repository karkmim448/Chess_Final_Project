#ifndef __WHITE_PIECE_FACTORY_HPP__
#define __WHITE_PIECE_FACTORY_HPP__

#include <string>
#include "PieceFactory.hpp"
#include "game.hpp"


class WhitePieceFactory: public PieceFactory{
public:
	WhitePieceFactory();

	piece* DrawPawn(Game*);
	piece* DrawRook(Game*);
	piece* DrawKing(Game*);
	piece* DrawKnight(Game*);
	piece* DrawBishop(Game*);
    piece* DrawQueen(Game*);

};



#endif
