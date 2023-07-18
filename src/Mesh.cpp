#include "Mesh.h"

#include <GL/glew.h>

Mesh::Mesh()
{
	glGenBuffers(1, &m_VB);
	glGenBuffers(1, &m_IBO);
	glGenVertexArrays(1, &m_VAO);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &m_VB);
	glDeleteBuffers(1, &m_IBO);
	glDeleteVertexArrays(1, &m_VAO);
}


// Only supports 2d vertex position (maybe introduce uv's)
void Mesh::SetVertexData(std::vector<float> vertexPositions, std::vector<unsigned> indexArray)
{
	glBindVertexArray(m_VAO);
	m_VBData = vertexPositions;
	m_IBOData = indexArray;

	glBindBuffer(GL_ARRAY_BUFFER, m_VB);
	glBufferData(GL_ARRAY_BUFFER, m_VBData.size() * sizeof(float), m_VBData.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_IBOData.size() * sizeof(unsigned int), m_IBOData.data(), GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void Mesh::Bind()
{
	glBindVertexArray(m_VAO);
}
void Mesh::Unbind()
{
	glBindVertexArray(0);
}


void Mesh::Draw()
{
	glDrawElements(GL_TRIANGLES, m_IBOData.size(), GL_UNSIGNED_INT, 0);
}


