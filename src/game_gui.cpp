#include "../header/game_gui.hpp"
#include "../header/game.hpp"
#include <iostream>
#include <vector>




GameGui::GameGui(sf::RenderWindow &window, std::string fileName){
    //Game game("../Save/Default.txt");
    window.clear(sf::Color(0,0,0));
    Run(window, fileName);
}


/* BOARD LAYOUT
(0,0) → → → → +x
↓
↓
↓

+y

*/

void GameGui::drawBoard(sf::RenderWindow &window, sf::Texture &lightSquareTexture, sf::Texture &darkSquareTexture){
    for(int i = 0; i<8; ++i){
        for (int j = 0; j < 8; ++j){
            board[i][j].setTexture(lightSquareTexture);
            board[i][j].setPosition(100*i, 100*j);
            window.draw(board[i][j]);
            //window.display();
            ++j;
            board[i][j].setTexture(darkSquareTexture);
            board[i][j].setPosition(100*i, 100*j);
            window.draw(board[i][j]);
            //window.display();
        }
        ++i;
        for (int j = 0; j < 8; ++j){
            board[i][j].setTexture(darkSquareTexture);
            board[i][j].setPosition(100*i, 100*j);
            window.draw(board[i][j]);
            //window.display();
            ++j;
            board[i][j].setTexture(lightSquareTexture);
            board[i][j].setPosition(100*i, 100*j);
            window.draw(board[i][j]);
            //window.display();
        }
    }
}


//CHECK TYPE OF PIECE NOT JUST PUT WHEREVER
void GameGui::drawPieces(sf::RenderWindow &window, Game &game, std::vector<sf::Sprite> spriteVector1){

    for(int i = 0; i < 8; ++i){
            for(int j =0; j< 8; ++j){
                //std::cout << board[i][j].getPosition().x << ", " << board[i][j].getPosition().y << std::endl;
                std::pair<int, int> piecePair; piecePair = std::make_pair (j, i);
                if(game.getSquare(piecePair)->getPiece() == nullptr){

                }
                //game.getSquare(piecePair)->getPiece()->getIcon();
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_bishop.png"){
                    spriteVector1.at(9).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(9));
                }
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_king.png"){
                    spriteVector1.at(8).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(8));
                }
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_knight.png"){
                    spriteVector1.at(7).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(7));
                }
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_pawn.png"){
                    spriteVector1.at(6).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(6));
                }
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_queen.png"){
                    spriteVector1.at(11).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(11));
                }
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_rook.png"){
                    spriteVector1.at(10).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(10));
                }
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_bishop.png"){
                    spriteVector1.at(3).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(3));
                }
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_king.png"){
                    spriteVector1.at(2).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(2));
                }
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_knight.png"){
                    spriteVector1.at(1).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(1));
                }
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_pawn.png"){
                    spriteVector1.at(0).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(0));
                }
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_queen.png"){
                    spriteVector1.at(5).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(5));
                }
                else if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_rook.png"){
                    spriteVector1.at(4).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(4));
                }
                
            }
        }
}

std::pair<int, int> GameGui::movePiece(sf::RenderWindow &window, Game &game, std::pair<int, int> piecePair){
    while(window.isOpen()){
        for(int k = 0; k<8; ++k){
            for (int l = 0; l < 8; ++l){
                if(board[k][l].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        std::pair<int, int> piecePair1; piecePair1 = std::make_pair (l, k);
                        if(game.getSquare(piecePair1)->getHighlight() == true){
                            if (game.getSquare(piecePair1)->getPiece() != nullptr && game.getSquare(piecePair1)->getPiece()->getIcon() == "images/black_king.png"){
                                std::cout << "game over" << std::endl;
                                gameOver("white", window);
                                std::cout << "game over1" << std::endl;
                            }
                            else if (game.getSquare(piecePair1)->getPiece() != nullptr && game.getSquare(piecePair1)->getPiece()->getIcon() == "images/white_king.png"){
                                std::cout << "game over" << std::endl;
                                gameOver("black", window);
                                std::cout << "game over1" << std::endl;
                            }
                            game.movePiece(&piecePair, &piecePair1);
                            return piecePair1;
                        }
                    }
                }
            }
        }
    }
}

