#include "Ship.h"

bool Ship::AliveTickInternal(const sf::RenderWindow& window) const {
	return health > 0.f;
}

// Ships damage each other upon collision.
void Ship::Collide(Object* other, CollisionType otherType) {
	// Do nothing for bullet.
	if (otherType == CollisionType::Bullet) {
		return;
	}
	else if (otherType == CollisionType::Ship) {
		// Small collision damage.
		dynamic_cast<Ship*>(other)->DamageFromShipContact(1);
	}
}

void Ship::DamageFromShipContact(int damage) {
	damageFromShipContactEvent.AttemptTrigger(damage);
}

void Ship::Damage(int damage) {
	health -= damage;
}
