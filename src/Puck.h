#pragma once

#include "glm/gtc/matrix_transform.hpp"
#include "Entity.h"
#include "Collision.h"

class Puck : public Entity
{
private:
	float m_Width = 20;
	float m_Height = 20;
	float m_Speed;
	Vector2 m_Direction;
	class Mesh* m_Mesh;
public:
	Puck();
	~Puck();

	void CheckPlayerCollision(class Paddle* player);

	void OnUpdate(double delta) override;

	Vector2 GetDirection() const { return m_Direction; }
	Mesh* GetMesh() const { return m_Mesh; }
	glm::mat4 GetModelMatrix() const;
	collision::BoundingBox GetBoundingBox() const;


private:
	void CheckWallCollision();
};