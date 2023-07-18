#pragma once
#include "Entity.h"

class Paddle : public Entity
{
private:
	int m_KeyUp;				// Key for moving upwards
	int m_KeyDown;				// Key for moving downwards
	int m_InputDirection = 0;	// 0 = no button press or both, 1 = up, -1 = down
	int m_Score = 0;
	float m_Speed = 300.0f;
public:
	Paddle(int keyUp, int keyDown, Vector2 position = {0, 0});

	void OnUpdate(double delta) override;
	void ReceiveInput(const int input);

	void IncrementScore() { m_Score++; }

	// Getters
	int GetKeyUp() const { return m_KeyUp; }
	int GetKeyDown() const { return m_KeyDown; }
	int GetScore() const { return m_Score; }
	
private:
	// Top and Bottom wall edge check
	void EdgeCheck(); 
};