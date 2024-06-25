#include <raylib.h>
#include "food.hpp"
#include "snake.hpp"
#include "game.hpp"

int cellSize = 30;
int cellCount = 25;
double lastUpdateTime = 0;
int offset = 75;

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
	int a = 2 * offset + cellSize * cellCount;

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

		DrawRectangleLinesEx(Rectangle{ (float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10 }, 5, DARKGRAY);

		if (!game.running)
		{
			DrawText("Game Over", 350, 300, 40, RED);
			DrawText("Press Space or Arrow keys to Restart", 250, 350, 20, GRAY);
		}

		DrawText("Snek", offset - 5, 20, 40, GRAY);
		DrawText("Score: ", 700, 20, 30, GRAY);
		DrawText(TextFormat("%i", game.score), 700 + 100, 20, 30, GRAY);
		DrawText("Hold Shift for boost", offset - 5, offset + 770, 20, GRAY);

		game.Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}