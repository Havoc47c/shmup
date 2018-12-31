#pragma once

#include "Object.h"

class Ship : public Object {
using Object::Object;
public:
	virtual bool Alive(const sf::RenderWindow& window) const override;

	float health;
	// Scalar unit in pixels per second.
	float speed;
};	

