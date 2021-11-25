#ifndef __WHITE_PIECE_FACTORY_HPP__
#define __WHITE_PIECE_FACTORY_HPP__

#include <string>
#include "PieceFactory.hpp"
#include "game.hpp"


class WhitePieceFactory: public PieceFactory{
public:

	WhitePieceFactory();
	piece* DrawPawn(std::pair<int, int>, Game*);
	piece* DrawRook(std::pair<int, int>, Game*);
	piece* DrawKing(std::pair<int, int>, Game*);
	piece* DrawKnight(std::pair<int, int>, Game*);
	piece* DrawBishop(std::pair<int, int>, Game*);
    piece* DrawQueen(std::pair<int, int>, Game*);

};



#endif
