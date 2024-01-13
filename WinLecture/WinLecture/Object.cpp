#include "pch.h"
#include "Object.h"

namespace assort
{
	Object::Object(float left, float top, float right, float bottom)
		: mPos{ left, top, right, bottom }
		, mSpeed(300)
	{
	}
}
