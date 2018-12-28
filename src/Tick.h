#pragma once

#include <chrono>

namespace tick {
using Duration = std::chrono::duration<float>;
using ExactDuration = std::chrono::duration<long long, std::nano>;
using Instant = std::chrono::time_point<std::chrono::steady_clock, ExactDuration>;

inline Instant Now() {
	return Instant::clock::now();
}

}
