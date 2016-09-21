#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <iostream>

using namespace std;

class GameOfLife
{
public:

	GameOfLife();

	~GameOfLife();

	static const int size = 50;

	typedef bool BoardType[size][size];

	void display(BoardType Board, int &iteration);

	bool Life(BoardType Board, int Row, int Col);

	void populate(BoardType Board, BoardType Board2);

	inline int NumLiveNeighbors(BoardType Board, int Row, int Col);

};

#endif