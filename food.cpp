#include "food.hpp"
#include "utils.hpp"
#include <raymath.h>


Food::Food(std::deque<Vector2> snakeBody)
{
	position = GenerateRandomPosition(snakeBody);
}



void Food::Draw()
{
	DrawRectangle(static_cast<int>(position.x * 30), static_cast<int> (position.y * 30), 30, 30, RED); // typecast to int
}


Vector2 Food::GenerateRandomCell()
{

	float x = static_cast<float> (GetRandomValue(0, 24)); // typecast to float
	float y = static_cast<float> (GetRandomValue(0, 24));
	return Vector2{ x,y };
}

Vector2 Food::GenerateRandomPosition(std::deque<Vector2> snakeBody)
{
	Vector2 position = GenerateRandomCell();

	while (ElementInDeque(position, snakeBody))
	{
		position = GenerateRandomCell();
	}
	return position;

}

