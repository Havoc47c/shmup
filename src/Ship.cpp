#include "Ship.h"

bool Ship::Alive(const sf::RenderWindow& window) const {
	return health > 0.f;
}
