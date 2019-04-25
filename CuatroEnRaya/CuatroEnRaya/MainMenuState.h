#pragma once
#include "GameState.h"

class MainMenuState :
	public State
{
private:
	//variables
	sf::RectangleShape background;
	sf::Text title, tPlay,t2,t3;
	sf::Font font;
	sf::Event evento;
	sf::Sprite arrowSprite;
	sf::Texture arrowTexture;

	//functions


public:
	MainMenuState(sf::RenderWindow* window);
	virtual ~MainMenuState();

	//Functions
	void endState();

	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};

