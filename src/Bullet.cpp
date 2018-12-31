#include "Bullet.h"

bool Bullet::AliveTickInternal(const sf::RenderWindow& window) const {
	return GameWindow::WithinWindowBounds(this->shape->getGlobalBounds());
}
