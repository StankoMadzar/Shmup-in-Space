#pragma once
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

class Game
{
private:
	sf::RenderWindow* window;

	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	Player* player;

	void initWindow();
	void initTextures();
	void initPlayer();
	void initEnemies();
public:
	Game();
	~Game();

	void run();
	void updatePollEvents();
	void updateInput();
	void updateBullets();
	void updateEnemies();
	void update();
	void render();
};

