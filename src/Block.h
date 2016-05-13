#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Block
{
public:
	Block(float origin_x, float origin_y, float size, int ID)
	{
		this->ID = ID;
		shape.setPosition(origin_x, origin_y);
		shape.setSize({size, size});
		shape.setFillColor(Color::White);
		shape.setOrigin(size / 2.0, size / 2.0);
	}

//	inline bool &isDestroyed() { return destroyed; }
	inline RectangleShape &getShape() { return shape; }
	inline int getID() { return ID; }

private:
	int ID;
	RectangleShape shape;
	//bool destroyed = false;
};

#endif