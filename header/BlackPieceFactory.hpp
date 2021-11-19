#ifndef __BLACK_PIECE_FACTORY_HPP__
#define __BLACK_PIECE_FACTORY_HPP__

#include <string>
#include "PieceFactory.hpp"


class BlackPieceFactory: public PieceFactory{

public:
	piece* DrawPawn(std::pair<int, int>);
	piece* DrawRook(std::pair<int, int>);
	piece* DrawKing(std::pair<int, int>);
	piece* DrawKnight(std::pair<int, int>);
	piece* DrawBishop(std::pair<int, int>);
    piece* DrawEmpty(std::pair<int, int>);

};



#endif
