#include "../../header/pieces/knight.hpp"

knight::knight(std::pair<int, int> pos){
    this->_position = pos;
}

bool knight::getColor(){
    return this->_color;
}

std::string knight::getIcon(){
    return this->_icon;
}
void knight::setColor(bool b){
    this->_color = b;
}

void knight::setIcon(std::string s){
    this->_icon = s;
}

bool knight::moveCheck(std::pair<int, int> endingSquare){
    for(int i = 0; i < _possiblemoves.size(); i++){
        if(_possiblemoves.at(i) == endingSquare){
            return true;
        }
        else{
            return false;
        }
    }
}

void knight::getPossibleMoves(){
    
    std::pair<int, int> temp = _position;

    //going down 2 and to the left and the right
    if(temp.first <= 5){
        for (int i = 0; i < 2; i++){
            temp.first += 2;
            if(i == 0 && temp.second <= 6){
                //To the right
                temp.second += 1;

                _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
            }
            else if(i == 1 && temp.second >= 1){
                //To the left
                temp.second -= 1;

                _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
            }
        }
        temp = _position;
    }

    //going up 2 and left and right
    if(temp.first >= 2){
        for (int j = 0; j < 2; j++){
            temp.first -= 2;
            if(j == 0 && temp.second <= 6){
                //To the right
                temp.second += 1;

                  _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
            }
            else if(j == 1 && temp.second >= 1){
                //To the left
                temp.second -= 1;

                _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
            }
        temp = _position;
        }
    }

    //going right 2 and then up and down
    if(temp.second <= 5){
        for (int k = 0; k < 2; k++){
            temp.second += 2;
            if(k == 0 && temp.first <= 6){
                //going down
                temp.first += 1;

                _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
            }
            else if(k == 1 && temp.first >= 1){
                //going up
                temp.first -= 1;

                _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
            }
        }
        temp = _position;
    }

    //going left 2 and then up and down
    if(temp.second >= 2){
        for (int l = 0; l < 2; l++){
            temp.second -= 2;
            if(l == 0 && temp.first <= 6){
                //To the right
                temp.first += 1;

                  _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
            }
            else if(l == 1 && temp.first >= 1){
                //To the left
                temp.first -= 1;

                _possiblemoves.push_back(std::make_pair(temp.first, temp.second));
            }
        temp = _position;
        }
    }

}
