#include "../../header/pieces/king.hpp"

king::king(): piece() {}

king::king(bool color, std::string icon, Game* game): piece(color, icon, game) {}

king::~king() {}

void king::updatePossibleMoves(std::pair<int, int> position){
    std::pair<int, int> temp;

    //clear possible moves
    this->getPossibleMoves()->clear();

    //cover forward case
    temp = std::make_pair(position.first - 1, position.second);

    if(this->getGame()->getSquare(temp)->getPiece() == nullptr || this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
        this->getPossibleMoves()->push_back(temp);
    }

    //cover forward right case
    temp = std::make_pair(position.first - 1, position.second + 1);

    if(this->getGame()->getSquare(temp)->getPiece() == nullptr || this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
        this->getPossibleMoves()->push_back(temp);
    }
    
    //cover right case
    temp = std::make_pair(position.first, position.second + 1);

    if(this->getGame()->getSquare(temp)->getPiece() == nullptr || this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
        this->getPossibleMoves()->push_back(temp);
    }
    
    //cover backward right case
    temp = std::make_pair(position.first + 1, position.second + 1);

    if(this->getGame()->getSquare(temp)->getPiece() == nullptr || this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
        this->getPossibleMoves()->push_back(temp);
    }
    
    //cover backward case
    temp = std::make_pair(position.first + 1, position.second);

    if(this->getGame()->getSquare(temp)->getPiece() == nullptr || this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
        this->getPossibleMoves()->push_back(temp);
    }
    
    //cover backward left case
    temp = std::make_pair(position.first + 1, position.second - 1);

    if(this->getGame()->getSquare(temp)->getPiece() == nullptr || this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
        this->getPossibleMoves()->push_back(temp);
    }
    
    //cover left case
    temp = std::make_pair(position.first, position.second - 1);

    if(this->getGame()->getSquare(temp)->getPiece() == nullptr || this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
        this->getPossibleMoves()->push_back(temp);
    }
    
    //cover left forward case
    temp = std::make_pair(position.first - 1, position.second - 1);

    if(this->getGame()->getSquare(temp)->getPiece() == nullptr || this->getGame()->getSquare(temp)->getPiece()->getColor() != this->getColor()){
        this->getPossibleMoves()->push_back(temp);
    }
    
    //castling requires the king to have not moved
    if (!this->getHasMoved()){
        bool canCastle = true;

        //cover king side castle case
        temp = std::make_pair(position.first, position.second + 2);

        //check for bounds of board
        if(temp.second <= 7){
            //check to see if squares are empty besides corner
            for(int i = position.second + 1; i < 7; i++){
                if(this->getGame()->getSquare(std::make_pair(position.first, i))->getPiece() != nullptr){
                    canCastle = false;
                }
            }

            if(canCastle){    
                //check for piece in king side corner
                if(this->getGame()->getSquare(std::make_pair(temp.first, 7))->getPiece() != nullptr && this->getGame()->getSquare(std::make_pair(temp.first, 7))->getPiece()->getColor() != this->getColor()){
                    //check if piece in corner is a rook
                    if(this->getColor()){ //white king
                        if (this->getGame()->getSquare(std::make_pair(temp.first, 7))->getPiece()->getIcon() == "images/white_rook.png"){
                            //check if rook has moved
                            if(!this->getGame()->getSquare(std::make_pair(temp.first, 7))->getPiece()->getHasMoved()){
                                //castle is a legal move
                                this->getPossibleMoves()->push_back(temp);
                            }
                        }
                    }

                    else{ //black king
                        if (this->getGame()->getSquare(std::make_pair(temp.first, 7))->getPiece()->getIcon() == "images/black_rook.png"){
                            //check if rook has moved
                            if(!this->getGame()->getSquare(std::make_pair(temp.first, 7))->getPiece()->getHasMoved()){
                                //castle is a legal move
                                this->getPossibleMoves()->push_back(temp);
                            }
                        }
                    }
                }
            }
        }

        canCastle = true;

        //cover queen side castle case
        temp = std::make_pair(position.first, position.second - 2);

        //check for bounds of board
        if(temp.second >= 0){
            //check to see if squares are empty besides corner
            for(int i = position.second - 1; i > 0; i--){
                if(this->getGame()->getSquare(std::make_pair(position.first, i))->getPiece() != nullptr){
                    canCastle = false;
                }
            }

            if(canCastle){    
                //check for piece in queen side corner
                if(this->getGame()->getSquare(std::make_pair(temp.first, 7))->getPiece() != nullptr && this->getGame()->getSquare(std::make_pair(temp.first, 0))->getPiece()->getColor() != this->getColor()){
                    //check if piece in corner is a rook
                    if(this->getColor()){ //white king
                        if (this->getGame()->getSquare(std::make_pair(temp.first, 0))->getPiece()->getIcon() == "images/white_rook.png"){
                            //check if rook has moved
                            if(!this->getGame()->getSquare(std::make_pair(temp.first, 0))->getPiece()->getHasMoved()){
                                //castle is a legal move
                                this->getPossibleMoves()->push_back(temp);
                            }
                        }
                    }

                    else{ //black king
                        if (this->getGame()->getSquare(std::make_pair(temp.first, 0))->getPiece()->getIcon() == "images/black_rook.png"){
                            //check if rook has moved
                            if(!this->getGame()->getSquare(std::make_pair(temp.first, 0))->getPiece()->getHasMoved()){
                                //castle is a legal move
                                this->getPossibleMoves()->push_back(temp);
                            }
                        }
                    }
                }
            }
        }
    }
}