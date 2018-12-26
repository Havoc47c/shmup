#pragma once
#include "Tick.h"
#include <SFML/Graphics.hpp>

class Renderable {
public:
	virtual ~Renderable() {}
	virtual void Tick(tick::Duration deltaTime) = 0;
	virtual void Render(sf::RenderWindow& window) const = 0;

	// Returns value indicating whether object is still alive. Alive=true/false
	// Dead objects can be deleted
	virtual bool Alive(const sf::RenderWindow& window) const = 0;
	bool Dead(const sf::RenderWindow& window) const { 
		return !Alive(window);
	}
};

