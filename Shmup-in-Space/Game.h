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

	sf::Font font;
	sf::Text pointText;

	Player* player;

	void initWindow();
	void initTextures();
	void initGUI();
	void initPlayer();
	void initEnemies();
public:
	Game();
	~Game();

	void run();
	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateBullets();
	void updateEnemiesAndCombat();
	void update();
	void renderGUI();
	void render();
};

