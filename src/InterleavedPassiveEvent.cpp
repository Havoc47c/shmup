#include "InterleavedPassiveEvent.h"

InterleavedPassiveEvent::InterleavedPassiveEvent(std::function<void(void)> callback,
	tick::Duration period) : 
		event(callback),
		eventPeriod(std::chrono::duration_cast<tick::ExactDuration>(period)),
		nextValidTriggerTime(tick::Now() - eventPeriod) {}


bool InterleavedPassiveEvent::AttemptTrigger() {
	if (ReadyToTrigger()) {
		Trigger();
		return true;
	}
	return false;
}
