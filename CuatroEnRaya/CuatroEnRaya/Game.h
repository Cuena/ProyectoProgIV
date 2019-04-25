#ifndef GAME_H
#define GAME_H


#include "MainMenuState.h"
class Game
{

private:
	//variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	//todos los estados: menu, juego, opciones...
	std::stack<State*> states;


	//initialization
	void initWindow();
	void initStates();

public:

	//constructor/destructor
	Game();
	virtual ~Game();

	//Functions

	//regular 
	void endApplication();
	//update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//render
	void render();
	//core
	void run();





};

#endif