void GameGui::gameOver(std::string winner, sf::RenderWindow &window){
    sf::Texture whiteWonTexture;
    sf::Texture blackWonTexture;
    whiteWonTexture.loadFromFile("../src/misc/whiteWon.png");
    blackWonTexture.loadFromFile("../src/misc/blackWon.png");

    sf::Sprite whiteWon;
    sf::Sprite blackWon;
    whiteWon.setTexture(whiteWonTexture);
    whiteWon.setPosition(0,0);
    blackWon.setTexture(blackWonTexture);
    blackWon.setPosition(0,0);
    if(winner=="white"){
        window.clear();
        window.draw(whiteWon);
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));


        window.close();
    }
    else{
        window.clear();
        window.draw(blackWon);
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));


        window.close();
    }
}


void GameGui::Run(sf::RenderWindow &window, std::string fileName){
    Game game(fileName);
    window.clear();
    //loads all textures
    sf::Texture lightSquareTexture;
    sf::Texture darkSquareTexture;
    sf::Texture whitePawnTexture;
    sf::Texture whiteKnightTexture;
    sf::Texture whiteKingTexture;
    sf::Texture whiteBishopTexture;
    sf::Texture whiteRookTexture;
    sf::Texture whiteQueenTexture;
    sf::Texture blackPawnTexture;
    sf::Texture blackKnightTexture;
    sf::Texture blackKingTexture;
    sf::Texture blackBishopTexture;
    sf::Texture blackRookTexture;
    sf::Texture blackQueenTexture;
    sf::Texture loadButtonTexture;
    sf::Texture saveButtonTexture;
    sf::Texture undoButtonTexture;
    sf::Texture whiteTurnTexture;
    sf::Texture blackTurnTexture;
    sf::Texture blackSquareTexture;
    lightSquareTexture.loadFromFile("../src/pieces/images/light_square.png");
    darkSquareTexture.loadFromFile("../src/pieces/images/dark_square.png");
    whitePawnTexture.loadFromFile("../src/pieces/images/white_pawn.png");
    whiteKnightTexture.loadFromFile("../src/pieces/images/white_knight.png");
    whiteKingTexture.loadFromFile("../src/pieces/images/white_king.png");
    whiteBishopTexture.loadFromFile("../src/pieces/images/white_bishop.png");
    whiteRookTexture.loadFromFile("../src/pieces/images/white_rook.png");
    whiteQueenTexture.loadFromFile("../src/pieces/images/white_queen.png");
    blackPawnTexture.loadFromFile("../src/pieces/images/black_pawn.png");
    blackKnightTexture.loadFromFile("../src/pieces/images/black_knight.png");
    blackKingTexture.loadFromFile("../src/pieces/images/black_king.png");
    blackBishopTexture.loadFromFile("../src/pieces/images/black_bishop.png");
    blackRookTexture.loadFromFile("../src/pieces/images/black_rook.png");
    blackQueenTexture.loadFromFile("../src/pieces/images/black_queen.png");
    loadButtonTexture.loadFromFile("../src/misc/loadButton.png");
    saveButtonTexture.loadFromFile("../src/misc/saveButton.png");
    undoButtonTexture.loadFromFile("../src/misc/undoButton.png");
    whiteTurnTexture.loadFromFile("../src/misc/whiteTurn.png");
    blackTurnTexture.loadFromFile("../src/misc/blackTurn.png");
    blackSquareTexture.loadFromFile("../src/misc/blackSquare.png");

    std::vector<sf::Sprite> spriteVector;
    //creates piece sprites and gives them textures+pushes them onto vector for function
    sf::Sprite whitePawnSprite(whitePawnTexture);
    spriteVector.push_back(whitePawnSprite);    //0
    sf::Sprite whiteKnightSprite(whiteKnightTexture);
    spriteVector.push_back(whiteKnightSprite);  //1
    sf::Sprite whiteKingSprite(whiteKingTexture);
    spriteVector.push_back(whiteKingSprite);    //2
    sf::Sprite whiteBishopSprite(whiteBishopTexture);
    spriteVector.push_back(whiteBishopSprite);  //3
    sf::Sprite whiteRookSprite(whiteRookTexture);
    spriteVector.push_back(whiteRookSprite);    //4
    sf::Sprite whiteQueenSprite(whiteQueenTexture);
    spriteVector.push_back(whiteQueenSprite);   //5
    sf::Sprite blackPawnSprite(blackPawnTexture);
    spriteVector.push_back(blackPawnSprite);    //6
    sf::Sprite blackKnightSprite(blackKnightTexture);
    spriteVector.push_back(blackKnightSprite);  //7
    sf::Sprite blackKingSprite(blackKingTexture);
    spriteVector.push_back(blackKingSprite);    //8
    sf::Sprite blackBishopSprite(blackBishopTexture);
    spriteVector.push_back(blackBishopSprite);  //9
    sf::Sprite blackRookSprite(blackRookTexture);
    spriteVector.push_back(blackRookSprite);    //11
    sf::Sprite blackQueenSprite(blackQueenTexture);
    spriteVector.push_back(blackQueenSprite);   //12

    drawBoard(window, lightSquareTexture, darkSquareTexture);


    sf::Sprite loadButton;
    loadButton.setTexture(loadButtonTexture);
    loadButton.setPosition(0.0, 800.0);
    window.draw(loadButton);

    sf::Sprite saveButton;
    saveButton.setTexture(saveButtonTexture);
    saveButton.setPosition(200.0, 800.0);
    window.draw(saveButton);

    //sf::Sprite undoButton;
    //undoButton.setTexture(undoButtonTexture);
    //undoButton.setPosition(400.0, 800.0);
    //window.draw(saveButton);

    sf::Sprite blackSquare;
    blackSquare.setTexture(blackSquareTexture);
    blackSquare.setPosition(400.0, 800.0);
    window.draw(blackSquare);


    sf::Sprite turnButton;
    if(game.getPlayerTurn()){
        turnButton.setTexture(whiteTurnTexture);
    }
    else{
        turnButton.setTexture(blackTurnTexture);
    }
    turnButton.setPosition(600.0, 800.0);
    window.draw(turnButton);

    
    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                    window.close();
            }

            //mouse location output for testing
            //std::cout << "( " << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << ") " << std::endl;


            /*
            switch (event.type) {
                case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                    case sf::Keyboard::W:
                    std::cout << "W PRESSED" << std::endl;
                    board[3][4].setTexture(blackQueen);
                    window.draw(board[3][4]);
                    window.display();
                    break;
                }

            }*/
        }


        drawBoard(window, lightSquareTexture, darkSquareTexture);

        if(game.getPlayerTurn()){
            turnButton.setTexture(whiteTurnTexture);
        }
        else{
            turnButton.setTexture(blackTurnTexture);
        }
        window.draw(turnButton);

        window.draw(loadButton);
        window.draw(saveButton);
