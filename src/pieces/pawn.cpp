#include "../../header/pieces/pawn.hpp"

pawn::pawn(): piece() {}

pawn::pawn(bool color, std::string icon, Game* game): piece(color, icon, game) {}

pawn::~pawn() {}

void pawn::updatePossibleMoves(std::pair<int, int> position){
    //check what color pawn is
}

void pawn::promote(std::pair<int, int> position){ //To be implemented by Gurman, requires GUI to function properly

}