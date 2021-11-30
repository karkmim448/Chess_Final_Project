#include "../header/menu_gui.hpp"
#include "../header/game_gui.hpp"
#include "../header/game.hpp"

#include "SFML/Graphics.hpp"
#include <iostream>

MenuGui::MenuGui(sf::RenderWindow &window){
	window.clear();
    Run(window);

}


void MenuGui::Run(sf::RenderWindow &window){
  
    //menu screen
    Menu menu(window.getSize().x,window.getSize().y);
    while(window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event))
        {
          switch (event.type)
          {
            case sf::Event::KeyReleased:
            switch (event.key.code)
            {
              case sf::Keyboard::Up:
              menu.MoveUp();
              break;

              case sf::Keyboard::Down:
              menu.MoveDown();
              break;

              case sf::Keyboard::Return:
              switch (menu.GetPressedItem())
              {
                case 0:{
                std::cout << "Play button has been pressed" << std::endl;
                window.clear();
                Game game("../Save/Default.txt");
                GameGui gameGui(window, game);
                break;
                }
                case 1:
                std::cout << "Load button has been pressed" << std::endl;
                break;
                case 2:
                window.close();
                break;
              }

              break;
            }

            break;

            case sf::Event::Closed:
            window.close();
            break;

          }
        }
        //end menu screen



        window.clear();
        sf::Texture menuBack;
        menuBack.loadFromFile("../src/misc/menuback.jpeg");
        sf::Sprite menubackground;
        menubackground.setTexture(menuBack);
        window.draw(menubackground);
        menu.draw(window);
    
    
	    window.display();
    }
}
