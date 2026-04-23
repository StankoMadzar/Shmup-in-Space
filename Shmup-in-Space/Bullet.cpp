#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed)
{
	shape.setTexture(*texture);
	shape.setPosition(posX, posY);
	direction.x = dirX;
	direction.y = dirY;
	this->movementSpeed = movementSpeed;
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
	return shape.getGlobalBounds();
}

void Bullet::update()
{
	shape.move(movementSpeed * direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(shape);
}
