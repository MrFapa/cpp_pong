#pragma once

struct Vector2
{
	float x, y;

	Vector2(float xVal, float yVal) : x(xVal), y(yVal) {}

	Vector2 operator+ (const Vector2& other) const
	{
		return { this->x + other.x, this->y + other.y };
	}

	Vector2 operator- (const Vector2& other) const
	{
		return { this->x - other.x, this->y - other.y };
	}

	Vector2 operator* (const float& scalar) const
	{
		return { this->x * scalar, this->y * scalar };
	}
};