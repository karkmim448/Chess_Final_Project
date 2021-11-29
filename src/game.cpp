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
    std::string fileInput = "";  //stores piece codes from fin

    bool squareColor = true; //holds color of square, alternated whenever a square is created
    int fileRow, fileColumn; //used by fin to build pairs for undoMove variables
                             //fileRow is also used as the temp variable for player turn

    WhitePieceFactory whiteFactory; //white piece factory used to generate all white pieces
    BlackPieceFactory blackFactory; //black piece factory used to generate all black pieces

    //file name is either "../Save/Default.txt" or "../Save/Save.txt"
    fin.open(fileName);
    
    //iterates through each row in board
    for(int i = 0; i < 8; i++){
        //iterates through each column in each row of board
        for(int j = 0; j < 8; j++){
            //fin should be iterating through the 8x8 grid of pieces stored in Save
            fin >> fileInput;

            //check what color the piece is as well as if there is even a piece there
            if(fileInput.at(0) == '+'){ //white piece branch
                this->_board[i][j] = new Square(squareColor, this->pieceBuilder(fileInput, &whiteFactory));
            }

            else if(fileInput.at(0) == '-'){ //black piece branch
                this->_board[i][j] = new Square(squareColor, this->pieceBuilder(fileInput, &blackFactory));
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

    //read in initialSquare and set it
    fin >> fileRow;
    fin >> fileColumn;

    this->_initialSquare = &std::make_pair(fileRow, fileColumn);

    //read in destinationSquare and set it
    fin >> fileRow;
    fin >> fileColumn;

    this->_destinationSquare = &std::make_pair(fileRow, fileColumn);

    //read in intialPiece and set it
    fin >>fileInput;

    //repeat for loop logic, but only got through it once for undoMoveInitialPieceStorage
    if(fileInput.at(0) == '+'){ //white piece branch
        this->_initialPiece = this->pieceBuilder(fileInput, &whiteFactory);
    }

    else if(fileInput.at(0) == '-'){ //black piece branch
        this->_initialPiece = this->pieceBuilder(fileInput, &blackFactory);
    }

    else{ //empty square branch
        this->_initialPiece = nullptr;
    }

    //repeat for finalPiece
    fin >> fileInput;

    if(fileInput.at(0) == '+'){ //white piece branch
        this->_finalPiece = this->pieceBuilder(fileInput, &whiteFactory);
    }

    else if(fileInput.at(0) == '-'){ //black piece branch
        this->_finalPiece = this->pieceBuilder(fileInput, &blackFactory);
    }

    else{ //empty square branch
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

    fout.open("../Save/Save.txt"); //opens Save.txt

    //start by saving board state

    //outer for loop iterates through each row in board state
    for(int i = 0; i < 8; i++){
        //inner for loop iterates through each square in each row
        for(int j = 0; j < 8; j++){
            //output code for each square in row to output file
            fout << this->codeBuilder(this->getSquare(std::make_pair(i, j))->getPiece()) << ' ';
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
    fout << this->codeBuilder(this->getInitialPiece()) << std::endl;

    //store finalPiece using for loop logic
    fout << this->codeBuilder(this->getFinalPiece()) << std::endl;
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
                this->getSquare(std::make_pair(i, j))->setPiece(this->pieceBuilder(fileInput, &whiteFactory));
            }

            else if(fileInput.at(0) == '-'){//black piece branch
                this->getSquare(std::make_pair(i, j))->setPiece(this->pieceBuilder(fileInput, &blackFactory));
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
        this->setInitialPiece(this->pieceBuilder(fileInput, &whiteFactory));
    }

    else if(fileInput.at(0) == '-'){//black piece branch
        this->setInitialPiece(this->pieceBuilder(fileInput, &blackFactory));
    }

    else{ //empty square branch
        this->setInitialPiece(nullptr);
    }

    //use for loop logic to read in final piece
    fin >> fileInput;

    if(fileInput.at(0) == '+'){//white piece branch
        this->setFinalPiece(this->pieceBuilder(fileInput, &whiteFactory));
    }

    else if(fileInput.at(0) == '-'){//black piece branch
        this->setFinalPiece(this->pieceBuilder(fileInput, &blackFactory));
    }

    else{ //empty square branch
        this->setFinalPiece(nullptr);
    }
}

bool Game::selectPiece(std::pair<int, int> initialPosition){
    if(this->getPlayerTurn() != this->getSquare(initialPosition)->getPiece()->getColor()){
        return false;
    }

    this->getSquare(initialPosition)->getPiece()->updatePossibleMoves(initialPosition);

    std::vector<std::pair<int, int>>* possibleMoves = this->getSquare(initialPosition)->getPiece()->getPossibleMoves();

    for(int i = 0; i < possibleMoves->size(); i++){
        this->getSquare(possibleMoves->at(i))->setHighlight(1);
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
    
    //check pawn special cases
    if(this->getSquare(*initialPosition)->getPiece()->getIcon() == "images/white_pawn.png" || this->getSquare(*initialPosition)->getPiece()->getIcon() == "images/black_pawn.png"){
        //if pawn pawn is moving diagonally into an empty square, must be en-passant
        if(this->getSquare(*destinationSquare)->getPiece() == nullptr && destinationSquare->second - initialPosition->second != 0){
            enPassantPossible = true;
        }

        //if a pawn is moving in to the last row, must be a promotion
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

    //If the king is moving two square in the same row, it must be a castle
    else if(this->getSquare(*initialPosition)->getPiece()->getIcon() == "images/white_king.png" || this->getSquare(*initialPosition)->getPiece()->getIcon() == "images/black_king.png"){
        if(destinationSquare->second - initialPosition->second == 2 || destinationSquare->second - initialPosition->second == -2){
            castlingPossible = true;
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
        temp->promote(*destinationSquare);
    }

    //de-highlight highlighted squares
    std::vector<std::pair<int, int>>* possibleMoves = this->getInitialPiece()->getPossibleMoves();

    for(int i = 0; i < possibleMoves->size(); i++){
        this->getSquare(possibleMoves->at(i))->setHighlight(0);
    }

    return true;
}

void Game::undoMove(){ //FINISHME
    //cover castling case
    //consists of moving rook and letting general case cover king movement
    if(this->getInitialPiece()->getIcon() == "images/white_king.png" || this->getInitialPiece()->getIcon() == "images/black_king.png"){
        if(this->getDestinationSquare()->second - this->getInitialSquare()->second == 2){
            this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second + 1))->getPiece()->setHasMoved(0);
            this->getSquare(std::make_pair(this->getInitialSquare()->first, 7))->setPiece(this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second + 1))->getPiece());
            this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second + 1))->setPiece(nullptr);
        }

        else if(this->getDestinationSquare()->second = this->getInitialSquare()->second == -2){
            this->getSquare(std::make_pair(this->getInitialSquare()->first, this->getInitialSquare()->second - 1))->getPiece()->setHasMoved(0);
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
                this->getSquare(std::make_pair(this->getDestinationSquare()->first + 1, this->getDestinationSquare()->second))->setPiece(whiteFactory.DrawPawn(this));
                this->getSquare(std::make_pair(this->getDestinationSquare()->first + 1, this->getDestinationSquare()->second))->getPiece()->setHasMoved(1);
            }

            else{
                BlackPieceFactory blackFactory;
                this->getSquare(std::make_pair(this->getDestinationSquare()->first - 1, this->getDestinationSquare()->second))->setPiece(blackFactory.DrawPawn(this));
                this->getSquare(std::make_pair(this->getDestinationSquare()->first - 1, this->getDestinationSquare()->second))->getPiece()->setHasMoved(1);
            }
        }
        //cover pawn double move case
        //set pawn hasmoved variable to 0 then let general case handle pawn movement
        if((this->getDestinationSquare()->second - this->getInitialSquare()->second == 2) || (this->getDestinationSquare()->second = this->getInitialSquare()->second == -2)){
            this->getInitialPiece()->setHasMoved(0);
        }
    }

    //general case/pawn promotion case
    this->getSquare(*this->getInitialSquare())->setPiece(this->getInitialPiece());
    this->getSquare(*this->getDestinationSquare())->setPiece(this->getFinalPiece());
    this->setPlayerTurn(!this->getPlayerTurn());
}

