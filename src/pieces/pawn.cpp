#include "../../header/pieces/pawn.hpp"


pawn::pawn(std::pair<int, int> pos){
    this->_position = pos;
}

bool pawn::getColor(){
    return this->_color;
}

std::string pawn::getIcon(){
    return this->_icon;
}
void pawn::setColor(bool b){
    this->_color = b;
}

void pawn::setIcon(std::string s){
    this->_icon = s;
}

bool pawn::moveCheck(std::pair<int, int> endingSquare){
    for(int i = 0; i < _possiblemoves.size(); i++){
        if(_possiblemoves.at(i) == endingSquare){
            return true;
        }
        else{
            return false;
        }
    }
}

void pawn::getPossibleMoves(){
    std::pair<int, int> temp;

    temp = _position;

    if(this->_color){
        if(temp.first < 7){
           _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second));
        }
    }
    else{
        if(temp.first > 0){
            _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second));
        }
    }
}
