#pragma once

#include <chrono>

namespace tick {
using Duration = std::chrono::duration<double>;
using Instant = std::chrono::time_point<std::chrono::system_clock>;
// using Instant = std::chrono::time_point<std::chrono::system_clock, TickDuration>;

inline auto Now() {
	return std::chrono::system_clock::now();
}

}
