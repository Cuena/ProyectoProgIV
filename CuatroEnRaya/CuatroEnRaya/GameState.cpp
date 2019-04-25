#include "GameState.h"



GameState::GameState(sf::RenderWindow* window) //...window, std::map<std::string,int>* supportedKeys
	: State(window)
{

}


GameState::~GameState()
{
}



void GameState::endState()
{
	std::cout << "Ending game state" << "\n";
}

void GameState::updateInput(const float & dt)
{
	this->checkForQuit();
}

void GameState::update(const float& dt)
{
	this->updateInput(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A" << "\n";
}

void GameState::render(sf::RenderTarget* target)
{
}
