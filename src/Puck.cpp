#include "Puck.h"

#include <algorithm>

#include "Paddle.h"

Puck::Puck()
	: Entity({500, 400}, 20, 20), m_Speed(200), m_Direction({1, 0})
{
}

void Puck::CheckPlayerCollision(Paddle* paddle)
{
	collision::BoundingBox paddleBB = paddle->GetBoundingBox();
	bool collided = collision::CheckAABBCollision(GetBoundingBox(), paddleBB);
	if (!collided)
	{
		return;
	}

	m_Position.x = (m_Direction.x < 0) ? paddleBB.max.x : paddleBB.min.x;

	float relativePosition = -1.0f + 2.0f * ((m_Position.y - paddleBB.min.y) / (paddleBB.max.y - paddleBB.min.y));
	relativePosition = std::max(-1.0f, std::min(1.0f, relativePosition));
	float yDir = relativePosition * 0.6f;
	float xDir = (m_Direction.x < 0) ? 1 - std::abs(yDir) : (1 - std::abs(yDir)) * -1;
	m_Direction = { xDir, yDir };
	m_Speed += 100;
	
}

void Puck::CheckIfScored(Paddle* left, Paddle* right)
{
	if(m_Position.x - m_Width / 2 < 0)
	{
		right->IncrementScore();
		Reset(false);
	} else if(m_Position.x + m_Width / 2 > 1000)
	{
		left->IncrementScore();
		Reset(true);
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


