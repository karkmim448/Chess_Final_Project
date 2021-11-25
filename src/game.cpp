#include "../header/game.hpp"

Game::Game(): _playerTurn(1), _mostRecentEndingSquare(0), _mostRecentStartingSquare(0), _undoMovePieceStorage(0){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            this->_board[i][j] = new Square();
        }
    }
}

Game::Game(std::string fileName){
    ifstream fin;
    std::string temp = "";
    
    fin.open(fileName);

    for(int i = 0; i < 8; i++){
        /*
            -If statement determines order fo light square dark square for row
            -If i is even, first square is light
            -If i is odd, first square is dark
        */
        if (i % 2){
            for(int j = 0; j < 8; j++){


                /*
                    -If j is even, square is dark
                    -If j is odd, square is light
                */
                if(j % 2){

                }

                else{

                }
            }
        }

        else{
            for(int j = 0; j < 8; j++){
                fin >> temp;

                /*
                    -If j is even, square is light
                    -If j is odd, square is dark
                */
                if(j % 2){

                }

                else{

                }
            }
        }
    }
}

Game::~Game(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            delete _board[i][j];
        }
    }

    delete _undoMovePieceStorage;
}

bool Game::getPlayerTurn(){
    return this->_playerTurn;
}

Square* Game::getSquare(std::pair<int, int> position){
    return this->_board[position.first][position.second];
}

std::pair<int, int>* Game::getMostRecentStartingSquare(){
    return this->_mostRecentStartingSquare;
}

std::pair<int, int>* Game::getMostRecentEndingSquare(){
    return this->_mostRecentEndingSquare;
}

piece* Game::getUndoMovePieceStorage(){
    return this->_undoMovePieceStorage;
}

void Game::setPlayerTurn(bool playerTurn){
    this->_playerTurn = playerTurn;
}

void Game::setMostRecentStartingSquare(std::pair<int, int>* toBeSet){
    this->_mostRecentStartingSquare = toBeSet;
}

void Game::setMostRecentEndingSquare(std::pair<int, int>* toBeSet){
    this->_mostRecentEndingSquare = toBeSet;
}

void Game::setUndoMovePieceStorage(piece* toBeSet){
    this->_undoMovePieceStorage = toBeSet;
}

void Game::save(){

}

void Game::load(){

}

bool Game::selectPiece(std::pair<int, int> initialPosition){

}

bool Game::movePiece(std::pair<int, int> initialPosition, std::pair<int, int> destinationSquare){

}

void Game::undoMove(){

}