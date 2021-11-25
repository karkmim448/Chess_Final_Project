#include "game.hpp"

Game::Game(): _playerTurn(1), _mostRecentEndingSquare(0), _mostRecentStartingSquare(0), _undoMovePieceStorage(0){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            this->_board[i][j] = new Square();
        }
    }
}

Game::Game(std::string fileName){
    std::fstream fin; //extracts input from file to be used for piece creation
    std::string fileInput = "";  //stores input from fin to be used to parse piece storage for piece creation

    bool squareColor = true; //holds color of square, alternated whenever a square is created
    std::pair<int, int> temp2; //holds position to be fed to piece factories
    int fileRow, fileColumn; //used by fin to build pairs for undoStorage variables
                             //fileRow is also used as the temp variable for single integer variables by fin

    WhitePieceFactory whiteFactory; //white piece factory used to generate all white pieces
    BlackPieceFactory blackFactory; //black piece factory used to generate all black pieces

    //file name is either "../Save/Default.txt" or "../Save/Save.txt"
    fin.open(fileName);
    
    //iterates through each row in board
    for(int i = 0; i < 8; i++){

        //iterates through each column in each row of board
        for(int j = 0; j < 8; j++){
            //fin should be iterating through the 8x8 grid of pieces stored in Savestates
            fin >> fileInput;

            //make the position based on i and j values, i is row, j is column
            temp2 = std::make_pair(i, j);

            //check what color the piece is as well as if there is even a piece there
            if(fileInput.at(0) == '+'){ //white piece branch
                //check what piece is at this position, build the square using said piece
                if(fileInput.at(1) == 'p'){
                    this->_board[i][j] = new Square(squareColor, whiteFactory.DrawPawn(temp2, this));
                }

                else if(fileInput.at(1) == 'r'){
                    this->_board[i][j] = new Square(squareColor, whiteFactory.DrawRook(temp2, this));
                }

                else if(fileInput.at(1) == 'h'){
                    this->_board[i][j] = new Square(squareColor, whiteFactory.DrawKnight(temp2, this));
                }

                else if(fileInput.at(1) == 'b'){
                    this->_board[i][j] = new Square(squareColor, whiteFactory.DrawBishop(temp2, this));
                }

                else if(fileInput.at(1) == 'q'){
                    this->_board[i][j] = new Square(squareColor, whiteFactory.DrawQueen(temp2, this));
                }

                else if(fileInput.at(1) == 'k'){
                    this->_board[i][j] = new Square(squareColor, whiteFactory.DrawKing(temp2, this));
                }
            }

            else if(fileInput.at(0) == '-'){ //black piece branch
                //check what piece is at this position, build the square using said piece
                if(fileInput.at(1) == 'p'){
                    this->_board[i][j] = new Square(squareColor, blackFactory.DrawPawn(temp2, this));
                }

                else if(fileInput.at(1) == 'r'){
                    this->_board[i][j] = new Square(squareColor, blackFactory.DrawRook(temp2, this));
                }

                else if(fileInput.at(1) == 'h'){
                    this->_board[i][j] = new Square(squareColor, blackFactory.DrawKnight(temp2, this));
                }

                else if(fileInput.at(1) == 'b'){
                    this->_board[i][j] = new Square(squareColor, blackFactory.DrawBishop(temp2, this));
                }

                else if(fileInput.at(1) == 'q'){
                    this->_board[i][j] = new Square(squareColor, blackFactory.DrawQueen(temp2, this));
                }

                else if(fileInput.at(1) == 'k'){
                    this->_board[i][j] = new Square(squareColor, blackFactory.DrawKing(temp2, this));
                }
            }

            else{   //empty square branch
                this->_board[i][j] = new Square(squareColor);
            }

            //swap Square color in order to build the alternating tiles
            squareColor = !squareColor;
        }
    }
    //at this point fin should be done with the board state grid, now work on other member variables
    
    //read in player turn and set it
    fin >> fileRow;
    this->_playerTurn = fileRow;

    //read in mostRecentStartingSquare and set it
    fin >> fileRow;
    fin >> fileColumn;

    this->_mostRecentStartingSquare = &std::make_pair(fileRow, fileColumn);

    //read in mostRecentEndingSquare and set it
    fin >> fileRow;
    fin >> fileColumn;

    this->_mostRecentEndingSquare = &std::make_pair(fileRow, fileColumn);

    //read in most undoMovePieceStorage and set it
    fin >>fileInput;

    //repeat for loop logic, but only got through it once
    temp2 = std::make_pair(fileRow, fileColumn);

    if(fileInput.at(0) == '+'){
        if(fileInput.at(1) == 'p'){
            this->_undoMovePieceStorage = whiteFactory.DrawPawn(temp2, this);
        }

        else if(fileInput.at(1) == 'r'){
            this->_undoMovePieceStorage = whiteFactory.DrawRook(temp2, this);
        }

        else if(fileInput.at(1) == 'h'){
            this->_undoMovePieceStorage = whiteFactory.DrawKnight(temp2, this);
        }

        else if(fileInput.at(1) == 'b'){
            this->_undoMovePieceStorage = whiteFactory.DrawBishop(temp2, this);
        }

        else if(fileInput.at(1) == 'q'){
            this->_undoMovePieceStorage = whiteFactory.DrawQueen(temp2, this);
        }

        else if(fileInput.at(1) == 'k'){
            this->_undoMovePieceStorage = whiteFactory.DrawKing(temp2, this);
        }
    }

    else if(fileInput.at(0) == '-'){
        if(fileInput.at(1) == 'p'){
            this->_undoMovePieceStorage = blackFactory.DrawPawn(temp2, this);
        }

        else if(fileInput.at(1) == 'r'){
            this->_undoMovePieceStorage = blackFactory.DrawRook(temp2, this);
        }

        else if(fileInput.at(1) == 'h'){
            this->_undoMovePieceStorage = blackFactory.DrawKnight(temp2, this);
        }

        else if(fileInput.at(1) == 'b'){
            this->_undoMovePieceStorage = blackFactory.DrawBishop(temp2, this);
        }

        else if(fileInput.at(1) == 'q'){
            this->_undoMovePieceStorage = blackFactory.DrawQueen(temp2, this);
        }

        else if(fileInput.at(1) == 'k'){
            this->_undoMovePieceStorage = blackFactory.DrawKing(temp2, this);
        }
    }

    else{
        this->_undoMovePieceStorage = nullptr;
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