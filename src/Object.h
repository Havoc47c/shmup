#pragma once
#include "Renderable.h"

#include <iostream>

#include "Collision.h"
#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"
#include "Tick.h"
#include "Team.h"

class Object : public Renderable {
public:
	Object(std::unique_ptr<sf::Shape> objectShape, const Team owningTeam);
	Object(std::unique_ptr<sf::Shape> objectShape, const Team owningTeam, const sf::Vector2f& initialVelocity);
	virtual ~Object() {}

	virtual void Tick(tick::Duration deltaTime) override;
	virtual void Render(sf::RenderWindow& window) const override; 
	virtual bool AliveTickInternal(const sf::RenderWindow& window) const override;

	auto getPosition() { return shape->getPosition(); }
	template<typename... Args>
	void setPosition(Args... args) { shape->setPosition(std::forward<Args>(args)...); }

	// Collision interface.
	// Indicates whether this object will actually collide with other objects.
	virtual bool CollidesWithObjects() const { return true; };
	// Indicates the type of objects that this collides with.
	virtual CollisionType GetCollisionType() const = 0;
	// Method which actually handles what happends upon a collision.
	virtual void Collide(Object* other, CollisionType type) = 0;

	sf::Vector2<float> velocity;
	std::unique_ptr<sf::Shape> shape;
	Team team;
private:
	void SetColorBasedOnTeam();
};

