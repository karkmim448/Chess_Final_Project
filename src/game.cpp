#include "game.hpp"

Game::Game(): _playerTurn(1), _destinationSquare(0), _initialSquare(0), _initialPiece(0), _finalPiece(0) {
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
    std::pair<int, int> temp;
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

    this->_initialSquare = &std::make_pair(fileRow, fileColumn);

    temp = std::make_pair(fileRow, fileColumn);

    //read in mostRecentEndingSquare and set it
    fin >> fileRow;
    fin >> fileColumn;

    this->_destinationSquare = &std::make_pair(fileRow, fileColumn);

    temp2 = std::make_pair(fileRow, fileColumn);

    //read in undoMoveInitialPieceStorage and set it
    fin >>fileInput;

    //repeat for loop logic, but only got through it once for undoMoveInitialPieceStorage
    if(fileInput.at(0) == '+'){
        if(fileInput.at(1) == 'p'){
            this->_initialPiece = whiteFactory.DrawPawn(temp, this);
        }

        else if(fileInput.at(1) == 'r'){
            this->_initialPiece = whiteFactory.DrawRook(temp, this);
        }

        else if(fileInput.at(1) == 'h'){
            this->_initialPiece = whiteFactory.DrawKnight(temp, this);
        }

        else if(fileInput.at(1) == 'b'){
            this->_initialPiece = whiteFactory.DrawBishop(temp, this);
        }

        else if(fileInput.at(1) == 'q'){
            this->_initialPiece = whiteFactory.DrawQueen(temp, this);
        }

        else if(fileInput.at(1) == 'k'){
            this->_initialPiece = whiteFactory.DrawKing(temp, this);
        }
    }

    else if(fileInput.at(0) == '-'){
        if(fileInput.at(1) == 'p'){
            this->_initialPiece = blackFactory.DrawPawn(temp, this);
        }

        else if(fileInput.at(1) == 'r'){
            this->_initialPiece = blackFactory.DrawRook(temp, this);
        }

        else if(fileInput.at(1) == 'h'){
            this->_initialPiece = blackFactory.DrawKnight(temp, this);
        }

        else if(fileInput.at(1) == 'b'){
            this->_initialPiece = blackFactory.DrawBishop(temp, this);
        }

        else if(fileInput.at(1) == 'q'){
            this->_initialPiece = blackFactory.DrawQueen(temp, this);
        }

        else if(fileInput.at(1) == 'k'){
            this->_initialPiece = blackFactory.DrawKing(temp, this);
        }
    }

    else{
        this->_initialPiece = nullptr;
    }

    //repeat for undoMoveFinalPieceStorage
    fin >> fileInput;

    if(fileInput.at(0) == '+'){
        if(fileInput.at(1) == 'p'){
            this->_finalPiece = whiteFactory.DrawPawn(temp2, this);
        }

        else if(fileInput.at(1) == 'r'){
            this->_finalPiece = whiteFactory.DrawRook(temp2, this);
        }

        else if(fileInput.at(1) == 'h'){
            this->_finalPiece = whiteFactory.DrawKnight(temp2, this);
        }

        else if(fileInput.at(1) == 'b'){
            this->_finalPiece = whiteFactory.DrawBishop(temp2, this);
        }

        else if(fileInput.at(1) == 'q'){
            this->_finalPiece = whiteFactory.DrawQueen(temp2, this);
        }

        else if(fileInput.at(1) == 'k'){
            this->_finalPiece = whiteFactory.DrawKing(temp2, this);
        }
    }

    else if(fileInput.at(0) == '-'){
        if(fileInput.at(1) == 'p'){
            this->_finalPiece = blackFactory.DrawPawn(temp2, this);
        }

        else if(fileInput.at(1) == 'r'){
            this->_finalPiece = blackFactory.DrawRook(temp2, this);
        }

        else if(fileInput.at(1) == 'h'){
            this->_finalPiece = blackFactory.DrawKnight(temp2, this);
        }

        else if(fileInput.at(1) == 'b'){
            this->_finalPiece = blackFactory.DrawBishop(temp2, this);
        }

        else if(fileInput.at(1) == 'q'){
            this->_finalPiece = blackFactory.DrawQueen(temp2, this);
        }

        else if(fileInput.at(1) == 'k'){
            this->_finalPiece = blackFactory.DrawKing(temp2, this);
        }
    }

    else{
        this->_finalPiece = nullptr;
    }
}

