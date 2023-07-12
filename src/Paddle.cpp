#include "Paddle.h"
#include <iostream>

Paddle::Paddle(int keyUp, int keyDown, Vector2 position)
	: Entity(position), m_KeyUp(keyUp), m_KeyDown(keyDown)
{
	
}

Paddle::~Paddle()
{
	return;
}

void Paddle::OnUpdate(float delta)
{
	m_Position.y = m_Position.y + m_InputDirection * delta;
	EdgeCheck();
	std::cout << m_Position.y << std::endl;
	m_InputDirection = 0;
}

void Paddle::OnDraw()
{
	
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





