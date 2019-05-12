#include "Circle.hpp"
#include "Square.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), "LW7", sf::Style::Fullscreen);
	window.setMouseCursorVisible(false);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	random.seed(rd());

	Shape* array[10];
	for (size_t t = 0; t < 5; ++t)
		array[t] = new Circle();
	for (size_t t = 5; t < 10; ++t)
		array[t] = new Square();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();
	
		for (size_t t = 0; t < 10; ++t)
			array[t]->change();
		for (size_t t = 0; t < 4; ++t)
		{
			window.clear();
			sf::sleep(sf::seconds(0.3f));
			for (size_t t = 0; t < 10; ++t)
			{
				array[t]->changeColor();
				array[t]->draw(window);
			}
			window.display();
		}
	}
	return 0;
}