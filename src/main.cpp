#include <SFML/Graphics.hpp>

//#include "../header/menu.hpp"
#include "../header/menu_gui.hpp"
#include <iostream>




int main() {
  sf::RenderWindow window(sf::VideoMode(900, 900), "Chess Dot Com");
  
  
  
  MenuGui gui(window);

  return EXIT_SUCCESS;

}