piece* Game::pieceBuilder(std::string code, PieceFactory* factory){
    //check what piece is at this position, build the square using said piece
    piece* output;

    //check for empty piece
    if(code.at(0) == '0'){
        return nullptr;
    }
    //move to general case

    if(code.at(1) == 'p'){ //pawn branch
        output = factory->DrawPawn(this);
    }

    else if(code.at(1) == 'r'){ //rook branch
        output = factory->DrawRook(this);
    }

    else if(code.at(1) == 'h'){ //knight branch
        output =  factory->DrawRook(this);
    }

    else if(code.at(1) == 'b'){ //bishop branch
        output =  factory->DrawBishop(this);
    }

    else if(code.at(1) == 'q'){ //queen branch
        output =  factory->DrawQueen(this);
    }

    else if(code.at(1) == 'k'){ //king branch
        output =  factory->DrawKing(this);
    }

    if(code.at(2) == '1'){ //check if the piece has moved, if so update hasMoved for that piece
        output->setHasMoved(1);
    }

    return output;
}

std::string Game::codeBuilder(piece* input){
    std::string output = "";

    //check to see if empty piece has been passed through
    if(input == nullptr){
        return "0";
    }
    //move to general case

    //check color of piece, store in output
    if(input->getColor()){ //white piece branch
        output.append("+");
    }

    else{ //black piece branch
        output.append("-");
    }

    //check what piece input it, store in output
    if(input->getIcon() == "images/white_pawn.png" || input->getIcon() == "images/black_pawn.png"){ //pawn branch
        output.append("p");
    }

    else if(input->getIcon() == "images/white_rook.png" || input->getIcon() == "images/black_rook.png"){ //rook branch
        output.append("r");
    }

    else if(input->getIcon() == "images/white_knight.png" || input->getIcon() == "images/black_knight.png"){ //knight branch
        output.append("h");
    }

    else if(input->getIcon() == "images/white_bishop.png" || input->getIcon() == "images/black_bishop.png"){ //bishop branch
        output.append("b");
    }

    else if(input->getIcon() == "images/white_queen.png" || input->getIcon() == "images/black_queen.png"){ //queen branch
        output.append("q");
    }

    else{ //king branch
        output.append("k");
    }

    //check if piece has moved, store in output
    if(input->getHasMoved()){
        output.append("1");
    }

    else{
        output.append("0");
    }

    return output;
}