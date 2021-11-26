#include "../../header/pieces/queen.hpp"

queen::queen(std::pair<int, int> pos){
    this->_position = pos;
}

bool queen::getColor(){
    return this->_color;
}

std::string queen::getIcon(){
    return this->_icon;
}
void queen::setColor(bool b){
    this->_color = b;
}

void queen::setIcon(std::string s){
    this->_icon = s;
}

bool queen::moveCheck(std::pair<int, int> endingSquare){
    for(int i = 0; i < _possiblemoves.size(); i++){
        if(_possiblemoves.at(i) == endingSquare){
            return true;
        }
        else{
            return false;
        }
    }
}

void queen::getPossibleMoves(){
    std::pair<int, int> temp;

    temp = _position;

    while(temp.first <= 7 && temp.second <= 7){
        temp.first += 1;
        temp.second += 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }

    temp = _position;

    while(temp.first >= 0 && temp.second >= 0){
        temp.first -= 1;
        temp.second -= 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }

    temp = _position;

    while(temp.first <= 7 && temp.second >= 0){
        temp.first += 1;
        temp.second -= 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }

    temp = _position;
    
    while(temp.first >= 0 && temp.second <- 7){
        temp.first -= 1;
        temp.second += 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }

    while(temp.first <= 7){
        temp.first += 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }

    temp = _position;

    while(temp.first >= 0){
        temp.first -= 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }

    temp = _position;

    while(temp.second <= 7){
        temp.second += 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }

    temp = _position;

    while(temp.second >= 0){
        temp.second -= 1;

        _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
    }
}
