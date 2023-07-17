#include "Puck.h"
#include "PrimitveFactory.h"

Puck::Puck()
	: Entity({500, 400}), m_Speed(200), m_Direction(1)
{
	m_Mesh = PrimitiveFactory::Cube(10, 10);
}

Puck::~Puck()
{
	
}

void Puck::OnUpdate(double delta)
{
	
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

void Puck::EdgeCheck()
{
	
}

void Puck::BounceWall()
{
	
}

void Puck::BouncePlayer()
{
	
}



