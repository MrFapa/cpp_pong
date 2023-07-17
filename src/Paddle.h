#pragma once
#include <vector>

#include "glm/gtc/matrix_transform.hpp"
#include "GL/glew.h"
#include "Entity.h"

class Paddle : public Entity
{
private:
	int m_KeyUp;
	int m_KeyDown;
	int m_InputDirection = 0;
	float m_Height = 80.0f;
	float m_Speed = 300.0f;
	class Mesh* m_Mesh;
public:
	Paddle(int keyUp, int keyDown, Vector2 position = {0, 0});
	~Paddle();

	void OnUpdate(double delta) override;
	void ReceiveInput(const int input);

	glm::mat4 GetModelMatrix() const;
	Mesh* GetMesh() const { return m_Mesh; }
	int GetKeyUp() const { return m_KeyUp; }
	int GetKeyDown() const { return m_KeyDown; }
	
private:
	void EdgeCheck();
};