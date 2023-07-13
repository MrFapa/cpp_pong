#include "Paddle.h"

Paddle::Paddle(int keyUp, int keyDown, Vector2 position)
	: Entity(position), m_KeyUp(keyUp), m_KeyDown(keyDown)
{
	m_VertexPositions.resize(8);
	UpdateVertexBuffer();

	glGenBuffers(1, &m_VB);
	glBindBuffer(GL_ARRAY_BUFFER, m_VB);
	glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), m_VertexPositions.data(), GL_DYNAMIC_DRAW);

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
	float y = m_Position.y;
	float x = m_Position.x;
	float height = m_Height / 2;
	/*m_vertexpositions[0] = y - height;
	m_vertexpositions[1] = x - 30;
	m_vertexpositions[2] = y - height;
	m_vertexpositions[3] = x + 30;
	m_vertexpositions[4] = y + height;
	m_vertexpositions[5] = x + 30;
	m_vertexpositions[6] = y + height;
	m_vertexpositions[7] = x - 30;*/

	m_VertexPositions[0] = -0.5f;
	m_VertexPositions[1] = -0.5f;
	m_VertexPositions[2] = 0.5f;
	m_VertexPositions[3] = -0.5f;
	m_VertexPositions[4] = 0.5f;
	m_VertexPositions[5] = 0.5f;
	m_VertexPositions[6] = -0.5f;
	m_VertexPositions[7] = 0.5f;
}






