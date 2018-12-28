#include "VirtualWorld.h"
tick::Duration VirtualWorld::Tick() {
	tick::Instant currentTime = tick::Now();
	tick::Duration deltaTime = currentTime - lastTickTime;
	// can't use range based for, because it uses iterators, and if inside tick,
	// new objects are created, then the iterators will be invalidated.
	// for(const auto& renderable : renderables) {
	for(int i = 0; i < renderables.size(); ++i) {
		renderables[i]->Tick(deltaTime);
	} 
	// Must set the last tick time from the time tick started, otherwise frame
	// updates are inconsistent.
	lastTickTime = currentTime;
	return deltaTime;
}

tick::Duration VirtualWorld::PrepareNextFrame() {
	Tick();
	window->clear();
	for(int i = 0; i < renderables.size(); ++i) {
		std::unique_ptr<Renderable>& renderable = renderables[i];
		if (renderable->Alive(*window)) {
			renderable->Render(*window);
		} else {
			// Plain erasing doesn't seem to have a huge performance penalty.
			//renderables.erase(renderables.begin() + i);
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

void VirtualWorld::Delete(std::unique_ptr<Renderable>& object) {
	// We might need to delete the last item on the vector.
	if (renderables.back() != object) {
		// Swap delete item with last item.
		object = std::move(renderables.back());
	}
	// Delete last item.
	renderables.pop_back();
}

std::unique_ptr<VirtualWorld> VirtualWorld::instance = nullptr;
