#include "Paddle.h"
#include "Mesh.h"
#include "PrimitveFactory.h"

Paddle::Paddle(int keyUp, int keyDown, Vector2 position)
	: Entity(position), m_KeyUp(keyUp), m_KeyDown(keyDown)
{
	m_Mesh = PrimitiveFactory::Cube(10, m_Height / 2);
}

Paddle::~Paddle()
{
	delete m_Mesh;
}

void Paddle::OnUpdate(double delta)
{
	m_Position.y = m_Position.y + static_cast<float>(m_InputDirection) * static_cast<float>(delta) * m_Speed;

	EdgeCheck();
	m_InputDirection = 0;
}

void Paddle::ReceiveInput(const int input)
{
	m_InputDirection += input;
}

glm::mat4 Paddle::GetModelMatrix() const
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

void Paddle::EdgeCheck()
{
	if(m_Position.y - m_Height / 2 < 0)
	{
		m_Position.y = m_Height / 2;
	}
	else if (m_Position.y + m_Height / 2 > 800)
	{
		m_Position.y = 800 - m_Height / 2;
	}
}






