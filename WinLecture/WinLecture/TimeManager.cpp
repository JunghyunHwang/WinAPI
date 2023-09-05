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

	void TimeManager::update()
	{
		QueryPerformanceCounter(&mCurrCount);

		mDT = (double)(mCurrCount.QuadPart - mPrevCount.QuadPart) / mFrequency.QuadPart;
		mPrevCount = mCurrCount;

		++mCallCount;
		mAccDT += mDT;

		if (mAccDT >= 1.0)
		{
			App::GetInstance()->objectSpeedUp();
			wchar_t szBuffer[255];
			swprintf_s(szBuffer, L"FPS: %d,  DT: %f  Speed: %d", mCallCount, mDT, App::GetInstance()->getObjectSpeed());
			SetWindowText(App::GetInstance()->GetMainHwnd(), szBuffer);

			mCallCount = 0;
			mAccDT = 0;
		}
	}

	double TimeManager::getDT() const
	{
		return mDT;
	}
}
