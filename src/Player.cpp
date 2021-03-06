#include "Player.h"
#include <cmath>
#include <iostream>
#include <utility>
#include "GameWindow.h"
#include "SFML/Window.hpp"
#include "ShapeFactory.h"
#include "PlayerBullet.h"
#include "VirtualWorld.h"

Player::Player() : Ship(factory::shape::PlayerShip(), Team0) {
	auto shootEvent = [this]() {
		WorldType::GetInstance()->Create<PlayerBullet>(this->getPosition(), -750);
	};
	Shoot = InterleavedPassiveEvent(shootEvent, 0.15s);
	this->health = 100;
	this->speed = 500;
	this->setPosition(sf::Vector2f(GameWindow::Size()));
}

void Player::Tick(tick::Duration deltaTime) {
	using std::sqrt;
	using std::pow;
	const sf::Vector2f dest(sf::Mouse::getPosition(*GameWindow::Get()));
	const sf::Vector2f pos = this->getPosition();
	const sf::Vector2f dir = dest - pos;
	const float directionMagnitude = sqrt(pow(dir.x, 2.f) + pow(dir.y, 2.f)); 
	if (directionMagnitude != 0.f) {
		this->velocity = speed * dir / directionMagnitude;
	} else {
		this->velocity = {0.f, 0.f};
	}
	Base::Tick(deltaTime);

	// Try to fire bullet.
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		Shoot.AttemptTrigger();
	}
}
