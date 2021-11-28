#include "../header/game.hpp"
#include "../header/pieces/pawn.hpp"

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
    this->_initialSquare = toBeSet;
}

void Game::setDestinationSquare(std::pair<int, int>* toBeSet){
    this->_destinationSquare = toBeSet;
}

void Game::setInitialPiece(piece* toBeSet){
    this->_initialPiece = toBeSet;
}

void Game::setFinalPiece(piece* toBeSet){
    this->_finalPiece = toBeSet;
}

void Game::save(){
    std::ofstream fout; //outputs information to Save.txt for use in a later load

    piece* temp;

    fout.open("../Save/Save.txt"); //opens Save.txt

    //start by saving board state

    //outer for loop iterates through each row in board state
    for(int i = 0; i < 8; i++){
        //inner for loop iterates through each square in each row
        for(int j = 0; j < 8; j++){
            temp = this->getSquare(std::make_pair(i, j))->getPiece();
            //check if there is a piece in target square, else store empty square
            if(temp != nullptr){
                    if(temp->getColor()){ //white piece branch
                        fout << '+';
                    }

                    else{   //white piece branch
                        fout << '-';
                    }

                    if(temp->getIcon() == "images/white_pawn.png" || temp->getIcon() == "images/black_pawn.png"){ //pawn branch
                        fout << 'p';
                    }

                    else if (temp->getIcon() == "images/white_rook.png" || temp->getIcon() == "images/black_rook.png"){ //rook branch
                        fout << 'r';
                    }

                    else if(temp->getIcon() == "images/white_knight.png" || temp->getIcon() == "images/black_knight.png"){ //knight branch
                        fout << 'h';
                    }

                    else if(temp->getIcon() == "images/white_bishop.png" || temp->getIcon() == "images/black_bishop.png"){ //bishop branch
                        fout << 'b';
                    }

                    else if(temp->getIcon() == "images/white_queen.png" || temp->getIcon() == "images/black_queen.png"){ //queen branch
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

    //store undoMove Square Storage
    fout << this->getInitialSquare()->first << ' ' << this->getInitialSquare()->second << std::endl;
    fout << this->getDestinationSquare()->first << ' ' << this->getDestinationSquare()->second << std::endl;

    //store initialPiece using for loop logic
    temp = this->getInitialPiece();

    if(temp != nullptr){
        if(temp->getColor()){
            fout << '+';
        }

        else{
            fout << '-';
        }

        if(temp->getIcon() == "images/white_pawn.png" || temp->getIcon() == "images/black_pawn.png"){
            fout << 'p';
        }

        else if(temp->getIcon() == "images/white_rook.png" || temp->getIcon() == "images/black_rook.png"){
            fout << 'r';
        }

        else if(temp->getIcon() == "images/white_knight.png" || temp->getIcon() == "images/black_knight.png"){
            fout << 'h';
        }

        else if(temp->getIcon() == "images/white_bishop.png" || temp->getIcon() == "images/black_bishop.png"){
            fout << 'b';
        }

        else if(temp->getIcon() == "images/white_queen.png" || temp->getIcon() == "images/black_queen.png"){
            fout << 'q';
        }

        else{
            fout << 'k';
        }
    }

    else{
        fout << '0';
    }

    fout << std::endl;

    //store finalPiece using for loop logic
    temp = this->getFinalPiece();

    if(temp != nullptr){
        if(temp->getColor()){
            fout << '+';
        }

        else{
            fout << '-';
        }

        if(temp->getIcon() == "images/white_pawn.png" || temp->getIcon() == "images/black_pawn.png"){
            fout << 'p';
        }

        else if(temp->getIcon() == "images/white_rook.png" || temp->getIcon() == "images/black_rook.png"){
            fout << 'r';
        }

        else if(temp->getIcon() == "images/white_knight.png" || temp->getIcon() == "images/black_knight.png"){
            fout << 'h';
        }

        else if(temp->getIcon() == "images/white_bishop.png" || temp->getIcon() == "images/black_bishop.png"){
            fout << 'b';
        }

        else if(temp->getIcon() == "images/white_queen.png" || temp->getIcon() == "images/black_queen.png"){
            fout << 'q';
        }

        else{
            fout << 'k';
        }
    }

    else{
        fout << '0';
    }
}

void Game::load(){
    std::ifstream fin;
    std::string fileInput;
    int fileRow;
    int fileColumn;
    std::pair<int, int>* initialSquare;
    std::pair<int, int>* destinationSquare;

    BlackPieceFactory blackFactory;
    WhitePieceFactory whiteFactory;

    fin.open("../Save/Save.txt");

    //build board state based on file input

    //outer for loop iterates through each row of board state
    for(int i = 0; i < 8; i++){
        //inner for loop iterates through each square in each row
        for(int j = 0; j < 8; j++){
            fin >> fileInput;

            delete this->getSquare(std::make_pair(i, j))->getPiece();

            if(fileInput.at(0) == '+'){//white piece branch
                if(fileInput.at(1) == 'p'){
                    this->getSquare(std::make_pair(i, j))->setPiece(whiteFactory.DrawPawn(std::make_pair(i, j), this));
                }

                else if(fileInput.at(1) == 'r'){
                    this->getSquare(std::make_pair(i, j))->setPiece(whiteFactory.DrawRook(std::make_pair(i, j), this));
                }

                else if(fileInput.at(1) == 'h'){
                    this->getSquare(std::make_pair(i, j))->setPiece(whiteFactory.DrawKnight(std::make_pair(i, j), this));
                }

                else if(fileInput.at(1) == 'b'){
                    this->getSquare(std::make_pair(i, j))->setPiece(whiteFactory.DrawBishop(std::make_pair(i, j), this));
                }

                else if(fileInput.at(1) == 'q'){
                    this->getSquare(std::make_pair(i, j))->setPiece(whiteFactory.DrawQueen(std::make_pair(i, j), this));
                }

                else{
                    this->getSquare(std::make_pair(i, j))->setPiece(whiteFactory.DrawKing(std::make_pair(i, j), this));
                }
            }

            else if(fileInput.at(0) == '-'){//black piece branch
                if(fileInput.at(1) == 'p'){
                    this->getSquare(std::make_pair(i, j))->setPiece(blackFactory.DrawPawn(std::make_pair(i, j), this));
                }

                else if(fileInput.at(1) == 'r'){
                    this->getSquare(std::make_pair(i, j))->setPiece(blackFactory.DrawRook(std::make_pair(i, j), this));
                }

                else if(fileInput.at(1) == 'h'){
                    this->getSquare(std::make_pair(i, j))->setPiece(blackFactory.DrawKnight(std::make_pair(i, j), this));
                }

                else if(fileInput.at(1) == 'b'){
                    this->getSquare(std::make_pair(i, j))->setPiece(blackFactory.DrawBishop(std::make_pair(i, j), this));
                }

                else if(fileInput.at(1) == 'q'){
                    this->getSquare(std::make_pair(i, j))->setPiece(blackFactory.DrawQueen(std::make_pair(i, j), this));
                }

                else{
                    this->getSquare(std::make_pair(i, j))->setPiece(blackFactory.DrawKing(std::make_pair(i, j), this));
                }
            }

            else{ //empty square branch
                this->getSquare(std::make_pair(i, j))->setPiece(nullptr);
            }
        }
    }
    //should now be done iterating through board state
    //now move on to other member variables

    //read in initialSquare and set it
    fin >> fileRow;
    fin >> fileColumn;

    delete this->getInitialSquare();
    
    initialSquare = &std::make_pair(fileRow, fileColumn);
    this->setInitialSquare(initialSquare);

    //read in destination square and set it
    fin >> fileRow;
    fin >> fileColumn;

    delete this->getDestinationSquare();

    destinationSquare = &std::make_pair(fileRow, fileColumn);
    this->setDestinationSquare(destinationSquare);

    //use for loop logic to read in initial piece
    fin >> fileInput;

    if(fileInput.at(0) == '+'){//white piece branch
        if(fileInput.at(1) == 'p'){
            this->setInitialPiece(whiteFactory.DrawPawn(*initialSquare, this));
        }

        else if(fileInput.at(1) == 'r'){
            this->setInitialPiece(whiteFactory.DrawRook(*initialSquare, this));
        }

        else if(fileInput.at(1) == 'h'){
            this->setInitialPiece(whiteFactory.DrawKnight(*initialSquare, this));
        }

        else if(fileInput.at(1) == 'b'){
            this->setInitialPiece(whiteFactory.DrawBishop(*initialSquare, this));
        }

        else if(fileInput.at(1) == 'q'){
            this->setInitialPiece(whiteFactory.DrawQueen(*initialSquare, this));
        }

        else{
            this->setInitialPiece(whiteFactory.DrawKing(*initialSquare, this));
        }
    }

    else if(fileInput.at(0) == '-'){//black piece branch
        if(fileInput.at(1) == 'p'){
            this->setInitialPiece(blackFactory.DrawPawn(*initialSquare, this));
        }

        else if(fileInput.at(1) == 'r'){
            this->setInitialPiece(blackFactory.DrawRook(*initialSquare, this));
        }

        else if(fileInput.at(1) == 'h'){
            this->setInitialPiece(blackFactory.DrawKnight(*initialSquare, this));
        }

        else if(fileInput.at(1) == 'b'){
            this->setInitialPiece(blackFactory.DrawBishop(*initialSquare, this));
        }

        else if(fileInput.at(1) == 'q'){
            this->setInitialPiece(blackFactory.DrawQueen(*initialSquare, this));
        }

        else{
            this->setInitialPiece(blackFactory.DrawKing(*initialSquare, this));
        }
    }

    else{ //empty square branch
        this->setInitialPiece(nullptr);
    }

    //use for loop logic to read in final piece
    fin >> fileInput;

    if(fileInput.at(0) == '+'){//white piece branch
        if(fileInput.at(1) == 'p'){
            this->setFinalPiece(whiteFactory.DrawPawn(*destinationSquare, this));
        }

        else if(fileInput.at(1) == 'r'){
            this->setFinalPiece(whiteFactory.DrawRook(*destinationSquare, this));
        }

        else if(fileInput.at(1) == 'h'){
            this->setFinalPiece(whiteFactory.DrawKnight(*destinationSquare, this));
        }

        else if(fileInput.at(1) == 'b'){
            this->setFinalPiece(whiteFactory.DrawBishop(*destinationSquare, this));
        }

        else if(fileInput.at(1) == 'q'){
            this->setFinalPiece(whiteFactory.DrawQueen(*destinationSquare, this));
        }

        else{
            this->setFinalPiece(whiteFactory.DrawKing(*destinationSquare, this));
        }
    }

    else if(fileInput.at(0) == '-'){//black piece branch
        if(fileInput.at(1) == 'p'){
            this->setFinalPiece(blackFactory.DrawPawn(*destinationSquare, this));
        }

        else if(fileInput.at(1) == 'r'){
            this->setFinalPiece(blackFactory.DrawRook(*destinationSquare, this));
        }

        else if(fileInput.at(1) == 'h'){
            this->setFinalPiece(blackFactory.DrawKnight(*destinationSquare, this));
        }

        else if(fileInput.at(1) == 'b'){
            this->setFinalPiece(blackFactory.DrawBishop(*destinationSquare, this));
        }

        else if(fileInput.at(1) == 'q'){
            this->setFinalPiece(blackFactory.DrawQueen(*destinationSquare, this));
        }

        else{
            this->setFinalPiece(blackFactory.DrawKing(*destinationSquare, this));
        }
    }

    else{ //empty square branch
        this->setFinalPiece(nullptr);
    }
}

bool Game::selectPiece(std::pair<int, int> initialPosition){
    if(this->getPlayerTurn() != this->getSquare(initialPosition)->getPiece()->getColor()){
        return false;
    }

    this->getSquare(initialPosition)->getPiece()->updatePossibleMoves();

    std::vector<std::pair<int, int>> possibleMoves = this->getSquare(initialPosition)->getPiece()->getPossibleMoves();

    for(int i = 0; i < possibleMoves.size(); i++){
        this->getSquare(possibleMoves.at(i))->setHighlight(1);
    }

    return true;
}

bool Game::movePiece(std::pair<int, int>* initialPosition, std::pair<int, int>* destinationSquare){
    //check if move is valid
    if(!this->getSquare(*destinationSquare)->getHighlight()){
        return false;
    }

    bool enPassantPossible = false;
    bool castlingPossible = false;
    bool pawnPromotion = false;

    //check special cases(en-passant, castling, pawn promotion)
    //if pawn pawn is moving diagonally into an empty square, must be en-passant
    if(this->getSquare(*initialPosition)->getPiece()->getIcon() == "images/white_pawn.png" || this->getSquare(*initialPosition)->getPiece()->getIcon() == "images/black_pawn.png"){
        if(this->getSquare(*destinationSquare)->getPiece() == nullptr && destinationSquare->second - initialPosition->second != 0){
            enPassantPossible = true;
        }
    }

    //If the king is moving two square in the same row, it must be a castle
    else if(this->getSquare(*initialPosition)->getPiece()->getIcon() == "images/white_king.png" || this->getSquare(*initialPosition)->getPiece()->getIcon() == "images/black_king.png"){
        if(destinationSquare->second - initialPosition->second == 2 || destinationSquare->second - initialPosition->second == -2){
            castlingPossible = true;
        }
    }

    //if a pawn is moving in to the last row, must be a promotion
    else if(this->getSquare(*initialPosition)->getPiece()->getIcon() == "images/white_pawn.png" || this->getSquare(*initialPosition)->getPiece()->getIcon() == "images/black_pawn.png"){
        if(this->getSquare(*initialPosition)->getPiece()->getColor()){//white piece branch
            if(destinationSquare->first == 0){
                pawnPromotion = true;
            }
        }

        else{ //black piece branch
            if(destinationSquare->first == 7){
                pawnPromotion = true;
            }
        }
    }

    //update undo move information
    delete this->getInitialSquare();
    this->setInitialSquare(initialPosition);

    delete this->getDestinationSquare();
    this->setDestinationSquare(destinationSquare);

    delete this->getInitialPiece();
    this->setInitialPiece(this->getSquare(*initialPosition)->getPiece());

    delete this->getFinalPiece();
    this->setFinalPiece(this->getSquare(*destinationSquare)->getPiece());

    //if en-passant case is possible, cover en-passant case
    //consits of deleting pawn is position in front of destinationSquare then going through the general case to move the pawn
    if(enPassantPossible){
        if(this->getInitialPiece()->getColor()){ //white piece capturing
            delete this->getSquare(std::make_pair(this->getDestinationSquare()->first + 1, this->getDestinationSquare()->second))->getPiece();
        }

        else{ //black piece capturing
            delete this->getSquare(std::make_pair(this->getDestinationSquare()->first - 1, this->getDestinationSquare()->second))->getPiece();
        }
    }

    //cover castling case
    //consists of moveing the rook to where it needs to be then letting the general case cover the king movement
    if(castlingPossible){
        if(destinationSquare->second - initialPosition->second == 2){//king side castle
            if(this->getInitialPiece()->getColor()){//white castle
                //move rook on king side to position directly to the right of starting king position
                this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second + 1))->setPiece(this->getSquare(std::make_pair(7, 7))->getPiece());
                this->getSquare(std::make_pair(7, 7))->getPiece()->setHasMoved(1);
                this->getSquare(std::make_pair(7, 7))->setPiece(nullptr);
            }

            else{//black castle
                //move rook on king side to position directly to the right of starting king position
                this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second + 1))->setPiece(this->getSquare(std::make_pair(0, 7))->getPiece());
                this->getSquare(std::make_pair(0, 7))->getPiece()->setHasMoved(1);
                this->getSquare(std::make_pair(0, 7))->setPiece(nullptr);
            }
        }

        else{//queen side castle
            if(this->getInitialPiece()->getColor()){ //white castle
                //move rook on queen side to position directly to the left of starting king position
                this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second -1))->setPiece(this->getSquare(std::make_pair(7, 0))->getPiece());
                this->getSquare(std::make_pair(7, 0))->getPiece()->setHasMoved(1);
                this->getSquare(std::make_pair(7, 0))->setPiece(nullptr);
            }

            else{   //black castle
                //move rook on queen side to position directly to the left of starting king position
                this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second -1))->setPiece(this->getSquare(std::make_pair(0, 0))->getPiece());
                this->getSquare(std::make_pair(0, 0))->getPiece()->setHasMoved(1);
                this->getSquare(std::make_pair(0, 0))->setPiece(nullptr);
            }
        }
    }

    //cover general case
    this->getSquare(*initialPosition)->setPiece(nullptr);
    this->getSquare(*destinationSquare)->setPiece(this->getInitialPiece());
    this->getInitialPiece()->setHasMoved(1);

    //call pawn promotion if necessary
    if(pawnPromotion){
        pawn* temp = static_cast<pawn*>(this->getSquare(*destinationSquare)->getPiece());
        temp->promote();
    }

    //de-highlight highlighted squares
    std::vector<std::pair<int, int>> possibleMoves = this->getInitialPiece()->getPossibleMoves();

    for(int i = 0; i < possibleMoves.size(); i++){
        this->getSquare(possibleMoves.at(i))->setHighlight(0);
    }

    return true;
}

