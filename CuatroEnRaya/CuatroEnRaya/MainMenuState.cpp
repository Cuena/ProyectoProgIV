#include "MainMenuState.h"
#include "Utils.h"
#include <string>



MainMenuState::MainMenuState(sf::RenderWindow* window) //...window, std::map<std::string,int>* supportedKeys
	: State(window)
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Blue);
	this->title.setString("4 EN RAYA OMG!");
	this->font.loadFromFile("Recursos/SaucerBB.ttf");

	title.setFont(font);
	title.setCharacterSize(100);
	title.setFillColor(sf::Color::White);
	
	this->tPlay.setString("PLAY");

	tPlay.setFont(font);
	tPlay.setCharacterSize(40);
	tPlay.setFillColor(sf::Color::White);

	
	tPlay.setPosition(window->getSize().x/2 - 50, window->getSize().y/4);

	this->t2.setString("text2");

	t2.setFont(font);
	t2.setCharacterSize(40);
	t2.setFillColor(sf::Color::White);


	t2.setPosition(window->getSize().x / 2 - 70, window->getSize().y / 2-65);

	this->t3.setString("text3");

	t3.setFont(font);
	t3.setCharacterSize(40);
	t3.setFillColor(sf::Color::White);


	t3.setPosition(window->getSize().x / 2 - 70, 3*window->getSize().y / 4-120);

	arrowTexture.loadFromFile("C:\\Users\\kikel\\source\\repos\\ProyectoProgIV\\CuatroEnRaya\\Recursos\\arrow2.png");

	arrowSprite.setTexture(arrowTexture);

	arrowSprite.setPosition(tPlay.getPosition().x-200,tPlay.getPosition().y-20);

	

}


MainMenuState::~MainMenuState()
{
}



void MainMenuState::endState()
{
	std::cout << "Ending game state" << "\n";
}

void MainMenuState::updateInput(const float & dt)
{
	this->checkForQuit();
}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A" << "\n";

	//sf::Vector2i mousePosition = sf::Mouse.getPosition();
	
	sf::IntRect rect(tPlay.getPosition().x, tPlay.getPosition().y, tPlay.getGlobalBounds().width, tPlay.getGlobalBounds().height);
	
	if (rect.contains(sf::Mouse::getPosition(*window)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
		
		std::cout<< "PLAY ";
	}
	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		std::cout << "F" << "\n";
	
	
	
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	target->draw(title);
	target->draw(tPlay);
	target->draw(t2);
	target->draw(t3);
	target->draw(arrowSprite);


}