#include "../../src/pieces/piece.hpp"
#include <string>


bool piece::getColor(){
	return this->_color;
}
std::string piece::getIcon(){
	return this->_icon;
}

void piece::setColor(bool color){
	this->_color = color;
}
void piece::setIcon(string icon){
	this->_icon = icon
}
