#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include "Game.h"

using namespace std;


int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game of life");
	window.setFramerateLimit(60);

	Game game(&window);
	sf::Clock clock;


	while (window.isOpen())
	{
		sf::Time elapsed = clock.getElapsedTime();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();


		}

		if (elapsed.asSeconds() >= 2) {
			window.clear();
			game.draw();
			window.display();
			clock.restart();
		}

	}


	return 0;
}