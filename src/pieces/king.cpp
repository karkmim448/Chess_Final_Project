#include "../../header/pieces/king.hpp"


bool king::castleCheck(){return true;}

king::king(std::pair<int, int> pos){
    this->_position = pos;
}

bool king::getColor(){
    return this->_color;
}

std::string king::getIcon(){
    return this->_icon;
}
void king::setColor(bool b){
    this->_color = b;
}

void king::setIcon(std::string s){
    this->_icon = s;
}

bool king::moveCheck(std::pair<int, int> endingSquare){
    for(int i = 0; i < _possiblemoves.size(); i++){
        if(_possiblemoves.at(i) == endingSquare){
            return true;
        }
        else{
            return false;
        }
    }
}

void king::getPossibleMoves(){
    std::pair<int, int> temp;

    temp = _position;

    //really terrible brute force implementation
    if(temp.first == 0 && temp.second == 0){
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second));
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second + 1));
        _possiblemoves.push_back(std::make_pair(temp.first, temp.second + 1));    
    }
    else if(temp.first == 7 && temp.second == 7){
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second));
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second - 1));
        _possiblemoves.push_back(std::make_pair(temp.first, temp.second - 1));
    }
    else if(temp.first == 0 && temp.second > 0 && temp.second < 7){
        _possiblemoves.push_back(std::make_pair(temp.first, temp.second - 1));
        _possiblemoves.push_back(std::make_pair(temp.first, temp.second + 1));
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second - 1));
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second));
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second + 1));
    }
    else if(temp.first == 7 && temp.second > 0 && temp.second < 7){
        _possiblemoves.push_back(std::make_pair(temp.first, temp.second - 1));
        _possiblemoves.push_back(std::make_pair(temp.first, temp.second + 1));
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second - 1));
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second));
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second + 1));
    }
    else if(temp.second == 0 && temp.first > 0 && temp.first < 7){
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second));
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second));
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second + 1));
        _possiblemoves.push_back(std::make_pair(temp.first, temp.second + 1));
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second + 1));
    }
    else if(temp.second == 7 && temp.first > 0 && temp.first < 7){
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second));
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second));
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second - 1));
        _possiblemoves.push_back(std::make_pair(temp.first, temp.second - 1));
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second - 1));
    }
    else{
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second - 1));
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second));
        _possiblemoves.push_back(std::make_pair(temp.first - 1, temp.second + 1));
        _possiblemoves.push_back(std::make_pair(temp.first, temp.second - 1));
        _possiblemoves.push_back(std::make_pair(temp.first, temp.second + 1));
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second - 1));
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second));
        _possiblemoves.push_back(std::make_pair(temp.first + 1, temp.second + 1));
    }
}
