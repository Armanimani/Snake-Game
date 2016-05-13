#ifndef GRID_H
#define GRID_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>
#include <iostream>
#include "Head.h"
#include "Block.h"
#include <deque>

using namespace sf;

constexpr int tailLength{10};

class Grid
{
public:
	Grid(float windowSize, int gridNum, RenderWindow &window)
	{
		this->window = &window;
		this->gridNum = gridNum;
		this->windowSize = windowSize;

		blockSize =(int) (windowSize / gridNum);

		for (int row = 0; row != gridNum; ++row)
		{
			for (int col = 0; col != gridNum; ++col)
			{
				coordinate[vectorize(row, col)] = 
					Vector2f{(col + 0.5f) * blockSize, (row + 0.5f) * blockSize};

				status[vectorize(row, col)] = 0;
			}
		}
		int index = vectorize(gridNum / 2 , gridNum / 2);
		head = Head(coordinate[index].x , coordinate[index].y, blockSize, index);

		status[index] = 2;

		for (int i = 0; i != tailLength; ++i)
		{
			insertBlock(getLeft(index, i));
		}


	}

	void update()
	{

	}

	int getLeft(int pos, int number) { return pos - number; }
	int getRight(int pos, int number) { return pos + number; }
	int getUp(int pos , int number) { return pos - gridNum * number; }
	int getBottom(int pos, int number) { return pos + gridNum * number; }

	inline float &getBlockSize() { return blockSize; }

	inline int &getStatus(int i, int j) { return status[vectorize(i, j)]; }
	inline std::deque<Block> &getBlocks() { return blocks; }
	inline Head &getHead() { return head; }

	inline void insertBlock(int i)
	{ 
		status[i] = 1;
		blocks.emplace_back(coordinate[i].x , coordinate[i].y, blockSize, i);
	}
	inline void removeBlock()
	{
		status[blocks[0].getID()] = 1;
		blocks.pop_front();
	}

private:
	RenderWindow *window;
	float windowSize;
	int gridNum;

	float blockSize;

	std::map<int, int> status;
	std::map<int, Vector2f> coordinate; 

	std::deque<Block> blocks;
	Head head;

	int vectorize(int i, int j) { return i * gridNum + j; } 
};

#endif