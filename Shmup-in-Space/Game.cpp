#include "Game.h"

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Schmup in Space", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
	player = new Player();
}

Game::Game()
{
	initWindow();
	initPlayer();
}

Game::~Game()
{
	delete window;
	delete player;
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
	sf::Event e;
	while (window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			window->close();
	}

	// Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		player->move(-1.0f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		player->move(1.0f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		player->move(0.0f, -1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		player->move(0.0f, 1.0f);
}

void Game::render()
{
	window->clear();
	player->render(*window);
	window->display();
}
