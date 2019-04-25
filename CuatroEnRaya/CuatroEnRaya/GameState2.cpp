#include "GameState2.h"




GameState2::GameState2()
{


	window.create(sf::VideoMode(800, 630), "ES UN 4 EN RAYA", sf::Style::Close);
	// Activa la sincronización vertical (60 fps)
	background.setSize(sf::Vector2f(800, 630));
	background.setFillColor(sf::Color(138, 138, 138));

	overlay.setSize(sf::Vector2f(630, 630));
	overlay.setFillColor(sf::Color(150, 150, 150, 150));

	board.setSize(sf::Vector2f(630, 630));
	board.setFillColor(sf::Color(50, 50, 255));
	board.setOutlineColor(sf::Color::Black);
	board.setOutlineThickness(5);

	circle.setRadius(38);
	circle.setPointCount(300);
	circle.setOutlineThickness(-3);
	circle.setOutlineColor(sf::Color::Black);

	for (int i = 0; i < 49; i++)
		grid[i] = NONE;

}


GameState2::~GameState2()
{
}

int GameState2::
dropLocation(Tile * grid, int column)
{
	int i = 6;
	do
	{
		if (grid[column + 7 * i] == NONE)
			return column + 7 * i;
		i--;
	} while (i >= 0);

	return -1;
}

void GameState2::run()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				if (event.mouseButton.x < 630 && !gameOver)
				{
					tileDropped = true;
					column = event.mouseButton.x / 90;
				}
				
			}
		}

		//////////////////////////////////////////////////
		//////////////////////////////////////////////////

		if (tileDropped)
		{
			tileDropped = false;
			newTile = dropLocation(grid, column);
			if (newTile != -1)
			{
				grid[newTile] = static_cast<Tile>(2 - currentRed);
				currentRed = !currentRed;
				tileDropped = false;
				moveCounter++;

				if (moveCounter >= 49)
				{
					gameOver = true;
					winner = NONE;
				}
				
			}
		}

		//////////////////////////////////////////////////
		//////////////////////////////////////////////////

		window.clear();

		window.draw(background);
		window.draw(board);

		for (int i = 0; i < 49; i++)
		{
			circle.setPosition(7 + 90 * (i % 7), 7 + 90 * (i / 7));
			if (grid[i] == RED)
				circle.setFillColor(sf::Color::Red);
			else if (grid[i] == YELLOW)
				circle.setFillColor(sf::Color::Yellow);
			else
				circle.setFillColor(sf::Color(138, 138, 138));
			window.draw(circle);
		}

		if (sf::Mouse::getPosition(window).x < 630)
		{
			hoverTile = dropLocation(grid, sf::Mouse::getPosition(window).x / 90);
			if (hoverTile != -1)
			{
				circle.setPosition(7 + 90 * (hoverTile % 7), 7 + 90 * (hoverTile / 7));
				if (currentRed)
					circle.setFillColor(sf::Color::Red + sf::Color(0, 75, 75));
				else
					circle.setFillColor(sf::Color::Yellow + sf::Color(0, 0, 75));
				window.draw(circle);
			}
		}

		if (gameOver)
		{
			if (winner == RED)
			{
				overlay.setFillColor(sf::Color(255, 0, 0, 150));
				
			}
			else if (winner == YELLOW)
			{
				overlay.setFillColor(sf::Color(255, 255, 0, 150));
				
			}
			else
			{
				overlay.setFillColor(sf::Color(150, 150, 150, 150));
				
				
			}
			window.draw(overlay);
			
		}
		

		

		window.display();
	}
}