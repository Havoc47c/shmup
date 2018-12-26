#include <vector>

#include "SFML/Graphics.hpp"
#include "Tick.h"
#include "Renderable.h"

class World {
public:
	World(sf::RenderWindow* newWindow) : window(newWindow) {}
	virtual tick::Duration RenderNextFrame() = 0;
protected:
	virtual tick::Duration Tick() = 0;
	sf::RenderWindow* window;
};
