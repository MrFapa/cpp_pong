#pragma once

#include "Entity.h"
namespace collision
{
	struct BoundingBox
	{
		Vector2 min;
		Vector2 max;
	};

	static bool CheckAABBCollision(const BoundingBox& first, const BoundingBox& second)
	{
        if (first.max.x < second.min.x || first.min.x > second.max.x)
            return false;
		
        if (first.max.y < second.min.y || first.min.y > second.max.y)
            return false;
		
        return true;
	}
}
