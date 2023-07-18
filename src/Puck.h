#pragma once
#include "Entity.h"

class Puck : public Entity
{
private:
	
	float m_Speed;
	Vector2 m_Direction;
	
public:
	Puck();
	~Puck();

	void CheckPlayerCollision(class Paddle* paddle);
	void CheckIfScored(class Paddle* left, class Paddle* right);

	void OnUpdate(double delta) override;

	Vector2 GetDirection() const { return m_Direction; }

private:
	void CheckWallCollision();
	void Reset(bool leftScored);
};