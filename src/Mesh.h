#pragma once
#include <vector>

class Mesh
{
public:
	Mesh();
	~Mesh();

	void SetVertexData(std::vector<float> vertexPositions, std::vector<unsigned int> indexArray);
	void Bind();
	void Unbind();
	void Draw();

private:
	unsigned int m_VB;					// Vertex Buffer ID
	unsigned int m_IBO;					// Index Buffer ID
	unsigned int m_VAO;					// Vertex Array ID
	std::vector<float> m_VBData;		// Vertex Data
	std::vector<unsigned int> m_IBOData;// Index Data
};
