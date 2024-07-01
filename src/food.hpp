#pragma once
#include <raylib.h>
#include <deque>

class Food
{
public:
	Vector2 position;
	Food(std::deque<Vector2> snakeBody);
	void Draw();
	Vector2 GenerateRandomPosition(std::deque<Vector2> snakeBody);
	Vector2 GenerateRandomCell();

};