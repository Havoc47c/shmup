#pragma once
#include <memory>
#include "SFML/Graphics.hpp"

namespace factory {
namespace shape {

std::unique_ptr<sf::CircleShape> PlayerShip();
std::unique_ptr<sf::CircleShape> PlayerBullet();
std::unique_ptr<sf::RectangleShape> RectangleShip();

}  // namespace factory
}  // namespace factory
