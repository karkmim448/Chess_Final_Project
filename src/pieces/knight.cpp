#include "../../header/pieces/knight.hpp"

knight::knight(): piece() {}

knight::knight(bool color, std::string icon, Game* game): piece(color, icon, game) {}

knight::~knight() {}

void knight::updatePossibleMoves(std::pair<int, int> position){
    //clear possibleMoves
    this->getPossibleMoves()->clear();

    //check forward cases
    if(position.first - 2 >= 0){
        //check forward left case
        if(position.second - 1 >= 0 && this->getGame()->getSquare(std::make_pair(position.first - 2, position.second - 1))->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(std::make_pair(position.first - 2, position.second - 1));
        }

        //check forward right case
        if(position.second + 1 <= 7 && this->getGame()->getSquare(std::make_pair(position.first - 2, position.second + 1))->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(std::make_pair(position.first - 2, position.second + 1));
        }
    }

    //check bacward cases
    if(position.first + 2 <= 7){
        //check backward left case
        if(position.second - 1 >= 0 && this->getGame()->getSquare(std::make_pair(position.first + 2, position.second - 1))->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(std::make_pair(position.first + 2, position.second - 1));
        }

        //check backward right case
        if(position.second + 1 <= 7 && this->getGame()->getSquare(std::make_pair(position.first + 2, position.second + 1))->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(std::make_pair(position.first + 2, position.second + 1));
        }
    }

    //check left cases
    if(position.second - 2 >= 0){
        //check left forward case
        if(position.first - 1 >= 0 && this->getGame()->getSquare(std::make_pair(position.first - 1, position.second - 2))->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(std::make_pair(position.first - 1, position.second - 2));
        }

        //check left backward case
        if(position.first + 1 >= 0 && this->getGame()->getSquare(std::make_pair(position.first + 1, position.second - 2))->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(std::make_pair(position.first + 1, position.second - 2));
        }
    }

    //check right cases
    if(position.second + 2 <= 7){
        //check right forward case
        if(position.first - 1 >= 0 && this->getGame()->getSquare(std::make_pair(position.first - 1, position.second + 2))->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(std::make_pair(position.first - 1, position.second + 2));
        }

        //check right backward case
        if(position.first + 1 >= 0 && this->getGame()->getSquare(std::make_pair(position.first + 1, position.second + 2))->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(std::make_pair(position.first + 1, position.second + 2));
        }
    }
}