#pragma once

#include "framework.h"

namespace assort
{
	class App;

	class TimeManager final
	{
		friend App;
	public:
		TimeManager();
		~TimeManager() = default;

	private:
		void update();
		double getDT() const;
		
	private:
		LARGE_INTEGER mCurrCount;
		LARGE_INTEGER mPrevCount;
		LARGE_INTEGER mFrequency;
		double mDT;
		int mCallCount;
		double mAccDT;
	};
}
