#include "VirtualWorld.h"
tick::Duration VirtualWorld::Tick() {
	tick::Instant currentTime = tick::Now();
	tick::Duration deltaTime = currentTime - lastTickTime;
	TickAi(deltaTime);
	// can't use range based for, because it uses iterators, and if inside tick,
	// new objects are created, then the iterators will be invalidated.
	// for(const auto& renderable : objects) {
	for(int i = 0; i < objects.size(); ++i) {
		objects[i]->Tick(deltaTime);
	} 
	// Must set the last tick time from the time tick started, otherwise frame
	// updates are inconsistent.
	lastTickTime = currentTime;
	return tick::Now() - currentTime;
}

// Ai's don't care about how long its been since the last tick.
tick::Duration VirtualWorld::TickAi(tick::Duration deltaTime) {
	tick::Instant currentTime = tick::Now();
	for(int i = 0; i < ais.size(); ++i) {
		if (ais[i]->Alive()) {
			ais[i]->Tick(deltaTime);
		} else {
			Delete(ais[i]);
		}
	}

	return tick::Now() - currentTime;
}

tick::Duration VirtualWorld::CollisionCheck() {
	tick::Instant currentTime = tick::Now();
	
	for(int i = 0; i < objects.size(); ++i) {
		if (!objects[i]->CollidesWithObjects()) {
			continue;
		}
		for(int j = i+1 ; j < objects.size(); ++j) {
			if (!objects[j]->CollidesWithObjects()) {
				continue;
			}
			TryCollide(objects[i].get(), objects[j].get());
		}
	}
	
	return tick::Now() - currentTime;
}

tick::Duration VirtualWorld::PrepareNextFrame() {
	Tick();
	CollisionCheck();

	window->clear();
	for(int i = 0; i < objects.size(); ++i) {
		std::unique_ptr<Object>& renderable = objects[i];
		if (renderable->AliveTick(*window)) {
			renderable->Render(*window);
		} else {
			// Plain erasing doesn't seem to have a huge performance penalty.
			//objects.erase(objects.begin() + i);
			Delete(renderable);
			// The another not deleted object is now at this location.
			--i;	
		}
	}

	auto currentFrameTime = tick::Now();
	tick::Duration deltaTime = currentFrameTime - lastFrameTime;
	lastFrameTime = currentFrameTime;
	return deltaTime;
}

void VirtualWorld::RenderNextFrame() {
	window->display();
}

void VirtualWorld::Delete(std::unique_ptr<Object>& object) {
	// We might need to delete the last item on the vector.
	if (objects.back() != object) {
		// Swap delete item with last item.
		object = std::move(objects.back());
	}
	// Delete last item.
	objects.pop_back();
}

void VirtualWorld::Delete(std::unique_ptr<Ai>& ai) {
	// We might need to delete the last item on the vector.
	if (ais.back() != ai) {
		// Swap delete item with last item.
		ai = std::move(ais.back());
	}
	// Delete last item.
	ais.pop_back();
}

std::unique_ptr<VirtualWorld> VirtualWorld::instance = nullptr;
