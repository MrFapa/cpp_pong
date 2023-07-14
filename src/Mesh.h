#pragma once
#include <vector>

class Mesh
{
public:
	Mesh();
	~Mesh();

	void SetVertexData(std::vector<float> vertexPositions, std::vector<unsigned int> indexArray);
	void Bind();
	void Draw();

private:
	unsigned int m_VB;
	std::vector<float> m_VBData;
	unsigned int m_IBO;
	std::vector<unsigned int> m_IBOData;
};
