#pragma once

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
		float getDT() const;
		
	private:
		LARGE_INTEGER mCurrCount;
		LARGE_INTEGER mPrevCount;
		LARGE_INTEGER mFrequency;
		float mDT;
		int mCallCount;
		float mAccDT;
		uint32_t mTotalTime;
	};
}
