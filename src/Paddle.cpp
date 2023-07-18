#include "Paddle.h"

Paddle::Paddle(int keyUp, int keyDown, Vector2 position)
	: Entity(position, 20, 80), m_KeyUp(keyUp), m_KeyDown(keyDown)
{
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

void Paddle::EdgeCheck()
{
	
	// Limits position to the edge 
	if(m_Position.y - m_Height / 2 < 0)
	{
		m_Position.y = m_Height / 2;
	}
	else if (m_Position.y + m_Height / 2 > 800)
	{
		m_Position.y = 800 - m_Height / 2;
	}
}






