#pragma once
#include "Tickable.h"

// Abstract object which executes some recurring logic.
class Ai : public Tickable {
public:
	virtual ~Ai() {};
};
