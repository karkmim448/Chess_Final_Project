#ifndef __BLACK_PIECE_FACTORY_HPP__
#define __BLACK_PIECE_FACTORY_HPP__

#include <string>
#include "PieceFactory.hpp"
#include "game.hpp"


class BlackPieceFactory: public PieceFactory{
public:
	BlackPieceFactory();

	piece* DrawPawn(std::pair<int, int> pos, Game*);
	piece* DrawRook(std::pair<int, int> pos, Game*);
	piece* DrawKing(std::pair<int, int> pos, Game*);
	piece*  DrawKnight(std::pair<int, int> pos, Game*);
	piece* DrawBishop(std::pair<int, int> pos, Game*);
	piece* DrawQueen(std::pair<int, int> pos, Game*);

};




#endif
