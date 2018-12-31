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
	virtual bool Alive(const sf::RenderWindow& window) const override;

	auto getPosition() { return shape->getPosition(); }
	template<typename... Args>
	void setPosition(Args... args) { shape->setPosition(std::forward<Args>(args)...); }

	sf::Vector2<float> velocity;
	std::unique_ptr<sf::Shape> shape;
	Team team;
private:
	void SetColorBasedOnTeam();
};

