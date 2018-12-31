#include "Ship.h"

bool Ship::AliveTickInternal(const sf::RenderWindow& window) const {
	return health > 0.f;
}
