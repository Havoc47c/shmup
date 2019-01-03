#include "Director.h"
#include "ShapeFactory.h"
#include "Ship.h"
#include "Team.h"
#include "VirtualWorld.h"
#include "SFML/Graphics.hpp"

Director::Director() 
	: spawnEnemyEvent([this](){this->SpawnEnemy();}, 1s) {
}

void Director::Tick() {
	spawnEnemyEvent.AttemptTrigger();
}

void Director::SpawnEnemy() {
	Ship* newEnemy = WorldType::GetInstance()->Create<Ship>(
		factory::shape::RectangleShip(), Team1);
	newEnemy->setPosition(sf::Vector2f{300, -100});
	newEnemy->velocity = {0, 300};
}
