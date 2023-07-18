#include "Puck.h"

#include <algorithm>
#include <iostream>

#include "Paddle.h"


Puck::Puck()
	: Entity({500, 400}, 20, 20), m_Speed(200), m_Direction({1, 0})
{
}

void Puck::CheckPlayerCollision(Paddle* paddle)
{
	collision::BoundingBox paddleBB = paddle->GetBoundingBox();
	// Check for collision
	bool collided = collision::CheckAABBCollision(GetBoundingBox(), paddleBB);

	// return if no collision
	if (!collided)
	{
		return;
	}

	m_Position.x = (m_Direction.x < 0) ? paddleBB.max.x : paddleBB.min.x;

	// Get relative position of puck from -1 (bottom) to 1 (top)
	float relativePosition = -1.0f + 2.0f * ((m_Position.y - paddleBB.min.y) / (paddleBB.max.y - paddleBB.min.y));

	// Limit because value can go above 1 and -1 (relative pos gets calculated
	// with center of puck
	relativePosition = std::max(-1.0f, std::min(1.0f, relativePosition));

	// redirect angle limited by the constant (1.0f 90deg, 0.0f 0deg),
	// x gets the remaining from 1 - yDir so that the direction is normalized
	
	float yDir = relativePosition * 0.6f;
	float xDir = (m_Direction.x < 0) ? 1 - std::abs(yDir) : (1 - std::abs(yDir)) * -1;
	m_Direction = { xDir, yDir };
	m_Speed += 50;
	
}

void Puck::CheckIfScored(Paddle* left, Paddle* right)
{
	if(m_Position.x - m_Width / 2 < 0)
	{
		right->IncrementScore();
		Reset(false);
		std::cout << left->GetScore() << " : " << right->GetScore() << std::endl;
	} else if(m_Position.x + m_Width / 2 > 1000)
	{
		left->IncrementScore();
		Reset(true);
		std::cout << left->GetScore() << " : " << right->GetScore() << std::endl;
	}
}

void Puck::OnUpdate(double delta)
{
	m_Position = m_Position + m_Direction * m_Speed * static_cast<float>(delta);
	CheckWallCollision();
}

void Puck::CheckWallCollision()
{
	if(m_Position.y - m_Height / 2 < 0)
	{
		m_Position.y = m_Height / 2;
		m_Direction.y *= -1;
	} else if ( m_Position.y + m_Height / 2 > 800)
	{
		m_Position.y = 800 - m_Height / 2;
		m_Direction.y *= -1;
	}
}

void Puck::Reset(bool leftScored)
{
	m_Direction = { leftScored ? 1.0f : -1.0f, 0.0f };
	m_Speed = 200;
	m_Position = { 500, 400 };
}


