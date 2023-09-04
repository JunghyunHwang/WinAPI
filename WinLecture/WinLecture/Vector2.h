#pragma once

namespace assort
{
	class Vector2 final
	{
	public:
		Vector2(float x, float y);
		~Vector2() = default;
		Vector2(const Vector2& other) = default;
		Vector2& operator=(const Vector2& rhs) = default;

	public:
		float mX;
		float mY;
	};
}
