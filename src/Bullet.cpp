#include "Bullet.h"

bool Bullet::Alive(const sf::RenderWindow& window) const {
	return GameWindow::WithinWindowBounds(this->shape->getGlobalBounds());
}
