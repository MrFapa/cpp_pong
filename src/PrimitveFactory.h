#pragma once
#include <vector>

#include "Mesh.h"
class PrimitiveFactory
{
public:
	static Mesh* Cube(float halfWidth, float halfHeight)
	{
		Mesh* cube = new Mesh();
		std::vector<float> vertexPositions = {
			-halfWidth, -halfHeight, 
			 halfWidth, -halfHeight,
			 halfWidth,  halfHeight,
			-halfWidth,  halfHeight
		};

		std::vector<unsigned int> indicies = {
			0, 1, 2,
			2, 3, 0
		};
		cube->SetVertexData(vertexPositions, indicies);
		return cube;
	}
};
