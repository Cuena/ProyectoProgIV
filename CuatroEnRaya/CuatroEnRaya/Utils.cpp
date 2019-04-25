#include "Utils.h"



Utils::Utils()
{
}


Utils::~Utils()
{
}

void Utils::ey(sf::Text text)
{
	sf::Font font;
	font.loadFromFile("Recursos/SaucerBB.ttf");

	text.setFont(font);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::White);
}


