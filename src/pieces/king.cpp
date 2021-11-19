#include "../../header/pieces/king.hpp"

king::king(std::pair<int, int> pos){
}

bool king::castleCheck(){return true;}

bool king::getColor(){return true;}
std::string king::getIcon(){return "";}
void king::setColor(bool){}
void king::setIcon(std::string){}
bool king::moveCheck(std::pair<int, int> endingSquare){return true;}
void king::getPossibleMoves(){}
