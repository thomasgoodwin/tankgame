#ifndef MATH_H
#define MATH_H

#define PI 3.1415926535897932384626433
#include "SFML/Graphics.hpp"

namespace MATH
{
	static float toDegrees(float radians)
	{
		return PI * radians / 180;
	}
	static void calculateDirectionVector(sf::Vector2f& directionVector, float rotation)
	{
		directionVector = { cos(toDegrees(rotation)), sin(toDegrees(rotation)) };
	}
	static float distance(sf::Vector2f vec1, sf::Vector2f vec2)
	{
		return sqrt(((vec2.x - vec1.x) * (vec2.x - vec1.x)) + ((vec2.y - vec1.y) * (vec2.y - vec1.y)));
	}
}
#endif // !MATH_H


