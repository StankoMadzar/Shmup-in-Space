#include "Player.h"

void Player::initVariables()
{
	moveSpeed = 10.f;
	attackCooldownMax = 10.0f;
	attackCooldown = attackCooldownMax;
}

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
	initVariables();
	initTexture();
	initSprite();
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos()
{
	return sprite.getPosition();
}

void Player::move(const float dirX, const float dirY)
{
	sprite.move(moveSpeed * dirX, moveSpeed * dirY);
}

bool Player::canAttack()
{
	if (attackCooldown > attackCooldownMax)
	{
		attackCooldown = 0.f;
		return true;
	}

	return false;
}

void Player::updateAttack()
{
	if(attackCooldown <= attackCooldownMax)
		attackCooldown += 1.f;
}

void Player::update()
{
	updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}