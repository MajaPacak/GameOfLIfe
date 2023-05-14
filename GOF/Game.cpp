#include "Game.h"


Game::Game(sf::RenderWindow* window)
{
	this->window = window;
}

void Game::set_grid()
{
	//works without srand but just in case
	srand(time(nullptr));
	sf::Vector2f rectangleSize(10.0f, 10.0f);
	sf::Vector2f rectanglePosition(x, y);
	for (int i = 0; i < (Width / 10); i++) {
		rectanglePosition.y = 1;
		vector<sf::RectangleShape> v1;
		for (int j = 0; j < (Height / 10); j++) {
			rectangle.setSize(rectangleSize);
			int r = rand() % 2;
			//use counter to reduce number of black
			if (r == 0) {
				rectangle.setFillColor(sf::Color::Black);

			}
			else {
				rectangle.setFillColor(sf::Color::White);

			}

			rectangle.setPosition(rectanglePosition);
			rectanglePosition.y += 10;
			v1.push_back(rectangle);
		}
		grid.push_back(v1);
		rectanglePosition.x += 10;
	}

}

void Game::draw_grid()
{

	set_grid();

	for (int i = 1; i < ((Width / 10) - 1) - 1; i++) {
		for (int j = 1; j < ((Height / 10) - 1); j++) {
			int isAlive = 0;
			if (grid[i - 1][j - 1].getFillColor() == sf::Color::White) {
				isAlive++;
			}
			if (grid[i - 1][j].getFillColor() == sf::Color::White) {
				isAlive++;
			}
			if (grid[i - 1][j + 1].getFillColor() == sf::Color::White) {
				isAlive++;
			}
			if (grid[i][j - 1].getFillColor() == sf::Color::White) {
				isAlive++;
			}
			if (grid[i][j + 1].getFillColor() == sf::Color::White) {
				isAlive++;
			}
			if (grid[i + 1][j - 1].getFillColor() == sf::Color::White) {
				isAlive++;
			}
			if (grid[i + 1][j].getFillColor() == sf::Color::White) {
				isAlive++;
			}
			if (grid[i + 1][j + 1].getFillColor() == sf::Color::White) {
				isAlive++;
			}
			if (grid[i][j].getFillColor() == sf::Color::White && isAlive > 3) {
				grid[i][j].setFillColor(sf::Color::Black);
			}
			if (grid[i][j].getFillColor() == sf::Color::Black && isAlive == 3) {
				grid[i][j].setFillColor(sf::Color::White);
			}
			if (grid[i][j].getFillColor() == sf::Color::White && isAlive < 2) {
				grid[i][j].setFillColor(sf::Color::Black);
			}
			window->draw(grid[i][j]);
		}
	}
}

void Game::draw()
{



	draw_grid();



}
