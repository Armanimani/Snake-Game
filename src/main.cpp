#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Block.h"
#include "Grid.h"
#include "Head.h"

using namespace sf;

constexpr int windowSize{500};
constexpr int windowFramerateLimit{60};
constexpr float gridNumber{100};
constexpr float headSpeed{2.0f};

int main()
{
	RenderWindow window{{windowSize, windowSize}, "Snake-v1.0"};
	window.setFramerateLimit(windowFramerateLimit);

	Grid grid(windowSize, gridNumber, window);

	// std::vector<Block> blocks;
	// blocks.emplace_back(windowWidth / 2, windowHeight /2, blockWidth, blockHeight);
	while(true)
	{
		window.clear(Color::Black);

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		{
			break;
		}

		for(auto block : grid.getBlocks())
		{
			window.draw(block.getShape());
		}
		window.draw(grid.getHead().getShape());

		window.display();
	}

	return 0;
}