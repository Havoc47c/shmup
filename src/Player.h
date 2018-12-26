#pragma once

#include "Ship.h"
#include "Tick.h"
#include "SFML/Graphics.hpp"

class Player : public Ship<sf::CircleShape>  {
protected:
using Base = Ship<sf::CircleShape>;
public:
	Player();
	virtual void Tick(tick::Duration deltaTime) override;
	

};
