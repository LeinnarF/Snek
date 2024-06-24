#include <raylib.h>
#include <deque>
#include <raymath.h>
#pragma once

class Snake
{
public:
	static	std::deque<Vector2> body;
	static Vector2 direction;
	bool addSegment = false;

	void Draw();
	void Update();
	void Move();
	void Reset();
};