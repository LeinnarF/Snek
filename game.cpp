#include "game.hpp"

void Game::Draw()
{
	food.Draw();
	snake.Draw();

}

void Game::Update()
{
	if (running)
	{
		snake.Update();
		CheckCollisionWithBody();
		CheckCollisionWithFood();
		CheckCollisionWithEdges();
	}
	if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_RIGHT))
	{
		running = true;
	}
}

void Game::GameOver()
{
	snake.Reset();
	food.position = food.GenerateRandomPosition(snake.body);
	running = false;

}

void Game::CheckCollisionWithFood()
{
	if (Vector2Equals(snake.body[0], food.position))
	{
		food.position = food.GenerateRandomPosition(snake.body);
		snake.addSegment = true;
	}
}

void Game::CheckCollisionWithEdges()
{
	if (snake.body[0].x == 25 || snake.body[0].x == -1)
	{
		GameOver();
	}
	if (snake.body[0].y == 25 || snake.body[0].y == -1)
	{
		GameOver();
	}
}

void Game::CheckCollisionWithBody()
{
	// Start checking from the second segment to avoid comparing the head with itself
	for (size_t i = 1; i < snake.body.size(); ++i)
	{
		if (Vector2Equals(snake.body[0], snake.body[i]))
		{
			GameOver();
			return; // Exit the method immediately after detecting a collision
		}
	}
}

