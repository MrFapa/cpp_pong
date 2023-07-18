#pragma once

#include "Vector2.h"
namespace collision
{
	struct BoundingBox
	{
		Vector2 min;
		Vector2 max;
	};

	static bool CheckAABBCollision(const BoundingBox& first, const BoundingBox& second)
	{

		// No overlap on x-axis
        if (first.max.x < second.min.x || first.min.x > second.max.x)
            return false;

		// No overlap on y-axis
        if (first.max.y < second.min.y || first.min.y > second.max.y)
            return false;

		// Boxed collide
        return true;
	}
}
