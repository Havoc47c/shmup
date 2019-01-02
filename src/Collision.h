#pragma once
#include "SFML/Graphics.hpp"

class Object;

enum class CollisionType {
	Ship,
	Bullet
};

// Check if two objects/shapes are colliding.
bool IsColliding(const sf::Shape* a, const sf::Shape* b);
// Does not check if these objects collide at all. Might be accidentally running a 
// collision check on objects which are not supposed to collide with anything.
bool IsColliding(const Object* a, const Object* b);

// Helper method which calls collide on both objects.
void Collide(Object* a, Object* b);

// Helper method which checks collision, then collides if necessary.
// Returns the value of IsColliding.
bool TryCollide(Object* a, Object* b);
