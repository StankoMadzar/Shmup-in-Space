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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && player->canAttack())
	{
		bullets.push_back(new Bullet(this->textures["BULLET"], player->getPos().x, player->getPos().y, 0.f, -1.0f, 10.f));
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto *bullet : bullets)
	{
		bullet->update();

		// Bullet culling at top of screen
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			// Delete the bullet
			delete bullets.at(counter);
			bullets.erase(bullets.begin() + counter);
			--counter;
			std::cout << bullets.size() << '\n';
		}

		++counter;
	}
}

void Game::update()
{
	updatePollEvents();
	updateInput();
	player->update();
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
