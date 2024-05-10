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
		LARGE_INTEGER mFrequency; // 사용자의 pc의 초당 셀 수 있는 수의 크기
		LARGE_INTEGER mCurrCount;
		LARGE_INTEGER mPrevCount;
		float mDT;
		int mCallCount;
		float mAccDT;
		uint32_t mTotalTime;
	};
}
