#pragma once

#include "Object.h"

#include "Collision.h"
#include "InterleavedPassiveEvent.h"

class Ship : public Object {
using Object::Object;
public:
	virtual bool AliveTickInternal(const sf::RenderWindow& window) const override;

	virtual CollisionType GetCollisionType() const override 
	{ return CollisionType::Ship; }
	virtual void Collide(Object* other, CollisionType otherType) override;

	void DamageFromShipContact(int damage);
	virtual void Damage(int damage);

	// Without health the ship dies immediately.
	float health = 1;
	// Scalar unit in pixels per second.
	float speed;
	InterleavedPassiveEvent<int> damageFromShipContactEvent =
		{ [this](int damage){ this->Damage(damage); }, 1s};
};	

