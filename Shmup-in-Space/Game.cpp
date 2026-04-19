#include "Game.h"

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Schmup in Space", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	textures["BULLET"] = new sf::Texture();
	textures["BULLET"]->loadFromFile("Textures/Bullet.png");
}

void Game::initPlayer()
{
	player = new Player();
}

Game::Game()
{
	initWindow();
	initTextures();
	initPlayer();
}

Game::~Game()
{
	delete window;
	delete player;

	for (auto &i : textures)
	{
		delete i.second;
	}

	for (auto* i : this->bullets)
	{
		delete i;
	}
}

void Game::run()
{
	while (window->isOpen())
	{
		update();
		render();
	}
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			window->close();
	}
}

void Game::updateInput()
{
	// Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		player->move(-1.0f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		player->move(1.0f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		player->move(0.0f, -1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		player->move(0.0f, 1.0f);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		bullets.push_back(new Bullet(this->textures["BULLET"], 100.f, 100.f, 0.f, 0.f, 0.f));
	}
}

void Game::updateBullets()
{
	for (auto& bullet : bullets)
	{
		bullet->update();
	}
}

void Game::update()
{
	updatePollEvents();
	updateInput();
	updateBullets();
}

void Game::render()
{
	window->clear();
	player->render(*window);
	for (auto& bullet : bullets)
	{
		bullet->render(window);
	}
	window->display();
}
