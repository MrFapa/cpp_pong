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

	float relativePosition = -1.0f + 2.0f * ((m_Position.y - paddleBB.min.y) / (paddleBB.max.y - paddleBB.min.y));

	m_Position.x = (m_Direction.x < 0) ? paddleBB.max.x : paddleBB.min.x;
	m_Direction.x *= -1;
}

void Puck::OnUpdate(double delta)
{
	m_Position = m_Position + m_Direction * m_Speed * static_cast<float>(delta);
}

void Puck::Reset()
{
	
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
	
}

