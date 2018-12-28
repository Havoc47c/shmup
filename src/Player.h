#pragma once

#include "InterleavedPassiveEvent.h"
#include "SFML/Graphics.hpp"
#include "Ship.h"
#include "Tick.h"

class Player : public Ship<sf::CircleShape>  {
protected:
using Base = Ship<sf::CircleShape>;
public:
	Player();
	virtual void Tick(tick::Duration deltaTime) override;

protected:
	InterleavedPassiveEvent Shoot;
};
