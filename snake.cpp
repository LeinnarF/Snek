#include "snake.hpp"

std::deque<Vector2> Snake::body = { {12, 12 } };
Vector2 Snake::direction = { 1,0 };

void Snake::Draw()
{
	for (const auto& segment : body)
	{
		DrawRectangle(static_cast<int>(75 + segment.x * 30), static_cast<int>(75 + segment.y * 30), 30, 30, GRAY);
	}
}

void Snake::Update()
{
	if (addSegment == true)
	{
		body.push_front(Vector2Add(body[0], direction));
		addSegment = false;
	}
	else
	{
		if (!body.empty()) // Ensure the body is not empty
		{
			// Calculate new head position based on the current direction
			Vector2 newHead = Vector2Add(body.front(), direction);

			// Here, you might want to add additional game logic to handle boundaries or collisions

			// Update the snake's body
			body.pop_back(); // Remove the last segment of the snake's body

			// Safely add the new head segment to the front
			body.push_front(newHead);
		}
		else
		{
			// Handle the case when the snake's body is empty
			// This could involve resetting the game or snake, or displaying a message, etc.
		}
	}
}

void Snake::Move()
{
	if (IsKeyPressed(KEY_UP) && direction.y != 1)
	{
		direction = { 0,-1 };
	}
	else if (IsKeyPressed(KEY_DOWN) && direction.y != -1)
	{
		direction = { 0,1 };
	}
	else if (IsKeyPressed(KEY_LEFT) && direction.x != 1)
	{
		direction = { -1,0 };
	}
	else if (IsKeyPressed(KEY_RIGHT) && direction.x != -1)
	{
		direction = { 1,0 };
	}
}

void Snake::Reset()
{
	body = { Vector2{12, 12} };
	direction = { 1, 0 };

}
