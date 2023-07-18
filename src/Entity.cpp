#include "Entity.h"
#include "PrimitveFactory.h"

Entity::Entity(Vector2 position, float width, float height)
	:m_Position(position), m_Width(width), m_Height(height)
{
	m_Mesh = PrimitiveFactory::Cube(m_Width, m_Height);
}


Entity::~Entity()
{
	delete m_Mesh;
}


glm::mat4 Entity::GetModelMatrix() const
{
	// Transposed because of OpenGL
	glm::mat4 modelMatrix = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		m_Position.x, m_Position.y, 0.0f, 1.0f
	};
	return modelMatrix;
}


collision::BoundingBox Entity::GetBoundingBox() const
{
	// Calculate the bounding box based on the position, width, and height
	collision::BoundingBox boundingBox =
	{
		{m_Position.x - m_Width / 2.0f, m_Position.y - m_Height / 2.0f},
		{m_Position.x + m_Width / 2.0f, m_Position.y + m_Height / 2.0f}
	};
	return boundingBox;
	
}
