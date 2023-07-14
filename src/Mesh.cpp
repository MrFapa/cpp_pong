#include "Mesh.h"

#include <GL/glew.h>

Mesh::Mesh()
{
	glGenBuffers(1, &m_VB);
	glBindBuffer(GL_ARRAY_BUFFER, m_VB);

	glGenBuffers(1, &m_IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &m_VB);
	glDeleteBuffers(1, &m_IBO);
}

void Mesh::SetVertexData(std::vector<float> vertexPositions, std::vector<unsigned> indexArray)
{
	m_VBData = vertexPositions;
	m_IBOData = indexArray;

	glBufferData(GL_ARRAY_BUFFER, m_VBData.size() * sizeof(float), m_VBData.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_IBOData.size() * sizeof(unsigned int), m_IBOData.data(), GL_STATIC_DRAW);

}

void Mesh::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
}

void Mesh::Draw()
{
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}




