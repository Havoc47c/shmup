#pragma once
#include "Tick.h"

class Tickable {
public:
	virtual void Tick(tick::Duration deltaTime) = 0;
	[[nodiscard]] virtual bool Alive() const noexcept = 0;
};
