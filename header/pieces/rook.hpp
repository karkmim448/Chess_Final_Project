#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include "piece.hpp"
#include <utility>
#include <string>

class rook : public piece{
	
public:
	rook(std::pair<int, int> pos, std::string s, Game* g);

	bool castleCheck();
		
    bool getColor();
    std::string getIcon();
    void setColor(bool);
    void setIcon(std::string);
    bool moveCheck(std::pair<int, int> endingSquare);
    void getPossibleMoves(std::pair<int, int> startingSquare);
};

#endif
