#pragma once
#include <vector>
#include "GL/glew.h"
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
	void UpdateVertexBuffer();

	int m_KeyUp;
	int m_KeyDown;
	int m_InputDirection = 0;
	float m_Height = 50.0f;

	float m_Speed = 1.0f;

	unsigned int m_VB;
	std::vector<float> m_VertexPositions;
	unsigned int m_IBO;
	std::vector<unsigned int> m_Indices = {
		  0, 1, 2,
		  2, 3, 0
	};
};