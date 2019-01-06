#pragma once
#include <functional>
#include "Tick.h"

// This event must be manually triggered and is prevented from firing more than
// once in the specified interval.
template<typename... Args>
class InterleavedPassiveEvent {
public:
	// No gaurentees on what happens.
	InterleavedPassiveEvent() = default;

	// Creates a usable event which can only be called every period.
	// Template args must be specified unless a void(void) lambda is given.
	// void(void) lambda always assumed.
	InterleavedPassiveEvent(std::function<void(Args...)> callback,
		tick::Duration period) : 
			event(callback),
			eventPeriod(std::chrono::duration_cast<tick::ExactDuration>(period)),
			nextValidTriggerTime(tick::Now() - eventPeriod) {}

	bool AttemptTrigger(Args... args) {
		if (ReadyToTrigger()) {
			Trigger(args...);
			return true;
		}
		return false;
	}

	[[nodiscard]] bool ReadyToTrigger() const noexcept {
		return nextValidTriggerTime < tick::Now();
	}
protected:
	void Trigger(Args... args) {
		nextValidTriggerTime = tick::Now() + eventPeriod;
		event(args...);
	}
private:
	std::function<void(Args...)> event;
	tick::ExactDuration eventPeriod;
	tick::Instant nextValidTriggerTime;
};

// Deduction guides.
template<typename Lambda, typename... Args>
InterleavedPassiveEvent(Lambda callback, tick::Duration period) -> 
	InterleavedPassiveEvent<>;
