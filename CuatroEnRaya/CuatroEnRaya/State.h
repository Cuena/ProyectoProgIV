#pragma once

#include<vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"

class State
{
private:



public:sf::RenderWindow* window;
	   std::vector<sf::Texture> textures;
	   bool quit;
	   State(sf::RenderWindow* window);
	   virtual ~State();

	   const bool& getQuit() const;
	   virtual void checkForQuit();
	   virtual void endState() = 0;

	   //pure virtual function: abstract en java
	   virtual void updateInput(const float& dt) = 0;
	   virtual void update(const float& dt) = 0;
	   virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

