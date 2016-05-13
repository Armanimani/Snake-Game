#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

constexpr int windowWidth{500}, windowHeight{500};
constexpr int windowFramerateLimit{60};
constexpr float blockWidth{10.0f}, blockHeight{10.0f};

int main()
{
	RenderWindow window{{windowWidth, windowHeight}, "Snake-v1.0"};
	window.setFramerateLimit(windowFramerateLimit);

	while(true)
	{
		window.clear(Color::Black);

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		{
			break;
		}

		window.display();
	}

	return 0;
}