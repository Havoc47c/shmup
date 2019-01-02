#include "Bullet.h"
#include "Ship.h"

bool Bullet::AliveTickInternal(const sf::RenderWindow& window) const {
	return GameWindow::WithinWindowBounds(this->shape->getGlobalBounds());
}

void Bullet::Collide(Object* other, CollisionType type) {
	// Its a bullet, do nothing.
	if (type == GetCollisionType()) {
		return;
	} else if (type == CollisionType::Ship) {
		Hit(dynamic_cast<Ship*>(other));
	}
	this->ForceKill();
}

void Bullet::Hit(Ship* ship) {
	ship->Damage(hitDamage);
}
