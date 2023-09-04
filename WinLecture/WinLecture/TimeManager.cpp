#include "TimeManager.h"
#include "App.h"

namespace assort
{
	TimeManager::TimeManager()
		: mCurrCount{}
		, mPrevCount{}
		, mDT(0)
		, mCallCount(0)
		, mAccDT(0)
	{
		QueryPerformanceFrequency(&mFrequency);
	}

	void TimeManager::Update()
	{
		QueryPerformanceCounter(&mCurrCount);

		mDT = (double)(mCurrCount.QuadPart - mPrevCount.QuadPart) / mFrequency.QuadPart;
		mPrevCount = mCurrCount;

		++mCallCount;
		mAccDT += mDT;

		if (mAccDT >= 1.0)
		{
			wchar_t szBuffer[255];
			swprintf_s(szBuffer, L"FPS: %d,  DT: %f", mCallCount, mDT);
			SetWindowText(App::GetInstance()->GetMainHwnd(), szBuffer);

			mCallCount = 0;
			mAccDT = 0;
		}
	}

	double TimeManager::GetDT() const
	{
		return mDT;
	}
}
