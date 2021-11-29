#include "../../header/pieces/piece.hpp"
#include "../../header/game.hpp"

#include <string>

piece::piece(): _color(0), _icon(""), _possibleMoves(0),_hasMoved(0), _game(nullptr) {}

piece::piece(bool color, std::string icon, Game* game): _color(color), _icon(icon), _possibleMoves(0), _hasMoved(0), _game(game) {}

piece::~piece(){}

bool piece::getColor(){
	return this->_color;
}

std::string piece::getIcon(){
	return this->_icon;
}

std::vector<std::pair<int, int>> piece::getPossibleMoves(){
	return this->_possibleMoves;
}

bool piece::getHasMoved(){
	return this->_hasMoved;
}

Game* piece::getGame(){
	return this->_game;
}

void piece::setColor(bool color){
	this->_color = color;
}

void piece::setHasMoved(bool hasMoved){
	this->_hasMoved = hasMoved;
}