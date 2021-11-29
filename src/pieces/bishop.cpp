#include "../../header/pieces/bishop.hpp"

bishop::bishop(): piece() {}

bishop::bishop(bool color, std::string icon, Game* game): piece(color, icon, game) {}

bishop::~bishop() {}

void bishop::updatePossibleMoves(std::pair<int, int> position){
    //clear updatePossibleMoves
    this->getPossibleMoves()->clear();
    
    //cover forward right loop

    //cover forward left loop

    //cover backward right loop

    //cover forward left loop
}