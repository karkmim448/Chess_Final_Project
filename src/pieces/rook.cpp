#include "../../header/pieces/rook.hpp"

rook::rook(std::pair<int, int> pos){
}

bool rook::castleCheck(){return true;}

bool rook::getColor(){return true;}
std::string rook::getIcon(){return "";}
void rook::setColor(bool){}
void rook::setIcon(std::string){}
bool rook::moveCheck(std::pair<int, int> endingSquare){return true;}
void rook::getPossibleMoves(){}

