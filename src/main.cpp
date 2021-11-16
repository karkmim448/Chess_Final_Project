#include <../SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Testing SFML");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while(window.isOpen()){
        sfEvent event;

	while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
