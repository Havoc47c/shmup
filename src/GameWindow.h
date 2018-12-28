#pragma once
#include <memory>
#include <utility>
#include "SFML/Graphics.hpp"

class GameWindow {
	static std::unique_ptr<sf::RenderWindow> window;
public:
	template<typename... Args>
	static sf::RenderWindow* Create(Args&&... args) {
		window = std::make_unique<sf::RenderWindow>((args)...);
		return window.get();
	}

	static const sf::RenderWindow* Get() { return window.get(); }
	static const sf::Vector2i Size() { return sf::Vector2<int>(window->getSize()); }
	static bool WithinWindowBounds(const sf::Vector2f& position);
	template<typename T>
	static bool WithinWindowBounds(const sf::Rect<T>& rect) {
		const auto size = Size();
		const sf::Rect windowRect = sf::Rect<T>(0, 0, size.x, size.y);
		return rect.intersects(windowRect);
	}
};
