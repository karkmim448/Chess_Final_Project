#include "../../header/pieces/bishop.hpp"

bishop::bishop(std::pair<int, int> pos){
}


bool bishop::getColor(){return true;}
std::string bishop::getIcon(){return "";}
void bishop::setColor(bool){}
void bishop::setIcon(std::string){}
bool bishop::moveCheck(std::pair<int, int> endingSquare){return true;}
void bishop::getPossibleMoves(){}
