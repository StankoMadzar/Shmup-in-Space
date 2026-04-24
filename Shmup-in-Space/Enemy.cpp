#include "Enemy.h"

void Enemy::initShape()
{
	shape.setRadius(rand()%20+20);
	shape.setPointCount(rand() % 20 + 3);
	shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}

void Enemy::initVariables()
{
	type = 0;
	speed = 2.0f;
	hpMax = 10;
	hp = 0;
	damage = 1;
	points = 5;
}

Enemy::Enemy(float posX, float posY)
{
	initShape();
	initVariables();
	shape.setPosition(posX, posY);
}

Enemy::~Enemy()
{

}

sf::FloatRect Enemy::getBounds()
{
	return shape.getGlobalBounds();
}

void Enemy::update()
{
	shape.move(0.f, speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(shape);
}