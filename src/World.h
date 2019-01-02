#include <vector>

#include "SFML/Graphics.hpp"
#include "Tick.h"
#include "Renderable.h"

class World {
public:
	World(sf::RenderWindow* newWindow) : window(newWindow) {}
	virtual tick::Duration PrepareNextFrame() = 0;
	virtual void RenderNextFrame() = 0;
protected:
	// Ticks all objects. Returns time taken to tick.
	virtual tick::Duration Tick() = 0;
	// Examines objects in the world and processes collisions.
	// Returns time taken to run the collision check.
	virtual tick::Duration CollisionCheck() = 0;
	sf::RenderWindow* window;
};
