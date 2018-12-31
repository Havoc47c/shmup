#pragma once
#include <memory>
#include "SFML/Graphics.hpp"
namespace factory {

class Shape {
public:
	// Prototypes.
	static std::unique_ptr<sf::CircleShape> PlayerShip();
	static std::unique_ptr<sf::CircleShape> PlayerBullet();
};

}  // namespace factory
