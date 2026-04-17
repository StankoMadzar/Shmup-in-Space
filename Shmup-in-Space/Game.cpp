#include "Game.h"

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Schmup in Space", sf::Style::Close | sf::Style::Titlebar);
}

Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete window;
}

void Game::run()
{
	while (window->isOpen())
	{
		update();
		render();
	}
}

void Game::update()
{

}

void Game::render()
{
	window->clear();
	window->display();
}
