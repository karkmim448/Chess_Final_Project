#include "../../header/pieces/pawn.hpp"

pawn::pawn(std::pair<int, int> pos){
}


bool pawn::getColor(){return true;}
std::string pawn::getIcon(){return "";}
void pawn::setColor(bool){}
void pawn::setIcon(std::string){}
bool pawn::moveCheck(std::pair<int, int> endingSquare){return true;}
void pawn::getPossibleMoves(){}
