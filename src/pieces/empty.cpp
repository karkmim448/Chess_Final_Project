#include "../../header/pieces/empty.hpp"

empty::empty(std::pair<int, int> pos){
}


bool empty::getColor(){return true;}
std::string empty::getIcon(){return "";}
void empty::setColor(bool){}
void empty::setIcon(std::string){}
bool empty::moveCheck(std::pair<int, int> endingSquare){return true;}
void empty::getPossibleMoves(){}