void Game::undoMove(){ //FINISHME
    //cover castling case
    //consists of moving rook and letting general case cover king movement
    if(this->getInitialPiece()->getIcon() == "images/white_king.png" || this->getInitialPiece()->getIcon() == "images/black_king.png"){
        if(this->getDestinationSquare()->second - this->getInitialSquare()->second == 2){
            this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second + 1))->setHasMoved(0);
            this->getSquare(std::make_pair(this->getInitialSquare()->first, 7))->setPiece(this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second + 1))->getPiece());
            this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second + 1))->setPiece(nullptr);
        }

        else if(this->getDestinationSquare()->second = this->getInitialSquare()->second == -2){
            this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second - 1))->setHasMoved(0);
            this->getSquare(std::make_pair(this->getInitialSquare()->first, 0))->setPiece(this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second - 1))->getPiece());
            this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second - 1))->setPiece(nullptr);
        }
    }
    //cover pawn special cases
    if(this->getInitialPiece()->getIcon() == "images/white_pawn.png" || this->getInitialPiece()->getIcon() == "images/black_pawn.png"){
        //cover en-passant case
        //consists of creating pawn behind destination sqaure of the opposite color and letting general case cover pawn movement
        if(this->getDestinationSquare()->second - this->getInitialSquare()->second != 1 && this->getSquare(*this->getDestinationSquare())->getPiece() == nullptr){
            if (this->getInitialPiece()->getColor()){
                WhitePieceFactory whiteFactory;
                this->getSquare(std::make_pair(this->getDestinationSquare()->first + 1, this->getDestinationSquare()->second))->setPiece(whiteFactory.DrawPawn(std::make_pair(this->getDestinationSquare()->first + 1, this->getDestinationSquare()->second), this));
                this->getSquare(std::make_pair(this->getDestinationSquare()->first + 1, this->getDestinationSquare()->second))->getPiece()->setHasMoved(1);
            }

            else{
                BlackPieceFactory blackFactory;
                this->getSquare(std::make_pair(this->getDestinationSquare()->first - 1, this->getDestinationSquare()->second))->setPiece(blackFactory.DrawPawn(std::make_pair(this->getDestinationSquare()->first - 1, this->getDestinationSquare()->second), this));
                this->getSquare(std::make_pair(this->getDestinationSquare()->first - 1, this->getDestinationSquare()->second))->getPiece()->setHasMoved(1);
            }
        }
        //cover pawn double move case
        //set pawn hasmoved variable to 0 then let general case handle pawn movement
        if(this->getDestinationSquare()->second - this->getInitialSquare()->second == 2 || this->getDestinationSquare()->second = this->getInitialSquare()->second == -2){
            this->getInitialPiece()->setHasMoved(0);
        }
    }

    //general case/pawn promotion case
    this->getSquare(*this->getInitialSquare())->setPiece(this->getInitialPiece());
    this->getSquare(*this->getDestinationSquare())->setPiece(this->getFinalPiece());
    this->setPlayerTurn(!this->getPlayerTurn());
}