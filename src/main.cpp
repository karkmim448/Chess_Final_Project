#include <SFML/Graphics.hpp>
#include "../header/menu_gui.hpp"
#include "../header/game.hpp"
#include <iostream>




int main(int argc, char ** argv) {

  sf::RenderWindow window(sf::VideoMode(800, 900), "Chess Dot Com");
  window.setFramerateLimit(15);     //increasing too much will lead to high cpu usage and other issues, 15 fps should be good, further testing may be required




  MenuGui gui(window);

  return EXIT_SUCCESS;

}
