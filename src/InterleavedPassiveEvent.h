#pragma once
#include <functional>
#include "Tick.h"

// This event must be manually triggered and is prevented from firing more than
// once in the specified interval.
class InterleavedPassiveEvent {
public:
	// No gaurentees on what happens.
	InterleavedPassiveEvent() = default;
	// Creates a usable event which can only be called every period.
	InterleavedPassiveEvent(std::function<void(void)> callback, 
		tick::Duration period);

	bool AttemptTrigger();

	[[nodiscard]] bool ReadyToTrigger() const noexcept {
		return nextValidTriggerTime < tick::Now();
	}
protected:
	void Trigger() {
		nextValidTriggerTime = tick::Now() + eventPeriod;
		event();
	}
private:
	std::function<void(void)> event;
	tick::ExactDuration eventPeriod;
	tick::Instant nextValidTriggerTime;
};
