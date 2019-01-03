#include "World.h"

#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>

#include "Ai.h"
#include "Tick.h"
#include "Object.h"
#include "SFML/Graphics.hpp"

class VirtualWorld : public World {
public:
	void BeginTicking() {
		lastTickTime = lastFrameTime = tick::Now();
	}

	template <typename T, typename... Args>
	T* Create(Args&&... args) {
		static_assert(std::is_base_of<Object, T>::value);
		objects.push_back(std::make_unique<T>(std::forward<Args>(args)...));
		return static_cast<T*>(objects.back().get());
	}

	template <typename T, typename... Args>
	T* CreateAi(Args&&... args) {
		static_assert(std::is_base_of<Ai, T>::value);
		ais.push_back(std::make_unique<T>(std::forward<Args>(args)...));
		return static_cast<T*>(ais.back().get());
	}

	tick::Duration PrepareNextFrame() override;

	void RenderNextFrame() override;

	template<typename T>
	T* get() { return static_cast<T*>(objects.back().get()); }

	auto ObjectSize() { return objects.size(); }

	static VirtualWorld* GetInstance() {
		return instance.get();
	}

	template<typename... Args>
	static VirtualWorld* CreateInstance(Args&&... args) {
		instance = std::unique_ptr<VirtualWorld>(new VirtualWorld(std::forward<Args>(args)...));
		return instance.get();
	}
	
protected:
	void MergePendingObjects();

	VirtualWorld(sf::RenderWindow* newWindow) : 
		World(newWindow),
		lastFrameTime(tick::Now()),
		lastTickTime(lastFrameTime) {
	}

	tick::Duration Tick() override;
	// Called inside Tick();
	tick::Duration TickAi();

	tick::Duration CollisionCheck() override;

	void Delete(std::unique_ptr<Object>& object);
	void Delete(std::unique_ptr<Ai>& ai);

	std::vector<std::unique_ptr<Object>> objects;

	std::vector<std::unique_ptr<Ai>> ais;
	// Used for fps measurements.
	tick::Instant lastFrameTime;
	// Used for proper displacement of moving objects.
	tick::Instant lastTickTime;
private:
	static std::unique_ptr<VirtualWorld> instance;
};

using WorldType = VirtualWorld;
