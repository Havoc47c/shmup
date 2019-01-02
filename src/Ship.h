#pragma once

#include "Object.h"
#include "Collision.h"

class Ship : public Object {
using Object::Object;
public:
	virtual bool AliveTickInternal(const sf::RenderWindow& window) const override;

	virtual CollisionType GetCollisionType() const override 
	{ return CollisionType::Ship; }
	virtual void Collide(Object* other, CollisionType otherType) override;

	virtual void Damage(int damage);

	// Without health the ship dies immediately.
	float health = 1;
	// Scalar unit in pixels per second.
	float speed;
};	

