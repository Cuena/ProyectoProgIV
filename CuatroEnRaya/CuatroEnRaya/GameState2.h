#pragma once


#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include "Juego76.h"



class GameState2
{
public:
	GameState2();
	virtual ~GameState2();
	
	enum Tile { NONE, RED, YELLOW };

	sf::ContextSettings settings;
	sf::RenderWindow window;
	sf::Font font;
	sf::RectangleShape background;
	sf::RectangleShape overlay;
	sf::RectangleShape board;
	sf::CircleShape circle;

	bool gameOver = false, tileDropped = false, currentRed = true;
	int column = 0, newTile = 0, hoverTile = 0, moveCounter = 0;
	Tile winner = NONE;

	Tile grid[49];
	
	int dropLocation(Tile *grid, int column);


	void run();
};