Game::~Game(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            delete this->_board[i][j];
        }
    }

    delete this->_initialPiece;
    delete this->_finalPiece;
    delete this->_destinationSquare;
    delete this->_initialSquare;
}

bool Game::getPlayerTurn(){
    return this->_playerTurn;
}

Square* Game::getSquare(std::pair<int, int> position){
    return this->_board[position.first][position.second];
}

std::pair<int, int>* Game::getInitialSquare(){
    return this->_initialSquare;
}

std::pair<int, int>* Game::getDestinationSquare(){
    return this->_destinationSquare;
}

piece* Game::getInitialPiece(){
    return this->_initialPiece;
}

piece* Game::getFinalPiece(){
    return this->_finalPiece;
}

void Game::setPlayerTurn(bool playerTurn){
    this->_playerTurn = playerTurn;
}

void Game::setInitialSquare(std::pair<int, int>* toBeSet){
    std::pair<int, int>* temp = this->_initialSquare;
    delete temp;
    this->_initialSquare = toBeSet;
}

void Game::setDestinationSquare(std::pair<int, int>* toBeSet){
    std::pair<int, int>* temp = this->_destinationSquare;
    delete temp;
    this->_destinationSquare = toBeSet;
}

void Game::setInitialPiece(piece* toBeSet){
    piece* temp = _initialPiece;
    delete temp;
    this->_initialPiece = toBeSet;
}

void Game::setFinalPiece(piece* toBeSet){
    piece* temp = _finalPiece;
    delete temp;
    this->_finalPiece = toBeSet;
}

void Game::save(){
    std::ofstream fout; //outputs information to Save.txt for use in a later load

    Square* temp;

    fout.open("../Save/Save.txt"); //opens Save.txt

    //start by saving board state

    //outer for loop iterates through each row in board state
    for(int i = 0; i < 8; i++){
        //inner for loop iterates through each square in each row
        for(int j = 0; j < 8; j++){
            temp = this->getSquare(std::make_pair(i, j));
            //check if there is a piece in target square, else store empty square
            if(temp->getPiece() != nullptr){
                    if(temp->getPiece()->getColor()){ //white piece branch
                        fout << '+';
                    }

                    else{   //white piece branch
                        fout << '-';
                    }

                    if(temp->getPiece()->getIcon() == "images/white_pawn.png" || temp->getPiece()->getIcon() == "images/black_pawn.png"){ //pawn branch
                        fout << 'p';
                    }

                    else if (temp->getPiece()->getIcon() == "images/white_rook.png" || temp->getPiece()->getIcon() == "images/black_rook.png"){ //rook branch
                        fout << 'r';
                    }

                    else if(temp->getPiece()->getIcon() == "images/white_knight.png" || temp->getPiece()->getIcon() == "images/black_knight.png"){ //knight branch
                        fout << 'h';
                    }

                    else if(temp->getPiece()->getIcon() == "images/white_bishop.png" || temp->getPiece()->getIcon() == "images/black_bishop.png"){ //bishop branch
                        fout << 'b';
                    }

                    else if(temp->getPiece()->getIcon() == "images/white_queen.png" || temp->getPiece()->getIcon() == "images/black_queen.png"){ //queen branch
                        fout << 'q';
                    }

                    else{ //king branch
                        fout << 'k';
                    }
            }

            else{ //empty square branch
                fout << '0';
            }

            fout << ' ';
        }
        //after each row, output newline to keep formatting
        fout << std::endl;
    }
    
    fout << std::endl;
    //should be done with board state, move on to other member variables
    
    //store player turn
    if(this->getPlayerTurn()){
        fout << '1' << std::endl;
    }

    else{
        fout << '0' << std::endl;
    }

    //store undoMoveStorage
}

void Game::load(){

}

bool Game::selectPiece(std::pair<int, int> initialPosition){

}

bool Game::movePiece(std::pair<int, int> initialPosition, std::pair<int, int> destinationSquare){

}

void Game::undoMove(){

}