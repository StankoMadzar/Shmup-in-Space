#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Player.h"

class Game
{
private:
	sf::RenderWindow* window;

	Player* player;

	void initWindow();
	void initPlayer();
public:
	Game();
	~Game();

	void run();
	void updatePollEvents();
	void updateInput();
	void update();
	void render();
};

