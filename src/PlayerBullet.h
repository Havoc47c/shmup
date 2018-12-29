#pragma once
#include "Bullet.h"

class PlayerBullet : public Bullet<sf::CircleShape> {
public:
	PlayerBullet(sf::Vector2f spawnPoint, float speed) : Bullet(sf::CircleShape(5, 9)) {
		this->shape.setFillColor(sf::Color(255, 255, 255));
		this->shape.setPosition(spawnPoint);
		this->velocity = {0, speed};
	}
};
