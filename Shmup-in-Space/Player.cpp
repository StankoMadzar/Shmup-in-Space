#include "Player.h"

void Player::initTexture()
{
	if (!texture.loadFromFile("Textures/spaceship.png"))
	{
		std::cerr << "ERROR: Failure to load player texture" << std::endl;
	}
}

void Player::initSprite()
{
	sprite.setTexture(texture);
	sprite.scale(0.05f, 0.05f);
}

Player::Player()
{
	moveSpeed = 10.f;
	initTexture();
	initSprite();
}

Player::~Player()
{

}

void Player::move(const float dirX, const float dirY)
{
	sprite.move(moveSpeed * dirX, moveSpeed * dirY);
}

void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}