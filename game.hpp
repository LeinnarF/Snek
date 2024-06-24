#pragma once
#include <raylib.h>
#include <deque>
#include "utils.hpp"
#include "food.hpp"
#include "snake.hpp"

class Game
{
public:
	bool running = true;
	Snake snake;
	Food food = Food(snake.body);
	void Draw();
	void Update();
	void GameOver();
	void CheckCollisionWithFood();
	void CheckCollisionWithEdges();
	void CheckCollisionWithBody();
};