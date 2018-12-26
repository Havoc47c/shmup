#include <vector>
#include <random>

#include "Object.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "VirtualWorld.h"
#include "GameWindow.h"

namespace {
using sf::Vector2;
}

int main() {

	sf::RenderWindow* window = GameWindow::Create(sf::VideoMode(400, 400), "Yay");
	VirtualWorld world = VirtualWorld(window);
	Player* player = world.Create<Player>();
	player->setPosition(sf::Vector2f(0,0));
	
	double runningFps = 0;
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		tick::Duration spf = world.RenderNextFrame();
		//std::cout << spf.count() << '\n';
		runningFps = (runningFps*0.95 + (1/spf.count())*0.05);
		//std::cout << "FPS: " <<  runningFps << '\n';
	}

	return 0;

}

