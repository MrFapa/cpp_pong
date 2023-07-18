#pragma once
#include <glm/gtc/matrix_transform.hpp>

#include "Collision.h"
#include "Vector2.h"


class Entity
{
public:
	Entity(Vector2 position = { 0, 0 }, float width = 10, float height = 10);
	~Entity();

	virtual void OnUpdate(double delta) {}

	// Getter
	Vector2 GetPosition() const { return m_Position; }
	virtual collision::BoundingBox GetBoundingBox() const; // Used for Collision
	virtual glm::mat4 GetModelMatrix() const; // Model Matrix for MVP
	virtual class Mesh* GetMesh() const { return m_Mesh; }

protected:
	float m_Width = 20;
	float m_Height = 20;

	Vector2 m_Position;
	class Mesh* m_Mesh;
};
