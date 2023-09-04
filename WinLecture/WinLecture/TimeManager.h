#pragma once

#include "framework.h"

namespace assort
{
	class TimeManager final
	{
	public:
		TimeManager();
		~TimeManager() = default;

		void Update();
		double GetDT() const;
		
	private:
		LARGE_INTEGER mCurrCount;
		LARGE_INTEGER mPrevCount;
		LARGE_INTEGER mFrequency;
		double mDT;
		int mCallCount;
		double mAccDT;
	};
}
