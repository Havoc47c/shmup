#include <vector>
#include <random>

#include "Object.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "ShapeFactory.h"
#include "VirtualWorld.h"
#include "GameWindow.h"

namespace {
using sf::Vector2;
}  // namespace


int main() {
	sf::Cursor target;
	target.loadFromSystem(sf::Cursor::Hand);
	sf::RenderWindow* window = GameWindow::Create(sf::VideoMode(600, 600), "Yay");
	window->setMouseCursorVisible(true);
	window->setMouseCursor(target);
	VirtualWorld* world = VirtualWorld::CreateInstance(window);
	Player* player = VirtualWorld::GetInstance()->Create<Player>();
	player->setPosition(sf::Vector2f(0,0));

	Ship* enemy = world->Create<Ship>(factory::shape::RectangleShip(), Team1);
	enemy->setPosition(sf::Vector2f{200, 100});
	enemy->health = 10;

	sf::Font font;
	if(!font.loadFromFile("assets/OpenSans-Regular.ttf")) {
		std::cout << "Font unable to load.\n";	
	}

	sf::Text fpsText;
	fpsText.setFont(font);
	fpsText.setFillColor(sf::Color::White);
	fpsText.setCharacterSize(24);
	
	double runningFps = 0;
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		tick::Duration spf = world->PrepareNextFrame();
		runningFps = (runningFps*0.99 + (1/spf.count())*0.01);
		fpsText.setString("FPS:" + std::to_string(static_cast<int>(runningFps)));
		window->draw(fpsText);
		world->RenderNextFrame();
	}

	return 0;

}

