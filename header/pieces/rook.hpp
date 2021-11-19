#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include "../../header/pieces/specialmove.hpp"
#include <utility>
#include <string>

class rook : public specialmove{
	
public:
	rook(std::pair<int, int> pos=std::make_pair(0,0));

	bool castleCheck();

	bool _hasMoved;
		
    bool getColor();
    std::string getIcon();
    void setColor(bool);
    void setIcon(std::string);
    bool moveCheck(std::pair<int, int> endingSquare);
    void getPossibleMoves();
};

#endif
