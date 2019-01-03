#pragma once

// Abstract object which executes some recurring logic.
class Ai {
public:
	virtual ~Ai() {};
	// Ai don't care how long its been since the last update.
	virtual void Tick() = 0;
	virtual bool Alive() = 0;
};