window.draw(blackSquare);

        


        //draw pieces
        drawPieces(window, game, spriteVector);


//std::cout << "( " << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << ") " << std::endl;

        //check if load pressed
        if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 200 && sf::Mouse::getPosition(window).y < 900 && sf::Mouse::getPosition(window).y > 800){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                game.load();
                drawPieces(window, game, spriteVector);
                std::cout << "Game Loaded" << std::endl;
            }
        }
        //check if save pressed
        if (sf::Mouse::getPosition(window).x > 200 && sf::Mouse::getPosition(window).x < 400 && sf::Mouse::getPosition(window).y < 900 && sf::Mouse::getPosition(window).y > 800){

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                game.save();
                std::cout << "Game Saved" << std::endl;

            }
        }

        //handle square clicking
        for(int i = 0; i<8; ++i){
            for (int j = 0; j < 8; ++j){
                if(board[i][j].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        std::pair<int, int> piecePair; piecePair = std::make_pair (j, i);
                        if(game.getSquare(piecePair)->getPiece() == nullptr){
                            std::cout << "EMPTY SQUARE"<<std::endl;
                        }
                        else if(game.getPlayerTurn() && game.getSquare(piecePair)->getPiece()->getColor()){    //white=true
                            std::cout << " (" << i << ", " << j << ") not yet selected" << std::endl;

                            game.selectPiece(piecePair);
                            std::cout << " (" << i << ", " << j << ") selected" << std::endl;
                            //TODO  highLightSquare
                            
                            std::pair<int, int> destPair; 
                            destPair = movePiece(window, game, piecePair);
                            
                            
                        }
                        else if(!game.getPlayerTurn() && !game.getSquare(piecePair)->getPiece()->getColor()){   // black=false
                            game.selectPiece(piecePair);
                            std::cout << " (" << i << ", " << j << ") selected" << std::endl;
                            //TODO  highLightSquare
                            std::pair<int, int> destPair; 
                            destPair = movePiece(window, game, piecePair);
                            
                        }
                        else{
                            std::cout << "Not your turn!" << std::endl;
                        }
                        
                    }
                }
            }
        }









        window.display();
    }
}
