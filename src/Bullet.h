#pragma once
#include "Object.h"
#include "GameWindow.h"
#include "SFML/Graphics.hpp"

class Ship;

class Bullet : public Object {
using Object::Object;
public:
	
	bool AliveTickInternal(const sf::RenderWindow& window) const override;

	virtual void Hit(Ship* hitShip);

	virtual CollisionType GetCollisionType() const override
	{ return CollisionType::Bullet; }

	virtual void Collide(Object* other, CollisionType type) override;

	int hitDamage = 1;
};
