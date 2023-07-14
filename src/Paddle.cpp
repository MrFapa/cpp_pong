#include "Paddle.h"
#include "glm/gtc/matrix_transform.hpp"

Paddle::Paddle(int keyUp, int keyDown, Vector2 position)
	: Entity(position), m_KeyUp(keyUp), m_KeyDown(keyDown)
{
	m_VertexPositions.resize(8);
	UpdateVertexBuffer();

	m_Position.x = 30;

	glGenBuffers(1, &m_VB);
	glBindBuffer(GL_ARRAY_BUFFER, m_VB);
	glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), m_VertexPositions.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
	glGenBuffers(1, &m_IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), m_Indices.data(), GL_STATIC_DRAW);
}

Paddle::~Paddle()
{
	glDeleteBuffers(1, &m_VB);
	glDeleteBuffers(1, &m_IBO);
}

void Paddle::OnUpdate(float delta)
{
	m_Position.y = m_Position.y + m_InputDirection * delta;
	EdgeCheck();
	m_InputDirection = 0;
	UpdateVertexBuffer();
}

void Paddle::OnDraw()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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

void Paddle::UpdateVertexBuffer()
{
	float height = m_Height / 2.0f;
	m_VertexPositions[0] = -10.0f;
	m_VertexPositions[1] = -height;
	m_VertexPositions[2] = 10.0f;
	m_VertexPositions[3] = -height;
	m_VertexPositions[4] = 10.0f;
	m_VertexPositions[5] = height;
	m_VertexPositions[6] = -10.0f;
	m_VertexPositions[7] = height;
}






