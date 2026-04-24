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

void Game::initGUI()
{
	if (!font.loadFromFile("Fonts/ARIAL.TTF"))
		std::cerr << "ERROR::GAME::Failed to load Arial font" << std::endl;

	pointText.setFont(font);
	pointText.setCharacterSize(12);
	pointText.setFillColor(sf::Color::White);
	pointText.setString("TEST");
}

void Game::initPlayer()
{
	player = new Player();
}

void Game::initEnemies()
{
	spawnTimerMax = 20.f;
	spawnTimer = spawnTimerMax;
}

Game::Game()
{
	initWindow();
	initTextures();
	initGUI();
	initPlayer();
	initEnemies();
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

	for (auto* i : this->enemies)
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
		bullets.push_back(
			new Bullet(this->textures["BULLET"], 
			player->getPos().x + player->getBounds().width / 4.f, 
			player->getPos().y, 0.f, -1.0f, 10.f)
		);
	}
}

void Game::updateGUI()
{
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

void Game::updateEnemies()
{
	// Spawning
	spawnTimer += 0.5f;
	if (spawnTimer >= spawnTimerMax)
	{
		enemies.push_back(new Enemy(rand() % window->getSize().x - 20.f, -100.f));
		spawnTimer = 0.f;
	}

	// Updating
	unsigned counter = 0;
	for (auto* enemy : enemies)
	{
		enemy->update();

		// Enemy culling at bottom of screen
		if (enemy->getBounds().top > window->getSize().y)
		{
			// Delete the Enemy
			delete enemies.at(counter);
			enemies.erase(enemies.begin() + counter);
			--counter;
			std::cout << enemies.size() << '\n';
		}

		++counter;
	}
}

void Game::updateCombat()
{
	for (int i = 0; i < enemies.size(); ++i)
	{
		bool enemyDeleted = false;
		for (size_t k = 0; k < bullets.size() && !enemyDeleted; k++)
		{
			if (enemies[i]->getBounds().intersects(bullets[k]->getBounds())) 
			{
				delete enemies[i];
				enemies.erase(enemies.begin() + i);

				delete bullets[k];
				bullets.erase(bullets.begin() + k);
				enemyDeleted = true;
			}
		}
	}
}

void Game::update()
{
	updatePollEvents();
	updateInput();
	player->update();
	updateBullets();
	updateEnemies();
	updateCombat();
	updateGUI();
}
void Game::renderGUI()
{
	window->draw(pointText);
}

void Game::render()
{
	window->clear();
	player->render(*window);
	for (auto& bullet : bullets)
	{
		bullet->render(window);
	}

	for (auto *enemy : enemies)
	{
		enemy->render(window);
	}

	renderGUI();

	window->display();
}
