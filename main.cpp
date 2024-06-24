#include <raylib.h>
#include "food.hpp"
#include "snake.hpp"
#include "game.hpp"

int cellSize = 30;
int cellCount = 25;
double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime > interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main()
{
	int a = cellCount * cellSize;

	InitWindow(a, a, "Snek");

	SetTargetFPS(60);

	Game game;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		game.snake.Move();
		if (eventTriggered(0.1))
		{
			game.Update();
		}
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			if (eventTriggered(0.025))
			{
				game.Update();
			}
		}

		ClearBackground(RAYWHITE);

		game.Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}