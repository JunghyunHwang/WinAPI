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
		LARGE_INTEGER mFrequency; // ������� pc�� �ʴ� �� �� �ִ� ���� ũ��
		LARGE_INTEGER mCurrCount;
		LARGE_INTEGER mPrevCount;
		float mDT;
		int mCallCount;
		float mAccDT;
		uint32_t mTotalTime;
	};
}
