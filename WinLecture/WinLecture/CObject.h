#pragma once
#include "framework.h"
#include "App.h"

namespace assort
{
	class App;

	class CObject
	{
		friend App;
	public:
		CObject();
		CObject(int pX, int pY, int sX, int sY);
		~CObject() = default;

	private:
		POINT mPos;
		POINT mScale;
	};
}
