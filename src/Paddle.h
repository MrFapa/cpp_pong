#pragma once
#include "Entity.h"
class Paddle : public Entity
{
public:
	Paddle(int keyUp, int keyDown, Vector2 position = {0, 0});
	~Paddle();

	void OnUpdate(float delta) override;
	void OnDraw() override;
	void ReceiveInput(const int input);
	
private:
	void EdgeCheck();

	int m_KeyUp;
	int m_KeyDown;
	int m_InputDirection = 0;
	int m_Height = 50;

	float m_Speed = 1.0f;
};