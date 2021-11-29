#include <SFML/Graphics.hpp>
#include "../header/menu_gui.hpp"
#include <iostream>




int main(int argc, char ** argv) {
  sf::RenderWindow window(sf::VideoMode(800, 900), "Chess Dot Com");
  window.setFramerateLimit(30);     //increasing too much will lead to high cpu usage, 30 fps should be more than enough




  MenuGui gui(window);

  return EXIT_SUCCESS;

}
