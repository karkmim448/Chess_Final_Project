#include "../../header/pieces/queen.hpp"

queen::queen(): piece() {}

queen::queen(bool color, std::string icon, Game* game): piece(color, icon, game) {}

queen::~queen() {}

void queen::updatePossibleMoves(std::pair<int, int> position){
    //clear updatePossibleMoves
    this->getPossibleMoves()->clear();
    
    std::pair<int, int> temp; //stores position

    //cover forward right loop
    temp = std::make_pair(position.first - 1, position.second + 1);

    while((temp.first >= 0) && (temp.second <= 7)){
        //destination square is empty
        if(this->getGame()->getSquare(temp)->getPiece() == nullptr){
            this->getPossibleMoves()->push_back(temp);

            temp.first = temp.first - 1;
            temp.second = temp.second + 1;
        }

        //destination square has a piece of the opposite color
        else if(this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(temp);

            temp = std::make_pair(-9, 9);
        }

        //destination square has a piece of the same color in it
        else{
            temp = std::make_pair(-9, 9);
        }
    }

    //cover forward left loop
    temp = std::make_pair(position.first - 1, position.second - 1);

    while((temp.first >= 0) && (temp.second >= 0)){
        //destination square is empty
        if(this->getGame()->getSquare(temp)->getPiece() == nullptr){
            this->getPossibleMoves()->push_back(temp);

            temp.first = temp.first - 1;
            temp.second = temp.second - 1;
        }

        //destination square has a piece of the opposite color
        else if(this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(temp);

            temp = std::make_pair(-9, -9);
        }
        
        //destination square has a piece of the same color in it
        else{
            temp = std::make_pair(-9, -9);
        }
    }

    //cover backward right loop
    temp = std::make_pair(position.first + 1, position.second + 1);

    while((temp.first <= 7) && (temp.second <= 7)){
        //destination square is empty
        if(this->getGame()->getSquare(temp)->getPiece() == nullptr){
            this->getPossibleMoves()->push_back(temp);

            temp.first = temp.first + 1;
            temp.second = temp.second + 1;
        }
        
        //destination square has a piece of the opposite color
        else if(this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(temp);

            temp = std::make_pair(9, 9);
        }

        //destination square has a piece of the same color in it
        else{
            temp = std::make_pair(9, 9);
        }
    }

    //cover forward left loop
    temp = std::make_pair(position.first + 1, position.second - 1);

    while((temp.first <= 7) && (temp.second >= 0)){
        //destination square is empty
        if(this->getGame()->getSquare(temp)->getPiece() == nullptr){
            this->getPossibleMoves()->push_back(temp);

            temp.first = temp.first + 1;
            temp.second = temp.second - 1;
        }
        
        //destination square has a piece of the opposite color
        else if(this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(temp);

            temp = std::make_pair(9, -9);
        }

        //destination square has a piece of the same color in it
        else{
            temp = std::make_pair(9, -9);
        }
    }

    //cover forward case
    temp = std::make_pair(position.first - 1, position.second);

    while(temp.first <= 0){
        //destination square is empty
        if(this->getGame()->getSquare(temp)->getPiece() == nullptr){
            this->getPossibleMoves()->push_back(temp);

            temp.first = temp.first - 1;
        }

        //destination square has a piece of the opposite color
        else if(this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(temp);

            temp = std::make_pair(-9, 9);
        }

        //destination square has a piece of the same color in it
        else{
            temp = std::make_pair(-9, 9);
        }
    }

    //cover backward case
    temp = std::make_pair(position.first + 1, position.second);

    while(temp.first >= 7){
        //destination square is empty
        if(this->getGame()->getSquare(temp)->getPiece() == nullptr){
            this->getPossibleMoves()->push_back(temp);

            temp.first = temp.first + 1;
        }

        //destination square has a piece of the opposite color
        else if(this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(temp);

            temp = std::make_pair(9, 9);
        }

        //destination square has a piece of the same color in it
        else{
            temp = std::make_pair(9, 9);
        }
    }

    //cover left case
    temp = std::make_pair(position.first, position.second - 1);

    while(temp.first <= 0){
        //destination square is empty
        if(this->getGame()->getSquare(temp)->getPiece() == nullptr){
            this->getPossibleMoves()->push_back(temp);

            temp.second = temp.second - 1;
        }

        //destination square has a piece of the opposite color
        else if(this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(temp);

            temp = std::make_pair(-9, 9);
        }

        //destination square has a piece of the same color in it
        else{
            temp = std::make_pair(-9, 9);
        }
    }

    //cover right case
    temp = std::make_pair(position.first, position.second + 1);

    while(temp.first >= 7){
        //destination square is empty
        if(this->getGame()->getSquare(temp)->getPiece() == nullptr){
            this->getPossibleMoves()->push_back(temp);

            temp.second = temp.second + 1;
        }

        //destination square has a piece of the opposite color
        else if(this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
            this->getPossibleMoves()->push_back(temp);

            temp = std::make_pair(9, 9);
        }

        //destination square has a piece of the same color in it
        else{
            temp = std::make_pair(9, 9);
        }
    }
}