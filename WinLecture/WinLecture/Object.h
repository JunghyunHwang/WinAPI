#pragma once

namespace assort
{
	class App;

	class Object final
	{
		friend App;
	public:
		Object(float pX, float pY, float sX, float sY);
		~Object() = default;

	private:
		Vec4 mPos;
		float mSpeed;
	};
}
