#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Enemy
{
private:
	sf::CircleShape shape;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initShape();
	void initVariables();
public:
	Enemy(float posX, float posY);
	~Enemy();

	sf::FloatRect getBounds();
	void update();
	void render(sf::RenderTarget* target);
};

