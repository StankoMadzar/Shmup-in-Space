#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float moveSpeed;
	float attackCooldown;
	float attackCooldownMax;

	void initVariables();
	void initTexture();
	void initSprite();
public:
	Player();
	~Player();

	const sf::Vector2f& getPos();

	void move(const float dirX, const float dirY);
	bool canAttack();
	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};

