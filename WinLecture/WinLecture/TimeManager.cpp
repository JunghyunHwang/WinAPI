#include "pch.h"
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
		, mTotalTime(0)
	{
		QueryPerformanceFrequency(&mFrequency);
	}

	void TimeManager::update()
	{
		QueryPerformanceCounter(&mCurrCount);

		mDT = (float)(mCurrCount.QuadPart - mPrevCount.QuadPart) / mFrequency.QuadPart;
		mPrevCount = mCurrCount;

		++mCallCount;
		mAccDT += mDT;

		if (mAccDT >= 1.0)
		{
			++mTotalTime;
			wchar_t szBuffer[255];
			swprintf_s(szBuffer, L"FPS: %d,  DT: %f  Speed: %f", mCallCount, mDT, App::GetInstance()->getObjectSpeed());
			SetWindowText(App::GetInstance()->GetMainHwnd(), szBuffer);

			mCallCount = 0;
			mAccDT = 0;
		}
	}

	float TimeManager::getDT() const
	{
		return mDT;
	}
}
