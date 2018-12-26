#include "World.h"

#include <memory>
#include <utility>
#include <iostream>

#include "Tick.h"
#include "Object.h"
#include "SFML/Graphics.hpp"

class VirtualWorld : public World {
public:
	VirtualWorld(sf::RenderWindow* newWindow) : 
		World(newWindow),
		lastFrameTime(tick::Now()),
		lastTickTime(lastFrameTime) {
	}

	void BeginTicking() {
		lastTickTime = lastFrameTime = tick::Now();
	}

	template <typename T, typename... Args>
	T* Create(Args... args) {
		renderables.push_back(std::make_unique<T>(std::forward(args)...));
		return static_cast<T*>(renderables.back().get());
	}
	tick::Duration RenderNextFrame();
	template<typename T>
	T* get() { return static_cast<T*>(renderables.back().get()); }
	auto RenderableSize() { return renderables.size(); }
protected:
	tick::Duration Tick();
	void Delete(std::unique_ptr<Renderable>& object);

	std::vector<std::unique_ptr<Renderable>> renderables;
	// Used for fps measurements.
	tick::Instant lastFrameTime;
	// Used for proper displacement of moving objects.
	tick::Instant lastTickTime;
};
