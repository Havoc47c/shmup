#pragma once
#include "Object.h"
#include "GameWindow.h"
#include "SFML/Graphics.hpp"

class Bullet : public Object {
using Object::Object;
public:
	
bool AliveTickInternal(const sf::RenderWindow& window) const;
};
