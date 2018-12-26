#pragma once

#include "Object.h"

template <typename Shape>
class Ship : public Object<Shape> {
public:
	virtual bool Alive(const sf::RenderWindow& window) const override;

	float health;
	// Scalar unit in pixels per second.
	float speed;
};	

template <typename Shape>
bool Ship<Shape>::Alive(const sf::RenderWindow& window) const {
	return health > 0.f;
}
