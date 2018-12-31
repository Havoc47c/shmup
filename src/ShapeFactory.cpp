#include "ShapeFactory.h"

namespace factory {
	
// static
std::unique_ptr<sf::CircleShape> Shape::PlayerShip() {
	static sf::CircleShape shape{18, 3};
	return std::make_unique<sf::CircleShape>(shape);
}

std::unique_ptr<sf::CircleShape> Shape::PlayerBullet() {
	static sf::CircleShape shape{5, 9};
	return std::make_unique<sf::CircleShape>(shape);
}

}
