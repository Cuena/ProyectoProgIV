#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>



int main()
{
	// Make a window that is 800 by 200 pixels
	// And has the title "Hello from SFML"
	sf::RenderWindow window(sf::VideoMode(900, 600), "Hello from SFML");

	// Create a "Text" object called "message". Weird but we will learn about objects soon
	sf::Text message;

	// We need to choose a font
	sf::Font font;
	font.loadFromFile("Recursos/SaucerBB.ttf");

	// Set the font to our message
	message.setFont(font);

	// Assign the actual message
	message.setString("4 EN RAYA OMG!");

	// Make it really big
	message.setCharacterSize(100);

	// Choose a color
	message.setFillColor(sf::Color::White);

	// This "while" loop goes round and round- perhaps forever
	while (window.isOpen())
	{
		// The next 6 lines of code detect if the window is closed
		// And then shuts down the program
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				// Someone closed the window- bye
				window.close();
		}

		// Clear everything from the last run of the while loop
		window.clear();

		// Draw our message
		window.draw(message);

		// Draw our game scene here
		// Just a message for now

	printf("ey que pasa\n");
	printf("SKERE");

	return 0;
}
