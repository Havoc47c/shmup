#pragma once
#include "Bullet.h"

#include "ShapeFactory.h"

class PlayerBullet : public Bullet {
public:
	PlayerBullet(sf::Vector2f spawnPoint, float speed) : Bullet(factory::shape::PlayerBullet(), Team0) {
		this->setPosition(spawnPoint);
		this->velocity = {0, speed};
	}
};
