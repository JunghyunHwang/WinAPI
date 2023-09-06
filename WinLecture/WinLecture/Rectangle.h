#pragma once

#include "Object.h"

namespace assort
{
	class Rectangle : Object
	{
	public:
		Rectangle(int pX, int pY, int sX, int sY);
		~Rectangle() = default;
	};
}
