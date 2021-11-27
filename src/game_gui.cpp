#include <SFML/Graphics.hpp>
#include "../header/game_gui.hpp"
#include "../header/menuState.hpp"



GameGUI::GameGUI(int width, int height, std::string title){
    _data->window.create(sf::VideoMode(width, height), title);
    _data->machine.addState(StateRef(new MenuState(this->_data)));

    this->Run();
}

/*
void GameGUI::Run(){
    while(this->_data->window.isOpen()){
        this->_data->machine.processStateChanges();

    }
}
*/



void GameGUI::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.processStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.getActiveState()->handleInput();
				this->_data->machine.getActiveState()->update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.getActiveState()->Draw(interpolation);
		}
	}
