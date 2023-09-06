#pragma once
#include "framework.h"
#include "Vector2.h"

namespace assort
{
	class App;
	class ObjectManager;

	class Object
	{
		friend App;
		friend ObjectManager;
	public:
		Object(int pX, int pY, int sX, int sY);
		virtual ~Object() = default;

	private:
		virtual void update() = 0;

	protected:
		Vector2 mPos;
		Vector2 mScale;
		int mSpeed;
	};
}
