#pragma once

struct Vector2
{
	float x, y;

	Vector2(float xVal, float yVal) : x(xVal), y(yVal){}

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

struct Input
{
	int key, state;
};

class Entity
{
public:
	Entity(Vector2 position = { 0, 0 }) : m_Position(position){}

	virtual void OnUpdate(double delta) {}
	Vector2 GetPosition() const { return m_Position; }
protected:
	Vector2 m_Position;
};