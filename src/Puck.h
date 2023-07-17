#pragma once

#include "glm/gtc/matrix_transform.hpp"
#include "Entity.h"

class Puck : public Entity
{
private:
	float m_Speed;
	float m_Direction;
	class Mesh* m_Mesh;
public:
	Puck();
	~Puck();

	void OnUpdate(double delta) override;
	void Reset();
	Mesh* GetMesh() const { return m_Mesh; }
	glm::mat4 GetModelMatrix() const;


private:
	void EdgeCheck();
	void BounceWall();
	void BouncePlayer();
};