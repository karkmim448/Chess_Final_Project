#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 900), "Chess Dot Com");

  
    sf::Texture lightSquare;
    sf::Texture darkSquare;
    lightSquare.loadFromFile("../src/pieces/images/light_square.png");  // "../src" needed to make cmake work for some reason idfk, doesnt work otherwise
    darkSquare.loadFromFile("../src/pieces/images/dark_square.png");

    while(window.isOpen()){
	    sf::Event event;
    
	    while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                    window.close();
                }
        }


        sf::Sprite board[8][8];
        
        window.clear();
        


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


/*
            lightSquare.loadFromFile("pieces/images/light_square.png");
            sf::Sprite firstSquare;
            firstSquare.setTexture(lightSquare);
*/

            
            //window.draw(firstSquare);
            window.display();
        }

    return 0;
}
