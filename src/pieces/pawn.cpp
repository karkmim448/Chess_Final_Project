#include "../../header/pieces/pawn.hpp"

pawn::pawn(): piece() {}

pawn::pawn(bool color, std::string icon, Game* game): piece(color, icon, game) {}

pawn::~pawn() {}

void pawn::updatePossibleMoves(std::pair<int, int> position){
    //clear _possibleMoves so that it only contains the most recent call of updatePossibleMoves
    this->getPossibleMoves()->clear();

    //check what color pawn is, determines direction of pawn movement
    if(this->getColor()){ //white piece branch
        //check if one space move is valid, if so check two space move if piece has not moved
        if(this->getGame()->getSquare(std::make_pair(position.first - 1, position.second))->getPiece() == nullptr){
            //adding one square move to possible moves
            this->getPossibleMoves()->push_back(std::make_pair(position.first - 1, position.second));

            //checking if two space move is valid
            if((!this->getHasMoved()) && (this->getGame()->getSquare(std::make_pair(position.first - 2, position.second))->getPiece() == nullptr) && (position.first - 2 >= 0)){
                this->getPossibleMoves()->push_back(std::make_pair(position.first - 2, position.second));
            }
        }

        //check capture cases

        //check left capture case
        //check if there is a piece in the left diagonal of the pawn
        if(this->getGame()->getSquare(std::make_pair(position.first - 1, position.second - 1))->getPiece() != nullptr){
            //check of that piece is a black piece
            if(this->getGame()->getSquare(std::make_pair(position.first - 1, position.second - 1))->getPiece()->getColor() != this->getColor()){
                this->getPossibleMoves()->push_back(std::make_pair(position.first - 1, position.second - 1));
            }
        }

        //check right capture case
        //check if there is a piece in the right diagonal of the pawn
        if(this->getGame()->getSquare(std::make_pair(position.first - 1, position.second + 1))->getPiece() != nullptr){
            //check of that piece is a black piece
            if(this->getGame()->getSquare(std::make_pair(position.first - 1, position.second + 1))->getPiece()->getColor() != this->getColor()){
                this->getPossibleMoves()->push_back(std::make_pair(position.first - 1, position.second + 1));
            }
        }

        //check if last move was a pawn for en-passant case
        if(this->getGame()->getInitialPiece() != nullptr && this->getGame()->getInitialPiece()->getIcon() == "images/black_pawn.png"){
            //check left en-passant case
            if((this->getGame()->getSquare(std::make_pair(position.first, position.second - 1))->getPiece() != nullptr) && (this->getGame()->getSquare(std::make_pair(position.first, position.second - 1))->getPiece()->getIcon() == "images/black_pawn.png")){
                if(this->getGame()->getInitialSquare()->first == position.first - 2 && this->getGame()->getInitialSquare()->second == position.second - 1){
                    this->getPossibleMoves()->push_back(std::make_pair(position.first - 1, position.second - 1));
                }
            }

            //check right en-passant case
            if((this->getGame()->getSquare(std::make_pair(position.first, position.second + 1))->getPiece() != nullptr) && (this->getGame()->getSquare(std::make_pair(position.first, position.second + 1))->getPiece()->getIcon() == "images/black_pawn.png")){
                if(this->getGame()->getInitialSquare()->first == position.first - 2 && this->getGame()->getInitialSquare()->second == position.second + 1){
                    this->getPossibleMoves()->push_back(std::make_pair(position.first - 1, position.second + 1));
                }
            }
        }
    }

    else{ //black piece branch
        //check if one space move is valid, if so check two space move if piece has not moved
        if(this->getGame()->getSquare(std::make_pair(position.first + 1, position.second))->getPiece() == nullptr){
            //adding one square move to possible moves
            this->getPossibleMoves()->push_back(std::make_pair(position.first + 1, position.second));

            //checking if two space move is valid
            if((!this->getHasMoved()) && (this->getGame()->getSquare(std::make_pair(position.first + 2, position.second))->getPiece() == nullptr) && (position.first + 2 <= 7)){
                this->getPossibleMoves()->push_back(std::make_pair(position.first + 2, position.second));
            }
        }

        //check capture cases

        //check left capture case
        //check if there is a piece in the left diagonal of the pawn
        if(this->getGame()->getSquare(std::make_pair(position.first + 1, position.second - 1))->getPiece() != nullptr){
            //check of that piece is a black piece
            if(this->getGame()->getSquare(std::make_pair(position.first + 1, position.second - 1))->getPiece()->getColor() != this->getColor()){
                this->getPossibleMoves()->push_back(std::make_pair(position.first + 1, position.second - 1));
            }
        }
        
        //check right capture case
        //check if there is a piece in the right diagonal of the pawn
        if(this->getGame()->getSquare(std::make_pair(position.first + 1, position.second + 1))->getPiece() != nullptr){
            //check of that piece is a black piece
            if(this->getGame()->getSquare(std::make_pair(position.first + 1, position.second + 1))->getPiece()->getColor() != this->getColor()){
                this->getPossibleMoves()->push_back(std::make_pair(position.first + 1, position.second + 1));
            }
        }

        //check if last move was a pawn for en-passant case
        if(this->getGame()->getInitialPiece()->getIcon() == "images/white_pawn.png"){
            //check left en-passant case
            if((this->getGame()->getSquare(std::make_pair(position.first, position.second - 1))->getPiece() != nullptr) && (this->getGame()->getSquare(std::make_pair(position.first, position.second - 1))->getPiece()->getIcon() == "images/white_pawn.png")){
                if(this->getGame()->getInitialSquare()->first == position.first + 2 && this->getGame()->getInitialSquare()->second == position.second - 1){
                    this->getPossibleMoves()->push_back(std::make_pair(position.first + 1, position.second - 1));
                }
            }

            //check right en-passant case
            if((this->getGame()->getSquare(std::make_pair(position.first, position.second + 1))->getPiece() != nullptr) && (this->getGame()->getSquare(std::make_pair(position.first, position.second + 1))->getPiece()->getIcon() == "images/white_pawn.png")){
                if(this->getGame()->getInitialSquare()->first == position.first + 2 && this->getGame()->getInitialSquare()->second == position.second + 1){
                    this->getPossibleMoves()->push_back(std::make_pair(position.first + 1, position.second + 1));
                }
            }
        }
    }
}

void pawn::promote(std::pair<int, int> position){ //To be implemented by Gurman, requires GUI to function properly

}