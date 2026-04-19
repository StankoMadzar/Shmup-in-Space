#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <map>
#include <vector>
#include "Player.h"
#include "Bullet.h"

class Game
{
private:
	sf::RenderWindow* window;

	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	Player* player;

	void initWindow();
	void initTextures();
	void initPlayer();
public:
	Game();
	~Game();

	void run();
	void updatePollEvents();
	void updateInput();
	void updateBullets();
	void update();
	void render();
};

