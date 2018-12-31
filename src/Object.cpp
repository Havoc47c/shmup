#include "Object.h" 

Object::Object(std::unique_ptr<sf::Shape> objectShape, const Team owningTeam) :
	Object(std::move(objectShape), owningTeam, {0,0}) { }

Object::Object(std::unique_ptr<sf::Shape> objectShape, const Team owningTeam, const sf::Vector2f& initialVelocity) :
		shape(std::move(objectShape)),
		team(owningTeam),
		velocity(initialVelocity) {
	// Set the origin of the object to be the center, not the default corner.
	const sf::FloatRect objectBounds = shape->getLocalBounds();
	shape->setOrigin(objectBounds.width/2., objectBounds.height/2.);
	SetColorBasedOnTeam();
}

void Object::Tick(tick::Duration deltaTime) {
	const auto newPosition = shape->getPosition() + 
		velocity * static_cast<float>(deltaTime.count());
	shape->setPosition(newPosition);
}

void Object::Render(sf::RenderWindow& window) const {
	window.draw(*shape);
}

bool Object::Alive(const sf::RenderWindow& window) const {
	const sf::Vector2 size = window.getSize();
	const sf::Vector2<float>& position = shape->getPosition();
	// Object is in bounds of the screen.
	if (0 <= position.x && position.x <= size.x &&
	    0 <= position.y && position.y <= size.y) {
		return true;
	}
	return false;
}

void Object::SetColorBasedOnTeam() {
	shape->setFillColor(GetTeamColor(this->team));
}
