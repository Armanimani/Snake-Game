#ifndef HEAD_H
#define HEAD_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Head
{
public:
	Head() = default;
	Head(float oX, float oY, float size, int ID)
	{
		this->ID = ID;
		shape.setPosition(oX, oY);
		shape.setSize({size, size});
		shape.setFillColor(Color::Yellow);
		shape.setOrigin(size / 2.0f, size / 2.0f);
	}
	
	inline RectangleShape &getShape() { return shape; }
	inline int getID() { return ID; }
	inline void setID(int id) { ID = id; }

private:
	RectangleShape shape;
	int ID;
};

#endif