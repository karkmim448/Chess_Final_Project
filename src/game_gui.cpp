#include "../header/game_gui.hpp"
#include "../header/game.hpp"
#include <iostream>
#include <vector>



GameGui::GameGui(sf::RenderWindow &window, Game &game){
    window.clear(sf::Color(0,0,0));
    Run(window, game);
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
                std::pair<int, int> piecePair; piecePair = std::make_pair (i, j);
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_bishop.png"){
                    spriteVector1.at(9).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(9));
                }
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_king.png"){
                    spriteVector1.at(8).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(8));
                }
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_knight.png"){
                    spriteVector1.at(7).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(7));
                }
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_pawn.png"){
                    spriteVector1.at(6).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(6));
                }
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_queen.png"){
                    spriteVector1.at(11).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(11));
                }
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/black_rook.png"){
                    spriteVector1.at(10).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(10));
                }
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_bishop.png"){
                    spriteVector1.at(3).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(3));
                }
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_king.png"){
                    spriteVector1.at(2).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(2));
                }
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_knight.png"){
                    spriteVector1.at(1).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(1));
                }
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_pawn.png"){
                    spriteVector1.at(0).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(0));
                }
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_queen.png"){
                    spriteVector1.at(5).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(5));
                }
                if(game.getSquare(piecePair)->getPiece()->getIcon() == "images/white_rook.png"){
                    spriteVector1.at(4).setPosition(100*i, 100*j);
                    window.draw(spriteVector1.at(4));
                }
                if(game.getSquare(piecePair) == nullptr){

                }
            }
        }
}

void GameGui::Run(sf::RenderWindow &window, Game &game){
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



        sf::Sprite loadButton;
        loadButton.setTexture(loadButtonTexture);
        loadButton.setPosition(0.0, 800.0);
        window.draw(loadButton);

        sf::Sprite saveButton;
        saveButton.setTexture(saveButtonTexture);
        saveButton.setPosition(200.0, 800.0);
        window.draw(saveButton);

        sf::Sprite undoButton;
        undoButton.setTexture(undoButtonTexture);
        undoButton.setPosition(400.0, 800.0);
        window.draw(saveButton);

        sf::Sprite turnButton;
        turnButton.setTexture(whiteTurnTexture);
        turnButton.setPosition(600.0, 800.0);
        window.draw(turnButton);


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
                        game.selectPiece(piecePair);
                        std::cout << " (" << i << ", " << j << ") selected" << std::endl;
                    }
                }
            }
        }







        window.display();
    }
}
