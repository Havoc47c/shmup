#pragma once
#include "Renderable.h"

#include <iostream>

#include "Collision.h"
#include "SFML/System/Vector2.hpp"
#include "Tick.h"
#include "Team.h"

template <typename Shape>
class Object : public Renderable {
public:
	Object(const Shape& objectShape, const Team owningTeam);
	Object(const Shape& objectShape, const Team owningTeam, const sf::Vector2f& initialVelocity);

	virtual ~Object() {}
	virtual void Tick(tick::Duration deltaTime) override;
	virtual void Render(sf::RenderWindow& window) const override; 
	virtual bool Alive(const sf::RenderWindow& window) const override;

	sf::Vector2<float> velocity;
	Shape shape;
	Team team;
	auto getPosition() { return shape.getPosition(); }
	void setPosition(sf::Vector2f newPosition) { shape.setPosition(newPosition); }
private:
	void SetColorBasedOnTeam();
};

//template<typename Shape>
//Object<Shape>::Object() :
//	Object(Shape(), {0, 0}) { }

template<typename Shape>
Object<Shape>::Object(const Shape& objectShape, const Team owningTeam) :
	Object(objectShape, owningTeam, {0,0}) { }

template<typename Shape>
Object<Shape>::Object(const Shape& objectShape, const Team owningTeam, const sf::Vector2f& initialVelocity) :
		shape(objectShape),
		team(owningTeam),
		velocity(initialVelocity) {
	// Set the origin of the object to be the center, not the default corner.
	const sf::FloatRect objectBounds = shape.getLocalBounds();
	shape.setOrigin(objectBounds.width/2., objectBounds.height/2.);
	SetColorBasedOnTeam();
}

template<typename Shape>
void Object<Shape>::Tick(tick::Duration deltaTime) {
	const auto newPosition = shape.getPosition() + 
		velocity * static_cast<float>(deltaTime.count());
	shape.setPosition(newPosition);
}

template<typename Shape>
void Object<Shape>::Render(sf::RenderWindow& window) const {
	window.draw(shape);
}

template<typename Shape>
bool Object<Shape>::Alive(const sf::RenderWindow& window) const {
	const sf::Vector2 size = window.getSize();
	const sf::Vector2<float>& position = shape.getPosition();
	// Object is in bounds of the screen.
	if (0 <= position.x && position.x <= size.x &&
	    0 <= position.y && position.y <= size.y) {
		return true;
	}
	return false;
}

template<typename Shape>
void Object<Shape>::SetColorBasedOnTeam() {
	shape.setFillColor(GetTeamColor(this->team));
}
