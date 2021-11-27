
#include "../header/menuState.hpp"
//#include "../header/gameState.hpp"
#include <iostream>


MenuState::MenuState(GameDataRef data): _data(data){}


void MenuState::init(){

    if (!font.loadFromFile("../src/misc/OpenSans-Regular.ttf"))
	{
        std::cout << "FONT LOAD ERROR"<< std::endl;
	}
    
    
    menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setOutlineThickness(10);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(this->_data->window.getSize().x / 2, this->_data->window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
    menu[1].setOutlineThickness(10);
	menu[1].setString("Load");
	menu[1].setPosition(sf::Vector2f(this->_data->window.getSize().x / 2, this->_data->window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
    menu[2].setOutlineThickness(10);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(this->_data->window.getSize().x / 2, this->_data->window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;

    
}

void MenuState::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MenuState::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MenuState::handleInput(){
    sf::Event event;

    while(this->_data->window.pollEvent(event)){    //might want to replace pollEvent with waitEvent
        
        /*if (sf::Event::Closed == event.type){
			this->_data->window.close();
		}
        else if(sf::Keyboard::Up == event.type){

        }*/     //replacing with switch/case

        switch(event.type){
            case sf::Event::KeyReleased:
            switch(event.key.code){
                case sf::Keyboard::Up:
                MoveUp();
                break;
          
                case sf::Keyboard::Down:
                MoveDown();
                break;

                case sf::Keyboard::Return:
                switch(GetPressedItem()){
                    case 0:
                    //ToDo:     load new game
                    std::cout << "Play button has been pressed" << std::endl;
                    this->_data->window.clear();
                    break;
                    
                    case 1:
                    //ToDo:     load from saved game
                    std::cout << "Load button has been pressed" << std::endl;
                    break;

                    case 2:
                    this->_data->window.close();
                    break;
                }
                break;
            }
            break;

            case sf::Event::Closed:
            this->_data->window.close();
            break;
        }

    }

}
void MenuState::update(float dt){

}
void MenuState::Draw(float dt){
    this->_data->window.clear();
    sf::Texture menuBack;
    menuBack.loadFromFile("../src/misc/menuback.jpeg");
    sf::Sprite menuBackground;
    menuBackground.setTexture(menuBack);
    this->_data->window.draw(menuBackground);
    
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		this->_data->window.draw(menu[i]);
	}



    this->_data->window.display();
}