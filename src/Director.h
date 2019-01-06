#pragma once
#include "Ai.h"
#include "InterleavedPassiveEvent.h"

class Director : public Ai {
public:
	Director();
	virtual void Tick(tick::Duration deltaTime) override;
	[[nodiscard]] virtual bool Alive() const noexcept override { return true; }
private:
	InterleavedPassiveEvent<> spawnEnemyEvent;
	void SpawnEnemy();
};
