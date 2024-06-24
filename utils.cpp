#include "utils.hpp"

bool ElementInDeque(Vector2 element, std::deque<Vector2> deque)
{
	for (size_t i = 0; i < deque.size(); i++)
	{
		if (Vector2Equals(deque[i], element))
		{
			return true;
		}
	}
	return false;
}
