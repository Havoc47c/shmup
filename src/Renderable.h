#pragma once
#include "Tick.h"
#include <SFML/Graphics.hpp>

class Renderable {
public:
	virtual ~Renderable() {}
	virtual void Tick(tick::Duration deltaTime) = 0;
	virtual void Render(sf::RenderWindow& window) const = 0;

	// Recurring calculation to determine if an object is alive.
	bool AliveTick(const sf::RenderWindow& window) {
		alive = alive && AliveTickInternal(window);
		return Alive();
	}
	
	// Returns value indicating whether object is still alive. Alive=true/false
	// Dead objects can be deleted.
	[[nodiscard]] bool Alive() const noexcept { return alive; }
	[[nodiscard]] bool Dead() const noexcept{ return !Alive(); }

	// Forceably kill this object.
	void ForceKill() { alive = false; }
protected:
private:
	bool alive = true;
	virtual bool AliveTickInternal(const sf::RenderWindow& window) const = 0;
};

