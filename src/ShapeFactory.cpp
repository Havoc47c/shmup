#include "ShapeFactory.h"

namespace factory {
namespace shape {
	
// static
std::unique_ptr<sf::CircleShape> PlayerShip() {
	static sf::CircleShape shape{18, 3};
	return std::make_unique<sf::CircleShape>(shape);
}

// static
std::unique_ptr<sf::CircleShape> PlayerBullet() {
	static sf::CircleShape shape{5, 9};
	return std::make_unique<sf::CircleShape>(shape);
}

// static
std::unique_ptr<sf::RectangleShape> RectangleShip() {
	static sf::RectangleShape shape{{30,22}};
	return std::make_unique<sf::RectangleShape>(shape);
}

} // namespace shape
} // namespace factory
