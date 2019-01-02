#include "Collision.h"
#include "Object.h"

bool IsColliding(const sf::Shape* a, const sf::Shape* b) {
	return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

bool IsColliding(const Object* a, const Object* b) {
	if (a->team != b->team) {
		return IsColliding(a->shape.get(), b->shape.get());
	}
	return false;
}

void Collide(Object* a, Object* b) {
	a->Collide(b, b->GetCollisionType());
	b->Collide(a, a->GetCollisionType());
}

bool TryCollide(Object* a, Object* b) {
	if (IsColliding(a, b)) {
		Collide(a, b);
		return true;
	} else {
		return false;
	}
}
