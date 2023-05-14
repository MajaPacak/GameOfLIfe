#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class Game
{
private:
	sf::RenderWindow* window;
	const int Width = 800;
	const int Height = 600;
	int x = 0;
	int y = 0;
	int counter = 0;
	sf::RectangleShape rectangle;
	vector<vector<sf::RectangleShape>> grid;
	vector<sf::RectangleShape> v1;
	sf::Clock clock;

public:
	Game(sf::RenderWindow* window);
	void set_grid();
	void draw_grid();
	void draw();



};


