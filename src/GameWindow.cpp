#include "GameWindow.h"

std::unique_ptr<sf::RenderWindow> GameWindow::window = nullptr;

// static
bool GameWindow::WithinWindowBounds(const sf::Vector2f& position) {
	const auto& size = Size();
	return 0 <= position.x && position.x <= size.x &&
		0 <= position.y && position.y <= size.y;
}
