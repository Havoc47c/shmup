#pragma once
#include "Ai.h"
#include "InterleavedPassiveEvent.h"

class Director : public Ai {
public:
	Director();
	virtual void Tick() override;
	virtual bool Alive() override { return true; }
private:
	InterleavedPassiveEvent spawnEnemyEvent;
	void SpawnEnemy();
};
