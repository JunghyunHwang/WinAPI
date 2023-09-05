#pragma once
#include "framework.h"
#include "Vector2.h"

namespace assort
{
	class App;

	class Object
	{
		friend App;
	public:
		Object(int pX, int pY, int sX, int sY);
		~Object() = default;

	private:
		Vector2 mPos;
		Vector2 mScale;
		int mSpeed;
	};
}
