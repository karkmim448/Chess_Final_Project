#include "../../header/pieces/rook.hpp"


bool rook::castleCheck(){return true;}

rook::rook(std::pair<int, int> pos, std::string s, Game* g){
    this->_position = pos;
    this->_icon = s;
}

bool rook::getColor(){
    return this->_color;
}

std::string rook::getIcon(){
    return this->_icon;
}
void rook::setColor(bool b){
    this->_color = b;
}

void rook::setIcon(std::string s){
    this->_icon = s;
}

bool rook::moveCheck(std::pair<int, int> endingSquare){
    for(int i = 0; i < _possiblemoves.size(); i++){
        if(_possiblemoves.at(i) == endingSquare){
            return true;
        }
        else{
            return false;
        }
    }
}

void rook::getPossibleMoves(std::pair<int, int> startingSquare){
    std::pair<int, int> temp;

    temp = startingSquare;

    while(temp.first <= 7){
        temp.first += 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }

    temp = startingSquare;

    while(temp.first >= 0){
        temp.first -= 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }

    temp = startingSquare;

    while(temp.second <= 7){
        temp.second += 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }

    temp = startingSquare;

    while(temp.second >= 0){
        temp.second -= 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }
}

