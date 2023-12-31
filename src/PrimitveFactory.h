#pragma once
#include <vector>

#include "Mesh.h"
class PrimitiveFactory
{
public:

	// pivot of cube is the center
	static Mesh* Cube(float width, float height)
	{
		float halfWidth = width / 2;
		float halfHeight = height / 2;

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

	// Extendable with further forms like triangle, circle, etc
};
