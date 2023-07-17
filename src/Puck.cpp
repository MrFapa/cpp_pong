#include "Puck.h"

#include "Paddle.h"
#include "PrimitveFactory.h"

Puck::Puck()
	: Entity({500, 400}), m_Speed(200), m_Direction({1, 0})
{
	m_Mesh = PrimitiveFactory::Cube(m_Width / 2.0f, m_Height / 2.0f);
}

Puck::~Puck()
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

void Puck::OnUpdate(double delta)
{
	m_Position = m_Position + m_Direction * m_Speed * static_cast<float>(delta);
	CheckWallCollision();
}

glm::mat4 Puck::GetModelMatrix() const
{
	// Transposed because of OpenGL
	glm::mat4 modelMatrix = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		m_Position.x, m_Position.y, 0.0f, 1.0f
	};
	return modelMatrix;
}

collision::BoundingBox Puck::GetBoundingBox() const
{
	collision::BoundingBox boundingBox =
	{
		{m_Position.x - m_Width / 2.0f, m_Position.y - m_Height / 2.0f},
		{m_Position.x + m_Width / 2.0f, m_Position.y + m_Height / 2.0f}
	};
	return boundingBox;
}


void Puck::CheckWallCollision()
{
	if(m_Position.y - m_Height / 2 < 0)
	{
		m_Position.y = m_Height / 2;
		m_Direction.y *= -1;
	} else if ( m_Position.y > 800)
	{
		m_Position.y = 800 - m_Height / 2;
		m_Direction.y *= -1;
	}
}

