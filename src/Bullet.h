#pragma once
#include "Object.h"
#include "GameWindow.h"

template<typename Shape>
class Bullet : public Object<Shape> {
using Object<Shape>::Object;
public:
	
bool Alive(const sf::RenderWindow& window) const;
};

template<typename Shape>
bool Bullet<Shape>::Alive(const sf::RenderWindow& window) const {
	return GameWindow::WithinWindowBounds(this->shape.getGlobalBounds());
}

