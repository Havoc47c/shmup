#pragma once
#include "Bullet.h"

class PlayerBullet : public Bullet<sf::CircleShape> {
public:
	PlayerBullet(sf::Vector2f spawnPoint, float speed) {
		this->shape = sf::CircleShape(1, 3);
		this->shape.setPosition(sf::Vector2f(GameWindow::Size()));
		this->shape.setFillColor(sf::Color(255, 255, 255));
		this->shape.setPosition(spawnPoint);
		this->velocity = {0, speed};
	}
};
