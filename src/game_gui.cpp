#include "../header/game_gui.hpp"
//#include "../header/game.hpp"
#include <iostream>



GameGui::GameGui(sf::RenderWindow &window){
    window.clear(sf::Color(0,0,0));
    Run(window);
}


/* BOARD LAYOUT
(0,0) → → → → +x
↓
↓
↓

+y

*/


void GameGui::Run(sf::RenderWindow &window){
    window.clear();
    //loads all textures
    sf::Texture lightSquare;
    sf::Texture darkSquare;
    sf::Texture whitePawn;
    sf::Texture whiteKnight;
    sf::Texture whiteKing;
    sf::Texture whiteBishop;
    sf::Texture whiteRook;
    sf::Texture whiteQueen;
    sf::Texture blackPawn;
    sf::Texture blackKnight;
    sf::Texture blackKing;
    sf::Texture blackBishop;
    sf::Texture blackRook;
    sf::Texture blackQueen;
    sf::Texture loadButtonTexture;
    sf::Texture saveButtonTexture;
    lightSquare.loadFromFile("../src/pieces/images/light_square.png");
    darkSquare.loadFromFile("../src/pieces/images/dark_square.png");
    whitePawn.loadFromFile("../src/pieces/images/white_pawn.png");
    whiteKnight.loadFromFile("../src/pieces/images/white_knight.png");
    whiteKing.loadFromFile("../src/pieces/images/white_king.png");
    whiteBishop.loadFromFile("../src/pieces/images/white_bishop.png");
    whiteRook.loadFromFile("../src/pieces/images/white_rook.png");
    whiteQueen.loadFromFile("../src/pieces/images/white_queen.png");
    blackPawn.loadFromFile("../src/pieces/images/black_pawn.png");
    blackKnight.loadFromFile("../src/pieces/images/black_knight.png");
    blackKing.loadFromFile("../src/pieces/images/black_king.png");
    blackBishop.loadFromFile("../src/pieces/images/black_bishop.png");
    blackRook.loadFromFile("../src/pieces/images/black_rook.png");
    blackQueen.loadFromFile("../src/pieces/images/black_queen.png");
    loadButtonTexture.loadFromFile("../src/misc/loadButton.png");
    saveButtonTexture.loadFromFile("../src/misc/saveButton.png");



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
/*
        Game game("../Save/Default");
        std::pair<int, int> testSquare;
        testSquare.first = 1;
        testSquare.second = 1;
        game.getSquare(testSquare)->getColor();
*/
        //draw board
        //i is collumn, j is row ( for game.cpp pairs )
        for(int i = 0; i<8; ++i){
            for (int j = 0; j < 8; ++j){
                board[i][j].setTexture(lightSquare);
                board[i][j].setPosition(100*i, 100*j);
                window.draw(board[i][j]);
                //window.display();
                ++j;
                board[i][j].setTexture(darkSquare);
                board[i][j].setPosition(100*i, 100*j);
                window.draw(board[i][j]);
                //window.display();
            }
            ++i;

            for (int j = 0; j < 8; ++j){
    	        board[i][j].setTexture(darkSquare);
    	        board[i][j].setPosition(100*i, 100*j);
    	        window.draw(board[i][j]);
    	        //window.display();
    	        ++j;
    	        board[i][j].setTexture(lightSquare);
    	        board[i][j].setPosition(100*i, 100*j);
    	        window.draw(board[i][j]);
    	        //window.display();
            }
        }

        sf::Sprite loadButton;
        loadButton.setTexture(loadButtonTexture);
        loadButton.setPosition(0.0, 800.0);
        window.draw(loadButton);

        sf::Sprite saveButton;
        saveButton.setTexture(saveButtonTexture);
        saveButton.setPosition(200.0, 800.0);
        window.draw(saveButton);



//std::cout << "( " << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << ") " << std::endl;
        
        //check if load pressed
        if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 200 && sf::Mouse::getPosition(window).y < 900 && sf::Mouse::getPosition(window).y > 800){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                std::cout << "load pressed" << std::endl;
                //game.load();
            }
        }
        //check if save pressed
        if (sf::Mouse::getPosition(window).x > 200 && sf::Mouse::getPosition(window).x < 400 && sf::Mouse::getPosition(window).y < 900 && sf::Mouse::getPosition(window).y > 800){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                std::cout << "save pressed" << std::endl;
                //game.save();
            }
        }

        //handle square clicking
        for(int i = 0; i<8; ++i){
            for (int j = 0; j < 8; ++j){
                if(board[i][j].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        std::cout << i << ", " << j << std::endl;
                    }
                }
            }
        }







        window.display();
    }
}
