#pragma once
#include "Entity.h"

class Paddle : public Entity
{
private:
	int m_KeyUp;
	int m_KeyDown;
	int m_InputDirection = 0;
	int m_Score = 0;
	float m_Speed = 300.0f;
public:
	Paddle(int keyUp, int keyDown, Vector2 position = {0, 0});

	void OnUpdate(double delta) override;
	void ReceiveInput(const int input);

	void IncrementScore() { m_Score++; }
	
	int GetKeyUp() const { return m_KeyUp; }
	int GetKeyDown() const { return m_KeyDown; }
	int GetScore() const { return m_Score; }
	
private:
	void EdgeCheck();
};